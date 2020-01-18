#include <SPI.h>
#include <SD.h>

File SensorDataFile;

int chipSelect = 4;
int SensorPin=A0;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);

  Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    return;
  }
  Serial.println("card initialized.");
  
 SensorDataFile = SD.open("datalog.txt", FILE_WRITE);

}

void loop() {
  // make a string for assembling the data to log:
  
  String dataString = "";

  // read sensor and append to the string:
    int sensor = analogRead(SensorPin);
    dataString += String(sensor);
      dataString += ",";
  
  // if the file is available, write to it:
  if (SensorDataFile) {
    SensorDataFile.println(dataString);
  }
  
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  }
}

