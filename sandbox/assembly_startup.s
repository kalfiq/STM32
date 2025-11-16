.syntax unified
.cpu cortex-m7
.fpu fpv5-d16
.thumb

.global g_pfnVectors

.word _sdata                    /* Start address for data section - value defined in linker script */
.word _edata                    /* End address for data section - value defined in linker script */

.word _sbss                     /* Start address for bss section - value defined in linker script */
.word _ebss                     /* End address for bss section - value defined in linker script */

.section .text.Reset_Handler    /* Put Reset_Handler into its own named section in .text */
.weak Reset_Handler             /* Allow for overridng with custom implementation */
.type Reset_Handler, %function  /* Define this symbol as a function */

Reset_Handler:
    ldr sp, =_estack

    ldr r0, =_sdata
    ldr r1, =_edata
    ldr r2, =_sidata

.section .text.Default_Handler,"ax",%progbits
.size Default_Handler, .-Default_Handler

Default_Handler:
Infinite_Loop:
    b Infinite_Loop

.section .isr_vector,"a",%progbits /* Allocate (denoted by the "a") program data (%progbits) in memory */
.type g_pfnVectors, %object        /* Define this symbol as an object */
.size g_pfnVectors, .-g_pfnVectors

g_pfnVectors:
    .word _estack                  /* Defined in the linker script */
    .word Reset_Handler
