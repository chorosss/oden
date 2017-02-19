//
//  Plate.h
//  emptyExample
//
//  Created by 大林巧 on 2017/02/17.
//
//

#ifndef __emptyExample__Plate__
#define __emptyExample__Plate__

#include <stdio.h>
#include "ofMain.h"
#include "Object.h"
class Plate:public Object{
    
public:
    Plate();
    void init(ofPoint _pos);
    void update();
    void draw();
    void setPos(ofPoint pos);
    ofPoint getPos();
    
    
private:
    
    ofMesh mesh;
    ofPoint pos;
    ofImage myImage;
    float volumeSize;
    int music;
    int meshWidth;
    int meshHeight;
    int meshDepth;
    
    int startTime = 0;
    
    
};

#endif /* defined(__emptyExample__Plate__) */
