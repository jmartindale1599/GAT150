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

#include "Components/PlayerComponent.h"

#include "Components/SpriteComponent.h"

#include "Components/AudioComponent.h"

#include "Components/PhysicsComponent.h"

#include "Components/ModelComponent.h"

#include "Renderer/Renderer.h"

#include "Audio/AudioSystem.h"

#include "Resource/ResourceMagager.h"

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

	extern ResourceManager g_resources;

}

