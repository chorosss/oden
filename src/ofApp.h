#pragma once

#include "ofMain.h"
#include "MySphere.h"
#include "Square.h"

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
    
    ofBoxPrimitive box; // 立方体プリミティブ
    ofSpherePrimitive sphere; // 球プリミティブ
    ofMesh mesh;
    ofEasyCam cam;
    ofLight light;
    
    ofImage myImage;
    
    int w,h;
    
    float angle;
    
    float camDistance;
    
    vector <MySphere> MySpheres;
    Square mySquare;
};
