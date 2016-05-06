#include <Arduino.h>

#define input_sensitive 1000

// pin output number by arduino uno
#define PIN_Y0 3
#define PIN_Y1 4
#define PIN_Y2 5
#define PIN_Y3 6
#define PIN_Y4 9
#define PIN_Y5 10
#define PIN_Y6 11
#define PIN_Y7 12

//pin input number by arduino uno
#define PIN_X0 2
#define PIN_X1 A3
#define PIN_X2 A2
#define PIN_X3 A1
#define PIN_X4 A0
#define PIN_X5 A7
#define PIN_X6 A6
#define PIN_X7 13

//fast Read input builtin
#define X0 (bool)((PIND>>2))
#define X1 (bool)((PINC>>3)&1)
#define X2 (bool)((PINC>>2)&1)
#define X3 (bool)((PINC>>1)&1)
#define X4 (bool)((PINC)&1)
#define X5 (bool)(analogRead(A7)/900)
#define X6 (bool)(analogRead(A6)/900) 
#define X7 (bool)((PINB>>5)&1)

//fast Read output builtin
#define Y0 (bool)((PIND>>3)&1)
#define Y1 (bool)((PIND>>4)&1)
#define Y2 (bool)((PIND>>5)&1)
#define Y3 (bool)((PIND>>6)&1)
#define Y4 (bool)((PINB>>1)&1)
#define Y5 (bool)((PINB>>2)&1)
#define Y6 (bool)((PINB>>3)&1)
#define Y7 (bool)((PINB>>4)&1)

// pin comport
#define TX1 0  //COM1
#define RX1 0

#define TX2 0  //COM2
#define RX2 0

// pin IIC
#define SDA 0
#define SCL 0


void input_config()
{
  DDRB  &=!(0x10);
  PORTB &=!(0x10);

  DDRC  &=!(0x0F);
  PORTC &=!(0x0F);

  DDRD  &=!(0x04);
  PORTD  &=!(0x04);
}

void output_config()
{
 
   DDRD |= 0x78 ;               
   DDRB |= 0x1E ;
}


void set_porty(uint8_t data)
{
  
   // 0b1xxxx111 --> 0x87
     PORTD = (PORTD&0x87)|((data&0x0F)<<3);
     // 0b111xxxx1 --> 0xE1
     PORTB = (PORTB&0xE1)|((data&0xF0)>>3);
    
}

int get_porty()
{
  return 0 ;
}

int get_portx()
{
  return 0 ;
}


