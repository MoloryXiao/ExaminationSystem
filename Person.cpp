#include "Person.h"
#include <string>

/*���캯��*/
Person::Person(string name,string sex)
{
	this->name=name;
	this->sex=sex;
}

/*��ȡ������Ϣ*/
string Person::getName()
{
	return name;
}
string Person::getSex()
{
	return sex;
}

/*����������Ϣ*/
void Person::setName(string newName)
{
	this->name=newName;
}
void Person::setSex(string newSex)
{
	this->sex=newSex;
}