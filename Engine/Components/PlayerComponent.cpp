
#include "PlayerComponent.h"

#include "../Engine.h"

#include "../Math/Transform.h"

#include <iostream>

void neu::PlayerComponent::Update(){

	if (neu::g_inputSystem.GetKeyDown(neu::key_w)) {

		m_owner->m_transform.position.y -= m_speed * neu::g_time.deltaTime;

	}

	if (neu::g_inputSystem.GetKeyDown(neu::key_s)) {

		m_owner->m_transform.position.y += m_speed * neu::g_time.deltaTime;

	}

	if (neu::g_inputSystem.GetKeyDown(neu::key_a)) {

		m_owner->m_transform.position.x -= m_speed * neu::g_time.deltaTime;

	}

	if (neu::g_inputSystem.GetKeyDown(neu::key_d)) {

		m_owner->m_transform.position.x += m_speed * neu::g_time.deltaTime;

	}

}
