#pragma once

#include "ofMain.h"
#include "GoalManager.h"
#include "MotorManager.h"
#include "Sequencer.h"
#include "SerialReader.h"

#define ENABLE_POLLEN  //undef == turn it off

class ofApp : public ofBaseApp{

 public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
		void selectGoal();
    void exit();
 private:
    void drawBoundaryCircle(ofVec2f center, float radius);
    void drawGrid(int rows, int cols, ofVec2f center, ofVec2f topLeft, float dim, int mWidth);
    void win();
    void lose();
    void newGame();

    GoalManager goals;
    MotorManager motors;
    Sequencer sequencer;
    SerialReader *serial_reader;

    ofSoundPlayer music;
    ofSoundPlayer winSound;
    ofSoundPlayer loseSound;

    int goalSelected;
    int goalTargeted;

		bool isPaused;
};
