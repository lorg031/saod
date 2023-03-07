#pragma once
#include <cstring>
#include <typeinfo>
using namespace std;

class Str
{
	char* m_pszText;
public:
	const Str& operator = (const Str& s)
	{
		if (&s == this) return *this;
		delete[] m_pszText;
		m_pszText = new char[strlen(s.m_pszText) + 1];
		strcpy_s(m_pszText,
			strlen(s.m_pszText) + 1,
			s.m_pszText);
		return *this;
	}

	Str(const Str& s)
	{
		m_pszText = new char[strlen(s.m_pszText) + 1];
		strcpy_s(m_pszText,
			strlen(s.m_pszText) + 1,
			s.m_pszText);
	}

	Str()
	{
		m_pszText = new char[1] {0};
	}


	operator const char* ()const { return m_pszText; }

	Str(const char* p)
	{
		if (p) {
			m_pszText = new char[strlen(p) + 1];
			strcpy_s(m_pszText, strlen(p) + 1, p);
		}
		else
			m_pszText = new char[1] {0};
	}

	inline Str& operator +=(const char* sz)
	{
		int l1 = strlen(m_pszText);
		int l2 = strlen(sz);
		int n = l1 + l2;
		char* tmp = new char[n + 1];

		//strcpy_s(tmp, l1, m_pszText);
		for (int i = 0; i < l1; i++)
			tmp[i] = m_pszText[i];
		for (int i = l1; i < n; i++)
			tmp[i] = sz[i-l1];
		tmp[n] = 0;
		cout << l1 << " " << l2 << endl;

		//strcpy_s(tmp + l1, l2, sz);
		

		//cout << tmp << " " << "test_tmp" << endl;

		//strcpy(tmp1, tmp);

		//cout << typeid(tmp).name() << "test_type" << endl;

		//strcpy_s(tmp, strlen(sz), sz);

		/*memcpy(tmp, *this, strlen(*this));
		memcpy(tmp + strlen(*this), sz, strlen(sz) + 1);*/

		/*cout << strlen(*this) << "lenthis" << endl;
		cout << n << " " << "testlen" << endl;
		cout << *this << " " << "test_this" << endl;
		cout << tmp << " " << "test_tmp" << endl;*/
		/*cout << length << " " << "test_length" << endl;*/
		/*cout << s << " " << "test_s" << endl;*/

		//*this = Str(tmp);
		//Str *res1 = Str(tmp);
		//Str res = Str(tmp);
		//cout << tmp << " " << "test_tmp" << endl;
		//cout << res << " " << "test_res" << endl;
		//delete tmp;
		/*strcpy(*this, tmp);*/

		delete[] m_pszText;
		m_pszText = tmp;
		//delete[] tmp;
		return *this;

	}

	Str operator +(const char* sz) const {
		int l1 = strlen(m_pszText);
		int l2 = strlen(sz);
		int n = l1 + l2;
		char* tmp = new char[n + 1];

		//strcpy_s(tmp, l1, m_pszText);
		for (int i = 0; i < l1; i++)
			tmp[i] = m_pszText[i];
		for (int i = l1; i < n; i++)
			tmp[i] = sz[i - l1];
		tmp[n] = 0;
		cout << l1 << " " << l2 << "  2" << endl;

		Str res(tmp);
		//cout << tmp << " " << "test_tmp2" << endl;

		return res;
	}

	~Str() { delete[]m_pszText; }
};

	

