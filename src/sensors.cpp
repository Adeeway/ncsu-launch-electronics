#include "sensors.hpp"



void readBNO08x() {
    if (bno08x.wasReset()) {
        Serial.println("BNO085 reset!");
    }

    if (bno08x.getSensorEvent(&sensorValue)) {
        switch (sensorValue.sensorId) {
            case SH2_ACCELEROMETER:
                accelX = sensorValue.un.accelerometer.x;
                accelY = sensorValue.un.accelerometer.y;
                accelZ = sensorValue.un.accelerometer.z;
                break;
            case SH2_GYROSCOPE_CALIBRATED:
                gyroX = sensorValue.un.gyroscope.x;
                gyroY = sensorValue.un.gyroscope.y;
                gyroZ = sensorValue.un.gyroscope.z;
                break;
            case SH2_MAGNETIC_FIELD_CALIBRATED:
                magX = sensorValue.un.magneticField.x;
                magY = sensorValue.un.magneticField.y;
                magZ = sensorValue.un.magneticField.z;
                break;
            case SH2_ROTATION_VECTOR:
                quatReal = sensorValue.un.rotationVector.real;
                quatI = sensorValue.un.rotationVector.i;
                quatJ = sensorValue.un.rotationVector.j;
                quatK = sensorValue.un.rotationVector.k;
                break;
        }
    }
}

void readDPS310() {
    sensors_event_t temp_event, pressure_event;
    if (dps.temperatureAvailable() && dps.pressureAvailable()) {
        dps.getEvents(&temp_event, &pressure_event);
        temperature_C = temp_event.temperature;
        pressure_hPa = pressure_event.pressure;
    }
}
