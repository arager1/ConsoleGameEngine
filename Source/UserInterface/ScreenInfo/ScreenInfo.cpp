
#include "ScreenInfo.hpp"

namespace UserInterface
{


ScreenInfo::ScreenInfo() :
	ScreenInfo(0, 0)
{
	
}


ScreenInfo::ScreenInfo(int screenWidth, int screenHeight) :
	ScreenInfo(screenWidth, screenHeight, '=', '-')
{

}
	
ScreenInfo::ScreenInfo(int screenWidth, int screenHeight,
					   char borderChar, char dividerChar) :
	m_screenWidth(screenWidth),
	m_screenHeight(screenHeight),
	m_borderChar(borderChar),
	m_dividerChar(dividerChar)
{
	
}




}