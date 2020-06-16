#ifndef COSMOPOLITAN_LIBC_SYSV_CONSTS_EXIT_H_
#define COSMOPOLITAN_LIBC_SYSV_CONSTS_EXIT_H_
#include "libc/runtime/symbolic.h"

#define EXIT_FAILURE SYMBOLIC(EXIT_FAILURE)
#define EXIT_SUCCESS SYMBOLIC(EXIT_SUCCESS)

#if !(__ASSEMBLER__ + __LINKER__ + 0)
COSMOPOLITAN_C_START_

hidden extern const long EXIT_FAILURE;
hidden extern const long EXIT_SUCCESS;

COSMOPOLITAN_C_END_
#endif /* !(__ASSEMBLER__ + __LINKER__ + 0) */
#endif /* COSMOPOLITAN_LIBC_SYSV_CONSTS_EXIT_H_ */