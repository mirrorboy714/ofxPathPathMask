#pragma once

#include "ofMain.h"

class ofxPathPathMask {

	public:
		void setup(const ofPath& pathMasked,const ofPath& pathMasker);
		void update();
		void draw();
		void setPathMasked(const ofPath& pathMasked);
		void setPathMasker(const ofPath& pathMasker);
		static ofRectangle getBoundingBoxOfPath(ofPath& path);
	private:
		ofPath _pathMasked;
		ofPath _pathMasker;
		ofFbo _fboMasked;
		ofFbo _fboMasker;

		void allocateFbo(ofFbo* pFbo,ofRectangle* pRect = nullptr);
};

