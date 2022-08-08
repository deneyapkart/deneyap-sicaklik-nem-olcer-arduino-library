# Deneyap Sıcaklık&Nem Ölçer SHTC3 Arduino Kütüphanesi

***** Fotoğraf eklenecek ****

Deneyap Sıcaklık&Nem Ölçer SHTC3 için Arduino kütüphanesidir.

## :mag_right:Özellikler 
- `Ürün ID` **M01**, **mpv1.0**
- `MCU` SHTC3
- `Ağırlık`
- `Modul Boyutları`
- `I2C Adres` 0x70

| Adres |  | 
| :---  | :---     |
| 0x70 | varsayılan adres |

## :closed_book:Dokümanlar
Deneyap Sıcaklık&Nem Ölçer SHTC3

[SHTC3-datasheet](https://media.digikey.com/pdf/Data%20Sheets/Sensirion%20PDFs/HT_DS_SHTC3_D1.pdf)

[Arduino Kütüphanesi Nasıl İndirilir](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries)

## :pushpin:Deneyap Sıcaklık&Nem Ölçer SHTC3
Bu Arduino kütüphanesi Deneyap Sıcaklık&Nem SHTC3 Ölçerinin I2C çevre birimi ile kullanılmasını sağlar. Arduino ile uyumlu, I2C çevre birimine sahip herhangi bir geliştirme kartı ile bu kütüphaneyi projelerinizde kullanabilirsiniz. 

## :globe_with_meridians:Repo İçeriği
- `/docs` README_tr.md ve ürün fotoğrafları
- `/examples` .ino uzantılı örnek uygulamalar
- `/src` kütüphane için .cpp ve .h uzantılı dosyalar
- `keywords.txt` Arduino IDE'de vurgulanacak anahtar kelimeler
- `library.properties` Arduino yöneticisi için genel kütüphane özellikleri

## Sürüm Geçmişi
1.0.1 - örnek uygulama hatası giderme
1.0.0 - ilk sürüm

## :rocket:Donanım Bağlantıları
- Deneyap Sıcaklık&Nem Ölçer ile kullanılan geliştirme kartı I2C kablosu ile bağlanabilir
- veya jumper kablolar ile 3V3, GND, SDA ve SCL bağlantıları yapılabilir.

| Sıcaklık&Nem Ölçer | Fonksiyon| Kart pinleri |
| :---     | :---   |   :---  |
| 3.3V     | Güç    | 3.3V    |
| GND      | Toprak |GND      |
| SDA      | I2C Data  | SDA pini |
| SCL      | I2C Clock | SCL pini|
| NC          | bağlantı yok |   |

## :bookmark_tabs:Lisans Bilgisi 
Lisans bilgileri için [LICENSE](https://github.com/deneyapkart/deneyap-sicaklik-nem-olcer-arduino-library/blob/master/LICENSE) dosyasını inceleyin.