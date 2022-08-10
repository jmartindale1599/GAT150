#pragma once

#include "Vector2.h"

//#include "2X2.h"

#include "3X3.h"

namespace neu {

	struct Transform {

		Vector2 position;

		float rotation{ 0 };

		Vector2 scale{ 1, 1 };

		//operator Matrix2x2 () const {

		//	Matrix2x2 mxScale = Matrix2x2::CreateScale(scale);

		//	Matrix2x2 mxRotation = Matrix2x2::CreateRotation(Math::DegToRad(rotation));

		//	return { mxScale * mxRotation };

		//}

		operator Matrix3x3 () const {

			Matrix3x3 mxScale = Matrix3x3::CreateScale(scale);

			Matrix3x3 mxRotation = Matrix3x3::CreateRotation(Math::DegToRad(rotation));

			Matrix3x3 mxTranslation = Matrix3x3::CreateTranslation(position);

			return { mxScale * mxRotation * mxTranslation };

		}

	};

}

