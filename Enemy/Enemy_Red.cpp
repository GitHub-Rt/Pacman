#include "Enemy_Red.h"
#include "../Engine/Model.h"
#include "../Player.h"

#include "../Wall.h"

Enemy_Red::Enemy_Red(GameObject* parent)
	: GameObject(parent,"Enemy_Red"),hModel(-1)
{

}

Enemy_Red::~Enemy_Red()
{

}


void Enemy_Red::Initialize()
{
	hModel = Model::Load("Enemy_Red.fbx");
	assert(hModel >= 0);


	transform_.position_.x = 12;
	transform_.position_.z = 12;

}

void Enemy_Red::Update()
{
	NextPos();
}

void Enemy_Red::Draw()
{
	Model::SetTransform(hModel, transform_);
	Model::Draw(hModel);
}

void Enemy_Red::Release()
{

}

void Enemy_Red::NextPos()
{
	
}