/**
 * @file os_timing.h
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

#ifndef OS_TIMING_H
#define OS_TIMING_H

#include <stdint.h>

struct os_timing_config {
	uint32_t (*get_timestamp)(void);

	uint32_t (*system_clock)(void);

	void (*wait_ms)(uint32_t time);
};

extern struct os_timing_config timing_config;

__STATIC_INLINE uint32_t timestamp_get(void)
{
	return timing_config.get_timestamp();
}

__STATIC_INLINE uint32_t system_clock_get(void)
{
	return timing_config.system_clock();
}

__STATIC_INLINE void system_wait_ms(uint32_t time)
{
	timing_config.wait_ms(time);
}

#endif /* OS_TIMING_H */