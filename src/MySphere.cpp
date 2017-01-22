//
//  MySphere.cpp
//  emptyExample
//
//  Created by 大林巧 on 2017/01/19.
//
//

#include "MySphere.h"

MySphere::MySphere(){
    pos = ofPoint(150,0,0);
    radius = 100.0;
    counter = 0;
}
void MySphere::update(){
    counter += 0.03f;
}
void MySphere::draw(){
        ofSetColor(255,255,255);
        sphere.set(100 + 30 * sin(counter),int(ABS(sin(counter))*10 + 2));
        sphere.setPosition(pos.x, pos.y, pos.z);
        sphere.draw();
        ofSetColor(255, 0, 0);
        //ofSetLineWidth(1+5 * sin(counter));
        sphere.drawWireframe();

}

void MySphere::setPos(ofPoint _pos){
    pos = _pos;
}

ofPoint MySphere::getPos(){
    return pos;
}

