#include "Tourism.h"

//�ļ���
#define VEX_File "Vex.txt"
#define EDGE_File "Edge.txt"

CTourism::CTourism()
{
}

void CTourism::CreatGraph()
{
	cout << "======������������======" << endl;
	m_Graph.Init();
	ifstream readVex("Vex.txt");
	if (!readVex.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	//��ȡ�������
	int nSpotCount = 0;
	//fscanf(pVex, "%d\n", &nSpotCount);
	readVex >> nSpotCount;
	cout << "�������" << nSpotCount << endl;
	//��ȡ������Ϣ
	cout << "------����------" << endl;
	Vex sVex;
	while (!readVex.eof())
	{
		readVex >> sVex.num >> sVex.name >> sVex.desc;
		//��ʾ������Ϣ
		cout << sVex.num << "-" << sVex.name << endl;
		//��������
		if (!m_Graph.InsertVex(sVex))
		{
			cout << "��������ʧ��!" << endl;
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
			cout << "����" << sEdge.vex1 << "�뾰��" << sEdge.vex2 << "֮������ʧ��!" << endl;
			continue;
		}
	}
	readEdge.close();
	system("pause");
}

void CTourism::GetSpotInfo()
{
	cout << "======��ѯ��������======\n------����------\t\t\t------��Ϣ------" << endl;
	for (int i = 0; i < m_Graph.GetVexNum(); i++)
	{
		Edge sEdge[19] = { {0,0,0} };
		cout << m_Graph.GetVex(i).name << m_Graph.GetVex(i).desc;
		if (m_Graph.FindEdge(i, sEdge) > 0)
		{
			cout << "\t";
			for (int j = 0; sEdge[j].weight != 0; j++)
				cout << "����" << m_Graph.GetVex(sEdge[j].vex2).name << sEdge[j].weight << "��\t";
			cout << endl;
		}
		cout << endl;
	}
	system("pause");
}

void CTourism::TravelPath()
{
	cout << "======���ξ��㵼��======" << endl;
	for (int i = 0; i < m_Graph.GetVexNum(); i++)
	{
		cout << m_Graph.GetVex(i).num << "-" << m_Graph.GetVex(i).name << endl;
	}
	cout << "�����뵼�������:";
	int nVex;
	cin >> nVex;
	if (nVex < 0 && nVex >= m_Graph.GetVexNum())
	{
		cout << "���������󣬵���ʧ��!";
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