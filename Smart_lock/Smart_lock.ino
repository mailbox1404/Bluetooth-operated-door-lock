//NOTE: NOW THE PASSWORD CAN ONLY BE CHANGED FROM THE ANDROID APP. UPDATE YOUR APP TO THE LATEST VERSION.
#include <EEPROM.h>

/*
Written by Rupak Poddar
www.youtube.com/RupakPoddar
www.github.com/RupakPoddar

Wiring Setup:
Bluetooth Module Rx   - Arduino Pin Tx
Bluetooth Module Tx   - Arduino Pin Rx
Bluetooth Module VCC  - Arduino 5v
Bluetooth Module GND  - Arduino GND
Lock or relay module  - Arduino pin 12
*/

int door_lock = 12;   //Connect the door lock at pin 12 of the Arduino board.
int interval = 1500;  //Change the lock delay from here 

void Unlock(){
  digitalWrite(door_lock, HIGH);
  delay(interval);
  digitalWrite(door_lock, LOW);
}

void Lock(){
  //Do nothing      //ADD THE COMMANDS HERE(if any) THAT SHOULD BE EXECUTED WHEN THE 'LOCK' BUTTON IS PRESSED.
}

void setup() 
{
Serial.begin(9600);
pinMode(door_lock, OUTPUT);
}

void loop()
{
  String input;
 
  while(Serial.available()){
    input = Serial.readString();

    if(EEPROM.read(0) != 1){
    Serial.println("Your password is \"None\"");
    Serial.println("Change it");{
    if(input == "Lock"){
      Lock();
    }
    else if(input == "None"){
      Serial.println("Unlocked");
      Unlock();
    }
    else if(input.substring(0,4) == "None" && input.substring(4,6) == "||"){
      EEPROM.write(0, 1);
      String New_password = input.substring(6);
      Set_password(New_password);
    }
    else{
      Serial.println("Wrong password");
    }}
  }
  else{
    Evaluate(input);
  }
  }
  input = "";
}

void Set_password(String data){
  int str_length = data.length();
  EEPROM.write(1, str_length);
  for (int i = 0; i < str_length; i++){
    EEPROM.write(i+2, data[i]);
  }
  Serial.println("Password changed");
}

void Evaluate(String data){
  int str_length = EEPROM.read(1);
  char password[str_length];
  for(int i = 2; i < str_length+2; i++){
    password[i-2] = EEPROM.read(i);
  }
  String Password = String(password);
  String get_data = data;

  if(get_data == "Lock"){
    Lock();
  }
  else if(Password == get_data){
    Serial.println("Unlocked");
    Unlock();
  }
  else if(get_data.substring(0, str_length) == Password && get_data.substring(str_length, str_length+2) == "||"){
    Set_password(get_data.substring(str_length+2));
  }
  else{
    Serial.println("Wrong password");
  }
}
