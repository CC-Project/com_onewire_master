/*
 */

#include "../code_polynomials/config_polynomials.h"
#include "../code_polynomials/src/poly.h"
#include "config.h"
#include "src/onewire.h"
#include "../lib_data/data.h"
#include "../lib_uart/uart.h"
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <stdio.h>
const uint16_t syndrome[N+1] PROGMEM = { 0, 1, 2, 4, 3, 7, 5, 6 };
Poly generator;

void main(void)
{
	poly_init_generator();
	Poly data = data_generate(K);
//    uint8_t str[10];
//    uart_init(0x19);
//    sprintf(str, "%d", freeRam());
//    uart_tx_str(str);
	//data_set(0, 1, data);
	//data_set(2, 1, data);
    bus_low();
    bus_release();
    Poly encoded = poly_encode(data);
    bus_low();
    bus_release();
    //while(1)
    //{
        //for(uint8_t i = 0; i < N; i++){
            //ow_write_bit(data_get(i,encoded));
			//_delay_us(50);
		//}
        //_delay_ms(5000);
    //}
}
