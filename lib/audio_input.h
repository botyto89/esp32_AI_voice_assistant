#ifndef AUDIO_INPUT_H
#define AUDIO_INPUT_H

#include <Arduino.h>

void initMic();
bool recordToBuffer(uint8_t* buffer, size_t maxLen);

#endif
