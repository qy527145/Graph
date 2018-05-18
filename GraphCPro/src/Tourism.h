#pragma once
#include"Graph.h"
class CTourism
{
private:
	CGraph m_Graph;

public:
	CTourism();
	void CreatGraph();//创建景点图
	void GetSpotInfo();//查询景点信息
	void TravelPath();//旅游景点导航
	~CTourism();
};
