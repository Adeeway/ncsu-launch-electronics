#include "brains.hpp"



void calculateAverages(){
    // TODO store last 3 data readings for all important variables (eg accelZ)
    // and create an average for those last 3, called accelZ_avg.
    // We will use that data to figure out what state we're in
    // NOTE: Dont create averages for ALL the data readings (for example,
    // we don't need a smoothed average for temperature readings)

 // create lists for last 3 readings of each important variable
    float accelX_list[3] = {0.0f, 0.0f, 0.0f};
    float accelY_list[3] = {0.0f, 0.0f, 0.0f};
    float accelZ_list[3] = {0.0f, 0.0f, 0.0f};
    float gyroX_list[3] = {0.0f, 0.0f, 0.0f};
    float gyroY_list[3] = {0.0f, 0.0f, 0.0f};
    float gyroZ_list[3] = {0.0f, 0.0f, 0.0f};
    float magX_list[3] = {0.0f, 0.0f, 0.0f};
    float magY_list[3] = {0.0f, 0.0f, 0.0f};
    float magZ_list[3] = {0.0f, 0.0f, 0.0f};
    float quatReal_list[3] = {0.0f, 0.0f, 0.0f};
    float quatI_list[3] = {0.0f, 0.0f, 0.0f};
    float quatJ_list[3] = {0.0f, 0.0f, 0.0f};
    float quatK_list[3] = {0.0f, 0.0f, 0.0f};
    float temperature_C_list[3] = {0.0f, 0.0f, 0.0f};

    // shift readings over and add new reading to the end of the list
    if(sensorValue.sensorId == SH2_ACCELEROMETER){
    accelX_list[0] = accelX_list[1];
    accelX_list[1] = accelX_list[2];
    accelX_list[2] = accelX;

    accelY_list[0] = accelY_list[1];
    accelY_list[1] = accelY_list[2];
    accelY_list[2] = accelY;

    accelZ_list[0] = accelZ_list[1];
    accelZ_list[1] = accelZ_list[2];
    accelZ_list[2] = accelZ;

    //Calculate averages for the acceleration readings
    accelX_avg = (accelX_list[0] + accelX_list[1] + accelX_list[2]) / 3.0f;
    accelY_avg = (accelY_list[0] + accelY_list[1] + accelY_list[2]) / 3.0f;
    accelZ_avg = (accelZ_list[0] + accelZ_list[1] + accelZ_list[2]) / 3.0f;

}   else if(sensorValue.sensorId == SH2_GYROSCOPE_CALIBRATED){
    gyroX_list[0] = gyroX_list[1];
    gyroX_list[1] = gyroX_list[2];
    gyroX_list[2] = gyroX;

    gyroY_list[0] = gyroY_list[1];
    gyroY_list[1] = gyroY_list[2];
    gyroY_list[2] = gyroY;

    gyroZ_list[0] = gyroZ_list[1];
    gyroZ_list[1] = gyroZ_list[2];
    gyroZ_list[2] = gyroZ;

    //Calculate the averages for the gyro readings
    gyroX_avg = (gyroX_list[0] + gyroX_list[1] + gyroX_list[2]) / 3.0f;
    gyroY_avg = (gyroY_list[0] + gyroY_list[1] + gyroY_list[2]) / 3.0f;
    gyroZ_avg = (gyroZ_list[0] + gyroZ_list[1] + gyroZ_list[2]) / 3.0f;

}   else if(sensorValue.sensorId == SH2_MAGNETIC_FIELD_CALIBRATED){
    magX_list[0] = magX_list[1];
    magX_list[1] = magX_list[2];
    magX_list[2] = magX;

    magY_list[0] = magY_list[1];
    magY_list[1] = magY_list[2];
    magY_list[2] = magY;

    magZ_list[0] = magZ_list[1];
    magZ_list[1] = magZ_list[2];
    magZ_list[2] = magZ;

    //Calculate the averages for the mag readings
    magX_avg = (magX_list[0] + magX_list[1] + magX_list[2]) / 3.0f;
    magY_avg = (magY_list[0] + magY_list[1] + magY_list[2]) / 3.0f;
    magZ_avg = (magZ_list[0] + magZ_list[1] + magZ_list[2]) / 3.0f;

}   else if(sensorValue.sensorId == SH2_ROTATION_VECTOR){
    quatReal_list[0] = quatReal_list[1];
    quatReal_list[1] = quatReal_list[2];
    quatReal_list[2] = quatReal;

    quatI_list[0] = quatI_list[1];
    quatI_list[1] = quatI_list[2];
    quatI_list[2] = quatI;

    quatJ_list[0] = quatJ_list[1];
    quatJ_list[1] = quatJ_list[2];
    quatJ_list[2] = quatJ;

    quatK_list[0] = quatK_list[1];
    quatK_list[1] = quatK_list[2];
    quatK_list[2] = quatK;

    //Calculate the averages for the quat readings
    quatReal_avg = (quatReal_list[0] + quatReal_list[1] + quatReal_list[2]) / 3.0f;
    quatI_avg = (quatI_list[0] + quatI_list[1] + quatI_list[2]) / 3.0f;
    quatJ_avg = (quatJ_list[0] + quatJ_list[1] + quatJ_list[2]) / 3.0f;
    quatK_avg = (quatK_list[0] + quatK_list[1] + quatK_list[2]) / 3.0f;
}   else if(temperature_C == temp_event.temperature){
   
    temperature_C_list[0] = temperature_C_list[1];
    temperature_C_list[1] = temperature_C_list[2];
    temperature_C_list[2] = temperature_C;

    //Calculate the average temp readings
    temperature_C_avg = (temperature_C_list[0] + temperature_C_list[1] + temperature_C_list[2]) / 3.0f;
}
}

void figureOutState(){

    /*
    Standby: Power is on, systems are idle, and the rocket sits on the pad waiting for final arming.
    Armed: Launch checks are complete, pyro channels are live, and the flight computer actively listens for launch acceleration.
    Boost (Launch): The motor ignites and the rocket accelerates upward off the pad, detected by high G-force and positive velocity.
    Coast: Motor burnout occurs, and the rocket continues climbing upward on momentum until it reaches apogee.
    Apogee: The highest point of the flight where vertical velocity hits zero, which triggers the primary deployment event (drogue parachute or main depending on dual-deploy).
    Recovery / Descent: The parachutes deploy, and the rocket floats safely back down to the ground.
    Touchdown: The rocket lands, detected by zero movement and zero vertical velocity, signaling the end of the flight profile.
    
    Abort: An anomaly is detected on the pad or early in flight, shutting down or safely triggering recovery before disaster strikes.
    Safe: A post-flight or error state where charges are disabled so recovery crews can handle the rocket safely.
    */
    

    
    /*
    if (Power is on, systems are idle, rocket is on pad) {
    state = STATE_STANDBY;
    }
    */
    
    if (accelZ_avg >= 20 && velocityZ>1) {
        state = STATE_BOOST;
    }

    if (accelZ_avg < 1 && velocityZ>0) {
        state = STATE_COAST;
    }

    if (velocityZ <= 1 && velocityZ >= -1) {
        state = STATE_APOGEE;
    }

    if (velocityZ < -1) {
        state = STATE_DESCENT;
    }

    if (accelZ_avg < 1 && velocityZ < 1) {
        state = STATE_LANDED;
    }   

}

void calculateVelocityZ(){
    velocityZ += accelZ_avg * deltaTime;
}