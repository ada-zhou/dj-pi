# hashbron-ada-zhou-project

WELCOME TO DJ PI USER MANUAL:

This project uses PWM to output sound from the Raspberry Pi. We have pre-coded tracks that the user can play and use our custom-built turntable to DJ. Two tracks can be playes simultaneously and the user can adjust the volume, the crossfade between the two tracks, and the play back spped of each track. Tracks can be found in the songs.h file and new tracks can be added. The two tracks are passed into turntable_run() in the main file.

We have included a lot of code that is not used in the actual execution of the program. Our sine function (sine.c) was used to generate our sine wave array that audio.c uses. Generating these values in real time, however, proved too time-costly for the sampling rate we wanted, so we hard coded the array in instead. Our peripheral functions (peripherals.c) are not called, and instead the body of the function is executed directly in turntable.c. This was again due to our need to ensure the function was speedy so as to not offst the audio samples. We also unrolled many of these functions that could have been executed with costlier loops to save time.

Finally, our program executes with a lot of warnings about unused variables. These are all of the songs we have hard code in for users to play with. As the main function (and the turn table) can only play two tracks at a time, all but two of these song structs will be unsed variables. (With more time we would have liked to create a GUI with our graphics library to allow users to pick a track from a track list).

We hope you enjoy DJ Pi!
