#ifndef PCF_H
#define PCF_H

void start();
void stop();
void checkACK();
void sendACK(bit);
void send_byte(unsigned char);
unsigned char receive_byte(); 
unsigned char Read_AD(unsigned char);

#endif