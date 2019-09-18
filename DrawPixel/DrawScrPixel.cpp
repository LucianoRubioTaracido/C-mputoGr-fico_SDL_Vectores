#include "pch.h"
#include "DrawScrPixel.h"
#include <stdio.h>
#include <SDL.h>


DrawScrPixel::DrawScrPixel()
{}

void DrawScrPixel::DrawCart(int x, int y, int width, int height, SDL_Renderer* Render,short lineWidth)
{
	int w = width; int h = height;
	if (lineWidth > 0)
	{
		for (unsigned short i = 0; abs(lineWidth) > i; i++)
		{
			SDL_RenderDrawPoint(Render, w / 2 + x - i , h / 2 - (y + i));
		}
	}
	else 
		for (unsigned short i = 0; abs(lineWidth) > i; i++)
		{
			SDL_RenderDrawPoint(Render, w / 2 + x + i , h / 2 - (y - i));
		}
}

DrawScrPixel::~DrawScrPixel()
{}