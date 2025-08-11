// подключение библиотеки для работы с Wi-Fi
#ifndef MYWIFI_H
#define MYWIFI_H    

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>

// прототип функции для подключения к Wi-Fi сети
void connectToWiFi(); 

#endif // MYWIFI_H
// Конец файла MyWIFI.h
// Этот файл содержит функции для подключения к Wi-Fi сети и настройки соединения