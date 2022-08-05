
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

	//create window

	neu::g_renderer.CreateWindow("Neumont", 800, 600);

	neu::g_renderer.SetClearColor(neu::Color{ 0, 0, 0, 255 });

	shared_ptr<neu::Texture> texture = make_shared<neu::Texture>();

	texture->Create(neu::g_renderer, "face.png");

	bool quit = false;

	//create actor

	neu::Scene scene;

	neu::Transform transform{ {100,100}, 0, {2} };

	std::unique_ptr<neu::Actor> actor = std::make_unique <neu::Actor>(transform);
	
	std::unique_ptr<neu::PlayerComponent> pcomponent = std::make_unique <neu::PlayerComponent>();

	actor->addComponent(std::move(pcomponent));

	std::unique_ptr<neu::SpriteComponent> scomponent = std::make_unique <neu::SpriteComponent>();
	
	scomponent->m_texture = texture;

	actor->addComponent(std::move(scomponent));

	scene.Add(std::move(actor));

	float angle = 0;

	while (!quit) {

		//update

		neu::g_time.Tick();

		angle += 90.0f * neu::g_time.deltaTime;
		
		scene.Update();

		neu::g_inputSystem.Update();

		neu::g_audio.Update();

		if (neu::g_inputSystem.GetKeyDown(neu::key_escape)) quit = true;

		//render

		neu::g_renderer.BeginFrame();

		scene.Draw(neu::g_renderer);

		neu::g_renderer.Draw(texture, { 200, 50 }, angle, { 2,2 }, { 0.5f,0.5f });

		neu::g_renderer.EndFrame();

	}

	neu::g_renderer.Shutdown();

	neu::g_audio.Shutdown();

}
