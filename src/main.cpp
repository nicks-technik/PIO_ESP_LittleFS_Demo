/*********
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp8266-nodemcu-vs-code-platformio-littlefs/  
*********/

// You have to add the following line to the platformio.ini
//     board_build.filesystem = littlefs

// The files must be must be stored in a folder,
// called "data" and then the FS must be uploaded via platformio home->platform->Upload Filesystem Image(all open serial consoles must be closed)
// than you can upload the the sketch

#include <Arduino.h>
#include "LittleFS.h"

void setup()
{
  Serial.begin(9600);

  if (!LittleFS.begin())
  {
    Serial.println("An Error has occurred while mounting LittleFS");
    return;
  }

  File file = LittleFS.open("/text.txt", "r");
  if (!file)
  {
    Serial.println("Failed to open file for reading");
    return;
  }

  Serial.println("File Content:");
  while (file.available())
  {
    Serial.write(file.read());
  }
  file.close();
}

void loop()
{
}