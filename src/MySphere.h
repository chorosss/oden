//
//  MySphere.h
//  emptyExample
//
//  Created by 大林巧 on 2017/01/19.
//
//

#ifndef _MY_SPHERE
#define _MY_SPHERE

#include "ofMain.h"
class MySphere{
    
public:
    
    MySphere();
    void init();
    void update();
    void draw(float volumeSize);
    
    void setPos(ofPoint pos);
    void setMusic(int music);
    void show();
    
    ofPoint getPos();
    
    
    
private:
    
    ofSpherePrimitive sphere; 
    float radius;
    float counter;
    float volumeSize;
    int playCounter;
    ofPoint pos;
    int music;
    
    ofSoundPlayer mySound;
    
    int startTime = 0;
    int s = ofGetSeconds();
    
    bool once;
    
    int frameRate;
    int frameNum;

};

#endif