#pragma once

#include "Actor.h"

#include <list>

#include <memory>

namespace neu {
	
	//forward declaration

	class Renderer;

	class Game;

	class Scene {

	public:

		Scene() = default;

		Scene(Game* game) : m_game{ game } {}

		~Scene() = default;

		void Update();

		void Draw(Renderer& renderer);

		void Add(std::unique_ptr<Actor> actor);

		template<typename T> T* GetActor();

		void setGame(Game* game) { m_game = game; }
		Game* getGame() { return m_game; }

	private:

		std::list<std::unique_ptr<Actor>> m_actors;

		Game* m_game = nullptr;

	};


	template<typename T>
	
	inline T* Scene::GetActor(){

		for (auto& actor : m_actors) {

			T* result = dynamic_cast<T*>(actor.get());

			if (result) return result;

		}

		return nullptr;
	
	}

}
