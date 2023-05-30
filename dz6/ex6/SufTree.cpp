// SufTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SuffixTree.h"
#include <string>

// �������� ����� �����
string GetLabel(STLink *pLnk)
{
	// �������� ����� �����
	int lnkLen = pLnk->Length();
	// ��������� ������ �� ������
	char ch = ((const char *)(*pLnk))[lnkLen];
	// �������� ��������� �� ������ �����
	char *p = (char*)(const char *)(*pLnk);
	// ������������ �� 0
	p[lnkLen] = 0;
	// ������ ������
	string t = (const char *)(*pLnk);
	// ��������������� ������, ������� �������� 0
	p[lnkLen] = ch;

	return t;
}
//��������� �� ������ � ������� ��� �� �������
void IterateTree(STNode *node, string pref = ". ")
{
	for (int i = 0; i < AlphaBetSize; i++)
	{
		STLink * pLnk = node->GetLink(i);
		if (pLnk != 0)
		{
			// ����� ���������� ���� (�� ����)
			if (pLnk->GetTarget()->IsNode())
			{
				string t = GetLabel(pLnk);
				// ������� � ������� ����� ����� � �������
				t = pref + t + " -> ";
				// �������� ��������� 
				IterateTree(pLnk->GetNode(), t);
			}
			else // ����� ����
			{
				// ������� � ������� ����� ����� � =
				string t = GetLabel(pLnk);
				t = pref + t + "\t = ";
				// ������� ������� ����� � ������ ������� � ������� ��������� � �����
				
				cout << '['; cout.width(2); cout<< (int)*(pLnk->GetTarget()) << ']' << t << '"' << SuffixTree::GetData() + (int)*(pLnk->GetTarget()) << '"' << endl;
			}
		}
	}
}

int main()
{
	// ������ ��� ���������� ������
	char s[] = "barbara_";
	// �������� ��������� ������ (��������������) �� "����������" (=> �� ���� ������� �� �������� �� � ����� ���������).
	s[strlen(s) - 1] = char(AlphaBetSize - 1);

	// ������ ������ ���������
	SuffixTree::Init(s);

	// ������� ������ � �� ����� 
	cout << SuffixTree::GetSize() << ' ' << SuffixTree::GetData() << endl<<endl;

	// �������� �� ������ � ������� ��� �� �������
	IterateTree(SuffixTree::GetRoot());

	cout << endl;

	char check[] = "rba";

	if (SuffixTree::Contains(check) == 0) {
		cout << "String " << check << " is not found" << endl;
	}
	else {
		cout << "String " << check << " is found" << endl;
	}

	cout << SuffixTree::FindPattern("b") << endl;
	cout << SuffixTree::FindPattern("a") << endl;
	cout << SuffixTree::FindPattern("r") << endl;
	cout << SuffixTree::FindPattern("rba") << endl;

    return 0;
}

