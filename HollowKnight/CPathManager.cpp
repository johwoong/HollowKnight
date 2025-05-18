#include "pch.h"
#include "CPathManager.h"
#include "CGame.h"

CPathManager::CPathManager() : m_szContentPath{}
{

}

CPathManager::~CPathManager()
{

}


void CPathManager::init()
{
    GetCurrentDirectory(255, m_szContentPath);

    int iLen = (int)wcslen(m_szContentPath);

    // ���� ������
    for (int i = iLen - 1; i >= 0; --i)
    {
        if (m_szContentPath[i] == '\\')
        {
            m_szContentPath[i] = '\0';
            break;
        }
    }

    wcscat_s(m_szContentPath, 255, L"\\Output\\bin\\content\\");
}

wstring CPathManager::GetRelativePath(const wchar_t* _filePath)
{
    wstring strFilePath = _filePath;

    size_t iAbsLen = wcslen(m_szContentPath);
    size_t iFullLen = strFilePath.length();

    if (iFullLen < iAbsLen)
        return L"";

    // �߶� ��� ���
    wstring strRelativePath = strFilePath.substr(iAbsLen, iFullLen - iAbsLen);

    return strRelativePath;
}
