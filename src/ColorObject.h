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
class ColorObject:public Object{
    
public:
    void init(float _x,float _y,float _z);
    void draw();
    void setPos(ofPoint pos);
    ofPoint getPos();
    
private:
    
    ofBoxPrimitive box; // 立方体プリミティブ
    ofConePrimitive cone;//cone
    ofPoint pos;
    ofMesh mesh;
    ofImage myImage;
};
#endif /* defined(__emptyExample__ColorObject__) */
