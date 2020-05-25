#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

class Student {
	public:
		Student();
		void SetName(string name);//设置学生的姓名
		void SetAge(string age);//设置学生的年龄
		void SetNo(long long number);//设置学生的学号
		void SetGen(string gender);//设置学生的性别
		void SetBir(int bir);//设置学生的生日
		void SetAdd(string address);//设置学生的地址
		void SetTel(long long tel); //设置学生的电话
		void SetEmail(string email);//设置学生的邮件
		void Setscore(float score);//设置学生的成绩
		void SetS(int S);//设置序号(用于排名)

		void GetName(string *pname);//得到学生的姓名
		void GetAge(string *page);//得到学生年龄
		long long GetNo();//得到学生的学号
		void Getgen(string *pgender);//得到性别
		void GetBir(int *pbir);//得到生日
		void GetAdd(string *address);//得到学生的地址
		void GetTel(long long *tel); //得到学生的电话
		void GetEmail(string *email);//得到学生的邮件
		void GetScore(float *pscore); //得到成绩
		int GetS();//得到序号(用于排名)

	private:
		long long stu_number;//学号
		string stu_name;//姓名
		string stu_age;//年龄
		string stu_gender;//性别
		int stu_bir;//生日YYYYMMDD
		string stu_address;//地址
		long long stu_tel; //电话号码 1XXXXXXXXXX
		string stu_email;//邮件
		float stu_score;//学生成绩（0-100）
		int sort;//排名

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
