#include <SoftwareSerial.h>
#include <String.h>

#include "DHT.h";
#define DHTpin 8
#define DHTTYPE DHT22
DHT dht(DHTpin,DHTTYPE);
 
SoftwareSerial mySerial(9, 8);

float temp=0.0;
float humi=0.0;

void setup()
{
  mySerial.begin(9600);               // the GPRS baud rate   
  Serial.begin(9600);    // the GPRS baud rate 
  dht.begin();
  
}
 
void loop()
{
      temp= 50/*dht.readTemperature()*/;
      humi=dht.readHumidity();
      delay(2);          
       Send2Pachube();
   
  if (mySerial.available())
    Serial.write(mySerial.read());
}
void Send2Pachube()
{
  mySerial.println("AT");
  delay(1000);

  mySerial.println("AT+CPIN?");
  delay(1000);

  mySerial.println("AT+CREG?");
  delay(1000);

  mySerial.println("AT+CGATT?");
  delay(1000);

  mySerial.println("AT+CIPSHUT");
  delay(1000);

  mySerial.println("AT+CIPSTATUS");
  delay(2000);

  mySerial.println("AT+CIPMUX=0");
  delay(2000);
 
  ShowSerialData();
 
  mySerial.println("AT+CSTT=\"Telenor Internet\"");//start task and setting the APN,
  delay(1000);
 
  ShowSerialData();
 
  mySerial.println("AT+CIICR");//bring up wireless connection
  delay(3000);
 
  ShowSerialData();
 
  mySerial.println("AT+CIFSR");//get local IP adress
  delay(2000);
 
  ShowSerialData();
 
  mySerial.println("AT+CIPSPRT=0");
  delay(3000);
 
  ShowSerialData();
  
  mySerial.println("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",\"80\"");//start up the connection
  delay(6000);
 
  ShowSerialData();
 
  mySerial.println("AT+CIPSEND");//begin send data to remote server
  delay(4000);
  ShowSerialData();
  
    String str1="GET http://api.thingspeak.com/update?api_key=E90BXKT472WIBC0W&" + String(temp);
    //String str2="GET http://api.thingspeak.com/update?api_key=E90BXKT472WIBC0W&field2=" + String(humi);
  mySerial.println(str1);//begin send data to remote server
  //mySerial.println(str2);//begin send data to remote server
  delay(4000);
  ShowSerialData();

  mySerial.println((char)26);//sending
  delay(5000);//waitting for reply, important! the time is base on the condition of internet 
  mySerial.println();
 
  ShowSerialData();
 
  mySerial.println("AT+CIPSHUT");//close the connection
  delay(100);
  ShowSerialData();
} 
void ShowSerialData()
{
  while(mySerial.available()!=0)
    Serial.write(mySerial.read());
}
