//Superhero Power Plant
//fades all pixels subtly
//code by Tony Sherwood for Adafruit Industries

#include <Adafruit_NeoPixel.h>

#define PIN 2
#define PIN2 3
#define BRIGHTNESS 64  //Max brightness for most patterns, keep lower to reduce current consumption
#define LOWHEART 25  //Low brightness setting of heartbeat pattern
#define HIGHHEART 150  //High brightness setting of heartbeat pattern



// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel ring = Adafruit_NeoPixel(24, PIN, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel jewel = Adafruit_NeoPixel(7, PIN2, NEO_GRB + NEO_KHZ800);

int minAlpha = 0; // Min value of brightness
int maxAlpha = 255; // Max value of brightness
int alphaDelta = 5; // Delta of brightness between times through the loop
int red;
int green;
int blue;
int rand_pixel;
int j;
int button1 = 4;
int b1 =0;
int led = 13;

void setup() 
{
  ring.begin();
  jewel.begin();
  ring.show(); // Initialize all pixels to 'off'
  jewel.show();
  pinMode(button1, INPUT);
  pinMode(led, OUTPUT);
}

void loop() 
{

 int b1 = digitalRead(button1);
  
 if (b1 == 1)
 {
    red=102;
    green=255;
    blue=255;
   colorfill(0x0080ff);
   colorfill2(0xFFFF33);
   digitalWrite(led, HIGH);
  }
  else 
  {
   glow();
 digitalWrite(led, LOW);
  }
 }

void colorfill(uint32_t c)
{
  ring.fill(c,0);
ring.setBrightness(64);
  ring.show();
}
void colorfill2(uint32_t c)
{
 jewel.fill(c,0);
jewel.setBrightness(64);
 jewel.show();
}
void glow(){
  colorWipe(ring.Color(255,255,255),10);
  colorfill2(0x00ffcc);
  //jewel.setBrightness(25);
    //jewel.show();
  //delay(10);
  for(int m = 1; m < BRIGHTNESS; m++){
    //if(chkBtn(digitalRead(button1))){break;}
    ring.setBrightness(m);
    ring.show();
   //jewel.setBrightness(m-1);
   //jewel.show();
    
    //colorWipe(strip.Color(255,255,255),0);
    //if(m == BRIGHTNESS){x = -1;}
    delay(30);
  }
  for(int m = BRIGHTNESS; m > 0; m--){
  //  if(chkBtn(digitalRead(button1))){break;}
    ring.setBrightness(m);
    ring.show();
  //jewel.setBrightness(m+1);
  // jewel.show();
    //colorWipe(strip.Color(255,255,255),0);
    //if(m == BRIGHTNESS){x = -1;}
    delay(30);
  }
}
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<ring.numPixels(); i++) {
  //  if(chkBtn(digitalRead(button1))){break;}
      ring.setPixelColor(i, c);
      ring.show();
     // jewel.setPixelColor(i,c);
      //jewel.show();
      delay(wait);
  }}
