 // файл реализации MyWIFI.cpp
#include "MyWIFI.h"


 const char* ssid = "HomeWIFI ";      // имя сети Wi-Fi
 const char* password = "wsxEsx.223"; // пароль сети Wi-Fi

// Функция для подключения к Wi-Fi сети
void connectToWiFi() {
    Serial.print("Connecting to WiFi");
    WiFi.begin(ssid, password);
    
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    
    Serial.println();
    Serial.println("Connected to WiFi");
    Serial.print("IP address: "); 
    Serial.println(WiFi.localIP());   // выводим IP адрес устройства если все ок! 
}
