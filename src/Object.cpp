//
//  Object.cpp
//  emptyExample
//
//  Created by 大林巧 on 2017/01/30.
//
//
#include "ofMain.h"
#include "Object.h"

Object::Object(){
    pos = ofPoint(150,0,0);
    counter = 0;
    frameNum=0;
    once = true;
}

void Object::init(){

}

void Object::update(){
}
void Object::draw(float _volumeSize){
}

void Object::setPos(ofPoint _pos){
    pos = _pos;
}
