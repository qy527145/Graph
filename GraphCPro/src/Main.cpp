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
		//����
		cout << "======������Ϣ����ϵͳ======" << endl;
		cout << "1.������������ͼ" << endl;
		cout << "2.��ѯ������Ϣ" << endl;
		cout << "3.���ξ��㵼��" << endl;
		cout << "4.�������·��" << endl;
		cout << "5.�����·�滮" << endl;
		cout << "0.�˳�" << endl;
		//����ѡ��
		cout << "������������(0-5):";
		cin >> key;
		switch (key)
		{
		case '1':tourism.CreatGraph(); break; //������������ͼ
		case '2':tourism.GetSpotInfo(); break; //��ѯ������Ϣ
		case '3':tourism.TravelPath(); break; //���ξ��㵼��
		case '4':cout << "4"; break; //�������·��
		case '5':cout << "5"; break; //�����·�滮
		case '0':Run = false; cout << "�ټ�!"; break; //�˳�
		default:cout << "��Ÿ�ʽ����"; break;
		}
		Sleep(1000);
		system("cls");
	}
	return 0;
}