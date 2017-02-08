#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    sounds[0].load("snare.wav");
    sounds[1].load("hihat.wav");
    sounds[2].load("horn.wav");
    sounds[3].load("wilhem.wav");
    sounds[4].load("beast.wav");
    sounds[5].load("reverse.wav");
    sounds[6].load("synth.wav");
    sounds[7].load("soda.wav");
    for(int i = 0; i < 8; i++) {
        sounds[i].setMultiPlay(true);
    }
    ofSetBackgroundColor(255);
    int bufferSize = 256;
    soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
}
//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    //RMS Algorithm. Get loudness of input.
    
    float rms = 0.0;
    int numCounted = 0;
    for (int i = 0; i < bufferSize; i++) {
        float leftSample = input[i * 2] * .5;
        float rightSample = input[i * 2 + 1] * .5;
        rms += leftSample * leftSample;
        rms += rightSample * rightSample;
        numCounted += 2;
    }
    
    rms /= (float)numCounted;
    rms = sqrt(rms);
    loudness = rms;
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetBackgroundColor(255);
    if(sounds[0].isPlaying()) {
        ofSetBackgroundColor(0);
    }
    if(sounds[1].isPlaying()) {
        ofSetBackgroundColor(0);
    }
    if(sounds[2].isPlaying()) {
        ofSetBackgroundColor(0);
    }
    if(sounds[3].isPlaying()) {
        ofSetBackgroundColor(0);
    }
    if(sounds[4].isPlaying()) {
        ofSetBackgroundColor(0);
    }
    if(sounds[5].isPlaying()) {
        ofSetBackgroundColor(0);
    }
    if(sounds[6].isPlaying()) {
        ofSetBackgroundColor(0);
    }
    if(sounds[7].isPlaying()) {
        ofSetBackgroundColor(0);
    }
    //for loop only changes background color for last element viewed
//    for(int i = 8; i > 0; i--) {
//        int soundsPlaying = 0;
//        if(sounds[i-1].isPlaying()) {
//            soundsPlaying++;
//        }
//        if(soundsPlaying == 0){
//            ofSetBackgroundColor(255);
//        }else{
//            ofSetBackgroundColor(0);
//        }
//    }
}
//--------------------------------------------------------------
void ofApp::draw(){
    for(int i = 0; i < 8; i++) {
        if(sounds[i].isPlaying()) {
            ofFill();
            ofSetColor(0,255,0);
            float curPos = i + (i * (ofGetWidth()/10));
            ofDrawCircle((i*ofGetWidth()/8+ofGetWidth()/16), ofGetHeight()*0.75+ofMap(sounds[i].getPosition(), 1, 0, 0, ofGetHeight()/8), 10);
        }else {
            ofSetColor(255, 0, 0);
            ofNoFill();
            for(int i = 0; i < 8; i++) {
                if(!sounds[i].isPlaying()){
                    float curPos = i + (i * (ofGetWidth()/10));
                    ofDrawCircle((i*ofGetWidth()/8+ofGetWidth()/16), ofGetHeight()*0.9, 10);
                }
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == '1') {
        sounds[0].play();
    }
    if(key == '2') {
        sounds[1].play();
    }
    if(key == '3') {
        sounds[2].play();
    }
    if(key == '4') {
        sounds[3].play();
    }
    if(key == '5') {
        sounds[4].play();
    }
    if(key == '6') {
        sounds[5].play();
    }
    if(key == '7') {
        sounds[6].play();
    }
    if(key == '8') {
        sounds[7].play();
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
