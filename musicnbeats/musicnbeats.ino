#include <EEPROM.h>
#include <SPI.h>
#include <GD2.h>

void setup()
{
  GD.begin();
}

#define DARK_GREEN      0x007000
#define LIGHT_GREEN     0x33ff33
#define DARK_RED        0x600000
#define LIGHT_RED       0xff3333
#define DARK_YELLOW     0x707000
#define LIGHT_YELLOW    0xffff33
#define DARK_BLUE       0x007070
#define LIGHT_BLUE      0x33ffff

void drawscreen(int pressed)
{
  GD.get_inputs();
  GD.Clear();

  GD.PointSize(16 * 20);  // 60-pixel radius points
  GD.Begin(RECTS);
  GD.Tag(1);
  if (pressed == 1)
    GD.ColorRGB(LIGHT_YELLOW);
  else
    GD.ColorRGB(DARK_GREEN);
  GD.Vertex2ii(50, 50);
  GD.Vertex2ii(100, 100);
  
  GD.Tag(2);
  if (pressed == 2)
    GD.ColorRGB(LIGHT_YELLOW);
  else
    GD.ColorRGB(DARK_YELLOW);
  GD.Vertex2ii(100, 100);
  GD.Vertex2ii(150, 150);
  
  GD.Tag(3);
  if (pressed == 3)
    GD.ColorRGB(LIGHT_YELLOW);
  else
    GD.ColorRGB(DARK_RED);
  GD.Vertex2ii(150, 150);
  GD.Vertex2ii(200, 200);
  
  GD.Tag(4);
  if (pressed == 4)
    GD.ColorRGB(LIGHT_YELLOW);
  else
    GD.ColorRGB(DARK_BLUE);
  GD.Vertex2ii(200, 200);
  GD.Vertex2ii(250, 250);
  
  GD.swap();
}

void play(int pressed)
{
  //                 G   R   Y   B
  //                 E3  A4  C#4 E4
  byte note[] = { 0, 52, 69, 61, 64 };
  GD.play(HARP, note[pressed]);
  for (int i = 0; i < 30; i++)
    drawscreen(pressed);
  for (int i = 0; i < 30; i++)
    drawscreen(0);
}

static int get_note()
{
  byte pressed = 0;
  while (pressed == 0) {
    GD.random();
    drawscreen(0);
    if ((1 <= GD.inputs.tag) && (GD.inputs.tag <= 4))
      pressed = GD.inputs.tag;
  }
  play(pressed);
  return pressed;
}

static int random_note()
{
  return 1 + GD.random(4);
}

void loop()
{
  int pressed = get_note();
    return;
  //}
}
