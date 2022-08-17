#pragma once

#include "RenderComponent.h"

namespace neu {

	class Texture;

	class Renderer;

	class SpriteComponent : public RenderComponent {

	public:

		virtual void Update() override;

		virtual void Draw(Renderer& renderer) override;

		std::shared_ptr<Texture> m_texture;

		virtual bool Write(const rapidjson::Value& value) const override;

		virtual bool Read(const rapidjson::Value& value) override;

	};

}
