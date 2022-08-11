#include "ModelComponent.h"

#include "../Model.h"

#include "../FrameWork/Actor.h"

void neu::ModelComponent::Update(){



}

void neu::ModelComponent::Draw(Renderer& renderer){

	m_model->Draw(renderer, m_owner->m_transform);

}
