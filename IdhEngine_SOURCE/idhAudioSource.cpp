#include "idhAudioSource.h"
#include "idhTransform.h"
#include "idhGameObject.h"
#include "idhFmod.h"

namespace idh
{
	AudioSource::AudioSource()
		: Component(enums::eComponentType::AudioSource)
	{

	}

	AudioSource::~AudioSource()
	{

	}

	void AudioSource::Initialize()
	{

	}

	void AudioSource::Update()
	{

	}

	void AudioSource::LateUpdate()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		Fmod::Set3DListenerAttributes(&pos);
	}

	void AudioSource::Render(HDC hdc)
	{

	}

	void AudioSource::Play()
	{
		mAudioClip->Play();
	}

	void AudioSource::Stop()
	{
		mAudioClip->Stop();
	}

	void AudioSource::SetLoop(bool loop)
	{
		mAudioClip->SetLoop(loop);
	}
}