#include "BeheadBall.h"

#include "GameComponents/EnemyComponent.h"

#include "Engine.h"

void BeheadBall::Initialize(){

	REGISTER_CLASS(EnemyComponent);

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

	neu::g_eventManager.Subscribe("EVENT_ADD_POINTS", std::bind(&BeheadBall::ONAddPoints, this, std::placeholders::_1));

}

void BeheadBall::Shutdown(){

	m_scene->removeAll();

}

void BeheadBall::Update(){

	switch (m_gameState) {

	case BeheadBall::gameState::titleScreen:

		if (neu::g_inputSystem.GetKeyDown(neu::key_space)) {

			m_stateTimer = 0;

			m_scene->getActorFromName("Title")->setActive(false);

			m_gameState = gameState::startLevel;

		}

			break;

	case BeheadBall::gameState::startLevel:

		for (int i = 0; i < 15; i++) {

			auto actor = neu::Factory::Instance().Create<neu::Actor>("Coin");

			actor->m_transform.position = { neu::randomf(0,800), 100.0f };

			actor->Initialize();

			m_scene->Add(std::move(actor));

		}

		for (int i = 0; i < 3; i++) {

			auto actor = neu::Factory::Instance().Create<neu::Actor>("Ghoul");

			actor->m_transform.position = { neu::randomf(0,800), 100.0f };

			actor->Initialize();

			m_scene->Add(std::move(actor));

		}

		m_gameState = gameState::game;

		break;

	case BeheadBall::gameState::game:

		break;

	case BeheadBall::gameState::gameOver:

		break;

	case BeheadBall::gameState::playerDied:

		m_stateTimer -= neu::g_time.deltaTime;

		if (m_stateTimer <= 0) {

			m_gameState = gameState::startLevel;

		}

		break;

	default:

			break;

	}

	m_scene->Update();

}

void BeheadBall::Draw(neu::Renderer& renderer){

	m_scene->Draw(renderer);

}

void BeheadBall::ONAddPoints(const neu::Event& event){

	addPoints(std::get<int>(event.data));

	std::cout << event.name << std::endl;

	std::cout << getScore() << std::endl;

}

void BeheadBall::ONPlayerDead(const neu::Event& event){

	m_gameState = gameState::playerDied;

	m_stateTimer = 4;

}
