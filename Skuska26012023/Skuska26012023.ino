#include <WiFiClientSecure.h>
#include <WiFi.h>
#include <HTTPClient.h>

#include "DHT.h"
#define DHT11PIN 16

WiFiClient wifi;
DHT dht(DHT11PIN, DHT11);

const char* ssid = "qwerty";
const char* pass = "1298347612";

int poc=0;


void setup()
{
  Serial.begin(9600);
  dht.begin();

  WiFi.begin(ssid, pass);
  Serial.println("Connecting");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(100);
    Serial.println("Connecting...");
  }

  Serial.println("Connected");


}

void loop()
{
  int temperature = dht.readTemperature();
  int humidity = dht.readHumidity();

  if (WiFi.status() == WL_CONNECTED) 
  {
    HTTPClient http;
    String server_name = "https://iot-php-tsaruk.azurewebsites.net/WebAzure/skuska26012023/getParameters.php?"; // nazov vasho webu a web stranky, ktoru chcete nacitat
    server_name += "temperature="; // nazov premennej na webe
    server_name += temperature; // hodnota premmenej
    server_name += "&humidity="; // nazov premennej na webe
    server_name += humidity; // hodnota premennej
    http.begin(server_name.c_str());
    delay(1000);
    http.end();
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("C ");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println("%");
  delay(1000);
}