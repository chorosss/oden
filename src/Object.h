//
//  Object.h
//  emptyExample
//
//  Created by 大林巧 on 2017/01/30.
//
//

#ifndef __emptyExample__Object__
#define __emptyExample__Object__

#include <stdio.h>
#include "ofMain.h"
#include "Object.h"

class Object{
public:
    Object();
    void init();
    void update();
    void draw(float volumeSize);
    
    void setPos(ofPoint pos);
    ofPoint getPos();
    
    void setMusic(int music);
    void show();
    
    
    
private:
    
    ofPoint pos;
    
    float volumeSize;
    
    bool once;
    int startTime = 0;
    float counter;
    int frameNum;
};
#endif /* defined(__emptyExample__Object__) */
