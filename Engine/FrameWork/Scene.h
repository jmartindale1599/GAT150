#pragma once

#include "Actor.h"

#include <list>

#include <memory>

namespace neu {
	
	//forward declaration

	class Actor;

	class Renderer;

	class Game;

	class Scene : public GameObject, public ISerializable{

	public:

		Scene() = default;

		Scene(Game* game) : m_game{ game } {}

		Scene(const Scene& other) {}

		~Scene() = default;

		CLASS_CLONE(Scene)

		void Update() override;

		void Initialize() override;

		void Draw(Renderer& renderer);

		void Add(std::unique_ptr<Actor> actor);

		void removeAll();

		template<typename T> T* GetActor();

		void setGame(Game* game) { m_game = game; }

		Game* getGame() { return m_game; }

		virtual bool Write(const rapidjson::Value& value) const override;

		virtual bool Read(const rapidjson::Value& value) override;
	
	private:
		
		Game* m_game = nullptr;

		std::list<std::unique_ptr<Actor>> m_actors;

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
