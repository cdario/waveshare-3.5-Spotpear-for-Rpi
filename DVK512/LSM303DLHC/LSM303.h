#ifndef __LSM303_H
#define __LSM303_H

#define   uchar unsigned char
#define   uint unsigned int	
#define   u32 unsigned long
#define   u8 unsigned char
#define   uint unsigned int	
typedef volatile  unsigned long  vu32;
/*=====================================================================================================*/
#define LSM303A_I2C_ADDR				((u8)0x19)
#define LSM303M_I2C_ADDR				((u8)0x1E)

#define LSM303A_CTRL_REG1				((u8)0x20)
#define LSM303A_CTRL_REG2				((u8)0x21)
#define LSM303A_CTRL_REG3				((u8)0x22)
#define LSM303A_CTRL_REG4				((u8)0x23)
#define LSM303A_CTRL_REG5				((u8)0x24)
#define LSM303A_HP_FILTER_RESET	((u8)0x25)
#define LSM303A_REFERENCE				((u8)0x26)
#define LSM303A_STATUS_REG			((u8)0x27)
#define LSM303A_OUT_X_L					((u8)0x28)
#define LSM303A_OUT_X_H					((u8)0x29)
#define LSM303A_OUT_Y_L					((u8)0x2A)
#define LSM303A_OUT_Y_H					((u8)0x2B)
#define LSM303A_OUT_Z_L					((u8)0x2C)
#define LSM303A_OUT_Z_H					((u8)0x2D)
#define LSM303A_INT1_CFG				((u8)0x30)
#define LSM303A_INT1_SOURCE			((u8)0x31)
#define LSM303A_INT1_INT1_THS		((u8)0x32)
#define LSM303A_INT1_DURATION		((u8)0x33)
#define LSM303A_INT2_CFG				((u8)0x34)
#define LSM303A_INT2_SOURCE			((u8)0x35)
#define LSM303A_INT2_THS				((u8)0x36)
#define LSM303A_INT2_DURATION		((u8)0x37)
#define LSM303A_MULTIPLE				((u8)0xA8)	// ³sÄòÅª¨ú¦a§}

#define LSM303M_CRA_REG					((u8)0x00)
#define LSM303M_CRB_REG					((u8)0x01)
#define LSM303M_MR_REG					((u8)0x02)
#define LSM303M_OUT_X_H					((u8)0x03)
#define LSM303M_OUT_X_L					((u8)0x04)
#define LSM303M_OUT_Z_H					((u8)0x05)
#define LSM303M_OUT_Z_L					((u8)0x06)
#define LSM303M_OUT_Y_H					((u8)0x07)
#define LSM303M_OUT_Y_L					((u8)0x08)
#define LSM303M_SR_REG					((u8)0x09)
#define LSM303M_IRA_REG					((u8)0x0A)
#define LSM303M_IRB_REG					((u8)0x0B)
#define LSM303M_IRC_REG					((u8)0x0C)
#define LSM303M_MULTIPLE				((u8)0x83)	// ³sÄòÅª¨ú¦a§}
/*=====================================================================================================*/

#define  LSM303DLHC_FS_1_3_GA               ((uint8_t) 0x20)  /*!< Full scale = ±1.3 Gauss */
#define  LSM303DLHC_FS_1_9_GA               ((uint8_t) 0x40)  /*!< Full scale = ±1.9 Gauss */
#define  LSM303DLHC_FS_2_5_GA               ((uint8_t) 0x60)  /*!< Full scale = ±2.5 Gauss */
#define  LSM303DLHC_FS_4_0_GA               ((uint8_t) 0x80)  /*!< Full scale = ±4.0 Gauss */
#define  LSM303DLHC_FS_4_7_GA               ((uint8_t) 0xA0)  /*!< Full scale = ±4.7 Gauss */
#define  LSM303DLHC_FS_5_6_GA               ((uint8_t) 0xC0)  /*!< Full scale = ±5.6 Gauss */
#define  LSM303DLHC_FS_8_1_GA               ((uint8_t) 0xE0)  /*!< Full scale = ±8.1 Gauss */



#define LSM303DLHC_M_SENSITIVITY_XY_1_3Ga     1100  /*!< magnetometer X Y axes sensitivity for 1.3 Ga full scale [LSB/Ga] */
#define LSM303DLHC_M_SENSITIVITY_XY_1_9Ga     855   /*!< magnetometer X Y axes sensitivity for 1.9 Ga full scale [LSB/Ga] */
#define LSM303DLHC_M_SENSITIVITY_XY_2_5Ga     670   /*!< magnetometer X Y axes sensitivity for 2.5 Ga full scale [LSB/Ga] */
#define LSM303DLHC_M_SENSITIVITY_XY_4Ga       450   /*!< magnetometer X Y axes sensitivity for 4 Ga full scale [LSB/Ga] */
#define LSM303DLHC_M_SENSITIVITY_XY_4_7Ga     400   /*!< magnetometer X Y axes sensitivity for 4.7 Ga full scale [LSB/Ga] */
#define LSM303DLHC_M_SENSITIVITY_XY_5_6Ga     330   /*!< magnetometer X Y axes sensitivity for 5.6 Ga full scale [LSB/Ga] */
#define LSM303DLHC_M_SENSITIVITY_XY_8_1Ga     230   /*!< magnetometer X Y axes sensitivity for 8.1 Ga full scale [LSB/Ga] */
#define LSM303DLHC_M_SENSITIVITY_Z_1_3Ga      980   /*!< magnetometer Z axis sensitivity for 1.3 Ga full scale [LSB/Ga] */
#define LSM303DLHC_M_SENSITIVITY_Z_1_9Ga      760   /*!< magnetometer Z axis sensitivity for 1.9 Ga full scale [LSB/Ga] */
#define LSM303DLHC_M_SENSITIVITY_Z_2_5Ga      600   /*!< magnetometer Z axis sensitivity for 2.5 Ga full scale [LSB/Ga] */
#define LSM303DLHC_M_SENSITIVITY_Z_4Ga        400   /*!< magnetometer Z axis sensitivity for 4 Ga full scale [LSB/Ga] */
#define LSM303DLHC_M_SENSITIVITY_Z_4_7Ga      355   /*!< magnetometer Z axis sensitivity for 4.7 Ga full scale [LSB/Ga] */
#define LSM303DLHC_M_SENSITIVITY_Z_5_6Ga      295   /*!< magnetometer Z axis sensitivity for 5.6 Ga full scale [LSB/Ga] */
#define LSM303DLHC_M_SENSITIVITY_Z_8_1Ga      205   /*!< magnetometer Z axis sensitivity for 8.1 Ga full scale [LSB/Ga] */


#define LSM_Acc_Sensitivity_2g     (float)     1            /*!< accelerometer sensitivity with 2 g full scale [LSB/mg] */
#define LSM_Acc_Sensitivity_4g     (float)     2           /*!< accelerometer sensitivity with 4 g full scale [LSB/mg] */
#define LSM_Acc_Sensitivity_8g     (float)     4           /*!< accelerometer sensitivity with 8 g full scale [LSB/mg] */
#define LSM_Acc_Sensitivity_16g    (float)     12         /*!< accelerometer sensitivity with 12 g full scale [LSB/mg] */

#define PI                         (float)     3.14159265f


#define LSM303DLHC_FULLSCALE_2G            ((uint8_t)0x00)  /*!< ±2 g */
#define LSM303DLHC_FULLSCALE_4G            ((uint8_t)0x10)  /*!< ±4 g */
#define LSM303DLHC_FULLSCALE_8G            ((uint8_t)0x20)  /*!< ±8 g */
#define LSM303DLHC_FULLSCALE_16G           ((uint8_t)0x30)  /*!< ±16 g */


/*=====================================================================================================*/
 void LSM303A_Init( void );
 void LSM303M_Init( void );
void LAM303M_Raed(float *Data);
void LAM303A_Raed(float *Data);

float Data_conversion(float *AccBuffer,float *MagBuffer);
/*=====================================================================================================*/
#endif
