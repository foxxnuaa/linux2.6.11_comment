/* 
 * Copyright (C) 2002 Jeff Dike (jdike@karaya.com)
 * Licensed under the GPL
 */

#ifndef __UM_PROCESSOR_I386_H
#define __UM_PROCESSOR_I386_H

extern int host_has_xmm;
extern int host_has_cmov;

struct arch_thread {
	unsigned long debugregs[8];
	int debugregs_seq;
};

#define INIT_ARCH_THREAD { .debugregs  		= { [ 0 ... 7 ] = 0 }, \
                           .debugregs_seq	= 0 }

#include "asm/arch/user.h"

/*
 * Default implementation of macro that returns current
 * instruction pointer ("program counter"). Stolen
 * from asm-i386/processor.h
 */
#define current_text_addr() \
	({ void *pc; __asm__("movl $1f,%0\n1:":"=g" (pc)); pc; })

#define ARCH_IS_STACKGROW(address) \
       (address + 32 >= UPT_SP(&current->thread.regs.regs))

#include "asm/processor-generic.h"

#endif

/*
 * Overrides for Emacs so that we follow Linus's tabbing style.
 * Emacs will notice this stuff at the end of the file and automatically
 * adjust the settings for this buffer only.  This must remain at the end
 * of the file.
 * ---------------------------------------------------------------------------
 * Local variables:
 * c-file-style: "linux"
 * End:
 */
