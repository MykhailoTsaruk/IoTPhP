#include <WiFiClientSecure.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define LED_RED   32
#define LED_GREEN 33
#define LED_BLUE  25

#define BUTTON    35  

#define RST_PIN   15
#define SS_PIN    5

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance
LiquidCrystal_I2C lcd(0x27,16,2);  // Устанавливаем дисплей

const char* ssid = "qwerty";
const char* pass = "1298347612";
WiFiClient wifi;

int balance = 0;

void blink_led_green(){
  for (int i = 0; i < 3; i++){
    digitalWrite(LED_GREEN, HIGH);
    delay(100);
    digitalWrite(LED_GREEN, LOW);
    delay(100);
  }
}

void blink_led_blue(){
  for (int i = 0; i < 3; i++){
    digitalWrite(LED_BLUE, HIGH);
    delay(100);
    digitalWrite(LED_BLUE, LOW);
    delay(100);
  }
}

void off_led(){
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_BLUE, LOW);
}

// void blink(){
//     digitalWrite(LED_RED, HIGH);
//     delay(200);
//     digitalWrite(LED_GREEN, HIGH);
//     delay(200);
//     digitalWrite(LED_BLUE, HIGH);
//     delay(200);
//     digitalWrite(LED_BLUE, LOW);
//     delay(200);
//     digitalWrite(LED_GREEN, LOW);
//     delay(200);
//     digitalWrite(LED_RED, LOW);
//     delay(200);
// }

void dump_card(){
  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
	if ( ! mfrc522.PICC_IsNewCardPresent()) {
		return;
	}

	// Select one of the cardsq
	if ( ! mfrc522.PICC_ReadCardSerial()) {
		return;
	}

  off_led();
  blink_led_green();
  
  mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
  
  blink_led_green();
  delay(500);
}

void read_data(int *balance){
  
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  blink_led_blue();
  // Prepare key - all keys are set to FFFFFFFFFFFFh at chip delivery from the factory.
  MFRC522::MIFARE_Key key;
  for (byte i = 0; i < 6; i++) key.keyByte[i] = 0xFF;

  //some variables we need
  byte block;
  byte len;
  MFRC522::StatusCode status;

  //-------------------------------------------
  //-------------------------------------------

  // mfrc522.PICC_DumpDetailsToSerial(&(mfrc522.uid)); //dump some details about the card

  //mfrc522.PICC_DumpToSerial(&(mfrc522.uid));      //uncomment this to see all blocks in hex

  //-------------------------------------------

  // Serial.print(F("Balance: "));

  byte buffer1[18];

  block = 4;
  len = 18;

  //------------------------------------------- GET FIRST NAME
  status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, 4, &key, &(mfrc522.uid)); //line 834 of MFRC522.cpp file
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("Authentication failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }

  status = mfrc522.MIFARE_Read(block, buffer1, &len);
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("Reading failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }

  // //PRINT FIRST NAME
  // for (uint8_t i = 0; i < 16; i++)
  // {
  //   if (buffer1[i] != 32)
  //   {
  //     Serial.write(buffer1[i]);
  //   }
  // }
  // Serial.print(" ");

  //---------------------------------------- GET LAST NAME

  byte buffer2[18];
  block = 1;

  status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, 1, &key, &(mfrc522.uid)); //line 834
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("Authentication failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }

  status = mfrc522.MIFARE_Read(block, buffer2, &len);
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("Reading failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }

  // //PRINT LAST NAME
  // for (uint8_t i = 0; i < 16; i++) {
  //   Serial.write(buffer2[i] );
  // }

  //----------------------------------------

  int buff = 0;
  for (int i = 0; i < 18; i++){
    if (buffer2[i] != '$') {
      buff += buffer2[i]-'0';
      buff *= 10; 
    }
    else if (buffer2[i] == '$'){
      buff /= 10; 
      break;
    }
  }

  if ((*balance) != buff){
    (*balance) = buff;
  }

  delay(100); //change value if you want to read cards faster

  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();

  blink_led_blue();

}

void setup() {
  Serial.begin(230400);
  
  WiFi.begin(ssid, pass);
  Serial.println("Connecting");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay (1000);
    Serial.print(".");
  }

  Serial.println("Connected");
  
  
  //LED
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED,   OUTPUT);
  pinMode(LED_BLUE,  OUTPUT);
  //BUTTONS
  pinMode(BUTTON, INPUT);

  while (!Serial);		// Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
	SPI.begin();			// Init SPI bus
	mfrc522.PCD_Init();		// Init MFRC522
	delay(4);				// Optional delay. Some board do need more time after init to be ready, see Readme
	mfrc522.PCD_DumpVersionToSerial();	// Show details of PCD - MFRC522 Card Reader details
  Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));

  lcd.init();                     
  lcd.backlight();
}

void loop() {

  if (digitalRead(BUTTON) == LOW) dump_card();
  else{ read_data(&balance); Serial.println(balance);}
  
  String payload="";
  
  if (WiFi.status() == WL_CONNECTED) // ak je ESP pripojene k wifi
  {
    HTTPClient http; // vytvorenie HTTP clienta
    String server_name = "https://iot-php-tsaruk.azurewebsites.net/"; // nazov vasho webu a web stranky, ktoru chcete nacitat
    http.begin(server_name.c_str());
    int httpCode = http.GET(); // http code
    if (httpCode>0) 
      payload= http.getString();

    http.end();
  }
  if (WiFi.status() == WL_CONNECTED) 
  {
    HTTPClient http;
    String server_name = "https://phpipaiot.azurewebsites.net/getParameters.php/?"; // nazov vasho webu a web stranky, ktoru chcete nacitat
    server_name += "balance="; // nazov premennej na webe
    server_name += balance; // hodnota premmenej
    http.begin(server_name.c_str());
    int httpCode = http.GET(); // http code
    if (httpCode>0) 
    {
      payload= http.getString();
      delay(100); // 0.1 sekunda 
    }
    http.end();
  }


  lcd.setCursor(0, 0);
 
  
  lcd.print("Welcome");
  delay(100);
  lcd.setCursor(2, 1);
  lcd.print("Weed");
  

  lcd.setCursor(8, 1);
  for (int thisChar = 2; thisChar < 5; thisChar++) {
    lcd.print(thisChar);
    delay(300);
    lcd.clear();
  }


} 
