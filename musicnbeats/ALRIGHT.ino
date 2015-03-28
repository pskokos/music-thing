#include <EEPROM.h>
#include <SPI.h> 
#include <GD2.h>

#define MUSICFILE "alright.ima"

static Streamer stream;

void setup()
{
GD.begin();
stream.begin(MUSICFILE);
}

void loop() {
  uint16_t val, range;
  stream.progress(val, range);
  GD.swap();
  GD.finish();
  stream.feed();
}
