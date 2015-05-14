/*
 * Main file. It is assumed only one DS18B20 is connected to the bus.
 * See datasheet to connect the sensors.
 * The data pin can be changed in the config.h file
 * No crc verification is made.
 */

#include "config.h"
#include "src/onewire.h"
//#ifdef DEBUG
//    #include "../../lib_uart/uart.h"
//#endif
#include <stdio.h>

int main(void)
{
	uint8_t data[9] = {0};

	#ifdef DEBUG
		uart_init(BAUD_RATE);
	#endif

	for(;;){
		uint8_t i; // Counter

		// Init and select device
		if(ow_reset())
            ow_skip_rom();


		// Start the temp conversion
		ow_write_byte(0x44);

		// Select device
		if(ow_reset())
            ow_skip_rom();

		// Read Scratchpad
		ow_write_byte(0xbe);

		// Read the reply
		for (i = 0; i < 10; i++)
		{
			data[i] = ow_read_byte();
		}

		// Conversion
		i = ( data[1] << 4 ) | ( data[0] >> 4);

		// Prints out the result.
		#ifdef DEBUG
			sprintf(data, "%d", i);
			uart_tx_str(data);
			uart_newline();
		#endif

		// Wait a little.
		_delay_ms(1000);
	}
	return 1;
}
