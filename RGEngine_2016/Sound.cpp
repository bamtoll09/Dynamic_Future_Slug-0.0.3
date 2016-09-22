#include "Sound.h"
#include "GameManager.h"

Sound::Sound(std::string path) : faid(0), isFaidIn(false), isFaidOut(false)
{
	name = "sound";

	audio = AttachComponent<Components::AudioSource>();
	audio->SetSound(path); // �ݵ�� ���־�� ��

						   // �������� ���� �۾��� �ݵ�� ��� ���Ŀ� �ؾ���.

	audio->Play(); // ���
	audio->SetVolume(0.1f);
}
Sound::Sound(std::string path, int loopcount)
{
	audio = AttachComponent<Components::AudioSource>();

	RGAssetSound->Load(path, loopcount);
	audio->SetSound(path); // �ݵ�� ���־�� ��

	audio->Play();
	audio->SetVolume(0.1f);
}

void Sound::OnUpdate()
{
	if (!GM->isPause)
		if (isFaidIn)
			if (faid < maxSound)
				audio->SetVolume(faid += 0.001);
			else
				isFaidIn = false;
		else if (isFaidOut)
			if (faid > 0)
				audio->SetVolume(faid -= 0.001);
			else
				isFaidOut = false;
}
