// #define RGB_BRIGHTNESS 64 // Change white brightness (max 255)

#include "pitches.h"



// change this to whichever pin you want to use
int buzzer = 5; // PWM pin for esp32 C3  //11;
// As such, any GPIO pins that support output can be used for LED PWM functions. Specifically, I believe you can use:
// GPIOs 0, 1, 2, 3, 4, 5, 12, 13, 14, 15, 16, 17, 18 ,19, 21, 22, 23, 25, 26, 27, 32 and 33

// change this to make the song slower or faster
int tempo = 140;
int merryChristmas[] = {
	// We Wish You a Merry Christmas
	NOTE_C5, 4, // 1
	NOTE_F5, 4, NOTE_F5, 8, NOTE_G5, 8, NOTE_F5, 8, NOTE_E5, 8,
	NOTE_D5, 4, NOTE_D5, 4, NOTE_D5, 4,
	NOTE_G5, 4, NOTE_G5, 8, NOTE_A5, 8, NOTE_G5, 8, NOTE_F5, 8,
	NOTE_E5, 4, NOTE_C5, 4, NOTE_C5, 4,
	NOTE_A5, 4, NOTE_A5, 8, NOTE_AS5, 8, NOTE_A5, 8, NOTE_G5, 8,
	NOTE_F5, 4, NOTE_D5, 4, NOTE_C5, 8, NOTE_C5, 8,
	NOTE_D5, 4, NOTE_G5, 4, NOTE_E5, 4,

	NOTE_F5, 2, NOTE_C5, 4, // 8
	NOTE_F5, 4, NOTE_F5, 8, NOTE_G5, 8, NOTE_F5, 8, NOTE_E5, 8,
	NOTE_D5, 4, NOTE_D5, 4, NOTE_D5, 4,
	NOTE_G5, 4, NOTE_G5, 8, NOTE_A5, 8, NOTE_G5, 8, NOTE_F5, 8,
	NOTE_E5, 4, NOTE_C5, 4, NOTE_C5, 4,
	NOTE_A5, 4, NOTE_A5, 8, NOTE_AS5, 8, NOTE_A5, 8, NOTE_G5, 8,
	NOTE_F5, 4, NOTE_D5, 4, NOTE_C5, 8, NOTE_C5, 8,
	NOTE_D5, 4, NOTE_G5, 4, NOTE_E5, 4,
	NOTE_F5, 2, NOTE_C5, 4,

	NOTE_F5, 4, NOTE_F5, 4, NOTE_F5, 4, // 17
	NOTE_E5, 2, NOTE_E5, 4,
	NOTE_F5, 4, NOTE_E5, 4, NOTE_D5, 4,
	NOTE_C5, 2, NOTE_A5, 4,
	NOTE_AS5, 4, NOTE_A5, 4, NOTE_G5, 4,
	NOTE_C6, 4, NOTE_C5, 4, NOTE_C5, 8, NOTE_C5, 8,
	NOTE_D5, 4, NOTE_G5, 4, NOTE_E5, 4,
	NOTE_F5, 2, NOTE_C5, 4,
	NOTE_F5, 4, NOTE_F5, 8, NOTE_G5, 8, NOTE_F5, 8, NOTE_E5, 8,
	NOTE_D5, 4, NOTE_D5, 4, NOTE_D5, 4,

	NOTE_G5, 4, NOTE_G5, 8, NOTE_A5, 8, NOTE_G5, 8, NOTE_F5, 8, // 27
	NOTE_E5, 4, NOTE_C5, 4, NOTE_C5, 4,
	NOTE_A5, 4, NOTE_A5, 8, NOTE_AS5, 8, NOTE_A5, 8, NOTE_G5, 8,
	NOTE_F5, 4, NOTE_D5, 4, NOTE_C5, 8, NOTE_C5, 8,
	NOTE_D5, 4, NOTE_G5, 4, NOTE_E5, 4,
	NOTE_F5, 2, NOTE_C5, 4,
	NOTE_F5, 4, NOTE_F5, 4, NOTE_F5, 4,
	NOTE_E5, 2, NOTE_E5, 4,
	NOTE_F5, 4, NOTE_E5, 4, NOTE_D5, 4,

	NOTE_C5, 2, NOTE_A5, 4, // 36
	NOTE_AS5, 4, NOTE_A5, 4, NOTE_G5, 4,
	NOTE_C6, 4, NOTE_C5, 4, NOTE_C5, 8, NOTE_C5, 8,
	NOTE_D5, 4, NOTE_G5, 4, NOTE_E5, 4,
	NOTE_F5, 2, NOTE_C5, 4,
	NOTE_F5, 4, NOTE_F5, 8, NOTE_G5, 8, NOTE_F5, 8, NOTE_E5, 8,
	NOTE_D5, 4, NOTE_D5, 4, NOTE_D5, 4,
	NOTE_G5, 4, NOTE_G5, 8, NOTE_A5, 8, NOTE_G5, 8, NOTE_F5, 8,
	NOTE_E5, 4, NOTE_C5, 4, NOTE_C5, 4,

	NOTE_A5, 4, NOTE_A5, 8, NOTE_AS5, 8, NOTE_A5, 8, NOTE_G5, 8, // 45
	NOTE_F5, 4, NOTE_D5, 4, NOTE_C5, 8, NOTE_C5, 8,
	NOTE_D5, 4, NOTE_G5, 4, NOTE_E5, 4,
	NOTE_F5, 2, NOTE_C5, 4,
	NOTE_F5, 4, NOTE_F5, 8, NOTE_G5, 8, NOTE_F5, 8, NOTE_E5, 8,
	NOTE_D5, 4, NOTE_D5, 4, NOTE_D5, 4,
	NOTE_G5, 4, NOTE_G5, 8, NOTE_A5, 8, NOTE_G5, 8, NOTE_F5, 8,
	NOTE_E5, 4, NOTE_C5, 4, NOTE_C5, 4,

	NOTE_A5, 4, NOTE_A5, 8, NOTE_AS5, 8, NOTE_A5, 8, NOTE_G5, 8, // 53
	NOTE_F5, 4, NOTE_D5, 4, NOTE_C5, 8, NOTE_C5, 8,
	NOTE_D5, 4, NOTE_G5, 4, NOTE_E5, 4,
	NOTE_F5, 2, REST, 4 };

// - - - - - - - - - - - - - - - - - - - - - - - -

int lastChristmas[] = {
 0, 0, 0, 165, 185, 220, 247, 247, 0, 294, 0, 0, 370, 370, 330, 294, 0, 494, 440, 659, 659, 659, 587, 440, 659, 659, 740, 587, 587, 494, 494, 659, 659,
 740, 587, 494, 554, 587, 554, 494, 494, 0, 740, 659, 659, 0, 494, 740, 784, 740, 659, 659, 0, 587, 554, 587, 554, 554, 554, 587, 554, 0, 440, 554, 554,
 440, 659, 659, 659, 587, 440, 659, 659, 740, 587, 587, 494, 494, 659, 659, 740, 587, 494, 554, 587, 554, 494, 494, 0, 740, 659, 659, 0, 494, 740, 784,
 740, 659, 659, 0, 587, 554, 587, 554, 554, 554, 587, 554, 0, 440, 554, 554, 440, 0, 659, 659, 587, 0, 587, 880, 740, 740, 659, 587, 0, 659, 659, 659,
 659, 587, 0, 587, 988, 988, 740, 740, 659, 587, 0, 740, 494, 587, 587, 659, 0, 740, 740, 740, 494, 587, 587, 659, 0, 0, 554, 554, 587, 554, 587, 554,
 587, 554, 554, 494, 440, 0, 0, 220, 220, 220, 220, 587, 554, 587, 554, 587, 554, 587, 659, 587, 554, 0, 587, 0, 554, 0, 587, 554, 587, 554, 587, 659,
 659, 587, 659, 659, 659, 587, 740, 0, 659, 587, 659, 659, 554, 554, 587, 587, 554, 587, 587, 554, 587, 554, 587, 554, 587, 440, 440, 0, 659, 659, 659,
 587, 440, 659, 659, 740, 587, 587, 494, 494, 659, 659, 740, 587, 494, 554, 587, 554, 494, 494, 0, 740, 659, 659, 0, 494, 740, 784, 740, 659, 659, 0, 587,
 554, 587, 554, 554, 554, 587, 554, 0, 440, 554, 554, 440, 0, 0, 0, 587, 554, 0, 440, 440, 494, 0, 0, 0, 1175, 0, 1109, 988, 880, 784, 740, 659, 0, 554,
 554, 587, 554, 0, 554, 587, 880, 880, 740, 587, 0, 440, 659, 659, 587, 554, 587, 0, 554, 587, 988, 988, 880, 659, 587, 0, 740, 740, 494, 587, 587, 659,
 740, 740, 740, 494, 587, 587, 659, 740, 587, 587, 554, 554, 587, 587, 554, 554, 494, 440, 440, 659, 587, 554, 554, 587, 440, 440, 659, 587, 554, 587,
 587, 440, 659, 587, 554, 554, 587, 440, 440, 880, 740, 740, 740, 659, 0, 587, 554, 494, 0, 740, 659, 659, 659, 587, 740, 659, 659, 587, 587, 554, 554, 587,
 587, 554, 587, 440, 440, 0, 659, 659, 659, 587, 440, 659, 659, 740, 587, 587, 494, 494, 659, 659, 740, 587, 494, 554, 587, 554, 494, 494, 0, 740, 659, 659,
 0, 494, 740, 784, 740, 659, 659, 0, 587, 554, 587, 554, 554, 554, 587, 554, 0, 440, 554, 554, 440, 659, 659, 659, 587, 440, 659, 659, 740, 587, 587, 494,
 494, 659, 659, 740, 587, 494, 554, 587, 554, 494, 494, 0, 740, 659, 659, 0, 494, 740, 784, 740, 659, 659, 0, 587, 554, 587, 554, 554, 554, 587, 554, 0,
 440, 554, 554, 440, 659, 659, 659, 587, 440, 659, 659, 740, 587, 587, 494, 494, 659, 659, 740, 587, 494, 554, 494, 554, 494, 494, 0, 0 };

int lastChristmasNotes[] = {
1008, 504, 252, 252, 504, 252, 252, 504, 252, 252, 504, 252, 252, 126, 126, 756, 1008, 756, 252, 756, 252, 252, 504, 252, 252, 252, 252, 252, 504, 252,
 252, 252, 252, 504, 756, 252, 252, 252, 252, 252, 756, 252, 756, 252, 504, 252, 252, 252, 252, 252, 252, 504, 252, 252, 252, 252, 252, 252, 252, 504,
 252, 252, 504, 252, 252, 756, 756, 252, 252, 504, 252, 252, 252, 252, 252, 504, 252, 252, 252, 252, 504, 756, 252, 252, 252, 252, 252, 756, 252, 756,
 252, 504, 252, 252, 252, 252, 252, 252, 504, 252, 252, 252, 252, 252, 252, 252, 504, 252, 252, 504, 252, 252, 756, 504, 504, 252, 252, 252, 252, 756,
 252, 252, 252, 504, 252, 252, 252, 252, 252, 252, 252, 252, 252, 504, 252, 252, 252, 504, 504, 252, 126, 126, 252, 252, 504, 252, 252, 252, 126, 126, 252,
 252, 504, 252, 504, 252, 126, 126, 504, 252, 252, 252, 252, 252, 1008, 504, 252, 126, 126, 252, 504, 252, 252, 252, 252, 252, 252, 756, 504, 252, 252, 252,
 252, 252, 252, 252, 252, 252, 252, 504, 504, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 504, 252, 252, 252, 252, 252,
 252, 252, 252, 252, 252, 756, 252, 756, 252, 252, 504, 252, 252, 252, 252, 252, 504, 252, 252, 252, 252, 504, 756, 252, 252, 252, 252, 252, 756, 252, 756,
 252, 504, 252, 252, 252, 252, 252, 252, 504, 252, 252, 252, 252, 252, 252, 252, 504, 252, 252, 504, 252, 252, 756, 504, 1008, 504, 252, 252, 252, 756, 756,
 252, 1008, 504, 252, 252, 252, 252, 252, 252, 252, 252, 504, 504, 504, 252, 252, 504, 252, 252, 252, 252, 252, 252, 504, 252, 252, 504, 252, 252, 252, 252,
 252, 252, 252, 252, 252, 126, 126, 504, 252, 252, 252, 252, 252, 252, 504, 252, 252, 252, 126, 126, 252, 756, 756, 252, 252, 252, 252, 252, 252, 252, 252,
 252, 756, 252, 504, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 756, 252, 504, 252, 252, 252, 252, 252, 252, 756, 252, 252, 504, 252, 252, 126, 126,
 504, 1008, 756, 252, 504, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 756, 252, 756, 252, 252, 504, 252, 252, 252, 252, 252,
 504, 252, 252, 252, 252, 504, 756, 252, 252, 252, 252, 252, 756, 252, 756, 252, 504, 252, 252, 252, 252, 252, 252, 504, 252, 252, 252, 252, 252, 252,
 252, 504, 252, 252, 504, 252, 252, 756, 756, 252, 252, 504, 252, 252, 252, 252, 252, 504, 252, 252, 252, 252, 504, 756, 252, 252, 252, 252, 252, 756,
 252, 756, 252, 504, 252, 252, 252, 252, 252, 252, 504, 252, 252, 252, 252, 252, 252, 252, 504, 252, 252, 504, 252, 252, 756, 756, 252, 252, 504, 252,
 252, 252, 252, 252, 504, 252, 252, 252, 252, 504, 756, 252, 252, 252, 252, 252, 756, 252, 0 };

int tetris[] = { //Based on the arrangement at https://www.flutetunes.com/tunes.php?id=192

	NOTE_E5, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_C5,8,  NOTE_B4,8,
	NOTE_A4, 4,  NOTE_A4,8,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
	NOTE_B4, -4,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
	NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,8,  NOTE_A4,4,  NOTE_B4,8,  NOTE_C5,8,

	NOTE_D5, -4,  NOTE_F5,8,  NOTE_A5,4,  NOTE_G5,8,  NOTE_F5,8,
	NOTE_E5, -4,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
	NOTE_B4, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
	NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,4, REST, 4,

	NOTE_E5, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_C5,8,  NOTE_B4,8,
	NOTE_A4, 4,  NOTE_A4,8,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
	NOTE_B4, -4,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
	NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,8,  NOTE_A4,4,  NOTE_B4,8,  NOTE_C5,8,

	NOTE_D5, -4,  NOTE_F5,8,  NOTE_A5,4,  NOTE_G5,8,  NOTE_F5,8,
	NOTE_E5, -4,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
	NOTE_B4, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
	NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,4, REST, 4,

	NOTE_E5,2,  NOTE_C5,2,
	NOTE_D5,2,   NOTE_B4,2,
	NOTE_C5,2,   NOTE_A4,2,
	NOTE_GS4,2,  NOTE_B4,4,  REST,8,
	NOTE_E5,2,   NOTE_C5,2,
	NOTE_D5,2,   NOTE_B4,2,
	NOTE_C5,4,   NOTE_E5,4,  NOTE_A5,2,
	NOTE_GS5,2,
};


int Godfather[] = {

  REST, 4, REST, 8, REST, 8, REST, 8, NOTE_E4, 8, NOTE_A4, 8, NOTE_C5, 8, //1
  NOTE_B4, 8, NOTE_A4, 8, NOTE_C5, 8, NOTE_A4, 8, NOTE_B4, 8, NOTE_A4, 8, NOTE_F4, 8, NOTE_G4, 8,
  NOTE_E4, 2, NOTE_E4, 8, NOTE_A4, 8, NOTE_C5, 8,
  NOTE_B4, 8, NOTE_A4, 8, NOTE_C5, 8, NOTE_A4, 8, NOTE_C5, 8, NOTE_A4, 8, NOTE_E4, 8, NOTE_DS4, 8,
  
  NOTE_D4, 2, NOTE_D4, 8, NOTE_F4, 8, NOTE_GS4, 8, //5
  NOTE_B4, 2, NOTE_D4, 8, NOTE_F4, 8, NOTE_GS4, 8,
  NOTE_A4, 2, NOTE_C4, 8, NOTE_C4, 8, NOTE_G4, 8, 
  NOTE_F4, 8, NOTE_E4, 8, NOTE_G4, 8, NOTE_F4, 8, NOTE_F4, 8, NOTE_E4, 8, NOTE_E4, 8, NOTE_GS4, 8,

  NOTE_A4, 2, REST,8, NOTE_A4, 8, NOTE_A4, 8, NOTE_GS4, 8, //9
  NOTE_G4, 2, NOTE_B4, 8, NOTE_A4, 8, NOTE_F4, 8, 
  NOTE_E4, 2, NOTE_E4, 8, NOTE_G4, 8, NOTE_E4, 8,
  NOTE_D4, 2, NOTE_D4, 8, NOTE_D4, 8, NOTE_F4, 8, NOTE_DS4, 8, 
   
  NOTE_E4, 2, REST, 8, NOTE_E4, 8, NOTE_A4, 8, NOTE_C5, 8, //13

  //repeats from 2
  NOTE_B4, 8, NOTE_A4, 8, NOTE_C5, 8, NOTE_A4, 8, NOTE_B4, 8, NOTE_A4, 8, NOTE_F4, 8, NOTE_G4, 8, //2
  NOTE_E4, 2, NOTE_E4, 8, NOTE_A4, 8, NOTE_C5, 8,
  NOTE_B4, 8, NOTE_A4, 8, NOTE_C5, 8, NOTE_A4, 8, NOTE_C5, 8, NOTE_A4, 8, NOTE_E4, 8, NOTE_DS4, 8,
  
  NOTE_D4, 2, NOTE_D4, 8, NOTE_F4, 8, NOTE_GS4, 8, //5
  NOTE_B4, 2, NOTE_D4, 8, NOTE_F4, 8, NOTE_GS4, 8,
  NOTE_A4, 2, NOTE_C4, 8, NOTE_C4, 8, NOTE_G4, 8, 
  NOTE_F4, 8, NOTE_E4, 8, NOTE_G4, 8, NOTE_F4, 8, NOTE_F4, 8, NOTE_E4, 8, NOTE_E4, 8, NOTE_GS4, 8,

  NOTE_A4, 2, REST,8, NOTE_A4, 8, NOTE_A4, 8, NOTE_GS4, 8, //9
  NOTE_G4, 2, NOTE_B4, 8, NOTE_A4, 8, NOTE_F4, 8, 
  NOTE_E4, 2, NOTE_E4, 8, NOTE_G4, 8, NOTE_E4, 8,
  NOTE_D4, 2, NOTE_D4, 8, NOTE_D4, 8, NOTE_F4, 8, NOTE_DS4, 8, 
   
  NOTE_E4, 2 //13
};

int doom[] = {
  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8, //1
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_B2, 8, NOTE_C3, 8,
  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8,
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, -2,

  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8, //5
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_B2, 8, NOTE_C3, 8,
  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8,
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, -2,

  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8, //9
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_B2, 8, NOTE_C3, 8,
  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8,
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, -2,

  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8, //13
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_B2, 8, NOTE_C3, 8,
  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8,
  NOTE_FS3, -16, NOTE_D3, -16, NOTE_B2, -16, NOTE_A3, -16, NOTE_FS3, -16, NOTE_B2, -16, NOTE_D3, -16, NOTE_FS3, -16, NOTE_A3, -16, NOTE_FS3, -16, NOTE_D3, -16, NOTE_B2, -16,

  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8, //17
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_B2, 8, NOTE_C3, 8,
  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8,
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, -2,

  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8, //21
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_B2, 8, NOTE_C3, 8,
  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8,
  NOTE_B3, -16, NOTE_G3, -16, NOTE_E3, -16, NOTE_G3, -16, NOTE_B3, -16, NOTE_E4, -16, NOTE_G3, -16, NOTE_B3, -16, NOTE_E4, -16, NOTE_B3, -16, NOTE_G4, -16, NOTE_B4, -16,

  NOTE_A2, 8, NOTE_A2, 8, NOTE_A3, 8, NOTE_A2, 8, NOTE_A2, 8, NOTE_G3, 8, NOTE_A2, 8, NOTE_A2, 8, //25
  NOTE_F3, 8, NOTE_A2, 8, NOTE_A2, 8, NOTE_DS3, 8, NOTE_A2, 8, NOTE_A2, 8, NOTE_E3, 8, NOTE_F3, 8,
  NOTE_A2, 8, NOTE_A2, 8, NOTE_A3, 8, NOTE_A2, 8, NOTE_A2, 8, NOTE_G3, 8, NOTE_A2, 8, NOTE_A2, 8,
  NOTE_F3, 8, NOTE_A2, 8, NOTE_A2, 8, NOTE_DS3, -2,

  NOTE_A2, 8, NOTE_A2, 8, NOTE_A3, 8, NOTE_A2, 8, NOTE_A2, 8, NOTE_G3, 8, NOTE_A2, 8, NOTE_A2, 8, //29
  NOTE_F3, 8, NOTE_A2, 8, NOTE_A2, 8, NOTE_DS3, 8, NOTE_A2, 8, NOTE_A2, 8, NOTE_E3, 8, NOTE_F3, 8,
  NOTE_A2, 8, NOTE_A2, 8, NOTE_A3, 8, NOTE_A2, 8, NOTE_A2, 8, NOTE_G3, 8, NOTE_A2, 8, NOTE_A2, 8,
  NOTE_A3, -16, NOTE_F3, -16, NOTE_D3, -16, NOTE_A3, -16, NOTE_F3, -16, NOTE_D3, -16, NOTE_C4, -16, NOTE_A3, -16, NOTE_F3, -16, NOTE_A3, -16, NOTE_F3, -16, NOTE_D3, -16,

  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8, //33
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_B2, 8, NOTE_C3, 8,
  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8,
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, -2,

  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8, //37
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_B2, 8, NOTE_C3, 8,
  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8,
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, -2,

  NOTE_CS3, 8, NOTE_CS3, 8, NOTE_CS4, 8, NOTE_CS3, 8, NOTE_CS3, 8, NOTE_B3, 8, NOTE_CS3, 8, NOTE_CS3, 8, //41
  NOTE_A3, 8, NOTE_CS3, 8, NOTE_CS3, 8, NOTE_G3, 8, NOTE_CS3, 8, NOTE_CS3, 8, NOTE_GS3, 8, NOTE_A3, 8,
  NOTE_B2, 8, NOTE_B2, 8, NOTE_B3, 8, NOTE_B2, 8, NOTE_B2, 8, NOTE_A3, 8, NOTE_B2, 8, NOTE_B2, 8,
  NOTE_G3, 8, NOTE_B2, 8, NOTE_B2, 8, NOTE_F3, -2,

  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8, //45
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_B2, 8, NOTE_C3, 8,
  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8,
  NOTE_B3, -16, NOTE_G3, -16, NOTE_E3, -16, NOTE_G3, -16, NOTE_B3, -16, NOTE_E4, -16, NOTE_G3, -16, NOTE_B3, -16, NOTE_E4, -16, NOTE_B3, -16, NOTE_G4, -16, NOTE_B4, -16,

  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8, //49
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_B2, 8, NOTE_C3, 8,
  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8,
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, -2,

  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8, //53
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_B2, 8, NOTE_C3, 8,
  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8,
  NOTE_FS3, -16, NOTE_DS3, -16, NOTE_B2, -16, NOTE_FS3, -16, NOTE_DS3, -16, NOTE_B2, -16, NOTE_G3, -16, NOTE_D3, -16, NOTE_B2, -16, NOTE_DS4, -16, NOTE_DS3, -16, NOTE_B2, -16,

// -/-

  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8, //57
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_B2, 8, NOTE_C3, 8,
  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8,
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, -2,

  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8, //61
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_B2, 8, NOTE_C3, 8,
  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8,
  NOTE_E4, -16, NOTE_B3, -16, NOTE_G3, -16, NOTE_G4, -16, NOTE_E4, -16, NOTE_G3, -16, NOTE_B3, -16, NOTE_D4, -16, NOTE_E4, -16, NOTE_G4, -16, NOTE_E4, -16, NOTE_G3, -16,  

  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8, //65
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_B2, 8, NOTE_C3, 8,
  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8,
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, -2,

  NOTE_A2, 8, NOTE_A2, 8, NOTE_A3, 8, NOTE_A2, 8, NOTE_A2, 8, NOTE_G3, 8, NOTE_A2, 8, NOTE_A2, 8, //69
  NOTE_F3, 8, NOTE_A2, 8, NOTE_A2, 8, NOTE_DS3, 8, NOTE_A2, 8, NOTE_A2, 8, NOTE_E3, 8, NOTE_F3, 8,
  NOTE_A2, 8, NOTE_A2, 8, NOTE_A3, 8, NOTE_A2, 8, NOTE_A2, 8, NOTE_G3, 8, NOTE_A2, 8, NOTE_A2, 8,
  NOTE_A3, -16, NOTE_F3, -16, NOTE_D3, -16, NOTE_A3, -16, NOTE_F3, -16, NOTE_D3, -16, NOTE_C4, -16, NOTE_A3, -16, NOTE_F3, -16, NOTE_A3, -16, NOTE_F3, -16, NOTE_D3, -16,

  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8, //73
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_B2, 8, NOTE_C3, 8,
  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8,
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, -2,

  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8, //77
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_B2, 8, NOTE_C3, 8,
  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8,
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, -2,

  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8, //81
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_B2, 8, NOTE_C3, 8,
  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8,
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, -2,

  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8, //73
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_B2, 8, NOTE_C3, 8,
  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8,
  NOTE_B3, -16, NOTE_G3, -16, NOTE_E3, -16, NOTE_B2, -16, NOTE_E3, -16, NOTE_G3, -16, NOTE_C4, -16, NOTE_B3, -16, NOTE_G3, -16, NOTE_B3, -16, NOTE_G3, -16, NOTE_E3, -16,  
};

int SilentNight[] = {
  NOTE_G4,-4, NOTE_A4,8, NOTE_G4,4,
  NOTE_E4,-2, 
  NOTE_G4,-4, NOTE_A4,8, NOTE_G4,4,
  NOTE_E4,-2, 
  NOTE_D5,2, NOTE_D5,4,
  NOTE_B4,-2,
  NOTE_C5,2, NOTE_C5,4,
  NOTE_G4,-2,

  NOTE_A4,2, NOTE_A4,4,
  NOTE_C5,-4, NOTE_B4,8, NOTE_A4,4,
  NOTE_G4,-4, NOTE_A4,8, NOTE_G4,4,
  NOTE_E4,-2, 
  NOTE_A4,2, NOTE_A4,4,
  NOTE_C5,-4, NOTE_B4,8, NOTE_A4,4,
  NOTE_G4,-4, NOTE_A4,8, NOTE_G4,4,
  NOTE_E4,-2, 
  
  NOTE_D5,2, NOTE_D5,4,
  NOTE_F5,-4, NOTE_D5,8, NOTE_B4,4,
  NOTE_C5,-2,
  NOTE_E5,-2,
  NOTE_C5,4, NOTE_G4,4, NOTE_E4,4,
  NOTE_G4,-4, NOTE_F4,8, NOTE_D4,4,
  NOTE_C4,-2,
  NOTE_C4,-1,
};

int ImperialMarch[] = {
  NOTE_A4,-4, NOTE_A4,-4, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_F4,8, REST,8,
  NOTE_A4,-4, NOTE_A4,-4, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_F4,8, REST,8,
  NOTE_A4,4, NOTE_A4,4, NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16,

  NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16, NOTE_A4,2,//4
  NOTE_E5,4, NOTE_E5,4, NOTE_E5,4, NOTE_F5,-8, NOTE_C5,16,
  NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16, NOTE_A4,2,
  
  NOTE_A5,4, NOTE_A4,-8, NOTE_A4,16, NOTE_A5,4, NOTE_GS5,-8, NOTE_G5,16, //7 
  NOTE_DS5,16, NOTE_D5,16, NOTE_DS5,8, REST,8, NOTE_A4,8, NOTE_DS5,4, NOTE_D5,-8, NOTE_CS5,16,

  NOTE_C5,16, NOTE_B4,16, NOTE_C5,16, REST,8, NOTE_F4,8, NOTE_GS4,4, NOTE_F4,-8, NOTE_A4,-16, //9
  NOTE_C5,4, NOTE_A4,-8, NOTE_C5,16, NOTE_E5,2,

  NOTE_A5,4, NOTE_A4,-8, NOTE_A4,16, NOTE_A5,4, NOTE_GS5,-8, NOTE_G5,16, //7 
  NOTE_DS5,16, NOTE_D5,16, NOTE_DS5,8, REST,8, NOTE_A4,8, NOTE_DS5,4, NOTE_D5,-8, NOTE_CS5,16,

  NOTE_C5,16, NOTE_B4,16, NOTE_C5,16, REST,8, NOTE_F4,8, NOTE_GS4,4, NOTE_F4,-8, NOTE_A4,-16, //9
  NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16, NOTE_A4,2
};


// sizeof gives the number of bytes, each int value is two bytes, 16 bits, two values per note, pitch and duration, each note is four bytes
// int melodyLength = sizeof(merryChristmas) / sizeof(merryChristmas[0]) / 2;

// this calculates the duration of a whole note in ms
//int wholenote = (60000 * 4) / tempo;

void setup()
{
	Serial.begin(115200);
}

int divider = 0, noteDuration = 0, melodyLength = 0;
int maxTone = 4000; int minTone = 200;

void loop()
{
  // tempo = 140;
	// melodyLength = sizeof(merryChristmas) / sizeof(merryChristmas[0]) / 2;
	// // iterate over the notes of the melody. Remember, the array is twice the number of notes (notes + durations)
	// MaxMinTone(merryChristmas, melodyLength, maxTone, minTone, true);
	// Serial.print("maxTone: "); Serial.print(maxTone); Serial.print(" ,  "); Serial.print("minTone: "); Serial.println(minTone);
	// for (int thisNote = 0; thisNote < melodyLength * 2; thisNote = thisNote + 2)
	// {
	// 	divider = merryChristmas[thisNote + 1];
	// 	if (divider > 0) { // regular note, just proceed
	// 		noteDuration = (wholenote) / divider;
	// 	}
	// 	else if (divider < 0) {  // dotted notes are represented with negative durations!!
	// 		noteDuration = (wholenote) / abs(divider);
	// 		noteDuration *= 1.5; // increases the duration in half for dotted notes
	// 	}
	// 	ToneAndColor(merryChristmas[thisNote], noteDuration, maxTone, minTone, 60);
	// }
	// delay(2000);

	// int melodyLength2 = sizeof(lastChristmas) / sizeof(lastChristmas[0]);
	// MaxMinTone(lastChristmas, melodyLength2, maxTone, minTone, false);
	// for (int thisNote = 0; thisNote < melodyLength; thisNote++)
	// {
	// 	noteDuration = lastChristmasNotes[thisNote];
	// 	ToneAndColor(lastChristmas[thisNote], noteDuration, maxTone, minTone, 60);
	// }
	// delay(2000);

  // tempo=144;
	// melodyLength = sizeof(tetris) / sizeof(tetris[0]) / 2;
  // JustPlay(tetris, melodyLength, 2, 60);
  // delay(2000);

  // tempo = 80;
  // melodyLength = sizeof(Godfather) / sizeof(Godfather[0]) / 2;
  // JustPlay(Godfather, melodyLength, 1, 60);
  // delay(2000);

  tempo = 225;
  melodyLength = sizeof(doom) / sizeof(doom[0]) / 2;
  JustPlay(doom, melodyLength, 1, 120);
  delay(2000);

  tempo = 140;
  melodyLength = sizeof(SilentNight) / sizeof(SilentNight[0]) / 2;
  JustPlay(SilentNight, melodyLength, 4, 120);  
  delay(2000);

  tempo = 120;
  melodyLength = sizeof(ImperialMarch) / sizeof(ImperialMarch[0]) / 2;
  JustPlay(ImperialMarch, melodyLength, 2, 90);
  delay(2000);
}




















void ToneAndColor(int nota, double duracion, int notaMax, int notaMin, int extraAngle) // notas van desde 31 a 4978
{
  tone(buzzer, nota, duracion * 0.9); Serial.print("nota: "); Serial.println(nota);

  if (nota>0){
    //#ifdef RGB_BUILTIN
    double nota360 = NotaInterpoladaA360(nota, notaMax, notaMin); //if(nota360<=0.0){rgbLedWrite(RGB_BUILTIN,0,0,0);}else{
    int r, g, b;
    HsvToRgb(nota360 + extraAngle, r, g, b); //digitalWrite(RGB_BUILTIN,HIGH);RGB LED white//digitalWrite(RGB_BUILTIN,LOW);RGB LED off
    rgbLedWrite(RGB_BUILTIN, r, g, b);
    Serial.print(r); Serial.print("\t"); Serial.print(g); Serial.print("\t"); Serial.println(b);  //}	//}
    //#endif
  }

	delay(duracion * 0.9);
	rgbLedWrite(RGB_BUILTIN, 0, 0, 0);
  noTone(buzzer);
	delay(duracion * 0.1);	
}


void MaxMinTone(int* arregloTonos, int largo, int& max, int& min, bool unArregloDeTodo)
{
	int mini = 300;
	int maxi = 1;
	if (unArregloDeTodo) // un arreglo incluye melodia y duracion de 2 en 2   A1, B1 , A2, B2 ...
	{
		for (int i = 0; i < largo * 2; i = i + 2)
		{
			if (arregloTonos[i] < mini && arregloTonos[i] > 0)
			{
				Serial.print("mini:  "); Serial.print(mini); Serial.print("  >>  "); Serial.print(arregloTonos[i]); Serial.print("  --  i = "); Serial.println(i);
				mini = arregloTonos[i];
			}

			if (arregloTonos[i] > maxi)
			{
				Serial.print("maxi:  "); Serial.print(maxi); Serial.print("  >>  "); Serial.print(arregloTonos[i]); Serial.print("  --  i = "); Serial.println(i);
				maxi = arregloTonos[i];
				//Serial.print("maxi: ");Serial.println(maxi);
			}
		}
	}
	else
	{
		for (int j = 0; j < largo; j++)
		{
			if (arregloTonos[j] < mini && arregloTonos[j] > 0)
			{
				Serial.print("mini:  "); Serial.print(mini); Serial.print("  >>  "); Serial.print(arregloTonos[j]); Serial.print("  --  j = "); Serial.println(j);
				mini = arregloTonos[j];
			}

			if (arregloTonos[j] > maxi) {
				Serial.print("maxi:  "); Serial.print(maxi); Serial.print("  >>  "); Serial.print(arregloTonos[j]); Serial.print("  --  j = "); Serial.println(j);
				maxi = arregloTonos[j];
			}
		}
	}

	max = maxi;
	min = mini;
}


void HsvToRgb(float H, int& r, int& g, int& b)
{	//H = H * 360.0;
	int MAX = 64;
  H = abs(H);
	H = fmod(H, 360); // cycle H around to 0-360 degrees
	H = 3.14159 * H / (float)180; // Convert to radians.

	// Math! Thanks in part to Kyle Miller.
	if (H < 2.09439) {
		r = MAX / 3 * (cos(H) / cos(1.047196667 - H));
		g = MAX / 3 * ((1 - cos(H) / cos(1.047196667 - H)));
		b = MAX / 3;
	}
	else if (H < 4.188787) {
		H = H - 2.09439;
		g = MAX / 3 * (cos(H) / cos(1.047196667 - H));
		b = MAX / 3 * ((1 - cos(H) / cos(1.047196667 - H)));
		r = MAX / 3;
	}
	else {
		H = H - 4.188787;
		b = MAX / 3 * (cos(H) / cos(1.047196667 - H));
		r = MAX / 3 * ((1 - cos(H) / cos(1.047196667 - H)));
		g = MAX / 3;
	}
}


double NotaInterpoladaA360(int nota, int max, int min)
{ // nota valida minima es 31 y maxima es 4978
	if (nota < 31)
		return -1;
	if (nota == 31)
		return 0;
	int notaAux = nota - min; // 4947
	double notaLerp = 360.0 * notaAux;
	notaLerp = notaLerp / max;
	return notaLerp;
}


void JustPlay(int* arregloTonos, int largo, int repetir, int fuckThisShitUp) {
	int mini = 300;
	int maxi = 1;

	for (int i = 0; i < largo * 2; i = i + 2) {
		if (arregloTonos[i] < mini && arregloTonos[i] > 0) mini = arregloTonos[i];
		if (arregloTonos[i] > maxi)	maxi = arregloTonos[i];
	}

  int wholenote = (60000 * 4) / tempo;
  for (int count = 0; count < repetir; count++)
  {
    for (int thisNote = 0; thisNote < melodyLength * 2; thisNote = thisNote + 2) {
      divider = arregloTonos[thisNote + 1];
      if (divider > 0) {
        noteDuration = (wholenote) / divider;
      }
      else if (divider < 0) {
        noteDuration = (wholenote) / abs(divider);
        noteDuration *= 1.5;
      }
      ToneAndColor(arregloTonos[thisNote], noteDuration, maxi, mini, fuckThisShitUp);
    }
  }

}
