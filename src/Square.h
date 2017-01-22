//
//  Square.h
//  emptyExample
//
//  Created by 大林巧 on 2017/01/20.
//
//

#ifndef __emptyExample__Square__
#define __emptyExample__Square__

#include "ofMain.h" //ofMain.hをインクルード

class Square {
public:
    Square();
    void init();
    void draw();
    void setPos(ofPoint pos);
    ofPoint getPos();
    
private:
    ofPoint pos;
    ofMesh mesh;
    ofImage myImage;

};
#endif /* defined(__emptyExample__Square__) */