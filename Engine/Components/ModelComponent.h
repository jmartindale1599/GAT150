#pragma once

#include "RenderComponent.h"

namespace neu {

	class Texture;

	class Renderer;

	class ModelComponent : public RenderComponent {

	public:

		virtual void Update() override;

		virtual void Draw(Renderer& renderer) override;

		std::shared_ptr<Texture> m_texture;

	};

}
