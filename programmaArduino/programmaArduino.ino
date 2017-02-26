#include <LiquidCrystal.h>

#include <SimpleDHT.h>


int pinDHT11 = 13;
SimpleDHT11 dht11;
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
void setup() {
  Serial.begin(9600);
  //lcd.begin(16,2);
  
}

void loop() {  
  // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  if (dht11.read(pinDHT11, &temperature, &humidity, NULL)) {
    return;
  }
  Serial.print((int)temperature); Serial.print(" *C;"); 
  Serial.print((int)humidity); Serial.println(" %");
  lcd.print((int)temperature+" ; "+(int)humidity);
  delay(2000);
}
