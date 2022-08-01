#pragma once

#include "Core/File.h"

#include "Core/Memory.h"

#include "Core/Time.h"

#include "Math/Random.h"

#include "Math/MathUtils.h"

#include "FrameWork/Scene.h"

#include "FrameWork/Game.h"

#include "Renderer/Font.h"

#include "Renderer/Text.h"

#include "Model.h"

#include "Input/InputSystem.h"

#include "Renderer.h"

#include "Audio/AudioSystem.h"

#include <memory>

#include <iostream>

#include <list>

#include <algorithm>


namespace neu {

	extern InputSystem g_inputSystem;

	extern Renderer g_renderer;

	extern Time g_time;

	extern Scene g_scene;

	extern AudioSystem g_audio;

}

