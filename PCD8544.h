#ifndef _PIC_CCS_PCD8544_H
#define _PIC_CCS_PCD8544_H

#define BLACK 1
#define WHITE 0

#define LCDWIDTH 84
#define LCDHEIGHT 48

#define PCD8544_POWERDOWN 0x04
#define PCD8544_ENTRYMODE 0x02
#define PCD8544_EXTENDEDINSTRUCTION 0x01

#define PCD8544_DISPLAYBLANK 0x0
#define PCD8544_DISPLAYNORMAL 0x4
#define PCD8544_DISPLAYALLON 0x1
#define PCD8544_DISPLAYINVERTED 0x5

// H = 0
#define PCD8544_FUNCTIONSET 0x20
#define PCD8544_DISPLAYCONTROL 0x08
#define PCD8544_SETYADDR 0x40
#define PCD8544_SETXADDR 0x80

// H = 1
#define PCD8544_SETTEMP 0x04
#define PCD8544_SETBIAS 0x10
#define PCD8544_SETVOP 0x80

#define _RST 	PIN_B2		//S3 Reset signal for LCD	(Active in low) S3
#define _CE 	PIN_B1 		//S2 Chip enable, this signal enables the driver (active in low)
#define _DC		PIN_B0 		//S1 Data/command, 1 for data, 0 for command
#define _DIN	PIN_B4		//TX SPI data line
#define _CLK	PIN_B5 		//RX SPI clock signal

typedef unsigned int8 uint8_t;
typedef  int8 int8_t;
typedef unsigned int16 uint16_t;
typedef signed int16 int16_t;

  void PCD_drawPixel(int16_t x, int16_t y, uint16_t color);
  unsigned int8 PCD_getPixel(int8_t x, int8_t y);
  void PCD_spiWrite(uint8_t d);

  void PCD_begin(uint8_t contrast = 40, uint8_t bias = 0x04);
  
  void PCD_command(uint8_t c);
  void PCD_data(uint8_t c);
  
  void PCD_setContrast(uint8_t val);
  void PCD_clearDisplay(void);
  void PCD_display();
  void PCD_drawChart(char c);
  void PCD_setCursor(uint16_t x, uint16_t y);	
