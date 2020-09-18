#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    font.load("framd.ttf", 200, true, true, true);
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    vector < ofPath > paths = font.getStringAsPoints("hello");
    
    ofTranslate(300,300);
    
    ofSeedRandom(mouseY);
    
    for (int i = 0; i < paths.size(); i++){
        paths[i].setPolyWindingMode(OF_POLY_WINDING_ODD);
        vector < ofPolyline > lines = paths[i].getOutline();
        
        
        ofSetColor(255);
        ofBeginShape();
        
        for (int j = 0; j < lines.size(); j++){
            
            lines[j].setClosed(true);
            lines[j] = lines[j].getResampledBySpacing(3);
            
            if (j != 0) ofNextContour();
            
            for (int k = 0; k < lines[j].size(); k++){
                lines[j][k].x += ofRandom(-mouseX, mouseX);
                lines[j][k].y += ofRandom(-mouseX, mouseX);
                
                ofVertex(lines[j][k].x, lines[j][k].y);
            }
            //lines[j] = lines[j].getSmoothed(mouseX*0.1);
            //lines[j].draw();
            
        }
        
        ofEndShape();
        
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
