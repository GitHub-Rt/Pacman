#pragma once
#include "Engine/GameObject.h"

//ステージを管理するクラス
class Wall : public GameObject
{
    //int hModel_;    //モデル番号Wallの変数
    //int hModel2_;    //モデル番号Floarの変数

    int hModel_[2]; //[0]床　[1]壁

    int map_[15][19]; //2次元配列




public:
    //コンストラクタ
    Wall(GameObject* parent);

    //デストラクタ
    ~Wall();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    //そこは壁？
    bool IsWall(int x, int z);

};