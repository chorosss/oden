//
//  Box.h
//  emptyExample
//
//  Created by 大林巧 on 2017/02/17.
//
//

#ifndef __emptyExample__Box__
#define __emptyExample__Box__

#include <stdio.h>
#include "ofMain.h"
#include "Object.h"
class Box:public Object{
    
public:
    Box();
    void init(ofPoint _pos);
    void update();
    void draw();
    void setPos(ofPoint pos);
    ofPoint getPos();
    
private:
    
    ofBoxPrimitive box; // 立方体プリミティブ
    ofPoint pos;
    ofImage myImage;
    
    float counter;
    float volumeSize;
    int music;
    
    int startTime = 0;
    int frameNum;
    
    float angle;

};

#endif /* defined(__emptyExample__Box__) */
