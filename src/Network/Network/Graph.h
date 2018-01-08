#pragma once
#include "CSVHandler.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include "json.hpp"
using json = nlohmann::json;

/* �û�����������
   ���ڼ����û�����ϵ��С������
   x[t]��ʾ������t-0.5~t+0.5�ĵ�Ӱ����
   normalization()���ڽ�������һ��
   dot()���ڼ������������ĵ��
*/
struct tensor{
	tensor() {
		for (int i = 0; i < 11; ++i)
			x[i] = 0;
	}
	double x[11];
	void normalization() {
		int cnt = 0;
		for (int i = 0; i < 11; ++i)
			cnt += (int)(x[i] + 1e-8);
		for (int i = 0; i < 11; ++i)
			x[i] /= cnt;
	}
	double dot(tensor& a) {
		double ret = 0;
		for (int i = 0; i < 11; ++i)
			ret += a.x[i] * x[i];
		return ret;
	}
	void clear() {
		for (int i = 0; i < 11; ++i)
			x[i] = 0;
	}
};

/*  ͼ��
    ��Ա����������N������M
	         ������ͨ����Group
			 �ڽӱ�edges
			 �û�����Ӱ���ֵ���ŵ�ӳ��userid,movieid
			 �û�����Ӱ��ŵ����ֵ�ӳ��iduser,idmovie
			 ��Ӱ����moviescores
			 �û�����userscores
			 ĳ����Ӱ�Ĺ�Ӱ�û��б�movieuser
			 ĳ���û��ۿ����ĵ�Ӱ�б�usermovie
	��Ա�������������ݼ�������ͼload_csv()
	         ������ͨ����connected_component()
			 ���Ϊ�ı���ʽprint_text()
			 ���Ϊjson��ʽprint_json()
*/

class Graph {
public:
	Graph();
	~Graph();

	void load_csv(int);
	void connected_component();
	void print_text();
	void print_json();

	int N, M;
	int *Group;
	vector<int> *movieuser, *usermovie;
	int *moviescores;
	tensor *userscores;
	map<string, int> userid, movieid;
	string *iduser, *idmovie;
	vector<pair<int, double>> *edges;
};

