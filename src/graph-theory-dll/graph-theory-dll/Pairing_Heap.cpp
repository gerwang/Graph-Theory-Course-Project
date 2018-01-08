#include "Pairing_Heap.h"



Pairing_Heap::Pairing_Heap(){
	root = nullptr;
}

Pairing_Heap::Pairing_Heap(int val, int id) {
	root = new Pairing_Heap_Node(val, id);
}

Pairing_Heap::~Pairing_Heap(){
	while (!empty()) Pop();
}

//�ϲ��Խڵ�a�ͽڵ�bΪ������������
inline Pairing_Heap_Node* Pairing_Heap_Node_Merge(Pairing_Heap_Node* a, Pairing_Heap_Node* b) {
	if (a->get_value() < b->get_value()) {
		a->link_child(b);
		return a;
	}
	else
	{
		b->link_child(a);
		return b;
	}
}
/*
Pairing_Heap_Node* Pairing_Heap_Node_List_Merge(Pairing_Heap_Node* c, Pairing_Heap_Node* End) {
	if (c->get_right() == End)
		return c;
	Pairing_Heap_Node* t = c->get_right();
	Pairing_Heap_Node* u = t->get_right();
	Pairing_Heap_Node *v = Pairing_Heap_Node_Merge(c, t);
	if (u == End) return v;
	return Pairing_Heap_Node_Merge(v, Pairing_Heap_Node_List_Merge(u, End));
}
*/
Pairing_Heap_Node** w = new Pairing_Heap_Node*[20000010];

std::pair<int,int> Pairing_Heap::Pop(){
	if (root == nullptr) {
		std::cout << "Heap is empty but pop!" << std::endl;
		return std::make_pair(0, 0);
	}
	std::pair<int, int> ret = std::make_pair(root->get_value(), root->get_id());

	Pairing_Heap_Node *I = root->get_child();
	Pairing_Heap_Node *J = I;
	//ɾ����
	delete root;
	//���ѿ�
	if (I == nullptr) {
		root = nullptr;
		return ret;
	}
	//�ѽ�ʣһ���ڵ�
	if (I->get_left() == I) {
		root = I;
		root->set_father(nullptr);
		root->set_left(root);
		root->set_right(root);
		return ret;
	}

	//�����Ķ��ӽڵ�ϲ���������С�ڵ���Ϊ�µĸ�
	w[0] = I;
	I = I->get_right();
	int p = 0;
	while (I != J) {
		w[++p] = I;
		I = I->get_right();
	}
	for (int i = 0; i < p; i+=2) {
		w[++p] = Pairing_Heap_Node_Merge(w[i], w[i+1]);
	}
	root = w[p];
	root->set_father(nullptr);
	root->set_left(root);
	root->set_right(root);

	return ret;
}

void Pairing_Heap::Decrease_value(Pairing_Heap_Node *t, int dlt) {
	//��СԪ��Ȩֵ
	int tmp = t->get_value() - dlt;
	t->set_value(tmp);
	if (t == root) return;
	//��Υ���ѵ����ʣ��򽫽ڵ����ӵ�������
	if (tmp < t->get_father()->get_value()) {
		t->get_father()->cut_child(t);
		root = Pairing_Heap_Node_Merge(root, t);
		root->set_father(nullptr);
		root->set_left(root);
		root->set_right(root);
	}
}

Pairing_Heap_Node* Pairing_Heap::Insert(int val, int id) {
	Pairing_Heap *tmp = new Pairing_Heap(val, id);
	Pairing_Heap_Node* ret = tmp->root;
	Merge(tmp);	//����Ԫ�ز����������Ƕѵĺϲ�������ͬ
	delete tmp;
	return ret;
}

void Pairing_Heap::Merge(Pairing_Heap* c) {
	//������һ����Ϊ�յ����
	if (c->root == nullptr) return;
	if (root == nullptr) {
		root = c->root;
		c->root = nullptr;
		return;
	}
	//����ǰ�ѵ���Ϊ���ڵ�Ԫ�ظ�С�Ķ�
	if (c->root->get_value() < root->get_value()) {
		std::swap(c->root, root);
	}
	//�ϲ�
	root->link_child(c->root);
	root->set_father(nullptr);
	root->set_left(root);
	root->set_right(root);
	c->root = nullptr;
}

void Pairing_Heap::clear() {
	while (!empty()) Pop();
}
