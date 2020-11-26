#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "particle.h"
#include "ofxPanel.h"


class ofApp : public ofBaseApp{
	
	public:
		
		void setup();
		void update();
		void draw();
		
		void keyPressed  (int key);
		void keyReleased (int key);
		
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased();
		
		// let's make a vector of them
		vector <particle> particles;
	
		ofxPanel panel;
    
    ofParameter < float > COHESION_STRENGTH;
    ofParameter < float > COHESION_RADIUS;
    ofParameter < float > ALIGNMENT_STRENGTH;
    ofParameter < float > ALIGNMENT_RADIUS;
    ofParameter < float > SEPERATION_STRENGTH;
    ofParameter < float > SEPERATION_RADIUS;
    ofParameter < float > DAMPING;

	
	
		 
	
};

#endif
	
