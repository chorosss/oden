//
//  ColorObject.cpp
//  emptyExample
//
//  Created by 大林巧 on 2017/02/11.
//
//
#include "ofMain.h"
#include "Cone.h"

Cone::Cone(){
    counter = 0;
    frameNum=0;
    once = true;
    
}

void Cone::init(ofPoint _pos){
    pos = _pos;
    Object::init();
    Object::setMusic(int(ofRandom(1, 3)));
    cone.set(100,100);

    }
void Cone::update(){
    
    Object::update();
    counter = Object::getCounter();    
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
