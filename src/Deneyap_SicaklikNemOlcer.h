/*
*****************************************************************************
@file         Deneyap_SicaklikNemOlcer.h
@mainpage     Deneyap Temperature&Humidity SHTC3 Arduino library header file
@version      v1.0.0
@date         June 27, 2022
@brief        This file contains all function prototypes and macros
              for Deneyap Temperature&Humidity SHTC3 Arduino library
*****************************************************************************
*/

#ifndef __Deneyap_SicaklikNemOlcer_H
#define __Deneyap_SicaklikNemOlcer_H

#include <Wire.h>
#include <Arduino.h>

//The default I2C address for the SHTC3 is 0x70
#define SHTC3_ADDR                                 0x70

#define SHTC3_CMD_WAKE                             0x3517
#define SHTC3_CMD_SLEEP                            0xB098
#define SHTC3_CMD_SFT_RST                          0x805D
#define SHTC3_CMD_READ_ID                          0xEFC8 

#define SHTC3_CMD_CSE_RHF_NPM                      0x5C24  /* Clock stretching, RH first, Normal power mode */
#define SHTC3_CMD_CSE_RHF_LPM                      0x44DE  /* Clock stretching, RH first, Low power mode */
#define SHTC3_CMD_CSE_TF_NPM                       0x7CA2  /* Clock stretching, T first, Normal power mode */
#define SHTC3_CMD_CSE_TF_LPM                       0x6458  /* Clock stretching, T first, Low power mode */
#define SHTC3_CMD_CSD_RHF_NPM                      0x58E0  /* Polling, RH first, Normal power mode */
#define SHTC3_CMD_CSD_RHF_LPM                      0x401A  /* Polling, RH first, Low power mode */
#define SHTC3_CMD_CSD_TF_NPM                       0x7866  /* Polling, T first, Normal power mode */
#define SHTC3_CMD_CSD_TF_LPM                       0x609C  /* Polling, T first, Low power mode */

// Higher level class inherited from core class includes begin() method
// and data manipulation functions
class TempHum { 
  public:
    bool begin(uint8_t address, TwoWire &wirePort = Wire); 
    float getTempValue(void);
    float getHumValue(void);
    uint16_t getReadID(void);
    void sleep(void);
    void wakeup(void);    
    void reset(void);                            
  
  private:
    uint8_t _address;
    void sendCommand(uint16_t cmd);   
    void readCommand(uint16_t cmd, uint8_t *pdata, uint8_t size);
};
#endif // End of __Deneyap_SicaklikNemOlcer_H definition check
