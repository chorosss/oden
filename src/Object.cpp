//
//  Object.cpp
//  emptyExample
//
//  Created by 大林巧 on 2017/01/30.
//
//
#include "ofMain.h"
#include "Object.h"

Object::Object(){
    pos = ofPoint(100,0,0);
  }

void Object::init(float _x,float _y){
    
    x = _x;
    y = _y;
    myImage.loadImage("texture01.jpg");
    
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
void Object::draw(){
    ofPushMatrix();
    ofTranslate(x,y,100);
    ofSetColor( 255, 255, 255 );
    myImage.getTextureReference().bind();
    mesh.draw();
    myImage.unbind();
    ofPushMatrix();
    ofTranslate(100, 100,100);
    ofSetLineWidth(1);
    mesh.drawWireframe();
    ofPopMatrix();
    ofPopMatrix();
    
    
}

void Object::setPos(ofPoint _pos){
    pos = _pos;
}

ofPoint Object::getPos(){
    return pos;
}

int Object::testFunction(){
    return 1;
}
