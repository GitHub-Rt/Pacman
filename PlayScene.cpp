#include "PlayScene.h"
#include "Engine/SceneManager.h"
#include "Wall.h"
#include "Player.h"
#include "Engine/Camera.h"

#include "Enemy/Enemy_Pink.h"
#include "Enemy/Enemy_Red.h"
#include "Enemy/Enemy_Blue.h"
//#include "Enemy/Enemy_Orange.h"

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
	Camera::SetPosition(XMFLOAT3(10, 30, 0));
	Camera::SetTarget(XMFLOAT3(10, 0, 10));


	Instantiate<Enemy_Red>(this);
	Instantiate<Enemy_Pink>(this);
	Instantiate<Enemy_Blue>(this);
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
