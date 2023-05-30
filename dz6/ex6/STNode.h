#pragma once
#include "STLink.h"

#define AlphaBetSize 127



class SuffixTree;
// ����� ���������� ����� ������
class STNode
{
	friend class SuffixTree;
	// ������ ����� ������ �������� AlphaBetSize;
	// ����� i-�� ����� ���������� � �������, � ����� i
	STLink **links;	
public:

	STNode() {
		links = new STLink* [AlphaBetSize] {0};
	}
	~STNode() {
		delete[]links;
	}

	// ���������� ����� �� ����, ����� ������� ���������� � ���� i.
	STLink *GetLink(unsigned char i) { return links[i]; }
	void SetLink(STLink *pLnk) { links[(unsigned char)(*pLnk)] = pLnk; }
};


