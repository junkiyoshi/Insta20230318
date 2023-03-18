#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(0);
	ofSetLineWidth(3);
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}
//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);
	
	ofSetColor(0, 7, 16);
	for (int x = -360; x <= 360; x += 15) {

		for (int y = -400; y <= 400; y += 15) {

			vector<glm::vec2> vertices;
			vertices.push_back(glm::vec2(x, y));
			for (int i = 0; i < 150; i++) {

				auto deg = ofMap(ofNoise(vertices.back().x * 0.00085, vertices.back().y * 0.00085 + ofGetFrameNum() * 0.005), 0, 1, -360, 360);
				auto vertex = vertices.back() + glm::vec2(2 * cos(deg * DEG_TO_RAD), 2 * sin(deg * DEG_TO_RAD));
				vertices.push_back(vertex);
			}

			ofNoFill();
			ofBeginShape();
			ofVertices(vertices);
			ofEndShape();
		}
	}
}


//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}