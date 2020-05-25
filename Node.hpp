#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <fstream>
#include "Student.hpp"
using namespace std;
class Node { //结点类
	public:
		void InputStudent();//输入学生信息
		void OutputStudent();//输出学生信息
		void AddStudent();//增加学生信息
		void DeleteStudent();//删除学生信息
		void ChangeStudent();//修改学生信息
		void SearchStudent();//查找学生信息
		void SortScore();//将成绩按照从大到小排序
		void SortNum();//将学号按照从大到小排序
		void SetScore();//设置排名
		void FileOutputStudent();//将学生信息写入文件 

	private:
		Student st;//数据域
		Node *pNext;//指针域
		Node *pHead;//头结点
};
typedef Node NODE;
typedef Node* PNODE;
/*
NODE 相当于  Node
PNODE 相当于 Node*
*/


//输入学生信息
void Node::InputStudent()
{
	//创建一个头结点
	pHead = new NODE[sizeof(NODE)];

	if (NULL == pHead)
	{
		cout << "动态内存分配失败,程序终止!" << endl;

		exit(0);
	}

	PNODE pTail = pHead;//创建一个指向头结点的指针
	pTail->pNext = NULL;//初始化指针的指针域为NULL

	//将文件中的数据输入到程序中
	ifstream infile("score.dat", ios::in);

	if (!infile)
	{
		cout << "文件打开失败,程序终止!" << endl;

		exit(0);
	}
	int l; 
	string name;//姓名
	string age;//年龄
	long long number;//学号
	float score;//成绩
	string gender;//性别
	int bir;//生日YYYYMMDD
	string address;//地址
	long long tel; //电话号码 1XXXXXXXXXX
	string email;//邮件

	cout << "请输入学生的人数:";
	cin >> l;


	for (int i = 1; i <= l; i++)
	{
		//创建一个保存数据的新结点
		PNODE pNew = new NODE[sizeof(NODE)];

		if (NULL == pNew)
		{
			cout << "动态内存分配失败,程序终止!" << endl;

			exit(0);
		}

		//读取文件中的数据
		infile >> name >> age >> number >> gender >> bir >> address >> tel >> email >> score;

		//初始化结点
		//pNew->st.SetLen(l);//学生的人数
		pNew->st.SetName(name);//学生的姓名
		pNew->st.SetAge(age);//学生的年龄
		pNew->st.SetNo(number);//学生的学号
		pNew->st.SetGen(gender);//设置学生的性别
		pNew->st.SetBir(bir); //设置学生的生日
		pNew->st.SetAdd(address);//设置学生的地址
		pNew->st.SetTel(tel); //设置学生的电话
		pNew->st.SetEmail(email);//设置学生的邮件
		pNew->st.Setscore(score);//设置学生的成绩

		pTail->pNext = pNew;//将pNew挂在老结点的后面
		pTail = pNew;//将指针pTail移到pNew上
		pTail->pNext = NULL;//清空指针域
	}

	//关闭文件
	infile.close();

	cout << "已经成功的向程序中输入了" << l << "个学生的信息" << endl;
}


void Node::OutputStudent()
{
    PNODE p = pHead->pNext;
 
	cout << "学号\t\t" << "姓名\t" << "年龄\t" << "性别\t" << "生日\t\t" << "地址\t" << "电话号码\t" << "邮件\t\t\t" << "成绩\t"<< "排名" << endl;
 
    string nm;//姓名
	string age;//年龄
	long long nu;//学号
	float score;//成绩
	string gender;//性别
	int bir;//生日YYYYMMDD
	string address;//地址
	long long tel; //电话号码 1XXXXXXXXXX
	string email;//邮件
 
    //遍历学生信息
    while(NULL != p)
    {	
    	p->st.GetName(&nm);
        p->st.GetAge(&age);//得到学生年龄
		p->st.Getgen(&gender);//得到性别
		p->st.GetBir(&bir);//得到生日
		p->st.GetAdd(&address);//得到学生的地址
		p->st.GetTel(&tel); //得到学生的电话
		p->st.GetEmail(&email);//得到学生的邮件
		p->st.GetScore(&score); //得到成绩
 

			cout << p->st.GetNo() << "\t" << nm << "\t" << age << "\t" << gender << "\t" << bir
				<< "\t" << address << "\t" << tel << "\t" << email << "\t" << score << "\t" << p->st.GetS() << endl;
 
        p = p->pNext;
    }
}

void Node::FileOutputStudent()
{
	PNODE p = pHead->pNext;

	cout << "学号\t\t" << "姓名\t" << "年龄\t" << "性别\t" << "生日\t\t" << "地址\t" << "电话号码\t" << "邮件\t\t\t" << "成绩\t" << "排名" << endl;

	ofstream outfile("score.dat", ios::out);

	if (!outfile)
	{
		cout << "文件打开失败,程序终止!" << endl;

		exit(0);
	}

	string nm;//姓名
	string age;//年龄
	long long nu;//学号
	float score;//成绩
	string gender;//性别
	int bir;//生日YYYYMMDD
	string address;//地址
	long long tel; //电话号码 1XXXXXXXXXX
	string email;//邮件

	//遍历学生信息
	while (NULL != p)
	{
		p->st.GetName(&nm);
		p->st.GetAge(&age);//得到学生年龄
		p->st.Getgen(&gender);//得到性别
		p->st.GetBir(&bir);//得到生日
		p->st.GetAdd(&address);//得到学生的地址
		p->st.GetTel(&tel); //得到学生的电话
		p->st.GetEmail(&email);//得到学生的邮件
		p->st.GetScore(&score); //得到成绩


		cout << p->st.GetNo() << "\t" << nm << "\t" << age << "\t" << gender << "\t" << bir
			<< "\t" << address << "\t" << tel << "\t" << email << "\t" << score << "\t" << p->st.GetS() << endl;

		outfile << nm << " " << age << " " << p->st.GetNo() << " " << gender << " " << bir
			<< " " << address << " " << tel << " " << email << " " << score << endl;

		p = p->pNext;
	}
	outfile.close();
}


void Node::AddStudent(void)//增加学生信息
{
	PNODE p = pHead->pNext;
	Student st;//定义一个学生类

	string name;//姓名
	string age;//年龄
	long long no;//学号
	float score;//成绩
	string gender;//性别
	int bir;//生日YYYYMMDD
	string address;//地址
	long long tel; //电话号码 1XXXXXXXXXX
	string email;//邮件
	int sort;//排名

	cout << "请输入学生的学号:" << endl;
	cin >> no;

	cout << "请输入学生的姓名" << endl;
	cin >> name;

	cout << "请输入学生的年龄" << endl;
	cin >> age;

	cout << "请输入学生的性别" << endl;
	cin >> gender;

	cout << "请输入学生的生日" << endl;
	cin >> bir;

	cout << "请输入学生的居住地址" << endl;
	cin >> address;

	cout << "请输入学生的电话号码" << endl;
	cin >> tel;
	
	cout << "请输入学生的邮箱" << endl;
	cin >> email;

	while(1)
	{
		cout << "请输入学生的成绩:"  << endl;
		cin >> score;
		if(score < 0 || score > 100)
			cout << "成绩不合法！请重新输入" << endl;
		else
			break;
	}
	PNODE pt = new NODE[sizeof(NODE)];

	if (NULL == pt)
	{
		printf("动态内存分配失败,程序终止!\n");
		exit(-1);
	}

	//初始化结点
	pt->st.SetName(name);//学生的姓名
	pt->st.SetAge(age);//学生的年龄
	pt->st.SetNo(no);//学生的学号
	pt->st.SetGen(gender);//设置学生的性别
	pt->st.SetBir(bir);//设置学生的生日
	pt->st.SetAdd(address);//设置学生的地址
	pt->st.SetTel(tel); //设置学生的电话
	pt->st.SetEmail(email); //设置学生的邮件 
	pt->st.Setscore(score);//设置学生的成绩

	while (p->pNext != NULL)
	{
		p = p->pNext;
	}
	p->pNext = pt;
	pt->pNext = NULL;

}

void Node::DeleteStudent()//删除学生信息
{
	long long exp;//要删除信息的学生学号 
	PNODE p, be, bp;

	cout << "请输入要删除的学生的学号:";
	cin >> exp;
	p = pHead; //指向头结点 
	
	be = bp = p;
	while (exp != bp->st.GetNo() && bp->pNext != NULL)//查找要删除的节点 
	{
		be = bp;
		bp = bp->pNext;
	}
	if (exp == bp->st.GetNo())//找到该学生信息 
	{
		be->pNext = bp->pNext;
		delete[]bp;
		cout << "已成功删除该学生信息" << endl;
	}
	else
		cout << "查无此人" << endl;
}

void Node::ChangeStudent()//修改学生信息
{
	PNODE p = pHead->pNext;

	string name;//姓名
	string age;//年龄
	long long nu;//修改前的学号
	long long nu2;//修改后的学号
	float score;//成绩
	string gender;//性别
	int bir;//生日YYYYMMDD
	string address;//地址
	long long tel; //电话号码 1XXXXXXXXXX
	string email;//邮件

	int flag = 0;//标识符,初始化表示没找到
	int select;
	cout << "请输入你需要修改的学生的姓名:";
	cin >> name;

	string nm;//姓名

	//遍历学生信息
	while (p != NULL)
	{
		//得到学生的姓名
		p->st.GetName(&nm);

		if (name == nm)
		{
			flag = 1;
			p->st.GetAge(&age);//得到学生年龄
			nu = p->st.GetNo();//得到学生的学号
			p->st.Getgen(&gender);//得到性别
			p->st.GetBir(&bir);//得到生日
			p->st.GetAdd(&address);//得到学生的地址
			p->st.GetTel(&tel); //得到学生的电话
			p->st.GetEmail(&email);//得到学生的邮件
			p->st.GetScore(&score); //得到成绩
			cout << "\n修改前的学生信息:" << endl;

			cout << "学号\t\t" << "姓名\t" << "年龄\t" << "性别\t" << "生日\t\t" << "地址\t" << "电话号码\t" << "邮件\t\t\t" << "成绩\t"<< "排名" << endl;

			cout << nu << "\t" << nm << "\t" << age << "\t" << gender << "\t" << bir
				<< "\t" << address << "\t" << tel << "\t" << email << "\t" << score << "\t" << p->st.GetS() << endl;

			break;
		}

		p = p->pNext;
	}

	if (flag == 0)
	{
		cout << "没找到你需要修改的学生信息!\n" << endl;
	}
	else
	{ 
			cout << "请选择要修改的内容" << endl;
			cout << "===============================================================================\n\n";
			cout << "-------------------------- 1 姓名--------------------------------------\n\n";
			cout << "-------------------------- 2 学号--------------------------------------\n\n";
			cout << "-------------------------- 3 性别--------------------------------------\n\n";
			cout << "-------------------------- 4 年龄--------------------------------------\n\n";
			cout << "-------------------------- 5 生日--------------------------------------\n\n";
			cout << "-------------------------- 6 地址--------------------------------------\n\n";
			cout << "-------------------------- 7 电话号码----------------------------------\n\n";
			cout << "-------------------------- 8 邮件--------------------------------------\n\n";
			cout << "-------------------------- 9 成绩--------------------------------------\n\n";
			cout << "-------------------------- 0 全部--------------------------------------\n\n";
			cout << "===============================================================================\n\n";
			
			cin >> select;
		switch(select)
		{
			case 1:
			{
				cout << "请输入新的姓名:";
				cin >> name;
				p->st.SetName(name);//设置学生的姓名
			}
			break;
			case 2:
			{
				cout << "请输入新的学号；";
				cin >> nu2; 
				p->st.SetNo(nu2);//设置学生的学号 
			}
			break;
			case 3:
			{
				cout << "请输入新的性别:"; 
				cin >> gender;
			}
			break;
			case 4:
			{
				cout << "请输入新的年龄:";
				cin >> age; 
				p->st.SetAge(age);//设置学生的年龄
			}
			break;
			case 5:
			{
				cout << "请输入新的生日:";
				cin >> bir; 
				p->st.SetBir(bir);//设置学生的生日
			}
			break;
			case 6:
			{
				cout << "请输入新的地址:";
				cin >> address;
				p->st.SetAdd(address);//设置学生的地址
			}
			break;
			case 7:
			{
				cout << "请输入新的电话:"; 
				cin >> tel;
				p->st.SetTel(tel); //设置学生的电话
			}
			break;
			case 8:
			{
				cout << "请输入新的邮件:";
				cin >> email; 
				p->st.SetEmail(email);//设置学生的邮件
			}
			break;
			case 9:
			{
				while(1)
				{
				cout << "请输入新的成绩:"; 
				cin >> score;
				if(score < 0 || score > 100)
					cout << "成绩不合法！请重新输入" << endl;
				else
				{
				p->st.Setscore(score);//设置学生的成绩
				break;
				}
			}
			break;
			case 0:
			{
				cout << "\n你将修改学号为" << nu << "的学生信息" << endl;
	
			cout << "请输入新的学号:";
			cin >> nu2;
	 
			cout << "请输入学号为" << nu2 << "的学生的姓名:";
			cin >> name;

			cout << "请输入学号为" << nu2 << "的学生的年龄:";
			cin >> age;

			cout << "请输入学号为" << nu2 << "的学生的性别:";
			cin >> gender;

			cout << "请输入学号为" << nu2 << "的学生的生日:";
			cin >> bir;

			cout << "请输入学号为" << nu2 << "的学生的地址:";
			cin >> address;

			cout << "请输入学号为" << nu2 << "的学生的电话号码:";
			cin >> tel;

			cout << "请输入学号为" << nu2 << "的学生的邮箱:";
			cin >> email;

			while(1)
			{
				cout << "请输入学号为" << nu2 << "的学生的成绩:";
				cin >> score;
				if(score < 0 || score > 100)
					cout << "成绩不合法！请重新输入" << endl;
				else
					break;
			}
			
			p->st.SetNo(nu2);//设置学生的学号 
			p->st.SetName(name);//设置学生的姓名
			p->st.SetAge(age);//设置学生的年龄
			p->st.SetGen(gender);//设置学生的性别
			p->st.SetBir(bir);//设置学生的生日
			p->st.SetAdd(address);//设置学生的地址
			p->st.SetTel(tel); //设置学生的电话
			p->st.SetEmail(email);//设置学生的邮件
			p->st.Setscore(score);//设置学生的成绩
			}
			default:
				break;
			}
		}
	cout << "修改成功！" << endl;

	}
}

void Node::SearchStudent()//查找学生信息
{
	PNODE p = pHead->pNext;

	string nm;//姓名

	int flag = 0;//标识符,初始化表示没找到

	cout << "请输入你需要查找的学生的姓名:";
	cin >> nm;

	cout << "学号\t\t" << "姓名\t" << "年龄\t" << "性别\t" << "生日\t\t" << "地址\t" << "电话号码\t" << "邮件\t\t\t" << "成绩\t"<< endl;

	string name;//姓名
	string age;//年龄
	long long nu;//学号
	float score;//成绩
	string gender;//性别
	int bir;//生日YYYYMMDD
	string address;//地址
	long long tel; //电话号码 1XXXXXXXXXX
	string email;//邮件

	//遍历学生信息
	while (p != NULL)
	{
		//得到学生的姓名和年龄
		p->st.GetName(&name);

		if (name == nm)
		{
			flag = 1;
			p->st.GetAge(&age);//得到学生年龄
			nu = p->st.GetNo();//得到学生的学号
			p->st.Getgen(&gender);//得到性别
			p->st.GetBir(&bir);//得到生日
			p->st.GetAdd(&address);//得到学生的地址
			p->st.GetTel(&tel); //得到学生的电话
			p->st.GetEmail(&email);//得到学生的邮件
			p->st.GetScore(&score); //得到成绩
			cout << nu << "\t" << nm << "\t" << age << "\t" << gender << "\t" << bir
				<< "\t" << address << "\t" << tel << "\t" << email << "\t" << score << "\t" << endl;

			break;//退出循环
		}

		p = p->pNext;
	}

	if (flag == 0)
	{
		cout << "没找到你需要的学生信息!" << endl;
	}
}

void Node::SortScore()//将成绩按照从大到小排序
{
	PNODE p, q;//定义两个指针


	NODE temp;//定义一个临时结点

	float c1, c2;//学生成绩

	for (p = pHead->pNext; p != NULL; p = p->pNext)//冒泡排序法 
	{
		for (q = p->pNext; q != NULL; q = q->pNext)
		{
			p->st.GetScore(&c1);
			q->st.GetScore(&c2);

			if (c1 < c2)//当前一个学生的成绩小于后一个学生的成绩时
			{
				temp.st = p->st;//交换学生的位置
				p->st = q->st;
				q->st = temp.st;
			}
		}
	}
}
void Node::SetScore()//设置排名
{
	PNODE p;//定义一个指向结点的指针
	int i;//保存排名

	//给学生的排名赋值
	for (p = pHead->pNext, i = 1; NULL != p; p = p->pNext, i++)
	{
		p->st.SetS(i);
	}
}

void Node::SortNum()//将学号按照从小到大排序
{
	PNODE p, q;//定义两个指针

	NODE temp;//定义一个临时结点

	long long s1, s2;//学号

	for (p = pHead->pNext; p != NULL; p = p->pNext)//冒泡排序法 
	{
		for (q = p->pNext; q != NULL; q = q->pNext)
		{
			s1 = p->st.GetNo();
			s2 = q->st.GetNo();

			if (s1 > s2)//当前一个学生的学号大于后一个学生的学号时
			{
				temp.st = p->st;//交换学生的位置
				p->st = q->st;
				q->st = temp.st;
			}
		}
	}
}
