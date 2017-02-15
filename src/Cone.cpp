//
//  ColorObject.cpp
//  emptyExample
//
//  Created by 大林巧 on 2017/02/11.
//
//
#include "ofMain.h"
#include "Cone.h"


void Cone::init(float _x,float _y,float _z){
    pos = ofPoint(_x,_y,_z);
    Object::init();
    cone.set(100,100);

    }

void Cone::draw(){
    
    Object::draw();
    ofSetColor(0, 0, 0);
    cone.setPosition(pos);
    cone.draw();
    ofSetColor(255, 255, 255);
    ofSetLineWidth(1);
    cone.drawWireframe();

}
