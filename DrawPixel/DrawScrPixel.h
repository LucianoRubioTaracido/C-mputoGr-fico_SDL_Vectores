#pragma once
#include "pch.h"
#include <stdio.h>
#include <SDL.h>

class DrawScrPixel
{
public:
	DrawScrPixel();
	void DrawCart(int x, int y, int width, int height, SDL_Renderer* Render, short lineWidth);
	~DrawScrPixel();
};

