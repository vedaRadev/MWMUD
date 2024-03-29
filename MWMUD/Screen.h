#pragma once

#include <d2d1.h>
#pragma comment(lib, "d2d1.lib")

struct Screen
{
	virtual ~Screen() {}

	// handle keyboard input
	virtual void handleKeypress(wchar_t key) = 0;

	// Draw the screen
	virtual void draw(ID2D1HwndRenderTarget* pRT) = 0;
};
