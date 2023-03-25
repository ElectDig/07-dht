/*
 *     Project 07-dht - main.cpp
 *
 *     Austral 2023 - Electronica Digital  - EAM 
 *
 *   Temperature and humidity measurement using DHT-XX sensor
 *
 *         Requires following libraries
 *         - DHT Sensor Library
 *         - Adafruit Unified Sensor Library
 */

#include <Arduino.h>

#include <Adafruit_Sensor.h>
#include <DHT.h>

/*
 *      Definitions in platformio.ini
 *      DHTPIN      GPIO where DHTxx data is connected
 *      DHTTYPE     Constant defining sensor type: DHT11 or DHT22
 *      SERIAL_BAUD Serial port Baud rate
 */

DHT dht(DHTPIN, DHTTYPE);   // New DHT type object

void
setup(void)
{
    Serial.begin(SERIAL_BAUD);
    Serial.printf( "\n\nDHT%d test!\n", DHTTYPE);
    dht.begin();
}

void
loop()
{
    float h, t, f;

    delay(2000);                    // It is a low speed sensor !!

    h = dht.readHumidity();
    t = dht.readTemperature();     // in Celsius
    f = dht.readTemperature(true); // in Fahrenheit

    if (isnan(h) || isnan(t) || isnan(f))   //    Failed measurement ?
        Serial.printf("Measurement failure\n");
    else
        Serial.printf( "DHT%d -> Humedad: %5.1f %%, Temperatura: %5.1f C | %5.1f F\n", DHTTYPE, h, t, f );
}
