#pragma once

#include "ofMain.h"
#include "SoundBug.h"
#include "ofxGui.h"
#include "ofxOsc.h"

#define PORT 7400
#define NUM_MSG_STRINGS 20

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void audioIn(float * input, int bufferSize, int nChannels);
    
    
    static const int NUM = 20000;
    SoundBug agents[NUM];
    int agentsCount = 4000;
    int drawMode = 1;
    
    
    ofxPanel gui;
    ofxFloatSlider noiseScale;
    ofxFloatSlider noiseStrength;
    ofxFloatSlider noiseZRange;
    ofxFloatSlider overlayAlpha;
    ofxFloatSlider agentsAlpha;
    ofxFloatSlider strokeWidth;
    ofxFloatSlider stepScale;
    
    
    
    // soundStream setting
    vector <float> left;
    vector <float> right;
    vector <float> volHistory;
    
    int 	bufferCounter;
    int 	drawCounter;
    
    float smoothedVol;
    float scaledVol;
    float kickVol;
    ofSoundStream soundStream;
    
    
    // osc setting
    ofTrueTypeFont font;
    ofxOscReceiver receiver;
    
    int current_msg_string;
    string msg_strings[NUM_MSG_STRINGS];
    float timers[NUM_MSG_STRINGS];
    
    int mouseX, mouseY;
    string mouseButtonState;
    
    ofImage receivedImage;
};
