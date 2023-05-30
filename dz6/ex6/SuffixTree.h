#pragma once
#include "STreeNode.h"


// ����� ����������� ������� ��� �������� ������ � ���������� ������ ���������
class SuffixTree
{
	static const char* pszData;	// ��������� �� ����� � ������� ����� �����
	static int N;				// ����� ����� ������
	static STNode* root;		// �������� ������� ������
public:
	// ��������� ����������� �� ���������, �������� ����������� � ������������.
	SuffixTree() = delete;
	SuffixTree(SuffixTree const&) = delete;
	SuffixTree& operator=(SuffixTree const&) = delete;

	// ��������� ���� � ������ ������ ���������
	static void Init(const char* s)
	{
		N = strlen(s);
		pszData = s;
		root = new STNode();

		// ��������� ��� �������� � ������
		for (int i = 0; i < N; i++)
			addSuffix(i);
	}
	static STNode* GetRoot()
	{
		return root;
	}
	// ���������� ������ ������, ��� �������� ��������� ������
	static int GetSize()
	{
		return N;
	}
	// ���������� ��������� �� �����, ��� �������� ��������� ������
	static const char* GetData()
	{
		return pszData;
	}
	static bool Contains(const char* s) {
		STNode* node = root;
		int i = 0;
		int len_of_match;
		while (1) {
			if (node->GetLink(s[i]) == 0) return false; 
			len_of_match = node->GetLink(s[i])->PrefixLen(&s[i]);
			if (len_of_match == strlen(&s[i])) return true;
			else {
				if (!node->GetLink(s[i])->GetTarget()->IsNode()) return false;
				node = node->GetLink(s[i])->GetNode();
				i += len_of_match;
			}
		}
	}
	static int FindPattern(const char* s) {
		if (!Contains(s)) return -1;
		int ASCIcode = (int)s[0];
		string first_suff = (string)*(root->links[ASCIcode]);
		return N - first_suff.length();
	}
private:
	// ��������� �������, ������� ���������� � ������� n � ������ pszData.
	static void addSuffix(int n)
	{
		if (n < 0 || n >= N)
			throw out_of_range("index out of range");
		
		// ������ ����� ������� ����� ���� ���� - ����� ������ ������� ������ ��������;
		// ������� ����� � ������ ������� ��������.
		STLink *pLnk = new STLink(pszData + n, N - n);
		pLnk->SetTarget(new STreeNode(n));

		STNode *node = root;
		while (1)
		{
			// ����� ����, � ������� ��� ��������������� �����
			if (node->GetLink(pszData[n]) == 0)
			{
				node->SetLink(pLnk);
				break;
			}
			else // ����������� �����
			{
				STLink* pLnkCurrent = node->GetLink(pszData[n]);
				int k = pLnkCurrent->PrefixLen(*pLnk);
				// ����� ��������� �������� ��������� ��������
				// �������� �������� ���� �� �����, �.�. ������� ������������� ���������� �������� (\xFF).
				if (k == pLnkCurrent->Length())
				{
					// ��������� ��������� ����� ��������, ������� ������� � ������� �����:
					// 1. �������� ����� �������� �����
					pLnk->LTruncate(k);
					// 2. �������� ������ �������� �� ����� ����������
					n += k;
					// ����� �������� ���� ����� � �������� ��������.
					node = pLnkCurrent->GetNode();
				}
				// ���� ������ ��������� ���������� ������� � �����.
				// ����� ������� ����� ���� � �������� ��� � ������� ����� � ������� k
				else
				{
					// ������� ����� ����
					STreeNode* pnewNode = new STreeNode();

					//� ����� ����� (� ���� ����� �� ����� �����, ������� ����� � �������� ����)
					STLink* pLnkTail = new STLink(*pLnkCurrent);
					// ��������� ���� ����� �����
					pLnkTail->LTruncate(k);
					// ... � ������ ������
					pLnkCurrent->RTruncate(k);
					// �������� ����� �������� �����
					pLnk->LTruncate(k);
					// �������� ������ �������� �� ����� ����������
					n += k;
					// �������� � ������ ����� ����
					pLnkCurrent->SetTarget(pnewNode);
					// � ������ ����� �������� ������� �����
					pnewNode->Node.SetLink(pLnkTail);
					// ���������� � ���� ������� ������������ ��������
					pnewNode->Node.SetLink(pLnk);
					break;
				}
			}
		}
	}
};

