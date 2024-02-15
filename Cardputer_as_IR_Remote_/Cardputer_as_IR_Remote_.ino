

#define DISABLE_CODE_FOR_RECEIVER  // Disables restarting receiver after each
// send. Saves 450 bytes program memory and
// 269 bytes RAM if receiving functions are
// not used.
#define SEND_PWM_BY_TIMER
#define IR_TX_PIN 44

uint8_t sCommand = 0x34;
uint8_t sRepeats = 0;


#include "M5Cardputer.h"
#include <IRremote.hpp>  // include the library

void setup() {
  auto cfg = M5.config();
  M5Cardputer.begin(cfg, true);
  M5Cardputer.Display.setRotation(1);
  M5Cardputer.Display.setTextColor(GREEN);
  M5Cardputer.Display.setTextDatum(middle_center);
  M5Cardputer.Display.setTextFont(&fonts::FreeSerifBoldItalic18pt7b);
  M5Cardputer.Display.setTextSize(1);
  M5Cardputer.Display.drawString("Press a Key",
                                 M5Cardputer.Display.width() / 2,
                                 M5Cardputer.Display.height() / 2);

  IrSender.begin(DISABLE_LED_FEEDBACK);  // Start with IR_SEND_PIN as send pin
  IrSender.setSendPin(IR_TX_PIN);
}

void loop() {
  M5Cardputer.update();
  if (M5Cardputer.Keyboard.isChange()) {
    if (M5Cardputer.Keyboard.isKeyPressed('1'))
    {
      M5Cardputer.Display.clear();
      M5Cardputer.Display.fillCircle(32, 105, 8, GREEN);
      M5Cardputer.Display.drawString("Light1",
                                     M5Cardputer.Display.width() / 2,
                                     M5Cardputer.Display.height() / 2);
      IrSender.sendNEC(0x80, 0xA, sRepeats);
      delay(500);
      M5Cardputer.Display.fillCircle(32, 105, 8, YELLOW);
    }
    else if (M5Cardputer.Keyboard.isKeyPressed('2'))
    {
      M5Cardputer.Display.clear();
      M5Cardputer.Display.fillCircle(32, 105, 8, GREEN);
      M5Cardputer.Display.drawString("Light2",
                                     M5Cardputer.Display.width() / 2,
                                     M5Cardputer.Display.height() / 2);
      IrSender.sendNEC(0x80, 0x1B, sRepeats);
      delay(500);
      M5Cardputer.Display.fillCircle(32, 105, 8, YELLOW);
    }
    else if (M5Cardputer.Keyboard.isKeyPressed('3'))
    {
      M5Cardputer.Display.clear();
      M5Cardputer.Display.fillCircle(32, 105, 8, GREEN);
      M5Cardputer.Display.drawString("Light3",
                                     M5Cardputer.Display.width() / 2,
                                     M5Cardputer.Display.height() / 2);
      IrSender.sendNEC(0x80, 0x1F, sRepeats);
      delay(500);
      M5Cardputer.Display.fillCircle(32, 105, 8, YELLOW);
    }
    else if (M5Cardputer.Keyboard.isKeyPressed('4'))
    {
      M5Cardputer.Display.clear();
      M5Cardputer.Display.fillCircle(32, 105, 8, GREEN);
      M5Cardputer.Display.drawString("Light4",
                                     M5Cardputer.Display.width() / 2,
                                     M5Cardputer.Display.height() / 2);
      IrSender.sendNEC(0x80, 0xC, sRepeats);
      delay(500);
      M5Cardputer.Display.fillCircle(32, 105, 8, YELLOW);
    }
    else
    {
      M5Cardputer.Display.clear();
      M5Cardputer.Display.drawString("Press Key",
                                     M5Cardputer.Display.width() / 2,
                                     M5Cardputer.Display.height() / 2);
    }
  }
}
