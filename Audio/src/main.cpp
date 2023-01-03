#include <M5Core2.h>
#include "AudioFileSourceID3.h"
#include "AudioFileSourceSD.h"
#include "AudioGeneratorMP3.h"
#include "AudioOutputI2S.h"
AudioGeneratorMP3 *mp3;
AudioFileSourceSD *file;
AudioOutputI2S *out;
AudioFileSourceID3 *id3;
void setup() {
  M5.begin();
  file = new AudioFileSourceSD("/Sorprendido.mp3");
  id3  = new AudioFileSourceID3(file);
  out  = new AudioOutputI2S(0,2,8,0);  // Output to builtInDAC
  out->SetOutputModeMono(true);
  mp3 = new AudioGeneratorMP3();
  mp3->begin(id3, out);
}

void loop() {
  if (mp3->isRunning()) {if (!mp3->loop())mp3->stop();}
}