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
#include <Deneyap_SicaklikNemOlcer.h>                       // Deneyap_SicaklikNemOlcer.h kütüphanesi eklendi
#include <Deneyap_OLED.h>                                   // Deneyap_OLED kütüphanesi eklendi

OLED OLED;                                                  //OLED örneğini tanımla
TempHum SicNem;                                             //TempHum örneğini tanımla
  
void setup() {
   Serial.begin(115200);                                    // seri terminal başlatıldı  
   if(!SicNem.begin(0x70)){                                 //begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatıldı
      delay(3000);
      Serial.println("SHTC3 I2C bağlantısı başarısız ");    //I2C bağlantısı başarısız olursa seri terminale yazdırıldı
   }  
   OLED.begin(0x7A);                                        //begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatıldı
   OLED.clearDisplay();                                     //OLED ekranı silindi        
}

void loop() {  
   float Tempvalue = SicNem.getTempValue();                  //Sıcaklık değeri alındı
   Serial.print("   Sıcaklık = ");
   Serial.print(Tempvalue);
   OLED.setTextXY(1,0);                                      //Satır ve sutun ayarlandı  
   OLED.putString("Sicaklik: ");
   OLED.setTextXY(1,10);
   OLED.putFloat(Tempvalue);                                 //Sıcaklık değeri OLED ekrana yazdırıldı
     
   float Humvalue = SicNem.getHumValue();                    // Nem değeri alındı
   Serial.print("°C   Nem = %");
   Serial.println(Humvalue);
   OLED.setTextXY(3,0);            
   OLED.putString("Nem: ");
   OLED.setTextXY(3,5);
   OLED.putFloat(Humvalue);
}   
