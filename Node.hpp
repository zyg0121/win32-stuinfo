#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <fstream>
#include "Student.hpp"
using namespace std;
class Node { //�����
	public:
		void InputStudent();//����ѧ����Ϣ
		void OutputStudent();//���ѧ����Ϣ
		void AddStudent();//����ѧ����Ϣ
		void DeleteStudent();//ɾ��ѧ����Ϣ
		void ChangeStudent();//�޸�ѧ����Ϣ
		void SearchStudent();//����ѧ����Ϣ
		void SortScore();//���ɼ����մӴ�С����
		void SortNum();//��ѧ�Ű��մӴ�С����
		void SetScore();//��������
		void FileOutputStudent();//��ѧ����Ϣд���ļ� 

	private:
		Student st;//������
		Node *pNext;//ָ����
		Node *pHead;//ͷ���
};
typedef Node NODE;
typedef Node* PNODE;
/*
NODE �൱��  Node
PNODE �൱�� Node*
*/


//����ѧ����Ϣ
void Node::InputStudent()
{
	//����һ��ͷ���
	pHead = new NODE[sizeof(NODE)];

	if (NULL == pHead)
	{
		cout << "��̬�ڴ����ʧ��,������ֹ!" << endl;

		exit(0);
	}

	PNODE pTail = pHead;//����һ��ָ��ͷ����ָ��
	pTail->pNext = NULL;//��ʼ��ָ���ָ����ΪNULL

	//���ļ��е��������뵽������
	ifstream infile("score.dat", ios::in);

	if (!infile)
	{
		cout << "�ļ���ʧ��,������ֹ!" << endl;

		exit(0);
	}
	int l; 
	string name;//����
	string age;//����
	long long number;//ѧ��
	float score;//�ɼ�
	string gender;//�Ա�
	int bir;//����YYYYMMDD
	string address;//��ַ
	long long tel; //�绰���� 1XXXXXXXXXX
	string email;//�ʼ�

	cout << "������ѧ��������:";
	cin >> l;


	for (int i = 1; i <= l; i++)
	{
		//����һ���������ݵ��½��
		PNODE pNew = new NODE[sizeof(NODE)];

		if (NULL == pNew)
		{
			cout << "��̬�ڴ����ʧ��,������ֹ!" << endl;

			exit(0);
		}

		//��ȡ�ļ��е�����
		infile >> name >> age >> number >> gender >> bir >> address >> tel >> email >> score;

		//��ʼ�����
		//pNew->st.SetLen(l);//ѧ��������
		pNew->st.SetName(name);//ѧ��������
		pNew->st.SetAge(age);//ѧ��������
		pNew->st.SetNo(number);//ѧ����ѧ��
		pNew->st.SetGen(gender);//����ѧ�����Ա�
		pNew->st.SetBir(bir); //����ѧ��������
		pNew->st.SetAdd(address);//����ѧ���ĵ�ַ
		pNew->st.SetTel(tel); //����ѧ���ĵ绰
		pNew->st.SetEmail(email);//����ѧ�����ʼ�
		pNew->st.Setscore(score);//����ѧ���ĳɼ�

		pTail->pNext = pNew;//��pNew�����Ͻ��ĺ���
		pTail = pNew;//��ָ��pTail�Ƶ�pNew��
		pTail->pNext = NULL;//���ָ����
	}

	//�ر��ļ�
	infile.close();

	cout << "�Ѿ��ɹ����������������" << l << "��ѧ������Ϣ" << endl;
}


void Node::OutputStudent()
{
    PNODE p = pHead->pNext;
 
	cout << "ѧ��\t\t" << "����\t" << "����\t" << "�Ա�\t" << "����\t\t" << "��ַ\t" << "�绰����\t" << "�ʼ�\t\t\t" << "�ɼ�\t"<< "����" << endl;
 
    string nm;//����
	string age;//����
	long long nu;//ѧ��
	float score;//�ɼ�
	string gender;//�Ա�
	int bir;//����YYYYMMDD
	string address;//��ַ
	long long tel; //�绰���� 1XXXXXXXXXX
	string email;//�ʼ�
 
    //����ѧ����Ϣ
    while(NULL != p)
    {	
    	p->st.GetName(&nm);
        p->st.GetAge(&age);//�õ�ѧ������
		p->st.Getgen(&gender);//�õ��Ա�
		p->st.GetBir(&bir);//�õ�����
		p->st.GetAdd(&address);//�õ�ѧ���ĵ�ַ
		p->st.GetTel(&tel); //�õ�ѧ���ĵ绰
		p->st.GetEmail(&email);//�õ�ѧ�����ʼ�
		p->st.GetScore(&score); //�õ��ɼ�
 

			cout << p->st.GetNo() << "\t" << nm << "\t" << age << "\t" << gender << "\t" << bir
				<< "\t" << address << "\t" << tel << "\t" << email << "\t" << score << "\t" << p->st.GetS() << endl;
 
        p = p->pNext;
    }
}

void Node::FileOutputStudent()
{
	PNODE p = pHead->pNext;

	cout << "ѧ��\t\t" << "����\t" << "����\t" << "�Ա�\t" << "����\t\t" << "��ַ\t" << "�绰����\t" << "�ʼ�\t\t\t" << "�ɼ�\t" << "����" << endl;

	ofstream outfile("score.dat", ios::out);

	if (!outfile)
	{
		cout << "�ļ���ʧ��,������ֹ!" << endl;

		exit(0);
	}

	string nm;//����
	string age;//����
	long long nu;//ѧ��
	float score;//�ɼ�
	string gender;//�Ա�
	int bir;//����YYYYMMDD
	string address;//��ַ
	long long tel; //�绰���� 1XXXXXXXXXX
	string email;//�ʼ�

	//����ѧ����Ϣ
	while (NULL != p)
	{
		p->st.GetName(&nm);
		p->st.GetAge(&age);//�õ�ѧ������
		p->st.Getgen(&gender);//�õ��Ա�
		p->st.GetBir(&bir);//�õ�����
		p->st.GetAdd(&address);//�õ�ѧ���ĵ�ַ
		p->st.GetTel(&tel); //�õ�ѧ���ĵ绰
		p->st.GetEmail(&email);//�õ�ѧ�����ʼ�
		p->st.GetScore(&score); //�õ��ɼ�


		cout << p->st.GetNo() << "\t" << nm << "\t" << age << "\t" << gender << "\t" << bir
			<< "\t" << address << "\t" << tel << "\t" << email << "\t" << score << "\t" << p->st.GetS() << endl;

		outfile << nm << " " << age << " " << p->st.GetNo() << " " << gender << " " << bir
			<< " " << address << " " << tel << " " << email << " " << score << endl;

		p = p->pNext;
	}
	outfile.close();
}


void Node::AddStudent(void)//����ѧ����Ϣ
{
	PNODE p = pHead->pNext;
	Student st;//����һ��ѧ����

	string name;//����
	string age;//����
	long long no;//ѧ��
	float score;//�ɼ�
	string gender;//�Ա�
	int bir;//����YYYYMMDD
	string address;//��ַ
	long long tel; //�绰���� 1XXXXXXXXXX
	string email;//�ʼ�
	int sort;//����

	cout << "������ѧ����ѧ��:" << endl;
	cin >> no;

	cout << "������ѧ��������" << endl;
	cin >> name;

	cout << "������ѧ��������" << endl;
	cin >> age;

	cout << "������ѧ�����Ա�" << endl;
	cin >> gender;

	cout << "������ѧ��������" << endl;
	cin >> bir;

	cout << "������ѧ���ľ�ס��ַ" << endl;
	cin >> address;

	cout << "������ѧ���ĵ绰����" << endl;
	cin >> tel;
	
	cout << "������ѧ��������" << endl;
	cin >> email;

	while(1)
	{
		cout << "������ѧ���ĳɼ�:"  << endl;
		cin >> score;
		if(score < 0 || score > 100)
			cout << "�ɼ����Ϸ�������������" << endl;
		else
			break;
	}
	PNODE pt = new NODE[sizeof(NODE)];

	if (NULL == pt)
	{
		printf("��̬�ڴ����ʧ��,������ֹ!\n");
		exit(-1);
	}

	//��ʼ�����
	pt->st.SetName(name);//ѧ��������
	pt->st.SetAge(age);//ѧ��������
	pt->st.SetNo(no);//ѧ����ѧ��
	pt->st.SetGen(gender);//����ѧ�����Ա�
	pt->st.SetBir(bir);//����ѧ��������
	pt->st.SetAdd(address);//����ѧ���ĵ�ַ
	pt->st.SetTel(tel); //����ѧ���ĵ绰
	pt->st.SetEmail(email); //����ѧ�����ʼ� 
	pt->st.Setscore(score);//����ѧ���ĳɼ�

	while (p->pNext != NULL)
	{
		p = p->pNext;
	}
	p->pNext = pt;
	pt->pNext = NULL;

}

void Node::DeleteStudent()//ɾ��ѧ����Ϣ
{
	long long exp;//Ҫɾ����Ϣ��ѧ��ѧ�� 
	PNODE p, be, bp;

	cout << "������Ҫɾ����ѧ����ѧ��:";
	cin >> exp;
	p = pHead; //ָ��ͷ��� 
	
	be = bp = p;
	while (exp != bp->st.GetNo() && bp->pNext != NULL)//����Ҫɾ���Ľڵ� 
	{
		be = bp;
		bp = bp->pNext;
	}
	if (exp == bp->st.GetNo())//�ҵ���ѧ����Ϣ 
	{
		be->pNext = bp->pNext;
		delete[]bp;
		cout << "�ѳɹ�ɾ����ѧ����Ϣ" << endl;
	}
	else
		cout << "���޴���" << endl;
}

void Node::ChangeStudent()//�޸�ѧ����Ϣ
{
	PNODE p = pHead->pNext;

	string name;//����
	string age;//����
	long long nu;//�޸�ǰ��ѧ��
	long long nu2;//�޸ĺ��ѧ��
	float score;//�ɼ�
	string gender;//�Ա�
	int bir;//����YYYYMMDD
	string address;//��ַ
	long long tel; //�绰���� 1XXXXXXXXXX
	string email;//�ʼ�

	int flag = 0;//��ʶ��,��ʼ����ʾû�ҵ�
	int select;
	cout << "����������Ҫ�޸ĵ�ѧ��������:";
	cin >> name;

	string nm;//����

	//����ѧ����Ϣ
	while (p != NULL)
	{
		//�õ�ѧ��������
		p->st.GetName(&nm);

		if (name == nm)
		{
			flag = 1;
			p->st.GetAge(&age);//�õ�ѧ������
			nu = p->st.GetNo();//�õ�ѧ����ѧ��
			p->st.Getgen(&gender);//�õ��Ա�
			p->st.GetBir(&bir);//�õ�����
			p->st.GetAdd(&address);//�õ�ѧ���ĵ�ַ
			p->st.GetTel(&tel); //�õ�ѧ���ĵ绰
			p->st.GetEmail(&email);//�õ�ѧ�����ʼ�
			p->st.GetScore(&score); //�õ��ɼ�
			cout << "\n�޸�ǰ��ѧ����Ϣ:" << endl;

			cout << "ѧ��\t\t" << "����\t" << "����\t" << "�Ա�\t" << "����\t\t" << "��ַ\t" << "�绰����\t" << "�ʼ�\t\t\t" << "�ɼ�\t"<< "����" << endl;

			cout << nu << "\t" << nm << "\t" << age << "\t" << gender << "\t" << bir
				<< "\t" << address << "\t" << tel << "\t" << email << "\t" << score << "\t" << p->st.GetS() << endl;

			break;
		}

		p = p->pNext;
	}

	if (flag == 0)
	{
		cout << "û�ҵ�����Ҫ�޸ĵ�ѧ����Ϣ!\n" << endl;
	}
	else
	{ 
			cout << "��ѡ��Ҫ�޸ĵ�����" << endl;
			cout << "===============================================================================\n\n";
			cout << "-------------------------- 1 ����--------------------------------------\n\n";
			cout << "-------------------------- 2 ѧ��--------------------------------------\n\n";
			cout << "-------------------------- 3 �Ա�--------------------------------------\n\n";
			cout << "-------------------------- 4 ����--------------------------------------\n\n";
			cout << "-------------------------- 5 ����--------------------------------------\n\n";
			cout << "-------------------------- 6 ��ַ--------------------------------------\n\n";
			cout << "-------------------------- 7 �绰����----------------------------------\n\n";
			cout << "-------------------------- 8 �ʼ�--------------------------------------\n\n";
			cout << "-------------------------- 9 �ɼ�--------------------------------------\n\n";
			cout << "-------------------------- 0 ȫ��--------------------------------------\n\n";
			cout << "===============================================================================\n\n";
			
			cin >> select;
		switch(select)
		{
			case 1:
			{
				cout << "�������µ�����:";
				cin >> name;
				p->st.SetName(name);//����ѧ��������
			}
			break;
			case 2:
			{
				cout << "�������µ�ѧ�ţ�";
				cin >> nu2; 
				p->st.SetNo(nu2);//����ѧ����ѧ�� 
			}
			break;
			case 3:
			{
				cout << "�������µ��Ա�:"; 
				cin >> gender;
			}
			break;
			case 4:
			{
				cout << "�������µ�����:";
				cin >> age; 
				p->st.SetAge(age);//����ѧ��������
			}
			break;
			case 5:
			{
				cout << "�������µ�����:";
				cin >> bir; 
				p->st.SetBir(bir);//����ѧ��������
			}
			break;
			case 6:
			{
				cout << "�������µĵ�ַ:";
				cin >> address;
				p->st.SetAdd(address);//����ѧ���ĵ�ַ
			}
			break;
			case 7:
			{
				cout << "�������µĵ绰:"; 
				cin >> tel;
				p->st.SetTel(tel); //����ѧ���ĵ绰
			}
			break;
			case 8:
			{
				cout << "�������µ��ʼ�:";
				cin >> email; 
				p->st.SetEmail(email);//����ѧ�����ʼ�
			}
			break;
			case 9:
			{
				while(1)
				{
				cout << "�������µĳɼ�:"; 
				cin >> score;
				if(score < 0 || score > 100)
					cout << "�ɼ����Ϸ�������������" << endl;
				else
				{
				p->st.Setscore(score);//����ѧ���ĳɼ�
				break;
				}
			}
			break;
			case 0:
			{
				cout << "\n�㽫�޸�ѧ��Ϊ" << nu << "��ѧ����Ϣ" << endl;
	
			cout << "�������µ�ѧ��:";
			cin >> nu2;
	 
			cout << "������ѧ��Ϊ" << nu2 << "��ѧ��������:";
			cin >> name;

			cout << "������ѧ��Ϊ" << nu2 << "��ѧ��������:";
			cin >> age;

			cout << "������ѧ��Ϊ" << nu2 << "��ѧ�����Ա�:";
			cin >> gender;

			cout << "������ѧ��Ϊ" << nu2 << "��ѧ��������:";
			cin >> bir;

			cout << "������ѧ��Ϊ" << nu2 << "��ѧ���ĵ�ַ:";
			cin >> address;

			cout << "������ѧ��Ϊ" << nu2 << "��ѧ���ĵ绰����:";
			cin >> tel;

			cout << "������ѧ��Ϊ" << nu2 << "��ѧ��������:";
			cin >> email;

			while(1)
			{
				cout << "������ѧ��Ϊ" << nu2 << "��ѧ���ĳɼ�:";
				cin >> score;
				if(score < 0 || score > 100)
					cout << "�ɼ����Ϸ�������������" << endl;
				else
					break;
			}
			
			p->st.SetNo(nu2);//����ѧ����ѧ�� 
			p->st.SetName(name);//����ѧ��������
			p->st.SetAge(age);//����ѧ��������
			p->st.SetGen(gender);//����ѧ�����Ա�
			p->st.SetBir(bir);//����ѧ��������
			p->st.SetAdd(address);//����ѧ���ĵ�ַ
			p->st.SetTel(tel); //����ѧ���ĵ绰
			p->st.SetEmail(email);//����ѧ�����ʼ�
			p->st.Setscore(score);//����ѧ���ĳɼ�
			}
			default:
				break;
			}
		}
	cout << "�޸ĳɹ���" << endl;

	}
}

void Node::SearchStudent()//����ѧ����Ϣ
{
	PNODE p = pHead->pNext;

	string nm;//����

	int flag = 0;//��ʶ��,��ʼ����ʾû�ҵ�

	cout << "����������Ҫ���ҵ�ѧ��������:";
	cin >> nm;

	cout << "ѧ��\t\t" << "����\t" << "����\t" << "�Ա�\t" << "����\t\t" << "��ַ\t" << "�绰����\t" << "�ʼ�\t\t\t" << "�ɼ�\t"<< endl;

	string name;//����
	string age;//����
	long long nu;//ѧ��
	float score;//�ɼ�
	string gender;//�Ա�
	int bir;//����YYYYMMDD
	string address;//��ַ
	long long tel; //�绰���� 1XXXXXXXXXX
	string email;//�ʼ�

	//����ѧ����Ϣ
	while (p != NULL)
	{
		//�õ�ѧ��������������
		p->st.GetName(&name);

		if (name == nm)
		{
			flag = 1;
			p->st.GetAge(&age);//�õ�ѧ������
			nu = p->st.GetNo();//�õ�ѧ����ѧ��
			p->st.Getgen(&gender);//�õ��Ա�
			p->st.GetBir(&bir);//�õ�����
			p->st.GetAdd(&address);//�õ�ѧ���ĵ�ַ
			p->st.GetTel(&tel); //�õ�ѧ���ĵ绰
			p->st.GetEmail(&email);//�õ�ѧ�����ʼ�
			p->st.GetScore(&score); //�õ��ɼ�
			cout << nu << "\t" << nm << "\t" << age << "\t" << gender << "\t" << bir
				<< "\t" << address << "\t" << tel << "\t" << email << "\t" << score << "\t" << endl;

			break;//�˳�ѭ��
		}

		p = p->pNext;
	}

	if (flag == 0)
	{
		cout << "û�ҵ�����Ҫ��ѧ����Ϣ!" << endl;
	}
}

void Node::SortScore()//���ɼ����մӴ�С����
{
	PNODE p, q;//��������ָ��


	NODE temp;//����һ����ʱ���

	float c1, c2;//ѧ���ɼ�

	for (p = pHead->pNext; p != NULL; p = p->pNext)//ð������ 
	{
		for (q = p->pNext; q != NULL; q = q->pNext)
		{
			p->st.GetScore(&c1);
			q->st.GetScore(&c2);

			if (c1 < c2)//��ǰһ��ѧ���ĳɼ�С�ں�һ��ѧ���ĳɼ�ʱ
			{
				temp.st = p->st;//����ѧ����λ��
				p->st = q->st;
				q->st = temp.st;
			}
		}
	}
}
void Node::SetScore()//��������
{
	PNODE p;//����һ��ָ�����ָ��
	int i;//��������

	//��ѧ����������ֵ
	for (p = pHead->pNext, i = 1; NULL != p; p = p->pNext, i++)
	{
		p->st.SetS(i);
	}
}

void Node::SortNum()//��ѧ�Ű��մ�С��������
{
	PNODE p, q;//��������ָ��

	NODE temp;//����һ����ʱ���

	long long s1, s2;//ѧ��

	for (p = pHead->pNext; p != NULL; p = p->pNext)//ð������ 
	{
		for (q = p->pNext; q != NULL; q = q->pNext)
		{
			s1 = p->st.GetNo();
			s2 = q->st.GetNo();

			if (s1 > s2)//��ǰһ��ѧ����ѧ�Ŵ��ں�һ��ѧ����ѧ��ʱ
			{
				temp.st = p->st;//����ѧ����λ��
				p->st = q->st;
				q->st = temp.st;
			}
		}
	}
}
