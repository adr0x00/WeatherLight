// прототип функции получения. 
#include "MyWIFI.h" // подключаем MyWIFI.h для работы с Wi-Fi Client Secure
#include "WeatherData.h"
	
/*struct WeatherData{
    
    String name;
    float temperature;
    float humidity;
    String time; 
}; 
*/

// Функиця для получения погоды - Москва 
struct WeatherData getWeatherData( const char* city); 