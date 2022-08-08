# Deneyap Temperature&Humidity SHTC3 Arduino Library
[FOR TURKISH VERSION](docs/README_tr.md) ![trflag](https://github.com/deneyapkart/deneyapkart-arduino-core/blob/master/docs/tr.png)

***** Add photo ****

Arduino library for Deneyap Temperature&Humidity SHTC3

## :mag_right:Specifications
- `Product ID` **M01**, **mpv1.0**
- `MCU` SHTC3
- `Weight`  
- `Module Dimension`
- `I2C address` 0x70

| Address |  | 
| :---      | :---     |
| 0x70 | default address |

## :closed_book:Documentation
Deneyap Temperature&Humidity SHTC3

[SHTC3-datasheet](https://media.digikey.com/pdf/Data%20Sheets/Sensirion%20PDFs/HT_DS_SHTC3_D1.pdf)

[How to installing a Arduino Library](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries)

## :pushpin:Deneyap Temperature&Humidity SHTC3
This Arduino library allows you to use Deneyap Temperature&Humidity SHTC3 with I2C peripheral. You can use this library in your projects with any Arduino compatible board with I2C peripheral.

## :globe_with_meridians:Repository Contents
- `/docs ` README_tr.md and product photos
- `/examples ` Examples with .ino extension sketches
- `/src ` Source files (.cpp .h)
- `keywords.txt ` Keywords from this library that will be highlighted in the Arduino IDE
- `library.properties ` General library properties for the Arduino package manager

## Version History
1.0.1 - bug fix for sketch

1.0.0 - initial release

## :rocket:Hardware Connections
- Deneyap Temperature&Humidity Sensor and Board can be connected with I2C cable
- or 3V3, GND, SDA and SCL pins can be connected with jumper cables

|Temperature&Humidity | Function | Board pins | 
|:--- |   :---  | :---|
|3.3V | Power   |3.3V |      
|GND  | Ground  | GND | 
|SDA  | I2C Data  | SDA pin |
|SCL  | I2C Clock | SCL pin |
| NC         | no connection|         |

## :bookmark_tabs: License Information
Please review the [LICENSE](https://github.com/deneyapkart/deneyap-sicaklik-nem-olcer-arduino-library/blob/master/LICENSE) file for license information.