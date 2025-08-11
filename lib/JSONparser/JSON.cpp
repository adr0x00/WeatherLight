// файл реализации функции парсера JSON 
#include "JSON.h"
#include "WeatherData.h"

WeatherData data_city;  // Создаем экземпляр структуры 

struct WeatherData JSONparser( const String& json ){
    
    JsonDocument doc; // Создаем документ для парсинга JSON
    
    DeserializationError error = deserializeJson(doc, json);
   // Serial.println("JSON: " + json); // Отладочный вывод JSON строки

    if (error) {
        Serial.print("deserializeJson() failed: ");
        Serial.println(error.c_str());
        return data_city; // Возвращаем пустую структуру в случае ошибки
    }
         
 // присваиваем полям приянятые значения функцией 
    WeatherData result;
    strncpy(result.name, doc["location"]["name"] | "Unknown", sizeof(result.name)-1); // ГОРОД 
    result.temperature = doc["current"]["temp_c"] |  0.0f;       // ТЕМПЕРАТУРА
    result.humidity = doc["current"]["humidity"]  |  0.0f;        // ВЛАЖНОСТЬ
    const char* full_time = doc["location"]["localtime"] | "Unknown"; // ВРЕМЯ

    strncpy(result.time, full_time + 11, 5);  // Берем "HH:MM" 
   /*
    Serial.println(result.temperature ); // Отладочный вывод температуры
    Serial.println(result.humidity );    // Отладочный вывод влажности
    Serial.println(result.name );        // Отладочный вывод  названия города
    Serial.println(result.time );        // Отладочный вывод времени
   */    
    return result; 
}
