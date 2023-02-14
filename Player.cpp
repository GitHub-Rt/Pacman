#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Wall.h"



//�R���X�g���N�^
Player::Player(GameObject* parent)
    :GameObject(parent, "Player"), hModel_(-1)
{
}

//�f�X�g���N�^
Player::~Player()
{
}

//������
void Player::Initialize()
{
    //���f���f�[�^�̃��[�h
    hModel_ = Model::Load("Pacman.fbx");
    assert(hModel_ >= 0);
    
    transform_.position_.x = 1.5;
    transform_.position_.z = 1.5;

    

    pStage = (Wall*)FindObject("Wall");
    assert(pStage != nullptr);
    
    
}

//�X�V
void Player::Update()
{

    XMVECTOR prevPosition = XMLoadFloat3(&transform_.position_); //�x�N�g���̕ϐ�

    //�E�L�[��������Ă�����
    if (Input::IsKey(DIK_RIGHT))
    {
        transform_.position_.x += 0.1;
    }

    //���L�[��������Ă�����
    if (Input::IsKey(DIK_LEFT))
    {
        transform_.position_.x -= 0.1;
    }

    //��L�[��������Ă�����
    if (Input::IsKey(DIK_UP))
    {
        transform_.position_.z += 0.1;
    }

    //���L�[��������Ă�����
    if (Input::IsKey(DIK_DOWN))
    {
        transform_.position_.z -= 0.1;
    }

    //�����Ă�������Ƀp�b�N�}���������悤�ɂ��鏈��

    //���݂̃x�N�g��
    XMVECTOR nowPosition = XMLoadFloat3(&transform_.position_); //�x�N�g���̕ϐ� ���݂̈ʒu�x�N�g��
    
    //����̈ړ��x�N�g��
    XMVECTOR move = nowPosition - prevPosition;

    //�ړ��x�N�g���̒����𑪂� length = ����
    XMVECTOR length = XMVector3Length(move);
    
    //0.1�ȏ�ړ����Ă��Ȃ��]�����������Ȃ��Ă���������[
    if (XMVectorGetX(length) > 0.001f)
    {

        //�p�x�����߂邽�߂ɒ�����1�ɂ���(���K��)
        move = XMVector3Normalize(move);

        //��ƂȂ鉜�����̃x�N�g��
        XMVECTOR front = { 0, 0, 1, 0 };

        //front��move�̓��ς����߂�

        XMVECTOR vecDot = XMVector3Dot(front, move);
        float dot = XMVectorGetX(vecDot);

        //�����Ă���p�x�����߂�i���W�A���j
        float angle = acos(dot);


        //���Ƃ�������Ă���x�N�g���Ɠ����x�N�g���̊O�� flont�����Ă��� move���� cross�O��
        XMVECTOR cross = XMVector3Cross(front, move);

        //�O�ς̌��ʂ�Y���}�C�i�X�@���@�������@�����ɐi��ł���@
        if (XMVectorGetY(cross) < 0)
        {
            angle *= -1;
        }

        //���̕���]������
        transform_.rotate_.y = angle * 180.0f / 3.14f;
    }

    //�ǂƂ̏Փ˔���
    int checkX, checkZ;

    //�E�̓����蔻��
    checkX = (int)(transform_.position_.x + 0.3f);
    checkZ = (int)(transform_.position_.z);

    if (pStage->IsWall
    ((int)checkX,(int)checkZ))
    {
       XMStoreFloat3(&transform_.position_, prevPosition);
    }

    //���̓����蔻��
    checkX = (int)(transform_.position_.x - 0.3f);
    checkZ = (int)(transform_.position_.z);

    if (pStage->IsWall
    ((int)checkX, (int)checkZ))
    {
        XMStoreFloat3(&transform_.position_, prevPosition);
    }

    //��̓����蔻��
    checkX = (int)(transform_.position_.x);
    checkZ = (int)(transform_.position_.z + 0.3f);

    if (pStage->IsWall
    ((int)checkX, (int)checkZ))
    {
        XMStoreFloat3(&transform_.position_, prevPosition);
    }

    //���̓����蔻��
    checkX = (int)(transform_.position_.x);
    checkZ = (int)(transform_.position_.z - 0.3f);

    if (pStage->IsWall
    ((int)checkX, (int)checkZ))
    {
        XMStoreFloat3(&transform_.position_, prevPosition);
    }
}

//�`��
void Player::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//�J��
void Player::Release()
{
}

void Player::FrontPositon()
{
    XMFLOAT3 Front = transform_.position_;

    Front.x += FRONT_X;
    Front.z += FRONT_Z;

    bool isWall = false;
    while (isWall == false);
    {
        isWall = pStage->IsWall((int)Front.x, (int)Front.z);
        if (isWall == false)
        {
            Front.x -= 1;
            Front.x -= 1;
        }
    } 

    SetFront(Front);
}