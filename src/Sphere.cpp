//
//  MySphere.cpp
//  emptyExample
//
//  Created by 大林巧 on 2017/01/19.
//
//

#include "Sphere.h"

Sphere::Sphere(){
    counter = 0;
    frameNum=0;
    radius = 100.0;
}

void Sphere::init(ofPoint _pos){
    
    Object::init();
    pos = _pos;
    Object::setMusic(1);
    
    myImage.loadImage("texture01.jpg");
    sphere.mapTexCoords(0, 0, 270, 180);
    
}

void Sphere::update(){
    
    Object::update();
    
    counter = Object::getCounter();

    //sphere.mapTexCoords(0, 0, 200+ 100* sin(counter), 130 + 100* sin(counter));
}

void Sphere::draw(float _volumeSize){
        volumeSize = _volumeSize;
    
        Object::draw();
    
        ofSetColor(255,255,255);
        sphere.set(100 + 30 * sin(counter)+ volumeSize,int(ABS(sin(counter))*10 + 2));
        sphere.setPosition(pos);
        myImage.getTextureReference().bind();
        sphere.draw();
        myImage.getTextureReference().unbind();
//        ofSetColor(255, 0, 0);
//        sphere.drawWireframe();
//        std::cout << "test " << endl;

}
