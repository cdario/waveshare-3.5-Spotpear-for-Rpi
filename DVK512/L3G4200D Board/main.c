
/* Includes ------------------------------------------------------------------*/
#include "L3G4200D.h"
#include <string.h>
#include <stdio.h>

float xyz[3]={0};
volatile float angle_x=0,angle_y=0,angle_z=0;
volatile unsigned char  f=0,t=0; 

/*******************************************************************************
* Function Name  : Delay
* Description    : Delay Time
* Input          : - nCount: Delay Time
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void  Delay (uint32_t nCount)
{
  for(; nCount != 0; nCount--);
}


void data_int(float *between)
{
  uint16_t i;
	float data[100][3]={0};
	for(i=0;i<100;i++)
	{ 
		//while(f)
		//{
		  READ_L3G4200D(data[i],data[i]+1,data[i]+2);
		//f=0;
		//}
		Delay_1ms(10);
		between[0]+=data[i][0];
		between[1]+=data[i][1];
		between[2]+=data[i][2];
  }
  for(i=0;i<3;i++)
	  between[i]=between[i]/100;
	

}
int main(void)
{
 float bet[3]={0};

    if (!bcm2835_init())
        return 1;
    bcm2835_spi_begin();
    bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);      // The default
    bcm2835_spi_setDataMode(BCM2835_SPI_MODE3);                   // The default
    bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_256); // The default
    bcm2835_gpio_fsel(CS, BCM2835_GPIO_FSEL_OUTP);//    
    bcm2835_gpio_write(CS, HIGH);


	
	Init_L3G4200D();
	
	printf("\rl3f4200D ID ..\r\n");

 printf("\r\n******In the initialization!  Do not move the module!!******\r\n");

  data_int(bet);


		printf("bet0=%f rad/s\r\n",bet[0]); // xyz[x]hi角速度。
		printf("bet1=%f rad/s\r\n",bet[1]);
		printf("bet2=%f rad/s\r\n",bet[2]);	

	
  printf("\r\n*************************************************\r\n");

  while (1)
  {
		 READ_L3G4200D(xyz,xyz+1,xyz+2);
		
			xyz[0]=(int)(xyz[0]-bet[0]); 
			xyz[1]=(int)(xyz[1]-bet[1]); //
			xyz[2]=(int)(xyz[2]-bet[2]);
			
			xyz[0]=(int)(xyz[0]); 
			xyz[1]=(int)(xyz[1]); 
			xyz[2]=(int)(xyz[2]); 

	    xyz[0]/=100;
	    xyz[1]/=100;
	  	xyz[2]/=100;
			angle_x=(xyz[0])+angle_x;  if(angle_x>=360)angle_x-=360;
		  angle_y=(xyz[1])+angle_y;  if(angle_y>=360)angle_y-=360;
		  angle_z=(xyz[2])+angle_z;  if(angle_z>=360)angle_z-=360;
			//TIM_Cmd(TIM2,ENABLE);
		t++;
			if(t==100)t=0;
		//if(test==10)test=0;
		

		if(t==10){
	  printf("\r\n******  L3G4200D  ******\r\n");
			
		printf("x=%f rad/s\r\n",xyz[0]); // xyz[x]hi角速度。
		printf("y=%f rad/s\r\n",xyz[1]);
		printf("z=%f rad/s\r\n",xyz[2]);	
		Delay_1ms(1000);

             }
  }
    printf("test end!\n");
    bcm2835_spi_end();
    bcm2835_close();
    return 0;
}