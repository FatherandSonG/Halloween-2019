//Robin Gambin Halloween Arc Reactor

#include <Adafruit_NeoPixel.h>

#define PIN 2 //Ring control pin
#define PIN2 3 //Jewel control pin
#define BRIGHTNESS 40  //Max brightness for most patterns, keep lower to reduce current consumption
#define LOWHEART 25  //Low brightness setting of heartbeat pattern
#define HIGHHEART 150  //High brightness setting of heartbeat pattern
#define NUM_PATTERNS 5 //total number of patterns

Adafruit_NeoPixel ring = Adafruit_NeoPixel(24, PIN, NEO_GRB + NEO_KHZ800); //(# of pixels, control pin, style + speed)
Adafruit_NeoPixel jewel = Adafruit_NeoPixel(7, PIN2, NEO_GRB + NEO_KHZ800);

int red;
int green;
int blue;
unsigned long mark;
int j;
int button1 = 4;
int b1 = 0;
int pattern = 1;
void setup() 
{
  ring.begin();
  jewel.begin();
  ring.show(); // Initialize all pixels to 'off'
  jewel.show();
  pinMode(button1, INPUT);
}

void loop() //main loop
{
chkBtn(digitalRead(button1)); //read the state of the button

if (pattern > NUM_PATTERNS){(pattern = 1);} //reset pattern when it is over max

pickPattern(pattern);
}
/* Functions to call and do operations */

boolean chkBtn(int b1)
{
  if (b1 == HIGH && (millis()- mark) > 250)
  {
    mark = millis();
    pattern++;
    return true;
  }
  else
  {
    return false;
  }}

void pickPattern(int var) //case structure
{
  switch (var)
  {
    case 1:
    ironman();
    break;

    case 2:
    heart();
    break;

    case 3:
   // colorring(0x00ff00);
    //colorjewel(0x00ff00);
    breathing();
    break;

    case 4:
    pulse();

    case 5:
    off();
  }
}

void ironman() //set ironman color and leave steady
{
  ring.setBrightness(40);
  jewel.setBrightness(40);
  colorring(0x66ffff);
  colorjewel(0x66ffff);
}

void heart() //set red color and heartbeat
{
  colorring(0xff0000);
  colorjewel(0xff0000);
  ring.setBrightness(LOWHEART);
  jewel.setBrightness(HIGHHEART);
  for(int q = 0; q < 76; q++)
  {
    if(chkBtn(digitalRead(button1)))
  {
    break;
  }
  delay(20);
}
ring.setBrightness(HIGHHEART);
jewel.setBrightness(LOWHEART);  
  ring.show();
  delay(10);
  jewel.show();
  delay(50);
ring.setBrightness(LOWHEART);
jewel.setBrightness(HIGHHEART);  
  ring.show();
  delay(10);
  jewel.show();  
  delay(250);
ring.setBrightness(HIGHHEART);
jewel.setBrightness(LOWHEART);  
  ring.show();
  delay(10);
  jewel.show();  
  delay(50);
}

void breathing() //set green color and breath
{
 int x = 1;
 int y = 0;
    colorring(0x00ff00);
    colorjewel(0x00ff00);
 for(int q = 0; q < 76; q++)
  {
    if(chkBtn(digitalRead(button1)))
  {
    break;
  }
  delay(20);
}
for (int i = 25; i > -1; i = i + x)
{
ring.setBrightness(i);
jewel.setBrightness(i);  
  ring.show();
  jewel.show();
  if (i == 150)
  {
    x = -1;
  }
 if (i == 24)
 {
  break;
 }
 delay(15);

}
 }

void pulse()  //set ironman color and pulse
{
  colorring(0xffffff);
  colorjewel(0xffffff);
}

void off() //all off
{
  colorring(0x000000);
  colorjewel(0x000000);
}

void colorring(uint32_t c)
{
  ring.fill(c,0);
//ring.setBrightness(64);
  ring.show();
}
void colorjewel(uint32_t c)
{
 jewel.fill(c,0);
//jewel.setBrightness(64);
 jewel.show();
}
