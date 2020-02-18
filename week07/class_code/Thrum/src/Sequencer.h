#ifndef _SEQUENCER
#define _SEQUENCER

#include "ofMain.h"
#include "Motor.h"
#include "MotorManager.h"

struct Step {
    unsigned motor;
    MotorState state;
};

struct Sequence {
    vector <Step> steps;
};


class Sequencer {
 public:
    void setup(MotorManager *);
    void update();
    void start(int);
    void stop();
    void togglePause();
    void speedUp();
    void speedDown();

    Sequencer();
 private:
    bool isRunning;
    bool isPaused;
    MotorManager * motors;
    float startTime;
    float nextStepTime;
    int goal;
    int step;
    int OffStepTime;
    int FullStepTime;
    int HalfStepTime;
    int lastMotor;
    Sequence currentSequence;
    int stepTimeFromMotorState(Step);
    std::map <int, Sequence> patterns;
};
#endif
