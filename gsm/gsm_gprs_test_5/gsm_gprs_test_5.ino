#include<SoftwareSerial.h>
#include<String.h>
SoftwareSerial gsm(9,10);

void setup() {
  // put your setup code here, to run once:
  gsm.begin(9600);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  SendMyNumber();
  if(gsm.available())
    Serial.write(gsm.read());
}

void SendMyNumber(){
  gsm.println("AT");
  delay(1000);

  gsm.println("AT+CPIN?");
  delay(1000);

  gsm.println("AT+CREG?");
  delay(1000);

  gsm.println("AT+CGATT?");
  delay(1000);

  gsm.println("AT+CIPSHUT");
  delay(1000);

  gsm.println("AT+CIPSTATUS");
  delay(2000);

  gsm.println("AT+CIPMUX=0");
  delay(2000);
 
  ShowSerialData();
 
  gsm.println("AT+CSTT=\"mytel\"");//start task and setting the APN,
  delay(1000);
 
  ShowSerialData();
 
  gsm.println("AT+CIICR");//bring up wireless connection
  delay(3000);
 
  ShowSerialData();
 
  gsm.println("AT+CIFSR");//get local IP adress
  delay(2000);
 
  ShowSerialData();
 
  gsm.println("AT+CIPSPRT=0");
  delay(3000);
 
  ShowSerialData();
  
  gsm.println("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",\"80\"");//start up the connection
  delay(6000);
 
  ShowSerialData();
 
  gsm.println("AT+CIPSEND");//begin send data to remote server
  delay(4000);
  ShowSerialData();
  
    String str1="GET http://api.thingspeak.com/update?api_key=E90BXKT472WIBC0W&field1=" + String(50);
   // String str2="GET http://api.thingspeak.com/update?api_key=E90BXKT472WIBC0W&field2=" + String(humi);
  gsm.println(str1);//begin send data to remote server
  //mySerial.println(str2);//begin send data to remote server
  delay(4000);
  ShowSerialData();

  gsm.println((char)26);//sending
  delay(5000);//waitting for reply, important! the time is base on the condition of internet 
  gsm.println();
 
  ShowSerialData();
 
  gsm.println("AT+CIPSHUT");//close the connection
  delay(100);
  ShowSerialData();
}
void ShowSerialData()
{
  while(gsm.available()!=0)
    Serial.write(gsm.read());
}
