#ifndef _ADAFRUIT_GFX_H
#define _ADAFRUIT_GFX_H

#if ARDUINO >= 100
 #include "Arduino.h"
 #include "Print.h"
#else
 #include "WProgram.h"
#endif

#include "gfxfont.h"

#define adagfxswap(a, b) { int16_t t = a; a = b; b = t; }

#if !defined(ESP8266)
  #define swap(a, b) adagfxswap(a, b)
#endif

class Adafruit_GFX : public Print {

 public:

  Adafruit_GFX(int16_t w, int16_t h); // Constructor

  // This MUST be defined by the subclass:
  virtual void drawPixel(int16_t x, int16_t y, uint16_t color) = 0;

  // These MAY be overridden by the subclass to provide device-specific
  // optimized code.  Otherwise 'generic' versions are used.
  virtual void
    drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color),
    drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color),
    drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color),
    drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color),
    fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color),
    fillScreen(uint16_t color),
    invertDisplay(boolean i);

  // These exist only with Adafruit_GFX (no subclass overrides)
  void
    drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color),
	drawArc(int16_t x0, int16_t y0, int16_t r, float endslope, uint16_t color),
	drawQ1Circle(int16_t x0, int16_t y0, int16_t r, uint16_t color),
	drawQ2Circle(int16_t x0, int16_t y0, int16_t r, uint16_t color),
	drawQ3Circle(int16_t x0, int16_t y0, int16_t r, uint16_t color),
	drawHalfCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color),
	drawPartyHornGauge(int16_t x0, int16_t y0, int16_t r, int16_t length, int16_t *gaugestart_x, int16_t *gaugestart_y),
	drawGauge(int16_t x0, int16_t y0, int16_t r, int16_t w, uint16_t color),
    drawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername,
      uint16_t color),
    fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color),
    fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername,
      int16_t delta, uint16_t color),
    drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1,
      int16_t x2, int16_t y2, uint16_t color),
    fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1,
      int16_t x2, int16_t y2, uint16_t color),
    drawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h,
      int16_t radius, uint16_t color),
    fillRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h,
      int16_t radius, uint16_t color),
    drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap,
      int16_t w, int16_t h, uint16_t color),
    drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap,
      int16_t w, int16_t h, uint16_t color, uint16_t bg),
    drawBitmap(int16_t x, int16_t y, uint8_t *bitmap,
      int16_t w, int16_t h, uint16_t color),
    drawBitmap(int16_t x, int16_t y, uint8_t *bitmap,
      int16_t w, int16_t h, uint16_t color, uint16_t bg),
    drawXBitmap(int16_t x, int16_t y, const uint8_t *bitmap,
      int16_t w, int16_t h, uint16_t color),
    drawChar(int16_t x, int16_t y, unsigned char c, uint16_t color,
      uint16_t bg, uint8_t size),
    setCursor(int16_t x, int16_t y),
    setTextColor(uint16_t c),
    setTextColor(uint16_t c, uint16_t bg),
    setTextSize(uint8_t s),
    setTextWrap(boolean w),
    setRotation(uint8_t r),
    cp437(boolean x=true),
    setFont(const GFXfont *f = NULL),
    getTextBounds(char *string, int16_t x, int16_t y,
      int16_t *x1, int16_t *y1, uint16_t *w, uint16_t *h),
    getTextBounds(const __FlashStringHelper *s, int16_t x, int16_t y,
      int16_t *x1, int16_t *y1, uint16_t *w, uint16_t *h);

#if ARDUINO >= 100
  virtual size_t write(uint8_t);
#else
  virtual void   write(uint8_t);
#endif

  int16_t height(void) const;
  int16_t width(void) const;

  uint8_t getRotation(void) const;

  // get current cursor position (get rotation safe maximum values, using: width() for x, height() for y)
  int16_t getCursorX(void) const;
  int16_t getCursorY(void) const;

 protected:
  const int16_t
    WIDTH, HEIGHT;   // This is the 'raw' display w/h - never changes
  int16_t
    _width, _height, // Display w/h as modified by current rotation
    cursor_x, cursor_y;
  uint16_t
    textcolor, textbgcolor;
  uint8_t
    textsize,
    rotation;
  boolean
    wrap,   // If set, 'wrap' text at right edge of display
    _cp437; // If set, use correct CP437 charset (default is off)
  GFXfont
    *gfxFont;
};
class Adafruit_GFX_RectTextGauge{
	public:
		Adafruit_GFX_RectTextGauge(void);
		void initGauge(Adafruit_GFX * gfx, int16_t x, int16_t y,
			int16_t width, int16_t height, int16_t outlinewidth, uint16_t outline, uint16_t background,
			uint16_t textcolor, char * label_upper, char * label_lower);
		void drawGauge(void);
		void drawUpperLabel(int16_t vertical_correction);
		void drawLowerLabel(int16_t vertical_correction);
		void changeUpperLabel(char * label);
		void changeLowerLabel(char * label);
		void updateGauge(char * label);
		boolean contains(int16_t x, int16_t y);
	private:
		Adafruit_GFX *_gfx;
		int16_t _x;
		int16_t _y;
		int16_t _width;
		int16_t _height;
		int16_t _outlinewidth;
		uint16_t _outlinecolor;
		uint16_t _backgroundcolor;
		uint16_t _textcolor;
		char _label_upper[10];
		char _last_upper[10];
		char _label_lower[10];
		char _last_lower[10];

		//main label
		char _label_main[3];
		int16_t _cursorx;
		int16_t _cursory;
		uint16_t _fillw;
		uint16_t _fillh;
		int16_t	_x1;
		int16_t _y1;

		//calculated values
		int16_t _centerx;
		int16_t _centery;


};
class Adafruit_GFX_PartyHornGauge{
	public:
		Adafruit_GFX_PartyHornGauge(void);
		void initGauge(Adafruit_GFX *gfx, int16_t x0, int16_t y0, 
			 int16_t r, uint16_t length, uint16_t outline, uint16_t fill,
			 uint16_t background, uint16_t textcolor, char * label_upper, char * label_lower);
		void drawGauge(void);
		void drawUpperLabel_major(int16_t vertical_correction);
		void drawLowerLabel_major(int16_t vertical_correction);
		void updateGauge_minor(double fill, char * label);
		void updateGauge_major(char * label);
		int16_t getwidth(void);
	private:
		int16_t	_x0;
		int16_t	_y0;
		int16_t _r;
		uint16_t _length;
		uint16_t _outlinecolor;
		uint16_t _fillcolor;
		uint16_t _backgroundcolor;
		uint16_t _textcolor;
		Adafruit_GFX *_gfx;
		char  _label_upper[10];
		char  _label_lower[10];

		//Calculated values - minor gauge
		int16_t _w;
		int16_t _gaugestart_x;
		int16_t _gaugestart_y;
		int16_t _linewidth;
		int16_t _current_x;
		int16_t _current_fill;
		int16_t _minorcursor_x;
		int16_t _minorcursor_y;
		uint16_t _minorfillw;
		uint16_t _minorfillh;
		int16_t _minorx1;
		int16_t _minory1;
		char	_minorlabel[5];

		//Calculated values - major gauge
		int16_t _textboxside;
		int16_t _majorcursor_x;
		int16_t _majorcursor_y;
		uint16_t _majorfillw;
		uint16_t _majorfillh;
		int16_t	_majorx1;
		int16_t _majory1;
		char	_majorlabel[5];



};
class Adafruit_GFX_Button {

 public:
  Adafruit_GFX_Button(void);
  void initButton(Adafruit_GFX *gfx, int16_t x, int16_t y,
   uint8_t w, uint8_t h, uint16_t outline, uint16_t fill,
   uint16_t textcolor, char *label, uint8_t textsize);
  void drawButton(boolean inverted = false);
  boolean contains(int16_t x, int16_t y);

  void press(boolean p);
  boolean isPressed();
  boolean justPressed();
  boolean justReleased();

 private:
  Adafruit_GFX *_gfx;
  int16_t _x, _y;
  uint16_t _w, _h;
  uint8_t _textsize;
  uint16_t _outlinecolor, _fillcolor, _textcolor;
  char _label[10];

  boolean currstate, laststate;
};

class GFXcanvas1 : public Adafruit_GFX {

 public:
  GFXcanvas1(uint16_t w, uint16_t h);
  ~GFXcanvas1(void);
  void     drawPixel(int16_t x, int16_t y, uint16_t color),
           fillScreen(uint16_t color);
  uint8_t *getBuffer(void);
 private:
  uint8_t *buffer;
};

class GFXcanvas16 : public Adafruit_GFX {
  GFXcanvas16(uint16_t w, uint16_t h);
  ~GFXcanvas16(void);
  void      drawPixel(int16_t x, int16_t y, uint16_t color),
            fillScreen(uint16_t color);
  uint16_t *getBuffer(void);
 private:
  uint16_t *buffer;
};

#endif // _ADAFRUIT_GFX_H
