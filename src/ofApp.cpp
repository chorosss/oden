#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    angle = 0;
    camDistance = 1200.0f;
    
    ofSetLogLevel(OF_LOG_VERBOSE);
    ofDisableArbTex(); // we need GL_TEXTURE_2D for our models coords.

    
    ofBackground(0, 180, 0);
    ofEnableDepthTest();
    ofEnableSmoothing();
    
    light.enable();
    light.setSpotlight();
    light.setPosition(-100, 100, 100);
    light.setAmbientColor(ofFloatColor(.7,1,1,0.0));
    light.setDiffuseColor(ofFloatColor(.2,0,0));
    light.setSpecularColor(ofFloatColor(0,0,0));
    ofSetFrameRate(60);

//    std::cout << "value: " << test << endl;
    
    current = ofPoint(250,0,0);
    
    Mysquare.init();
    
    //texture
    myImage.loadImage("texture01.jpg");
    
    //3dmodel
    squirrelModel.loadModel("testPoly/testPoly.3ds", 30);
    squirrelModel.setRotation(1, 270, 0, 0, 1);
    squirrelModel.setScale(0.9, 0.9, 0.9);
    squirrelModel.setPosition(0, 0, 0);
    
    animationPosition = 0;
    
    model.loadModel("testPoly2/testPoly.dae", true);
    model.setScale(0.5, 0.5, 0.5);
    model.setPosition(100, 100, 0);
    model.setLoopStateForAllAnimations(OF_LOOP_NORMAL);
    model.playAllAnimations();
    
    tex.allocate(400,400,GL_RGB);


    // GUIを設定
    gui.setup();
    gui.add(distance.setup("distance", 1200, 0, 3800));
    gui.add(volume.setup("volume", 0, 0, 1));
 }

//--------------------------------------------------------------
void ofApp::update(){
    
    mySound.setVolume(volume); //サウンド再生開始
    float * val = ofSoundGetSpectrum(1); //再生中のサウンドの音量を取得
    boxSize = val[0] * 1000.0; //円の半径に適用
    
    model.update();
    mesh = model.getCurrentAnimatedMesh(0);
    
    
    for(int i = 0; i < Spheres.size();i++){
        Spheres[i].update();
    }
    for(int i = 0; i < Cylinders.size();i++){
        Cylinders[i].update();
    }
    for(int i = 0; i < Cones.size();i++){
        Cones[i].update();
    }
    for(int i = 0; i < Boxes.size();i++){
        Boxes[i].update();
    }
    for(int i = 0; i < Plates.size();i++){
        Plates[i].update();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    glEnable(GL_DEPTH_TEST);
    cam.begin();
    ofSetColor(255);
    
    ofVec3f camPos = current;
    
    cam.setTarget(camPos);
    cam.setDistance(distance);
    
    Mysquare.draw();
    
    for(int i = 0; i < Spheres.size();i++){
        Spheres[i].draw(boxSize);
    }

    for(int i = 0; i < Cylinders.size();i++){
        Cylinders[i].draw(boxSize);
    }
    
    for(int i = 0; i < Cones.size();i++){
        Cones[i].draw();
    }
    for(int i = 0; i < Boxes.size();i++){
        Boxes[i].draw();
    }
    for(int i = 0; i < Plates.size();i++){
        Plates[i].draw();
    }


    //bar
    ofSetColor(255, 255, 255);
    ofSetLineWidth(30);
    ofLine(150, 0, 0, 15000, 0, 0);
    
    //3d model
    //ofSetColor(255, 0, 0, 255);
    
    tex = myImage.getTextureReference();
    tex.bind();
    squirrelModel.draw();
    
    tex.unbind();
    tex = myImage.getTextureReference();
    tex.bind();
    model.drawFaces();
    tex.unbind();
    
    cam.end();

    // GUIを表示
    glDisable(GL_DEPTH_TEST);
    gui.draw();
    ofSetHexColor(0x000000);
    ofDrawBitmapString("fps: "+ofToString(ofGetFrameRate(), 2), 10, 15);
    ofDrawBitmapString("num animations for this model: " + ofToString(model.getAnimationCount()), 10, 260);
    
    
}


void ofApp::keyPressed  (int key){
    //キー入力でモード切り替え
    switch (key){
        case 'a':
        {
            ofPoint prev = current;
            ofPoint next = ofPoint(prev.x + 200,0,0);
            
            Sphere s;
            s.init(next);
            Spheres.push_back(s);
            
            current = next;
            break;
        }
            
        case 's':
        {
            ofPoint prev = current;
            ofPoint next = ofPoint(prev.x + 200,0,0);
            
            Cylinder c;
            c.init(next);
            Cylinders.push_back(c);
            
            current = next;
            break;
        }
        case 'd':
        {
            ofPoint prev = current;
            ofPoint next = ofPoint(prev.x + 200,0,0);
            
            Cone cone;
            cone.Object::setPos(next);
            cone.init(next);
            Cones.push_back(cone);
            
            current = next;
            break;
        }
        case 'f':
        {
            ofPoint prev = current;
            ofPoint next = ofPoint(prev.x + 200,0,0);
            
            Box b;
            b.Object::setPos(next);
            b.init(next);
            Boxes.push_back(b);
            
            current = next;
            break;
        }
        case 'g':
        {
            ofPoint prev = current;
            ofPoint next = ofPoint(prev.x + 200,0,0);
            
            Plate p;
            p.Object::setPos(next);
            p.init(next);
            Plates.push_back(p);
            
            current = next;
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
    // pause all animations, so we can scrub through them manually.
    //model.setPausedForAllAnimations(true);
    animationPosition = y / (float)ofGetHeight();

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