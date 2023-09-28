/*
   CONIOEX.H 
   Funktionen f r Konsolen-Programme
   nach dem Original von Rene K nig, zu finden auf www.tbkoenig.de
*/

#ifndef   CONIOEX_H
  #define CONIOEX_H

    #define TBK_CONIOEXAPI  __cdecl
	
	/*#if defined(__BORLANDC__) || (_MSC_VER >= 1200)
		#pragma hdrstop
	#endif
	*/
    #ifdef __BORLANDC__

      // We don't need conioex.h since Borland-Compilers support
      // their own prototypes trough conio.h
      #include <conio.h>

    #else

      #if (!defined(_WIN32)) || (defined(_MSC_VER) && !defined(_CONSOLE))
        #error Only Win32-Console-Targets supported
      #endif

      #ifndef __COLORS
        #define __COLORS

          enum COLORS
          {
              BLACK,          /* dark colors */
              BLUE,
              GREEN,
              CYAN,
              RED,
              MAGENTA,
              BROWN,
              LIGHTGRAY,
              DARKGRAY,       /* light colors */
              LIGHTBLUE,
              LIGHTGREEN,
              LIGHTCYAN,
              LIGHTRED,
              LIGHTMAGENTA,
              YELLOW,
              WHITE
          };
      #endif

      // cursortypes used with _setcursortype()
      #define _NOCURSOR      0
      #define _SOLIDCURSOR   1
      #define _NORMALCURSOR  2
		
	  //We must use this library
	  #include <windows.h>

      // use this macro to build the attribute used with textattr()
      // usage: BUILD_TEXTATTR(textcolor, backgroundcolor);
      #ifndef BUILD_TEXTATTR
        #define BUILD_TEXTATTR(f, b)    (int)((((b) & 15) << 4) | ((f) & 15))
      #endif

      #ifdef __cplusplus
        extern "C" {
      #endif

      // clears the screen and moves the cursor to position x = 1, y = 1
      void  TBK_CONIOEXAPI  clrscr(void)
			{
				CONSOLE_SCREEN_BUFFER_INFO csbi;
				HANDLE                     hOutput;
				DWORD                      dwWritten;
				COORD                      coordOrg;

				if(INVALID_HANDLE_VALUE == (hOutput = GetStdHandle(STD_OUTPUT_HANDLE)))
					return;
				if(!GetConsoleScreenBufferInfo(hOutput, &csbi))
					return;

				coordOrg.X = 0;
				coordOrg.Y = 0;

				FillConsoleOutputAttribute(hOutput, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coordOrg, &dwWritten);
				FillConsoleOutputCharacter(hOutput, TEXT(' '), csbi.dwSize.X * csbi.dwSize.Y, coordOrg, &dwWritten);
				SetConsoleCursorPosition(hOutput, coordOrg);

				return;
			}

      // clears the line from the actual cursor position to the end,
      // the cursor position remains unchanged
      void  TBK_CONIOEXAPI  clreol(void)
			{
				CONSOLE_SCREEN_BUFFER_INFO csbi;
				HANDLE                     hOutput;
				DWORD                      dwWritten;

				if(INVALID_HANDLE_VALUE == (hOutput = GetStdHandle(STD_OUTPUT_HANDLE)))
					return;
				if(!GetConsoleScreenBufferInfo(hOutput, &csbi))
					return;

				FillConsoleOutputAttribute(hOutput, csbi.wAttributes, (csbi.dwSize.X - csbi.dwCursorPosition.X), csbi.dwCursorPosition, &dwWritten);
				FillConsoleOutputCharacter(hOutput, TEXT(' '), (csbi.dwSize.X - csbi.dwCursorPosition.X), csbi.dwCursorPosition, &dwWritten);
				SetConsoleCursorPosition(hOutput, csbi.dwCursorPosition);

				return;
			}

      // moves the cursor to position x, y
      // to move the cursor to the top-left corner of the screen use
      // the coordinates x = 1, y = 1
      void  TBK_CONIOEXAPI  gotoxy(int x, int y)
			{
				COORD  coordPos;

				if(HIWORD(x) || HIWORD(y))
					return;

				coordPos.X = LOWORD(x - 1);
				coordPos.Y = LOWORD(y - 1);

				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordPos);

				return;
			}

      // returns the x-coordinate of the current cursor-position
      int   TBK_CONIOEXAPI  wherex(void)
			{
				CONSOLE_SCREEN_BUFFER_INFO csbi;

				csbi.dwCursorPosition.X = 0;
				GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

				return(csbi.dwCursorPosition.X + 1);
			}

      // returns the y-coordinate of the current cursor-position
      int   TBK_CONIOEXAPI  wherey(void)
			{
				CONSOLE_SCREEN_BUFFER_INFO csbi;

				csbi.dwCursorPosition.Y = 0;
				GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

				return(csbi.dwCursorPosition.Y + 1);
			}

      // inserts a line at the current cursor position and moves all
      // lines from the current cursor-position one line down. the
      // bottom line is discarded
      void  TBK_CONIOEXAPI  insline(void)
			{
				CONSOLE_SCREEN_BUFFER_INFO csbi;
				SMALL_RECT                 smrcScroll;
				CHAR_INFO                  ciFill;
				HANDLE                     hOutput;
				COORD                      coordDestOrg;

				if(INVALID_HANDLE_VALUE == (hOutput = GetStdHandle(STD_OUTPUT_HANDLE)))
					return;
				if(!GetConsoleScreenBufferInfo(hOutput, &csbi))
					return;

				#ifdef UNICODE
					ciFill.Char.UnicodeChar = L' ';
				#else
					ciFill.Char.AsciiChar   =  ' ';
				#endif

				ciFill.Attributes = csbi.wAttributes;

				smrcScroll.Left   = 0;
				smrcScroll.Top    = LOWORD(csbi.dwCursorPosition.Y);
				smrcScroll.Right  = LOWORD(csbi.dwSize.X - 1);
				smrcScroll.Bottom = LOWORD(csbi.dwSize.Y - 1);

				coordDestOrg.X    = 0;
				coordDestOrg.Y    = LOWORD(csbi.dwCursorPosition.Y + 1);

				ScrollConsoleScreenBuffer(hOutput, &smrcScroll, NULL, coordDestOrg, &ciFill);
				return;
			}

      // deletes the line at the current cursor-position and moves all
      // lines below the cursor one line up
      void  TBK_CONIOEXAPI  delline(void)
			{
				CONSOLE_SCREEN_BUFFER_INFO csbi;
				SMALL_RECT                 smrcScroll;
				CHAR_INFO                  ciFill;
				HANDLE                     hOutput;
				COORD                      coordDestOrg;

				if(INVALID_HANDLE_VALUE == (hOutput = GetStdHandle(STD_OUTPUT_HANDLE)))
					return;
				if(!GetConsoleScreenBufferInfo(hOutput, &csbi))
					return;

				#ifdef UNICODE
					ciFill.Char.UnicodeChar = L' ';
				#else
					ciFill.Char.AsciiChar   =  ' ';
				#endif

				ciFill.Attributes = csbi.wAttributes;

				smrcScroll.Left   = 0;
				smrcScroll.Top    = LOWORD(csbi.dwCursorPosition.Y + 1);
				smrcScroll.Right  = LOWORD(csbi.dwSize.X - 1);
				smrcScroll.Bottom = LOWORD(csbi.dwSize.Y - 1);

				coordDestOrg.X    = 0;
				coordDestOrg.Y    = LOWORD(csbi.dwCursorPosition.Y);

				ScrollConsoleScreenBuffer(hOutput, &smrcScroll, NULL, coordDestOrg, &ciFill);
				return;
			}

      // sets the current textcolor. possible values are in the range
      // from 0-15 and are seen in the COLORS-enumeration
      void  TBK_CONIOEXAPI  textcolor(int newcolor)
	  {
				CONSOLE_SCREEN_BUFFER_INFO csbi;
				HANDLE                     hOutput;

				if(INVALID_HANDLE_VALUE == (hOutput = GetStdHandle(STD_OUTPUT_HANDLE)))
					return;
				if(!GetConsoleScreenBufferInfo(hOutput, &csbi))
					return;

				SetConsoleTextAttribute(hOutput, (WORD)((csbi.wAttributes & ~0x0F) | ((WORD)(newcolor & 0x0F))));
				return;
			}
			
      // sets the current color for the textbackground. possible values
      // are in the range from 0-15 and are seen in the COLORS-enumeration
      void  TBK_CONIOEXAPI  textbackground(int newcolor)
			{
				CONSOLE_SCREEN_BUFFER_INFO csbi;
				HANDLE                     hOutput;

				if(INVALID_HANDLE_VALUE == (hOutput = GetStdHandle(STD_OUTPUT_HANDLE)))
					return;
				if(!GetConsoleScreenBufferInfo(hOutput, &csbi))
					return;

				SetConsoleTextAttribute(hOutput, (WORD)((csbi.wAttributes & ~0xF0) | ((WORD)((newcolor & 0x0F) << 4))));
				return;
			}
			
      // sets the textcolor and the textbackground in one step. build the
      // attribute using the BUILD_TEXTATTR() macro
      void  TBK_CONIOEXAPI  textattr(int newattr)
			{
				CONSOLE_SCREEN_BUFFER_INFO csbi;
				HANDLE                     hOutput;

				if(INVALID_HANDLE_VALUE == (hOutput = GetStdHandle(STD_OUTPUT_HANDLE)))
					return;
				if(!GetConsoleScreenBufferInfo(hOutput, &csbi))
					return;

				SetConsoleTextAttribute(hOutput, (WORD)((csbi.wAttributes & ~0xFF) | (WORD)((newattr & 0xFF))));
				return;
			}

      // turns on high intensity for following text outputs
      void  TBK_CONIOEXAPI  highvideo(void)
			{
				CONSOLE_SCREEN_BUFFER_INFO csbi;
				HANDLE                     hOutput;

				if(INVALID_HANDLE_VALUE == (hOutput = GetStdHandle(STD_OUTPUT_HANDLE)))
					return;
				if(!GetConsoleScreenBufferInfo(hOutput, &csbi))
					return;

				SetConsoleTextAttribute(hOutput, (WORD)(csbi.wAttributes | FOREGROUND_INTENSITY));
				return;
			}

      // turns off high intensity for following text outputs
      void  TBK_CONIOEXAPI  lowvideo(void)
			{
				CONSOLE_SCREEN_BUFFER_INFO csbi;
				HANDLE                     hOutput;

				if(INVALID_HANDLE_VALUE == (hOutput = GetStdHandle(STD_OUTPUT_HANDLE)))
					return;
				if(!GetConsoleScreenBufferInfo(hOutput, &csbi))
					return;

				SetConsoleTextAttribute(hOutput, (WORD)(csbi.wAttributes & ~FOREGROUND_INTENSITY));
				return;
			}


      // set the cursor shape to one of the following shapes:
      // _NOCURSOR     - the cursor is invisible
      // _NORMALCURSOR - default underscore-cursor
      // _SOLIDCURSOR  - boxed cursor
      void  TBK_CONIOEXAPI  _setcursortype(int cur_t)
			{
				CONSOLE_CURSOR_INFO cci;

				if((cur_t == _NOCURSOR) || (cur_t == _NORMALCURSOR))
					cci.dwSize = 25;
				else if(cur_t == _SOLIDCURSOR)
					cci.dwSize = 100;
					 else
						return;

				cci.bVisible = (cur_t == _NOCURSOR) ? FALSE : TRUE;
				SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
				return;
			}
			
      #ifdef __cplusplus
        }
      #endif

    #endif  // __BORLANDC__
#endif  // CONIOEX_H