//
//  Cylinder.h
//  emptyExample
//
//  Created by 大林巧 on 2017/01/30.
//
//

#ifndef __emptyExample__Cylinder__
#define __emptyExample__Cylinder__

#include <stdio.h>
#include "ofMain.h"
#include "Object.h"

class Cylinder{
public:
    Cylinder();
    void init();
    void update();
    void draw(float _volumeSize);
    
    void setPos(ofPoint pos);
    void setMusic(int music);
    void show();
    
    ofPoint getPos();

private:
    
    ofCylinderPrimitive cylinder;
    float counter;
    float volumeSize;
    int playCounter;
    ofPoint pos;
    ofImage myImage;
    int music;
    
    ofSoundPlayer mySound;
    
    int startTime = 0;
    int s = ofGetSeconds();
    
    bool once;
    
    int frameRate;
    int frameNum;

};
#endif /* defined(__emptyExample__Cylinder__) */
