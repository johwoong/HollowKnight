#pragma once
#include "CScene.h"
class CMenuScene : public CScene
{
private:
	Image* m_Background;
public:
	virtual void update();
	virtual void render(HDC _dc);
	virtual void Enter();
	virtual void Exit();

public:
	CMenuScene();
	~CMenuScene();
};

