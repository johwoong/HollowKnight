#pragma once
#include "CScene.h"
class CStartScene :
    public CScene
{
private:
    Image* m_map;
public:
    virtual void update();
    virtual void render(HDC _dc);
    virtual void Enter();
    virtual void Exit();

public:
    CStartScene();
    ~CStartScene();
};

