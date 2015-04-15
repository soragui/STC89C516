#ifndef EEPROM_H
#define EEPROM_H

typedef unsigned char uchar;
typedef unsigned int  uint;

void start();
void stop();
void checkACK();
void sendACK(bit);
void send_byte(uchar);
uchar receive_byte();
void write_word(uchar device_add, uchar word_add, uchar date);
uchar read_word(uchar device_add, uchar word_add);

#endif