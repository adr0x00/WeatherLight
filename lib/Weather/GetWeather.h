// прототип функции получения. 
#include "MyWIFI.h" // подключаем MyWIFI.h для работы с Wi-Fi Client Secure

	
struct WeatherData{
    
    String name;
    float temperature;
    float humidity;
    String time; 
}; 
 
// Функиця для получения погоды - Москва 
struct WeatherData getWeatherData( char* city); 