// appset.cpp

#include "appset.h"

const char* WindowSettings::appName = "Twitcutter";
const char* WindowSettings::mainWinClass = "TwitCutterWindowClass";

WindowSettings::WindowSettings()
{
}

const char* WindowSettings::get_appName()
{
	return appName;
}

const char* WindowSettings::get_mainWinClass()
{
	return mainWinClass;
}

WindowDimensions::WindowDimensions() 
	: xPos{ 0 },
	yPos{ 0 },
	width{ 100 },
	height{ 100 }
{
}

void WindowDimensions::setX(const unsigned int x)
{
	xPos = x;
}

void WindowDimensions::setY(const unsigned int y)
{
	yPos = y;
}

void WindowDimensions::setWidth(const unsigned int wd)
{
	width = wd;
}

void WindowDimensions::setHeight(const unsigned int ht)
{
	height = ht;
}

unsigned int WindowDimensions::getX() const
{
	return xPos;
}

unsigned int WindowDimensions::getY() const
{
	return yPos;
}

unsigned int WindowDimensions::getWidth() const
{
	return width;
}

unsigned int WindowDimensions::getHeight() const
{
	return height;
}

