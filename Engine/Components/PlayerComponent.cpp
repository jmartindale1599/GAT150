
#include "PlayerComponent.h"

#include "../Engine.h"

#include "../Math/Transform.h"

#include <iostream>

void neu::PlayerComponent::Update(){

	float thrust = 0;

	if (neu::g_inputSystem.GetKeyDown(neu::key_w)) {

		thrust = m_speed;

	}

	if (neu::g_inputSystem.GetKeyDown(neu::key_a)) {

		m_owner->m_transform.rotation -= m_speed * neu::g_time.deltaTime;

	}

	if (neu::g_inputSystem.GetKeyDown(neu::key_d)) {

		m_owner->m_transform.rotation += m_speed * neu::g_time.deltaTime;

	}

	auto component = m_owner->GetComponent<PhysicsComponent>();

	if (component) {

		//thrust force

		Vector2 force = Vector2::Rotate({ 0, -1 }, Math::DegToRad(m_owner->m_transform.rotation)) * thrust;

		component->ApplyForce(force);

		//center grav force

		//force = (Vector2{ 400,300 } - m_owner->m_transform.position).Normalized() * 60.0f;

		//component->ApplyForce(force);

	}

	if (g_inputSystem.GetKeyDown(key_space)){// == InputSystem::State::Pressed) {

		auto component = m_owner->GetComponent<AudioComponent>();

		if (component) {

			component->Play();

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
