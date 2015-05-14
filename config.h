/**
*	Configuration file for the One Wire bus
**/

#ifndef CONFIG_OW_H
#define CONFIG_OW_H
    #pragma once
    #define DEBUG // Enable debugging
    #ifdef DEBUG
        #define BAUD_RATE 0x19
    #endif // DEBUG

	// CPU clock frequency
	#define F_CPU	16000000UL

    #define OW_BUS_DDR DDRB
    #define OW_BUS_PIN PINB
    #define OW_BUS_PORT PORTB
    #define OW_BUS_PIN_MASK	_BV(1)
#endif
