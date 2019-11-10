//
//  Hexagon.hpp
//  hexDraw
//
//  Created by Phoenix Perry on 6/23/17.
//
//

#ifndef Hexagon_hpp
#define Hexagon_hpp

#include <stdio.h>
#include "ofMain.h"

class Hexagon{
public:
    vector<ofPoint> points;
    ofMesh hexMesh;
    ofPolyline hexLine;
    
    ofPoint center;
    ofPoint currentPoint;
    int size = 0;
    ofColor color;
    bool full = false;
    bool half = false;
    bool off = true;
    bool insideHex = false;
    
    Hexagon(ofPoint *center_, int size_, ofColor color_);
    void setup();
    void update(float mx, float my);
    void draw();
    void hexClicked(ofColor *color);
    
    
private:
    
    void drawHexLine(vector<ofPoint> *points);
    void drawHexMesh(vector<ofPoint> *points);
    ofPoint setHexCorner(ofPoint center, int size_, int i);
    
};
#endif /* Hexagon_hpp */
