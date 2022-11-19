#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NUMBER_OF_FRAME 10
#define ASCII_TO_UINT_CONST 48
#define STRIKE_VALUE 10

typedef uint32_t score_t;
typedef uint32_t number_of_frame_t;
typedef uint32_t number_of_rolls_t;
typedef uint32_t first_rolls_pins_uint_t;
typedef uint32_t second_rolls_pins_uint_t;
typedef uint32_t first_roll_number_t;
typedef bool is_strike_t;
typedef bool is_spare_t;

score_t number_of_points = 0;
number_of_frame_t number_of_frame = 1;
number_of_rolls_t number_of_rolls = 1;
first_roll_number_t first_roll_number = 0;
is_strike_t is_strike = false;
is_strike_t is_strike_again = false;
is_spare_t is_spare = false;

char first_rolls_pins_char[5];
char second_rolls_pins_char[5];

first_rolls_pins_uint_t first_rolls_pins_uint = 0;
second_rolls_pins_uint_t second_rolls_pins_uint = 0;


void roll(int number_of_pins_in_one_roll);     // is called each time the player rolls a ball. The argument is the number of pins knocked down
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

        printf("Give number of pins knocked down in %d frame and %d rolls: ", number_of_frame, number_of_rolls);
        fgets(first_rolls_pins_char, 5, stdin);

        printf("%s", first_rolls_pins_char);
        if(first_rolls_pins_char[0] == '1')
        {
            if (strncmp(first_rolls_pins_char, "10", 2) == 0) // 10 - STRIKE
            {
                first_rolls_pins_uint = 10;
                printf("-Saved number of pins knocked down in first rolls == %d == - STRIKE! \r\n\n", first_rolls_pins_uint);
            }
            else
            {
                first_rolls_pins_uint = 1;
                printf("-Saved number of pins knocked down in first rolls == %d == \r\n", first_rolls_pins_uint);
            }
        }
        else
        {
            first_rolls_pins_uint = (uint32_t)(first_rolls_pins_char[0]) - ASCII_TO_UINT_CONST;
            printf("-Saved number of pins knocked down in first rolls == %d == \r\n", first_rolls_pins_uint);
        }

        roll(first_rolls_pins_uint);

        number_of_rolls++;

        if(first_rolls_pins_uint != STRIKE_VALUE) // if wasn`t strike in first roll
        {
            printf("\r\nGive number of pins knocked down in %d frame and %d rolls: ", number_of_frame, number_of_rolls);
            fgets( second_rolls_pins_char, 5, stdin);
            printf("%s", second_rolls_pins_char);
            if(second_rolls_pins_char[0] == '1')
            {
                if (strncmp(second_rolls_pins_char, "10", 2) == 0) // 10 - SPARE
                {
                    second_rolls_pins_uint = 10;
                }
                else
                {
                    second_rolls_pins_uint = 1;
                }
                printf("-Saved number of pins knocked down in second rolls == %d == ", second_rolls_pins_uint);
            }
            else
            {
                second_rolls_pins_uint = (uint32_t)(second_rolls_pins_char[0]) - ASCII_TO_UINT_CONST;
                printf("-Saved number of pins knocked down in second rolls == %d ==", second_rolls_pins_uint);
            }

            if((first_rolls_pins_uint + second_rolls_pins_uint) >= 10) printf(" - SPARE!\r\n\n");
            else printf("\r\n\n");


            roll(second_rolls_pins_uint);
        }

        number_of_rolls--;
        number_of_frame++;

        // second rolls
    printf("Total score after %d frame: %d\r\n============================================================\r\n\n",  number_of_frame-1, score());

    }
    printf("\r\nTotal score of the game : !!! %d !!!",  score());
    return 0;

}

void roll(int number_of_pins_in_one_roll)
{
    if(number_of_rolls == 1)  // FIRST ROLL
    {
        if(number_of_pins_in_one_roll == 10)  // STRIKE
        {
            if(is_strike)
            {
                number_of_points = number_of_points + 2 * number_of_pins_in_one_roll;
            }
            else if(is_spare)
            {
                number_of_points = number_of_points + 2 * number_of_pins_in_one_roll;
                is_spare = false;
            }
            else number_of_points = number_of_points + number_of_pins_in_one_roll;
            is_strike_again = true;
            is_strike = true;
        }
        else
        {
            first_roll_number = number_of_pins_in_one_roll;
            if(is_strike)
            {
                number_of_points = number_of_points + 2 * number_of_pins_in_one_roll;
            }
            else if(is_spare)
            {
                number_of_points = number_of_points + 2 * number_of_pins_in_one_roll;
                is_spare = false;
            }
            else number_of_points = number_of_points + number_of_pins_in_one_roll;
            is_strike_again = false;
        }
    }

    else    // SECOND ROLL
    {
        if((number_of_pins_in_one_roll + first_roll_number) >= 10)
        {
            is_spare = true;
        }
        if(is_strike)
        {
            number_of_points = number_of_points + 2 * number_of_pins_in_one_roll;
            if(!is_strike_again) is_strike = false;
        }
        else number_of_points = number_of_points + number_of_pins_in_one_roll;
    }






}

int score()
{
    return number_of_points;
}
