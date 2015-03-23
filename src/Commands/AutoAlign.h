// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#ifndef AUTO_ALIGN_GROUP_H
#define AUTO_ALIGN_GROUP_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"
#include <cmath>

/**
 *
 *
 * @author ExampleAuthor
 */
class AutoAlign: public CommandGroup 
{
private:
    //all ratios are width/height
    const float toteLength = 26.9;
    const float toteWidth = 16.9;
    const float toteHeight = 12.1;
    const float toteDiagonal = 31.76;
    const float shortFaceRatio = toteWidth/toteHeight;
    const float longFaceRatio = toteLength/toteHeight;
    const float maxFaceRatio = toteDiagonal/toteHeight;
    const double maxRatioAngle = 58.2;
    float ratioRight = 0.0;
    float ratioLeft = 0.0;
    double ratioAverage = 0.0;
    int leftOrRight = 0.0; //indicates whether you are left or right of max angle; right is 1, left is -1
    float angle = 0.0;
public:
	AutoAlign();
	double AngleAlgor(float wR, float hR, float wL,  float hL); //feed algor the dinosaur
};

#endif
