 
/* 
             define from  wiringPi.h                     define from Board DVK511
                 3.3V | | 5V               ->                 3.3V | | 5V
                8/SDA | | 5V               ->                  SDA | | 5V
                9/SCL | | GND              ->                  SCL | | GND
                    7 | | 14/TX            ->                  IO7 | | TX
                  GND | | 15/RX            ->                  GND | | RX
                    0 | | 18               ->                  IO0 | | IO1
                    2 | | GND              ->                  IO2 | | GND
                    3 | | 23               ->                  IO3 | | IO4
                  VCC | | 24               ->                  VCC | | IO5
              MOSI/12 | | GND              ->                 MOSI | | GND
              MISO/13 | | 25               ->                 MISO | | IO6
               SCK/14 | | 8/CE0            ->                  SCK | | CE0
                  GND | | 9/CE19           ->                  GND | | CE1
*/



#include <stdio.h>
#include <string.h> 
#include <errno.h>

#include<wiringPi.h>
#include<softPwm.h>

int buz=0;
int pwm,pwmmax=100,count;

int main(){
if (wiringPiSetup() < 0)
{
    fprintf (stderr, "Unable to open device: %s\n", strerror (errno)) ;
    return 1 ;
}

if(softPwmCreate(buz,pwm,pwmmax)<0)
{
    fprintf (stderr, "Unable to open pwm  device: %s\n", strerror (errno)) ;
    return 1 ;
}
for(count=0;count<100;count++)
{
softPwmWrite(buz,count);
delay(50);
}

/*
pinMode(0,OUTPUT);
while(1)
{
digitalWrite(0,LOW);
delay(2000);//0.5 second or sleep(1)=1 second
digitalWrite(0,HIGH);
delay(300);//0.5 second
}
*/
}
