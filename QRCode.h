#ifndef QRCODE_H
#define QRCODE_H

#include <stdint.h>
//wln included pgmspace to move log table(s) and other constants to flash memory and save SRAM
#include <arduino.h>
//wln include the universal graphics library
#include "U8glib.h"
#include <avr/pgmspace.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>

extern Adafruit_ST7735 Tft;
extern boolean debug;


extern const uint8_t antiLogTableF[] PROGMEM;//end of antiLog table

extern const uint8_t LogTableF[] PROGMEM;//end of Log table

// ECC type L
extern const uint8_t LM0[]; //ECC Level L Mask 0
extern const uint8_t LM1[]; //ECC Level L Mask 1
extern const uint8_t LM2[]; //ECC Level L Mask 2
extern const uint8_t LM3[]; //ECC Level L Mask 3
extern const uint8_t LM4[]; //ECC Level L Mask 4
extern const uint8_t LM5[]; //ECC Level L Mask 5,
extern const uint8_t LM6[]; //ECC Level L Mask 6
extern const uint8_t LM7[]; //ECC Level L Mask 7,

extern int maskType;//Place holde for the QR code mask type

extern byte BinaryMessComp[]; //big enough for Version 3.

extern unsigned int MessageI[];//big enough for Version 3 L

extern unsigned int MessageA[];//big enough for Version 3 L

extern int qrV;
extern char qrE;
extern unsigned int GeneratorA[]; //version 3L

extern unsigned int Result[];//big enough for V 3 L

extern unsigned int xorResult[];//big enough for V 3 L

// QR image buffer for grading. supports up to version 3, 29 x29 modules
extern unsigned long qrBuff[];//sized for 1, 2 and 3. Does double duty as offscreen graphics buffer and bit string storage (V27 and later)
extern int qrBuffindex;// holds pointer to the next available bit in the qrBuff when using it for bit string storage
// QR module width and height
extern byte qrS;//2 means a 2x2 pix per module
extern int qrM;//number of modules per side default version 1, changed automatically to correct size based on qrV

extern byte xOffs;
extern byte yOffs;

extern int centerFlag;// if not 0 overides xOffs and yOffs to center the code, 1 centers Horz, 2 centers Vert, 3 centers both directions

extern char charsToEncode[];

extern int grade; //place holder for qrmask grade
//ECC words in binary

//char array length
extern int length;//max length version 3L
//byte counter
extern int byteCounter;
//Keeps track of data displayed
extern int counter;

extern char mess9[]; //a place holder for 9 character messages to be displayed on screen
extern char mess3[]; //a place holder for 3 character messages to be displayed on screen

#endif
