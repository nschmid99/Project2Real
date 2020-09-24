#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/tracking.hpp>

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "CinderOpenCV.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class P2Attempt : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
};

void P2Attempt::setup()
{
}

void P2Attempt::mouseDown( MouseEvent event )
{
}

void P2Attempt::update()
{
}

void P2Attempt::draw()
{
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP( P2Attempt, RendererGl )
