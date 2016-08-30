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


}



