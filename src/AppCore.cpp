#include "AppCore.h"

void AppCore::setup(const int numOutChannels, const int numInChannels,
                    const int sampleRate, const int ticksPerBuffer)
{
    // setup Pd
    if(!pd.init(numOutChannels, numInChannels, sampleRate, ticksPerBuffer)) {
		OF_EXIT_APP(1);
	}
    
    pd.subscribe("toOF");
    
    pd.addReceiver(*this);
    
    pd.addToSearchPath("pd");
    Patch patch = pd.openPatch("pd/main.pd");
	cout << patch << endl;
    
    pd.start();
    
    
    ofBackground(0, 0, 0);
    ofSetVerticalSync(true);
    
}

//--------------------------------------------------------------
void AppCore::update()
{
    pd.sendFloat("fromOF", ofRandom(10));
    pd.readArray("scope", mScopeArray);
}

//--------------------------------------------------------------
void AppCore::draw()
{
	ofSetColor(0, 255, 0);
	ofSetRectMode(OF_RECTMODE_CENTER);
	float x = 0, y = ofGetHeight()/2;
	float w = ofGetWidth() / (float) mScopeArray.size(), h = ofGetHeight()/2;
	for(int i = 0; i < mScopeArray.size()-1; ++i) {
		ofLine(x, y+mScopeArray[i]*h, x+w, y+mScopeArray[i+1]*h);
		x += w;
	}
}

//--------------------------------------------------------------
void AppCore::exit()
{
}

//--------------------------------------------------------------
void AppCore::keyPressed(int key)
{
}

//--------------------------------------------------------------
void AppCore::keyReleased(int key)
{
}

//--------------------------------------------------------------
void AppCore::mouseMoved(int x, int y )
{
}

//--------------------------------------------------------------
void AppCore::mouseDragged(int x, int y, int button)
{
}

//--------------------------------------------------------------
void AppCore::mousePressed(int x, int y, int button)
{
}

//--------------------------------------------------------------
void AppCore::mouseReleased(int x, int y, int button)
{
}

//--------------------------------------------------------------
void AppCore::windowResized(int w, int h)
{
}

//--------------------------------------------------------------
void AppCore::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void AppCore::dragEvent(ofDragInfo dragInfo)
{
}

//--------------------------------------------------------------
void AppCore::audioIn(float *input, int bufferSize, int nChannels)
{
    pd.audioIn(input, bufferSize, nChannels);
}

void AppCore::audioOut(float *input, int bufferSize, int nChannels)
{
    pd.audioOut(input, bufferSize, nChannels);
}

//--------------------------------------------------------------
void AppCore::print(const std::string& message)
{
	cout << message << endl;
}

void AppCore::receiveBang(const std::string& dest)
{
}

void AppCore::receiveFloat(const std::string& dest, float value)
{
}

void AppCore::receiveSymbol(const std::string& dest, const std::string& symbol)
{
}

void AppCore::receiveList(const std::string& dest, const List& list)
{
}

void AppCore::receiveMessage(const std::string& dest, const std::string& msg, const List& list)
{
}

//--------------------------------------------------------------
void AppCore::receiveNoteOn(const int channel, const int pitch, const int velocity)
{
}

void AppCore::receiveControlChange(const int channel, const int controller, const int value)
{
}

// note: pgm nums are 1-128 to match pd
void AppCore::receiveProgramChange(const int channel, const int value)
{
}

void AppCore::receivePitchBend(const int channel, const int value)
{
}

void AppCore::receiveAftertouch(const int channel, const int value)
{
}

void AppCore::receivePolyAftertouch(const int channel, const int pitch, const int value)
{
}

// note: pd adds +2 to the port num, so sending to port 3 in pd to [midiout],
//       shows up at port 1 in ofxPd
void AppCore::receiveMidiByte(const int port, const int byte)
{
}
