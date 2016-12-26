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

  u8g2.setFont(u8g2_font_ncenB14_tr);

  u8g2.sendBuffer();

}

void loop() {
  u8g2.clearBuffer();
  int xpos = 1023 - Esplora.readJoystickX() / 16;
  int ypos = Esplora.readJoystickY() / 16;
  u8g2.drawPixel(xpos + 64, ypos + 32);
  u8g2.sendBuffer();
  delay(100);
}

