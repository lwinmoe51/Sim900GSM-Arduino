void data_init()
{
  Serial.println("Please wait.....");
  gsm.println("AT");
  delay(1000); delay(1000);
  gsm.println("AT+CPIN?");
  delay(1000); delay(1000);
  gsm.print("AT+SAPBR=3,1");
  gsm.write(',');
  gsm.write('"');
  gsm.print("contype");
  gsm.write('"');
  gsm.write(',');
  gsm.write('"');
  gsm.print("GPRS");
  gsm.write('"');
  gsm.write(0x0d);
  gsm.write(0x0a);
  delay(1000); ;
  gsm.print("AT+SAPBR=3,1");
  gsm.write(',');
  gsm.write('"');
  gsm.print("APN");
  gsm.write('"');
  gsm.write(',');
  gsm.write('"');
  //------------APN------------//
  gsm.print("mytel"); //APN Here
  //--------------------------//
  gsm.write('"');
  gsm.write(0x0d);
  gsm.write(0x0a);
  delay(1000);
  gsm.print("AT+SAPBR=3,1");
  gsm.write(',');
  gsm.write('"');
  gsm.print("USER");
  gsm.write('"');
  gsm.write(',');
  gsm.write('"');
  gsm.print("  ");
  gsm.write('"');
  gsm.write(0x0d);
  gsm.write(0x0a);
  delay(1000);
  gsm.print("AT+SAPBR=3,1");
  gsm.write(',');
  gsm.write('"');
  gsm.print("PWD");
  gsm.write('"');
  gsm.write(',');
  gsm.write('"');
  gsm.print("  ");
  gsm.write('"');
  gsm.write(0x0d);
  gsm.write(0x0a);
  delay(2000);
  gsm.print("AT+SAPBR=1,1");
  gsm.write(0x0d);
  gsm.write(0x0a);
  delay(3000);
}
