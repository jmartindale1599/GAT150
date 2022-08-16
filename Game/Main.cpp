
#include "Engine.h"

#include <iostream>

using namespace std;

int main() {

	kronk::innitMemory();

	neu::SetFilePath("../Assets");

	rapidjson::Document document;

	bool success = neu::json::Load("json.txt", document);

	assert(success);

	std::string str;

	neu::json::Get(document, "string", str);

	std::cout << str << std::endl;

	bool b;

	neu::json::Get(document, "boolean", b);

	std::cout << b << std::endl;

	int i1;

	neu::json::Get(document, "integer1", i1);

	std::cout << i1 << std::endl;

	int i2;

	neu::json::Get(document, "integer2", i2);

	std::cout << i2 << std::endl;

	float f;

	neu::json::Get(document, "float", f);

	std::cout << f << std::endl;

	neu::Vector2 v2;

	neu::json::Get(document, "vector2", v2);

	std::cout << v2 << std::endl;

	neu::Color color;

	neu::json::Get(document, "color", color);

	std::cout << color << std::endl;

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

	//create actor

	bool quit = false;

	neu::Scene scene;

	neu::Transform transform{ {400,300}, 0, {1.5} };

	//std::unique_ptr<neu::Actor> actor = std::make_unique <neu::Actor>(transform);
	
	std::unique_ptr<neu::Actor> actor = neu::Factory::Instance().Create<neu::Actor>("Actor");

	actor->m_transform = transform;

	std::unique_ptr<neu::Component> pcomponent = neu::Factory::Instance().Create<neu::Component>("PlayerComponent");

	actor->addComponent(std::move(pcomponent));

	std::unique_ptr<neu::ModelComponent> mcomponent = std::make_unique <neu::ModelComponent>();

	std::shared_ptr<neu::Texture> texture = neu::g_resources.Get<neu::Texture>("sprites/Russle.png", &neu::g_renderer);

	//auto font = neu::g_resources.Get<neu::Font>("fonts/rb2.ttf", 10);

	mcomponent->m_model = neu::g_resources.Get<neu::Model>("models/model.txt");

	actor->addComponent(std::move(mcomponent));

	//std::unique_ptr<neu::SpriteComponent> scomponent = std::make_unique <neu::SpriteComponent>();
	
	//scomponent->m_texture = texture;

	//actor->addComponent(std::move(scomponent));
	
	std::unique_ptr<neu::AudioComponent> acomponent = std::make_unique <neu::AudioComponent>();

	std::unique_ptr<neu::Component> phcomponent = neu::Factory::Instance().Create<neu::Component>("PhysicsComponent");

	acomponent->m_soundName = "lazar";
	
	actor->addComponent(std::move(acomponent));

	actor->addComponent(std::move(phcomponent));

	//child actor

	neu::Transform transformC{ {10,5}, 0, {1, 1} };

	std::unique_ptr<neu::Actor> child = std::make_unique <neu::Actor>(transformC);
	
	std::unique_ptr<neu::ModelComponent> mcomponentC = std::make_unique <neu::ModelComponent>();

	mcomponentC->m_model = neu::g_resources.Get<neu::Model>("models/Model.txt");;

	child->addComponent(std::move(mcomponentC));

	actor->addChild(std::move(child));

	scene.Add(std::move(actor));

	float angle = 0;

	while (!quit) {

		//update

		neu::g_time.Tick();

		scene.Update();

		neu::g_inputSystem.Update();

		neu::g_audio.Update();

		if (neu::g_inputSystem.GetKeyDown(neu::key_escape)) quit = true;

		//render

		angle += 360.0f * neu::g_time.deltaTime;

		neu::g_renderer.BeginFrame();

		scene.Draw(neu::g_renderer);

		neu::g_renderer.EndFrame();

	}

	neu::g_renderer.Shutdown();

	neu::g_audio.Shutdown();

}
