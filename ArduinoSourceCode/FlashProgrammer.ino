/*
 * File Name:        FlashProgrammer.ino
 * Version:          V0.4
 * Created:          18 September 2017
 * Last Modified:    1 October 2017
 * Author:           Gary MacMinn
 * Purpose:          Flash Memory Programmer
 * 
 * Notes:
 *   PORTL is data bits 0-7
 *   PORTA is address bits 0-7
 *   PORTC is address bits 8-15
 */
  
// Define high address pins 
int AD16 = 53; 
int AD17 = 52; 
int AD18 = 51; 

// Define control pins
int ChipEN = 40;
int ReadEN = 39;
int WriteEN = 41;

// Define the LED pins
int LedRed = 38;
int LedGreen = 50;

const int MAX_SUBSTRINGS = 3;             // Maximum number of command parts
static char* substrings[MAX_SUBSTRINGS];  // Array of pointers to each command part after ParseString() has been called

char inputBuffer[45];
int cnt = 0;
boolean ready = false;

void setup()
{
  Serial.begin(115200);

  // set the LED pins as outputs and turn them off
  pinMode(LedRed,OUTPUT);
  digitalWrite(LedRed,LOW);
  pinMode(LedGreen,OUTPUT);
  digitalWrite(LedGreen,LOW);
  
  // set control signals to HIGH (All are active LOW)
  pinMode(ChipEN,OUTPUT);
  digitalWrite(ChipEN,HIGH);
  pinMode(ReadEN,OUTPUT);
  digitalWrite(ReadEN,HIGH);
  pinMode(WriteEN,OUTPUT);
  digitalWrite(WriteEN,HIGH);
  
  // configure the address lines as outputs and set them all to LOW
  DDRA = 255;
  PORTA = 0;
  DDRC = 255;
  PORTC = 0;
  pinMode(AD16,OUTPUT);
  digitalWrite(AD16,0);
  pinMode(AD17,OUTPUT);
  digitalWrite(AD17,0);
  pinMode(AD18,OUTPUT);
  digitalWrite(AD18,0);
  
  Serial.println();
  Serial.println("Flash Memory Programmer Ver 0.4");
  Serial.println("(C)2017 Gary MacMinn");

  // Flash the LEDs to show we're ready
  digitalWrite(LedRed,HIGH);
  delay(500);
  digitalWrite(LedRed,LOW);
  digitalWrite(LedGreen,HIGH);
  delay(500);
  digitalWrite(LedGreen,LOW);
  digitalWrite(LedRed,HIGH);
  delay(500);
  digitalWrite(LedRed,LOW);
  digitalWrite(LedGreen,HIGH);
  delay(500);
  digitalWrite(LedGreen,LOW);

  Serial.print("Ready> ");
}

void loop()
{
  if (readline(Serial.read(), inputBuffer, 80) > 0) {
    Serial.println("");
    
    ParseString(inputBuffer);

    ProcessCommand(substrings[0][0]);
    
    Serial.print("Ready> ");
  }
}

