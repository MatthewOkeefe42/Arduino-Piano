#ifndef _NOTES_H            //Header guard
#define _NOTES_H

#define NOTE_C5 523         //Define frequencies for each note
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1046
#define NOTE_CS6 1109
#define NOTE_D6 1175
#define NOTE_DS6 1245
#define NOTE_E6 1319

#define ACTIVATED LOW         //Define value for button state
#define DEACTIVATED HIGH

const int BUTTON_C5 = 29;     //Designate pin connections for each button.
const int BUTTON_CS5 = 32;
const int BUTTON_D5 = 33;
const int BUTTON_DS5 = 34;
const int BUTTON_E5 = 35;
const int BUTTON_F5 = 38;
const int BUTTON_FS5 = 39;
const int BUTTON_G5 = 40;
const int BUTTON_GS5 = 41;
const int BUTTON_A5 = 44;
const int BUTTON_AS5 = 45;
const int BUTTON_B5 = 46;
const int BUTTON_C6 = 47;
const int BUTTON_CS6 = 50;
const int BUTTON_D6 = 51;
const int BUTTON_DS6 = 52;
const int BUTTON_E6 = 53;

const int LEDC = 13;          //Designate pin connections for each LED.
const int LEDCS = 12;
const int LEDD = 11;
const int LEDDS = 10;
const int LEDE = 9;
const int LEDF = 8;
const int LEDFS = 7;
const int LEDG = 6;
const int LEDGS = 5;
const int LEDA = 4;
const int LEDAS = 3;
const int LEDB = 2;

const int PIEZO = 17;        //Designate pin 17 for speaker.
const int SWITCH = 19;       //Designate pin connections for switches.
const int SWITCH1 = 18;

#endif