#ifndef _KERNEL_ARCH_I386_BDA_H
#define _KERNEL_ARCH_I386_BDA_H

#include <stdint.h>

const struct bios_data {
  uint16_t com1;
  uint16_t com2;
  uint16_t com3;
  uint16_t com4;
  
  uint16_t lpt1;
  uint16_t lpt2;
  uint16_t lpt3;
  /*
  uint16_t ebda_addr;
  uint16_t hw_flags;
  uint16_t ebda_offset;
  uint16_t kb_state_flags;
  uint8_t kb_buffer[32];
  
  uint8_t display_mode;
  uint16_t text_mode_cols;
  uint16_t video_base_port;
  
  uint16_t irq0_ticks;
  uint8_t hdd_count;
  
  uint16_t kb_buffer_start;
  uint16_t kb_buffer_end;
  */
} __attribute__((packed))
*bios_data = (struct bios_data *)0x400;

#endif