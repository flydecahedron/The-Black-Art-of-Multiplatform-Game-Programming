/*
 * Graphics.cpp
 *
 *  Created on: Aug 25, 2016
 *      Author: eric
 */

#include"Graphics.h"
/* init()
 * Sets sdl video mode
 * returns false if failed
 */
bool Graphics::init(int screenWidth, int screenHeight, bool isFullscreen){
	if(isFullscreen){
		backbuffer = SDL_SetVideoMode(screenWidth, screenHeight, 32, SDL_SWSURFACE|SDL_FULLSCREEN);
	} else {
		backbuffer = SDL_SetVideoMode(screenWidth, screenHeight, 32, SDL_SWSURFACE);
	}

	if(backbuffer == NULL){
		printf("Failed to initialize graphics!\n");
		return false;
	}
	return true;
}
/* drawPixel()
 * draws a pixel primitive
 * returns if backbuffer is null, if the backbuffer is locked or the
 * coordinates are out of range
 */
void Graphics::drawPixel(int x,int y,int r,int g,int b){
	if(backbuffer == NULL){
		return;
	}
	if(SDL_MUSTLOCK(backbuffer)){
		if(SDL_LockSurface(backbuffer)<0){
			return;
		}
	}
	if(x  >= backbuffer->w||x<0||y>=backbuffer->h||y<0){
		return;
	}
	Uint32 *buffer;
	Uint32 color;

	color = SDL_MapRGB(backbuffer->format, r, g, b);
	buffer = (Uint32*)backbuffer->pixels + y*backbuffer->pitch/4+x;
	*buffer = color;

	if(SDL_MUSTLOCK(backbuffer)){
		SDL_UnlockSurface(backbuffer);
	}
}
/* drawRect()
 * uses fillRect() to fill 4 "rects" in the shape of rectangle with a line thickness
 * of 1 pixel
 */
void Graphics::drawRect(int x, int y, int width, int height, int r, int g, int b){
	fillRect(x, y, width, 1, r, g , b);
	fillRect(x, y+height-1, width, 1, r, g, b);
	fillRect(x, y, 1, height, r, g, b);
	fillRect(x+width-1, y, 1, height, r, g, b);
}
/* fillRect()
 *
 */
void Graphics::fillRect(int x, int y, int width, int height, int r, int g, int b){
	if (backbuffer == NULL){
		return;
	}

	Uint32 color;
	color = SDL_MapRGB(backbuffer->format, r, g, b );

	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;

	SDL_FillRect(backbuffer, &rect, color);
}
/* clear()
 *
 */
void Graphics::clear(int r, int g, int b){
	if(backbuffer == NULL){
		return;
	}
	Uint32 color;
	color = SDL_MapRGB(backbuffer->format, r, g, b);
	SDL_FillRect(backbuffer, NULL, color);
}

int Graphics::getWidth(){
	return width;
}
int Graphics::getHeight(){
	return height;
}
SDL_Surface* Graphics::getBackbuffer(){
	return backbuffer;
}

void Graphics::flip(){
	SDL_Flip(backbuffer);
}
