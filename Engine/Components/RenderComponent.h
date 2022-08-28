#pragma once

#include "../FrameWork/Component.h"

#include "Math/Rect.h"

#include "Renderer/Renderer.h"

namespace neu {

	class RenderComponent : public Component{

	public:
	 
		virtual void Draw(Renderer & renderer) = 0;

		virtual Rect& GetSource() { return source; }

	protected:

		Rect source;

	};

}


