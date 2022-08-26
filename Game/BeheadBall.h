#pragma once

#include "FrameWork/Game.h"

class BeheadBall : public neu::Game {

public:

	virtual void Initialize() override;

	virtual void Shutdown() override;

	virtual void Update() override;

	virtual void Draw(neu::Renderer& renderer) override;

};


