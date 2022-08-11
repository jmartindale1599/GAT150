#pragma once

#include "RenderComponent.h"

namespace neu {

	class Model;

	class ModelComponent : public RenderComponent {

	public:

		virtual void Update() override;

		virtual void Draw(Renderer& renderer) override;

		std::shared_ptr<Model> m_model;

	};

}
