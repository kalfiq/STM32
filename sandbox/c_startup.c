extern int main(void);

extern unsigned int _sdata;
extern unsigned int _sidata;
extern unsigned int _edata;
extern unsigned int _sbss;
extern unsigned int _ebss;

extern unsigned int _estack;

/* Copy data from flash into RAM */
static void copy_data(void)
{
  unsigned int* src_data_ptr = &_sidata;
  unsigned int* dst_data_ptr = &_sdata;

  while (dst_data_ptr < &_edata)
  {
    *dst_data_ptr++ = *src_data_ptr++;
  }
}

/* Initialize all the bss data to 0 */
static void clear_bss(void)
{
  unsigned int* bss_ptr = &_sbss;

  while (bss_ptr < &_ebss)
  {
    *bss_ptr++ = 0;
  }
}

void Reset_Handler(void)
{
  copy_data();
  clear_bss();
  main();

  while(1);
}

void Default_Handler(void)
{
  while(1);
}

typedef void (*isr_t)(void);

#define IVT_ARRAY_SIZE (48U)

__attribute((used, section(".isr_vector")))
static const isr_t ivr[IVT_ARRAY_SIZE] =
{
  (isr_t)&_estack,
  Reset_Handler,
  0,                          /* Non-maskable interrupt */
  Default_Handler

  /* Incomplete table of vectors */
};
