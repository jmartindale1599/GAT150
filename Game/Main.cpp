
#include <iostream>

#include "Engine.h"

using namespace std;

int main() {

	cout << "Henlo World" << endl;

	kronk::innitMemory();

	neu::SetFilePath("../../Build");

	cout << neu::GetFilePath() << endl;

	//initialize

	neu::g_audio.Initialize();

	neu::g_renderer.Initialize();

	neu::g_inputSystem.Initialize();

	//create window

	neu::g_renderer.CreateWindow("Neumont", 800, 600);

	neu::g_renderer.SetClearColor(neu::Color{ 0, 0, 0, 255 });

	bool quit = false;

	while (!quit) {

		//update

		neu::g_time.Tick();

		neu::g_inputSystem.Update();

		neu::g_audio.Update();

		if (neu::g_inputSystem.GetKeyDown(neu::key_escape)) quit = true;

		//render
		neu::g_renderer.BeginFrame();

		neu::g_renderer.EndFrame();

	}

	neu::g_renderer.Shutdown();

	neu::g_audio.Shutdown();

}
