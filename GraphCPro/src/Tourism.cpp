#include "Tourism.h"

//文件名
#define VEX_File "Vex.txt"
#define EDGE_File "Edge.txt"

CTourism::CTourism()
{
}

void CTourism::CreatGraph()
{
	cout << "======创建景区景点======" << endl;
	m_Graph.Init();
	ifstream readVex("Vex.txt");
	if (!readVex.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	//读取景点个数
	int nSpotCount = 0;
	//fscanf(pVex, "%d\n", &nSpotCount);
	readVex >> nSpotCount;
	cout << "景点个数" << nSpotCount << endl;
	//读取景区信息
	cout << "------景点------" << endl;
	Vex sVex;
	while (!readVex.eof())
	{
		readVex >> sVex.num >> sVex.name >> sVex.desc;
		//显示景点信息
		cout << sVex.num << "-" << sVex.name << endl;
		//新增景点
		if (!m_Graph.InsertVex(sVex))
		{
			cout << "新增顶点失败!" << endl;
			continue;
		}
	}
	readVex.close();
	fstream readEdge(EDGE_File);
	Edge sEdge;
	while (!readEdge.eof())
	{
		readEdge >> sEdge.vex1 >> sEdge.vex2 >> sEdge.weight;
		if (!m_Graph.InsertEdge(sEdge))
		{
			cout << "景点" << sEdge.vex1 << "与景点" << sEdge.vex2 << "之间连线失败!" << endl;
			continue;
		}
	}
	readEdge.close();
	system("pause");
}

void CTourism::GetSpotInfo()
{
	cout << "======查询景区景点======\n------景点------\t\t\t------信息------" << endl;
	for (int i = 0; i < m_Graph.GetVexNum(); i++)
	{
		Edge sEdge[19] = { {0,0,0} };
		cout << m_Graph.GetVex(i).name << m_Graph.GetVex(i).desc;
		if (m_Graph.FindEdge(i, sEdge) > 0)
		{
			cout << "\t";
			for (int j = 0; sEdge[j].weight != 0; j++)
				cout << "距离" << m_Graph.GetVex(sEdge[j].vex2).name << sEdge[j].weight << "米\t";
			cout << endl;
		}
		cout << endl;
	}
	system("pause");
}

void CTourism::TravelPath()
{
	cout << "======旅游景点导航======" << endl;
	for (int i = 0; i < m_Graph.GetVexNum(); i++)
	{
		cout << m_Graph.GetVex(i).num << "-" << m_Graph.GetVex(i).name << endl;
	}
	cout << "请输入导航起点编号:";
	int nVex;
	cin >> nVex;
	if (nVex < 0 && nVex >= m_Graph.GetVexNum())
	{
		cout << "编号输入错误，导航失败!";
		return;
	}
	/*PathList head = (PathList)malloc(sizeof(Path)), pList = head;
	*head = { {0},NULL };*/
	m_Graph.DFSTraverse(nVex);
	system("pause");
}

CTourism::~CTourism()
{
}