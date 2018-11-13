#include <WioCellLibforArduino.h>
#include "SHT31.h"

WioCellular Wio;
SHT31 sht31 = SHT31();

void setup() {
  delay(200);
  SerialUSB.begin(115200);
  SerialUSB.println("### Initialize...");
  Wio.Init();
  SerialUSB.println("### Grove Power On...");
  Wio.PowerSupplyGrove(true);
  SerialUSB.println("### SHT31 begin sensing...");
  sht31.begin();
}

void loop() {
  float temp = sht31.getTemperature();
  float hum = sht31.getHumidity();
  SerialUSB.print("Temp = "); 
  SerialUSB.print(temp);
  SerialUSB.println(" C"); //The unit for  Celsius because original arduino don't support speical symbols
  SerialUSB.print("Hum = "); 
  SerialUSB.print(hum);
  SerialUSB.println("%"); 
  SerialUSB.println();
  delay(5000);
}
