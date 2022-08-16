#pragma once

#include "../FrameWork/Component.h"

#include "../Math/Vector2.h"

namespace neu {

	class PhysicsComponent : public Component {

	public:

		PhysicsComponent() = default;

		void Update() override;

		void ApplyForce(const Vector2& force) { m_acceleration += force; }

		Vector2 m_velocity;

		Vector2 m_acceleration;

		float m_damping = .99999f;

	};

}