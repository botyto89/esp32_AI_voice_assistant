#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <WiFi.h>
#include <WiFiMulti.h>
#include "config/secrets.h"

WiFiMulti wifiMulti;

void setupWiFi() {
  Serial.println("🔌 尝试连接多个 Wi-Fi 网络...");

  // 你可以添加多个 WiFi，这些定义在 secrets.h
  wifiMulti.addAP(WIFI_SSID_1, WIFI_PASS_1);
  wifiMulti.addAP(WIFI_SSID_2, WIFI_PASS_2);
  wifiMulti.addAP(WIFI_SSID_3, WIFI_PASS_3);

  int retry = 0;
  while (wifiMulti.run() != WL_CONNECTED && retry < 20) {
    delay(500);
    Serial.print(".");
    retry++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\n✅ 已连接：" + WiFi.SSID());
    Serial.println("IP 地址: " + WiFi.localIP().toString());
  } else {
    Serial.println("\n❌ 无法连接任何 WiFi");
  }
}

#endif