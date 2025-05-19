#include "pch.h"
#include "SceneManager.h"
#include "CMenuScene.h"
#include "CStartScene.h"

SceneManager::SceneManager() : m_arrScene{}, m_pCurScene(nullptr)
{

}

SceneManager::~SceneManager()
{
	// �� ����
	for (UINT i = 0; i < (UINT)SCENE_TYPE::END; ++i)
	{
		if (nullptr != m_arrScene[i])
			delete m_arrScene[i];
	}
}

void SceneManager::init()
{
	// Scene ����
	m_arrScene[(UINT)SCENE_TYPE::MAINMENU] = new CMenuScene;
	m_arrScene[(UINT)SCENE_TYPE::MAINMENU]->SetName(L"MainMenu");
    m_arrScene[(UINT)SCENE_TYPE::STARTMAP] = new CStartScene;
    m_arrScene[(UINT)SCENE_TYPE::STARTMAP]->SetName(L"StartScene");
	m_pCurScene = m_arrScene[(UINT)SCENE_TYPE::MAINMENU];
	m_pCurScene->Enter();
}

void SceneManager::update()
{
    m_pCurScene->update();
}

void SceneManager::render(HDC _dc)
{
    m_pCurScene->render(_dc);
}

void SceneManager::ChangeScene(SCENE_TYPE _eNext)
{
    m_pCurScene->Exit();
    m_pCurScene = m_arrScene[(UINT)_eNext];
    m_pCurScene->Enter();
}
