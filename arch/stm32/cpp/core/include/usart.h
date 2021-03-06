/*
	usart.h - Header to provide access to USART functionality.
	
*/


#ifndef USART_H
#define USART_H


#include <common.h>
#include <gpio.h>
#include <rcc.h>

#include <functional>


enum USART_devices {
	USART_1,
	USART_2,
	USART_3,
	USART_4,
	USART_5,
	USART_6
};


struct USART_device {
	bool active = false;
	USART_TypeDef* regs;
	GPIO_ports tx_port;
	uint8_t tx_pin;
	uint8_t tx_af;
	GPIO_ports rx_port;
	uint8_t rx_pin;
	uint8_t rx_af;
	uint32_t baudrate;
	RccPeripheral per;
	IRQn_Type irqType;
	std::function<void(char)> callback;
};


class USART {
	static GPIO gpio;
	
public:
	static bool startUart(USART_devices device, GPIO_ports tx_port, uint8_t tx_pin, uint8_t tx_af,
											GPIO_ports rx_port, uint8_t rx_pin, uint8_t rx_af,
											uint32_t baudrate, std::function<void(char)> callback);
	static bool sendUart(USART_devices device, char &ch);
	static bool stopUart(USART_devices device);
};

#endif
