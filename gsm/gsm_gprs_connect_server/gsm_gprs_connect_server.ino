#include<SoftwareSerial.h> // serial software library for interfacing gsm module
SoftwareSerial myGSM(9,10); 

String pvtKey="wY9DPG5vzpH99KNrNkx2";     // private key for posting data to sparkfun
String publicKey="w5nXxM6rp0tww5YVYg3G";  // public key for open page of sparkfun 
String url="";
String ip="\"data.sparkfun.com\"";        // sparkfun server ip or url
int port=80;                              // sparkfun server port

String SendCmd="AT+CIPSEND=";           // sending number of byte command
String Start="AT+CIPSTART=\"TCP\"";     // TCPIP start command 


void setup() {
  // put your setup code here, to run once:
  myGSM.begin(9600); //init myGSM for GSM
  Serial.begin(9600); //init for serial monitor
  Serial.println("Sending data to server by Lwin Moe");
  delay(2000);
  Serial.println("Initializing GSM");
  initGSM(); //init GSM module
}

void loop() {
  // put your main code here, to run repeatedly:

}
