#include "PhysicsSystem.h" 

#include "Math/MathUtils.h"

namespace neu{

	const float PhysicsSystem::pixelsPerUnit = 48.0f;

	void PhysicsSystem::Initialize(){

		b2Vec2 gravity{ 0, 10 };
		
		m_world = std::make_unique<b2World>(gravity);
	
	}

	b2Body* PhysicsSystem::CreateBody(const Vector2& position, float angle, const RigidBodyData& data){
		
		Vector2 worldPosition = ScreenToWorld(position);

		b2BodyDef bodyDef;
		
		bodyDef.type = (data.isDynamic) ? b2_dynamicBody : b2_staticBody;
		
		bodyDef.position = *((b2Vec2*)(&worldPosition));
		
		bodyDef.angle = Math::DegToRad(angle);
		
		bodyDef.fixedRotation = data.constrainAngle;
		
		b2Body* body = m_world->CreateBody(&bodyDef);

		return body;
	
	}

	void PhysicsSystem::DestroyBody(b2Body* body)
	{
		m_world->DestroyBody(body);
	}

	void PhysicsSystem::Shutdown(){



	}

	void PhysicsSystem::Update(){

		m_world->Step(1.0f / 60,8,3);

	}

}