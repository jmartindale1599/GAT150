#include "Actor.h"

#include "../Components/RenderComponent.h"

void neu::Actor::Update(){

	for (auto& component : m_components) {

		component->Update();

	}

	for (auto& child : m_children) {

		child->Update();

	}

	if (m_parent) {

		m_transform.Update(m_parent->m_transform.matrix);

	}else {

		m_transform.Update();

	}

}

void neu::Actor::Draw(Renderer& renderer){

	for (auto& component : m_components) {
		
		auto renderComponent = dynamic_cast<RenderComponent*>(component.get());

		if (renderComponent) {

			renderComponent->Draw(renderer);

		}

		//component->Update();

	}

	for (auto& child : m_children) {

		child->Draw(renderer);

	}

}

void neu::Actor::addChild(std::unique_ptr<Actor> child){
	
	child->m_parent = this;

	child->m_scene = this->m_scene;

	m_children.push_back(std::move(child));

}

void neu::Actor::addComponent(std::unique_ptr<Component> component){

	component->m_owner = this;

	m_components.push_back(std::move(component));

}
