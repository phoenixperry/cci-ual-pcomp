#include "Goal.h"
Goal::Goal() {
}

void Goal::setup(int _idx) {
    idx = _idx;
    isTarget = false;
    isSelected = false;
}

void Goal::selectTarget() {
    isTarget = true;
}

void Goal::unselectTarget() {
    isTarget = false;
}

bool Goal::getIsTarget() {
    return isTarget;
}

void Goal::select() {
    isSelected = true;
}

void Goal::unselect() {
    isSelected = false;
}

bool Goal::getIsSelected() {
    return isSelected;
}
