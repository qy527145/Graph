#include "Graph.h"

CGraph::CGraph()
{
}

void CGraph::Init()
{
	m_nVexs = 0;
	for (int i = 0; i < 20; i++)
	{
		m_Vexs[i] = { 0,"","" };
		for (int j = 0; j < 20; j++)
		{
			m_Ljjz[i][j] = 0;
		}
	}
}

bool CGraph::InsertVex(Vex sVex)
{
	if (m_nVexs == 20)
		return false;
	m_Vexs[m_nVexs++] = sVex;
	return true;
}

bool CGraph::InsertEdge(Edge sEdge)
{
	m_Ljjz[sEdge.vex1][sEdge.vex2] = sEdge.weight;
	m_Ljjz[sEdge.vex2][sEdge.vex1] = sEdge.weight;
	return true;
}

int CGraph::GetVexNum()
{
	return m_nVexs;
}

Vex CGraph::GetVex(int nVex)
{
	return m_Vexs[nVex];
}

int CGraph::FindEdge(int nVex, Edge sEdge[])
{
	int i = 0;
	for (int j = 0; j < 20; j++)
	{
		if (m_Ljjz[nVex][j] > 0)
			sEdge[i++] = { nVex,j,m_Ljjz[nVex][j] };
	}
	return i;
}

void CGraph::DFS(int nVex, bool bVisited[], int & nIndex, int vexs[])
{
	vexs[nIndex++] = nVex;
	bVisited[nVex] = true;
	for (int i = 0; i < GetVexNum(); i++)
	{
		if (m_Ljjz[nVex][i] > 0 && !bVisited[i])
		{
			DFS(i, bVisited, nIndex, vexs);
			bVisited[i] = false;
			nIndex--;
		}
	}

	if (nIndex == GetVexNum())
	{
		cout << "第" << ++count << "条路线:\t";
		int S = 0;
		for (int i = 0; i < GetVexNum(); i++)
		{
			if (i > 0)
			{
				S += m_Ljjz[vexs[i - 1]][vexs[i]];
				cout << "->";
			}
			AllPath[count - 1].vexs[i] = vexs[i];
			cout << GetVex(vexs[i]).name;
		}
		AllPath[count - 1].S = S;
		cout << "\t全程" << S << "米" << endl;
	}
}

void CGraph::DFSTraverse(int nVex)
{
	int nIndex = 0, vexs[20] = { 0 };
	bool bVisited[20] = { false };
	DFS(nVex, bVisited, nIndex, vexs);
	Line minLine = { {0},0 };
	int minIndex = 0;
	for (int i = 0, S = INT_MAX; i < count; i++)
	{
		if (S > AllPath[i].S)
		{
			minLine = AllPath[i];
			minIndex = i + 1;
			S = AllPath[i].S;
		}
	}
	cout << "一共" << count << "条可行路径\n推荐走第" << minIndex << "条：";
	for (int i = 0; i < GetVexNum(); i++)
	{
		if (i > 0)
			cout << "->";
		cout << GetVex(minLine.vexs[i]).name;
	}
	cout << "\t全程" << minLine.S << "米" << endl;
	AllPath[20] = { { { 0 },0 } };
	count = 0;
}

CGraph::~CGraph()
{
}