#include <Arduino.h>
#include <BluetoothSerial.h>

#define LED 2

BluetoothSerial SerialBT;

void setup() {
    pinMode(LED, OUTPUT);
    Serial.begin(115200);         // Serial Monitor
    SerialBT.begin("ESP32_BT");   // Bluetooth ESP32
    Serial.println("Bluetooth started! Pair with 'ESP32_BT'");
}

void loop() {
    if (SerialBT.available()) {
        char received = SerialBT.read();
        Serial.print("Received: ");
        Serial.println(received);

        if (received == '1') {
            digitalWrite(LED, HIGH);
            Serial.println("LED ON");   // ON LED
        } else if (received == '0') {
            digitalWrite(LED, LOW);
            Serial.println("LED OFF");   // OFF LED
        }
    }

    delay(20);
}
