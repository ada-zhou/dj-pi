#include "peripherals.h"
#include "mcp3008.h"
#include "printf.h"
#include "gpio.h"

#define VOLUME 0
#define CROSS_FADE 3

#define PLAY_BUTT GPIO_PIN20

void peripherals_init(){
	mcp3008_init();

	gpio_set_input(PLAY_BUTT);
	gpio_set_pullup(PLAY_BUTT);


}

unsigned int getButtonState(int button) {
	return gpio_read(button);

}

double getFade(){
	double fade = (double)mcp3008_read(CROSS_FADE)/1024.0;
	return fade;

}

int getVolume(){
	//mcp3008_init();
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
	//mcp3008_init();
	double speed = (double)mcp3008_read(channel);
	int adjusted = (int)((speed/(double)1024)*10)+1;
	printf("Speed is %d", adjusted);
	return adjusted;


}

