#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){	
	
	
	ofBackground(0, 0, 0);
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	
	for (int i = 0; i < 60; i++){
		particle myParticle;
		myParticle.setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
		particles.push_back(myParticle);
	}
	
	
    panel.setup();
    
	panel.add(COHESION_STRENGTH.set("cohesion strength", 0.01,0,1));
	panel.add(COHESION_RADIUS.set("cohesion radius", 50,0,200));
	panel.add(ALIGNMENT_STRENGTH.set("alignment strength", 0.01,0,1));
	panel.add(ALIGNMENT_RADIUS.set("alignment radius",  50,0,200));
	panel.add(SEPERATION_STRENGTH.set("seperation strength", 0.01,0, 1));
	panel.add(SEPERATION_RADIUS.set("seperation radius",  50,0,200));
	panel.add(DAMPING.set("damping", 0.01, 0.001, 0.5));
	
	panel.loadFromFile("settings.xml");
}

//--------------------------------------------------------------
void ofApp::update(){

	
	for (int i = 0; i < particles.size(); i++){
		particles[i].cohesion.distance = COHESION_RADIUS;
		particles[i].alignment.distance = ALIGNMENT_RADIUS;
		particles[i].seperation.distance = SEPERATION_RADIUS;
		
		
		particles[i].cohesion.strength = COHESION_STRENGTH;
		particles[i].alignment.strength = ALIGNMENT_STRENGTH;
		particles[i].seperation.strength = SEPERATION_STRENGTH;
		
		particles[i].damping = DAMPING;
		
	}
	
	
	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update

	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
	}
	
	for (int i = 0; i < particles.size(); i++){
		for (int j = 0; j < particles.size(); j++){
			if (i != j){
				particles[i].addForFlocking(particles[j]);	
			}
		}
		
		
		
		// this was something we tried in class (partitcle move away from mouse...)
		particles[i].addRepulsionForce(mouseX, mouseY, 40, 0.4);
	}
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].addFlockingForce();
		particles[i].addDampingForce();
		particles[i].update();
	}
	
	
	// wrap torroidally.
	for (int i = 0; i < particles.size(); i++){
		ofPoint pos = particles[i].pos;
		if (pos.x < 0) pos.x = ofGetWidth();
		if (pos.x > ofGetWidth()) pos.x = 0;
		if (pos.y < 0) pos.y = ofGetHeight();
		if (pos.y > ofGetHeight()) pos.y = 0;
		particles[i].pos = pos;
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(180,180,180);
    
	
	ofEnableAlphaBlending();
	ofSetColor(0,130,130, 200);
	
	ofSetColor(0xffffff);
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}
	
	panel.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){ 
	
	switch (key){
			
		case ' ':
			// reposition everything: 
			for (int i = 0; i < particles.size(); i++){
				particles[i].setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
			}
			break;
	}
	
	
}

//--------------------------------------------------------------
void ofApp::keyReleased  (int key){ 
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	
	if (x < 500){
		particles.erase(particles.begin());
		particle myParticle;
		float randomAngle = ofRandom(0, TWO_PI);
		myParticle.setInitialCondition(x,y,cos(randomAngle),sin(randomAngle));
		particles.push_back(myParticle);
	}
	
	
	
	
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void ofApp::mouseReleased(){
	
}
