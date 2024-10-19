#include <cpu.h>

#define Z80_VECTOR_BASE $8000

// whole RST table for reference
#define RST_00_ADDR     Z80_VECTOR_BASE+$01
#define RST_08_ADDR     Z80_VECTOR_BASE+$05
#define RST_10_ADDR     Z80_VECTOR_BASE+$09
#define RST_18_ADDR     Z80_VECTOR_BASE+$0D
#define RST_20_ADDR     Z80_VECTOR_BASE+$11
#define RST_28_ADDR     Z80_VECTOR_BASE+$15
#define RST_30_ADDR     Z80_VECTOR_BASE+$19
#define RST_38_ADDR     Z80_VECTOR_BASE+$1D

#define INT_INT0_ADDR   Z80_VECTOR_BASE+$1D
#define INT_NMI_ADDR    Z80_VECTOR_BASE+$21

void my_rst_20_function(void);

int main(void)
{
  uint16_t volatile * const interrupt_vector = (uint16_t *) RST_20_ADDR;
  * interrupt_vector = (uint16_t) my_rst_20_function;

  return 0;
}

void my_rst_20_function(void)
{
    return;
}
