#pragma once

#include "Renderer/Renderer.h"

#include <string>

#include <vector>

namespace neu {

	class Model {

	public:
	
		Model() = default;

		Model(const std::vector<neu::Vector2>& points, const neu::Color& color) : m_points{ points }, m_color{ color }{}

		Model(const std::string filename);

		bool Create(const std::string& filename);

		void Draw(Renderer& reference, const Vector2& position, float angle, float scale);

		void Draw(Renderer& reference, const Transform& transform);

		bool Load(const std::string& filename);

		float calcRadius();

		float getRadius() { return m_radius; }

	private:

		neu::Color m_color{ 0, 0, 0, 0 };

		std::vector<neu::Vector2> m_points;

		float m_radius = 0;

	};

}



