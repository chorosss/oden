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
#include "Object.h"

class MySphere:public Object{
    
public:
    
    MySphere();
    void init(ofPoint pos);
    void update();
    void draw(float volumeSize);
    
    void setPos(ofPoint pos);
    void setMusic(int music);
    void show();
    
    ofPoint getPos();
    bool once;
    
    
    
private:
    
    ofSpherePrimitive sphere; 
    float radius;
    float counter;
    float volumeSize;
    int playCounter;
    ofPoint pos;
    ofImage myImage;

    int music;
    
    int startTime = 0;
    int s = ofGetSeconds();
    
    
    int frameRate;
    int frameNum;

};

#endif