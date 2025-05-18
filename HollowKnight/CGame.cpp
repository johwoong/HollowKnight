#include "pch.h"
#include "CGame.h"
#include "SceneManager.h"
#include "CPathManager.h"
#include "CTexture.h"
CGame::CGame()
{

}

CGame::~CGame()
{

}

int CGame::Init(HWND _hWnd, POINT _ptResolution)
{
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;
	// �ػ󵵿� �°� ������ ũ�� ����
	RECT rt = { 0, 0, m_ptResolution.x, m_ptResolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
	SetWindowPos(_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);

	m_hDC = GetDC(m_hWnd);


	// Manager �ʱ�ȭ
    CPathManager::GetInst()->init();
	SceneManager::GetInst()->init();

	
	return 0;
}

void CGame::Update()
{
	SceneManager::GetInst()->update();





    // Rendering
    SceneManager::GetInst()->render(m_hDC);
    
}
