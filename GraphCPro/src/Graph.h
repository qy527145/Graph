#pragma once
#include<iostream>
#include<string>
#include <vector>
#include<fstream>
using namespace std;
typedef struct PathLine
{
	int vexs[20];
	int S;
}Line;
struct Vex
{
	int num;//������
	string name;//��������
	string desc;//�������
};
struct Edge
{
	int vex1;//�ߵĵ�һ������
	int vex2;//�ߵĵڶ�������
	int weight;//Ȩֵ
};
class CGraph
{
private:
	Vex m_Vexs[20] = { {0,"","" } };//��������
	int m_nVexs = 0;//ͼ�Ķ������
	int m_Ljjz[20][20] = { {0} };//�ڽӾ���
	Line AllPath[20] = { {{0},0} };//���浼��������·��
	int count = 0;//��ͳ��·����
public:
	CGraph();
	void Init();
	bool InsertVex(Vex sVex);
	bool InsertEdge(Edge sEdge);
	int GetVexNum();
	Vex GetVex(int nVex);
	int FindEdge(int nVex, Edge sEdge[]);
	void DFS(int nVex, bool bVisited[], int &nIndex, int vexs[]);
	void DFSTraverse(int nVex);
	~CGraph();
};