//Node MCU is used in the project 
// Along with three triple light boards representing traffic signals
// Of Three different roads
// The 5V output -> 3.3V input in the MCU 
// Pins of the LED according to color -> MCU Pins


// Due to a technical issue in the LED Boards, in the given Code the keywords HIGH & LOW have been used inversely


#include <ESP8266WiFi.h>
const char* ssid = "You're_Wifi_Name";
const char* password = "You're WiFi Password";

int Red1 = 16 ;
int Yellow1 = 4;
int Green1 = 5 ;

int Red2 = 12;
int Yellow2 = 14 ;
int Green2 = 2;

int Red3 = 3 ;
int Yellow3 = 15;
int Green3 = 13;

WiFiServer server(80);
void setup(){
  Serial.begin(115200);
  delay(10);


// Pins ----------------------------
  pinMode(Red1, OUTPUT);
  pinMode(Yellow1, OUTPUT);
  pinMode(Green1, OUTPUT);
  
  pinMode(Red2, OUTPUT);
  pinMode(Yellow2, OUTPUT);
  pinMode(Green2, OUTPUT);
  
  pinMode(Red3, OUTPUT);
  pinMode(Yellow3, OUTPUT);
  pinMode(Green3, OUTPUT);

//Pins --------------------------


  digitalWrite(Red1, HIGH);
  digitalWrite(Yellow1, HIGH);
  digitalWrite(Green1, HIGH);
  digitalWrite(Red2, HIGH);
  digitalWrite(Yellow2, HIGH);
  digitalWrite(Green2, HIGH);
  
  digitalWrite(Red3, HIGH);
  digitalWrite(Green3, HIGH);
  digitalWrite(Yellow3, HIGH);
 
//-------------------------------------

// WiFI Connection ----------
Serial.println();
Serial.print("Connecting to ");

Serial.println(ssid);
WiFi.begin(ssid, password);
while(WiFi.status()!= WL_CONNECTED)
{
  
    delay(50);
    Serial.print(".");
 }
 
    Serial.println("");
    Serial.println("Wifi Connected");

    server.begin();
    Serial.println("Server started");

    Serial.println("Use this URL to connect: ");
    Serial.print("http://");
    Serial.print(WiFi.localIP());
    Serial.println("/");
  }

  void loop(){
    WiFiClient client = server.available();

    if (!client)
    {
      return;
      
    }

    Serial.println("new client");
    while(!client.available())
    {
      delay(0.5);
    }

    int value = LOW;

    String request = client.readStringUntil('\r');
    Serial.println(request);
    client.flush();


// LED 1 ---------------------------------------------------

    if (request.indexOf("/LED-1=GO") != -1)
    {




      
//    Initial State //
      digitalWrite(Green1, HIGH);
      digitalWrite(Yellow1, HIGH);
      digitalWrite(Red1, HIGH); // L1 - RED 1 OFF
      digitalWrite(Red2, LOW); // L2 - Red ON
      digitalWrite(Red3, LOW); // L3 - Red ON
      digitalWrite(Yellow2, HIGH); // L2 - Yellow  OFF
      digitalWrite(Yellow3, HIGH); // L3 - Yellow OFF
      digitalWrite(Green2, HIGH); // L2 - Green OFF
      digitalWrite(Green3, HIGH); // L3 - Green OFF



//
      digitalWrite(Yellow1, LOW); // L1 - YELLOW ON
      delay(1000);
      digitalWrite(Yellow1, HIGH); // L1 - YELLOW OFF
      delay(1000);
      digitalWrite(Green1, LOW); // L1 - GREEN ON
      
      
      
    }


// LED 2 STUFF ----------------------------------------------
if (request.indexOf("/LED-2=GO") != -1)
    {




      
//    Initial State //
      digitalWrite(Green2, HIGH);
      digitalWrite(Yellow2, HIGH);
      digitalWrite(Red2, HIGH); // L2 - RED 1 OFF
      digitalWrite(Red1, LOW); // L1 - Red ON
      digitalWrite(Red3, LOW); // L3 - Red ON
      digitalWrite(Yellow1, HIGH); // L1 - Yellow  OFF
      digitalWrite(Yellow3, HIGH); // L3 - Yellow OFF
      digitalWrite(Green1, HIGH); // L1 - Green OFF
      digitalWrite(Green3, HIGH); // L3 - Green OFF



//
      digitalWrite(Yellow2, LOW); // L2 - YELLOW ON
      delay(1000);
      digitalWrite(Yellow2, HIGH); // L2 - YELLOW OFF
      delay(1000);
      digitalWrite(Green2, LOW); // L2 - GREEN ON
      
      
      
    }





// LED 3 STUFF ----------------------------------------------
if (request.indexOf("/LED-3=GO") != -1)
    {




      
//    Initial State //
      digitalWrite(Green3, HIGH);
      digitalWrite(Yellow3, HIGH);
      digitalWrite(Red3, HIGH); // L3 - RED 1 OFF
      digitalWrite(Red1, LOW); // L1 - Red ON
      digitalWrite(Red2, LOW); // L2 - Red ON
      digitalWrite(Yellow1, HIGH); // L1 - Yellow  OFF
      digitalWrite(Yellow2, HIGH); // L2 - Yellow OFF
      digitalWrite(Green1, HIGH); // L1 - Green OFF
      digitalWrite(Green2, HIGH); // L2 - Green OFF



//
      digitalWrite(Yellow3, LOW); // L3 - YELLOW ON
      delay(1000);
      digitalWrite(Yellow3, HIGH); // L3 - YELLOW OFF
      delay(1000);
      digitalWrite(Green3, LOW); // L3 - GREEN ON
      
      
      
    }


if (request.indexOf("/LED-M=OFF") != -1)
    {




      
//    Initial State //

     digitalWrite(Red1, HIGH);
     digitalWrite(Red2, HIGH);
     digitalWrite(Red3, HIGH);
     
     digitalWrite(Green1, HIGH);
     digitalWrite(Green2, HIGH);
     digitalWrite(Green3, HIGH);






      digitalWrite(Yellow1, LOW);
      digitalWrite(Yellow2, LOW);
      digitalWrite(Yellow3, LOW); // L3 - RED 1 OFF
      delay(1000);

      digitalWrite(Yellow1, HIGH);
      digitalWrite(Yellow2, HIGH);
      digitalWrite(Yellow3, HIGH); // L3 - RED 1 OFF

      delay(500);

      digitalWrite(Yellow1, LOW);
      digitalWrite(Yellow2, LOW);
      digitalWrite(Yellow3, LOW); // L3 - RED 1 OFF

      delay(1000);

      digitalWrite(Yellow1, HIGH);
      digitalWrite(Yellow2, HIGH);
      digitalWrite(Yellow3, HIGH); // L3 - RED 1 OFF

      delay(500);


      digitalWrite(Red1, LOW);
      digitalWrite(Red2, LOW);
      digitalWrite(Red3, LOW); // L3 - RED 1 OFF
      
      




      
      
    }
























    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("<head>");
    client.println("<title> Green Corridor </title>");
    client.println("</head>");
    
    client.println("<center><h3 class = \"title\">Traffic Light - Green Corridor</h3></center>");

    
    client.println("<br><br>");

  
    client.println("<center>");
    client.println("<a href = \"/LED-1=GO\"\"><button class = \"btn-1\">GO1</button></a>");

    client.println("<a href = \"/LED-2=GO\"\"><button class = \"btn-2\">GO2</button></a>");
    client.println("<a  href = \"/LED-3=GO\"\"><button class = \"btn-3\">GO3</button></a>");

    client.println("<a  href = \"/LED-M=OFF\"\"><button class = \"btn-master\">MASTER OFF</button></a>");
    client.println("</center>");
   

    client.println("");
    
    client.print("<style>");
    client.print(".title{font-size: 28px; color: white; font-family: Roboto; font-strength: bolder;}");
    client.print(".btn-1, .btn-2, .btn-3{background-color: #4CAF50; border: none; color: white; padding: 15px 32px; text-align: center; text-decoration: none; display: inline-block; font-size: 16px; cursor: pointer;}");
    client.print(".btn-1:hover, .btn-2:hover, .btn-3:hover{background-color: #black; border: none; color: white; padding: 15px 32px; text-align: center; text-decoration: none; display: inline-block; font-size: 16px; cursor: pointer;}");
    
    client.print(".btn-master{background-color: #FF0000; border: none; color: white; padding: 15px 32px; text-align: center; text-decoration: none; display: inline-block; font-size: 16px; cursor: pointer;}");
    client.print("html{ background-image: linear-gradient(90deg, #00B2FF, #21FCFC)}");
        
    client.print("</style");

    
    client.println("</html>");
    delay(1);
    Serial.println("Client Disconnected");
    Serial.println("");




  
}
