#include "main.h"

 char* cities[5] = {
    "Moscow", 
    "London", 
    "USA", 
    "Tokyo", 
    "Berlin"
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Setup complete");   
  
  oled_init();  // OLED SSD1306 

  connectToWiFi(); // подключаемся к Wi-Fi сети 

   WeatherData data_cities;
 
   for( int i = 0 ; i < 5  ; i++ ) {
      data_cities = getWeatherData(cities[i]);    //cities[i]
      Serial.println("City: " + String (data_cities.name) );
      Serial.println(data_cities.temperature); 
      Serial.println(data_cities.humidity); 
      Serial.println("Time: " + String (data_cities.time)); 
   }
   //+ String (" %") 
}

void loop() {
  // put your main code here, to run repeatedly:

}
















// Задачи следующие получать данные о погоде с сервера и отображать их на дисплее 
   // подзадачи  
  // 1. подключить ESP 8266 к Wi-Fi сети.   - выполнено 
  // 2. получить данные о погоде с сервера  - выполнено 
  // 3. обработать данные о погоде.         - выполнено
  // 4. отобразить данные о погоде на дисплее - в процессе 

// подключить ленту которая будет отображать погоду в виде цвета 
   // нужны драйверы управления в виде 3-транзиторов PNP или NPN определюсь по ходу дела
   // например если погода дождливая - эффект синих капель падающих на адресной ленте. 


// идеи подключить советы и нейронку которая будет анализировать 
 // совет дня: сегодня жарковато , лучше одется легче. 