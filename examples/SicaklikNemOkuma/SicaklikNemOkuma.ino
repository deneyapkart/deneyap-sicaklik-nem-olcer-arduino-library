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
 *      ------> https://github.com/deneyapkart/deneyap-sicaklik-nem-olcer-arduino-library  <------ 
 *     
 */
#include <Deneyap_SicaklikNemOlcer.h>               // Deneyap_SicaklikNemOlcer.h kütüphanesi eklendi

TempHum SHTC3;                                      //SHTC3 örneğini tanımla
  
void setup() {
   Serial.begin(115200);                            // seri terminal başlatıldı  
   if(!SHTC3.begin(0x70)){                          //begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatıldı
      delay(3000);
      Serial.println("I2C bağlantısı başarısız ");  //I2C bağlantısı başarısız olursa seri terminale yazdırıldı
   }
   
   uint16_t READ_ID = SHTC3.getReadID();            // Read ID değeri alındı
   Serial.print("READ_ID = ");
   Serial.print(READ_ID);
}

void loop() {  
   float Tempvalue = SHTC3.getTempValue();          //Sıcaklık değeri alındı
   Serial.print("Sıcaklık = ");
   Serial.print(Tempvalue);
  
   float Humvalue = SHTC3.getHumValue();           // Nem değeri alındı
   Serial.print("°C   Nem = %");
   Serial.println(Humvalue);

   delay(1000);                                    // 1 saniye bekleme süresi
}   
