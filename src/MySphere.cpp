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
    frameNum=0;
    once = true;
}

void MySphere::init(){
    myImage.loadImage("texture01.jpg");
    
    sphere.mapTexCoords(0, 0, 270, 180);
    

    
    if(music==1){
        mySound.loadSound("music/01.mp3");
    }else if(music ==2){
        mySound.loadSound("music/02.mp3");
    }else if(music ==3){
        mySound.loadSound("music/03.mp3");
    }else if(music ==4){
        mySound.loadSound("music/04.mp3");
    }else if(music ==5){
        mySound.loadSound("music/05.mp3");
    }else{
        mySound.loadSound("music/06.mp3");
    }
    
    mySound.setLoop(false); //ループ再生をONに
}

void MySphere::update(){
    
    sphere.mapTexCoords(0, 0, 200+ 100* sin(counter), 130 + 100* sin(counter));
    
    frameNum ++;
    
    if(frameNum==300){
        mySound.play();
        frameNum=0;
    }
    
    counter += 0.03f;

    
}

void MySphere::draw(float _volumeSize){
    
    volumeSize = _volumeSize;
    
    if(once){
        show();
        once = false;
    }
    
        ofSetColor(255,255,255);
        sphere.set(100 + 30 * sin(counter)+ volumeSize,int(ABS(sin(counter))*10 + 2));
        sphere.setPosition(pos.x, pos.y, pos.z);
        myImage.getTextureReference().bind();
        sphere.draw();
        myImage.getTextureReference().unbind();
//        ofSetColor(255, 0, 0);
//        sphere.drawWireframe();

}

void MySphere::setPos(ofPoint _pos){
    pos = _pos;
}

void MySphere::setMusic(int _music){
    music = _music;
}

ofPoint MySphere::getPos(){
    return pos;
}

void MySphere::show(){
    mySound.play();
}