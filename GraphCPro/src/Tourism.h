#pragma once
#include"Graph.h"
class CTourism
{
private:
	CGraph m_Graph;

public:
	CTourism();
	void CreatGraph();//��������ͼ
	void GetSpotInfo();//��ѯ������Ϣ
	void TravelPath();//���ξ��㵼��
	~CTourism();
};
