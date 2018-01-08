#include "Pairing_Heap_Node.h"



Pairing_Heap_Node::Pairing_Heap_Node(int value_, int id_):
	value(value_), id(id_), Left(this), Right(this), Father(nullptr), Child(nullptr) {}


Pairing_Heap_Node::~Pairing_Heap_Node(){

}

void Pairing_Heap_Node::cut_child(Pairing_Heap_Node *c) {
	if (c->Father != this) return;
	//�����ӽڵ㲻��c,ֱ��ɾ��
	if (Child != c) {
		c->Left->Right = c->Right;
		c->Right->Left = c->Left;
		return;
	}
	//�����ӽڵ���c���ҽ���һ�����ӽڵ㣬�����ӽڵ���Ϊ��
	if (c->Left == c) {
		Child = nullptr;
		return;
	}
	//�����ӽڵ���c���ҽ�����һ�����ӽڵ㣬�����ӽڵ���Ϊc����һ���ֵ�
	Child = c->Right;
	c->Left->Right = c->Right;
	c->Right->Left = c->Left;
}

void Pairing_Heap_Node::link_child(Pairing_Heap_Node *c) {
	//�����ӽڵ�Ϊ�գ����º��ӽڵ�
	if (Child == nullptr) {
		Child = c;
		c->Left = c->Right = c;
		c->Father = this;
		return;
	}
	//����ֱ�Ӳ��뵽���ӽڵ�֮ǰ
	c->Left = Child->Left;
	c->Right = Child;
	Child->Left->Right = c;
	Child->Left = c;

	c->Father = this;
}
