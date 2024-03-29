#include "pch.h"
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include "Vector.h"
#include "Matrix.h"
#include "DrawScrPixel.h"
#include <conio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;

//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//DrawClass
DrawScrPixel DrawPixel;

//Matrices
Matrix Mat2(2, 2);
Matrix Mat3(3, 3);

//Vectores
Vector Vect1(0, 0);
Vector Vect2(100, 0);
Vector Vect3(100, 50);
Vector Vect4(100, 100);
Vector Vect5(50, 100);
Vector Vect6(0, 100);
Vector Vect7(-50, 100);
Vector Vect8(-100, 100);
Vector Vect9(-100, 50);
Vector Vect10(-100, 0);
Vector Vect11(-100, -50);
Vector Vect12(-100, -100);
Vector Vect13(-50, -100);
Vector Vect14(0, -100);
Vector Vect15(50, -100);
Vector Vect16(100, -100);
Vector Vect17(100, -50);
Vector Vect18(0, 0);

int bNum;

bool init()
{
	//Initialization flag
	bool success = true;
	
	int f;
	bool band;
	std::cout << "Quieres insertar un vector? 1 = si, 0 = no \n Los vectores default hacen un cuadro de -100,-100 a 100, 100" << std::endl;
	std::cin >> f;
	if (f == 0)
		band = false;
	else band = true;
	while (band)
	{
		std::cout << "Qué vector quieres insertar? 1-18";
		std::cin >> f;
		switch (f)
		{
		case 1:
			std::cout << "Dame X y Y del vect 1" << std::endl;
			std::cin >> Vect1.x;
			std::cin >> Vect1.y;
			break;
		case 2:
			std::cout << "Dame X y Y del vect 2" << std::endl;
			std::cin >> Vect2.x;
			std::cin >> Vect2.y;
			break;
		case 3:
			std::cout << "Dame X y Y del vect 3" << std::endl;
			std::cin >> Vect3.x;
			std::cin >> Vect3.y;
			break;
		case 4:
			std::cout << "Dame X y Y del vect 4" << std::endl;
			std::cin >> Vect4.x;
			std::cin >> Vect4.y;
			break;
		case 5:
			std::cout << "Dame X y Y del vect 5" << std::endl;
			std::cin >> Vect5.x;
			std::cin >> Vect5.y;
			break;
		case 6:
			std::cout << "Dame X y Y del vect 6" << std::endl;
			std::cin >> Vect6.x;
			std::cin >> Vect6.y;
			break;
		case 7:
			std::cout << "Dame X y Y del vect 7" << std::endl;
			std::cin >> Vect7.x;
			std::cin >> Vect7.y;
			break;
		case 8:
			std::cout << "Dame X y Y del vect 8" << std::endl;
			std::cin >> Vect8.x;
			std::cin >> Vect8.y;
		case 9:
			std::cout << "Dame X y Y del vect 9" << std::endl;
			std::cin >> Vect9.x;
			std::cin >> Vect9.y;
			break;
		case 10:
			std::cout << "Dame X y Y del vect 10" << std::endl;
			std::cin >> Vect10.x;
			std::cin >> Vect10.y;
			break;
		case 11:
			std::cout << "Dame X y Y del vect 11" << std::endl;
			std::cin >> Vect11.x;
			std::cin >> Vect11.y;
			break;
		case 12:
			std::cout << "Dame X y Y del vect 12" << std::endl;
			std::cin >> Vect12.x;
			std::cin >> Vect12.y;
			break;
		case 13:
			std::cout << "Dame X y Y del vect 13" << std::endl;
			std::cin >> Vect1.x;
			std::cin >> Vect1.y;
			break;
		case 14:
			std::cout << "Dame X y Y del vect 14" << std::endl;
			std::cin >> Vect1.x;
			std::cin >> Vect1.y;
			break;
		case 15:
			std::cout << "Dame X y Y del vect 15" << std::endl;
			std::cin >> Vect1.x;
			std::cin >> Vect1.y;
			break;
		case 16:
			std::cout << "Dame X y Y del vect 16" << std::endl;
			std::cin >> Vect16.x;
			std::cin >> Vect16.y;
			break;
		case 17:
			std::cout << "Dame X y Y del vect 17" << std::endl;
			std::cin >> Vect17.x;
			std::cin >> Vect17.y;
			break;
		case 18:
			std::cout << "Dame X y Y del vect 18" << std::endl;
			std::cin >> Vect18.x;
			std::cin >> Vect18.y;
			break;
		default:
			std::cout << "ese vector no existe\n";
		}
		std::cout << "Quieres agregar otro? 1 = si, 0 = no";
		std::cin >> f;
		if (f == 0)
			band = false;
	}	

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);


			}
		}
	}

	return success;
}
void close()
{
	//Destroy window	
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;


	SDL_Quit();
}

void DrawLineMPos(Vector v1, Vector v2, int r, int g, int b, int lwidth)
{
	SDL_SetRenderDrawColor(gRenderer, r, g, b, 0xFF);
	int dx = v2.x - v1.x;
	int dy = v2.y - v1.y;
	int x = v1.x;
	int y = v1.y;
	float m;
	m = (float)(v1.y - v2.y) / (v1.x - v2.x);

	if (abs(m) == 0)
	{
		for (unsigned short i = 0; i < v2.x; i++)
		{
			DrawPixel.DrawCart(x + i, y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, lwidth);
		}

	}
	else if (fabs(m) < 1)
	{
		int p = 2 * dy - dx;
		for (unsigned short i = 0; i < dx / 2; i++)
		{
			if (p < 0)
			{
				x = x + 1;
				y = y;
				p = p + 2 * dy;
			}
			if (p >= 0)
			{
				x = x + 1;
				y = y + 1;
				p = p + (2 * dy) - (2 * dx);
			}
			DrawPixel.DrawCart(x, y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, lwidth);
		}
	}
	else if (fabs(m) > 1)
	{
		int p = 2 * dy - dx;
		for (unsigned short i = 0; i < dx; i++)
		{
			if (p < 0)
			{
				x = x + 1;
				y = y + 1;
				p = p + 2 * dy;
			}
			if (p >= 0)
			{
				x = x + 1;
				y = y + 1;
				p = p + (2 * dy) - (2 * dx);
			}
			DrawPixel.DrawCart(x, y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, lwidth);
		}
	}
	else if (fabs(m) == 1)
	{
		for (unsigned short i = 0; i < v2.x - x; i++)
		{
			DrawPixel.DrawCart(x + i, y + i, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, lwidth);
		}
	}
}

void DrawRainbowCircle(int radius, Vector vector, int w)
{
	bool rnt = true;
	int x = 0;
	int p = 1 - radius;
	int y = radius;
	while (rnt)
	{
		SDL_SetRenderDrawColor(gRenderer, 0xF0, 0x00, 0x80, 0xDD);
		DrawPixel.DrawCart(x + vector.x, y + vector.y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, w);
		SDL_SetRenderDrawColor(gRenderer, 0xB0, 0x40, 0xB0, 0xFF);
		DrawPixel.DrawCart(y + vector.x, x + vector.y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, w);
		SDL_SetRenderDrawColor(gRenderer, 0x80, 0x80, 0xF0, 0xFF);
		DrawPixel.DrawCart(y + vector.x, -x + vector.y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, w);
		SDL_SetRenderDrawColor(gRenderer, 0x40, 0xB0, 0xB0, 0xFF);
		DrawPixel.DrawCart(x + vector.x, -y + vector.y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, w);
		SDL_SetRenderDrawColor(gRenderer, 0x00, 0xF0, 0x80, 0xFF);
		DrawPixel.DrawCart(-x + vector.x, -y + vector.y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, w);
		SDL_SetRenderDrawColor(gRenderer, 0x40, 0xB0, 0x40, 0xFF);
		DrawPixel.DrawCart(-y + vector.x, -x + vector.y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, w);
		SDL_SetRenderDrawColor(gRenderer, 0x80, 0x80, 0x00, 0xFF);
		DrawPixel.DrawCart(-y + vector.x, x + vector.y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, w);
		SDL_SetRenderDrawColor(gRenderer, 0xB0, 0x40, 0x40, 0xFF);
		DrawPixel.DrawCart(-x + vector.x, y + vector.y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, w);
		if (p < 0)
		{
			x = x + 1;
			y = y;
			p = p + (2 * x) + 3;
		}
		else if (p >= 0)
		{
			x = x + 1;
			y = y - 1;
			p = p + (2 * x) - (2 * y) + 5;
		}

		if (x >= y)
			rnt = false;
	}
}
void DrawCircle(int radius, Vector vector, int w, int r, int g, int b)
{
	bool rnt = true;
	int x = 0;
	int p = 1 - radius;
	int y = radius;
	while (rnt)
	{
		SDL_SetRenderDrawColor(gRenderer, r, g, b, 0xDD);
		DrawPixel.DrawCart(x + vector.x, y + vector.y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, w);
		SDL_SetRenderDrawColor(gRenderer, r, g, b, 0xFF);
		DrawPixel.DrawCart(y + vector.x, x + vector.y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, w);
		SDL_SetRenderDrawColor(gRenderer, r, g, b, 0xFF);
		DrawPixel.DrawCart(y + vector.x, -x + vector.y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, w);
		SDL_SetRenderDrawColor(gRenderer, r, g, b, 0xFF);
		DrawPixel.DrawCart(x + vector.x, -y + vector.y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, w);
		SDL_SetRenderDrawColor(gRenderer, r, g, b, 0xFF);
		DrawPixel.DrawCart(-x + vector.x, -y + vector.y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, w);
		SDL_SetRenderDrawColor(gRenderer, r, g, b, 0xFF);
		DrawPixel.DrawCart(-y + vector.x, -x + vector.y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, w);
		SDL_SetRenderDrawColor(gRenderer, r, g, b, 0xFF);
		DrawPixel.DrawCart(-y + vector.x, x + vector.y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, w);
		SDL_SetRenderDrawColor(gRenderer, r, g, b, 0xFF);
		DrawPixel.DrawCart(-x + vector.x, y + vector.y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, w);
		if (p < 0)
		{
			x = x + 1;
			y = y;
			p = p + (2 * x) + 3;
		}
		else if (p >= 0)
		{
			x = x + 1;
			y = y - 1;
			p = p + (2 * x) - (2 * y) + 5;
		}

		if (x >= y)
			rnt = false;
	}
}

float Power(float base, float exp)
{
	float res = base;
	if (exp == 0)
	{
		return 1;
	}
	for (int i = 1; i < exp; i++)
	{
		res = res * base;
	}
	return res;
}
long Fact(int base)
{
	if (base == 0)
	{
		return 1;
	}
	long res = base;
	for (unsigned int i = 1; i < base; i++)
	{
		res = res * (base - i);
	}
	return res;
}
float Combination(int n, int i)
{
	return Fact(n) / (Fact(i) * Fact(n - i));
}

Vector Rot(Vector v, float ang)
{
	float rad = ang * (3.14/180);
	float x = (v.x * cos(rad) + v.y * sin(rad));
	float y = (v.x * -sin(rad) + v.y * cos(rad));
	Vector temp(x, y);
	return temp;
}
Vector Esc(Vector v, float size)
{
	return v.operator*(size);
}
Vector Tras(Vector v, int tX, int tY)
{
	Vector temp(v.x + tX, v.y + tY);
	return temp;
}

//Matemáticas Para Videojuegos 3D p 460 Mediateca
void DrawBezier4Curve(Vector v1, Vector v2, Vector v3, Vector v4, int r, int g, int b)
{
	float x = 0;
	float y = 0;
	SDL_SetRenderDrawColor(gRenderer, r, g, b, 0xFF);
	for (float t = 0; t < 1; t = t + .001)
	{
		float dif = 1 - t;
		x = (dif*dif*dif) * v1.x + 3 * t * (dif*dif) * v2.x + 3 * t*t * dif * v3.x + t*t*t * v4.x;
		y = (dif*dif*dif) * v1.y + 3 * t * (dif*dif) * v2.y + 3 * t*t * dif * v3.y + t*t*t * v4.y;
		DrawPixel.DrawCart((int)x, (int)y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, 2);
	}
}
void DrawBezier6Curve(Vector v1, Vector v2, Vector v3, Vector v4, Vector v5, Vector v6)
{
	float x = 0; float y = 0;
	SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
	for (float t = 0; t < 1; t = t + .0001)
	{
		float dif = 1 - t;
		x = (dif*dif*dif*dif*dif) * v1.x + 5 * t * (dif*dif*dif*dif) * v2.x + 10 * t*t * (dif*dif*dif) * v3.x + 10 * t*t*t * (dif*dif) * v4.x + 5 * t*t*t*t * (dif)* v5.x + t * t*t*t*t * v6.x;
		y = (dif*dif*dif*dif*dif) * v1.y + 5 * t * (dif*dif*dif*dif) * v2.y + 10 * t*t * (dif*dif*dif) * v3.y + 10 * t*t*t * (dif*dif) * v4.y + 5 * t*t*t*t * (dif)* v5.y + t * t*t*t*t * v6.y;
		DrawPixel.DrawCart((int)x, (int)y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, 2);
	}
}
void DrawBezierNCurve(std::vector<Vector> vectOfVect, int r, int g, int b, int widthline)
{
	float x = 0; float y = 0;
	SDL_SetRenderDrawColor(gRenderer, r, g, b, 0xFF);
	int n = vectOfVect.size();
	for (float t = 0; t < 1; t = t + .0001)
	{
		int xtemp = 0; int ytemp = 0;
		float dif = 1 - t;
	    std::vector<Vector>::iterator iterator = vectOfVect.begin();
		for (unsigned int i = 0; i < n; i++)
		{
			xtemp = xtemp + Combination(n - 1, i) * Power(t, n -1 -i) * Power(dif, i) * (iterator->x);
			ytemp = ytemp + Combination(n - 1, i) * Power(t, n -1 -i) * Power(dif, i) * (iterator->y);
			std::advance(iterator, 1);
		}
		x = xtemp;
		y = ytemp;
		DrawPixel.DrawCart((int)x, (int)y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, widthline);
	}
}

int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Main loop flag
		bool quit = false;

		//Event handler
		SDL_Event e;

		//While application is running
		while (!quit)
		{
			//Handle events on queue
			while (SDL_PollEvent(&e) != 0)
			{
				//User requests quit
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
			}

			//Clear screen
			SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(gRenderer);

			//DEBUG
	/*		for (unsigned i = 0; i < 3; i++)
			{
				int o = 1;
				for (unsigned j = 0; j < 3; j++)
				{
					Mat1.ModMatrix(o, i, j);
					std::cout << Mat1.operator()(i, j);
					o++;
				}   std::cout << std::endl;
			};

			for (unsigned i = 0; i < 3; i++)
			{
				int o = 4;
				for (unsigned j = 0; j < 3; j++)
				{
					Mat2.ModMatrix(o, i, j);
					std::cout << Mat2.operator()(i, j);
					o--;
				}   std::cout << std::endl;
			};

			Mat3 = Mat1.operator*(Mat2);

			for (unsigned i = 0; i < 3; i++)
			{
				for (unsigned j = 0; j < 3; j++)
				{
					std::cout << Mat3.operator()(i, j);
				}   std::cout << std::endl;
			};*/
			//DEBUG*
			


			//DRAW_GRID
			for (int j = 0; j < SCREEN_WIDTH; j += 10)
			{
				SDL_SetRenderDrawColor(gRenderer, 0xEA, 0xEA, 0xEA, 0xFF);
				for (int i = 0; i < SCREEN_HEIGHT; i += 1)
				{
					SDL_RenderDrawPoint(gRenderer, j, i);
				}
			}
			for (int j = 0; j < SCREEN_HEIGHT; j += 10)
			{
				SDL_SetRenderDrawColor(gRenderer, 0xEE, 0xEE, 0xEE, 0xFF);
				for (int i = 0; i < SCREEN_WIDTH; i += 1)
				{
					SDL_RenderDrawPoint(gRenderer, i, j);
				}
			}

			//DRAW_CART
			SDL_SetRenderDrawColor(gRenderer, 0x33, 0x33, 0x99, 0xFF);
			for (int i = 0; i < SCREEN_HEIGHT; i += 10)
			{
				SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH / 2 + 1, i);
			}
			SDL_SetRenderDrawColor(gRenderer, 0x33, 0x33, 0x99, 0xFF);
			for (int i = 0; i < SCREEN_WIDTH; i += 10)
			{
				SDL_RenderDrawPoint(gRenderer, i, SCREEN_HEIGHT / 2);
			}
			SDL_SetRenderDrawColor(gRenderer, 0x2D, 0x59, 0x86, 0xFF);
			for (int i = 0; i < SCREEN_WIDTH; i += 1)
			{
				SDL_RenderDrawPoint(gRenderer, i, SCREEN_HEIGHT / 2 +1);
			}
			SDL_SetRenderDrawColor(gRenderer, 0x2D, 0x59, 0x86, 0xFF);
			for (int i = 0; i < SCREEN_HEIGHT; i += 1)
			{
				SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH / 2, i);
			}


			//DrawRainbowCircle(200, Vect6, 3);
			//DrawCircle(200, Vect1, 3, 50, 50, 50);
			//DrawBezier4Curve(Vect1, Vect2, Vect3, Vect4, 200, 40, 40);

			//Vect3 = Rot(Vect2, 45);
			//Vect4 = Tras(Vect2, 100, 200);
			//Vect5 = Esc(Vect2, 5);

			//PUNTOS PRUEBA

			DrawCircle(2, Vect1, 1, 90, 0, 200);
			DrawCircle(2, Vect2, 1, 90, 100, 150);
			DrawCircle(2, Vect3, 1, 90, 255, 20);
			DrawCircle(2, Vect4, 1, 200, 30, 200);
			DrawCircle(2, Vect5, 1, 90, 100, 100);
			DrawCircle(2, Vect6, 1, 90, 0, 200);
			DrawCircle(2, Vect7, 1, 90, 0, 200);
			DrawCircle(2, Vect8, 1, 90, 0, 200);
			DrawCircle(2, Vect9, 1, 90, 0, 200);
			DrawCircle(2, Vect10, 1, 90, 0, 200);
			DrawCircle(2, Vect11, 1, 90, 0, 200);
			DrawCircle(2, Vect12, 1, 90, 0, 200);
			DrawCircle(2, Vect13, 1, 90, 0, 200);
			DrawCircle(2, Vect14, 1, 90, 0, 200);
			DrawCircle(2, Vect15, 1, 90, 0, 200);
			DrawCircle(2, Vect16, 1, 90, 0, 200);
			DrawCircle(2, Vect17, 1, 90, 0, 200);

			//DrawBezier6Curve(Vect1, Vect2, Vect3, Vect4, Vect5, Vect6);

			//DrawCircle(2, V1, 2, 200, 100, 200);
			//DrawCircle(2, V2, 2, 200, 100, 200);
			//DrawCircle(2, V3, 2, 200, 100, 200);
			////RES
			//DrawCircle(2, V1f, 2, 200, 0, 0);
			//DrawCircle(2, V2f, 2, 0, 200, 0);
			//DrawCircle(2, V3f, 2, 0, 0, 200);
			
			DrawLineMPos(Vect1, Vect2, 150, 150, 150, 2);
			DrawLineMPos(Vect1, Vect3, 150, 150, 150, 2);
			DrawLineMPos(Vect1, Vect4, 150, 150, 150, 2);
			DrawLineMPos(Vect1, Vect5, 150, 150, 150, 2);
			DrawLineMPos(Vect1, Vect6, 150, 150, 150, 2);
			DrawLineMPos(Vect1, Vect7, 150, 150, 150, 2);
			DrawLineMPos(Vect1, Vect8, 150, 150, 150, 2);
			DrawLineMPos(Vect1, Vect9, 150, 150, 150, 2);
			DrawLineMPos(Vect1, Vect10, 150, 150, 150, 2);
			DrawLineMPos(Vect1, Vect11, 150, 150, 150, 2);
			DrawLineMPos(Vect1, Vect12, 150, 150, 150, 2);
			DrawLineMPos(Vect1, Vect13, 150, 150, 150, 2);
			DrawLineMPos(Vect1, Vect14, 150, 150, 150, 2);
			DrawLineMPos(Vect1, Vect15, 150, 150, 150, 2);
			DrawLineMPos(Vect1, Vect16, 150, 150, 150, 2);
			DrawLineMPos(Vect1, Vect17, 150, 150, 150, 2);

			std::vector<Vector> vectVect;
			vectVect.push_back(Vect1); vectVect.push_back(Vect2); vectVect.push_back(Vect3);
			vectVect.push_back(Vect4); vectVect.push_back(Vect5); vectVect.push_back(Vect6);
			DrawBezierNCurve(vectVect, 40, 120, 40, 2);

			//Update screen
			SDL_RenderPresent(gRenderer);
		}

	}


	//Free resources and close SDL
	close();

	return 0;
}