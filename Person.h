#pragma once
#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
	string name;
	string sex;
public:
	/*���캯��*/
	Person(string name="Unknown",string sex="Unknown");
	
	/*��ȡ��Ա����*/
	string getName();
	string getSex();

	/*�޸ĳ�Ա����*/
	void setName(string newName);
	void setSex(string newSex);
};