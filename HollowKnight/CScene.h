#pragma once
class CScene
{
private:
	wstring m_strName; // Scene이름

public:
	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName; }

	virtual void update();
	virtual void finaludpate();
	virtual void render(HDC _dc);

	virtual void Enter() = 0; // Scene 진입
	virtual void Exit() = 0; // Scene 탈출

public:
	CScene();
	virtual ~CScene();


};

