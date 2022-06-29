#include <SoftwareSerial.h>
//port 17
SoftwareSerial mySerial(2, 3); // CONNECTION WITH GSM TX/RX
void setup() {
  // put your setup code here, to run once:
   mySerial.begin(9600);   // Setting the baud rate of GSM Module 

  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)


}

void loop() {
  // put your main code here, to run repeatedly:
  //if gsm module will respon, this respon will see on serial monitor 
  if (mySerial.available()>0){
    Serial.write(mySerial.read());
    //delay(1000);
  }
  //if i send AT command from serial monitor, this command will send to gsm module
  if (Serial.available()>0){
    mySerial.write(Serial.read());
    //delay(1000);
  }
  

   
  
}
