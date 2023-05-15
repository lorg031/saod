#pragma once
#include<iostream>
#include "_str.h";
using namespace std;
class Str {
	_str* m_pStr;
public:
	Str() { m_pStr = new _str; }		//если не копи€, то создаем
	Str(const char* p) {		// новый ресурс
		m_pStr = new _str(p);
	}
	~Str() {
		m_pStr->Release(); 	// Ќе уничтожаем ресурс!
	}				// ”меньшаем счетчик ссылок!

	int len() const {
		return strlen(m_pStr->m_pszData);
	}
	Str(const Str& s)
	{
		m_pStr = s.m_pStr; 	// ссылаемс€ на тот же ресурс
		m_pStr->AddRef(); 	// отмечаем, что сослались
	}
	Str& operator = (const Str& s) {
		if (this != &s) {
			s.m_pStr->AddRef(); // ¬ажен пор€док?!
			m_pStr->Release();
			m_pStr = s.m_pStr;
		}
		return *this;
	}
	Str& operator += (const Str& s) {
		int length = len() + s.len();
		if (s.len() != 0) {
			_str* pstrTmp = new _str;
			delete[] pstrTmp->m_pszData;

			pstrTmp->m_pszData = new char[length + 1];
			strcpy_s(pstrTmp->m_pszData, length + 1, m_pStr->m_pszData);
			strcat_s(pstrTmp->m_pszData, length + 1, s.m_pStr->m_pszData);

			m_pStr->Release();
			m_pStr = pstrTmp;
		}
		return *this;
	}

	operator const char* ()const { return m_pStr->m_pszData; };

	void reverse() {
		int n = this->len();
		if (n > 1 && !isPalindrome(m_pStr->m_pszData, n)) {
			if (this->m_pStr->m_nCount > 1) {				//ѕроверка, есть ли копии; если есть - пам€ть раздел€ем
				_str* strTmp = new _str;
				delete[] strTmp->m_pszData;

				strTmp->m_pszData = new char[n + 1];

				char* strOrig = m_pStr->m_pszData;
				char* strCopy = strTmp->m_pszData;

				for (int begin = 0, end = n - 1; end >= begin; begin++, end--) {
					strCopy[begin] = strOrig[end];
					strCopy[end] = strOrig[begin];
				}
				strCopy[n] = '\0';

				m_pStr->Release();
				m_pStr = strTmp;
			}
			else {												//если копий нет, реверс без раздедени€ пам€ти
				char* str = m_pStr->m_pszData;

				for (int begin = 0, end = n - 1; end >= begin; begin++, end--) {
					char temp = str[begin];
					str[begin] = str[end];
					str[end] = temp;
				}
				cout << "has no copies" << endl;
			}
		}
		else {
			cout << "error: str_len < 2 or palindrome" << endl;
		}
	};

	bool isPalindrome(char str[], int len)
	{
		for (int start = 0, end = len - 1; end >= start; start++, end--) {
			if (str[start] != str[end]) return false;
		}
		return true;
	}
};