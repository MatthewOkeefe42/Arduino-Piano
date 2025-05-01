#include <Adafruit_GFX.h>      //Core graphics library
#include <Wire.h>              //Include Wire library
#include <SPI.h>               //Include SPI library
#include <Adafruit_SSD1306.h>  //Include library for OLED screen used
#include "Notes.h"             //Header for note frequencies and pin assignments
#include "OLEDBitmaps.h"       //Header to call Bitmaps for animations.

void checkButtonDeactivated(int buttonPin) {      //Check if button is being pressed
  if (digitalRead(buttonPin) == DEACTIVATED) {    //While pressed...
    while (true) {                                //infinite loop until button is activated again
      if (digitalRead(buttonPin) == ACTIVATED) {  //When released...
        break;                                    //Cease animation, tone, and LED.
      }
    }
  }
}

void setup() {                                //Set pinmodes and states of LEDs and Buttons.
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  //Start OLED.
  display.clearDisplay();                     //Clear the OLED screen.
  delay(2000);

  pinMode(LEDC, OUTPUT);  //Initialize all LEDs as outputs and turn them off by default.
  digitalWrite(LEDC, LOW);
  pinMode(LEDCS, OUTPUT);
  digitalWrite(LEDCS, LOW);
  pinMode(LEDD, OUTPUT);
  digitalWrite(LEDD, LOW);
  pinMode(LEDDS, OUTPUT);
  digitalWrite(LEDDS, LOW);
  pinMode(LEDE, OUTPUT);
  digitalWrite(LEDE, LOW);
  pinMode(LEDF, OUTPUT);
  digitalWrite(LEDF, LOW);
  pinMode(LEDFS, OUTPUT);
  digitalWrite(LEDFS, LOW);
  pinMode(LEDG, OUTPUT);
  digitalWrite(LEDG, LOW);
  pinMode(LEDGS, OUTPUT);
  digitalWrite(LEDGS, LOW);
  pinMode(LEDA, OUTPUT);
  digitalWrite(LEDA, LOW);
  pinMode(LEDAS, OUTPUT);
  digitalWrite(LEDAS, LOW);
  pinMode(LEDB, OUTPUT);
  digitalWrite(LEDB, LOW);

  pinMode(SWITCH, INPUT);  //Set buttons as inputs and activate pull-up resistors.
  digitalWrite(SWITCH, HIGH);
  pinMode(SWITCH1, INPUT);
  digitalWrite(SWITCH1, HIGH);

  pinMode(BUTTON_C5, INPUT);
  digitalWrite(BUTTON_C5, HIGH);
  pinMode(BUTTON_CS5, INPUT);
  digitalWrite(BUTTON_CS5, HIGH);
  pinMode(BUTTON_D5, INPUT);
  digitalWrite(BUTTON_D5, HIGH);
  pinMode(BUTTON_DS5, INPUT);
  digitalWrite(BUTTON_DS5, HIGH);
  pinMode(BUTTON_E5, INPUT);
  digitalWrite(BUTTON_E5, HIGH);
  pinMode(BUTTON_F5, INPUT);
  digitalWrite(BUTTON_F5, HIGH);
  pinMode(BUTTON_FS5, INPUT);
  digitalWrite(BUTTON_FS5, HIGH);
  pinMode(BUTTON_G5, INPUT);
  digitalWrite(BUTTON_G5, HIGH);
  pinMode(BUTTON_GS5, INPUT);
  digitalWrite(BUTTON_GS5, HIGH);
  pinMode(BUTTON_A5, INPUT);
  digitalWrite(BUTTON_A5, HIGH);
  pinMode(BUTTON_AS5, INPUT);
  digitalWrite(BUTTON_AS5, HIGH);
  pinMode(BUTTON_B5, INPUT);
  digitalWrite(BUTTON_B5, HIGH);
  pinMode(BUTTON_C6, INPUT);
  digitalWrite(BUTTON_C6, HIGH);
  pinMode(BUTTON_CS6, INPUT);
  digitalWrite(BUTTON_CS6, HIGH);
  pinMode(BUTTON_D6, INPUT);
  digitalWrite(BUTTON_D6, HIGH);
  pinMode(BUTTON_DS6, INPUT);
  digitalWrite(BUTTON_DS6, HIGH);
  pinMode(BUTTON_E6, INPUT);
  digitalWrite(BUTTON_E6, HIGH);
}

void loop() {  //If i = 1; play pokemon animations, if i = 0; play animal animations.
  if (digitalRead(SWITCH) == ACTIVATED) {
    i = 1;
  }
  if (digitalRead(SWITCH1) == ACTIVATED) {
    i = 0;
  }

  while (digitalRead(BUTTON_C5) == ACTIVATED) {  //While button is pressed...
    tone(PIEZO, NOTE_C5);                        //Play the tone for that button.
    digitalWrite(LEDC, HIGH);                    //Light the LED for that note.

    if (i == 1) {  //If the pokemon switch is activated...
      const uint8_t* CHARMANDERList[] = { CHARMANDER0, CHARMANDER1 };
      const int CHARMANDERCount = sizeof(CHARMANDERList) / sizeof(CHARMANDERList[0]);  //Store the number of bitmaps in (Bitmap_Name)Count.
      for (int r = 0; r < CHARMANDERCount; r++) {                                      //Iterate through each bitmap from the array.
        display.clearDisplay();                                                        //Clear the OLED screen.
        display.drawBitmap(xx, yy, CHARMANDERList[r], 48, 48, 1);                      //Call the current bitmap.
        display.display();                                                             //Display the bitmap.
        delay(tt);                                                                     //Set the length of time that each frame displays.

        display.setTextSize(1);                    //Set the text font size.
        display.setTextColor(WHITE);               //Set the font color.
        display.setCursor(0, 0);                   //Set the first letter to start at the top left corner.
        display.println("You played, C!");         //First line of text to be displayed.
        display.println("C is for...CHARMANDER");  //Second line of text to be displayed.
        display.display();                         //Display the text.
        delay(tt);                                 //Set the length of time that the text displays.

        if (digitalRead(BUTTON_C5) == DEACTIVATED) {  //If button is released...
          break;                                      //Stop the animation.
        }
      }
    }

    if (i == 0) {  //If the animal switch is activated...
      const uint8_t* CATList[] = { CAT0, CAT1, CAT2, CAT3, CAT4, CAT5, CAT6, CAT7, CAT8, CAT9, CAT10 };
      const int CATCount = sizeof(CATList) / sizeof(CATList[0]);

      for (int r = 0; r < CATCount; r++) {
        display.clearDisplay();
        display.drawBitmap(xx, yy, CATList[r], 48, 48, 1);
        display.display();
        delay(tt);

        display.setTextSize(1);  //TEXT DISPLAY
        display.setTextColor(WHITE);
        display.setCursor(0, 0);
        display.println("You played, C!");
        display.println("C is for... CAT!");
        display.display();
        delay(tt);

        if (digitalRead(BUTTON_C5) == DEACTIVATED) {
          break;
        }
      }
    }
  }

  while (digitalRead(BUTTON_CS5) == ACTIVATED) {
    tone(PIEZO, NOTE_CS5);
    digitalWrite(LEDCS, HIGH);

    if (i == 1) {
      const uint8_t* CHARMANDERList[] = { CHARMANDER0, CHARMANDER1 };
      const int CHARMANDERCount = sizeof(CHARMANDERList) / sizeof(CHARMANDERList[0]);

      for (int r = 0; r < CHARMANDERCount; r++) {
        display.clearDisplay();
        display.drawBitmap(xx, yy, CHARMANDERList[r], 48, 48, 1);
        display.display();
        delay(tt);

        display.setTextSize(1);  //TEXT DISPLAY
        display.setTextColor(WHITE);
        display.setCursor(0, 0);
        display.println("You played, C#!");
        display.println("C is for...CHARMANDER");
        display.display();
        delay(tt);

        if (digitalRead(BUTTON_CS5) == DEACTIVATED) {
          break;
        }
      }
    }
    if (i == 0) {
      const uint8_t* CATList[] = { CAT0, CAT1, CAT2, CAT3, CAT4, CAT5, CAT6, CAT7, CAT8, CAT9, CAT10 };
      const int CATCount = sizeof(CATList) / sizeof(CATList[0]);

      for (int r = 0; r < CATCount; r++) {
        display.clearDisplay();
        display.drawBitmap(xx, yy, CATList[r], 48, 48, 1);
        display.display();
        delay(tt);

        display.setTextSize(1);  //TEXT DISPLAY
        display.setTextColor(WHITE);
        display.setCursor(0, 0);
        display.println("You played, C#!");
        display.println("C is for... CAT!");
        display.display();
        delay(tt);

        if (digitalRead(BUTTON_CS5) == DEACTIVATED) {
          break;
        }
      }
    }
  }

  while (digitalRead(BUTTON_D5) == ACTIVATED) {
    tone(PIEZO, NOTE_D5);
    digitalWrite(LEDD, HIGH);

    if (i == 1) {
      const uint8_t* DITTOList[] = { DITTO0, DITTO1, DITTO2, DITTO3, DITTO4, DITTO5, DITTO6, DITTO7, DITTO8, DITTO9, DITTO10 };
      const int DITTOCount = sizeof(DITTOList) / sizeof(DITTOList[0]);

      for (int r = 0; r < DITTOCount; r++) {
        display.clearDisplay();
        display.drawBitmap(xx, yy, DITTOList[r], 48, 48, 1);
        display.display();
        delay(tt);

        display.setTextSize(1);  //TEXT DISPLAY
        display.setTextColor(WHITE);
        display.setCursor(0, 0);
        display.println("You played, D!");
        display.println("D is for... DITTO!");
        display.display();
        delay(tt);

        if (digitalRead(BUTTON_D5) == DEACTIVATED) {
          break;
        }
      }
    }
    if (i == 0) {
      const uint8_t* DINOSAURList[] = { DINOSAUR0, DINOSAUR1, DINOSAUR2, DINOSAUR3, DINOSAUR4, DINOSAUR5, DINOSAUR6, DINOSAUR7, DINOSAUR8, DINOSAUR9, DINOSAUR10 };
      const int DINOSAURCount = sizeof(DINOSAURList) / sizeof(DINOSAURList[0]);

      for (int r = 0; r < DINOSAURCount; r++) {
        display.clearDisplay();
        display.drawBitmap(xx, yy, DINOSAURList[r], 48, 48, 1);
        display.display();
        delay(tt);

        display.setTextSize(1);  //TEXT DISPLAY
        display.setTextColor(WHITE);
        display.setCursor(0, 0);
        display.println("You played, D!");
        display.println("D is for... DINOSAUR!");
        display.display();
        delay(tt);

        if (digitalRead(BUTTON_DS5) == DEACTIVATED) {
          break;
        }
      }
    }
  }

  while (digitalRead(BUTTON_DS5) == ACTIVATED) {
    tone(PIEZO, NOTE_DS5);
    digitalWrite(LEDDS, HIGH);

    if (i == 1) {
      const uint8_t* DITTOList[] = { DITTO0, DITTO1, DITTO2, DITTO3, DITTO4, DITTO5, DITTO6, DITTO7, DITTO8, DITTO9, DITTO10 };
      const int DITTOCount = sizeof(DITTOList) / sizeof(DITTOList[0]);

      for (int r = 0; r < DITTOCount; r++) {
        display.clearDisplay();
        display.drawBitmap(xx, yy, DITTOList[r], 48, 48, 1);
        display.display();
        delay(tt);

        display.setTextSize(1);  //TEXT DISPLAY
        display.setTextColor(WHITE);
        display.setCursor(0, 0);
        display.println("You played, D#!");
        display.println("D is for... DITTO!");
        display.display();
        delay(tt);

        if (digitalRead(BUTTON_DS5) == DEACTIVATED) {
          break;
        }
      }
    }
    if (i == 0) {
      const uint8_t* DINOSAURList[] = { DINOSAUR0, DINOSAUR1, DINOSAUR2, DINOSAUR3, DINOSAUR4, DINOSAUR5, DINOSAUR6, DINOSAUR7, DINOSAUR8, DINOSAUR9, DINOSAUR10 };
      const int DINOSAURCount = sizeof(DINOSAURList) / sizeof(DINOSAURList[0]);

      for (int r = 0; r < DINOSAURCount; r++) {
        display.clearDisplay();
        display.drawBitmap(xx, yy, DINOSAURList[r], 48, 48, 1);
        display.display();
        delay(tt);

        display.setTextSize(1);  //TEXT DISPLAY
        display.setTextColor(WHITE);
        display.setCursor(0, 0);
        display.println("You played, D#!");
        display.display();
        delay(tt);

        if (digitalRead(BUTTON_DS5) == DEACTIVATED) {
          break;
        }
      }
    }
  }

  while (digitalRead(BUTTON_E5) == ACTIVATED) {
    tone(PIEZO, NOTE_E5);
    digitalWrite(LEDE, HIGH);

    if (i == 1) {
      const uint8_t* EVEEList[] = { EVEE0, EVEE1, EVEE2, EVEE3, EVEE4, EVEE5, EVEE6, EVEE7, EVEE8, EVEE9, EVEE10 };
      const int EVEECount = sizeof(EVEEList) / sizeof(EVEEList[0]);

      for (int r = 0; r < EVEECount; r++) {
        display.clearDisplay();
        display.drawBitmap(xx, yy, EVEEList[r], 48, 48, 1);
        display.display();
        delay(tt);

        display.setTextSize(1);  //TEXT DISPLAY
        display.setTextColor(WHITE);
        display.setCursor(0, 0);
        display.println("You played, E!");
        display.println("E is for... EVEE!");
        display.display();
        delay(tt);

        if (digitalRead(BUTTON_E5) == DEACTIVATED) {
          break;
        }
      }
    }
    if (i == 0) {
      const uint8_t* ELEPHANTList[] = { ELEPHANT0, ELEPHANT1, ELEPHANT2, ELEPHANT3, ELEPHANT4, ELEPHANT5, ELEPHANT6, ELEPHANT7, ELEPHANT8, ELEPHANT9, ELEPHANT10 };
      const int ELEPHANTCount = sizeof(ELEPHANTList) / sizeof(ELEPHANTList[0]);

      for (int r = 0; r < ELEPHANTCount; r++) {
        display.clearDisplay();
        display.drawBitmap(xx, yy, ELEPHANTList[r], 48, 48, 1);
        display.display();
        delay(tt);

        display.setTextSize(1);  //TEXT DISPLAY
        display.setTextColor(WHITE);
        display.setCursor(0, 0);
        display.println("You played, E6!");
        display.println("E is for... ELEPHANT!");
        display.display();

        if (digitalRead(BUTTON_E5) == DEACTIVATED) {
          break;
        }
      }
    }
  }
  while (digitalRead(BUTTON_F5) == ACTIVATED) {  //While button F5 is pressed...
    tone(PIEZO, NOTE_F5);                        //Play the tone for F5.
    digitalWrite(LEDF, HIGH);                    //Light the LED for F.

    if (i == 1) {  //If the pokemon switch is activated...
      const uint8_t* FLAREONList[] = { FLAREON0, FLAREON1, FLAREON2, FLAREON3, FLAREON4, FLAREON5, FLAREON6, FLAREON7, FLAREON8, FLAREON9, FLAREON10 };
      const int FLAREONCount = sizeof(FLAREONList) / sizeof(FLAREONList[0]);  //Store the number of FLAREON bitmaps in FLAREONCount.

      for (int r = 0; r < FLAREONCount; r++) {                  //Iterate through each FLAREON bitmap from the array.
        display.clearDisplay();                                 //Clear the OLED screen.
        display.drawBitmap(xx, yy, FLAREONList[r], 48, 48, 1);  //Call the current FLAREON bitmap.
        display.display();                                      //Display the bitmap.
        delay(tt);                                              //Set the length of time that each frame displays.

        display.setTextSize(1);                   //Set the text font size.
        display.setTextColor(WHITE);              //Set the font color.
        display.setCursor(0, 0);                  //Set the first letter to start at the top left corner.
        display.println("You played, F!");        //First line of text to be displayed.
        display.println("F is for... FLAREON!");  //Second line of text to be displayed.
        display.display();                        //Display the text.
        delay(tt);                                //Set the length of time that the text displays.

        if (digitalRead(BUTTON_F5) == DEACTIVATED) {  //If button F5 is released...
          break;                                      //Stop the animation.
        }
      }
    }
    if (i == 0) {
      //FROG
      const uint8_t* FROGList[] = { FROG0, FROG1, FROG2, FROG3, FROG4, FROG5, FROG6, FROG7, FROG8, FROG9, FROG10 };
      const int FROGCount = sizeof(FROGList) / sizeof(FROGList[0]);

      for (int r = 0; r < FROGCount; r++) {
        display.clearDisplay();
        display.drawBitmap(xx, yy, FROGList[r], 48, 48, 1);
        display.display();
        delay(tt);

        display.setTextSize(1);  //TEXT DISPLAY
        display.setTextColor(WHITE);
        display.setCursor(0, 0);
        display.println("You played, F!");
        display.println("F is for... FROG!");
        display.display();
        delay(tt);

        if (digitalRead(BUTTON_F5) == DEACTIVATED) {
          break;
        }
      }
    }
  }

  while (digitalRead(BUTTON_FS5) == ACTIVATED) {
    tone(PIEZO, NOTE_FS5);
    digitalWrite(LEDFS, HIGH);

    if (i == 1) {
      const uint8_t* FLAREONList[] = { FLAREON0, FLAREON1, FLAREON2, FLAREON3, FLAREON4, FLAREON5, FLAREON6, FLAREON7, FLAREON8, FLAREON9, FLAREON10 };
      const int FLAREONCount = sizeof(FLAREONList) / sizeof(FLAREONList[0]);

      for (int r = 0; r < FLAREONCount; r++) {
        display.clearDisplay();
        display.drawBitmap(xx, yy, FLAREONList[r], 48, 48, 1);
        display.display();
        delay(tt);

        display.setTextSize(1);  //TEXT DISPLAY
        display.setTextColor(WHITE);
        display.setCursor(0, 0);
        display.println("You played, F#!");
        display.println("F is for... FLAREON!");
        display.display();
        delay(tt);

        if (digitalRead(BUTTON_FS5) == DEACTIVATED) {
          break;
        }
      }
    }
    if (i == 0) {
      //FROG
      const uint8_t* FROGList[] = { FROG0, FROG1, FROG2, FROG3, FROG4, FROG5, FROG6, FROG7, FROG8, FROG9, FROG10 };
      const int FROGCount = sizeof(FROGList) / sizeof(FROGList[0]);

      for (int r = 0; r < FROGCount; r++) {
        display.clearDisplay();
        display.drawBitmap(xx, yy, FROGList[r], 48, 48, 1);
        display.display();
        delay(tt);

        display.setTextSize(1);  //TEXT DISPLAY
        display.setTextColor(WHITE);
        display.setCursor(0, 0);
        display.println("You played, F#!");
        display.println("F is for... FROG!");
        display.display();
        delay(tt);

        if (digitalRead(BUTTON_FS5) == DEACTIVATED) {
          break;
        }
      }
    }
  }

  while (digitalRead(BUTTON_G5) == ACTIVATED) {
    tone(PIEZO, NOTE_G5);
    digitalWrite(LEDG, HIGH);

    if (i == 1) {
      const uint8_t* GENGARList[] = { GENGAR0, GENGAR1, GENGAR2, GENGAR3, GENGAR4, GENGAR5, GENGAR6, GENGAR7, GENGAR8, GENGAR9, GENGAR10 };
      const int GENGARCount = sizeof(GENGARList) / sizeof(GENGARList[0]);

      for (int r = 0; r < GENGARCount; r++) {
        display.clearDisplay();
        display.drawBitmap(xx, yy, GENGARList[r], 48, 48, 1);
        display.display();
        delay(tt);

        display.setTextSize(1);  //TEXT DISPLAY
        display.setTextColor(WHITE);
        display.setCursor(0, 0);
        display.println("You played, G!");
        display.println("G is for... GENGAR!");
        display.display();
        delay(tt);

        if (digitalRead(BUTTON_G5) == DEACTIVATED) {
          break;
        }
      }
    }
    if (i == 0) {
      const uint8_t* GORILLAList[] = { GORILLA0, GORILLA1, GORILLA2, GORILLA3, GORILLA4, GORILLA5, GORILLA6, GORILLA7, GORILLA8, GORILLA9, GORILLA10 };
      const int GORILLACount = sizeof(GORILLAList) / sizeof(GORILLAList[0]);

      for (int r = 0; r < GORILLACount; r++) {
        display.clearDisplay();
        display.drawBitmap(xx, yy, GORILLAList[r], 48, 48, 1);
        display.display();
        delay(tt);

        display.setTextSize(1);  //TEXT DISPLAY
        display.setTextColor(WHITE);
        display.setCursor(0, 0);
        display.println("You played, G!");
        display.println("G is for... GORILLA!");
        display.display();
        delay(tt);

        if (digitalRead(BUTTON_G5) == DEACTIVATED) {
          break;
        }
      }
    }
  }

  while (digitalRead(BUTTON_GS5) == ACTIVATED) {
    tone(PIEZO, NOTE_GS5);
    digitalWrite(LEDGS, HIGH);

    if (i == 1) {
      const uint8_t* GENGARList[] = { GENGAR0, GENGAR1, GENGAR2, GENGAR3, GENGAR4, GENGAR5, GENGAR6, GENGAR7, GENGAR8, GENGAR9, GENGAR10 };
      const int GENGARCount = sizeof(GENGARList) / sizeof(GENGARList[0]);

      for (int r = 0; r < GENGARCount; r++) {
        display.clearDisplay();
        display.drawBitmap(xx, yy, GENGARList[r], 48, 48, 1);
        display.display();
        delay(tt);

        display.setTextSize(1);  //TEXT DISPLAY
        display.setTextColor(WHITE);
        display.setCursor(0, 0);
        display.println("You played, G#!");
        display.println("G is for... GENGAR!");
        display.display();
        delay(tt);

        if (digitalRead(BUTTON_GS5) == DEACTIVATED) {
          break;
        }
      }
    }
    if (i == 0) {
      const uint8_t* GORILLAList[] = { GORILLA0, GORILLA1, GORILLA2, GORILLA3, GORILLA4, GORILLA5, GORILLA6, GORILLA7, GORILLA8, GORILLA9, GORILLA10 };
      const int GORILLACount = sizeof(GORILLAList) / sizeof(GORILLAList[0]);

      for (int r = 0; r < GORILLACount; r++) {
        display.clearDisplay();
        display.drawBitmap(xx, yy, GORILLAList[r], 48, 48, 1);
        display.display();
        delay(tt);

        display.setTextSize(1);  //TEXT DISPLAY
        display.setTextColor(WHITE);
        display.setCursor(0, 0);
        display.println("You played, G#!");
        display.println("G is for... GORILLA!");
        display.display();
        delay(tt);

        if (digitalRead(BUTTON_GS5) == DEACTIVATED) {
          break;
        }
      }
    }
  }

  while (digitalRead(BUTTON_A5) == ACTIVATED) {
    digitalWrite(LEDA, HIGH);
    tone(PIEZO, NOTE_A5);

    if (i == 1) {

      const uint8_t* aggronList[] = { AGGRON0, AGGRON1, AGGRON2, AGGRON3, AGGRON4, AGGRON5, AGGRON6, AGGRON7, AGGRON8, AGGRON9, AGGRON10 };
      const int aggronCount = sizeof(aggronList) / sizeof(aggronList[0]);

      for (int r = 0; r < aggronCount; r++) {
        display.clearDisplay();
        display.drawBitmap(xx, yy, aggronList[r], 48, 48, 1);
        display.display();
        delay(tt);

        display.setTextSize(1);  //TEXT DISPLAY
        display.setTextColor(WHITE);
        display.setCursor(0, 0);
        display.println("You played, A!");
        display.println("A is for... AGGRON!");
        display.display();
        delay(tt);

        if (digitalRead(BUTTON_A5) == DEACTIVATED) {
          break;
        }
      }
    }
    if (i == 0) {

      const uint8_t* alpacaList[] = { Alpaca0, Alpaca1, Alpaca2, Alpaca3, Alpaca4, Alpaca5, Alpaca6, Alpaca7, Alpaca8, Alpaca9, Alpaca10 };
      const int alpacaCount = sizeof(alpacaList) / sizeof(alpacaList[0]);

      for (int r = 0; r < alpacaCount; r++) {
        display.clearDisplay();
        display.drawBitmap(xx, yy, alpacaList[r], 48, 48, 1);
        display.display();
        delay(tt);

        display.setTextSize(1);  //TEXT DISPLAY
        display.setTextColor(WHITE);
        display.setCursor(0, 0);
        display.println("You played, A!");
        display.println("A is for... ALPACA!");
        display.display();
        delay(tt);

        if (digitalRead(BUTTON_A5) == DEACTIVATED) {
          break;
        }
      }
    }
  }

  while (digitalRead(BUTTON_AS5) == ACTIVATED) {
    digitalWrite(LEDAS, HIGH);
    tone(PIEZO, NOTE_AS5);

    if (i == 1) {
      const uint8_t* aggronList[] = { AGGRON0, AGGRON1, AGGRON2, AGGRON3, AGGRON4, AGGRON5, AGGRON6, AGGRON7, AGGRON8, AGGRON9, AGGRON10 };
      const int aggronCount = sizeof(aggronList) / sizeof(aggronList[0]);

      for (int r = 0; r < aggronCount; r++) {
        display.clearDisplay();
        display.drawBitmap(xx, yy, aggronList[r], 48, 48, 1);
        display.display();
        delay(tt);

        display.setTextSize(1);  //TEXT DISPLAY
        display.setTextColor(WHITE);
        display.setCursor(0, 0);
        display.println("You played, A#!");
        display.println("A is for... AGGRON!");
        display.display();
        delay(tt);

        if (digitalRead(BUTTON_AS5) == DEACTIVATED) {
          break;
        }
      }
    }

    if (i == 0) {
      const uint8_t* alpacaList[] = { Alpaca0, Alpaca1, Alpaca2, Alpaca3, Alpaca4, Alpaca5, Alpaca6, Alpaca7, Alpaca8, Alpaca9, Alpaca10 };
      const int alpacaCount = sizeof(alpacaList) / sizeof(alpacaList[0]);

      for (int r = 0; r < alpacaCount; r++) {
        display.clearDisplay();
        display.drawBitmap(xx, yy, alpacaList[r], 48, 48, 1);
        display.display();
        delay(tt);

        display.setTextSize(1);  //TEXT DISPLAY
        display.setTextColor(WHITE);
        display.setCursor(0, 0);
        display.println("You played, A#!");
        display.println("A is for... ALPACA!");
        display.display();
        delay(tt);

        if (digitalRead(BUTTON_AS5) == DEACTIVATED) {
          break;
        }
      }
    }
  }

  while (digitalRead(BUTTON_B5) == ACTIVATED) {
    tone(PIEZO, NOTE_B5);
    digitalWrite(LEDB, HIGH);

    if (i == 1) {
      const uint8_t* BULBASAURList[] = { BULBASAUR0, BULBASAUR1, BULBASAUR2 };
      const int BULBASAURCount = sizeof(BULBASAURList) / sizeof(BULBASAURList[0]);

      for (int r = 0; r < BULBASAURCount; r++) {
        display.clearDisplay();
        display.drawBitmap(xx, yy, BULBASAURList[r], 48, 48, 1);
        display.display();
        delay(tt);

        display.setTextSize(1);  //TEXT DISPLAY
        display.setTextColor(WHITE);
        display.setCursor(0, 0);
        display.println("You played, B!");
        display.println("B is for...BULBASAUR!");
        display.display();
        delay(tt);

        if (digitalRead(BUTTON_B5) == DEACTIVATED) {
          break;
        }
      }
    }
    if (i == 0) {
      const uint8_t* batList[] = { bat0, bat1, bat2, bat3, bat4, bat5, bat6, bat7, bat8, bat9, bat10 };
      const int batCount = sizeof(batList) / sizeof(batList[0]);

      for (int r = 0; r < batCount; r++) {
        display.clearDisplay();
        display.drawBitmap(xx, yy, batList[r], 48, 48, 1);
        display.display();
        delay(tt);

        display.setTextSize(1);  //TEXT DISPLAY
        display.setTextColor(WHITE);
        display.setCursor(0, 0);
        display.println("You played, B!");
        display.println("B is for... BAT!");
        display.display();
        delay(tt);

        if (digitalRead(BUTTON_B5) == DEACTIVATED) {
          break;
        }
      }
    }
  }

  while (digitalRead(BUTTON_C6) == ACTIVATED) {
    tone(PIEZO, NOTE_C6);
    digitalWrite(LEDC, HIGH);

    if (i == 1) {
      const uint8_t* CHARMANDERList[] = { CHARMANDER0, CHARMANDER1 };
      const int CHARMANDERCount = sizeof(CHARMANDERList) / sizeof(CHARMANDERList[0]);
      for (int r = 0; r < CHARMANDERCount; r++) {
        display.clearDisplay();
        display.drawBitmap(xx, yy, CHARMANDERList[r], 48, 48, 1);
        display.display();
        delay(tt);

        display.setTextSize(1);  //TEXT DISPLAY
        display.setTextColor(WHITE);
        display.setCursor(0, 0);
        display.println("You played, C6!");
        display.println("C is for...CHARMANDER");
        display.display();
        delay(tt);

        if (digitalRead(BUTTON_C6) == DEACTIVATED) {
          break;
        }
      }
    }
    if (i == 0) {
      const uint8_t* CATList[] = { CAT0, CAT1, CAT2, CAT3, CAT4, CAT5, CAT6, CAT7, CAT8, CAT9, CAT10 };
      const int CATCount = sizeof(CATList) / sizeof(CATList[0]);

      for (int r = 0; r < CATCount; r++) {
        display.clearDisplay();
        display.drawBitmap(xx, yy, CATList[r], 48, 48, 1);
        display.display();
        delay(tt);

        display.setTextSize(1);  //TEXT DISPLAY
        display.setTextColor(WHITE);
        display.setCursor(0, 0);
        display.println("You played, C6!");
        display.println("C is for... CAT!");
        display.display();
        delay(tt);

        if (digitalRead(BUTTON_C6) == DEACTIVATED) {
          break;
        }
      }
    }
  }

  while (digitalRead(BUTTON_CS6) == ACTIVATED) {
    tone(PIEZO, NOTE_CS6);
    digitalWrite(LEDCS, HIGH);

    if (i == 1) {
      const uint8_t* CHARMANDERList[] = { CHARMANDER0, CHARMANDER1 };
      const int CHARMANDERCount = sizeof(CHARMANDERList) / sizeof(CHARMANDERList[0]);
      for (int r = 0; r < CHARMANDERCount; r++) {
        display.clearDisplay();
        display.drawBitmap(xx, yy, CHARMANDERList[r], 48, 48, 1);
        display.display();
        delay(tt);

        display.setTextSize(1);  //TEXT DISPLAY
        display.setTextColor(WHITE);
        display.setCursor(0, 0);
        display.println("You played, C#6!");
        display.println("C is for...CHARMANDER");
        display.display();
        delay(tt);

        if (digitalRead(BUTTON_CS6) == DEACTIVATED) {
          break;
        }
      }
    }
    if (i == 0) {
      const uint8_t* CATList[] = { CAT0, CAT1, CAT2, CAT3, CAT4, CAT5, CAT6, CAT7, CAT8, CAT9, CAT10 };
      const int CATCount = sizeof(CATList) / sizeof(CATList[0]);

      for (int r = 0; r < CATCount; r++) {
        display.clearDisplay();
        display.drawBitmap(xx, yy, CATList[r], 48, 48, 1);
        display.display();
        delay(tt);

        display.setTextSize(1);  //TEXT DISPLAY
        display.setTextColor(WHITE);
        display.setCursor(0, 0);
        display.println("You played, C#6!");
        display.println("C is for... CAT!");
        display.display();
        delay(tt);

        if (digitalRead(BUTTON_CS6) == DEACTIVATED) {
          break;
        }
      }
    }
  }

  while (digitalRead(BUTTON_D6) == ACTIVATED) {
    tone(PIEZO, NOTE_D6);
    digitalWrite(LEDD, HIGH);

    if (i == 1) {
      const uint8_t* DITTOList[] = { DITTO0, DITTO1, DITTO2, DITTO3, DITTO4, DITTO5, DITTO6, DITTO7, DITTO8, DITTO9, DITTO10 };
      const int DITTOCount = sizeof(DITTOList) / sizeof(DITTOList[0]);

      for (int r = 0; r < DITTOCount; r++) {
        display.clearDisplay();
        display.drawBitmap(xx, yy, DITTOList[r], 48, 48, 1);
        display.display();
        delay(tt);

        display.setTextSize(1);  //TEXT DISPLAY
        display.setTextColor(WHITE);
        display.setCursor(0, 0);
        display.println("You played, D6!");
        display.println("D is for... DITTO!");
        display.display();
        delay(tt);

        if (digitalRead(BUTTON_D6) == DEACTIVATED) {
          break;
        }
      }
    }
    if (i == 0) {
      const uint8_t* DINOSAURList[] = { DINOSAUR0, DINOSAUR1, DINOSAUR2, DINOSAUR3, DINOSAUR4, DINOSAUR5, DINOSAUR6, DINOSAUR7, DINOSAUR8, DINOSAUR9, DINOSAUR10 };
      const int DINOSAURCount = sizeof(DINOSAURList) / sizeof(DINOSAURList[0]);

      for (int r = 0; r < DINOSAURCount; r++) {
        display.clearDisplay();
        display.drawBitmap(xx, yy, DINOSAURList[r], 48, 48, 1);
        display.display();
        delay(tt);

        display.setTextSize(1);  //TEXT DISPLAY
        display.setTextColor(WHITE);
        display.setCursor(0, 0);
        display.println("You played, D6!");
        display.println("D is for... DINOSAUR!");
        display.display();
        delay(tt);

        if (digitalRead(BUTTON_D6) == DEACTIVATED) {
          break;
        }
      }
    }
  }

  while (digitalRead(BUTTON_DS6) == ACTIVATED) {
    tone(PIEZO, NOTE_DS6);
    digitalWrite(LEDDS, HIGH);

    if (i == 1) {
      const uint8_t* DITTOList[] = { DITTO0, DITTO1, DITTO2, DITTO3, DITTO4, DITTO5, DITTO6, DITTO7, DITTO8, DITTO9, DITTO10 };
      const int DITTOCount = sizeof(DITTOList) / sizeof(DITTOList[0]);

      for (int r = 0; r < DITTOCount; r++) {
        display.clearDisplay();
        display.drawBitmap(xx, yy, DITTOList[r], 48, 48, 1);
        display.display();
        delay(tt);

        display.setTextSize(1);  //TEXT DISPLAY
        display.setTextColor(WHITE);
        display.setCursor(0, 0);
        display.println("You played, D#6!");
        display.println("D is for... DITTO!");
        display.display();

        if (digitalRead(BUTTON_DS6) == DEACTIVATED) {
          break;
        }
      }
    }
    if (i == 0) {
      const uint8_t* DINOSAURList[] = { DINOSAUR0, DINOSAUR1, DINOSAUR2, DINOSAUR3, DINOSAUR4, DINOSAUR5, DINOSAUR6, DINOSAUR7, DINOSAUR8, DINOSAUR9, DINOSAUR10 };
      const int DINOSAURCount = sizeof(DINOSAURList) / sizeof(DINOSAURList[0]);

      for (int r = 0; r < DINOSAURCount; r++) {
        display.clearDisplay();
        display.drawBitmap(xx, yy, DINOSAURList[r], 48, 48, 1);
        display.display();
        delay(tt);

        display.setTextSize(1);  //TEXT DISPLAY
        display.setTextColor(WHITE);
        display.setCursor(0, 0);
        display.println("You played, D#6!");
        display.println("D is for... DINOSAUR!");
        display.display();

        if (digitalRead(BUTTON_DS6) == DEACTIVATED) {
          break;
        }
      }
    }
  }

  while (digitalRead(BUTTON_E6) == ACTIVATED) {
    tone(PIEZO, NOTE_E6);
    digitalWrite(LEDE, HIGH);

    if (i == 1) {
      const uint8_t* EVEEList[] = { EVEE0, EVEE1, EVEE2, EVEE3, EVEE4, EVEE5, EVEE6, EVEE7, EVEE8, EVEE9, EVEE10 };
      const int EVEECount = sizeof(EVEEList) / sizeof(EVEEList[0]);

      for (int r = 0; r < EVEECount; r++) {
        display.clearDisplay();
        display.drawBitmap(xx, yy, EVEEList[r], 48, 48, 1);
        display.display();
        delay(tt);

        display.setTextSize(1);  //TEXT DISPLAY
        display.setTextColor(WHITE);
        display.setCursor(0, 0);
        display.println("You played, E6!");
        display.println("E is for... EVEE!");
        display.display();

        if (digitalRead(BUTTON_E6) == DEACTIVATED) {
          break;
        }
      }
    }
    if (i == 0) {
      const uint8_t* ELEPHANTList[] = { ELEPHANT0, ELEPHANT1, ELEPHANT2, ELEPHANT3, ELEPHANT4, ELEPHANT5, ELEPHANT6, ELEPHANT7, ELEPHANT8, ELEPHANT9, ELEPHANT10 };
      const int ELEPHANTCount = sizeof(ELEPHANTList) / sizeof(ELEPHANTList[0]);

      for (int r = 0; r < ELEPHANTCount; r++) {
        display.clearDisplay();
        display.drawBitmap(xx, yy, ELEPHANTList[r], 48, 48, 1);
        display.display();
        delay(tt);

        display.setTextSize(1);  //TEXT DISPLAY
        display.setTextColor(WHITE);
        display.setCursor(0, 0);
        display.println("You played, E6!");
        display.println("E is for... ELEPHANT!");
        display.display();

        if (digitalRead(BUTTON_E6) == DEACTIVATED) {
          break;
        }
      }
    }
  }
  noTone(PIEZO);                          //Turn off speaker and LEDs when there are no buttons being pressed.
  digitalWrite(LEDC, LOW);
  digitalWrite(LEDCS, LOW);
  digitalWrite(LEDD, LOW);
  digitalWrite(LEDDS, LOW);
  digitalWrite(LEDE, LOW);
  digitalWrite(LEDF, LOW);
  digitalWrite(LEDFS, LOW);
  digitalWrite(LEDG, LOW);
  digitalWrite(LEDGS, LOW);
  digitalWrite(LEDA, LOW);
  digitalWrite(LEDAS, LOW);
  digitalWrite(LEDB, LOW);
  display.clearDisplay();
  display.display();
}
