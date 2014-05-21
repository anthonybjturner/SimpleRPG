/*
 * main.cpp
 *
 *  Created on: May 21, 2014
 *      Author: Anthony
 */

#include <windows.h>
#include "Game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR pCmdLine, int nCmdShow){

	Game* engine;
	try{

		MessageBoxA(NULL, "Welcome to the game. Click to play", "SimpleRPG",  MB_OK | 0);
		 engine = new Game();
		engine->start();

	}catch (const char* e){

		MessageBoxA(NULL, e, "Exception Occured", MB_OK | 0);

	}

	delete engine;
	return 0;

}

