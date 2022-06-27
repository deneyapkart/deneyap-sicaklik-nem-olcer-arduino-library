/*
*****************************************************************************
@file         Deneyap_SicaklikNemOlcer.cpp
@mainpage     Deneyap Temperature&Humidity SHTC3 Arduino library source file
@maintainer   RFtek Electronics <techsupport@rftek.com.tr>
@version      v1.0.0
@date         June 27, 2022
@brief        Includes functions to control Deneyap Temperature&Humidity SHTC3
              Arduino library

Library includes:
--> Configuration functions
--> Data manipulation functions
--> I2C communication functions
*****************************************************************************
*/
  
#include "Deneyap_SicaklikNemOlcer.h"

/**
  * @brief  I2C initialization and read check  
  * @param  adress: Device adress 
  * @retval None
**/
bool TempHum::begin(uint8_t address, TwoWire &wirePort) {
  
  _address = address; 
  Wire.begin(); 
  Wire.beginTransmission(address);
  if(!Wire.endTransmission())
     return true;
  return false;     
}

/**
  * @brief  Read Temp status
  * @param  None
  * @retval Temperature processed data
**/
float TempHum::getTempValue(void) {

  uint8_t buffer[2];
  float result;

  readCommand(SHTC3_CMD_CSE_TF_NPM, &buffer[0], 2);
  result = (buffer[0] << 8) | buffer[1];
  return result = (-45)+(((float)result/65536)*175);
}

/**
  * @brief  Read Hum status
  * @param  None
  * @retval Humidity processed data
**/
float TempHum::getHumValue(void) {

  uint8_t buffer[2];
  float result;

  readCommand(SHTC3_CMD_CSE_RHF_NPM, &buffer[0], 2);
  result = (buffer[0] << 8) | buffer[1];
  return result = (((float)result/65536)*100);
}

/**
  * @brief  Read ID function
  * @param  None
  * @retval ID data
**/
uint16_t TempHum::getReadID(void) {

  uint8_t buffer[2];
  uint16_t result;
 
  readCommand(SHTC3_CMD_READ_ID, &buffer[0], 2);
  return result = (buffer[0] << 8) | buffer[1];
}

/**
  * @brief  Sleep function for SHTC3
  * @param  None
  * @retval None
**/
void TempHum::sleep(void) {
  sendCommand(SHTC3_CMD_SLEEP); 
}

/**
  * @brief  Wakeup function 
  * @param  None
  * @retval None
**/
void TempHum::wakeup(void) {
  sendCommand(SHTC3_CMD_WAKE); 
}

/**
  * @brief  Reset function
  * @param  None
  * @retval None
**/
void TempHum::reset(void) {
  sendCommand(SHTC3_CMD_SFT_RST); 
}

/**
  * @brief   I2C read command for 16bit unsigned data
  * @param   cmd: 
  * @retval  None
**/
void TempHum::sendCommand(uint16_t cmd) {
  
  Wire.beginTransmission(_address);
  Wire.write((((uint16_t)cmd) >> 8));
  Wire.write((((uint16_t)cmd) & 0x00FF));
  Wire.endTransmission();
}

/**
  * @brief   I2C read command for 8bit unsigned data
  * @param   cmd: ,*pdata: ,size: 
  * @retval  None
**/
void TempHum::readCommand(uint16_t cmd, uint8_t *pdata, uint8_t size) {
  
  Wire.beginTransmission(_address); 
  Wire.write((((uint16_t)cmd) >> 8));
  Wire.write((((uint16_t)cmd) & 0x00FF));
  Wire.endTransmission();    
  Wire.requestFrom(_address, size);

  for(uint8_t i=0; i<size; i++){
    *(pdata+i) = Wire.read();
  }
}
