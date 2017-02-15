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

class Object{
public:
    Object();
    void init();
    void update();
    void draw();
    void show();
    
    //setter
    void setMusic(int music);
    void setPos(ofPoint pos);
    
    //getter
    ofPoint getPos();
    float getCounter();
    
    ofSoundPlayer mySound;
    
    float x,y;
    int music;
    bool once;
    float counter;
    int frameRate;
    int frameNum;

private:
    ofPoint pos;
    ofMesh mesh;
    ofImage myImage;
 

};
#endif /* defined(__emptyExample__Object__) */
