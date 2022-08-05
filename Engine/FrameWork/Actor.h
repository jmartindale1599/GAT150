#pragma once

#include "../Framework/GameObject.h"

#include "Component.h"

#include <vector>

namespace neu {

	class Scene;

	class Renderer;

	class Actor : public GameObject {

	public:

		Actor() = default;

		Actor(const Transform& transform) : m_transform{ transform } {}

		virtual void Update() override;

		virtual void Draw(Renderer& renderer);

		void addComponent(std::unique_ptr<Component> component);

		virtual void onCollision(Actor* other) {}

		float GetRadius() { return 0; } //m_model.getRadius()* m_transform.scale; }

		std::string& getTag() { return m_tag; }

		Scene* scene;

		friend class Scene;

		Transform m_transform;
	protected:

		std::string m_tag;

		bool m_destroy = false;

		Vector2 m_velocity;


		float m_damping = 1;

		Scene* m_scene;

		std::vector<std::unique_ptr<Component>> m_components;

	};

}

