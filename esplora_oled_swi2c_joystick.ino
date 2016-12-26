/*
 * This program plots the position of the Esplora's
 * joystick to an SSD1306 OLED over software I2C.
 * SPI is not supported yet.
 * 
 * Connections:
 * VCC > pin 1 of first orange header
 * GND > pin 3 of first orange header
 * SDA > pin 2 of second orange header (D3)
 * SCL > pin 2 of first orange header (D11)
 */
#define SCL_PIN D11
#define SCL_PORT PORTD
#define SDA_PIN D3
#define SDA_PORT PORTB

#include <SoftI2CMaster.h>
#include <Esplora.h>
#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ 11, /* data=*/ 3, /* reset=*/U8X8_PIN_NONE );

void setup() {
  u8g2.begin();
}

void loop() {
  int temp = Esplora.readJoystickX();
  u8g2.clearBuffer();
  u8g2.setCursor(0, 20);
  u8g2.print(temp);
  u8g2.sendBuffer();
}

