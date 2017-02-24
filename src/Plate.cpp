//
//  Plate.cpp
//  emptyExample
//
//  Created by 大林巧 on 2017/02/17.
//
//

#include "Plate.h"

Plate::Plate(){

}

void Plate::init(ofPoint _pos){
    pos = _pos;
    Object::init();
    Object::setMusic(int(ofRandom(5, 6)));
    meshWidth =  100;
    meshHeight = 100;
    meshDepth = 150;
    myImage.loadImage("texture01.jpg");
    
    mesh.addVertex(ofVec3f(-meshWidth,-meshHeight,0));
    mesh.addVertex(ofVec3f(-meshWidth,meshHeight,0));
    mesh.addVertex(ofVec3f(meshWidth,meshHeight,0));
    mesh.addVertex(ofVec3f(meshWidth,-meshHeight,0));
    mesh.addVertex(ofVec3f(0,0,meshDepth));

    
    mesh.addTexCoord( ofVec3f(0,0,0) );
    mesh.addTexCoord( ofVec3f(150,150,0) );
    mesh.addTexCoord( ofVec3f(100,100,0));
    mesh.addTexCoord( ofVec3f(100,150,0));
    mesh.addTexCoord( ofVec3f(100,100,150));

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
void Plate::update(){

        Object::update();
        counter = Object::getCounter();
        angle = Object::getAngle();
    
}

void Plate::draw(){
    
    Object::draw();
    ofPushMatrix();
    ofTranslate(pos);
    ofRotateY(90);
    
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
