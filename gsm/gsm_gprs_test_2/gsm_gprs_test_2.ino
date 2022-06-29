//-----Electronics-project-hub>com------//
#include <SoftwareSerial.h>
#include "DHT.h";
#define DHTpin 8
#define DHTTYPE DHT22
DHT dht(DHTpin,DHTTYPE);

SoftwareSerial gsm(9,10); // RX, TX

float humi = 0;
float temp = 0;
void setup()
{
  Serial.begin(9600);
  gsm.begin(9600);
  dht.begin();
  modem_init();
  data_init();
  internet_init();
}
void loop()
{ 
  humi = dht.readHumidity();
  temp = dht.readTemperature();
  Serial.print("Humidity: ");
  Serial.print(humi);
  Serial.print("%");
  Serial.print(",\t");
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println("*C");
  delay(2000);
  Send_data();
}
