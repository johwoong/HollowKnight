#include "pch.h"
#include "CStartScene.h"
#include "CTexture.h"
#include "ResourceManager.h"
#include "CGame.h"

CStartScene::CStartScene()
{
}

CStartScene::~CStartScene()
{
}

void CStartScene::update()
{
}

void CStartScene::render(HDC _dc)
{
    CTexture* backgroundTex
        = ResourceManager::GetInst()
        ->LoadTexture(L"StartScene", L"texture\\StartScene.bmp");
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

void CStartScene::Enter()
{

}

void CStartScene::Exit()
{
}

