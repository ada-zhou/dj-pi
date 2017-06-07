#include "peripherals.h"
#include "mcp3008.h"
#include "printf.h"

#define VOLUME 0

int getVolume(){
	mcp3008_init();
	double volume = (double)mcp3008_read(VOLUME);
	int adjusted = (int)((volume/(double)1024)*6);
	// printf("Volume is: %d\n", volume);
	// printf("Volume from one to six: %d\n", adjusted);
	int returned = 1;
	for (int i = 0; i < adjusted; i++){
		returned *= 2;
	}
	return returned;
}

int getSpeed(int channel) {
	mcp3008_init();
	double speed = (double)mcp3008_read(channel);
	int adjusted = (int)((speed/(double)1024)*10)+1;
	printf("Speed is %d", adjusted);
	return adjusted;


}