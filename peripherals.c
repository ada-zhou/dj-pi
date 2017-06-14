#include "peripherals.h"
#include "mcp3008.h"
#include "printf.h"
#include "gpio.h"
#include "gpioextra.h"

#define VOLUME 0
#define SPEED_ONE 1
#define SPEED_TWO 2
#define CROSS_FADE 3

#define PLAY_BUTT_ONE GPIO_PIN20
#define PLAY_BUTT_TWO GPIO_PIN21
#define ESCAPE_BUTT GPIO_PIN16



void peripherals_init(){
	mcp3008_init();

	gpio_set_input(PLAY_BUTT_ONE);
	gpio_set_pullup(PLAY_BUTT_ONE);
    
    gpio_set_input(PLAY_BUTT_TWO);
    gpio_set_pullup(PLAY_BUTT_TWO);
    
    gpio_set_input(ESCAPE_BUTT);
    gpio_set_pullup(ESCAPE_BUTT);


}

unsigned int buttonPressed(int button) {
	return gpio_read(button);

}



int getFade(){
	int fade = ((double)mcp3008_read(CROSS_FADE)/1024.0) * 100;
	return fade;

}

int getVolume(){

	double volume = (double)mcp3008_read(VOLUME);
	int adjusted = (int)((6.0*volume/1024.0));
	
    if (adjusted == 0) {
        return 1;
    } else if (adjusted == 1) {
        return 2;
    } else if (adjusted == 2) {
        return 4;
    } else if (adjusted == 3) {
        return 8;
    } else if (adjusted == 4) {
        return 16;
    }
    return 32;

}

int getSpeed(int channel) {
	double speed = (double)mcp3008_read(channel);
	int adjusted = (int)((speed/(double)1024)*10)+1;
	return adjusted;


}

