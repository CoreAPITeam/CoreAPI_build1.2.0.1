#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

namespace core
{

	enum TEXT_ALIGN
	{
	ALIGN_LEFT,
	ALIGN_CENTER,
	ALIGN_RIGHT,
	TITLE
	};
	
	enum MOUSE_BUTTON
	{
	KEY_M_RIGHT,
	KEY_M_LEFT,
	KEY_M_MIDDLE
	};
	
	struct MenuItem
	{
	const char *Caption;
	TEXT_ALIGN text_align;
	byte color;
	};

	#define COLOR_BLACK		0x0
	#define COLOR_DARKBLUE	0x1
	#define COLOR_DARKGREEN 0x2
	#define COLOR_DARKTURK	0x3
	#define COLOR_DARKRED	0x4
	#define COLOR_LILA		0x5
	#define COLOR_BROWN		0x6
	#define COLOR_GREY		0x7
	#define COLOR_DARKGREY	0x8
	#define COLOR_BLUE		0x9
	#define COLOR_GREEN		0xA
	#define COLOR_TURK		0xB
	#define COLOR_RED		0xC
	#define COLOR_PINK		0xD
	#define COLOR_YELLOW	0xE
	#define COLOR_WHITE		0xF

	class CoreAPI
	{
	private :

	public :
		TEXT_ALIGN text_align;
		HANDLE hConsole;
		byte FontColor;
		byte BGColor;
		HANDLE hStdInput,hStdOutput,hEvent;                         
		INPUT_RECORD ir[128];                                      
		DWORD nRead;                                               
		COORD xy;
		UINT i;
		COORD CursorPos;

		CoreAPI();

		void SaveCursorPos(void);
		void GotoCursorPos(COORD coord);
		void clear();
		SMALL_RECT GetRect();
		void Draw();
		void StringTextElement(std::string Text, bool visible);
		void StringTextElementCopyBackup(std::string Text, bool visible,std::string* textcopy);
		void SetFontColor(byte Color);
		void SetBGColor(byte Color);
		void Write(char *Text);
		void DrawWin(int wx, int wy, int ww, int wh,byte wBorderColor,int wnItems,MenuItem* Items);
		void DrawCenterWin(int wy, int ww, int wh,byte wBorderColor,int wnItems,MenuItem *Items);
		void DrawLine(char CHAR,byte color,int len);
		void DrawCenterBox(int y, int w, int h,byte BorderColor,int nItems,MenuItem *Items);
		void DrawBox(int x, int y, int w, int h,byte BorderColor,int nItems,MenuItem* Items);

		void DrawCustomWindow(const char* Char, int cx, int cy, int cw, int ch,byte cBorderColor,int cnItems,MenuItem* Items);
		void DrawCustomCenterWindow(const char* Char,int cy, int cw, int ch,byte cBorderColor,int cnItems,MenuItem *Items);

		void CreateMouseButtonArea(int y_begin , int y_end, int x_begin, int x_end, MOUSE_BUTTON mb, void (*action)());

		void Draw_unexpected_error_msg();
		void Draw_costum_error_msg(const char* errortext);
		void Draw_costum_warning_msg(const char* warningtext);
		void Draw_costum_info_msg(const char* infotext);
		void free(CoreAPI* g01237331gui){ delete g01237331gui;}
		void Fill(byte Color,bool OnlyVisible);
		void WriteLn(char *Text);

		CoreAPI(short iScreenx, short iScreeny,const char* cConsoleTitle,bool bShowCursor);
		void show_cursor(bool bShowCursor);
		void setScreenSize(int ScreenWidth,int ScreenHeigth,int ScreenCordx,int ScreenCordy);
		void setCursorPos(short Cursorx,short Cursory);
		void setConsoleTitle(const char* ConsoleTitle);
		void StrCheckSysData(std::string datapath,const char* accescode);
	};
}