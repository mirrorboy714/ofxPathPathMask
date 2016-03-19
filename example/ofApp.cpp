#include "ofApp.h"

ofPath pathMasked;
ofPath pathMasker;

auto drawLines = [](ofPath& path){

	for(int i = 0 ; i < 100 ; i++){
		const auto& pos = ofPoint(ofRandom(ofGetWidth()/2),ofRandom(ofGetHeight()/2));
		path.lineTo(pos);
	}
};

//--------------------------------------------------------------
void ofApp::setup(){

	drawLines(pathMasked);	

	auto rectPathMasked = ofxPathPathMask::getBoundingBoxOfPath(pathMasked);
	pathMasker.setCircleResolution(120);
	pathMasker.circle(ofPoint(rectPathMasked.width/2,rectPathMasked.height/2),rectPathMasked.width/2);

	ppMask.setup(pathMasked,pathMasker);
}

//--------------------------------------------------------------
void ofApp::update(){

	pathMasked.clear();
	drawLines(pathMasked);
	ppMask.setPathMasked(pathMasked);

/*
	pathMasker.clear();
	auto randomPos = ofPoint(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
	ppMask.setPathMasker(pathMasker);
*/
	ppMask.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofBackgroundGradient(ofColor::white,ofColor::gray);

	ofPushMatrix();
	ofTranslate(ofGetWidth()/4,ofGetHeight()/4);
	ofSetColor(200,120,0);
	ppMask.draw();
	ofPopMatrix();

	ofDrawBitmapStringHighlight("Framerate:" + ofToString(ofGetFrameRate()),20,20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
