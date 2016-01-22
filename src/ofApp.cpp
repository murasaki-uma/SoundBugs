#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    for(int i=0; i<NUM; i++) {
        agents[i].setup();
    }
    ofSetVerticalSync(true);
    ofSetCircleResolution(80);
    
    int bufferSize = 256;
    
    
    left.assign(bufferSize, 0.0);
    right.assign(bufferSize, 0.0);
    volHistory.assign(400, 0.0);
    
    bufferCounter	= 0;
    drawCounter		= 0;
    smoothedVol     = 0.0;
    scaledVol		= 0.0;
    
    soundStream.setup(this, 0, 2, 44100, bufferSize, 4);

    /*
     float noiseScale = 100;
     float noiseStrength = 10;
     float noiseZRange = 0.4;
     float overlayAlpha = 10;
     float agentsAlpha = 90;
     float strokeWidth = 0.3;
     */
    
    gui.setup(); // most of the time you don't need a name
    gui.add(noiseScale.setup("noiseScale", 100.0, -500.0, ofGetWidth()));
    gui.add(noiseStrength.setup("noiseStrength", 10.0, -30.0, 30.0));
    gui.add(noiseZRange.setup("noiseZRange", 0.4, -1.0, 1.0));
    gui.add(overlayAlpha.setup("overlayAlpha", 10.0, -20.0, 20.0));
    gui.add(agentsAlpha.setup("agentsAlpha", 90.0, 0.0, 255.0));
    gui.add(strokeWidth.setup("strokeWidth", 0.3, -10.0, 10.0));
    gui.add(stepScale.setup("stepScale", 1.0, 0.0, 10.0));
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i=0; i<NUM; i++) {
        //agents[i] = new SoundBug();
        agents[i].update1(noiseScale, noiseStrength, strokeWidth, stepScale*scaledVol);
        }
    
    
    cout << scaledVol << endl;
    //lets scale the vol up to a 0-1 range
    scaledVol = ofMap(smoothedVol, 0.0, 0.1, 1.0, 6.0, true);
    
    //lets record the volume into an array
    volHistory.push_back( scaledVol );
    
    //if we are bigger the the size we want to record - lets drop the oldest value
    if( volHistory.size() >= 400 ){
        volHistory.erase(volHistory.begin(), volHistory.begin()+1);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(240,240,240);
    //ofSetColor(0, 0, 0,alphaStage);
    //ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    //ofSetColor(255, 255, 255, alphaStage);
    for(int i=0; i<NUM; i++) {
        agents[i].draw();
    }
    
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    
    float curVol = 0.0;
    
    // samples are "interleaved"
    int numCounted = 0;
    
    //lets go through each sample and calculate the root mean square which is a rough way to calculate volume
    for (int i = 0; i < bufferSize; i++){
        left[i]		= input[i*2]*0.5;
        right[i]	= input[i*2+1]*0.5;
        
        curVol += left[i] * left[i];
        curVol += right[i] * right[i];
        numCounted+=2;
    }
    
    //this is how we get the mean of rms :)
    curVol /= (float)numCounted;
    
    // this is how we get the root of rms :)
    curVol = sqrt( curVol );
    
    smoothedVol *= 0.93;
    smoothedVol += 0.07 * curVol;
    
    bufferCounter++;
    
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
    if( key == 's' ){
        soundStream.start();
    }
    
    if( key == 'e' ){
        soundStream.stop();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
