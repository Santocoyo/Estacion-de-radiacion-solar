#include <DS1302.h>
DS1302 rtc(8, 7, 6); //(RST, DAT, CLK)
Time t;
void setup() {
rtc.halt(false);
rtc.writeProtect(false);
rtc.setDOW(TUESDAY); // Configurar dia de la semana (inglés).
rtc.setTime(14, 38, 40); // Configurar hora en formato 24hs con min y seg.
rtc.setDate(03, 07, 2019); // Configurar fecha en formato dia/mes/año.
}
void loop() {
digitalWrite(13,HIGH); // El led integrado confirmara la finalizacion.
}
