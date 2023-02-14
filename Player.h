#pragma once
#include "Engine/GameObject.h"
#include "Wall.h"

//◆◆◆を管理するクラス
class Player : public GameObject
{
    const int FRONT_X = 3;
    const int FRONT_Z = 3;

    int hModel_;    //モデル番号

    int map_[15][15];
    Wall* pStage;
    XMFLOAT3 front;

public:
    //コンストラクタ
    Player(GameObject* parent);

    //デストラクタ
    ~Player();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;


    XMFLOAT3 GetFront() { return front; }
    void SetFront(XMFLOAT3 position) { front = position; }



    void FrontPositon();


};
