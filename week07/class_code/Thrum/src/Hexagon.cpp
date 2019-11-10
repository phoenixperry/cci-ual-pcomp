//
//  Hexagon.cpp
//  hexDraw
//
//  Created by Phoenix Perry on 6/23/17.
//
//

#include "Hexagon.hpp"
Hexagon::Hexagon(ofPoint *center_, int size_, ofColor color_){
    center = *center_;
    size = size_;
    color = color_;
    setup();
}

void Hexagon::setup(){
    points.clear();
    ofPolyline hexline = *new ofPolyline();
    
    for (int i = 0; i < 6; i++)
    {
        currentPoint= setHexCorner(center, size, i);
        points.push_back(currentPoint);
        // cout<<points.size() <<endl;
    }
    hexMesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
    
}
void Hexagon::update(float mx, float my){
    if(hexLine.inside(mx, my) ){
        insideHex = true;
    }else insideHex = false;
    
   // cout << insideHex << endl;
}
void Hexagon::draw(){
    drawHexLine(&points);
    drawHexMesh(&points);
}
void Hexagon::drawHexMesh(vector<ofPoint> *points){
    hexMesh.clear();
    for (int i=0; i<6; i++) {
        hexMesh.addVertex(points->at(i));
    }
    ofSetColor(color);
    ofFill();
    hexMesh.draw();
}

void Hexagon::drawHexLine(vector<ofPoint> *points){
    hexLine.clear();
    for(int i=0; i<6; i++)
    {
        ofPoint p = points->at(i);
        ofSetLineWidth(2.0);  // Line widths apply to polylines
        ofSetColor(ofColor::black);
        hexLine.addVertex(p);
        ofFill();
    }
    hexLine.close();
    hexLine.draw();
}

//creates the points from the center point for the hexagon
ofPoint Hexagon::setHexCorner(ofPoint center, int size_, int i){
    float startPointInDegrees =30;
    float angle_deg = 60*i+startPointInDegrees;
    float angle_rad = PI/180 * angle_deg;
    float x = center.x + size_ * cos(angle_rad);
    float y = center.y + size_ * sin(angle_rad);
    ofPoint location = *new ofPoint(x,y);
    return location;
}

