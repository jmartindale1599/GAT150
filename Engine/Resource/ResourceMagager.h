#pragma once

#include "Resource.h"

#include <map>

#include <string>

#include <memory>

namespace neu {

	class ResourceManager {

	public:

		ResourceManager() = default;

		~ResourceManager() = default;

		void initialize();

		void shutDown();

		template<typename T>

		std::shared_ptr<T> Get(const std::string& pathname, void* data = nullptr);

	private:

		std::map<std::string, std::shared_ptr<Resource>> m_library;

	};

	template<typename T>

	inline std::shared_ptr<T> ResourceManager::Get(const std::string& pathname, void* data) {

		if (m_library.find(pathname) != m_library.end()){

		//found

		return std::dynamic_pointer_cast<T> (m_library[pathname]);

		}else {

			//not found

			std::shared_ptr<T> resource = std::make_shared<T>();

			resource->Create(pathname, data);

			m_library[pathname] = resource;

			return resource;

		}

		return std::shared_ptr<T>();

	}

}
