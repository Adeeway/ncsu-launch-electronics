#include "brains.hpp"

// Temporary event value used by the flight-state logic.




void calculateAverages(){
    Serial.println("Calculating averages...");
    // TODO store last 3 data readings for all important variables (eg accelZ)
    // and create an average for those last 3, called accelZ_avg.
    // We will use that data to figure out what state we're in
    // NOTE: Dont create averages for ALL the data readings (for example,
    // we don't need a smoothed average for temperature readings)

 // create lists for last 3 readings of each important variable
}

void figureOutState(){

    /*
    Standby: Power is on, systems are idle, and the rocket sits on the pad waiting for final arming.
    Boost (Launch): The motor ignites and the rocket accelerates upward off the pad, detected by high G-force and positive velocity.
    Coast: Motor burnout occurs, and the rocket continues climbing upward on momentum until it reaches apogee.
    Apogee: The highest point of the flight where vertical velocity hits zero, which triggers the primary deployment event (drogue parachute or main depending on dual-deploy).
    Descent / Descent: The parachutes deploy, and the rocket floats safely back down to the ground.
    Landed: The rocket lands, detected by zero movement and zero vertical velocity, signaling the end of the flight profile.
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