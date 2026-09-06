#include "brains.hpp"






void calculateAverages(){
    // TODO store last 3 data readings for all important variables (eg accelZ)
    // and create an average for those last 3, called accelZ_avg.
    // We will use that data to figure out what state we're in
    // NOTE: Dont create averages for ALL the data readings (for example,
    // we don't need a smoothed average for temperature readings)
}

void figureOutState(){
    // TODO: figure out state from the data given. THese down here are just silly examples!
    if(accelZ_avg && state == STATE_STANDBY){
        state = STATE_STANDBY; // this would be fully useless!
        // please remember not to waste compute power, here its very limited
    }
    else if(accelZ_avg == 123456789.123 && state == STATE_STANDBY){
        state = STATE_BURN;
    }

}
