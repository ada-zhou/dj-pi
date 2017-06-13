#include "mcp3008.h"

#include "gpio.h"

void peripherals_init();
unsigned int buttonPressed(int button);
int getFade();
int getVolume();
int getSpeed(int channel);
