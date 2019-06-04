#include <SoftwareSerial.h>

SoftwareSerial BTSerial(9, 8);
char c= ' ';
boolean NL = true;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("ahh");
  BTSerial.begin(38400);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Read from the Bluetooth module and send to the Arduino Serial Monitor
    if (BTSerial.available())
    {
        c = BTSerial.read();
        Serial.write(c);
    }
 
 
    // Read from the Serial Monitor and send to the Bluetooth module
    if (Serial.available())
    {
        c = Serial.read();
        BTSerial.write(c);   
 
        // Echo the user input to the main window. The ">" character indicates the user entered text.
        if (NL) { Serial.print(">");  NL = false; }
        Serial.write(c);
        if (c==10) { NL = true; }
    }
}
