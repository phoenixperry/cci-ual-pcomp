#include "MotorManager.h"
#include "Hexagon.hpp"

const unsigned NMotors = 7;

const int rows[NMotors] = {0, 0,
    
                        1, 1, 1,
    
                         2, 2};

const int cols[NMotors] = {1, 2,
    
                        0, 1, 2,
    
                           1, 2};
vector<Hexagon> hexs;
const int size = 50;
const int qs[7] = {0,   1, -1, 0, 1, -1, 0};
const int rs[7] = {-1, -1,  0, 0, 0,  1, 1};
ofPoint hex_location;
MotorManager::MotorManager() {
}

void MotorManager::setup() {
    // layout row/column for each motor
    for (unsigned i=0; i<NMotors; i++) {
        Motor m;
        m.setup(i);
        motors.push_back(m);

        MotorTarget t;
        targets.push_back(t);
    }
    // populate color table
    colorMap[MotorState::HALF] = ofColor::orange;
    colorMap[MotorState::FULL] = ofColor::red;
    colorMap[MotorState::OFF] = ofColor::white;
    for (int i = 0; i < NMotors; i++) {
        hex_location = ofPoint(ofGetWidth()/2,ofGetHeight()/2);
        int q = qs[i];
        int r = rs[i];
        double x = (sqrt(3.0) * q + (sqrt(3.0) / 2.0) * r) * size;
        double y = (3.0 / 2.0) * r * size;
        hex_location.x = x +hex_location.x;
        hex_location.y = y +hex_location.y;
        Hexagon h = * new Hexagon(&hex_location, size,colorMap[MotorState::OFF]);
        hexs.push_back(h);
    }

  
#ifdef ENABLE_MOTORS
    ofLogNotice() << "enabling serialwriter";
    sWriter = new SerialWriter();
    sWriter->setup();
#endif
}

void MotorManager::update() {
#ifdef ENABLE_MOTORS
    sWriter->update();

#endif
}

void MotorManager::winAnimation() {
    // in here because the motor controller arduino
    // happens to be the one with the neopixels attached
#ifdef ENABLE_MOTORS
    sWriter->winAnimation();
#endif
}

void MotorManager::draw(ofVec2f topLeft, int mWidth, ofVec2f center) {
    for (unsigned int i=0; i < motors.size(); i++) {
        int row = rows[i];
        int col = cols[i];
        auto radius = float(mWidth) / 2;

        // fill color based on motor state
        ofSetColor(colorMap[motors.at(i).getState()]);
//        ofFill();
//        ofDrawCircle(topLeft.x + (mWidth * col) + radius,
//                     topLeft.y + (mWidth * row) + radius,
//                     radius);
        hex_location = ofVec2f(center);
    
        int q = qs[i];
        int r = rs[i];
        double x = (sqrt(3.0) * q + (sqrt(3.0) / 2.0) * r) * mWidth/2;
        double y = (3.0 / 2.0) * r * mWidth/2;
        hex_location.x = x +hex_location.x;
        hex_location.y = y +hex_location.y;

        hexs.at(i).color =colorMap[motors.at(i).getState()];
        hexs.at(i).center = hex_location;
        hexs.at(i).size = mWidth/2;
        hexs.at(i).setup();
        hexs.at(i).draw();
        
        // then a black outline
        ofSetColor(ofColor::black);
        ofNoFill();
        //ofSetCircleResolution(50);
        
        
//        ofDrawCircle(topLeft.x + (mWidth * col) + radius,
//                     topLeft.y + (mWidth * row) + radius,
//                     radius);

        // also save the clickable target box
        
        targets.at(i).x = topLeft.x + (mWidth * col);
        targets.at(i).y = topLeft.y + (mWidth * row);
        targets.at(i).width = mWidth;
    }

}

void MotorManager::mouseReleased(int x, int y, int button){
    for (unsigned int i=0; i<targets.size(); i++) {
        auto t = targets.at(i);
        if ((x >= t.x && x < (t.x + t.width)) &&
            (y >= t.y && y < (t.y + t.width))) {
            MotorState s = motors.at(i).interact();
            setMotorState(i, s);
        }
    }
}

void MotorManager::allOff() {
    for (auto & motor : motors) {
        motor.setState(MotorState::OFF);
    }
#ifdef ENABLE_MOTORS
    for (int i=0; i < motors.size(); i++) {
        sWriter->setMotor(i, MotorState::OFF);
    }
#endif
}

void MotorManager::setMotorState(int idx, MotorState ms) {
    motors.at(idx).setState(ms);
#ifdef ENABLE_MOTORS
    sWriter->setMotor(idx, ms);
#endif
}
