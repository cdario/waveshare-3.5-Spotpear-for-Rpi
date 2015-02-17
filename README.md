#README


## LCD Screen Setup

1.Expand the filesystem

```
sudo raspi-config
```

2.Change fb0 to fb1

```
sudo nano /usr/share/X11/xorg.conf.d/99-fbturbo.conf
```

3.Enable SPI if needed

```
# remove or comment out the spi blacklist line
sudo nano /etc/modprobe.d/raspi-blacklist.conf
```

4.FBTFT drivers as loadable modules

```
sudo REPO_URI=https://github.com/notro/rpi-firmware rpi-update
sudo reboot
```

5.Test (After second command, screen is not white anymore)

```
sudo modprobe flexfb  width=320  height=480  regwidth=16 init=-1,0xb0,0x0,-1,0x11,-2,250,-1,0x3A,0x55,-1,0xC2,0x44,-1,0xC5,0x00,0x00,0x00,0x00,-1,0xE0,0x0F,0x1F,0x1C,0x0C,0x0F,0x08,0x48,0x98,0x37,0x0A,0x13,0x04,0x11,0x0D,0x00,-1,0xE1,0x0F,0x32,0x2E,0x0B,0x0D,0x05,0x47,0x75,0x37,0x06,0x10,0x03,0x24,0x20,0x00,-1,0xE2,0x0F,0x32,0x2E,0x0B,0x0D,0x05,0x47,0x75,0x37,0x06,0x10,0x03,0x24,0x20,0x00,-1,0x36,0x28,-1,0x11,-1,0x29,-3

sudo modprobe fbtft_device debug=3 rotate=90 name=flexfb speed=16000000 gpios=reset:25,dc:24

```

6.Perminantly add Driver

```
#Add to file /etc/modules
flexfb  width=320  height=480  regwidth=16 init=-1,0xb0,0x0,-1,0x11,-2,250,-1,0x3A,0x55,-1,0xC2,0x44,-1,0xC5,0x00,0x00,0x00,0x00,-1,0xE0,0x0F,0x1F,0x1C,0x0C,0x0F,0x08,0x48,0x98,0x37,0x0A,0x13,0x04,0x11,0x0D,0x00,-1,0xE1,0x0F,0x32,0x2E,0x0B,0x0D,0x05,0x47,0x75,0x37,0x06,0x10,0x03,0x24,0x20,0x00,-1,0xE2,0x0F,0x32,0x2E,0x0B,0x0D,0x05,0x47,0x75,0x37,0x06,0x10,0x03,0x24,0x20,0x00,-1,0x36,0x28,-1,0x11,-1,0x29,-3

fbtft_device debug=3 rotate=90 name=flexfb speed=16000000 gpios=reset:25,dc:24
```
7.Additional settings

```
#/boot/config.txt
gpu_mem=128

#/boot/cmdline.txt
fbcon=map:1 fbcon=font:ProFont6x11

```


## Enabling touchscreen


1. Install libraries

```
sudo apt-get -y install xinput evtest libts-bin
```

2. Add device to /etc/modules

```
ads7846_device model=7846 cs=1 gpio_pendown=17  keep_vref_on=1 swap_xy=0 pressure_max=255 x_plate_ohms=60 x_min=200  x_max=3900 y_min=200 y_max=3900

```

3. Get calibration parameters

```
wget http://adafruit-download.s3.amazonaws.com/xinput-calibrator_0.7.5-1_armhf.deb

sudo dpkg -i -B xinput-calibrator_0.7.5-1_armhf.deb

sudo rm /usr/share/X11/xorg.conf.d/99-calibration.conf

sudo reboot

```

After reboot type `startx` and open `xterminal` then run the calibration tool

```
DISPLAY=:0.0 xinput_calibrator
```

Edit 99-calibration using the new parameters, e.g.

```
Section "InputClass"
	Identifier "calibration"
	MatchProduct "ADS7846 Touchscreen"
	Option "Calibration" "3873 272 236 3868"
	Option  "SwapAxes"      "1"
EndSection

```

##Installing onscreen keyboard

1. Download and install the debian package (do not get from repos)

```
wget http://ftp.us.debian.org/debian/pool/main/m/matchbox-keyboard/matchbox-
keyboard_0.1+svn20080916-9+b1_armhf.deb


```

2. Create a toogle script to avoid multiple instances

```
#!/bin/bash

PID=$(pidof matchbox-keyboard)
if [ ! -e $PID ]; then
        killall matchbox-keyboard
else
        matchbox-keyboard -s 80 extended&
fi

```


```
$ sudo chmod +x /usr/bin/toggle-matchbox-keyboard.sh
```

_buggy in Openbox_


## Additional stuff

1. Auto-login: edit `$ sudo nano /etc/inittab` as shown

```
#1:2345:respawn:/sbin/getty --noclear 38400 tty1
1:2345:respawn:/bin/login -f pi tty </dev/tty1 >/dev/tty1 2>&1


``` 

2. Startx by default

Add the following lines before `exit 0` in `/etc/rc.local `


```
echo -e '[NOTICE] Press any key NOW to cancel startx...'
read -n 1 -t 3 ANY_KEY

if [ "$ANY_KEY" == "" ]; then
  su -l pi -c startx
else
  echo -e '[NOTICE] startx stopped'
fi

``` 


### Sources :

[1] https://github.com/notro/fbtft/issues/215

[2] http://ozzmaker.com/2014/06/30/virtual-keyboard-for-the-raspberry-pi/

[3] http://www.raspberrypi.org/forums/viewtopic.php?f=66&t=14719