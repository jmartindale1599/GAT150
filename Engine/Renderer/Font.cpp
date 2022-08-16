#include "Font.h"
#include "..\Core\Logger.h"
#include <SDL_ttf.h>

neu::Font::Font(const std::string& filename, int fontSize){

	Load(filename, fontSize);

}

neu::Font::~Font(){

	if (!m_ttfFont) {

		TTF_CloseFont(m_ttfFont);

	}

}

bool neu::Font::Create(std::string filename, ...){

    va_list args;

    va_start(args, filename);

    int fontSize = va_arg(args, int);

    va_end(args);

	return Load(filename, fontSize);
}

bool neu::Font::Load(const std::string& filename, int fontSize){

	m_ttfFont = TTF_OpenFont(filename.c_str(), fontSize);
	if (m_ttfFont == nullptr)
	{
		LOG("Could not load font %s", filename.c_str());
		return false;
	}

	return true;
}
