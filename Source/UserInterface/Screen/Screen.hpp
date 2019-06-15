#ifndef USERINTERFACE_SCREEN_HPP
#define USERINTERFACE_SCREEN_HPP


#include "ScreenInfo.hpp"

#include <string>
#include <vector>

namespace UserInterface
{




class Screen
{
public:
	Screen();

	Screen(const Screen&) = default;
	Screen(Screen&&) = default;
	Screen& operator=(const Screen&) = default;
	Screen& operator=(Screen&&) = default;
	~Screen() = default;

	inline const ScreenInfo& getScreenInfo() { return m_screenInfo; }

	

private:
	const ScreenInfo m_screenInfo;
	std::vector<std::string> m_screenData;
};





}




#endif