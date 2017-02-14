//
//  ColorObject.cpp
//  emptyExample
//
//  Created by 大林巧 on 2017/02/11.
//
//
#include "ofMain.h"
#include "ColorObject.h"


void ColorObject::init(float _x,float _y){

    Object::init(_x,_y,"texture03.jpg");
    }

void ColorObject::draw(){
    Object::draw();
}

//void ColorObject::setPos(ofPoint _pos){
//    pos = _pos;
//}
//
//ofPoint ColorObject::getPos(){
//    return pos;
//}
