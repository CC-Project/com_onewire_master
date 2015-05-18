/**
*	Functions definitions for the One Wire bus
**/

#ifndef ONEWIRE_H_
#define ONEWIRE_H_
	#include "../config.h"

	#ifdef __AVR__
        #include <avr/io.h>
        #include <util/delay.h>
    #else
        #include <inttypes.h>
    #endif // __AVR__

	#define LOW 0
	#define HIGH 1
    #define T 60 // Standard time slot


	/*	Utility functions	*/
	void bus_low(void);
	void bus_release(void);
	uint8_t bus_read(void);

	/*	One Wire functions	*/
	// Resets the bus. Returns 1 if a device was found, 0 otherwise
	uint8_t	ow_reset(void);

	void	ow_write_bit(uint8_t bit);
	uint8_t	ow_read_bit(void);
	void	ow_write_byte(uint8_t byte);
	uint8_t	ow_read_byte(void);

	void	ow_skip_rom(void);
	void	ow_read_rom(void);

#endif
