#ifndef _GOAL
#define _GOAL

#include "ofMain.h"

class Goal {
public:
    int idx;

    void setup(int _idx);
		void selectTarget();
		void unselectTarget();
		bool getIsTarget();
		void select();
		void unselect();		
		bool getIsSelected();
		
    Goal();
 private:
		bool isTarget;
		bool isSelected;
};
#endif
