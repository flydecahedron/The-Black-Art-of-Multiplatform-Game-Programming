/*
 * Graphics.h
 *
 *  Created on: Aug 25, 2016
 *      Author: eric
 */

#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include<SDL2/SDL.h>
#include<stdio.h>
class Graphics{
private:
	SDL_Surface* backbuffer;
	SDL_Window* window;
	int width;
	int height;
public:
	bool init(int screenWidth, int screenHeight, bool isFullScreen);
	void kill(); //destroys windows
	void setTitle(char* title);
	void drawPixel(int x, int y, int r, int g, int b);
	void drawRect(int x, int y, int width, int height, int r, int g, int b);
	void fillRect(int x, int y, int width, int height, int r, int g, int b);
	void clear(int r, int g, int b);
	void flip();
	int getWidth();
	int getHeight();
	SDL_Surface* getBackbuffer();
};



#endif /* GRAPHICS_H_ */
