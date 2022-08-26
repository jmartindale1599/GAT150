
#include "Engine.h"

#include "BeheadBall.h"

#include <iostream>

using namespace std;

int main() {

	kronk::innitMemory();

	neu::SetFilePath("../Assets");

	//initialize

	neu::g_audio.Initialize();

	neu::g_renderer.Initialize();

	neu::g_inputSystem.Initialize();

	neu::g_resources.initialize();

	neu::g_physicsSystem.Initialize();

	neu::Engine::Instance().Register();

	//create window

	neu::g_renderer.CreateWindow("Neumont", 800, 600);

	neu::g_renderer.SetClearColor(neu::Color{ 0, 0, 0, 255 });

	//create game

	std::unique_ptr<BeheadBall> game = std::make_unique<BeheadBall>();

	game->Initialize();

	bool quit = false;

	while (!quit) {

		//update

		neu::g_time.Tick();

		neu::g_inputSystem.Update();

		neu::g_physicsSystem.Update();

		neu::g_audio.Update();

		if (neu::g_inputSystem.GetKeyDown(neu::key_escape)) quit = true;

		//render

		game->Update();

		neu::g_renderer.BeginFrame();

		game->Draw(neu::g_renderer);

		neu::g_renderer.EndFrame();

	}

	game->Shutdown();

	game.reset();

	neu::Factory::Instance().Shutdown();

	neu::g_physicsSystem.Shutdown();

	neu::g_inputSystem.Shutdown();

	neu::g_resources.shutDown();

	neu::g_renderer.Shutdown();

	neu::g_audio.Shutdown();

}
