#include "PlayScene.h"
#include "Engine/SceneManager.h"
#include "Wall.h"
#include "Player.h"
#include "Engine/Camera.h"


//�R���X�g���N�^
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

//������
void PlayScene::Initialize()
{
	Instantiate<Wall>(this);
	Instantiate<Player>(this);
	Camera::SetPosition(XMFLOAT3(7.5, 18, -1));//11
	Camera::SetTarget(XMFLOAT3(7.5, 7, 4));//0
}

//�X�V
void PlayScene::Update()
{
}

//�`��
void PlayScene::Draw()
{
}

//�J��
void PlayScene::Release()
{
}
