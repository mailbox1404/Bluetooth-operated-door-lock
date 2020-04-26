//Written by Rupak Poddar
//www.youtube.com/RupakPoddar
/*
Wiring Setup-
Bluetooth Module Rx-------Arduino Pin Tx
Bluetooth Module Tx-------Arduino Pin Rx
Bluetooth Module VCC------Arduino 5v
Bluetooth Module GND------Arduino GND
Lock or relay-------------Arduino pin 12
*/
int Lock = 12; // Connect the Lock at the pin 12 of the arduino

String readString;

String password = "default"; // Change password from here, the current password is "default".

void setup() 
{
Serial.begin(9600);
pinMode(Lock, OUTPUT);
}

void loop() 
{
while (Serial.available()) 
{
delay(3); 
char c = Serial.read();
readString += c; 
}
if(readString.length() >0) 
{
if (readString == password)
{
digitalWrite(Lock, HIGH);
delay(1000);                 // Change the delay from here.
digitalWrite(Lock, LOW);
Serial.println("Successfully unlocked");
}

if(readString != password)
{
Serial.println("Wrong Password");
}
readString="";
} 
}
