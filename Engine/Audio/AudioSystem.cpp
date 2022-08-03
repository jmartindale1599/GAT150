#include "AudioSystem.h"

#include "../Core/Logger.h"

#include <fmod.hpp>

void neu::AudioSystem::Initialize(){

	FMOD::System_Create(&m_fmodSystem);

	void* extradriverdata = nullptr;

	m_fmodSystem->init(32, FMOD_INIT_NORMAL, extradriverdata);

}

void neu::AudioSystem::Shutdown(){
  
	for (auto sounds : m_sounds) {

		sounds.second->release();

	}

	m_sounds.clear();

	m_fmodSystem->close();

	m_fmodSystem->release();

}

void neu::AudioSystem::Update(){

	m_fmodSystem->update();

}

void neu::AudioSystem::AddAudio(const std::string& name, const std::string& filename){

	if (m_sounds.find(name) == m_sounds.end()){

		FMOD::Sound* sound = nullptr;

		m_fmodSystem->createSound(filename.c_str(), FMOD_DEFAULT, 0, &sound);

		if (sound == nullptr) {

			LOG("Error Creating sound %s. ", filename.c_str());

		}
		
		m_sounds[name] = sound;
	
	}

}

void neu::AudioSystem::PlayAudio(const std::string& name, bool loop){

	auto iter = m_sounds.find(name);
		
	if (iter == m_sounds.end()) {

		LOG("Error could not find sound %s. ", name.c_str());

	}

	if (iter != m_sounds.end()){

		FMOD::Sound* sound = iter->second;
		
		if (loop) {

			sound->setMode(FMOD_LOOP_NORMAL);

		}else{

			sound->setMode(FMOD_LOOP_OFF);
			
		}

		FMOD::Channel* channel;
			
		m_fmodSystem->playSound(sound, 0, false, &channel);
		
	}

}
