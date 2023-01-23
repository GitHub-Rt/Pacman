#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Wall.h"



//コンストラクタ
Player::Player(GameObject* parent)
    :GameObject(parent, "Player"), hModel_(-1)
{
}

//デストラクタ
Player::~Player()
{
}

//初期化
void Player::Initialize()
{
    //モデルデータのロード
    hModel_ = Model::Load("Pacman.fbx");
    assert(hModel_ >= 0);
    
    transform_.position_.x = 1.5;
    transform_.position_.z = 1.5;

    transform_.scale_.x *= 1.25f;
    transform_.scale_.y *= 1.25f;
    transform_.scale_.z *= 1.25f;

    pStage = (Wall*)FindObject("Wall");
    assert(pStage != nullptr);
    
    
}

//更新
void Player::Update()
{

    XMVECTOR prevPosition = XMLoadFloat3(&transform_.position_); //ベクトルの変数

    //右キーが押されていたら
    if (Input::IsKey(DIK_RIGHT))
    {
        transform_.position_.x += 0.1;
    }

    //左キーが押されていたら
    if (Input::IsKey(DIK_LEFT))
    {
        transform_.position_.x -= 0.1;
    }

    //上キーが押されていたら
    if (Input::IsKey(DIK_UP))
    {
        transform_.position_.z += 0.1;
    }

    //下キーが押されていたら
    if (Input::IsKey(DIK_DOWN))
    {
        transform_.position_.z -= 0.1;
    }

    //向いている方向にパックマンが向くようにする処理

    //現在のベクトル
    XMVECTOR nowPosition = XMLoadFloat3(&transform_.position_); //ベクトルの変数 現在の位置ベクトル
    
    //今回の移動ベクトル
    XMVECTOR move = nowPosition - prevPosition;

    //移動ベクトルの長さを測る length = 長さ
    XMVECTOR length = XMVector3Length(move);
    
    //0.1以上移動してたなら回転処理をおこなってくださいよー
    if (XMVectorGetX(length) > 0.001f)
    {

        //角度を求めるために長さを1にする(正規化)
        move = XMVector3Normalize(move);

        //基準となる奥向きのベクトル
        XMVECTOR front = { 0, 0, 1, 0 };

        //frontとmoveの内積を求める

        XMVECTOR vecDot = XMVector3Dot(front, move);
        float dot = XMVectorGetX(vecDot);

        //向いている角度を求める（ラジアン）
        float angle = acos(dot);


        //もとから向いているベクトルと動くベクトルの外積 flont向いている move動く cross外積
        XMVECTOR cross = XMVector3Cross(front, move);

        //外積の結果のYがマイナス　＝　下向き　＝左に進んでいる　
        if (XMVectorGetY(cross) < 0)
        {
            angle *= -1;
        }

        //その分回転させる
        transform_.rotate_.y = angle * 180.0f / 3.14f;
    }

    //壁との衝突判定
    int checkX, checkZ;

    //右の当たり判定
    checkX = (int)(transform_.position_.x + 0.3f);
    checkZ = (int)(transform_.position_.z);

    if (pStage->IsWall
    ((int)checkX,(int)checkZ))
    {
       XMStoreFloat3(&transform_.position_, prevPosition);
    }

    //左の当たり判定
    checkX = (int)(transform_.position_.x - 0.3f);
    checkZ = (int)(transform_.position_.z);

    if (pStage->IsWall
    ((int)checkX, (int)checkZ))
    {
        XMStoreFloat3(&transform_.position_, prevPosition);
    }

    //上の当たり判定
    checkX = (int)(transform_.position_.x);
    checkZ = (int)(transform_.position_.z + 0.3f);

    if (pStage->IsWall
    ((int)checkX, (int)checkZ))
    {
        XMStoreFloat3(&transform_.position_, prevPosition);
    }

    //下の当たり判定
    checkX = (int)(transform_.position_.x);
    checkZ = (int)(transform_.position_.z - 0.3f);

    if (pStage->IsWall
    ((int)checkX, (int)checkZ))
    {
        XMStoreFloat3(&transform_.position_, prevPosition);
    }
}

//描画
void Player::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//開放
void Player::Release()
{
}