#include<SoftwareSerial.h>
SoftwareSerial myGSM(9,10); //9-RX==10-TX FOR Arduino
char c;
void setup() {
  // put your setup code here, to run once:
  myGSM.begin(9600); // Setting the baud rate of GSM Module 
  Serial.begin(9600); //Setting the baud rate of Serial Monitor (arduino)
  delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Keep reading from the Arduino Serial Monitor and send to SIM900A 
    if  (Serial.available ()>0) 
    {  c  =  Serial.read (); 
      myGSM.write (c);   
       }
       
   // Keep reading from SIM800 and send to Arduino Serial Monitor 
    if  (myGSM.available ()>0) 
    {  c  =  myGSM.read (); 
      Serial.write (c);}
 
    
}
