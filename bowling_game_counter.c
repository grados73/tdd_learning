#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAX_NUMBER_OF_FRAME 10

typedef uint32_t score_t;
typedef uint32_t number_of_frame_t;
typedef uint32_t number_of_rolls_t;

score_t number_of_points = 0;
number_of_frame_t number_of_frame = 1; 
number_of_rolls_t number_of_rolls = 0;


void roll(int);     // is called each time the player rolls a ball. The argument is the number of pins knocked down
int score();        // returns the total score for that game

int main(void)
{
    printf("Welcome in bowling score program.\r\n");
    printf("Give number of pins knocked down in each rolls in each frame.\r\n\n");
    //printf("Include a dot ('.') in a sentence to exit:\r\n");
    for(uint8_t i = 0 ; i < MAX_NUMBER_OF_FRAME ; i++)
    {
        uint32_t temp_number_knoceked = 0;
        // first rolls
        printf("Give number of pins knocked down in %d frame and %d rolls: \r\n", number_of_frame, number_of_rolls);
        // gets
        number_of_rolls++;

        // second rolls
        printf("Give number of pins knocked down in %d frame and %d rolls: \r\n", number_of_frame, number_of_rolls);
        //gets
        printf("\r\n");
        number_of_rolls--;
        number_of_frame++;
    }
    return 0;
}

void roll(int)
{

}

int score()
{

}