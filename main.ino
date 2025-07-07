#include <WiFi.h>
#include "config/secrets.h"
#include "lib/audio_input.h"
#include "lib/wifi_manager.h"


void connectWiFi() {
  Serial.print("Connecting to WiFi...");
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  int retries = 0;
  while (WiFi.status() != WL_CONNECTED && retries < 20) {
    delay(500);
    Serial.print(".");
    retries++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWiFi connected!");
    Serial.println("IP address: " + WiFi.localIP().toString());
  } else {
    Serial.println("\nWiFi connection failed.");
  }
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  setupWiFi();     // 👈 自动联网

  initMic();
  Serial.println("麦克风已初始化");

  uint8_t buffer[2048];
  bool ok = recordToBuffer(buffer, sizeof(buffer));

  if (ok) {
    Serial.println("✅ 模拟录音成功");
  }
}

void loop() {
  // 后续添加自动唤醒 + Azure STT + TTS 等
}
