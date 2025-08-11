/*
  ОПИСАНИЕ - отправляет структуру с данными 
  ПАРАМЕТРЫ - город в виде строки 
  ВОЗВРАЩЕТ - Структуру с заполненными полями. 
*/ 

#include "GetWeather.h"
#include "JSON.h"

const char* API_KEY = "89c09cc4d67e4e4198791335252907";  // АПИ сервиса для получения погоды

struct WeatherData city;   // структура для сбора данных о городе.
// Функция для получения данных о погоде с сервера 
struct WeatherData getWeatherData( char* user_city ) {

    const char* API_KEY = "89c09cc4d67e4e4198791335252907";
    const char* CITY = user_city;
    
     // Формируем URL динамически
     String URL = "https://api.weatherapi.com/v1/current.json?key=" + String(API_KEY) + "&q=" + String(CITY);

    HTTPClient http;
    WiFiClientSecure client;
    client.setInsecure(); // Отключает проверку сертификата (для теста)

    http.begin(client, URL);

    int httpCode = http.GET();

    if (httpCode > 0) {

        String json_answere = http.getString();

        city = JSONparser(json_answere);  // Получаем ответ в виде структуры с полями     

    } else {
        Serial.printf("Error on HTTP request: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();

    return city; 
}
