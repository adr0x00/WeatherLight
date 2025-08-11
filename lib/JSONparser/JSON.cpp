// файл реализации функции парсера JSON 
#include "JSON.h"

 // структура данных о городе. 
struct WeatherData {
    String name;
    float temperature;
    float humidity;
    String time;
};

WeatherData data_city;  // Создаем экземпляр структуры 

struct WeatherData JSONparser( String json_messege ){
         
     JsonDocument document; 
     DeserializationError error = deserializeJson(document, json_messege);

      if (error) {
        Serial.print("JSON parsing failed: ");
        Serial.println(error.c_str());
     } 
         
    // присваиваем полям приянятые значения функцией 
      data_city.name = (String)document["location"]["name"];       // ГОРОД 
      data_city.temperature = document["current"]["temp_c"];       // ТЕМПЕРАТУРА
      data_city.humidity = document["current"]["humidity"];        // ВЛАЖНОСТЬ
      data_city.time = (String)document["location"]["localtime"];  // ВРЕМЯ
      
      return data_city; 
}
/*
void JSONparser( String json_messege){

    JsonDocument doc;   //Пул памяти
    
    DeserializationError error = deserializeJson(doc, json_messege);
  
    if (error) {
        Serial.print("JSON parsing failed: ");
        Serial.println(error.c_str());
        return;
    } 
    
    const char* city = doc["location"]["name"];   // извлекаем поле города
    float temperature = doc["current"]["temp_c"];   // извлекаем поле температуру
    float humidity = doc["current"]["humidity"];   // извлекаем поле влажность
    const char*  city_time = doc["location"]["localtime"];   // извлекаем поле города

    Serial.println("City: " + String (city) ); 
    Serial.println("Temperature: " + String (temperature) + "°C" );  
    Serial.println("Hamidity: " + String (humidity) + " %"); 
    Serial.println("Time: " + String (city_time + 11)); 
}
*/