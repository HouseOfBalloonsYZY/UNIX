#include "everything.h"

int main(int argc, char* argv[]) {
  float phase = 0;
  
  int harmonicCount = 20;
  

  for (float note = 127; note > 0; note -= 0.001) 
  {
    
    float frequency = mtof(note);

    float squareSample = 0;

    for (int i = 1; i <= harmonicCount; i++) 
    {
      if(i%2==1)
      squareSample += sin(phase * i) / i;
    }
    squareSample = (4 / pi) * squareSample;

    mono(squareSample);

    phase += 2 * pi * frequency / SAMPLE_RATE;
    if (phase > 2 * pi)
      phase -= 2 * pi;
  }
}
