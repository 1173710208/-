#include<iostream>
#include<string>
using namespace std;

#define MAX 1000//���ౣ��һǧ��

//��ϵ�˽ṹ��
struct Person {
	string m_Name;
	int m_Sex;//1 man 2 women
	int m_Age;
	string m_Phone;
	string m_Addr;
};

//ͨѶ¼�ṹ��
struct Addressbooks {
	struct Person personArray[MAX];
	int m_Size;//��ǰ�ж�����;
};

//չʾ�˵�
void showMenu();
//�����ϵ��
void addPerson(Addressbooks* ads);
//��ʾ��ϵ��
void showPerson(Addressbooks* ads);
//�����ϵ���Ƿ���� return�����±�i
int isExist(Addressbooks* ads, string name);
//ɾ����ϵ��
void deletePerson(Addressbooks* ads);
//������ϵ��
void findPerson(Addressbooks* ads);
//�޸���ϵ��
void modifyPerson(Addressbooks* ads);
//�޸���ϵ��
void clearPerson(Addressbooks* ads);

int main() {

	Addressbooks ads;
	ads.m_Size = 0;

	int select = 0;
	while (true) {
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1://�����ϵ��
		{
			addPerson(&ads);
			break; 
		}
		case 2://��ʾ��ϵ��
		{
			showPerson(&ads);
			break;
		}
		case 3://ɾ����ϵ��
		{
			deletePerson(&ads);
			break;
		}
		case 4://������ϵ��
		{
			findPerson(&ads);
			break;
		}
		case 5://�޸���ϵ��
		{
			modifyPerson(&ads);
			break;
		}
		case 6://�����ϵ��
		{
			clearPerson(&ads);
			break;
		}
		case 0://�˳�ͨѶ¼
		{
			cout << "��ӭ���´�ʹ�ã�" << endl;
			system("pause");
			return 0;
			break;
		}
		}
	}


	system("pause");
	return 0;
}

//չʾ�˵�
void showMenu()
{
	cout << "**********************" << endl;
	cout << "**** 1.�����ϵ�� ****" << endl;
	cout << "**** 2.��ʾ��ϵ�� ****" << endl;
	cout << "**** 3.ɾ����ϵ�� ****" << endl;
	cout << "**** 4.������ϵ�� ****" << endl;
	cout << "**** 5.�޸���ϵ�� ****" << endl;
	cout << "**** 6.�����ϵ�� ****" << endl;
	cout << "**** 0.�˳�ͨѶ¼ ****" << endl;
	cout << "**********************" << endl;
}
//�����ϵ��
void addPerson(Addressbooks* ads) {
	if (ads->m_Size == MAX) {
		cout << "ͨѶ¼�������޷����"<<endl;
	}
	else {
		//����
		cout << "����������" << endl;
		string name;
		cin >> name;
		ads->personArray[ads->m_Size].m_Name = name;
		//�Ա�
		int sex;
		cout << "�������Ա�" << endl;
		cout << "1 man" << endl;
		cout << "2 woman" << endl;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				ads->personArray[ads->m_Size].m_Sex = sex;
				break;
			}
			else
			{
				cout << "��������������1����2" << endl;
			}
		}
		//����
		cout << "����������" << endl;
		int age;
		cin >> age;
		ads->personArray[ads->m_Size].m_Age = age;
		//�绰
		cout << "������绰" << endl;
		string phone;
		cin >> phone;
		ads->personArray[ads->m_Size].m_Phone= phone;
		//��ַ
		cout << "�������ַ" << endl;
		string address;
		cin >> address;
		ads->personArray[ads->m_Size].m_Addr = address;
		//��������
		ads->m_Size++;
		cout << "new successful" << endl;
		system("pause");
		system("cls");
		
	}

}
//��ʾ��ϵ��
void showPerson(Addressbooks* ads) {
	if (ads->m_Size == 0) {
		cout << "��ǰͨѶ¼û����" << endl;
	}
	else {
		for (int i = 0; i < ads->m_Size; i++) {
			cout << ads->personArray[i].m_Name<<"\t" << (ads->personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t" << ads->personArray[i].m_Age << "\t" << ads->personArray[i].m_Phone << "\t"<< ads->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}
//�����ϵ���Ƿ���� return�����±�i
int isExist(Addressbooks* ads, string name) {
	for (int i = 0; i < ads->m_Size; i++) {
		if (ads->personArray[i].m_Name == name) {
			return i;
		}
	}
	return -1;
}
//ɾ����ϵ��
void deletePerson(Addressbooks* ads) {
	if (ads->m_Size == 0) {
		cout << "��ǰͨѶ¼û����" << endl;
		return;
	}
	cout << "������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(ads, name);
	if (ret!=-1) {
		for (int i = ret; i < ads->m_Size; i++) {
			ads->personArray[i] = ads->personArray[i + 1];
		}
		ads->m_Size--;
		cout << "ɾ���ɹ�" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "���޴���" << endl;
		system("pause");
		system("cls");
	}
}
//������ϵ��
void findPerson(Addressbooks* ads) {
	if (ads->m_Size == 0) {
		cout << "��ǰͨѶ¼û����" << endl;
		return;
	}
	cout << "������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(ads, name);
	if (ret != -1) {
		cout << ads->personArray[ret].m_Name << endl;
		cout << (ads->personArray[ret].m_Sex==1?"��":"Ů") << endl;
		cout << ads->personArray[ret].m_Age << endl;
		cout << ads->personArray[ret].m_Phone << endl;
		cout << ads->personArray[ret].m_Addr<< endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "���޴���" << endl;
		system("pause");
		system("cls");
	}
}
//�޸���ϵ��
void modifyPerson(Addressbooks* ads) {
	if (ads->m_Size == 0) {
		cout << "��ǰͨѶ¼û����" << endl;
		return;
	}
	cout << "������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(ads, name);
	if (ret != -1) {
		//����
		cout << "����������" << endl;
		string name;
		cin >> name;
		ads->personArray[ret].m_Name = name;
		//�Ա�
		int sex;
		cout << "�������Ա�" << endl;
		cout << "1 man" << endl;
		cout << "2 woman" << endl;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				ads->personArray[ret].m_Sex = sex;
				break;
			}
			else
			{
				cout << "��������������1����2" << endl;
			}
		}
		//����
		cout << "����������" << endl;
		int age;
		cin >> age;
		ads->personArray[ret].m_Age = age;
		//�绰
		cout << "������绰" << endl;
		string phone;
		cin >> phone;
		ads->personArray[ret].m_Phone = phone;
		//��ַ
		cout << "�������ַ" << endl;
		string address;
		cin >> address;
		ads->personArray[ret].m_Addr = address;
		system("pause");
		system("cls");
	}
	else {
		cout << "���޴���" << endl;
		system("pause");
		system("cls");
	}
}
//�޸���ϵ��
void clearPerson(Addressbooks* ads) {
	if (ads->m_Size == 0) {
		cout << "��ǰͨѶ¼û����" << endl;
		return;
	}
	cout << "��ȷ��Ҫ���" << endl;
	cout << "1 ȷ��" << endl;
	cout << "0 ȡ��" << endl;
	cout << "��ȷ��Ҫ���" << endl;
	int confirm;
	cin >> confirm;
	if (confirm == 1) {
		ads->m_Size = 0;
		cout << "�����" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "��ȡ�����" << endl;
		system("pause");
		system("cls");

	}
}