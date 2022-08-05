/*
 *   Sıcaklık Nem Okuma örneği,
 *   
 *   Bu örnekte temel konfigürasyon ayarları yapılmaktadır. 
 *   Saniyede bir sıcaklık ve nem değerlerini alınmaktadır.
 *   Ardından değerler seri terminale yazdırmaktadır.  
 *   
 *   Bu algılayıcı I2C haberleşme protokolü ile çalışmaktadır.
 *   
 *   Bu örnek Deneyap Sıcaklık Nem Ölçer Algılayıcısı için oluşturulmuştur
 *      ------> www.....com <------ //docs
 *      ------>  https://github.com/deneyapkart/deneyap-sicaklik-nem-olcer-arduino-library  <------ 
 *     
 */
#include <Deneyap_SicaklikNemOlcer.h>               // Deneyap_SicaklikNemOlcer kütüphanesi eklenmesi

TempHum SHTC3;                                      // SHTC3 için class tanımlaması
  
void setup() {
   Serial.begin(115200);                            // Seri haberleşme başlatılması
   if(!SHTC3.begin(0x70)){                          // begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatılması
      delay(3000);
      Serial.println("I2C bağlantısı başarısız ");  // I2C bağlantısı başarısız olursa seri terminale yazdırılması
   }
   
   uint16_t READ_ID = SHTC3.getReadID();            // Read ID değeri alınması
   Serial.print("READ_ID = ");
   Serial.print(READ_ID);
}

void loop() {  
   float Tempvalue = SHTC3.getTempValue();          // Sıcaklık değeri alınması
   Serial.print("Sıcaklık = ");
   Serial.print(Tempvalue);
  
   float Humvalue = SHTC3.getHumValue();            // Nem değeri alınması
   Serial.print("°C   Nem = %");
   Serial.println(Humvalue);

   delay(1000);                                     // 1 saniye bekleme süresi
}   
