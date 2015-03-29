
#ifndef Vision_H
#define Vision_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "PixelLogic.h"
#include <cmath>
//#include "../CommandBase.h"

class Vision: public Subsystem
{
private:
	I2C* wire;

	//TODO: Not sure if I should change the variables names to 'left' and 'right' as opposed to '0' and '1'
	uint8_t cam0Received = false;
	uint8_t cam1Received = false;

	uint16_t* cam0Data; //Stores all raw data from cameras
	uint16_t* cam1Data;

	uint16_t convertTo16Int(uint8_t* array, uint32_t beginIndex); //Converts to 16 bit unsigned int
	void transferData(uint8_t* buffer, uint16_t* target); //Transfers data from 8-bit buffer to 16-bit target
	void handleTransaction(uint8_t* buffer); //Handles all readings from the i2c

public:
	//Easier way of accessing cameras
	enum Camera {LEFT, RIGHT};

	Vision();
	~Vision();

	void InitDefaultCommand();

	//Needs to be called by the routine using vision every tick, receives the new info
	void receiveI2C();

	//Removes all data in the camera's caches
	void flushData();

	//Check to see if the camera has received information on it's last ping
	bool hasReceived(Camera camera);

	//Gets an index of a cameras raw data
	uint16_t getRaw(Camera camera, uint32_t index);

	//Retrieves the X position of a camera's bounding box
	uint16_t getBoundingX(Camera camera);

	//Retrieves the width of a camera's bounding box
	uint16_t getBoundingWidth(Camera camera);

	//Retrieves the height of a camera's bounding box
	uint16_t getBoundingHeight(Camera camera);
};

#endif
