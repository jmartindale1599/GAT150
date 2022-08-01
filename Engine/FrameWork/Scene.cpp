#include "Scene.h"

#include <algorithm>

#include <iostream>

namespace neu {

	void Scene::Update() {

		auto iter = m_actors.begin();

		while (iter != m_actors.end()) {

			(*iter)->Update();

			if ((*iter)->m_destroy) {

				iter = m_actors.erase(iter);

			}
			else {

				iter++;

			}

		}

		// check colision

		for (auto iter1 = m_actors.begin(); iter1 != m_actors.end(); iter1++) {

			for (auto iter2 = m_actors.begin(); iter2 != m_actors.end(); iter2++) {

				if (iter1 == iter2) continue;

				float radius = (*iter1)->GetRadius() + (*iter2)->GetRadius();

				float distance = (*iter1)->m_transform.position.Distance((*iter2)->m_transform.position);

				if (distance < radius) {

					(*iter1)->onCollision((*iter2).get());

					(*iter2)->onCollision((*iter1).get());

				}

			}

		}

	}

	void Scene::Draw(Renderer& renderer){

		for (auto& actor : m_actors) {

			actor->Draw(renderer);

		}

	}

	void Scene::Add(std::unique_ptr<Actor> actor){

		actor->m_scene = this;

		m_actors.push_back(std::move(actor));

	}

}
