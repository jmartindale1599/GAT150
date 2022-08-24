#pragma once

#include "FrameWork/Component.h"

#include "Physics/Collision.h"

#include "Physics/PhysicsSystem.h"

namespace neu {

	class CollisionComponent : public Component, public ICollosion {

	public:

		virtual void Initialize() override;

		virtual bool Write(const rapidjson::Value& value) const override;

		virtual bool Read(const rapidjson::Value& value) override;

		virtual void Update() override;

		virtual void onCollisionEnter(Actor* other) override;

		virtual void onCollisionExit(Actor* other) override;

	private:

		PhysicsSystem::CollisionData data;

	};

}
