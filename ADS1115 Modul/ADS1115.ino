#include <Adafruit_ADS1X15.h>
Adafruit_ADS1115 ads;
int16_t rawValue;
int moisture;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  if (!ads.begin()) {
    Serial.println("Failed to initialize ADS.");
    while (1);
  }
  ads.setGain(GAIN_ONE);
}

void loop() {
  // put your main code here, to run repeatedly:
  rawValue = ads.readADC_SingleEnded(0);
  float voltage = ads.computeVolts(rawValue);
  moisture = map(rawValue, 40, 6000, 0, 100);
  moisture = constrain(moisture, 0, 100);

  Serial.print("ADC : ");
  Serial.println(rawValue);
  Serial.print("Voltage : ");
  Serial.println(voltage);
  Serial.print("V");
  Serial.print("moisture : ");
  Serial.print(moisture);
  Serial.println("%");
  delay(1000);

}
