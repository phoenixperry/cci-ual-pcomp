#ifndef _MOTORMANAGER
#define _MOTORMANAGER

#include "ofMain.h"
#include "Motor.h"
#include "SerialWriter.h"

#define ENABLE_MOTORS 1

struct MotorTarget {
		int x, y;
		float width;
};

class MotorManager {
public:
    void setup();
    void update();
    void draw(ofVec2f topLeft, int mWidth, ofVec2f center);
		void mouseReleased(int x, int y, int button);
		void allOff();
		void setMotorState(int, MotorState);
		void winAnimation();

		MotorManager();
 private:
		vector <Motor> motors;
		vector <MotorTarget> targets;
    std::map<MotorState,ofColor> colorMap;
		SerialWriter * sWriter;
};
#endif
