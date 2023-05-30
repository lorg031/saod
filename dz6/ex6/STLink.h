#pragma once
#include <assert.h>
#include "STreeNode.h"

class STreeNode;
class STNode;

// ����� ����� ��� ����� ������ ��������
class Label
{
public:
	// ��������� ������ ����� � ������
	const char *pos;
	// ����� �����
	int len;
	Label(const char *p, int len) :pos(p), len(len) {}
};
// ����� ����� ��� ������ ���������
class STLink
{
	Label lbl;
	STreeNode *pTarget;
public:

	STLink(const char *p, int len) :lbl(p, len)
	{
	}
	~STLink() {}

	operator const char *() const { return lbl.pos; }
	operator const char () const { return *lbl.pos; }
	
	// ����������� �������� ���� �����
	void SetTarget(STreeNode *p) {
		pTarget = p;
	}
	// �������� �������� ���� �����
	STreeNode *GetTarget() {
		return pTarget;
	}
	// ���������� ����� ����� �����
	int Length() { return lbl.len; }

	// �������� ��������� �� �������� ���� �����, ���� �� ����
	// ��� ����� ���������� ����������
	STNode *GetNode() const;

	// ��������� ����� �������� ������ s, ������������ � ��������� �����
	int PrefixLen(const char * s) const
	{
		for (int i = 0; i < lbl.len; i++)
			if (s[i] != lbl.pos[i])
				return i;
		return lbl.len;
	}

	// �������� ����� ����� �� n �������� �����.
	// ��������� ������ � ��������� �����
	void LTruncate(int n)
	{
		assert(n < lbl.len);
		lbl.pos += n;
		lbl.len -= n;
	}
	// �������� ����� ����� �� n �������� ������.
	// ��������� ������, �� ��������� �����
	void RTruncate(int n)
	{
		lbl.len = n;
	}
};

