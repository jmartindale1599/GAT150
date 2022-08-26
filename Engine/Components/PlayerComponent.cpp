
#include "PlayerComponent.h"

#include "../Engine.h"

#include "../Math/Transform.h"

#include <iostream>

void neu::PlayerComponent::Initialize() {

	auto component = m_owner->GetComponent<CollisionComponent>();

	if (component) {

		component->setCollisionEnter(std::bind(&PlayerComponent::onCollisionEnter, this, std::placeholders::_1));

		component->setCollisionExit(std::bind(&PlayerComponent::onCollisionExit, this, std::placeholders::_1));

	}

}

void neu::PlayerComponent::Update(){

	Vector2 direction = Vector2::zero;

	if (neu::g_inputSystem.GetKeyDown(neu::key_w)) {

		direction = Vector2::up;

	}

	if (neu::g_inputSystem.GetKeyDown(neu::key_a)) {

		direction = Vector2::left;

	}

	if (neu::g_inputSystem.GetKeyDown(neu::key_d)) {

		direction = Vector2::right;

	}

	auto component = m_owner->GetComponent<PhysicsComponent>();

	if (component) {

		component->ApplyForce(direction * m_speed);

	}

	if (g_inputSystem.GetKeyDown(key_space)){

		auto component = m_owner->GetComponent<PhysicsComponent>();

		if (component) {

			component->ApplyForce(direction * m_speed);

		}

	}

}

bool neu::PlayerComponent::Write(const rapidjson::Value& value) const{

	return false;

}

bool neu::PlayerComponent::Read(const rapidjson::Value& value){

	READ_DATA(value, m_speed);

	return true;

}

void neu::PlayerComponent::onCollisionEnter(Actor* other){

	if (other->getName() == "Coin") {

		other->setDestroy();

	}

	std::cout << "player enter\n";

}

void neu::PlayerComponent::onCollisionExit(Actor* other){

	std::cout << "player enter\n";

}
