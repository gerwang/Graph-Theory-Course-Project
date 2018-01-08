#pragma once
#include <algorithm>
#include "Pairing_Heap_Node.h"
#include <list>
#include <cstring>
#include <iostream>

/*  ��Զ���
    ��Ա�������Ѷ��ڵ�ָ��root
	��Ա��������ȡ�Ѷ�Ԫ��Top()
	         �����Ѷ�Ԫ��Pop()
			 ������Ԫ��Insert()
			 �ϲ�������Merge()
			 ��СԪ��ȨֵDecrease_value()
			 ��ն�clear()
			 �ж϶��Ƿ�Ϊ��empty()
*/

class Pairing_Heap {
public:
	Pairing_Heap();
	Pairing_Heap(int, int);
	~Pairing_Heap();
	std::pair<int, int> Top();
	std::pair<int, int> Pop();
	bool empty() const;
	void clear();
	void Decrease_value(Pairing_Heap_Node*, int);
	void Merge(Pairing_Heap*);
	Pairing_Heap_Node* Insert(int, int);
private:
	Pairing_Heap_Node* root;
	//int size;
};

inline std::pair<int, int> Pairing_Heap::Top() { return std::make_pair(root->get_value(), root->get_id()); }
inline bool Pairing_Heap::empty() const { return root == nullptr; }

