#pragma once
#include "Engine/GameObject.h"
#include "Wall.h"

//���������Ǘ�����N���X
class Player : public GameObject
{
    const int FRONT_X = 3;
    const int FRONT_Z = 3;

    int hModel_;    //���f���ԍ�

    int map_[15][15];
    Wall* pStage;
    XMFLOAT3 front;

public:
    //�R���X�g���N�^
    Player(GameObject* parent);

    //�f�X�g���N�^
    ~Player();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;


    XMFLOAT3 GetFront() { return front; }
    void SetFront(XMFLOAT3 position) { front = position; }



    void FrontPositon();


};
