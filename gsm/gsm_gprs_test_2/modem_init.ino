void modem_init()
{
  Serial.println("Please wait.....");
  gsm.println("AT"); //test communication
  delay(1000);
  gsm.println("AT+CMGF=1"); //sets the GSM Module in text mode
  delay(1000);
  gsm.println("AT+CNMI=2,2,0,0,0"); //AT Command to recieve a live SMS
  delay(1000);
}
