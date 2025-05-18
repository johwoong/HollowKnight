#pragma once
class CTexture;

class CGame
{
	SINGLE(CGame);
private:
	HWND m_hWnd;
	POINT m_ptResolution;
	HDC m_hDC;

    CTexture* m_pMemTex;
	

public:
	int Init(HWND _hWnd, POINT _ptResolution);
	void Update();

public:
	HWND GetMainHwnd() { return m_hWnd; }
	HDC GetMainDC() { return m_hDC; }
	POINT GetResolution() { return m_ptResolution; }

};

