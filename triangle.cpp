#include "everything.h"

int main(int argc, char* argv[]) {
  float phase = 0;
  
  int harmonicCount = 20;
  

  for (float note = 127; note > 0; note -= 0.001) 
  {
    
    float frequency = mtof(note);

    float traingleSample = 0;

    for (int i = 1; i <= harmonicCount; i++) 
    {
      if(i%2==1)
      traingleSample += pow(-1,(i - 1)/2) * sin(phase * i) / pow(i,2);
    }
    traingleSample = (8 / pow(pi,2)) * traingleSample;

    mono(traingleSample);

    phase += 2 * pi * frequency / SAMPLE_RATE;
    if (phase > 2 * pi)
      phase -= 2 * pi;
  }
}
