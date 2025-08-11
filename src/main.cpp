#include "main.h"

//String json = "{\"location\":{\"name\":\"Moscow\",\"region\":\"Moscow\",\"country\":\"Russia\",\"lat\":55.7558,\"lon\":37.6173,\"tz_id\":\"Europe/Moscow\",\"localtime_epoch\":1633036800,\"localtime\":\"2021-10-01 00:00\"},\"current\":{\"temp_c\":15.0,\"temp_f\":59.0,\"is_day\":1,\"condition\":{\"text\":\"Partly cloudy\",\"icon\":\"//cdn.weatherapi.com/weather/64x64/day/116.png\",\"code\":1003},\"wind_mph\":5.6,\"wind_kph\":9.0,\"wind_degree\":180,\"wind_dir\":\"S\",\"pressure_mb\":1012.0,\"pressure_in\":29.88,\"precip_mm\":0.0,\"precip_in\":0.0,\"humidity\":72,\"cloud\":20,\"feelslike_c\":14.5,\"feelslike_f\":58.1}}";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Setup complete");   
  
  oled_init();  // OLED SSD1306 

  connectToWiFi(); // подключаемся к Wi-Fi сети 

   WeatherData data_cities = getWeatherData("Moscow"); // Получаем данные о погоде в Москве
   // data_cities = JSONparser(json); // Получаем данные о погоде в Москве
   Serial.println( data_cities.name );
   Serial.println( data_cities.temperature );
   Serial.println( data_cities.humidity );
   Serial.println( data_cities.time );
   
    display.clearDisplay(); // очищаем дисплей перед выводом данных
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.println(data_cities.name);

    display.setCursor(0,20);
    display.println(data_cities.temperature);

    display.setCursor(0,40);
    display.println(data_cities.time);
    // drawing commands to make them visible on screen!
    display.display();
}

void loop() {
  // put your main code here, to run repeatedly:
   
}

/*
   for( int i = 0 ; i < 5  ; i++ ) {
      data_cities = getWeatherData(cities[i]);   
      Serial.println("City: " + String (data_cities.name) );
      Serial.println(data_cities.temperature); 
      Serial.println(data_cities.humidity); 
      Serial.println("Time: " + String (data_cities.time)); 
   }

*/














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