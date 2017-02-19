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
    pos = ofPoint(100,0,0);

  }

void Object::init(){

    once = true;
    frameNum=0;
    counter = 0;
    angle = 0;
    mySound.setLoop(false); //ループ再生をONに
//    
//    mesh.addVertex(ofVec3f(100,100,0));
//    mesh.addVertex(ofVec3f(100,200,0));
//    mesh.addVertex(ofVec3f(200,200,0));
//    mesh.addVertex(ofVec3f(200,100,0));
//    mesh.addVertex(ofVec3f(150,150,100));
//    
//    mesh.addTexCoord( ofVec3f(100,100,0) );
//    mesh.addTexCoord( ofVec3f(100,200,0) );
//    mesh.addTexCoord( ofVec3f(200,200,0));
//    mesh.addTexCoord( ofVec3f(200,100,0));
//    mesh.addTexCoord( ofVec3f(150,150,100));
//    
//    mesh.setMode(OF_PRIMITIVE_TRIANGLES);
//    
//    mesh.addIndex(0);
//    mesh.addIndex(1);
//    mesh.addIndex(2);
//    mesh.addIndex(0);
//    mesh.addIndex(3);
//    mesh.addIndex(2);
//    mesh.addIndex(0);
//    mesh.addIndex(4);
//    mesh.addIndex(1);
//    mesh.addIndex(0);
//    mesh.addIndex(3);
//    mesh.addIndex(4);
//    mesh.addIndex(3);
//    mesh.addIndex(2);
//    mesh.addIndex(4);
//    mesh.addIndex(1);
//    mesh.addIndex(2);
//    mesh.addIndex(4);
}
void Object::update(){
        
    frameNum ++;
    
    if(frameNum==300){
        mySound.play();
        frameNum=0;
    }
    
    counter += 0.03f;
    angle += 0.03f;
    
}


void Object::draw(){
    
    if(once){
        //std::cout << "value: "<< endl;
        show();
        once = false;
    }

//    ofPushMatrix();
//    ofTranslate(x,y,100);
//    ofSetColor( 255, 255, 255 );
//    myImage.getTextureReference().bind();
//    mesh.draw();
//    myImage.unbind();
//    ofPushMatrix();
//    ofTranslate(100, 100,100);
//    ofSetLineWidth(1);
//    mesh.drawWireframe();
//    ofPopMatrix();
//    ofPopMatrix();
}

void Object::setPos(ofPoint _pos){
    pos = _pos;
}

ofPoint Object::getPos(){
    return pos;
}

float Object::getCounter(){
    return counter;
}

float Object::getAngle(){
    return angle;
}

void Object::setMusic(int _music){
    music = _music;
    
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

}

void Object::show(){
    mySound.play();
    
}
