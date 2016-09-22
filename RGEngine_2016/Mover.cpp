#include "Mover.h"

CMover::CMover() { }

CMover::CMover(std::string path)
{
	sprite = AttachComponent<Components::SpriteRenderer>();
	sprite->SetTexture(path);
	sprite->GetGameObject()->rotationCenter.SetVector(
		sprite->GetTexture()->GetWidth() / 2.0f,
		sprite->GetTexture()->GetHeight() / 2.0f);
}

void CMover::InitImage(std::string path)
{
	sprite = AttachComponent<Components::SpriteRenderer>();
	sprite->SetTexture(path);

	sprite->GetGameObject()->rotationCenter.SetVector(
		sprite->GetTexture()->GetWidth() / 2.0f,
		sprite->GetTexture()->GetHeight() / 2.0f);
}

void CMover::InitAnimation(std::string path)
{
	animation->PushBackFrame(path);
}
