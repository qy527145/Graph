#include"Graph.h"
#include"Tourism.h"
#include<Windows.h>
int main()
{
	CTourism tourism;
	bool Run = true;
	char key;
	while (Run)
	{
		//界面
		cout << "======景区信息管理系统======" << endl;
		cout << "1.创建景区景点图" << endl;
		cout << "2.查询景点信息" << endl;
		cout << "3.旅游景点导航" << endl;
		cout << "4.搜索最短路径" << endl;
		cout << "5.铺设电路规划" << endl;
		cout << "0.退出" << endl;
		//输入选项
		cout << "请输入操作编号(0-5):";
		cin >> key;
		switch (key)
		{
		case '1':tourism.CreatGraph(); break; //创建景区景点图
		case '2':tourism.GetSpotInfo(); break; //查询景点信息
		case '3':tourism.TravelPath(); break; //旅游景点导航
		case '4':cout << "4"; break; //搜索最短路径
		case '5':cout << "5"; break; //铺设电路规划
		case '0':Run = false; cout << "再见!"; break; //退出
		default:cout << "编号格式错误"; break;
		}
		Sleep(1000);
		system("cls");
	}
	return 0;
}