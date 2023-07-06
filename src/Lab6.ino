SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

#include "oled-wing-adafruit.h"
OledWingAdafruit display;


void setup() {

pinMode(A4, INPUT);


}


void loop() {

display.loop();
display.setup();
display.clearDisplay();
display.setTextSize(1);
display.setTextColor(WHITE);
display.setCursor(0, 0);


uint64_t reading = analogRead(A4);
double voltage = (reading * 3.3) / 4095.0;
double celsiusTemperature = (voltage - 0.5) * 100;
double farenheitTemperature = (celsiusTemperature * 9.0/5.0 + 32);

display.print("Celsius: ");
display.println(celsiusTemperature);

display.print("Farenheit: ");
display.println(farenheitTemperature);
display.display();
delay(5000);
}