/*
 * File Name:        FlashProgrammerFunctions.ino
 * Version:          V0.2
 * Created:          18 September 2017
 * Last Modified:    23 September 2017
 * Author:           Gary MacMinn
 * Purpose:          Supporting functions for the Flash Programmer
 */

/****************************
 * Chip Operation Functions *
 ****************************/

/***********************************************************
 * WriteFlash                                              *
 *                                                         *
 *            +++ CAUTION - DESTRUCTIVE +++                *
 *                                                         * 
 * Writes 16 bytes to Flash starting at the given address. * 
 * Command format is a "W", a colon ":", 5 HEX digits,     *
 * another colon":" and 16 bytes of 2 digit HEX.           *
 *                                                         * 
 * W:00000:0123456789ABCDEF0123456789ABCDEF                * 
 *                                                         * 
 * After writing, the 16 bytes are read and sent to the    *
 * Serial port.                                            *
 *                                                         *
 ***********************************************************/
void WriteFlash(char* startL, char* data)
{
   unsigned long ctr;
   unsigned long WriteAddrL;
   char ReadNiblLo, ReadNiblHi;
   char  readVal, writeVal, hexVal[3];
   
   WriteAddrL = Asc52Long(startL);

   for (ctr = 0 ; ctr <  16; ctr++)
   {
      hexVal[0] = data[ctr *2];
      hexVal[1] = data[ctr *2 + 1];
      hexVal[3] = 0;
      writeVal = Asc22Byte(hexVal);
      DoWrite(0x5555L,0xAA);                // First output byte of Byte Program 
      DoWrite(0x2AAAL,0x55);                // Second output byte of Byte Program
      DoWrite(0x5555L,0xA0);                // Third output byte of of Byte Program
      DoWrite(WriteAddrL+ctr,writeVal);     // Address and Data to store
      delay(1);
   }

   // Read back the section just written
   PrintHex5(WriteAddrL);
   Serial.print(":");   
   for (ctr = 0 ; ctr <  16; ctr++)
   {
      readVal = DoRead(WriteAddrL+ctr);
      ReadNiblLo = readVal & 0xF;
      ReadNiblHi = (readVal >>4) &0xF;
      Serial.print(ReadNiblHi,HEX);
      Serial.print(ReadNiblLo,HEX);
   } 
   Serial.println();
}

/*******************************************************
 * SectorErase                                         *
 *                                                     *
 *            +++ CAUTION - DESTRUCTIVE +++            *
 *                                                     * 
 * Erases the requested sector of the flash.           * 
 * Flash is divided in to 4K or 64k blocks or sectors. *
 * Check the flash memory datasheet for full details.  *
 *                                                     *
 *******************************************************/
void SectorErase(char* Sector)
{
   unsigned long EraseAddrL;
   //char Sector[3]={'\0','\0','\0'};
   //Serial.println();
   //Serial.println("Write to Flash");
   //Serial.println("Sector to Write -");
   //Serial.println("00 to 1F for SST39SF010");   
   //Serial.println("00 to 3F for SST39SF020");   
   //Serial.println("00 to 7F for SST39SF040");   
   //do
   //{
   //   Serial.readBytesUntil(13,Sector,2);
   //}while(Sector[0]==0);
   
   Sector[0]= Sector[0] & 0x0F;
   Sector[0]= Sector[0] <<4;
   Sector[1]= Sector[1] - 0x30;
 
   if (Sector[1] > 0x9)
   {
      Sector[1] = (Sector[1] & 0xF) + 9;
   }
   
   EraseAddrL = Sector[0] | Sector[1];
   EraseAddrL = EraseAddrL << 12;
   
   //Serial.print("Starting address = ");
   
   PrintHex5(EraseAddrL);
   Serial.println();
   DoWrite(0x5555L,0xAA);   // First output byte of Sector Erase 
   DoWrite(0x2AAAL,0x55);   // Second output byte of Sector Erase
   DoWrite(0x5555L,0x80);   // Third output byte of Sector Erase
   DoWrite(0x5555L,0xAA);   // Fourth output byte of Sector Erase
   DoWrite(0x2AAAL,0x55);   // Fifth output byte of Sector Erase
   DoWrite(EraseAddrL,0x30);   // Sector Address and 0x30 Sector Erase Command
}

/*********************************************************
 * ReadFlash                                             *
 *                                                       * 
 * Takes a start address as an unsigned long integer and * 
 * prints the 16 bytes of memory from that location.     *
 *                                                       *
 *********************************************************/
void ReadFlash(char* startL)
{
   unsigned long ctr;
   unsigned long ReadAddrL;
   char ReadNiblLo, ReadNiblHi;
   char readVal;
   
   ReadAddrL = Asc52Long(startL);
   
   PrintHex5(ReadAddrL);
   Serial.print(":");
   for (ctr = ReadAddrL; ctr < (ReadAddrL + 0x10); ctr++)
   {
       readVal = DoRead(ctr);
       ReadNiblLo = readVal & 0xF;
       ReadNiblHi = (readVal >>4) &0xF;
       Serial.print(ReadNiblHi,HEX);
       Serial.print(ReadNiblLo,HEX);
   } 
   Serial.println();
}

/*********************************************************
 * DumpFlash                                             *
 *                                                       * 
 * Takes a start address as an unsigned long integer and * 
 * a length as an unsigned long integer and dumps the    *
 * flash contents in 16 byte lines of hex.               *
 *                                                       *
 *********************************************************/
void DumpFlash(char* startL, char* lengthL)
{
   unsigned long ctr,ctr0;
   unsigned long ReadAddrL, ReadLenL;
   char ReadNiblLo, ReadNiblHi;
   char readVal;

   ReadAddrL = Asc52Long(startL);
   ReadLenL = Asc52Long(lengthL);

   Serial.print("Dump Flash starting at 0x"); Serial.print(startL); 
   Serial.print(" and showing 0x"); Serial.print(lengthL); 
   Serial.println(" bytes."); Serial.println(""); 

   for (ctr0 = ReadAddrL; ctr0 < (ReadAddrL + ReadLenL); ctr0+=0x10) {
     PrintHex5(ctr0);
     Serial.print(":");
     for (ctr = ctr0; ctr < (ctr0 + 0x10); ctr++)
     {
       readVal = DoRead(ctr);
       ReadNiblLo = readVal & 0xF;
       ReadNiblHi = (readVal >>4) &0xF;
       Serial.print(ReadNiblHi,HEX);
       Serial.print(ReadNiblLo,HEX);
     } 
     Serial.println();
     //ReadAddrL+= 0x10;
   }
}

/****************************************************
 * DoWrite                                          *
 *                                                  * 
 * Takes an address as un unsigned long integer and * 
 * a byte and writes the byte to that address       *
 *                                                  *
 ****************************************************/
void DoWrite(unsigned long writeAddr, byte writeVal)
{
   digitalWrite(LedRed,HIGH);           // Turn the red LED on to show a write operation
   
   LoadAddr(writeAddr);
   DDRL = 255;    // set port A as all outputs to Flash Data Lines
   PORTL = writeVal;      // load the value to PORTA

  digitalWrite(ChipEN,LOW);     // set ChipEN and WriteEN LOW
  digitalWrite(WriteEN,LOW);

  delay(1);                // let the signals settle

  digitalWrite(ChipEN,HIGH);    // set ChipEN and WriteEN HIGH
  digitalWrite(WriteEN,HIGH);

  digitalWrite(LedRed,LOW);           // Led off
}


/*************************************************************************************
 * DoRead                                                                            *
 *                                                                                   * 
 * Takes an address as un unsigned long integer and returns the byte at that address *
 *                                                                                   *
 *************************************************************************************/
byte DoRead(unsigned long readAddr)
{
  byte readVal; 
  //unsigned int PGHold;
  digitalWrite(LedGreen,HIGH);           // Turn the green LED on to show a read operation
  
  LoadAddr(readAddr);
  DDRL = 0;                              // set port A as all inputs from Flash Data Lines
  PORTL=0xFF;

  digitalWrite(ChipEN,LOW);
  digitalWrite(ReadEN,LOW);
  digitalWrite(WriteEN,HIGH);
  
  delay(1);                              // let the signals settle
  readVal = PINL;                        // Read the data

  digitalWrite(ChipEN,HIGH);             // All Enable bits high
  digitalWrite(ReadEN,HIGH);
  digitalWrite(WriteEN,HIGH);
  
  digitalWrite(LedGreen,LOW);           // Led off
  return readVal;
}

/************************************
 * DeviceID                         *
 *                                  * 
 * Gets the device ID from the chip * 
 *                                  *
 ************************************/
void DeviceID()
{
  byte WorkByte;
  Serial.println();
  Serial.println("Device Identification");
  Serial.println();
  DoWrite(0x5555L,0xAA);   // First output byte of Software ID Entry
  DoWrite(0x2AAAL,0x55);   // Second output byte of Software ID Entry
  DoWrite(0x5555L,0x90);   // Third output byte of Software ID Entry
  WorkByte = DoRead(0L);   // Read address 0 for manufacturer ID
  if (WorkByte == 0xBF)
  {
     Serial.println("Chip Manufactured by SST");
  }
  else if (WorkByte == 0x01)
  {
     Serial.println("Chip Manufactured by AMD");
  }
  else if (WorkByte == 0x37)
  {
     Serial.println("Chip Manufactured by AMIC");
  }
  else
  {
     Serial.print("Unkmown manufacturer : ");
     Serial.println(WorkByte,HEX);
  }
  WorkByte = DoRead(1L);   // Read address 1 for Chip ID
  if (WorkByte == 0xB5)
  {
     Serial.println("SST39SF010");
     Serial.println("128Kx8 Device");
     Serial.println("131,072 Bytes");
  }
  else if (WorkByte == 0xB6)
  {
     Serial.println(" SST39SF020");
     Serial.println("256Kx8 Device");
     Serial.println("262,144 Bytes");
  }
  else if (WorkByte == 0xB7)
  {
     Serial.println(" SST39SF040");
     Serial.println("512Kx8 Device");
     Serial.println("524,288 Bytes");
  }
  else if (WorkByte == 0xA4)
  {
     Serial.println(" AM29F040B");
     Serial.println("512Kx8 Device");
     Serial.println("524,288 Bytes");
  }
  else
  {
     Serial.print(" Unknown Device : ");
     Serial.println(WorkByte,HEX);
  }
  Serial.println();
  DoWrite(0x5555L,0xF0);   // Exit ID Mode
}


/*********************
 * Utility Functions *
 *********************/

/************************************************
 * ProcessCommand                               *
 *                                              *
 * Processes the appropriate command based      *
 * on the first character of the command string *
 *                                              *
 ************************************************/

void ProcessCommand(char cmd) {
  //Serial.print("Process Command: "); Serial.println(cmd);

  switch (toupper(cmd))                 // Convert the instruction to upper case and switch
   {
      case '?': // '?' display Help
                 Help();
                 break;
      case 'D': // 'D' Dumps a section of the chip
                 DumpFlash(substrings[1],substrings[2]);
                 break;
      case 'E': // 'E' Erase device
                 // not implemented.
                 break;
      case 'I': // 'I' device Id
                 DeviceID();
                 break;
      case 'R': // 'R' Read flash
                 ReadFlash(substrings[1]);
                 break;
      case 'S': // S' erase Sector
                 SectorErase(substrings[1]);
                 break;
      case 'W': // 'W' Write to flash
                 WriteFlash(substrings[1],substrings[2]);
                 break;
   }
}

/********************************************
 * ParseString                              *
 *                                          * 
 * Chops up the command string using ':'    *
 * as the seperator and outputs the (up to) *
 * 3 parts:                                 *
 *   Command                                *
 *   Start Address                          *
 *   Option 3rd parameter                   *
 *                                          *
 ********************************************/
void ParseString(char *s) {
    // First clear the array of substrings
    for (int i = 0; i < MAX_SUBSTRINGS; i++)
        substrings[i] = 0;
    // Now split the input string
    char* text = strtok(s,":");
    int i = 0;
    while (text != 0 && i < MAX_SUBSTRINGS) {
        // A token was found: append it to the array of substrings
        substrings[i++] = text;
        text = strtok(0,":");
    }
}

/****************************************
 * readline                             *
 *                                      * 
 * Reads a command line from the Serial *
 * port                                 *
 *                                      *
 ****************************************/
int readline(int readch, char *buffer, int len)
{
  static int pos = 0;
  int rpos;
  

  if (readch > 0) {
    switch (readch) {
      case '\n': // Ignore new-lines
        break;
      case '\r': // Return on CR
        rpos = pos;
        pos = 0;  // Reset position index ready for next time
        return rpos;
      default:
        if (pos < len-1) {
          buffer[pos++] = readch;
          buffer[pos] = 0;
        }
    }
  }
  // No end of line has been found, so return -1.
  return -1;
}

/*******************************************
 * Asc22Byte                               *
 *                                         * 
 * takes 2 HEX digits and converts them to *
 * a byte                                  *
 *                                         *
 *******************************************/
byte Asc22Byte(char *srcStr)
{
  int ctr;
  char tmpChar;
  char workChar = 0;
  for (ctr = 0; ctr < 2 ; ctr++)
  {
      tmpChar = srcStr[ctr];
      tmpChar = tmpChar & 0x4F;
      if (tmpChar > 9) 
      {
         tmpChar = (tmpChar & 0xF) + 9;
      }
      workChar = (workChar << 4) + tmpChar;
  }
  return workChar;
}

/*******************************************
 * Asc52Long                               *
 *                                         * 
 * takes 5 HEX digits and converts them to *
 * an unsigned long                        *
 *                                         *
 *******************************************/
unsigned long Asc52Long(char *srcStr)
{
  int ctr;
  int tmpChar;
  unsigned long tmpLong = 0L;
  for (ctr = 0; ctr < 5; ctr++)
  {
      tmpChar = srcStr[ctr];
      tmpChar = tmpChar & 0x4F;
      if (tmpChar > 9) 
      {
         tmpChar = (tmpChar & 0xF) + 9;
      }
      tmpLong = (tmpLong << 4) + tmpChar;
  }
  return tmpLong;   
}

/*******************************************
 * PrintHex5                               *
 *                                         * 
 * Prints an unsigned long as 5 hex digits * 
 *                                         *
 *******************************************/
void PrintHex5(unsigned long PrintVal)
{
  Serial.print((PrintVal >> 16) & 0xF,HEX);
  Serial.print((PrintVal >> 12) & 0xF,HEX);
  Serial.print((PrintVal >> 8) & 0xF,HEX);
  Serial.print((PrintVal >> 4) & 0xF,HEX);
  Serial.print(PrintVal & 0xF,HEX);
}  

/**********************************************************
 * LoadAddr                                               *
 *                                                        *
 * Takes an address as an unsigned long and               *
 * loads it into the address ports A & C and the extra    *
 * three high bit pins (AD16-AD18).                       *
 *                                                        *
 * On exit, ChipEN, WriteEN, and ReadEN will all be HIGH. *
 *                                                        *
 **********************************************************/
void LoadAddr(unsigned long AddressL)
{
  unsigned long workAddrL;
  workAddrL = AddressL;
  PORTA = lowByte(workAddrL);
  PORTC = highByte(workAddrL);

  digitalWrite(AD16, (AddressL&65536)?HIGH:LOW);
  digitalWrite(AD17, (AddressL&131072)?HIGH:LOW);
  digitalWrite(AD18, (AddressL&262144)?HIGH:LOW);
  
  digitalWrite(ChipEN,HIGH);
  digitalWrite(ReadEN,HIGH);
  digitalWrite(WriteEN,HIGH);
}

/*******************************************************
 * Help                                                *
 *                                                     *
 * Prints a simple help message describing the various *
 * commands and their parameters.                      *
 *                                                     *
 *******************************************************/
void Help()
{
   Serial.println();
   Serial.println("(I)d     - read the software ID of the chip (I)");
   Serial.println("(R)ead   - Read the contents of a sector.   (R:xxxxx)");
   Serial.println("(D)ump   - Dump a block of sectors.         (D:xxxxx:yyyyy)");
   Serial.println("(E)rase  - Erase the entire chip (not implemented yet)");
   Serial.println("(S)ector - erase a Sector.                  (S:xx)");
   Serial.println("(W)rite  - Write code to the flash.         (W:xxxxx:yy...yy)");
   Serial.println("(?)      - Shows this command reference");
   Serial.println();
}


