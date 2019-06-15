#ifndef USERINTERFACE_SCREENINFO_HPP
#define USERINTERFACE_SCREENINFO_HPP




namespace UserInterface
{



	
class ScreenInfo
{
public:
	ScreenInfo();

	ScreenInfo(int screenWidth, int screenHeight);

	ScreenInfo(int screenWidth, int screenHeight,
			   char borderChar, char dividerChar);

	ScreenInfo(const ScreenInfo&) = default;
	ScreenInfo(ScreenInfo&&) = default;
	ScreenInfo& operator=(const ScreenInfo&) = default;
	ScreenInfo& operator=(ScreenInfo&&) = default;
	~ScreenInfo() = default;

	inline int getScreenWidth() { return m_screenWidth; }
	inline int getScreenHeight() { return m_screenHeight; }
	inline char getBorderChar() { return m_borderChar; }
	inline char getDividerChar() { return m_dividerChar; }

private:
	const int m_screenWidth;
	const int m_screenHeight;
	const char m_borderChar;
	const char m_dividerChar;
	
};






}




#endif