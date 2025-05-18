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

    // 1) 현재 클라이언트 영역 크기 구하기
    RECT rcClient;
    HWND hWnd = CGame::GetInst()->GetMainHwnd();  // CGame이 관리하는 메인 윈도우 핸들
    GetClientRect(hWnd, &rcClient);
    int clientW = rcClient.right - rcClient.left;
    int clientH = rcClient.bottom - rcClient.top;

    // 2) 텍스처 정보
    HDC texDC = backgroundTex->GetDC();
    int texW = backgroundTex->Width();
    int texH = backgroundTex->Height();

    // 3) 고품질 스트레치 모드 설정(Optional)
    SetStretchBltMode(_dc, HALFTONE);

    // 4) 화면 크기에 맞춰 배경 그리기
    StretchBlt(
        _dc,
        0, 0,
        clientW, clientH,   // 동적으로 구한 크기
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

