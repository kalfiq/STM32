.syntax unified
.cpu cortex-m7
.fpu fpv5-d16
.thumb

.global g_pfnVectors

.word _sdata                    /* Start address for data section - value defined in linker script */
.word _edata                    /* End address for data section - value defined in linker script */

.word _sbss                     /* Start address for bss section - value defined in linker script */
.word _ebss                     /* End address for bss section - value defined in linker script */

.section .text.reset_handler    /* Put reset_handler into its own named section in .text */
.weak reset_handler             /* Allow for overridng with custom implementation */
.type reset_handler, %function  /* Define this symbol as a function */

.extern main

/* There could be multiple sources of reset.
 * Check chapter 5.1.1 of the user manual for more info */
reset_handler:
  ldr sp, =_estack

  /* Copy variables from FLASH to RAM */
  ldr r0, =_sdata
  ldr r1, =_edata
  ldr r2, =_sidata
  movs r3, #0
  bl loop_copy_data_init

  /* Initialize global and static variables with zero */
  ldr r0, =_sbss
  ldr r1, =_ebss
  movs r2, #0
  bl loop_fill_zero_bss

  bl system_init

  bl  main
  bx  lr

.size reset_handler, .-reset_handler

.section .text.copy_data_init
.type copy_data_init, %function

.section .text.loop_copy_data_init
.type loop_copy_data_init, %function

copy_data_init:
  ldr r4, [r2, r3]
  str r4, [r0, r3]
  adds r3, r3, #4
  adds r0, r0, r3

loop_copy_data_init:
  cmp r0, r1
  bcc copy_data_init

  bx lr

.section .text.fill_zero_bss
.type fill_zero_bss, %function

.section .text.loop_fill_zero_bss
.type loop_fill_zero_bss, %function

fill_zero_bss:
  str  r2, [r0]
  adds r0, r0, #4

loop_fill_zero_bss:
  cmp r0, r1
  bcc fill_zero_bss

  bx lr

.section .text.default_handler,"ax",%progbits
default_handler:
infinite_loop:
  b infinite_loop

.size default_handler, .-default_handler

.section .isr_vector,"a",%progbits /* Allocate (denoted by the "a") program data (%progbits) in memory */
.type g_pfnVectors, %object        /* Define this symbol as an object */
.size g_pfnVectors, .-g_pfnVectors

g_pfnVectors:
    .word _estack                  /* Defined in the linker script */
    .word reset_handler
