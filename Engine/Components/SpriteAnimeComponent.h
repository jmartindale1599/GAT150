#pragma once

#include "RenderComponent.h"

#include "../Math/Rect.h"

namespace neu {

	class Texture;

	class Renderer;

	class SpriteAnimeComponent : public RenderComponent {

	public:

		virtual void Update() override;

		virtual void Draw(Renderer& renderer) override;

		virtual bool Write(const rapidjson::Value& value) const override;

		virtual bool Read(const rapidjson::Value& value) override;

		float fps = 0;

		int num_colums = 0;

		int num_rows = 0;

		int startFrame = 0;

		int endFrame = 0;

		int frame = 0;

		float frameTimer = 0;

		Rect source;

		std::shared_ptr<Texture> m_texture;

	};

}
