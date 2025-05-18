#include "pch.h"
#include "CMenuScene.h"
#include "CTexture.h"
#include "ResourceManager.h"
#include "CGame.h"

CMenuScene::CMenuScene()
{

}

CMenuScene::~CMenuScene()
{

}

void CMenuScene::update()
{
}

void CMenuScene::render(HDC _dc)
{
    CTexture* backgroundTex
        = ResourceManager::GetInst()
        ->LoadTexture(L"BackGround", L"texture\\menuBackground.bmp");
    if (!backgroundTex) return;

    // 1) ���� Ŭ���̾�Ʈ ���� ũ�� ���ϱ�
    RECT rcClient;
    HWND hWnd = CGame::GetInst()->GetMainHwnd();  // CGame�� �����ϴ� ���� ������ �ڵ�
    GetClientRect(hWnd, &rcClient);
    int clientW = rcClient.right - rcClient.left;
    int clientH = rcClient.bottom - rcClient.top;

    // 2) �ؽ�ó ����
    HDC texDC = backgroundTex->GetDC();
    int texW = backgroundTex->Width();
    int texH = backgroundTex->Height();

    // 3) ��ǰ�� ��Ʈ��ġ ��� ����(Optional)
    SetStretchBltMode(_dc, HALFTONE);

    // 4) ȭ�� ũ�⿡ ���� ��� �׸���
    StretchBlt(
        _dc,
        0, 0,
        clientW, clientH,   // �������� ���� ũ��
        texDC,
        0, 0,
        texW, texH,
        SRCCOPY
    );
}

void CMenuScene::Enter()
{

}

void CMenuScene::Exit()
{
}

