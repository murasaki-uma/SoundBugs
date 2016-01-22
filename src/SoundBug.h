//
//  SoundBug.h
//  SoundBugs
//
//  Created by 岩城勇磨 on 1/2/16.
//
//

#ifndef SoundBug_h
#define SoundBug_h

#include <stdio.h>
#include "ofMain.h"

class SoundBug {
public:
    SoundBug();
    void setup();
    void update1(float noiseScale, float noiseStrength, float _strokeWidth, float _stepScale);
    void update2(float noiseScale, float noiseStrength, float _strokeWidth);
    void draw();
    void setNoiseZrange(float theNoiseZRange);
    ofVec3f p, pOld;
    float noiseZ,noiseZVelocity;
    float stepSize, angle;
    float strokeWidth;//stepSize;
    float lifeTime;
    float lifeSpeed;
private:
};

#endif /* SoundBug_h */
