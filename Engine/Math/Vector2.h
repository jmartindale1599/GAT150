#pragma once

#include <cmath>

#include <sstream>

#include <string>

namespace neu {

	struct Vector2 {

		float x, y;

		Vector2() : x{ 0 }, y{ 0 } {}

		Vector2(float x, float y) : x{ x }, y{ y } {}

		Vector2(float v) : x{ v }, y{ v } {}

		Vector2(int x, int y) : x{ (float)x }, y{ (float)y } {}

		void Set(float x, float y) { this->x = x; this->y = y; }

		//arithmatic operators

		//Vector2 = Vector2 + Vector2

		Vector2 operator + (const Vector2 v) const { return Vector2{ this->x + v.x , this->y + v.y }; }
		
		Vector2 operator - (const Vector2 v) const { return Vector2{ this->x - v.x , this->y - v.y }; }

		Vector2 operator * (const Vector2 v) const { return Vector2{ this->x * v.x , this->y * v.y }; }
		
		Vector2 operator / (const Vector2 v) const { return Vector2{ this->x / v.x , this->y / v.y }; }

		//Vector2 = Vector2 + float

		Vector2 operator + (float s) const { return Vector2{ this->x + s , this->y + s }; }

		Vector2 operator - (float s) const { return Vector2{ this->x - s , this->y - s }; }

		Vector2 operator * (float s) const { return Vector2{ this->x * s , this->y * s }; }

		Vector2 operator / (float s) const { return Vector2{ this->x / s , this->y / s }; }

		//assignment operators

		Vector2& operator += (const Vector2 v) { this->x += v.x, this->y += v.y; return *this; }
		
		Vector2& operator -= (const Vector2 v) { this->x -= v.x, this->y -= v.y; return *this; }

		Vector2& operator *= (const Vector2 v) { this->x *= v.x, this->y *= v.y; return *this; }
		
		Vector2& operator /= (const Vector2 v) { this->x /= v.x, this->y /= v.y; return *this; }

		

		Vector2& operator += (const float s) { this->x += s, this->y += s; return *this; }
		
		Vector2& operator -= (const float s) { this->x -= s, this->y -= s; return *this; }

		Vector2& operator *= (const float s) { this->x *= s, this->y *= s; return *this; }
		
		Vector2& operator /= (const float s) { this->x /= s, this->y /= s; return *this; }

		//unary

		//Vector 2 = -Vector2 (makes neg)

		Vector2 operator - () const { return Vector2{ -x, -y }; }

		//comparison

		bool operator == (const Vector2& v) const { return (this->x == v.x && this->y == v.y); }
		
		bool operator != (const Vector2& v) const { return (this->x != v.x || this->y != v.y); }

		//functions
		
		float LegnthSquare();

		float Legnth();

		float GetAngle();

		float DistanceSqr(const Vector2 v);

		float Distance(const Vector2 v);

		Vector2 Normalized();

		void Normalize();

		static Vector2 Rotate(const Vector2& v, float angle);



	};

	inline std::istream& operator >> (std::istream& stream, Vector2& v){
	
		std::string line;

		std::getline(stream, line);

		// (#,#)

		std::string xs = line.substr(line.find("{") + 1, line.find(",") - (line.find("}")));
	
		v.x = std::stof(xs);

		std::string ys = line.substr(line.find(",") + 1, line.find("}") - (line.find(",")));

		v.y = std::stof(ys);

		return stream;
	
	}

	inline float Vector2::LegnthSquare() { return x * x + y * y; }

	inline float Vector2::Legnth() { return std::sqrt(x * x + y * y); }

	inline float Vector2::DistanceSqr(const Vector2 v) { return ((*this) - v).LegnthSquare(); }

	inline float Vector2::Distance(const Vector2 v) { return ((*this) - v).Legnth(); }

	inline float Vector2::GetAngle() {

		return std::atan2(y, x);

	}

	inline Vector2 Vector2::Normalized(){

		float length = Legnth();

		return Vector2( x / length, y / length);

	}

	inline void Vector2::Normalize(){

		(*this) /= Legnth();

	}

	inline Vector2 Vector2::Rotate(const Vector2& v, float angle){

		float x = v.x * std::cos(angle) - v.y * std::sin(angle);

		float y = v.x * std::sin(angle) + v.y * std::cos(angle);

		return Vector2(x,y);
	
	}



}


