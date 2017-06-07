#include "peripherals.h"

#define VOLUME 0

int getVolume(){
	double volume = mcp3008_read(VOLUME);
	return (int)((volume/(double)1024)*6);
}

int getSpeed(int channel) {
	double speed = mcp3008_read(channel);
	return (int)((speed/(double)1024)*10);


}