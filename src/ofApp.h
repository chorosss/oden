#pragma once

#include "ofMain.h"
//Addon
#include "ofx3DModelLoader.h"
#include "ofxGui.h"
//Class
#include "Object.h"
#include "Cylinder.h"
#include "Sphere.h"
#include "Square.h"
#include "Cone.h"
#include "Box.h"
#include "Plate.h"



class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    float boxSize;
    int w,h;
    float angle;
    float camDistance;
    ofPoint current;
    
    //premitive
    ofBoxPrimitive box;
    ofSpherePrimitive sphere;
    ofMesh mesh;
    ofEasyCam cam;
    ofLight light;
    
    //modelTest
    ofx3DModelLoader squirrelModel;
    
    //texture
    ofImage myImage;
    ofTexture tex;
    
    
    //sound
    ofSoundPlayer mySound;
    ofSoundPlayer mySound_2;
    
 
    //object
    vector <Sphere> Spheres;
    vector <Cylinder> Cylinders;
    vector <Cone> Cones;
    vector <Box> Boxes;
    vector <Plate> Plates;
    Square Mysquare;
    
    // GUI para
    ofxPanel gui;
    ofxFloatSlider distance;
    ofxFloatSlider volume;
    ofxColorSlider color;
    ofxVec2Slider position;
    ofxFloatSlider frameRate;
};
