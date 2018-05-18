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
	int num;//景点编号
	string name;//景点名称
	string desc;//景点介绍
};
struct Edge
{
	int vex1;//边的第一个顶点
	int vex2;//边的第二个顶点
	int weight;//权值
};
class CGraph
{
private:
	Vex m_Vexs[20] = { {0,"","" } };//景点数组
	int m_nVexs = 0;//图的顶点个数
	int m_Ljjz[20][20] = { {0} };//邻接矩阵
	Line AllPath[20] = { {{0},0} };//保存导航的所有路线
	int count = 0;//做统计路径用
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