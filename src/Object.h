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
    void init(float _x,float _y);
    void draw();
    void setPos(ofPoint pos);
    ofPoint getPos();
    int testFunction();
    float x,y;

private:
    ofPoint pos;
    ofMesh mesh;
    ofImage myImage;
};
#endif /* defined(__emptyExample__Object__) */
