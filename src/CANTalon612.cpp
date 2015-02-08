/*
 * CANTalon612.cpp
 *
 *  Created on: Feb 8, 2015
 *      Author: zachary
 */

#include <CANTalon612.h>

CANTalon612::CANTalon612(uint32_t port, uint32_t encoderA, uint32_t encoderB, Preferences* pfs, bool inverted, bool override) : CANTalon(port)
{
	encoder = new Encoder(encoderA, encoderB, inverted);
	prefs = pfs;
	initPID(pfs, override);
}
CANTalon612::CANTalon612(uint32_t port, uint32_t encoderA, uint32_t encoderB, float p, float i, float d, bool inverted, bool override) : CANTalon(port)
{
	encoder = new Encoder(encoderA, encoderB, inverted);
	prefs = Preferences::GetInstance();
	initPID(p, i, d, override);
}
CANTalon612::CANTalon612(uint32_t port, Encoder* e, Preferences* pfs, bool override) : CANTalon(port)
{
	encoder = e;
	prefs = pfs;
	initPID(pfs, override);
}
CANTalon612::CANTalon612(uint32_t port, Encoder* e, float p, float i, float d, bool override) : CANTalon(port)
{
	encoder = e;
	prefs = Preferences::GetInstance();
	initPID(p, i, d, override);
}

void CANTalon612::initPID(Preferences* pfs, bool override)
{
	readPrefs();
	pid = new PIDController(P, I, D, encoder, this);
}
void CANTalon612::initPID(float p, float i, float d, bool override)
{
	if (override || checkPrefs() == false)
	{
		writePrefs(p,i,d);
	}
	else
	{
		readPrefs();
	}
	pid = new PIDController(P, I, D, encoder, this);
}
void CANTalon612::readPrefs()
{
	if (checkPrefs())
	{
		P = prefs->GetFloat("P");
		I = prefs->GetFloat("I");
		D = prefs->GetFloat("D");
	}
	else
	{
		std::printf("No Preferences found!\n");
	}
}
bool CANTalon612::checkPrefs()
{
	if (prefs->ContainsKey("P") && prefs->ContainsKey("I") && prefs->ContainsKey("D"))
		return true;
	else
		return false;
}
int CANTalon612::writePrefs(float p, float i, float d)
{
	int exit_status = 0;
	if (checkPrefs())
		exit_status = 1;
	prefs->PutFloat("P", p);
	prefs->PutFloat("I", i);
	prefs->PutFloat("D", d);
	return exit_status;
}
CANTalon612::~CANTalon612()
{
	delete encoder;
	//CANTalon::~CANTalon();
}
void CANTalon612::PIDWrite(float output)
{
	Set(output);
}


