/**
 * @file os_gpio.h
 * @author Giuliano FRANCHETTO
 * @date 21 October 2021
 * 
 * @copyright @verbatim
 * Intellinium SAS, 2014-present
 * All Rights Reserved.
 *
 * NOTICE:  All information contained herein is, and remains
 * the property of Intellinium SAS and its suppliers,
 * if any.  The intellectual and technical concepts contained
 * herein are proprietary to Intellinium SAS
 * and its suppliers and may be covered by French and Foreign Patents,
 * patents in process, and are protected by trade secret or copyright law.
 * Dissemination of this information or reproduction of this material
 * is strictly forbidden unless prior written permission is obtained
 * from Intellinium SAS.
 * @endverbatim
 * 
 * @brief 
 **/

#ifndef OS_GPIO_H
#define OS_GPIO_H

#include <stdint.h>

enum os_gpio_direction {
	OS_GPIO_OUTPUT,
	OS_GPIO_INPUT,
	OS_GPIO_DISCONNECTED
};

#define OS_GPIO_PULL_UP                                (1 << 0)
#define OS_GPIO_PULL_DOWN                        (1 << 1)
#define OS_GPIO_HIGH_DRIVE                        (1 << 2)

struct os_gpio_cfg {
	enum os_gpio_direction direction;
	uint32_t flags;
};

struct os_gpio_pin {
	uint8_t port;
	uint8_t pin;
};

struct os_gpio_config {
#if defined(DAP_CORE_SWD_ENABLED)
	struct os_gpio_pin swd_io;
	struct os_gpio_pin swd_clk;
#endif

#if defined(DAP_CORE_TARGET_RESET_ENABLED)
	struct os_gpio_pin reset;
#endif

#if defined(DAP_CORE_JTAG_ENABLED)
	struct os_gpio_pin tdi;
	struct os_gpio_pin tdo;
	struct os_gpio_pin trst;
#endif

	int (*configure)(struct os_gpio_pin pin, struct os_gpio_cfg *config);

	int (*set)(struct os_gpio_pin pin, uint8_t level);

	int (*get)(struct os_gpio_pin pin);
};

extern struct os_gpio_config gpio_config;

__STATIC_INLINE void sw_dp_swdio_enable(void)
{
#if defined(DAP_CORE_SWD_ENABLED)
	struct os_gpio_cfg cfg = {
		.direction = OS_GPIO_OUTPUT
	};
	gpio_config.configure(gpio_config.swd_io, &cfg);
#endif
}

__STATIC_INLINE void sw_dp_swdio_disable(void)
{
#if defined(DAP_CORE_SWD_ENABLED)
	struct os_gpio_cfg cfg = {
		.direction = OS_GPIO_INPUT
	};
	gpio_config.configure(gpio_config.swd_io, &cfg);
#endif
}

__STATIC_INLINE void sw_dp_swdio_set(void)
{
#if defined(DAP_CORE_SWD_ENABLED)
	gpio_config.set(gpio_config.swd_io, 1);
#endif
}

__STATIC_INLINE int sw_dp_swdio_get(void)
{
#if defined(DAP_CORE_SWD_ENABLED)
	return gpio_config.get(gpio_config.swd_io);
#else
	return 0;
#endif
}

__STATIC_INLINE void sw_dp_swdio_clear(void)
{
#if defined(DAP_CORE_SWD_ENABLED)
	gpio_config.set(gpio_config.swd_io, 0);
#endif
}

__STATIC_INLINE void sw_dp_swdclk_set(void)
{
#if defined(DAP_CORE_SWD_ENABLED)
	gpio_config.set(gpio_config.swd_clk, 1);
#endif
}

__STATIC_INLINE int sw_dp_swdclk_get(void)
{
#if defined(DAP_CORE_SWD_ENABLED)
	return gpio_config.get(gpio_config.swd_clk);
#else
	return 0;
#endif
}

__STATIC_INLINE void sw_dp_swdclk_clear(void)
{
#if defined(DAP_CORE_SWD_ENABLED)
	gpio_config.set(gpio_config.swd_clk, 0);
#endif
}

/* TDI pin */
__STATIC_INLINE void jtag_tdi_set(uint8_t val)
{
#if defined(DAP_CORE_JTAG_ENABLED)
	gpio_config.set(gpio_config.tdi, val);
#endif
}

__STATIC_INLINE uint8_t jtag_tdi_get(void)
{
#if defined(DAP_CORE_JTAG_ENABLED)
	return gpio_config.get(gpio_config.tdi);
#else
	return 0;
#endif
}

/* TDO pin */
__STATIC_INLINE uint8_t jtag_tdo_get(void)
{
#if defined(DAP_CORE_JTAG_ENABLED)
	return gpio_config.get(gpio_config.tdo);
#else
	return 0;
#endif
}

/* TRST pin */
__STATIC_INLINE void jtag_trst_set(uint8_t val)
{
#if defined(DAP_CORE_JTAG_ENABLED)
	gpio_config.set(gpio_config.trst, val);
#endif
}

__STATIC_INLINE uint8_t jtag_trst_get(void)
{
#if defined(DAP_CORE_JTAG_ENABLED)
	return gpio_config.get(gpio_config.trst);
#else
	return 0;
#endif
}

/* nRST pin */
__STATIC_INLINE void target_rst_set(uint8_t val)
{
#if defined(DAP_CORE_TARGET_RESET_ENABLED)
	gpio_config.set(gpio_config.reset, val);
#endif
}

__STATIC_INLINE uint8_t target_rdst_get(void)
{
#if defined(DAP_CORE_TARGET_RESET_ENABLED)
	return gpio_config.get(gpio_config.reset);
#else
	return 0;
#endif
}

__STATIC_INLINE void swd_port_setup(void)
{
#if defined(DAP_CORE_SWD_ENABLED)
	struct os_gpio_cfg cfg = {
		.direction = OS_GPIO_OUTPUT,
	};
	gpio_config.configure(gpio_config.swd_clk, &cfg);
	gpio_config.configure(gpio_config.swd_io, &cfg);
	gpio_config.set(gpio_config.swd_io, 1);
#endif
}

__STATIC_INLINE void jtag_port_setup(void)
{
#if defined(DAP_CORE_JTAG_ENABLED)
	/* TODO */
#endif
}

__STATIC_INLINE void swd_jtag_port_off(void)
{
#if defined(DAP_CORE_SWD_ENABLED)
	struct os_gpio_cfg cfg = {
		.direction = OS_GPIO_INPUT,
	};
	gpio_config.configure(gpio_config.swd_clk, &cfg);
	gpio_config.configure(gpio_config.swd_io, &cfg);
#endif

#if defined(DAP_CORE_JTAG_ENABLED)
	 /* TODO */
#endif
}

#endif /* OS_GPIO_H */