#pragma once
#include "Pairing_Heap.h"
#include "ThreadPool.h"
#include <Thread>
#include <queue>
#include <cstring>
#include <algorithm>
#include <iostream>

/*  ͼ ��
    ��Ա����������N������M���ڽӱ�ڵ���ͳ�Ʊ���tot
	         �ڽӱ����飺ͷָ��a,�ڵ�node,��һ���ڵ�nxt,��Ȩֵweight
			 �����INF
	��Ա�������ӱ�addedge()
	         ���㵥Դ���·ShortestPath()
			 �������������MST()
			 ����������Ķ�Betweenness_Centrality()
			 ����������Ķ�Closeness_Centrality()
			 ��Դ���·Floyd()
*/

class Graph {
public:
	Graph(int, int);
	~Graph();
	void addedge(int, int, int);
	int ShortestPath(int, int, int*, int*, long long *path = nullptr);
	int MST(int*, int*);
	//int MST_test(int*, int*);
	void Betweenness_Centrality(double*);
	//void Betweenness_Centrality_test(double*);
	void Closeness_Centrality(double*);
	void Floyd(int**);
	static int INF;
private:
	int N, M, tot;
	int *a, *node, *nxt/*, *to*/;
	int *weight;
};

