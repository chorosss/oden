#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    angle = 0;
    camDistance = 1200.0f;
    
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
    
    current = ofPoint(250,0,0);

    
    //cylinder
    Cylinder c;
    c.setMusic(int (ofRandom(1,3)));
    c.setPos(ofPoint(250,0,0));
    c.init();
    Cylinders.push_back(c);
    
    //sphere
    MySphere s;
    s.setMusic(int(ofRandom(4, 6)));
    s.setPos(ofPoint(150,0,0));
    s.init();
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
    
    // colorの初期値、最小値、最大値を設定
    ofColor initColor = ofColor(0, 127, 255, 255);
    ofColor minColor = ofColor(0,0,0,0);
    ofColor maxColor = ofColor(255,255,255,255);
    
    // positionの初期値、最小値、最大値を設定
    ofVec2f initPos = ofVec2f(ofGetWidth()/2, ofGetHeight()/2);
    ofVec2f minPos = ofVec2f(0, 0);
    ofVec2f maxPos = ofVec2f(ofGetWidth(), ofGetHeight());
    
    // GUIを設定
    gui.setup();
    gui.add(distance.setup("distance", 1200, 0, 3800));
    gui.add(volume.setup("volume", 0, 0, 1));
 }

//--------------------------------------------------------------
void ofApp::update(){
    mySquare.init();
    
    mySound.setVolume(volume); //サウンド再生開始
    float * val = ofSoundGetSpectrum(1); //再生中のサウンドの音量を取得
    boxSize = val[0] * 1000.0; //円の半径に適用
    
    
    for(int i = 0; i < MySpheres.size();i++){
        MySpheres[i].update();
    }
    for(int i = 0; i < Cylinders.size();i++){
        Cylinders[i].update();
    }
    
    angle += 0.03f;
    
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
    glEnable(GL_DEPTH_TEST);
    cam.begin();
    ofSetColor(255);
    
    mySquare.draw();
    
    ofVec3f camPos = MySpheres.back().getPos();
    
    cam.setTarget(mySquare.getPos());
    cam.setDistance(distance);
    
    //cam.setTarget(camPos);
    //cam.setDistance(camDistance);
    //cam.setPosition(camPos.x + 1000+ABS(sin(angle))*100 ,camPos.y +1000 ,camPos.z + 1000+ABS(sin(angle))*100);
    
    // 頂点の位置をドットで表示
//    glPointSize(12.0);
//    glEnable(GL_POINT_SMOOTH);
//    mesh.addColor(ofFloatColor(0, 0, 0));
//    mesh.drawVertices();
//    mesh.drawWireframe();

    
    //box
    box.set(100);
    box.setPosition(-150, 0, 0);
    box.rotate(sin(angle),10,10,10);
    ofSetColor(0, 0, 0);
    box.draw();
    ofSetColor(255, 255, 255);
    ofSetLineWidth(1);
    box.drawWireframe();
    
    for(int i = 0; i < MySpheres.size();i++){
        MySpheres[i].draw(boxSize);
    }

    for(int i = 0; i < Cylinders.size();i++){
        Cylinders[i].draw();
    }

    
    //bar
    ofSetColor(255, 255, 255);
    ofSetLineWidth(30);
    ofLine(150, 0, 0, 15000, 0, 0);
    cam.end();

    // GUIを表示
    glDisable(GL_DEPTH_TEST);
    gui.draw();
    
    
}


void ofApp::keyPressed  (int key){
    //キー入力でモード切り替え
    switch (key){
        case 'a':
        {
            ofPoint prev = current;
            MySphere s;
            s.setMusic(int(ofRandom(1, 6)));
            s.setPos(ofPoint(prev.x + 200,0,0));
            s.init();
            MySpheres.push_back(s);

            break;
        }
            
        case 's':
        {
            ofPoint prev = current;
            Cylinder c;
            c.setMusic(int(ofRandom(1, 3)));
            c.setPos(ofPoint(prev.x + 200,0,0));
            c.init();
            Cylinders.push_back(c);
            break;
        }
    }
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