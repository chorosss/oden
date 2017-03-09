#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    angle = 0;
    camDistance = 1200.0f;
    
    map_x = 270;
    map_y = 180;
    
    sphereSize = 10;

    
    ofBackground(255, 118, 118);
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
    
    current = ofPoint(0,0,0);
    
    Mysquare.init();
    
    //texture
    myImage.loadImage("noise.png");
    
    
    //texturePlane
    
    texturePlane.set(100,100);
    
    //3dmodel
    squirrelModel.loadModel("testPoly/testPoly.3ds", 30);
    squirrelModel.setRotation(1, 270, 0, 0, 1);
    squirrelModel.setScale(0.9, 0.9, 0.9);
    squirrelModel.setPosition(0, 0, 0);
    
    // GUIを設定
    gui.setup();
    gui.add(distance.setup("distance", 1200, 0, 3800));
    gui.add(volume.setup("volume", 0, 0, 1));
    gui.add(sphereSize.setup("sphereSize", 10, 0, 100));
    gui.add(map_x.setup("map_x", 360, 0, 1800));
    gui.add(map_y.setup("map_y", 360, 0, 1800));
    gui.add(rotateX.setup("rotateX", 0, 0, 360));

 }

//--------------------------------------------------------------
void ofApp::update(){
    
    mySound.setVolume(volume); //サウンド再生開始
    float * val = ofSoundGetSpectrum(1); //再生中のサウンドの音量を取得
    boxSize = val[0] * 1000.0; //円の半径に適用
    
    //background
    texturePlane.set(sphereSize,sphereSize);

    
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
    
    ofVec3f camDir = cam.getLookAtDir();
    double angle = (180 * acos(camDir.x)) / PI;
    
    ofSetColor(255);
    
    ofVec3f targetPos = current;
    ofVec3f camAxis = cam.getXAxis();
    ofVec3f camAngle = cam.getLookAtDir();
    
    cam.setTarget(targetPos);
    cam.setDistance(distance);
    
    ofVec3f camPos = cam.getPosition();
    
    Mysquare.draw();
    
    std::cout << "LookAtDir: " << cam.getLookAtDir() << endl;
    std::cout << "position: " << camPos << endl;

    
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
    ofSetLineWidth(10);
    ofLine(0, -300, 0, 0, 1000, 0);
    
    
    //x軸
    ofSetColor(255, 0, 0);
    ofSetLineWidth(1);
    ofLine(-1000, 0, 0, 1000,0, 0);
    
    //y軸
    ofSetColor(0, 255, 0);
    ofSetLineWidth(1);
    ofLine(0, -1000, 0, 0,1000, 0);
    
    //z軸
    ofSetColor(0, 0, 255);
    ofSetLineWidth(1);
    ofLine(0, 0, -1000, 0,0, 1000);


    
    
    //3d model
    ofSetColor(255, 216, 120, 255);
    squirrelModel.draw();
    
    //AxisTest
    ofSetColor(255, 255, 255);
    ofSetLineWidth(100);
    //    ofLine(camPos.x,camPos.y,camPos.z, camAxis.x+10, camAxis.y+10, camAxis.z+10);
    ofLine(camPos.x,camPos.y,camPos.z-1, current.x, current.y, current.z);

    
    //background
    ofSetColor(255, 255, 255,255);
    
    ofPushMatrix();
    
    ofTranslate(camPos.x,camPos.y,camPos.z-10);
    ofRotateY(rotateX);
    texturePlane.setPosition(0,0,0);
    texturePlane.mapTexCoords(0, 0, map_x, map_y);
    myImage.getTextureReference().bind();
    texturePlane.draw();
    myImage.getTextureReference().unbind();

    ofPopMatrix();
    
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
            ofPoint next = ofPoint(0,prev.y +200,0);
            
            Sphere s;
            s.init(next);
            Spheres.push_back(s);
            
            current = next;
            break;
        }
            
        case 's':
        {
            ofPoint prev = current;
            ofPoint next = ofPoint(0,prev.y +200,0);
            
            Cylinder c;
            c.init(next);
            Cylinders.push_back(c);
            
            current = next;
            break;
        }
        case 'd':
        {
            ofPoint prev = current;
            ofPoint next = ofPoint(0,prev.y +200,0);
            
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
            ofPoint next = ofPoint(0,prev.y +200,0);
            
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
            ofPoint next = ofPoint(0,prev.y +200,0);
            
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