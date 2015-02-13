// blink.c
//
// Example program for bcm2835 library
// Blinks a pin on an off every 0.5 secs
//
// After installing bcm2835, you can build this 
// with something like:
// make or gcc -o led led.c -lbcm2835
// sudo ./led
/*
             define from bcm2835.h                       define from Board DVK511
                 3.3V | | 5V               ->                 3.3V | | 5V
    RPI_V2_GPIO_P1_03 | | 5V               ->                  SDA | | 5V
    RPI_V2_GPIO_P1_05 | | GND              ->                  SCL | | GND
       RPI_GPIO_P1_07 | | RPI_GPIO_P1_08   ->                  IO7 | | TX
                  GND | | RPI_GPIO_P1_10   ->                  GND | | RX
       RPI_GPIO_P1_11 | | RPI_GPIO_P1_12   ->                  IO0 | | IO1
    RPI_V2_GPIO_P1_13 | | GND              ->                  IO2 | | GND
       RPI_GPIO_P1_15 | | RPI_GPIO_P1_16   ->                  IO3 | | IO4
                  VCC | | RPI_GPIO_P1_18   ->                  VCC | | IO5
       RPI_GPIO_P1_19 | | GND              ->                 MOSI | | GND
       RPI_GPIO_P1_21 | | RPI_GPIO_P1_22   ->                 MISO | | IO6
       RPI_GPIO_P1_23 | | RPI_GPIO_P1_24   ->                  SCK | | CE0
                  GND | | RPI_GPIO_P1_26   ->                  GND | | CE1

::if your raspberry Pi is version 1 or rev 1 or rev A
RPI_V2_GPIO_P1_03->RPI_GPIO_P1_03
RPI_V2_GPIO_P1_05->RPI_GPIO_P1_05
RPI_V2_GPIO_P1_13->RPI_GPIO_P1_13
::

*/
#include <bcm2835.h>


#define LED0 RPI_GPIO_P1_11
#define LED1 RPI_GPIO_P1_12
#define LED2 RPI_V2_GPIO_P1_13
#define LED3 RPI_GPIO_P1_15
#define LED4 RPI_GPIO_P1_16
#define LED5 RPI_GPIO_P1_18
#define LED6 RPI_GPIO_P1_22
#define LED7 RPI_GPIO_P1_07
char LED[8]={LED0,LED1,LED2,LED3,LED4,LED5,LED6,LED7};
int main(int argc, char **argv)
{
    if (!bcm2835_init())
        return 1;
    // Blink
    char i;
    while (1)
    {
	for(i=0;i<8;i++)
	{	
		bcm2835_gpio_fsel(LED[i], BCM2835_GPIO_FSEL_OUTP);
                bcm2835_gpio_write(LED[i],HIGH);
       	        bcm2835_delay(100);
               	bcm2835_gpio_write(LED[i],LOW);
                bcm2835_delay(100);
	}
    }
    bcm2835_close();
    return 0;
}
