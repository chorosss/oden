//
//  Box.cpp
//  emptyExample
//
//  Created by 大林巧 on 2017/02/17.
//
//

#include "Box.h"

Box::Box(){
    once = true;
}

void Box::init(ofPoint _pos){
    pos = _pos;
    Object::init();
    Object::setMusic(int(ofRandom(1, 3)));
    box.set(160);
    box.setPosition(pos);
}
void Box::update(){
    
    Object::update();
    counter = Object::getCounter();
    angle = Object::getAngle();
}

void Box::draw(){
    
    Object::draw();
    
    //box
    box.rotate(sin(angle),10,10,10);
    ofSetColor(0, 0, 0);
    box.draw();
    ofSetColor(255, 255, 255);
    ofSetLineWidth(1);
    box.drawWireframe();
}
