#include <LiquidCrystal.h>

#include "pitches.h"

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int LCDswitchPin = 7; // define menu/LCD switch name
int LCDswitchState = 0; // set menu/LCD switch state to off/low
int prevLCDswitchState = 0;
int blueLED = 6;
int LCDswitchCounter = 0;   // counter for the number of menu button presses 
    // (this code counts the menu button pushes, displays them on your computer, 
    // and starts from zero after ending "menu mode". currently has no other effect 
    // on this sketch, but is a good starting point for expanding on the project with 
    // new features later    

// Music Note Keys - Set frequency values
int notes[] = {262, 294, 330, 349, 392, 440, 494}; // Set notes C, D, E, F, G, A, B



//////////////////////////////////////////////
void setup() {
  
  Serial.begin(9600);
  
  lcd.begin(16, 2);
  pinMode(LCDswitchPin, INPUT);
  pinMode(blueLED, OUTPUT);
  digitalWrite(blueLED, LOW); // LED stays off while piano keys are on
  

} // end setup


//////////////////////////////////////////////
void loop() {
  
  LCDswitchState = digitalRead(LCDswitchPin);
  int keyVal = analogRead(A0);
  Serial.println(keyVal);
  lcd.noDisplay();
  digitalWrite(blueLED, LOW); // Turn LED back off every time main loop starts
  


// ************** START "LCDstart" WHEN MENU BUTTON IS PUSHED ***********

    if (LCDswitchState == HIGH)  {
      digitalWrite(blueLED, HIGH); // Turn LED on to show piano keys are disabled and device is in "menu mode"
      lcd.display();
      lcd.clear();
      LCDstart();
      }
   
   
// ***********************************************************************
  
  

////// KEYBOARD NOTES & FREQUENCY STATEMENTS //////
// Use the resistor ladder you created to change the voltage of each piano key button
// 220 ohm = C5 // 560 ohm = D5 // 1K ohm = E5 // etc...
  if(keyVal == 1023)  {
    tone(8, notes[0]); // C
    } // end if
    
        else if(keyVal >= 990 & keyVal <=1010)  {
          tone(8, notes[1]); // D
          } // end else if
    
        else if(keyVal >= 960 && keyVal <= 980)  {
          tone(8, notes[2]); // E
          } // end else if
        
        else if(keyVal >= 900 && keyVal <= 945)  {
          tone(8, notes[3]); // F
          } // end else if
        
        else if(keyVal >= 650 && keyVal <= 710)  {
          tone(8, notes[4]); // G
          } // end else if
        
        else if(keyVal >= 500 && keyVal <= 550)  {
          tone(8, notes[5]); // A
          } // end else if
        
        else if(keyVal >= 5 && keyVal <= 10)  {
          tone(8, notes[6]); // B
          } // end else if
        
        else if(keyVal <= 1)  { // if no switch is pressed, do not play tone
          noTone(8);
          } // end else if

} //end frequency tone loop





/////////////////////////////////////////////////////
void LCDstart()  {
  int keyVal = analogRead(A0);  
  LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button

    while (LCDswitchState == LOW)  { // continue loop while menu button isn't pressed
      LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button every time loop starts
      
      //************* START SONG 1 TITLE LOOP ********************
      if (LCDswitchState == HIGH)  { // if menu button is pressed, then...
        LCDswitchCounter++; // set button count to 1
        Serial.print("number of button pushes:  ");
        Serial.println(LCDswitchCounter);
        delay(300); // min. time until counts adds 1 more

        Song1title();
        lcd.clear();
        break;
        }

      //************* ELSE SHOW MENU ****************
      else   {  // if menu button is not pressed, then...
        LCDswitchCounter=0; // set menu button count to 0
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("WHICH SONG WOULD");
        lcd.setCursor(0, 1);
        lcd.print("YOU LIKE TO PLAY");
        delay(50); // return to main 
        }
     
      } // end while
  } // end LCDstart loop
  
  
  

// ************* SONG 1 LOOP STARTS HERE **************  
void Song1title()  {
  int keyVal = analogRead(A0);
  LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again
  
  while (LCDswitchState == LOW)  { // continue loop while menu button isn't pressed  
    LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again 

      //************* START SONG 2 TITLE LOOP ********************
      if (LCDswitchState == HIGH)  { // if menu button is pressed, then...
        LCDswitchCounter++; // set button count to 2
        Serial.print("number of button pushes:  ");
        Serial.println(LCDswitchCounter);
        delay(300); // min. time until counts adds 1 more

        Song2title();
        lcd.clear();
        break;
        }
        
      else  { // if menu button is not pressed   
        int keyVal = analogRead(A0);
        Serial.println(keyVal); 
         
         if(keyVal >= 2)  {
           digitalWrite(blueLED, LOW);
           Song1();
           break;
           } // end if
        
        lcd.clear();
        lcd.setCursor(0, 0);
        //lcd.print("SUPER MARIO BROS");
        lcd.print("FOKKING STEBBI");
        lcd.setCursor(0, 1);
        lcd.print("   THEME SONG");
        delay(50);
        }
    } // end while song 1 -> 2
        
} // end Song1title loop


void Song1()  {
  
  lcd.clear();


// notes in the melody:
int melody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};


      lcd.setCursor(1, 0);
      lcd.print("Now playing...");
      lcd.setCursor(0, 1);
      lcd.print("MARIO THEME SONG");
     
      


    int size = sizeof(melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
 
      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDurations[thisNote];
 
      tone(8, melody[thisNote], noteDuration);
 
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
 
      // stop the tone playing:
      tone(8, 0, noteDuration);
 
    }


Song1title();

  
  } // end Song1 loop


// ************* SONG 2 LOOP STARTS HERE **************  
void Song2title()  {
  int keyVal = analogRead(A0);
  LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again
  
  while (LCDswitchState == LOW)  { // continue loop while menu button isn't pressed  
    LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again 

      //************* START SONG 3 TITLE LOOP ********************
      if (LCDswitchState == HIGH)  { // if menu button is pressed, then...
        LCDswitchCounter++; // set button count to 3
        Serial.print("number of button pushes:  ");
        Serial.println(LCDswitchCounter);
        delay(300); // min. time until counts adds 1 more

        Song3title();
        lcd.clear();
        break;
        }
        
      else  { // if menu button is not pressed
        int keyVal = analogRead(A0);
        Serial.println(keyVal); 
         
         if(keyVal >= 2)  {
           digitalWrite(blueLED, LOW);
           Song2();
           break;
           } // end if
           
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("SUPER MARIO BROS");
          lcd.setCursor(0, 1);
          lcd.print("   UNDERWORLD");
          delay(50);
          }
        
        } // end while song 2 -> 3
        
} // end Song2title loop

void Song2()  {
  
  lcd.clear();


// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0, NOTE_DS4, NOTE_CS4, NOTE_D4,
  NOTE_CS4, NOTE_DS4,
  NOTE_DS4, NOTE_GS3,
  NOTE_G3, NOTE_CS4,
  NOTE_C4, NOTE_FS4, NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
  NOTE_GS4, NOTE_DS4, NOTE_B3,
  NOTE_AS3, NOTE_A3, NOTE_GS3,
  0, 0, 0
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  6, 18, 18, 18,
  6, 6,
  6, 6,
  6, 6,
  18, 18, 18, 18, 18, 18,
  10, 10, 10,
  10, 10, 10,
  3, 3, 3
};


      lcd.setCursor(1, 0);
      lcd.print("Now playing...");
      lcd.setCursor(0, 1);
      lcd.print("MARIO UNDERWORLD");
     
      


    int size = sizeof(melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
 
      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDurations[thisNote];
 
      tone(8, melody[thisNote], noteDuration);
 
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
 
      // stop the tone playing:
      tone(8, 0, noteDuration);
 
    }


Song2title();

  
  } // end Song2 loop



// ************* SONG 3 LOOP STARTS HERE **************  
void Song3title()  {
  int keyVal = analogRead(A0);
  LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again
  
  while (LCDswitchState == LOW)  { // continue loop while menu button isn't pressed  
    LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again 

      //************* START SONG 4 TITLE LOOP ********************
      if (LCDswitchState == HIGH)  { // if menu button is pressed, then...
        LCDswitchCounter++; // set button count to 4
        Serial.print("number of button pushes:  ");
        Serial.println(LCDswitchCounter);
        delay(300); // min. time until counts adds 1 more

        Song4title();
        lcd.clear();
        break;
        }
        
      else  { // if menu button is not pressed
        int keyVal = analogRead(A0);
        Serial.println(keyVal); 
         
         if(keyVal >= 2)  {
           digitalWrite(blueLED, LOW);
           Song3();
           break;
           } // end if
           
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("    JEOPARDY");
        lcd.setCursor(0, 1);
        lcd.print("   THEME SONG");
        delay(50);
        }
        
        } // end while song 3 -> 4
        
} // end Song3title loop
void Song3()  {
  
  lcd.clear();


// notes in the melody:
int melody[] = {
  NOTE_C2, NOTE_F3, NOTE_C3, NOTE_A2, NOTE_A2,
  NOTE_C3, NOTE_F3, NOTE_C3,
  NOTE_C3, NOTE_F3, NOTE_C3, NOTE_F3,
  NOTE_AS3, NOTE_G3, NOTE_F3, NOTE_E3, NOTE_D3, NOTE_CS3,
  NOTE_C2, NOTE_F3, NOTE_C3, NOTE_A2, NOTE_A2, // repeat line 1 and 2
  NOTE_C3, NOTE_F3, NOTE_C3,
  NOTE_AS3, 0, NOTE_G3, NOTE_F3,
  NOTE_E3, NOTE_D3, NOTE_CS3, NOTE_C3};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4,    4,    4,    8,   8,
  4,    4,          2,
  4,    4,    4,    4,
  3,    8,    8,    8,    8,   8,
  4,    4,    4,    8,    8, // repeat line 1 and 2
  4,    4,          2,
  4,    8,    8,    4,    4,
  4,    4,    4,    4,
  0};


      lcd.setCursor(1, 0);
      lcd.print("Now playing...");
      lcd.setCursor(0, 1);
      lcd.print("    JEOPARDY");
     
      

  for (int thisNote = 0; noteDurations[thisNote] != 0; thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 2000/noteDurations[thisNote];
    tone(8, melody[thisNote],noteDuration * 0.9);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    //int pauseBetweenNotes = noteDuration * 1.30;
    //delay(pauseBetweenNotes);
  delay(noteDuration);
  }


Song3title();

  
  } // end Song3 loop





// ************* SONG 4 LOOP STARTS HERE **************  
void Song4title()  {
  int keyVal = analogRead(A0);
  LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again
  
  while (LCDswitchState == LOW)  { // continue loop while menu button isn't pressed  
    LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again 

      //************* START SONG 5 TITLE LOOP ********************
      if (LCDswitchState == HIGH)  { // if menu button is pressed, then...
        LCDswitchCounter++; // set button count to 5
        Serial.print("number of button pushes:  ");
        Serial.println(LCDswitchCounter);
        delay(300); // min. time until counts adds 1 more

        Song5title();
        lcd.clear();
        break;
        }
        
      else  { // if menu button is not pressed
        int keyVal = analogRead(A0);
        Serial.println(keyVal); 
         
         if(keyVal >= 2)  {
           digitalWrite(blueLED, LOW);
           //Song4();
           break;
           } // end if
          
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("     SONG 4");
          lcd.setCursor(0, 1);
          lcd.print("   TITLE HERE");
          delay(50);
          }
        
        } // end while song 4 -> 5
        
} // end Song4title loop






// ************* SONG 5 LOOP STARTS HERE **************  
void Song5title()  {
  int keyVal = analogRead(A0);
  LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again
  
  while (LCDswitchState == LOW)  { // continue loop while menu button isn't pressed  
    LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again 

      //************* START SONG 4 TITLE LOOP ********************
      if (LCDswitchState == HIGH)  { // if menu button is pressed, then...
        LCDswitchCounter=0; // set button count to 0
        Serial.print("number of button pushes:  ");
        Serial.println(LCDswitchCounter);
        delay(300); // min. time until counts adds 1 more
        lcd.clear();
        }
        
      else  { // if menu button is not pressed
        int keyVal = analogRead(A0);
        Serial.println(keyVal); 
         
         if(keyVal >= 2)  {
           digitalWrite(blueLED, LOW);
           //Song5();
           break;
           } // end if
           
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("     SONG 5");
          lcd.setCursor(0, 1);
          lcd.print("   TITLE HERE");
          delay(50);
          }
        
        } // end while song 4 -> 5
        
} // end Song5title loop







