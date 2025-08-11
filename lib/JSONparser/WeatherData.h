// Файл для структуры данных о погоде
#ifndef WEATHERDATA_H
#define WEATHERDATA_H   

struct WeatherData {

    char name[32];      // Название города
    float temperature;  // Температура в градусах Цельсия
    float humidity;     // Влажность в процентах
    char time[16];      // Время получения данных (формат: YYYY-MM-DD HH:MM)
};

#endif // WEATHERDATA_H