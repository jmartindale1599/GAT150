
#include "Engine.h"

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

	neu::Engine::Instance().Register();

	//create window

	neu::g_renderer.CreateWindow("Neumont", 800, 600);

	neu::g_renderer.SetClearColor(neu::Color{ 0, 0, 0, 255 });

	//load assets

	//shared_ptr<neu::Texture> texture = make_shared<neu::Texture>();
	
	//texture->Create(neu::g_renderer, "sprites/Russle.png");

	//shared_ptr<neu::Model> model = make_shared<neu::Model>();

	//model->Create("models/Model.txt");

	neu::g_audio.AddAudio("music","audio/emotional-disappointed.wav");
	
	neu::g_audio.AddAudio("lazar","audio/Lazer.wav");

	//create scene

	bool quit = false;

	neu::Scene scene;

	rapidjson::Document document;

	bool success = neu::json::Load("level.txt", document);

	scene.Read(document);

	while (!quit) {

		//update

		neu::g_time.Tick();

		neu::g_inputSystem.Update();

		neu::g_audio.Update();

		if (neu::g_inputSystem.GetKeyDown(neu::key_escape)) quit = true;

		//render

		scene.Update();

		neu::g_renderer.BeginFrame();

		scene.Draw(neu::g_renderer);

		neu::g_renderer.EndFrame();

	}

	neu::g_renderer.Shutdown();

	neu::g_audio.Shutdown();

}
