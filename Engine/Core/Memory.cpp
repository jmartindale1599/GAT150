#include "Memory.h"

namespace kronk {

	void innitMemory() {

		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	}

}