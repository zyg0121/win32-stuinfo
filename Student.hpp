#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

class Student {
	public:
		Student();
		void SetName(string name);//����ѧ��������
		void SetAge(string age);//����ѧ��������
		void SetNo(long long number);//����ѧ����ѧ��
		void SetGen(string gender);//����ѧ�����Ա�
		void SetBir(int bir);//����ѧ��������
		void SetAdd(string address);//����ѧ���ĵ�ַ
		void SetTel(long long tel); //����ѧ���ĵ绰
		void SetEmail(string email);//����ѧ�����ʼ�
		void Setscore(float score);//����ѧ���ĳɼ�
		void SetS(int S);//�������(��������)

		void GetName(string *pname);//�õ�ѧ��������
		void GetAge(string *page);//�õ�ѧ������
		long long GetNo();//�õ�ѧ����ѧ��
		void Getgen(string *pgender);//�õ��Ա�
		void GetBir(int *pbir);//�õ�����
		void GetAdd(string *address);//�õ�ѧ���ĵ�ַ
		void GetTel(long long *tel); //�õ�ѧ���ĵ绰
		void GetEmail(string *email);//�õ�ѧ�����ʼ�
		void GetScore(float *pscore); //�õ��ɼ�
		int GetS();//�õ����(��������)

	private:
		long long stu_number;//ѧ��
		string stu_name;//����
		string stu_age;//����
		string stu_gender;//�Ա�
		int stu_bir;//����YYYYMMDD
		string stu_address;//��ַ
		long long stu_tel; //�绰���� 1XXXXXXXXXX
		string stu_email;//�ʼ�
		float stu_score;//ѧ���ɼ���0-100��
		int sort;//����

};

Student::Student()
 {
	sort = 0;
}

void Student::SetName(string name) 
{
	stu_name = name;
}
void Student::SetAge(string age)
{
	stu_age = age;
}
void Student::SetGen(string gender) {
	stu_gender = gender;
}
void Student::SetNo(long long number)
{
	stu_number = number;
}
void Student::SetBir(int bir) {
	stu_bir = bir;
}
void Student::SetAdd(string address) {
	stu_address = address;
}
void Student::SetTel(long long tel) {
	stu_tel = tel;
}
void Student::SetEmail(string email) {
	stu_email = email;
}
void Student::Setscore(float score) {
	stu_score = score;
}
void Student::SetS(int S)
{
	sort = S;
}
void Student::GetName(string *pname) {
	*pname = stu_name;
}
void Student::GetAge(string *page)
{
	*page = stu_age;
}
long long Student::GetNo() {
	return stu_number;
}
void Student::Getgen(string *pgender)
{
	*pgender = stu_gender;
}
void Student::GetBir(int *pbir)
{
	*pbir = stu_bir;
}
void Student::GetAdd(string *address)
{
	*address = stu_address;
}
void Student::GetTel(long long *tel)
{
	*tel = stu_tel;
}
void Student::GetEmail(string *email)
{
	*email = stu_email;
}
void Student::GetScore(float *pscore)
{
	*pscore = stu_score;
}
int Student::GetS() {
	return sort;
}
