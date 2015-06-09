/*
 */

#include "../code_polynomials/config_polynomials.h"
#include "../code_polynomials/src/poly.h"
#include "config.h"
#include "src/onewire.h"
#include "../lib_data/data.h"
#include "../lib_uart/uart.h"
#include <avr/interrupt.h>
#include <stdio.h>

Poly generator;

void main(void)
{
	Poly data = data_generate(K);
	data_set(0, 1, data);
	data_set(2, 1, data);
	 
	Poly encoded = poly_encode(data);
	
    while(1)
    {
        for(uint8_t i = 0; i < N; i++){
            ow_write_bit(data_get(i,encoded));
			_delay_us(50);
		}
        _delay_ms(5000);
    }
}
