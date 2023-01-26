// setup - vykonava sa len raz pri sputeni programu
// pokusi sa pripojit k wifi
void setup()
{
  Serial.begin(9600);
}

// vykonava sa dookola
void loop()
{

// Váš kód ...
// pomocne premenne
  poc++;
  String hodnota1=String(poc);
  String hodnota2="22";
  String payload="";

  // NACITANIE DAT Z WEBU
  

  int hodnota3 = (payload[2]); // nacitanie 2. znaku z html (>)
  Serial.println(hodnota3); // vypisanie ASCII (62) hodnoty znaku >, ktory bol nacitany v payloade
  delay(2000); // 2 sekundy 

  // ZAPIS DAT NA WEB
  if (WiFi.status() == WL_CONNECTED) 
  {
    HTTPClient http;
    String server_name = "https://iot-php-tsaruk.azurewebsites.net"; // nazov vasho webu a web stranky, ktoru chcete nacitat
    server_name += "temperature="; // nazov premennej na webe
    server_name += temperature; // hodnota premmenej
    server_name += "&humidity="; // nazov premennej na webe
    server_name += humidity; // hodnota premennej
    http.begin(server_name.c_str());
    int httpCode = http.GET(); // http code

    if (httpCode>0) 
    {
      payload= http.getString();
      Serial.print("HTTP Response code: ");
      Serial.println(httpCode); // vypisanie http code do Serial monitoru (200 - OK)
      Serial.println(payload); // vypisanie celej html stranky, ktora sa na tejto url nachadza (zobrazene v serial monitore)

      int hodnota3 = (payload[26]); // nacitanie 2. znaku z html (>)
      Serial.println(hodnota3); // vypisanie ASCII (62) hodnoty znaku >, ktory bol nacitany v payloade
      delay(2000); // 2 sekundy 
    }
    http.end();
  }  
}