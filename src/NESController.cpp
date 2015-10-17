#include "Arduino.h"
#include "NESController.h"

NESController::NESController(int pin_latch, int pin_clock, int pin_data) {
    NESLatch = pin_latch;
    NESClock = pin_clock;
    NESData = pin_data;

    pinMode(NESLatch, OUTPUT);
    pinMode(NESClock, OUTPUT);
    pinMode(NESData, INPUT);
}

bool NESController::pressed(byte direction) {
    return (~NESButtonData & direction) > 0;
}

void NESController::read() {            
    // Send a pulse through latch pin to make 4021 chip store controller state
    digitalWrite(NESLatch, HIGH);
    digitalWrite(NESLatch, LOW);

    // Controller state is made of 8 bits
    for(int x = 0; x <= 7; x++) {
        bitWrite(NESButtonData, x, digitalRead(NESData));

        // Send a clock pulse to indicate we're ready to read next bit
        digitalWrite(NESClock, HIGH);
        digitalWrite(NESClock, LOW);
    }
}
