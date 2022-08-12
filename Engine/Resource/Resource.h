#pragma once

#include <string>

namespace neu {

	class Resource {

	public:

		virtual bool Create(const std::string& pathname, void* data = nullptr) = 0;

	};

}
