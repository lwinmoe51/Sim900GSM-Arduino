void Send_data()
{
  gsm.print("AT+HTTPPARA=");
  gsm.print('"');
  gsm.print("URL");
  gsm.print('"');
  gsm.print(',');
  gsm.print('"');
  gsm.print("http:");
  gsm.print('/');
  gsm.print('/');
  //-----------------------Your API Key Here----------------------//
  //Replace xxxxxxxxxxx with your write API key.
  gsm.print("api.thingspeak.com/update?api_key=E90BXKT472WIBC0W&field1="); 
 
  //---------------------------------------------------------------//
  gsm.print(temp); //>>>>>>  variable 1 (temperature)
  gsm.print("&field2=");
  gsm.print(humi); //>>>>>> variable 2 (Humidity)
  gsm.write(0x0d);
  gsm.write(0x0a);
  delay(1000);
  gsm.println("AT+HTTPACTION=0");
  delay(1000);
}
