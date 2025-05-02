#pragma once
#include <iostream>
#include "Defines.h"

int main()
{
    RS_Initialize("Keagon King", RASTER_WIDTH, RASTER_HEIGHT);
    do {
        
    } while (RS_Update(SCREEN_ARRAY, NUM_PIXELS));

    RS_Shutdown();

    return 0;
}

