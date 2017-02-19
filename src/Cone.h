//
//  ColorObject.h
//  emptyExample
//
//  Created by 大林巧 on 2017/02/11.
//
//

#ifndef __emptyExample__ColorObject__
#define __emptyExample__ColorObject__

#include <stdio.h>
#include "ofMain.h"
#include "Object.h"
class Cone:public Object{
    
public:
    Cone();
    void init(ofPoint pos);
    void update();
    void draw();
    void setPos(ofPoint pos);
    ofPoint getPos();
    
private:
    
    int startTime = 0;
    int frameNum;
    bool once;
    
    ofConePrimitive cone;//cone
    ofPoint pos;
    ofMesh mesh;
    ofImage myImage;
};
#endif /* defined(__emptyExample__ColorObject__) */
