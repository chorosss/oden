//
//  Square.cpp
//  emptyExample
//
//  Created by 大林巧 on 2017/01/20.
//
//

#include "Square.h"

Square::Square(){
    pos = ofPoint(150,0,0);
}

void Square::init(){
    
    myImage.loadImage("test.jpg");
    
    mesh.addVertex(ofVec3f(100,100,0));
    mesh.addVertex(ofVec3f(100,200,0));
    mesh.addVertex(ofVec3f(200,200,0));
    mesh.addVertex(ofVec3f(200,100,0));
    mesh.addVertex(ofVec3f(150,150,100));
    
    mesh.addTexCoord( ofVec3f(100,100,0) );
    mesh.addTexCoord( ofVec3f(100,200,0) );
    mesh.addTexCoord( ofVec3f(200,200,0));
    mesh.addTexCoord( ofVec3f(200,100,0));
    mesh.addTexCoord( ofVec3f(150,150,100));
    
     mesh.setMode(OF_PRIMITIVE_TRIANGLES);

    mesh.addIndex(0);
    mesh.addIndex(1);
    mesh.addIndex(2);
    mesh.addIndex(0);
    mesh.addIndex(3);
    mesh.addIndex(2);
    mesh.addIndex(0);
    mesh.addIndex(4);
    mesh.addIndex(1);
    mesh.addIndex(0);
    mesh.addIndex(3);
    mesh.addIndex(4);
    mesh.addIndex(3);
    mesh.addIndex(2);
    mesh.addIndex(4);
    mesh.addIndex(1);
    mesh.addIndex(2);
    mesh.addIndex(4);


}

void Square::draw(){
    ofPushMatrix();
    ofTranslate(300, 300,100);
    ofSetColor( 255, 255, 255 );
    myImage.bind();
    mesh.draw();
    myImage.unbind();
    ofPushMatrix();
    ofTranslate(100, 100,100);
    ofSetLineWidth(1);
    mesh.drawWireframe();
    ofPopMatrix();
    ofPopMatrix();

    
}

void Square::setPos(ofPoint _pos){
    pos = _pos;
}

ofPoint Square::getPos(){
    return pos;
}

