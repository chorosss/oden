//
//  Cylinder.cpp
//  emptyExample
//
//  Created by 大林巧 on 2017/01/30.
//
//

#include "Cylinder.h"

Cylinder::Cylinder(){
    pos = ofPoint(150,0,0);
    counter = 0;
    frameNum=0;
    once = true;

}

void Cylinder::init(){
    myImage.loadImage("texture04.jpg");
    
    cylinder.mapTexCoords(0, 0, 270, 180);
    
    
    
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

void Cylinder::update(){
    
    cylinder.mapTexCoords(0, 0, 200+ 100* sin(counter), 130 + 100* sin(counter));
    
    frameNum ++;
    
    if(frameNum==300){
        mySound.play();
        frameNum=0;
    }
    
    counter += 0.03f;
    
    
}

void Cylinder::draw(){
    
    //volumeSize = _volumeSize;
    
    if(once){
        show();
        once = false;
    }
    
    ofSetColor(255,255,255);
    cylinder.set(100 + 30 * sin(counter)+ volumeSize,int(ABS(sin(counter))*100 + 2));
    cylinder.setPosition(pos.x, pos.y, pos.z);
    myImage.getTextureReference().bind();
    cylinder.draw();
    myImage.getTextureReference().unbind();
      
}

void Cylinder::setPos(ofPoint _pos){
    pos = _pos;
}

void Cylinder::setMusic(int _music){
    music = _music;
}

ofPoint Cylinder::getPos(){
    return pos;
}

void Cylinder::show(){
    mySound.play();
}