#include "idhAudioListener.h"
#include "idhTransform.h"
#include "idhGameObject.h"
#include "idhFmod.h"

namespace idh
{
	AudioListener::AudioListener()
		: Component(enums::eComponentType::AudioListener)
	{

	}

	AudioListener::~AudioListener()
	{

	}

	void AudioListener::Initialize()
	{

	}

	void AudioListener::Update()
	{

	}

	void AudioListener::LateUpdate()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		Fmod::Set3DListenerAttributes(&pos);
	}

	void AudioListener::Render(HDC hdc)
	{

	}
}