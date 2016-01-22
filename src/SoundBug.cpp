//
//  SoundBug.cpp
//  SoundBugs
//
//  Created by Â≤©ÂüéÂãáÁ£® on 1/2/16.
//
//

#include "SoundBug.h"

SoundBug::SoundBug() {
    
}

void SoundBug::setNoiseZrange(float theNoiseZRange) {
    noiseZ = ofRandom(theNoiseZRange);
}

void SoundBug::setup() {
    noiseZVelocity = 0.01;
    p = ofVec3f(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()),0);
    pOld = ofVec3f(p.x,p.y,p.z);
    stepSize = ofRandom(1.0,5.0);
    //stepSize = 10;
    // init noiseZ
    setNoiseZrange(0.4);
    
    lifeTime = 10.0;
    lifeSpeed = 0.01;
}

void SoundBug::update1(float noiseScale, float noiseStrength, float _strokeWidth, float _stepScale) {
    
    pOld=p;
    noiseZ += noiseZVelocity;
    
    strokeWidth = _strokeWidth;
    angle = ofNoise(p.x/noiseScale, p.y/noiseScale, noiseZ) * noiseStrength;
    
    p.x += cos(angle) * stepSize*_stepScale;
    p.y += sin(angle) * stepSize*_stepScale;
    
    if (p.x<-10) p.x=pOld.x=ofGetWidth()+10;
    if (p.x>ofGetWidth()+10) p.x=pOld.x=-10;
    if (p.y<-10) p.y=pOld.y=ofGetHeight()+10;
    if (p.y>ofGetHeight()+10) p.y=pOld.y=-10;
    
    
    
    
}

void SoundBug::update2(float noiseScale, float noiseStrength, float _strokeWidth) {
    strokeWidth = _strokeWidth;
    angle = ofNoise(p.x/noiseScale ,p.y/noiseScale, noiseZ) * 24;
    angle = (angle - int(angle)) * noiseStrength;
    
    p.x += cos(angle) * stepSize;
    p.y += sin(angle) * stepSize;
    
    // offscreen wrap
    if (p.x<-10) p.x=pOld.x=ofGetWidth()+10;
    if (p.x>ofGetWidth()+10) p.x=pOld.x=-10;
    if (p.y<-10) p.y=pOld.y=ofGetHeight()+10;
    if (p.y>ofGetHeight()+10) p.y=pOld.y=-10;
    
    //ofSetLineWidth(strokeWidth*stepSize);
    //ofDrawLine(pOld.x,pOld.y, p.x,p.y);
    
    pOld.set(p);
    noiseZ += noiseZVelocity;
}

void SoundBug::draw() {
    //cout << "width :" << strokeWidth*stepSize << endl;
    //cout << "p :" << p << endl;
    ofSetColor(10,10,10);
    ofSetLineWidth(strokeWidth*stepSize);
    ofDrawLine(pOld.x,pOld.y, p.x,p.y);
    //ofDrawCircle(p.x, p.y, strokeWidth);
    //ofDrawLine(pOld.x,pOld.y, ofGetWidth(),ofGetHeight());
    //ofDrawCircle(p, 10);
    //ofDrawCircle(100, 100, 100);
}