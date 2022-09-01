#pragma once

#include "Components/CharacterComponent.h"

	class EnemyComponent : public neu::CharacterComponent{

	public:

		CLASS_CLONE(EnemyComponent);

		virtual void Initialize() override;
		
		virtual void Update() override;

		virtual void onCollisionEnter(neu::Actor* other) override;
		
		virtual void onCollisionExit(neu::Actor* other) override;

		virtual void OnNotify(const neu::Event& event) override;

		virtual bool Write(const rapidjson::Value& value) const override;
		
		virtual bool Read(const rapidjson::Value& value) override;

	protected:

	};
