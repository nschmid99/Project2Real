//
//  Squares.hpp
//  P2Attempt
//
//  Created by Natasha Schmid on 9/19/20.
//

#ifndef Squares_hpp
#define Squares_hpp


#include <stdio.h>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/tracking.hpp>

#include "CinderOpenCV.h"

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"


using namespace cv;
class Squares
{
    
public:
    int N;
    int x1;
    int y1;
    int x2;
    int y2;
    virtual float count(ci::Rectf)=0;
    virtual float getDivisorOfSum()=0;
    virtual void setN(int n)
    {
        N=n;
        
    }
    
    
    virtual void drawRect()
    {//for i,j etc.
        
        int width=cinder::app::getWindowWidth()/N;   //set up width for each square
        int height=cinder::app::getWindowHeight()/N; //set up height for each square
        
        //do all the things to find the squares -
        for(int i=0;i<=N;i++)
        {
            for(int j=0;j<=N;j++)
            {
                
                x1=i*width;
                y1=j*height;
                x2=width*(i+1);
                y2=height*(j+1);
                
                ci::Rectf curSquare = ci::Rectf(x1,y1,x2,y2);
                
                float sum = count(curSquare);   //count up instances in a square
                float getDivisorOfSum=sum/100;  //divide sum to be able to change color
                
                cinder::gl::color(getDivisorOfSum*N*N*255,0,0,.5); //set color to red
                cinder::gl::drawSolidRect(curSquare);   //draw square
                
            }
            
        }
    }
    
};


class SquaresFrameDiff : public Squares{    //frame diff class inherits functionality from squares
private:
    cv::Mat frameDiff;
    int s;
    int num;
public:
    virtual void setN(int n)    //change n
    {
        num=n;
    }
    virtual void drawRect(cv::Mat b)
    {
        Squares::setN(num); //allows for n to change
        frameDiff = b;
        Squares::drawRect();    //creates and draws squares
        
    }
    virtual float count(ci::Rectf curSquare)    //passes in one rectangle at a time
    {
        s=0;
        for(int o=x1; o<x2; o++){       //gets square boundaries
            for(int q=y1; q<y2;q++){
                
                s=s+frameDiff.at<u_int8_t>(q,o);    //adds up pixels
                
            }
        }
        return s;
    }
    
    float getDivisorOfSum()
    {
        float setColor=s/1000;  //divides pixels  for color
        cinder::gl::color(setColor*N*N*255,0,0,.5); //sets the color
        return 1;   //faux return. not used
    }
};


class SquaresFeatures : public Squares
{
private:
    std::vector<cv::Point2f> features;
    int s;
    int num;
public:
    virtual void setN(int n){   //change n
        num=n;
    }
    
    virtual void drawRect(std::vector<cv::Point2f> pts)
    {
        Squares::setN(num);     //allows for n to change
        features = pts;
        Squares::drawRect();    //creates and draws rectangles
    }
    
    virtual float count(ci::Rectf curSquare)    //passes in one rectangle at a time
    {
        //return the sum of the features points
        s=0;
        for(int index =0; index<features.size();index++){
            if( curSquare.contains(cinder::fromOcv(features[index]))){  //if the square contains features
                s++;    //add to the sum
                
            }
            
        }
        return s;
    }
    
    float getDivisorOfSum()
    {
        float setColor=s/1000;  //divides total features for color
        cinder::gl::color(setColor*N*N*255,0,0,.5); //sets the color
        return 1;   //faux return. not used
    }
    
};





#endif /* Squares_hpp */
