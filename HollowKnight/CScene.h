#pragma once
class CScene
{
private:
	wstring m_strName; // Scene�̸�

public:
	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName; }

	virtual void update();
	virtual void finaludpate();
	virtual void render(HDC _dc);

	virtual void Enter() = 0; // Scene ����
	virtual void Exit() = 0; // Scene Ż��

public:
	CScene();
	virtual ~CScene();


};

