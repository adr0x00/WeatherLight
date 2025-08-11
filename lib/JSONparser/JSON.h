#include <ArduinoJson.h>

struct WeatherData;   // структура для сбора данных о городе. 

//void JSONparser(String json_messege);  // Объявление функции

struct WeatherData JSONparser( String json_messege ); // Структура для чтения Json 