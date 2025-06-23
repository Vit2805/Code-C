#ifndef UART_H
#define UART_H

#include <stdint.h>

// CommunicationChannel Structure
typedef struct {
    int (*send)(void* channelIstance, const uint8_t* data, size_t length);
    int (*receive)(void* channelInstance, const uint8_t* buffer, size_t bufferLength, size_t*);
    void* instanceData;
}CommunicationChannel;

// Function prototypes for creating RawUartChannel
CommunicationChannel* createRawUartChannel();

// Funtion to free memory allocated for a RawUartChannel
void freeRawUartChannel(CommunicationChannel* CommunicationChannel);

#endif // UART_H
