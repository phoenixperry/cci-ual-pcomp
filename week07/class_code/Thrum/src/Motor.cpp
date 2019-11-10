#include "Motor.h"

Motor::Motor() {
}

void Motor::setup(int _idx) {
    idx = _idx;
    state = MotorState::OFF;

    // set up state transition table
    stateTransitions[MotorState::OFF] = MotorState::HALF;
    stateTransitions[MotorState::HALF] = MotorState::FULL;
    stateTransitions[MotorState::FULL] = MotorState::OFF;
}

MotorState Motor::getState() {
    return state;
}

MotorState Motor::interact() {
    return stateTransitions[state];
}

std::string stateString(MotorState ms) {
    switch(ms) {
    case MotorState::OFF:
        return "OFF";
    case MotorState::HALF:
        return "HALF";
    default:
        return "FULL";
    }
}

void Motor::setState(MotorState ms) {
    if (state != ms) {
        state = ms;
    }
}
