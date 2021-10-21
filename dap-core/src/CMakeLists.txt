add_subdirectory(board_info)
add_subdirectory(cmsis-dap)

if (NOT TARGET_MCU_CORTEX_A)
    target_sources(dap-core PRIVATE
            swd_host.c
            )
endif ()
