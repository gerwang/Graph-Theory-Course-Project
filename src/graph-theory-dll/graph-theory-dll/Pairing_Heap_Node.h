#pragma once

/*  ��Զѽڵ���
    ��Ա������Ԫ��Ȩֵvalue
	         Ԫ�ر��id
			 �����ֵܽڵ�Left��Right
			 ���׽ڵ�Father
			 ���ӽڵ�Child
	��Ա��������ȡ������Ԫ��Ȩֵ get_value(), set_value()
	         ��ȡ������Ԫ�ر�� get_id(), set_id()
			 ��ȡ���������Һ��ӽڵ� get_left(), get_right(), set_left(), set_right()
			 ��ȡ�����ø��ڵ� get_father(), set_father()
			 ��ȡ�����ú��ӽڵ� get_child(), set_child()
			 �ж�ĳ�����ӽڵ�cut_child()
			 ����ĳ�����ӽڵ�link_child()
*/

class Pairing_Heap_Node {
public:
	Pairing_Heap_Node(int, int);
	~Pairing_Heap_Node();
	void cut_child(Pairing_Heap_Node*);
	void link_child(Pairing_Heap_Node*);
	int get_value()const;
	int get_id()const;
	Pairing_Heap_Node* get_left()const;
	Pairing_Heap_Node* get_right()const;
	Pairing_Heap_Node* get_father()const;
	Pairing_Heap_Node* get_child()const;
	void set_value(int);
	void set_id(int);
	void set_left(Pairing_Heap_Node*);
	void set_right(Pairing_Heap_Node*);
	void set_father(Pairing_Heap_Node*);
	void set_child(Pairing_Heap_Node*);
private:
	int id;
	int value;
	Pairing_Heap_Node *Left, *Right, *Father, *Child;
};

inline int Pairing_Heap_Node::get_value() const { return value; }
inline int Pairing_Heap_Node::get_id() const { return id; }
inline Pairing_Heap_Node* Pairing_Heap_Node::get_left()const { return Left; }
inline Pairing_Heap_Node* Pairing_Heap_Node::get_right()const { return Right; }
inline Pairing_Heap_Node* Pairing_Heap_Node::get_father()const { return Father; }
inline Pairing_Heap_Node* Pairing_Heap_Node::get_child()const { return Child; }
inline void Pairing_Heap_Node::set_value(int value_) { value = value_; }
inline void Pairing_Heap_Node::set_id(int id_) { id = id_; }
inline void Pairing_Heap_Node::set_left(Pairing_Heap_Node* left_) { Left = left_; }
inline void Pairing_Heap_Node::set_right(Pairing_Heap_Node* right_) { Right = right_; }
inline void Pairing_Heap_Node::set_father(Pairing_Heap_Node* father_) { Father = father_; }
inline void Pairing_Heap_Node::set_child(Pairing_Heap_Node* child_) { Child = child_; }
