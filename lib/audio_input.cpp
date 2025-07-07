#include "audio_input.h"
#include <driver/i2s.h>

void initMic() {
  // I2S 配置略过，后续我们会加上
  Serial.println("Mic initialized");
}

bool recordToBuffer(uint8_t* buffer, size_t maxLen) {
  // 模拟采样逻辑（暂时只是返回 true）
  Serial.println("Recording simulated...");
  delay(1000); // 模拟录音 1 秒
  return true;
}
