/*
 * Main file. It is assumed only one DS18B20 is connected to the bus.
 * See datasheet to connect the sensors.
 * The data pin can be changed in the config.h file
 * No crc verification is made.
 */

#include "config.h"
#include "src/onewire.h"
#include <stdio.h>

void main_master();

void main_master()
{
    /*
    uint32_t nb_data = 8;
    uint8_t data = 9;

    while(1)
    {
        for(uint8_t i = 0; i < 32; i++)
            ow_write_bit((nb_data & _BV(i)) ? 1 : 0);
        _delay_ms(2000);
    }


//    for(uint32_t i = 0; i < nb_data; i++)
//        ow_write_bit((data & _BV(i)) ? 1 : 0);

    for(;;) {}
    */
}
