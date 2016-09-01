/*
 * main.cpp
 *
 *  Created on: Sep 1, 2016
 *      Author: eric
 */
#include "Graphics.h"

const int FPS = 60;
const int FRAME_TIME = 1000/FPS;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int FULLSCREEN = false;

Graphics graphics;

bool isInit();
void freeProgram();
bool isRunning();

int main(int argc, char *argv[]){
	if(!isInit()){
		freeProgram();
		return false;
	}
	int counter = 0;

	while(isRunning()){
		int frameStart = SDL_GetTicks();
		counter++;
		if(counter > 180){
			counter = 0;
			//raphics.clear(rand())
		}

	}
}
