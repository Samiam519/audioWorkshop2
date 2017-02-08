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
}

//--------------------------------------------------------------
void ofApp::update(){
    int soundsPlaying = 0;
    for(int i = 8; i > 0; i--) {
        if(sounds[i-1].isPlaying()) {
            soundsPlaying++;
            cout << "sound " << i - 1 << " is playing" << endl;
        }
    }
    if(soundsPlaying == 0){
        ofSetBackgroundColor(255);
    }else{
        ofSetBackgroundColor(0);
    }

}
//--------------------------------------------------------------
void ofApp::draw(){
    for(int i = 0; i < 8; i++) {
        if(sounds[i].isPlaying()) {
            ofFill();
            ofSetColor(0,255,0);
            float curPos = i + (i * (ofGetWidth()/10));
            if(sounds[i].getPosition() < 0.5){
                ofDrawCircle((i*ofGetWidth()/8+ofGetWidth()/16), ofGetHeight()*0.75+ofMap(sounds[i].getPosition(), 0.2, 0, 0, ofGetHeight()/8), 10);
            }else{
                ofDrawCircle((i*ofGetWidth()/8+ofGetWidth()/16), ofGetHeight()*0.75+ofMap(1-(sounds[i].getPosition()), 0.2, 0, 0, ofGetHeight()/8), 10);
            }
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
