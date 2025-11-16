ENTRY(Reset_Handler)

/* Are these values defined in the datasheet? */
_Min_Heap_Size  = 0x200;
_Min_Stack_Size = 0x400;

MEMORY
{
    FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 512K
    RAM   (rwx) : ORIGIN = 0x20000000, LENGTH = 256K
}

_estack = ORIGIN(RAM) + LENGTH(RAM); /* Point to the top of the stack */

SECTIONS
{
    /* Interrupt vectors used for system start-up */

    .text : ALIGN(4)
    {
        *(.isr_vector)
        *(.text*)
    } > FLASH

      /* Store this initial FLASH memory address for copying over later */
      _sidata = LOADADDR(.data);

    /* Stores initialized variables */
    .data : ALIGN(4)
    {
        _sdata = .;
        *(.data*)

        . = ALIGN(4);
        _edata = .;
    } > RAM AT> FLASH

    /* Stores uninitialized variables */
    .bss : ALIGN(4)
    {
        _sbss = .;         /* define a global symbol at bss start */
        *(.bss*)

        . = ALIGN(4);
        _ebss = .;         /* define a global symbol at bss end */
    } > RAM
}
