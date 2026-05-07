#define SENSOR_BIT 9
#include <SchooMyUtilities.h>
#include <OneWire.h>
#include <DallasTemperature.h>
SchooMyUtilities scmUtils = SchooMyUtilities();

OneWire _tempWire_19(19);
DallasTemperature _tempSensors_19(&_tempWire_19);
float _sbeGetTemperature(DallasTemperature& sensors) {
  sensors.requestTemperatures();
  return sensors.getTempCByIndex(0);
}

void setColor_6_5_3(int r, int g, int b) {
  analogWrite(6, 255 - r);
  analogWrite(5, 255 - g);
  analogWrite(3, 255 - b);
}
void setup() {
  Serial.begin(9600);
  _tempSensors_19.begin();
  _tempSensors_19.setResolution(SENSOR_BIT);
  pinMode(A1, INPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop() {
  if ((_sbeGetTemperature(_tempSensors_19) > 0)) {
    setColor_6_5_3(255, 0, 0);
    delay(1000);
  }
  if ((analogRead(A1) > 0)) {
    setColor_6_5_3(255, 249, 0);
    delay(1000);
  }
  Serial.print("温度");
  Serial.print(":");
  Serial.print(_sbeGetTemperature(_tempSensors_19));
  Serial.print(",");
  Serial.print("土壌水分");
  Serial.print(":");
  Serial.print(analogRead(A1));
  Serial.println();
}
