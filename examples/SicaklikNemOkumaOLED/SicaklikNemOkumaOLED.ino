/*
 *   Sıcaklık Nem okuyup SSD1306 OLED ekrana yazdırma örneği,
 *   
 *   Bu örnekte temel konfigürasyon ayarları yapılmaktadır. 
 *   Saniyede bir sıcaklık ve nem değerlerini alınmaktadır.
 *   Değerler seri terminale ve OLED ekrana yazdırmaktadır.  
 *   
 *   Bu algılayıcı I2C haberleşme protokolü ile çalışmaktadır.
 *   
 *   Bu örnek Deneyap Sıcaklık Nem Ölçer Algılayıcısı ve Deneyap OLED ekran için oluşturulmuştur
 *      ------> www.....com <------ //docs
 *      ------> https://github.com/deneyapkart/deneyap-sicaklik-nem-olcer-arduino-library  <------
 *      ------> www.....com <------ //docs oled
 *      ------> https://github.com/deneyapkart/deneyap-oled-ekran-arduino-library  <------
 *     
*/
#include <Deneyap_SicaklikNemOlcer.h>                       // Deneyap_SicaklikNemOlcer.h kütüphane eklenmesi
#include <Deneyap_OLED.h>                                   // Deneyap_OLED kütüphane eklenmesi

OLED OLED;                                                  // OLED için class tanımlaması
TempHum SicNem;                                             // TempHum için class tanımlaması
  
void setup() {
<<<<<<< HEAD
   Serial.begin(115200);                                    // Seri haberleşme başlatılması
   SicNem.begin(0x70);                                      // begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatılması
   OLED.begin(0x7A);                                        // begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatılması
   OLED.clearDisplay();                                     // OLED ekranı silinmesi        
=======
   Serial.begin(115200);                                    // seri terminal başlatıldı  
   if(!SicNem.begin(0x70)){                                 //begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatıldı
      delay(3000);
      Serial.println("SHTC3 I2C bağlantısı başarısız ");    //I2C bağlantısı başarısız olursa seri terminale yazdırıldı
   }  
   OLED.begin(0x7A);                                        //begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatıldı
   OLED.clearDisplay();                                     //OLED ekranı silindi        
>>>>>>> 1ef3a205c8e9251cd8ebffb38aa0c3b22a8d3e6b
}

void loop() {  
   float Tempvalue = SicNem.getTempValue();                  // Sıcaklık değeri alınmaso
   Serial.print("   Sıcaklık = ");
   Serial.print(Tempvalue);
   OLED.setTextXY(1,0);                                      // Satır ve sutun ayarlanması  
   OLED.putString("Sicaklik: ");
   OLED.setTextXY(1,10);
   OLED.putFloat(Tempvalue);                                 // Sıcaklık değeri OLED ekrana yazdırılması
     
   float Humvalue = SicNem.getHumValue();                    // Nem değeri alınması
   Serial.print("°C   Nem = %");
   Serial.println(Humvalue);
   OLED.setTextXY(3,0);            
   OLED.putString("Nem: ");
   OLED.setTextXY(3,5);
   OLED.putFloat(Humvalue);
}   
