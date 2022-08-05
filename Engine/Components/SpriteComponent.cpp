#include "SpriteComponent.h"

#include "../Renderer/Renderer.h"

#include "../FrameWork/Actor.h"

void neu::SpriteComponent::Update(){



}

void neu::SpriteComponent::Draw(Renderer& renderer){

	renderer.Draw(m_texture, m_owner->m_transform);

}
