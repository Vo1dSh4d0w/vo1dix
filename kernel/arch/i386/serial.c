#include "serial.h"
#include "bda.h"
#include <stdio.h>
#include <sys/io.h>

int serial_init() {
    outb(0, bios_data->com1 + SERIAL_INT_ENABLE_REGISTER);
    outb(SERIAL_DLAB, bios_data->com1 + SERIAL_LINE_CONTROL_REGISTER);
    outb(12, bios_data->com1 + SERIAL_BAUD_RATE_LSB);
    outb(0, bios_data->com1 + SERIAL_BAUD_RATE_MSB);
    outb(SERIAL_DATA(3) | SERIAL_PARITY_NONE | SERIAL_STOP(0), bios_data->com1 + SERIAL_LINE_CONTROL_REGISTER);
    outb(SERIAL_MODEM_LOOPBACK, bios_data->com1 + SERIAL_MODEM_CONTROL_REGISTER);
    outb(0xAE, bios_data->com1);
    
    if (inb(bios_data->com1) != 0xAE) {
        return 1;
    }
    
    outb(0, bios_data->com1 + SERIAL_MODEM_CONTROL_REGISTER);
    return 0;
}

void serial_write(char c) {
    while (!(inb(bios_data->com1 + SERIAL_LINE_STATUS_REGISTER) & SERIAL_THRE));
    
    outb(c, bios_data->com1);
}

void __serial_write(__attribute__((unused)) FILE *file, const char *restrict str, size_t len) {
    size_t idx;
    for (idx = 0; idx < len; idx++) {
        serial_write(str[idx]);
    }
}

FILE *serial_out = &(FILE) {
    .device = 0,
    .write = __serial_write
};