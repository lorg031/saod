#pragma once

#include "STNode.h"
// ����� ���������� ���� ������
// ����� ���� ��� ���������� ����� STNode,
//  ��� � ������ - �����

enum class STNodeTypes { SNodeType, IntType };

// �����-����������� ���������� ����� ����� ��������� (STNode) � ������� (int)
class STreeNode
{
public:
	STreeNode() :type(STNodeTypes::SNodeType), Node()
	{
	}

	STreeNode(int N) :type(STNodeTypes::IntType), StartPosition(N)
	{
	}
	~STreeNode() {
		if (type == STNodeTypes::SNodeType) Node.~STNode();
	}
	
	//��������, �������� �� ���� ����������� (STNode). 
	//���� ���, �� ��� ����. ��� �������� - ������ ���������������� ��������
	bool IsNode() { return type == STNodeTypes::SNodeType; }

	// ��� ����� ������� ��� �������� (������� ������ ���������������� ��������)
	operator int() {
		if (type == STNodeTypes::IntType)
			return StartPosition;
		throw runtime_error("Node is not leave.");
	}
	
	STNodeTypes type;
	union {
		STNode Node;
		int StartPosition;
	};
};
