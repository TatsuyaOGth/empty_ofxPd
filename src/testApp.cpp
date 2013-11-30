#include "testApp.h"

void testApp::setup()
{
    // the number if libpd ticks per buffer,
	// used to compute the audio buffer len: tpb * blocksize (always 64)
	int ticksPerBuffer = 8;	// 8 * 64 = buffer len of 512
	ofSoundStreamSetup(2, 2, this, 44100, ofxPd::blockSize()*ticksPerBuffer, 4);
    ofSoundStreamListDevices();
    core.setup(2, 2, 44100, ticksPerBuffer);
}
void testApp::update(){ core.update(); }
void testApp::draw(){ core.draw(); }
void testApp::exit(){core.exit();}
void testApp::keyPressed(int key){core.keyPressed(key);}
void testApp::keyReleased(int key){core.keyReleased(key);}
void testApp::mouseMoved(int x, int y ){core.mouseMoved(x, y);}
void testApp::mouseDragged(int x, int y, int button){core.mouseDragged(x, y, button);}
void testApp::mousePressed(int x, int y, int button){core.mousePressed(x, y, button);}
void testApp::mouseReleased(int x, int y, int button){core.mouseReleased(x, y, button);}
void testApp::windowResized(int w, int h){core.windowResized(w, h);}
void testApp::gotMessage(ofMessage msg){core.gotMessage(msg);}
void testApp::dragEvent(ofDragInfo dragInfo){core.dragEvent(dragInfo);}
void testApp::audioIn(float *input, int bufferSize, int nChannels){core.audioIn(input, bufferSize, nChannels);}
void testApp::audioOut(float *input, int bufferSize, int nChannels){core.audioOut(input, bufferSize, nChannels);}
