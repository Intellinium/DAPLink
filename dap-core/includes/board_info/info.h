/**
 * @file info.h
 * @author Giuliano FRANCHETTO
 * @date 20 October 2021
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

#ifndef DAP_CORE_INFO_H
#define DAP_CORE_INFO_H

#include <string.h>
#include <stdint.h>

struct hic_data {
	/**
	 * Gets the unique ID of the HIC.
	 * @param buffer[out] The buffer to fill with the ID
	 * @return length of the unique id
	 */
	size_t (*get_unique_id)(char *buffer);

	/**
	 * Gets the version the HIC.
	 * @param buffer[out] The buffer to fill with the version
	 * @return length of the unique id
	 */
	size_t (*get_version)(char *buffer);
};

/**
 * This variable SHALL be set by the HIC implementation.
 * If not, there will be linkage error when building the dap-core library
 */
extern struct hic_data hic;

static inline size_t hic_get_unique_id(char *buffer)
{
	return hic.get_unique_id(buffer);
}

static inline size_t hic_get_version(char *buffer)
{
	return hic.get_version(buffer);
}
#endif /* DAP_CORE_INFO_H */