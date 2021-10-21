/**
 * @file dap-core-config.h
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

#ifndef DAP_CORE_CONFIG_H
#define DAP_CORE_CONFIG_H

/* Set to 1 if a reset pin is available on the target */
#define DAP_CORE_TARGET_RESET_ENABLED			1

/* Set to 1 to include SWD functionality */
#define DAP_CORE_SWD_ENABLED				1

/* Set to 1 to include JTAG functionality */
#define DAP_CORE_JTAG_ENABLED				1

#if DAP_CORE_JTAG_ENABLED
#define DAP_CORE_JTAG_DEV_CNT				1
#endif /* DAP_CORE_JTAG_ENABLED */

/// Maximum Package Size for Command and Response data.
/// This configuration settings is used to optimize the communication performance with the
/// debugger and depends on the USB peripheral. Typical vales are 64 for Full-speed USB HID or WinUSB,
/// 1024 for High-speed USB HID and 512 for High-speed USB WinUSB.
#define DAP_CORE_PACKET_SIZE         64U            ///< Specifies Packet Size in bytes.

/// Maximum Package Buffers for Command and Response data.
/// This configuration settings is used to optimize the communication performance with the
/// debugger and depends on the USB peripheral. For devices with limited RAM or USB buffer the
/// setting can be reduced (valid range is 1 .. 255).
#define DAP_CORE_PACKET_COUNT        8U              ///< Specifies number of packets buffered.

/// Clock frequency of the Test Domain Timer. Timer value is returned with \ref TIMESTAMP_GET.
#define DAP_CORE_TIMESTAMP_CLOCK         100000000U      ///< Timestamp clock in Hz (0 = timestamps not supported).

/// Default communication speed on the Debug Access Port for SWD and JTAG mode.
/// Used to initialize the default SWD/JTAG clock frequency.
/// The command \ref DAP_SWJ_Clock can be used to overwrite this default setting.
#define DAP_CORE_DEFAULT_SWJ_CLOCK   8000000U        ///< Default SWD/JTAG clock frequency in Hz.

/// Number of processor cycles for I/O Port write operations.
/// This value is used to calculate the SWD/JTAG clock speed that is generated with I/O
/// Port write operations in the Debug Unit by a Cortex-M MCU. Most Cortex-M processors
/// require 2 processor cycles for a I/O Port Write operation.  If the Debug Unit uses
/// a Cortex-M0+ processor with high-speed peripheral I/O only 1 processor cycle might be
/// required.
#define DAP_CORE_IO_PORT_WRITE_CYCLES    2U              ///< I/O Cycles: 2=default, 1=Cortex-M0+ fast I/0.

/// Default communication mode on the Debug Access Port.
/// Used for the command \ref DAP_Connect when Port Default mode is selected.
#define DAP_CORE_DEFAULT_PORT        1U              ///< Default JTAG/SWJ Port Mode: 1 = SWD, 2 = JTAG.

#endif /* DAP_CORE_CONFIG_H */