#include <TMRpcm.h>
#include <SD.h>
#include <EEPROM.h>
#include <SPI.h>
#include <GD2.h>

#define DARK_GREEN      0x007000
#define LIGHT_GREEN     0x33ff33
#define DARK_RED        0x700000
#define LIGHT_RED       0xff3333
#define DARK_YELLOW     0x707000
#define LIGHT_YELLOW    0xffff33
#define DARK_BLUE       0x007070
#define LIGHT_BLUE      0x33ffff
#define BEATS            "cool.ima"
#define COWBELL          "cowbell.jpg"
//TMRpcm tmrpcm;
static Streamer stream;
void setup()
{
  //tmrpcm.speakerPin = 9;
  GD.begin();
  //GD.cmd_loadimage(200, 200)
  //GD.load("morecowbell.jpg");
  //tmrpcm.play("cool.wav");
  //stream.begin(BEATS);
}

void drawscreen(int pressed)
{
  GD.get_inputs();
  //GD.Clear();
  GD.cmd_gradient(0, 0,   0x0060c0,
                0, 271, 0xc06000);
  //GD.Clear();              
  GD.cmd_text(240, 136, 31, OPT_CENTER, "Keyboard Kid!!");
  GD.PointSize(16 * 30);  // 60-pixel radius points
  GD.Begin(RECTS);
  GD.Tag(1);
  if (pressed == 1)
    GD.ColorRGB(LIGHT_GREEN);
  else
    GD.ColorRGB(DARK_GREEN);
  GD.Vertex2ii(0, 0);
  GD.Vertex2ii(50, 50);

  GD.Tag(2);
  if (pressed == 2)
    GD.ColorRGB(LIGHT_RED);
  else
    GD.ColorRGB(DARK_RED);
  GD.Vertex2ii(0, 51);
  GD.Vertex2ii(50, 100);

  GD.Tag(3);
  if (pressed == 3)
    GD.ColorRGB(LIGHT_GREEN);
  else
    GD.ColorRGB(DARK_GREEN);
  GD.Vertex2ii(0, 102);
  GD.Vertex2ii(50, 150);

  GD.Tag(4);
  if (pressed == 4)
    GD.ColorRGB(LIGHT_RED);
  else
    GD.ColorRGB(DARK_RED);
  GD.Vertex2ii(0, 153);
  GD.Vertex2ii(50, 200);

  GD.Tag(5);
  if (pressed == 5)
    GD.ColorRGB(LIGHT_GREEN);
  else
    GD.ColorRGB(DARK_GREEN);
  GD.Vertex2ii(0, 204);
  GD.Vertex2ii(50, 250);
  
  GD.swap();
}

void play(int pressed)
{
  //                 G   R   Y   R   F  
  //                 E3  A4  C#4 E4
  byte note[] = { 0, 52, 69, 61, 64, 67};
  GD.play(PIANO, note[pressed]);
  //audio.play(COOL);
  for (int i = 0; i < 30; i++)
    drawscreen(pressed);
  for (int i = 0; i < 15; i++)
    drawscreen(0);
}

static int get_note()
{
  byte pressed = 0;
  while (pressed == 0) {
    GD.random();
    drawscreen(0);
    if ((1 <= GD.inputs.tag) && (GD.inputs.tag <= 5))
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
    //GD.Begin(BITMAPS);
    ///GD.Vertex2ii(200, 200);
    //GD.swap();
  //tmrpcm.play("cool.wav");
  int sequence[100];
  int length = 0;
    sequence[length++] = random_note();
      int pressed = get_note();
  // stream.feed();
}
