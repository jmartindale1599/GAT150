#pragma once

#include "RenderComponent.h"

namespace neu {

	class Model;

	class ModelComponent : public RenderComponent {

	public:

		CLASS_CLONE(ModelComponent)

		virtual void Update() override;

		virtual void Draw(Renderer& renderer) override;

		virtual bool Write(const rapidjson::Value& value) const override;

		virtual bool Read(const rapidjson::Value& value) override;

		std::shared_ptr<Model> m_model;

	};

}
