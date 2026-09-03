#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_BNO08x.h>

#define BNO08X_RESET 3
#define BNO08X_INT   2

Adafruit_BNO08x bno08x(BNO08X_RESET);
sh2_SensorValue_t sensorValue;

void setup() {
    Serial.begin(115200);

    // Give the USB serial connection a moment
    delay(1000);

    Serial.println("BNO085 test");

    // Start I2C
    Wire.begin();

    // Initialize BNO085
    if (!bno08x.begin_I2C()) {
        Serial.println("Failed to find BNO085!");
        while (1) {
            delay(10);
        }
    }

    Serial.println("BNO085 found!");

    // Enable the reports we want
    if (!bno08x.enableReport(SH2_ACCELEROMETER)) {
        Serial.println("Could not enable accelerometer");
    }

    if (!bno08x.enableReport(SH2_GYROSCOPE_CALIBRATED)) {
        Serial.println("Could not enable gyroscope");
    }

    if (!bno08x.enableReport(SH2_MAGNETIC_FIELD_CALIBRATED)) {
        Serial.println("Could not enable magnetometer");
    }

    if (!bno08x.enableReport(SH2_ROTATION_VECTOR)) {
        Serial.println("Could not enable rotation vector");
    }

    Serial.println("Reports enabled.");
}

void loop() {
    if (bno08x.wasReset()) {
        Serial.println("BNO085 reset!");
    }

    if (bno08x.getSensorEvent(&sensorValue)) {

        switch (sensorValue.sensorId) {

            case SH2_ACCELEROMETER:
                Serial.print("ACCEL: ");
                Serial.print(sensorValue.un.accelerometer.x);
                Serial.print(", ");
                Serial.print(sensorValue.un.accelerometer.y);
                Serial.print(", ");
                Serial.println(sensorValue.un.accelerometer.z);
                break;

            case SH2_GYROSCOPE_CALIBRATED:
                Serial.print("GYRO: ");
                Serial.print(sensorValue.un.gyroscope.x);
                Serial.print(", ");
                Serial.print(sensorValue.un.gyroscope.y);
                Serial.print(", ");
                Serial.println(sensorValue.un.gyroscope.z);
                break;

            case SH2_MAGNETIC_FIELD_CALIBRATED:
                Serial.print("MAG: ");
                Serial.print(sensorValue.un.magneticField.x);
                Serial.print(", ");
                Serial.print(sensorValue.un.magneticField.y);
                Serial.print(", ");
                Serial.println(sensorValue.un.magneticField.z);
                break;

            case SH2_ROTATION_VECTOR:
                Serial.print("QUAT: ");
                Serial.print(sensorValue.un.rotationVector.real);
                Serial.print(", ");
                Serial.print(sensorValue.un.rotationVector.i);
                Serial.print(", ");
                Serial.print(sensorValue.un.rotationVector.j);
                Serial.print(", ");
                Serial.println(sensorValue.un.rotationVector.k);
                break;
        }
    }
  delay(1000);
