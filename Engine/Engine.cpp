
#include "Engine.h"

namespace neu {

	InputSystem g_inputSystem;

	Renderer g_renderer;

	Time g_time;

	Scene g_scene;

	AudioSystem g_audio;

	ResourceManager g_resources;

	PhysicsSystem g_physicsSystem;

	EventManager g_eventManager;

	void Engine::Register(){

		REGISTER_CLASS(Actor);
		
		REGISTER_CLASS(AudioComponent);
		
		REGISTER_CLASS(ModelComponent);

		REGISTER_CLASS(TextComponent);
		
		REGISTER_CLASS(PhysicsComponent);

		REGISTER_CLASS(RBPhysicsComponent);

		REGISTER_CLASS(CollisionComponent);
		
		REGISTER_CLASS(PlayerComponent);
		
		REGISTER_CLASS(SpriteComponent);

		REGISTER_CLASS(SpriteAnimeComponent);

		REGISTER_CLASS(TilemapComponent);
		
	}

}
