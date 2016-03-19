#include "ofxPathPathMask.h"

void ofxPathPathMask::setup(const ofPath& pathMasked,const ofPath& pathMasker){

	auto rect = getBoundingBoxOfPath(const_cast<ofPath&>(pathMasked));
	allocateFbo(&_fboMasked,&rect);
	allocateFbo(&_fboMasker,&rect);

	setPathMasked(pathMasked);
	setPathMasker(pathMasker);
}

void ofxPathPathMask::update(){

	_fboMasked.getTexture().setAlphaMask(_fboMasker.getTexture());
}

void ofxPathPathMask::draw(){

	_fboMasked.draw(0,0,_fboMasked.getWidth(),_fboMasked.getHeight());
}

void ofxPathPathMask::setPathMasked(const ofPath& pathMasked){

	_pathMasked = pathMasked;	

	if(_fboMasked.isAllocated()){
		allocateFbo(&_fboMasked);
	}

	_fboMasked.begin();
		_pathMasked.draw();
	_fboMasked.end();
}

void ofxPathPathMask::setPathMasker(const ofPath& pathMasker){

	_pathMasker = pathMasker;

	if(_fboMasker.isAllocated()){
		allocateFbo(&_fboMasker);
	}

	_fboMasker.begin();
		_pathMasker.draw();
	_fboMasker.end();
}

ofRectangle ofxPathPathMask::getBoundingBoxOfPath(ofPath& path){
	
	auto strokeWidth = path.getStrokeWidth();

	if(strokeWidth == 0){

		path.setStrokeWidth(1.0);
	}

	path.setPolyWindingMode(OF_POLY_WINDING_ODD);

	auto& polyLine = path.getOutline()[0];
	auto rect = polyLine.getBoundingBox();

	path.setStrokeWidth(strokeWidth);

	return move(rect);
}

void ofxPathPathMask::allocateFbo(ofFbo* pFbo,ofRectangle* pRect){

	
	auto rect = ofRectangle(0,0,pFbo->getWidth(),pFbo->getHeight());

	if(pFbo->isAllocated()){

		pFbo->clear();
		/*
		pFbo->begin();
			ofSetColor(0,0);
			ofDrawRectangle(0,0,pFbo->getWidth(),pFbo->getHeight());
		pFbo->end();
		
		return;
		*/
	}

	if(pRect == nullptr){

		pFbo->allocate(rect.getWidth(),rect.getHeight(),GL_RGBA);
	}else{
		pFbo->allocate(pRect->width,pRect->height,GL_RGBA);
	}
}
