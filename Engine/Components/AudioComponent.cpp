#include "AudioComponent.h"

#include "../Engine.h"

void neu::AudioComponent::Update(){



}

void neu::AudioComponent::Play(){

	g_audio.PlayAudio(m_soundName,m_loop);

}

void neu::AudioComponent::Stop(){



}
