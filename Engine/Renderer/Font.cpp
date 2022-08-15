#include "Font.h"

#include <SDL_ttf.h>

neu::Font::Font(const std::string& filename, int fontSize){

	Load(filename, fontSize);

}

neu::Font::~Font(){

	if (!m_ttfFont) {

		TTF_CloseFont(m_ttfFont);

	}

}

bool neu::Font::Create(const std::string& filename, int data){

    va_list args;

    va_start(args, filename);

    Font& font = va_arg(args, Font);

    va_end(args);

	Load(filename, (int)data);

	return false;

}

void neu::Font::Load(const std::string& filename, int fontSize){

	m_ttfFont = TTF_OpenFont(filename.c_str(), fontSize);

}
