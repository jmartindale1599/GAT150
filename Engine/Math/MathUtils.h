#pragma once

//#ifndef __MATH_UTILS_H__

//#define __MATH_UTILS_H__

//code would go here

//#endif // __MATH_UTILS_H__



namespace Math {

	const float Pi = 3.14159265359f;

	const float TwoPi = 6.28318530718f;

	const float HalfPi = 1.57079632679f;

	inline float DegToRad(float degrees) {

		return degrees * (Pi / 180);

	}

	inline float RadToDeg(float radians) {

		return radians * (180 / Pi);

	}

	int sqr(int num);

	//inline int half(int num) { return num / 2; };

}







