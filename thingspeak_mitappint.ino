#include <ThingSpeak.h>               // add librery
#include <ESP8266WiFi.h>
#define ledPin1 D4
#define ledPin2 D3

WiFiClient  client;
unsigned long counterChannelNumber = IDTHINGSPEAK;                // Channel ID
const char * myCounterReadAPIKey = "API_READ";      // Read API Key
const int FieldNumber1 = 1;                                 // The field you wish to read
const int FieldNumber2 = 2;                                 // The field you wish to read

void setup()
{
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  Serial.begin(115200);
  Serial.println();

  WiFi.begin("username", "password");           // write wifi name & password           

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(client);
}

void loop() 
{
 int A = ThingSpeak.readLongField(counterChannelNumber, FieldNumber1, myCounterReadAPIKey);
 Serial.println(A);
 digitalWrite(ledPin1,A);
 
 int B = ThingSpeak.readLongField(counterChannelNumber, FieldNumber2, myCounterReadAPIKey);
 Serial.println(B);
 digitalWrite(ledPin2,B);
}
