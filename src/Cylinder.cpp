//
//  Cylinder.cpp
//  emptyExample
//
//  Created by 大林巧 on 2017/01/30.
//
//

#include "Cylinder.h"

Cylinder::Cylinder(){
    counter = 0;
    frameNum=0;
    once = true;

}

void Cylinder::init(ofPoint _pos){
    
    Object::init();
    pos = _pos;
    Object::setMusic(5);
    myImage.loadImage("texture04.jpg");
    cylinder.mapTexCoords(0, 0, 270, 180);
}

void Cylinder::update(){
    
    Object::update();
    counter = Object::getCounter();
    //cylinder.mapTexCoords(0, 0, 200+ 100* sin(counter), 130 + 100* sin(counter));
}

void Cylinder::draw(float _volumeSize){
    
    volumeSize = _volumeSize;
    Object::draw();
    
    ofSetColor(255,255,255);
    cylinder.set(100 + 30 * sin(counter)+ volumeSize,int(ABS(sin(counter))*100 + 2));
    cylinder.setPosition(pos.x, pos.y, pos.z);
    myImage.getTextureReference().bind();
    cylinder.draw();
    myImage.getTextureReference().unbind();
      
}
