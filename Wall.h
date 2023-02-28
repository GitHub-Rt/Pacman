#pragma once
#include "Engine/GameObject.h"

const int MAP_SIZE = 23;


//ステージを管理するクラス
class Wall : public GameObject
{
    const int MAP_ROW = 23;
    const int MAP_COL = 23;



    //int hModel_;    //モデル番号Wallの変数
    //int hModel2_;    //モデル番号Floarの変数

    int hModel_[2]; //[0]床　[1]壁

    int map_[23][23]; //2次元配列




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

    /// <summary>
    /// 壁かどうかを判断
    /// </summary>
    /// <param name="x"></param>
    /// <param name="z"></param>
    /// <returns>壁だったらtrue</returns>
    bool IsWall(int x, int z);

};