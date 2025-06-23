#include <stdio.h> 
#include <stdint.h>
#include <string.h>
#include "uart.h"

// Funtion to create a RawUartChannel
CommunicationChannel* createRawUartChannel() {
    CommunicationChannel* uart = (CommunicationChannel*)malloc(sizeof(CommunicationChannel));
    
}