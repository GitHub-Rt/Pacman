#include "Wall.h"
#include "Engine/Model.h"
#include "Engine/CsvReader.h"
#include "Wall.h"

//コンストラクタ
Wall::Wall(GameObject* parent)
    :GameObject(parent, "Wall")//,hModel_(-1)
{
}

//デストラクタ
Wall::~Wall()
{
}

//初期化
void Wall::Initialize()
{
    //モデルデータのロード
    hModel_[1] = Model::Load("Wall.fbx");
    assert(hModel_[1] >= 0);

    //モデルデータのロード
    hModel_[0] = Model::Load("Floar.fbx");
    assert(hModel_[0] >= 0);

    CsvReader csv;
    csv.Load("Map.csv"); //Mapのデータをロード

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            map_[i][j] = csv.GetValue(i, j);
        }
    }
}

//更新
void Wall::Update()
{
}

//描画
void Wall::Draw()
{
    for (int x = 0; x < 15; x++)                               //Wallの出現の処理
    {
        transform_.position_.x = x;                    //～個マス壁配置
        for (int z = 0; z < 15; z++)                        //Wallの出現の処理

        {
            int type = map_[x][z]; //&&どっちも揃ったら マップにブロックの処理
            transform_.position_.z = z;                   //～個マス壁配置
            Model::SetTransform(hModel_[type], transform_); //配列[0]か[1]で壁か床か調整できる
            Model::Draw(hModel_[type]);                    //配列[0]か[1]で壁か床か調整できる
        }
    }
}

//開放
void Wall::Release()
{
}

//そこは壁かどうか
bool Wall::IsWall(int x, int z)
{
    //return map_[x][z] == 0 ? false : true;       三項演算子

    return map_[x][z] == 1; //x z が１returnで返す

    if (map_[x][z] == 1) //まっぷのｘ、ｚが壁[1]だったらyesかnoでreturn返す
    {
        return false;
    }
    else
    {
        return true;
    }
}
