//
//  Square.cpp
//  emptyExample
//
//  Created by 大林巧 on 2017/01/20.
//
//

#include "Square.h"

Square::Square(){
}

void Square::init(){
    pos = ofPoint(-150,0,0);
    
    myImage.loadImage("texture07.png");

//testPoly
    mesh.addVertex(ofVec3f(0.194994 ,-0.968873 ,-6.312304));
    mesh.addVertex(ofVec3f(-1.472353 ,-1.399229 ,-2.985683));
    mesh.addVertex(ofVec3f(-3.329753 ,-1.299885 ,-3.313952));
    mesh.addVertex(ofVec3f(-3.045809 ,-1.037619 ,-5.593700));
    
    mesh.addVertex(ofVec3f(-1.515894 ,1.791104 ,-4.092675));
    mesh.addVertex(ofVec3f(-0.837049 ,1.173553 ,-3.436670));
    mesh.addVertex(ofVec3f(-3.256200 ,1.311775 ,-3.356315));
    mesh.addVertex(ofVec3f(-3.023315 ,1.019421 ,-5.561774));

//square
//    mesh.addVertex(ofVec3f(1.000000 ,-1.000000 ,-1.000000));
//    mesh.addVertex(ofVec3f(1.000000 ,-1.000000 ,1.000000));
//    mesh.addVertex(ofVec3f(-1.000000 ,-1.000000 ,1.000000));
//    mesh.addVertex(ofVec3f(-1.000000 ,-1.000000 ,-1.000000));
//    
//    mesh.addVertex(ofVec3f(1.000000 ,1.000000 ,-0.999999));
//    mesh.addVertex(ofVec3f(0.999999 ,1.000000 ,1.000001));
//    mesh.addVertex(ofVec3f(-1.000000 ,1.000000 ,1.000000));
//    mesh.addVertex(ofVec3f(-1.000000 ,1.000000 ,-1.000000));

    
    
//    mesh.addVertex(ofVec3f(100,100,0));
//    mesh.addVertex(ofVec3f(100,200,0));
//    mesh.addVertex(ofVec3f(200,200,0));
//    mesh.addVertex(ofVec3f(200,100,0));
//    mesh.addVertex(ofVec3f(150,150,100));
//    
//    mesh.addTexCoord( ofVec3f(100,100,0) );
//    mesh.addTexCoord( ofVec3f(100,200,0) );
//    mesh.addTexCoord( ofVec3f(200,200,0));
//    mesh.addTexCoord( ofVec3f(200,100,0));
//    mesh.addTexCoord( ofVec3f(150,150,100));
    
     mesh.setMode(OF_PRIMITIVE_TRIANGLES);

    for (int i=0; i<=8; i++) {
        for (int k=0; k<=8; k++) {
            for (int j=0; j+1<=8; j++) {
            
            mesh.addIndex(i);
            mesh.addIndex(k);
            mesh.addIndex(j);
            std::cout << "addIndex-i: " << i << endl;
            std::cout << "addIndex-k: " << k << endl;
            std::cout << "addIndex-j: " << j << endl;
            }
        }
    }

  

    
//    for (int i=0; i<9; i++) {
//        mesh.addIndex(i);
//        mesh.addIndex(i+1);
//        mesh.addIndex(i+2);
//    
//    }
//

    
//    mesh.addIndex(0);
//    mesh.addIndex(0);
//    mesh.addIndex(1);
//    
//    mesh.addIndex(0);
//    mesh.addIndex(1);
//    mesh.addIndex(2);
//    
//    mesh.addIndex(0);
//    mesh.addIndex(2);
//    mesh.addIndex(3);
    
    
//
//    mesh.addIndex(0);
//    mesh.addIndex(3);
//    mesh.addIndex(2);
//    
//    mesh.addIndex(0);
//    mesh.addIndex(4);
//    mesh.addIndex(1);
//    
//    mesh.addIndex(0);
//    mesh.addIndex(3);
//    mesh.addIndex(4);
//    
//    mesh.addIndex(0);
//    mesh.addIndex(4);
//    mesh.addIndex(5);
//    
//    mesh.addIndex(0);
//    mesh.addIndex(4);
//    mesh.addIndex(6);
//    
//    mesh.addIndex(0);
//    mesh.addIndex(6);
//    mesh.addIndex(7);
//    
//    mesh.addIndex(1);
//    mesh.addIndex(2);
//    mesh.addIndex(3);
//    
//    mesh.addIndex(1);
//    mesh.addIndex(3);
//    mesh.addIndex(4);
//    
//    mesh.addIndex(1);
//    mesh.addIndex(4);
//    mesh.addIndex(5);
//    
//    mesh.addIndex(1);
//    mesh.addIndex(5);
//    mesh.addIndex(6);
//    
//    mesh.addIndex(1);
//    mesh.addIndex(6);
//    mesh.addIndex(7);
//    
//    mesh.addIndex(3);
//    mesh.addIndex(2);
//    mesh.addIndex(4);
//    
//    mesh.addIndex(1);
//    mesh.addIndex(2);
//    mesh.addIndex(4);
//    
//    mesh.addIndex(7);
//    mesh.addIndex(0);
//    mesh.addIndex(1);
//    
//    mesh.addIndex(7);
//    mesh.addIndex(1);
//    mesh.addIndex(2);
//    
//    mesh.addIndex(7);
//    mesh.addIndex(2);
//    mesh.addIndex(3);
//    
//    mesh.addIndex(7);
//    mesh.addIndex(3);
//    mesh.addIndex(4);
//    
 

}

void Square::draw(){
    //std::cout << "square draw "<< endl;
    ofPushMatrix();
    ofTranslate(100, 100,100);
    ofSetColor( 255,255, 0 );
    //myImage.getTextureReference().bind();
    
    //v
//    ofLine(194.994 ,-968.873 ,-631.2304,-302.3315 ,101.9421 ,-556.1774);
//    ofLine(-147.2353 ,-139.9229 ,-298.5683,-325.6200 ,131.1775 ,-335.6315);
//    ofLine(-3.329753 ,-1.299885 ,-3.313952,-3.045809 ,-1.037619 ,-5.593700);
//    ofLine(-1.515894 ,1.791104 ,-4.092675,-0.837049 ,1.173553 ,-3.436670);
//    ofLine(-3.256200 ,1.311775 ,-3.356315,-3.023315 ,1.019421 ,-5.561774);
    
    //vn
//    ofLine(-0.0158, -0.9916, -0.1280,-3.023315 ,1.019421 ,-5.561774);
//    ofLine(-0.0158, -0.9916, -0.1280,-0.2065 ,0.9681 ,0.1422);
//    ofLine(0.9583 ,0.1052, 0.2655,-0.2065 ,0.9681 ,0.1422);
//    ofLine(0.9583 ,0.1052, 0.2655,0.0635 ,0.4408 ,-0.8954);
    ofScale(20,20,20);
    mesh.draw();
    //myImage.unbind();
    ofPushMatrix();
    //ofTranslate(100, 100,100);
    ofSetLineWidth(1);
    ofSetColor( 255, 0, 255 );
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

