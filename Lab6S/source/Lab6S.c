#include "board.h"
#include "fsl_debug_console.h"
#include "fsl_gpio.h"
#include "pin_mux.h"
#include <stdbool.h>
#include "fsl_power.h"

#define APP_BOARD_TEST_LED_PORT   1U
#define APP_BOARD_TEST_LED_PIN    7U
#define APP_SW_PORT               BOARD_SW1_GPIO_PORT
#define APP_SW_PIN                BOARD_SW1_GPIO_PIN

volatile uint32_t g_systickCounter;

void SysTick_Handler(void){
	if (g_systickCounter != 0U){
		g_systickCounter--;
	}
}

void SysTick_DelayTicks(uint32_t n){
    g_systickCounter = n;
    while (g_systickCounter != 0U){
    }
}

int main(void) {
    uint32_t port_state = 0;

    gpio_pin_config_t led_config = {
    		kGPIO_DigitalOutput,
        0,
    };

    POWER_SetBodVbatLevel(kPOWER_BodVbatLevel1650mv, kPOWER_BodHystLevel50mv, false);
    CLOCK_AttachClk(BOARD_DEBUG_UART_CLK_ATTACH);
    CLOCK_EnableClock(kCLOCK_Gpio0);
    CLOCK_EnableClock(kCLOCK_Gpio1);

    BOARD_InitBootPins();
    BOARD_BootClockPLL150M();
    BOARD_InitDebugConsole();

    GPIO_PortInit(GPIO, APP_BOARD_TEST_LED_PORT);
    GPIO_PortInit(GPIO, APP_SW_PORT);
    GPIO_PinInit(GPIO, APP_BOARD_TEST_LED_PORT, APP_BOARD_TEST_LED_PIN, &led_config);
    GPIO_PinWrite(GPIO, APP_BOARD_TEST_LED_PORT, APP_BOARD_TEST_LED_PIN, 1);

	GPIO_PortMaskedSet(GPIO, APP_BOARD_TEST_LED_PORT, 0x0000FFFF);
	GPIO_PortMaskedWrite(GPIO, APP_BOARD_TEST_LED_PORT, 0xFFFFFFFF);
	port_state = GPIO_PortRead(GPIO, APP_BOARD_TEST_LED_PORT);
	PRINTF("\r\n Standard port read: %x\r\n", port_state);
	port_state = GPIO_PortMaskedRead(GPIO, APP_BOARD_TEST_LED_PORT);
	PRINTF("\r\n Masked port read: %x\r\n", port_state);

	if (SysTick_Config(SystemCoreClock / 1000U)) {
		while (1) {
		}
	}

	while (1) {
		port_state = GPIO_PortRead(GPIO, APP_SW_PORT);
		if (!(port_state & (1 << APP_SW_PIN))) {
			PRINTF("\r\n Port state: %x\r\n", port_state);
			GPIO_PortToggle(GPIO, APP_BOARD_TEST_LED_PORT, 1U << APP_BOARD_TEST_LED_PIN);
		}
			SysTick_DelayTicks(1000U);
	}
	return 0;
}
