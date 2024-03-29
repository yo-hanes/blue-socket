#include <SoftwareSerial.h>

#define relay1 10  
#define relay2 11  
#define relay3 12  
#define relay4 13  

SoftwareSerial BTserial(0, 1); 


void setup() {
  Serial.begin(9600);
  BTserial.begin(9600);

  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);

  // OFF state
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, LOW);
  digitalWrite(relay4, LOW);
}

void loop() {
  if (BTserial.available() > 0) {
    char command = BTserial.read();

    switch (command) {
      case 'A':
        toggleRelay(relay1);
        break;
      case 'B':
        toggleRelay(relay2);
        break;
      case 'C':
        toggleRelay(relay3);
        break;
      case 'D':
        toggleRelay(relay4);
        break;
      default:
        break;
    }
  }
}

void toggleRelay(int relayPin) {
  if (digitalRead(relayPin) == LOW) 
  {
    digitalWrite(relayPin, HIGH);  
    Serial.print("Relay ");
    Serial.print(relayPin - 9);
    Serial.println(" is ON");
  } 
  else {
    digitalWrite(relayPin, LOW);   
    Serial.print("Relay ");
    Serial.print(relayPin - 9);
    Serial.println(" is OFF");
  }
}
