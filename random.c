#include<stdlib.h>
#include<time.h>
#include"random.h"

void initRandom()
{
    srand(time(NULL));
}

int random(int low, int high)
{
    int number = -1;

    if(low <= high)
    {
        number = (rand() % (high-low+1)) + low;
    }

    return number;
}