#include "ofApp.h"

const float BoundaryCircleScale = 0.9;
const float MotorGridScale = 0.6;
const int NGoals = 6;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    ofBackground(0);
    ofSetFrameRate(60);
    ofSetCircleResolution(50);
    ofEnableAntiAliasing();

    motors.setup();
    sequencer.setup(&motors);
    goals.setup(NGoals, &sequencer);

    goalSelected = -1; // which one the player has chosen
    goalTargeted = -1; // the "correct" one

    // serial setup
#ifdef ENABLE_POLLEN
    serial_reader = new SerialReader();
    serial_reader->setup();
#endif

//    music.loadSound("honey_for_the_drones.mp3");
//    music.play();
    winSound.loadSound("win.wav");
    loseSound.loadSound("lose.wav");

    isPaused = false;
}

//--------------------------------------------------------------
void ofApp::update(){
#ifdef ENABLE_POLLEN
    int serialGoal = serial_reader->update();
    if (serialGoal > -1) {
        goalSelected = serialGoal;
    }
#endif
    goalTargeted = goals.getTargetGoal();
    sequencer.update();
    motors.update();
    selectGoal();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(ofColor::white);

    // some useful info about the screen
    auto width = ofGetWidth();
    auto height = ofGetHeight();
    auto bound = std::min(width, height);

    ofVec2f center(width / 2, height / 2);
    auto radius = (bound / 2) * BoundaryCircleScale;

    // draw a big ol circle
    drawBoundaryCircle(center, radius);

    // draw the goals
    goals.draw(center, radius);

    // draw the motor grid
    auto dim = MotorGridScale * bound;
    int rows = 3;
    int cols =3;
    int mWidth = dim / rows;
    ofVec2f topLeft(center.x - (mWidth * 1.5), center.y - (mWidth * 1.5));
   // drawGrid(rows, cols, center, topLeft, dim, mWidth);

    // finally, the motors
    motors.draw(topLeft, mWidth, center);
}

void ofApp::drawBoundaryCircle(ofVec2f center, float radius) {
    ofSetColor(220, 220, 220);
    ofDrawCircle(center.x, center.y, radius);
}

void ofApp::drawGrid(int rows, int cols, ofVec2f center, ofVec2f topLeft, float dim, int mWidth) {
//    ofSetColor(ofColor::white);
//    ofSetRectMode(OF_RECTMODE_CENTER);
//    ofDrawRectangle(center.x, center.y, dim, dim);
//    ofSetColor(ofColor::black);
//    ofNoFill();
//    ofSetRectMode(OF_RECTMODE_CORNER);
//
//    for (int i=0; i < rows; i++) {
//        for (int j=0; j < cols; j++) {
//            ofDrawRectangle(topLeft.x + (mWidth * i),
//                            topLeft.y + (mWidth * j),
//                            mWidth, mWidth);
//        }
//    }
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'x') {
        sequencer.stop();
    }
    if (key == ' ') {
        isPaused = !isPaused;
        sequencer.togglePause();
    }
    // speed controls
    if (key == '+') {
        sequencer.speedUp();
    }
    if (key == '-') {
        sequencer.speedDown();
    }

    // this won't work once we have more than 10 goals,
    // but for now...
    if (key >= '0' && key <= '7') {
        // simulate a goal selection
        goalSelected = key - '0';
    }
}

void ofApp::selectGoal() {
    if (goalSelected == -1) {
        return;
    }
    goals.select(goalSelected);
    if (goalTargeted > -1) {
        // there's a target goal, so we're "playing"
        if (goalTargeted == goalSelected) {
            // CORRECT!
            win();
        } else {
            // BZZT! Wrong!
            lose();
        }
    } else {
        // no goal was targeted, so just treat this as
        // debugging
    }
}

void ofApp::win() {
    ofLogNotice() << "correct goal selected! you've got pollen!";
    // show animation
    winSound.play();
    newGame();
}

void ofApp::lose() {
    ofLogNotice() << "wrong goal! no pollen for you!";
    // show animation
    loseSound.play();
    newGame();
}

void ofApp::newGame() {
    ofLogNotice() << "starting new game";
    goalSelected = -1;
    // pick a random goal
    auto g = std::rand() % NGoals;
    goals.selectTarget(g);
    goals.unselectAll();
    sequencer.start(g);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    motors.mouseReleased(x, y, button);
    goals.mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    ofLogNotice() << "resized [" << w << ", " << h << "]";
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}

void ofApp::exit() {
    cout << "stopping all motors" << endl;
    sequencer.stop();
}
