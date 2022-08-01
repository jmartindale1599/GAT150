#pragma once

#include "../Framework/GameObject.h"

#include "../Model.h"

namespace neu {

	class Scene;

	class Actor : public GameObject {

	public:

		Actor() = default;

		Actor(const Model& model, const Transform& transform) : m_model{ model }, GameObject{ transform }{}

		virtual void Update() override {};

		virtual void Draw(Renderer& renderer);

		virtual void onCollision(Actor* other) {}

		float GetRadius() { return m_model.getRadius() * m_transform.scale; }

		std::string& getTag() { return m_tag; }

		Scene* scene;

		friend class Scene;

	protected:

		std::string m_tag;

		bool m_destroy = false;

		Vector2 m_velocity;

		float m_damping = 1;

		Scene* m_scene;

		Model m_model;

	};

}

