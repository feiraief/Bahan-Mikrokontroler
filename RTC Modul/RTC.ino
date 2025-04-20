#include <Wire.h>
#include <RTClib.h>

RTC_DS3231 rtc;

const int PinSCL = 1;
const int PinSDA = 2;

void setup() {
  Serial.begin(115200);
  Wire.begin(PinSDA,PinSCL);

  if(!rtc.begin()){
    Serial.println("RTC DS3231 TIDAK DITEMUKAN");
    while(1);
  }
  if(rtc.lostPower()){
    Serial.println("MENSINKORNKAN WAKTU");
    rtc.adjust(DateTime(F(__DATE__),F(__TIME__)));
  }

}

void loop() {
  DateTime now = rtc.now();

  Serial.print(now.day(), DEC);
  Serial.print("/");
  Serial.print(now.month(), DEC);
  Serial.print("/");
  Serial.print(now.year(), DEC);
  Serial.print("  ");

  Serial.print(now.hour(), DEC);
  Serial.print(" : ");
  Serial.print(now.minute(), DEC);
  Serial.print(" : ");
  Serial.println(now.second(), DEC);
    
  delay(1000);
}
