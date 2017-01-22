#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    angle = 0;
    camDistance = 1200.0f;
    
    ofEnableDepthTest();
    
    ofBackground(0, 180, 0);
    ofEnableDepthTest();
    ofEnableSmoothing();
    
    light.enable();
    light.setSpotlight();
    light.setPosition(-100, 100, 100);
    light.setAmbientColor(ofFloatColor(.7,1,1,0.0));
    light.setDiffuseColor(ofFloatColor(.2,0,0));
    light.setSpecularColor(ofFloatColor(0,0,0));
        ofSetFrameRate(60); // if vertical sync is off, we can go a bit fast... this caps the framerate at 60fps.
    
    Square mySquare;
    
    MySphere s;
    s.setPos(ofPoint(150,0,0));
    MySpheres.push_back(s);
    
    // メッシュの幅と高さ
    w = 200;
    h = 200;
    
    // 頂点の色を初期化
    for (int i = 0; i < w; i+=10) {
        for (int j = 0; j < h; j+=10) {
            mesh.addColor(ofFloatColor(0, 0, 1.0));
        }
    }
    
    myImage.loadImage("test.jpg");
}

//--------------------------------------------------------------
void ofApp::update(){
    mySquare.init();
    
    
    for(int i = 0; i < MySpheres.size();i++){
        MySpheres[i].update();
    }
    angle += 0.03f;
    //camDistance += sin(angle)*10;
    
    // まず全ての頂点情報を削除
    mesh.clearVertices();
    
    // 全ての頂点の位置を更新して頂点情報として追加
    for (int i = 0; i < w; i+=10) {
        for (int j = 0; j < h; j+=10) {
            float x = sin(i * 0.1 + ofGetElapsedTimef())*10.0;
            float y = sin(j*0.15 + ofGetElapsedTimef()) * 10.0;
            float z = x + y;
            mesh.addVertex(ofVec3f(i - w/2, j - h/2, z));
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    ofSetColor(255);
    
    mySquare.draw();
    
    ofVec3f camPos = MySpheres.back().getPos();
    
    cam.setTarget(mySquare.getPos());
    cam.setDistance(1200);
    
    //cam.setTarget(camPos);
    //cam.setDistance(camDistance);
    //cam.setPosition(camPos.x + 1000+ABS(sin(angle))*100 ,camPos.y +1000 ,camPos.z + 1000+ABS(sin(angle))*100);
    
    // 頂点の位置をドットで表示
//    glPointSize(12.0);
//    glEnable(GL_POINT_SMOOTH);
//    mesh.addColor(ofFloatColor(0, 0, 0));
//    mesh.drawVertices();
//    mesh.drawWireframe();

    
    
    box.set(200);
    box.setPosition(-150, 0, 0);
    box.rotate(sin(angle),10,10,10);
    ofSetColor(0, 0, 0);
    myImage.getTextureReference().bind();
    box.draw();
    myImage.unbind();
    ofSetColor(255, 255, 255);
    ofSetLineWidth(1);
    box.drawWireframe();
    
    for(int i = 0; i < MySpheres.size();i++){
        MySpheres[i].draw();
    }
    ofSetColor(255, 255, 255);
    ofSetLineWidth(30);
    ofLine(150, 0, 0, 15000, 0, 0);
    cam.end();

    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
   
    

    ofPoint prev = MySpheres.back().getPos();
    MySphere s;
    s.setPos(ofPoint(prev.x + 200,0,0));
    MySpheres.push_back(s);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
   

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}