#include "brains.hpp"



void calculateAverages(){
    // TODO store last 3 data readings for all important variables (eg accelZ)
    // and create an average for those last 3, called accelZ_avg.
    // We will use that data to figure out what state we're in
    // NOTE: Dont create averages for ALL the data readings (for example,
    // we don't need a smoothed average for temperature readings)
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
    
    if (/* Power is on, systems are idle, rocket is on pad */) {
    state = STATE_STANDBY;
    }


    if (accelZ_avg >= 20 && calculateVelocityZ) {
        state = STATE_BOOST;
    }

    if (/* Motor burnout: acceleration returns near 0 AND vertical velocity is still positive */) {
        state = STATE_COAST;
    }

    if (/* Vertical velocity reaches approximately 0 at the top of the flight */) {
        state = STATE_APOGEE;
    }

    if (/* Parachute deployed AND vertical velocity is negative */) {
        state = STATE_RECOVERY;
    }

    if (/* Rocket has essentially zero velocity AND zero acceleration/movement */) {
        state = STATE_TOUCHDOWN;
    }   

}

void calculateVelocityZ(){
    velocityZ += accelZ_avg * deltaTime
}