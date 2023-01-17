#include "PlayScene.h"
#include "Engine/SceneManager.h"
#include "Wall.h"
#include "Player.h"
#include "Engine/Camera.h"


//コンストラクタ
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

//初期化
void PlayScene::Initialize()
{
	Instantiate<Wall>(this);
	Instantiate<Player>(this);
	Camera::SetPosition(XMFLOAT3(7.5, 18, -1));//11
	Camera::SetTarget(XMFLOAT3(7.5, 7, 4));//0
}

//更新
void PlayScene::Update()
{
}

//描画
void PlayScene::Draw()
{
}

//開放
void PlayScene::Release()
{
}
