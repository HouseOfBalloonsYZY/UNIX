#include "everything.h"

int main(int argc, char* argv[]) {
  float phase = 0;
  
  int harmonicCount = 20;
  

  for (float note = 127; note > 0; note -= 0.001) 
  {
    
    float frequency = mtof(note);

    float sawtoothSample = 0;

    for (int h = 1; h <= harmonicCount; h++) 
    {
      sawtoothSample += sin(phase * h) / h;
    }
    sawtoothSample /= 2 * harmonicCount;

    mono(sawtoothSample);

    phase += 2 * pi * frequency / SAMPLE_RATE;
    if (phase > 2 * pi)
      phase -= 2 * pi;
  }
}
