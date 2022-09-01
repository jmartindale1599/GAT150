#pragma once

#include "FrameWork/Game.h"

#include "FrameWork/Event.h"

class BeheadBall : public neu::Game, public neu::INotify {

public:

	enum class gameState {

		titleScreen,

		startLevel,
		
		game,
		
		playerDied,

		gameOver

	};

	virtual void Initialize() override;

	virtual void Shutdown() override;

	virtual void Update() override;

	virtual void Draw(neu::Renderer& renderer) override;

	virtual void OnNotify(const neu::Event& event) override;

	void ONAddPoints(const neu::Event& event);

	void ONPlayerDead(const neu::Event& event);

private:

	gameState m_gameState = gameState::titleScreen;

	float m_stateTimer = 0;

};


