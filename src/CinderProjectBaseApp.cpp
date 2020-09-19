#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class CinderProjectBaseApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
};

void CinderProjectBaseApp::setup()
{
}

void CinderProjectBaseApp::mouseDown( MouseEvent event )
{
}

void CinderProjectBaseApp::update()
{
}

void CinderProjectBaseApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP( CinderProjectBaseApp, RendererGl )
