#include "BeheadBall.h"

#include "Engine.h"

void BeheadBall::Initialize(){

	m_scene = std::make_unique<neu::Scene>();

	rapidjson::Document document;

	std::vector <std::string> sceneNames = { "scenes/prefabs.txt", "scenes/tilemap.txt", "scenes/level.txt"};

	for (auto sceneName : sceneNames) {

	bool success = neu::json::Load(sceneName, document);

	if (!success) {

		LOG("Could nor load scene %s", sceneName.c_str());

		continue;

	}

	m_scene->Read(document);

	}

	m_scene->Initialize();


	for (int i = 0; i < 15; i++) {

		auto actor = neu::Factory::Instance().Create<neu::Actor>("Coin");

		actor->m_transform.position = { neu::randomf(0,800), 100.0f };

		actor->Initialize();

		m_scene->Add(std::move(actor));

	}

}

void BeheadBall::Shutdown(){

	m_scene->removeAll();

}

void BeheadBall::Update(){

	m_scene->Update();

}

void BeheadBall::Draw(neu::Renderer& renderer){

	m_scene->Draw(renderer);

}
