#pragma once

#include "../FrameWork/Component.h"

#include "Physics/Collision.h"

namespace neu {

	class PlayerComponent : public Component, public ICollosion {

	public:

		PlayerComponent() = default;

		void Update() override;

		void Initialize() override;

		virtual bool Write(const rapidjson::Value& value) const override;

		virtual bool Read(const rapidjson::Value& value) override;

		virtual void onCollisionEnter(Actor* other) override;

		virtual void onCollisionExit(Actor* other) override;
		
		float m_speed = 150;

	};

}
