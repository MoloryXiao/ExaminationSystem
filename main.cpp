#include "Check.h"
#include "Course.h"
#include "Student.h"
#include "Teacher.h"
#include "printMenu.h"
#include <string>
#include <vector>

vector<Course> myCourses;
vector<Student> myStudents;
vector<Teacher> myTeachers;

void GoToXY(int x, int y)
{
	COORD pos = { x,y };                 //���ù��λ��        
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);    // ��ȡ��׼����豸���       
	SetConsoleCursorPosition(hOut, pos);      //���������ֱ���ָ���ĸ����壬ʲôλ�ã� 
}

void courseManagementMenu_1()/*�γ���Ϣ��������1.���ӿγ�*/
{
	system("cls");
	cout << "���ڽ��С����ӿγ̡����밴����ʾ������" << endl;

	Course newCourse;
	string newName;
	string newCourseID, newTeacherID;
	int newTime;
	bool flag = false;

	cout << "������γ�����";
	cin >> newName;
	newCourse.setName(newName);

	cout << "������3λ'�γ�'��ţ�";
	cin >> newCourseID;
	cout << "������6λ'��ʦ'��ţ�";
	cin >> newTeacherID;
	newCourse.setNumber(newCourseID, newTeacherID);

	cout << "�������ʱ����";
	cin >> newTime;

	newCourse.setTime(newTime);

	for (auto iter = myTeachers.begin(); iter != myTeachers.end(); ++iter)
		if (iter->getWorkNum() == newTeacherID)
		{
			iter->addCourse(newCourse);
			flag = true;
		}

	if (!flag) { cout << "����ʧ�ܣ� Error:û�иù��ŵĽ�ʦ��" << endl; return; }

	cout << "������ɣ�" << endl;
	myCourses.push_back(newCourse);
}
void courseManagementMenu_2()/*�γ���Ϣ��������2.ɾ���γ�*/
{
	system("cls");
	if (!myCourses.empty()) {
		cout << "���ڽ��С�ɾ���γ̡����밴����ʾ������" << endl;
		for (auto iter = myCourses.begin(); iter != myCourses.end(); ++iter)
			(*iter).showInfo();
	}
	else {
		cout << "��Ǹ�����޿γ̣�" << endl; return;
	}

	string delNumber;
	cout << "������γ̱�ţ�" << endl;
	cin >> delNumber;
	bool flag = false;
	for (auto iter = myCourses.begin(); iter != myCourses.end(); ++iter)
		if (delNumber == (*iter).getNumber())
		{
			flag = true;
			(*iter).showInfo();
			bool confirm;
			cout << "ȷ��ɾ������ 0.No/1.Yes ��" << endl;
			cin >> confirm;
			if (confirm) {
				for (auto iter2 = myTeachers.begin(); iter2 != myTeachers.end(); ++iter2)
					if (iter2->getWorkNum() == iter->getNumber().substr(6)) {
						iter2->deleteCourse(*iter);//ɾ����ʦĳһ�ſ�
						break;
					}
				myCourses.erase(iter);
				cout << "ɾ���ɹ���" << endl;
				break;
			}
			else cout << "��ȡ��������" << endl;
			break;
		}
	if (!flag) cout << "û�иÿγ̣���ȷ�Ͽγ̱��!" << endl;
}
void courseManagementMenu_3()
{
	system("cls");
	if (!myCourses.empty())
	{
		cout << "���ڽ��С��޸Ŀγ���Ϣ�����밴����ʾ������" << endl;
		for (auto iter = myCourses.begin(); iter != myCourses.end(); ++iter)
			(*iter).showInfo();
	}
	else {
		cout << "��Ǹ�����޿γ̣�" << endl; return;
	}
	string number;
	int choice_2;
	cout << "��������Ҫ�޸Ŀγ���Ϣ�ı�ţ�";
	cin >> number;
	auto iter = myCourses.begin();
	while (iter != myCourses.end())
	{
		if ((*iter).getNumber() == number)
		{
			cout << "�����޸ġ�" << (*iter).getName() << "������ţ�" << iter->getNumber() << endl
				<< "1.�޸Ŀγ�����" << endl
				<< "2.�޸Ŀγ̿�ʱ" << endl
				<< "3.�޸Ŀγ̱��" << endl
				<< "4.ȡ���޸�" << endl
				<< "�������޸���Ŀ��ţ�";
			cin >> choice_2;
			switch (choice_2)
			{
			case 1:
			{
				string newName;
				cout << "�����������ƣ�";
				cin >> newName;
				(*iter).setName(newName);
				cout << "�޸ĳɹ���������Ϊ " << (*iter).getName() << endl;
				break;
			}
			case 2:
			{
				int newTime;
				cout << "�������¿�ʱ����";
				cin >> newTime;
				(*iter).setTime(newTime);
				cout << "�޸ĳɹ����¿�ʱ��Ϊ " << (*iter).getTime() << endl;
				break;
			}
			case 3:
			{
				string newCN;
				cout << "������3λ�γ̱�ţ�";
				cin >> newCN;

				string newTN;
				cout << "������6λ��ʦ��ţ�";
				cin >> newTN;

				iter->setNumber(newCN, newTN);
				cout << "�޸ĳɹ����±��Ϊ " << (*iter).getNumber() << endl;
				break;
			}
			case 4:
				break;
			}
			break;
		}
		++iter;
	}
	if (iter == myCourses.end()) cout << "û�иÿγ̣���ȷ�Ͽγ̱��!" << endl;
}
void courseManagementMenu_4()
{
	if (!myCourses.empty())
		for (auto iter = myCourses.begin(); iter != myCourses.end(); ++iter)
			(*iter).showInfo();
	else cout << "��Ǹ�����޿γ̣�" << endl;
}
void courseManagementMenu()
{
	char choice;
	printCourseManagementMenu();
	do
	{
		cin >> choice;
		cin.ignore(1024, '\n');
		switch (choice)
		{
		case '1'://���ӿγ�
			courseManagementMenu_1();
			break;
		case '2'://ɾ���γ�
			courseManagementMenu_2();
			break;
		case '3'://�޸Ŀγ���Ϣ
			courseManagementMenu_3();
		    break;
		case '4'://�г��γ���Ϣ
			courseManagementMenu_4();
		    break;
		case '5'://�����ϼ��˵�
			continue;
		default:
			cout << "�����������������루1/2/3/4/5��: ";
			continue;
		}
		std::system("pause");
		printCourseManagementMenu();
	} while (choice != '5');
}

void teacherCourseChoose(int i, int &n)
{
	myTeachers[i].showTeacherAllCourses();
	cout << "������γ���ţ�";
	cin >> n;
}
void teacherModifyCourseCheck(int i)
{
	char choice;
	printTeacherModifyCourseCheck();
	do
	{
		cin >> choice;
		cin.ignore(1024, '\n');
		switch (choice)
		{
		case '1':
			myTeachers[i].showTeacherAllCourses();
			break;
		case '2':
		{
			myTeachers[i].showTeacherAllCourses();
			cout << "������γ̱�ţ�";
			int No_;
			cin >> No_;
			myTeachers[i].showCourseInfo(No_);
			cout << "�����뿼����Ŀ���֣�";
			string nm;
			cin >> nm;
			myTeachers[i].createCheck(No_, nm);
			cout << "������ɣ�" << endl;
			break;
		}
		case '3':
		{
			myTeachers[i].showTeacherAllCourses();
			cout << "������γ̱�ţ�";
			int No_;
			cin >> No_;
			myTeachers[i].showCourseInfo(No_);
			cout << "��������ɾ��������Ŀ����ţ�";
			int index;
			cin >> index;
			myTeachers[i].delCheck(No_, index - 1);
			cout << "ɾ����ɣ�" << endl;
			break;
		}
		case '4':
		{
			myTeachers[i].showTeacherAllCourses();
			cout << "������γ̱�ţ�";
			int No_;
			cin >> No_;
			myTeachers[i].resetScoreRate(No_);
			break;
		}
		case '5':
			break;
		default:
			cout << "�����������������루1/2/3/4/5��: ";
			continue;
		}
		if (choice != '5') std::system("pause");
		printTeacherModifyCourseCheck();
	} while (choice != '5');
}
void teacherManagementMenu_1()
{
	system("cls");
	cout << "���ڽ��С����ӽ�ʦ�����밴����ʾ������" << endl;

	Teacher newTeacher;
	string newName;
	string newSex;
	string newTeacherID;

	cout << "�������ʦ���ţ�";
	cin >> newTeacherID;

	cout << "�������ʦ������";
	cin >> newName;

	do{
		cout << "�������Ա���/Ů����";
		cin >> newSex;
		if (!(newSex == "��" || newSex == "Ů")) cout << "�����������������룡" << endl;
	} while (!(newSex == "��" || newSex == "Ů"));

	newTeacher.setAllData(newName, newSex, newTeacherID, 0, "000000");
	cout << "������ɣ���ʼ����Ϊ��000000��" << endl;
	myTeachers.push_back(newTeacher);

}
void teacherManagementMenu_2()
{
	system("cls");
	if (!myTeachers.empty()) {
		cout << "���ڽ��С�ɾ����ʦ�����밴����ʾ������" << endl;
		for (auto iter = myTeachers.begin(); iter != myTeachers.end(); ++iter)
			(*iter).showTeacherInfo();
	}
	else {
		cout << "��Ǹ�����޽�ʦ��" << endl; return;
	}

	string delNumber;
	cout << "�������ʦ��ţ�" << endl;
	cin >> delNumber;
	bool flag = false;
	for (auto iter = myTeachers.begin(); iter != myTeachers.end(); ++iter)
		if (delNumber == (*iter).getWorkNum())
		{
			flag = true;
			(*iter).showTeacherInfo();
			bool confirm;
			cout << "ȷ��ɾ������ 0.No/1.Yes ��" << endl;
			cin >> confirm;
			if (confirm) {
				myTeachers.erase(iter);
				cout << "ɾ���ɹ���" << endl;
				break;
			}
			else cout << "��ȡ��������" << endl;
			break;
		}
	if (!flag) cout << "û�иý�ʦ����ȷ�Ͻ�ʦ����!" << endl;
}
void teacherManagementMenu_3()
{
	system("cls");
	if (!myTeachers.empty())
	{
		cout << "���ڽ��С����ҽ�ʦ�����밴����ʾ������" << endl;

		char choice2;
		cout << "\t1.���ݽ�ʦ����" << endl
			<< "\t2.���ݽ�ʦ����" << endl
			<< "���������ѡ��";
		cin >> choice2;
		cin.ignore(1024, '\n');
		switch (choice2)
		{
		case '1':
		{
			string findNum;
			cout << "�������ʦ���ţ�";
			cin >> findNum;
			bool flag = false;
			for (auto iter = myTeachers.begin(); iter != myTeachers.end(); ++iter)
			{

				if (iter->getWorkNum() == findNum) {
					iter->showTeacherInfo();
					flag = true;
					break;
				}
			}
			if (!flag) cout << "���޴��ˣ���ȷ�Ͻ�ʦ���ţ�" << endl;
			break;
		}

		case '2':
		{
			string findName;
			bool flag = false;//���޴���
			cout << "�������ʦ������";
			cin >> findName;
			for (auto iter = myTeachers.begin(); iter != myTeachers.end(); ++iter)
			{
				if (iter->getName() == findName) {
					iter->showTeacherInfo();
					flag = true;
					break;
				}
			}
			if (!flag) cout << "���޴��ˣ���ȷ�Ͻ�ʦ������" << endl;
		}
		break;
		default: cout << "����������ȷ�����ѡ��" << endl;
		}
	}
	else cout << "��Ǹ�����޽�ʦ��" << endl;

}
void teacherManagementMenu_4()
{
	system("cls");
	if (!myTeachers.empty()) {
		cout << "���ڽ��С��޸Ľ�ʦ��Ϣ�����밴����ʾ������" << endl;
		for (auto iter = myTeachers.begin(); iter != myTeachers.end(); ++iter)
			(*iter).showTeacherInfo();
	}
	else {
		cout << "��Ǹ�����޽�ʦ��" << endl; return;
	}
	string number;
	int choice_2;
	cout << "��������Ҫ�޸Ľ�ʦ��Ϣ�ı�ţ�";
	cin >> number;
	auto iter = myTeachers.begin();
	while (iter != myTeachers.end())
	{
		if ((*iter).getWorkNum() == number)
		{
			cout << "�����޸�\"" << (*iter).getName() << "\"����ţ�" << iter->getWorkNum() << endl
				<< "\t1.�޸�����" << endl
				<< "\t2.�޸��Ա�" << endl
				<< "\t3.�޸Ĺ���" << endl
				<< "\t4.�޸��ڿο�Ŀ" << endl
				<< "\t5.�޸Ŀ���" << endl
				<< "\t5.�޸�����" << endl
				<< "\t6.ȡ��" << endl
				<< "�������޸���Ŀ��ţ�";
			cin >> choice_2;
			switch (choice_2)
			{
			case 1:
			{
				string newName;
				cout << "�����������֣�";
				cin >> newName;
				(*iter).setName(newName);
				cout << "�޸ĳɹ���������Ϊ " << (*iter).getName() << endl;
				break;
			}
			case 2:
			{
				string newSex;
				do
				{
					cout << "�������Ա���/Ů����";
					cin >> newSex;
					if (!(newSex == "��" || newSex == "Ů")) cout << "�����������������룡" << endl;
				} while (!(newSex == "��" || newSex == "Ů"));
				(*iter).setSex(newSex);
				cout << "�޸ĳɹ���";
				break;
			}
			case 3:
			{
				string newNum;
				cout << "�������¹��ţ�";
				cin >> newNum;
				iter->setWorkNum(newNum);
				cout << "�޸ĳɹ�����ǰ����Ϊ " << (*iter).getWorkNum() << endl;
				break;
			}
			case 4:
			{
				int choice_3;
				cout << endl
					<< "=====��ѡ���޸��ڿο�Ŀ��=====" << endl
					<< "1.���ӿγ�" << endl
					<< "2.ɾ���γ�" << endl
					<< "3.ȡ��" << endl
					<< "���������ѡ��";
				cin >> choice_3;
				switch (choice_3)
				{
				case 1:
				{
					string newCourse;
					cout << "�����������ӿγ̵ı�ţ�";
					cin >> newCourse;
					auto i = myCourses.begin();
					for (i; i != myCourses.end(); ++i)
					{
						if (i->getNumber() == newCourse) (*iter).addCourse((*i));
						cout << "���ӳɹ���" << endl;
						break;
					}
					if (i == myCourses.end()) cout << "δ�ҵ��ÿγ̣���ȷ�Ͽγ̱�ţ�" << endl;
					break;
				}
				case 2:
				{
					iter->showTeacherAllCourses();
					string delCourse;
					cout << "��������ɾ���γ̵ı�ţ�";
					cin >> delCourse;
					auto i = myCourses.begin();
					for (i; i != myCourses.end(); ++i)
					{
						if (i->getNumber() == delCourse) (*iter).deleteCourse((*i));
						cout << "ɾ���ɹ���" << endl;
						break;
					}
					if (i == myCourses.end()) cout << "δ�ҵ��ÿγ̣���ȷ�Ͽγ̱�ţ�" << endl;
					break;
				}
				case 3:
					break;
				default:
					cout << "����������ȷ�����ѡ��" << endl;
					break;
				}
				break;
			}

			case 5:
				teacherModifyCourseCheck(iter - myTeachers.begin());

			case 6:
			{
				string newPW;
				string newPW2;
				cout << "�����������룺";
				cin >> newPW;
				cout << "���ٴ��������룺";
				cin >> newPW2;
				if (newPW == newPW2)
				{
					iter->setPassword(newPW);
					cout << "�޸ĳɹ���" << endl;
				}
				else cout << "�޸�ʧ�ܣ��������벻ƥ�䣬�����ԣ�" << endl;
				break;
			}
			case 7:
				cout << "��ȡ����" << endl;
				break;
			}
			break;
		}
		++iter;
	}
	if (iter == myTeachers.end()) cout << "û�иý�ʦ����ȷ�Ͻ�ʦ����!" << endl;

}
void teacherManagementMenu_5()
{
	if (!myTeachers.empty())
	{
		cout << "------------------------------------------------------------------" << endl
			<< setw(7) << "����" << setw(6) << "����" << setw(4) << "�Ա�" << "   " << endl
			<< "------------------------------------------------------------------" << endl;
		for (auto iter = myTeachers.begin(); iter != myTeachers.end(); ++iter)
			(*iter).showTeacherInfo();
		cout << "------------------------------------------------------------------" << endl;
	}
	else cout << "��Ǹ�����޽�ʦ��" << endl;
}
void teacherManagementMenu()
{
	char choice;
	printTeacherManagementMenu();
	do
	{
		cin >> choice;
		cin.ignore(1024, '\n');
		switch (choice)
		{
		case '1':
			teacherManagementMenu_1();
			break;
		case '2':
			teacherManagementMenu_2();
			break;
		case '3':
			teacherManagementMenu_3();
			break;
		case '4':
			teacherManagementMenu_4();
			break;
		case '5':
			teacherManagementMenu_5();
			break;
		case '6':
			continue;
		}
		std::system("pause");
		printTeacherManagementMenu();
	} while (choice != '6');
}
void teacherMenu(int i)
{
	int n;
	char choice;
	printTeacherMenu(i);
	do
	{
		cin >> choice;
		cin.ignore(1024, '\n');
		switch (choice)
		{
		case '1':
			myTeachers[i].addStuMark();
			break;
		/*
		{
			
			if (myTeachers[i].students.empty()) {cout << "û��ѧ����" << endl; break;}
			if (myTeachers[i].is_CourseEmpty()) { cout << "���޿γ̣�"<<endl; break; }
			int No_ = 1;
			teacherCourseChoose(i, n);
			for(auto iter=myTeachers[i].students.begin();iter!= myTeachers[i].students.end();++iter,++No_)
				cout <<No_+1<<"\t"<< iter->getName() << endl;
			cout << "������ѧ����ţ�";
			cin >> No_;
			int temp = myTeachers[i].students[No_ - 1].is_ExistCourse(myTeachers[i].courses[n - 1]);
			myTeachers[i].students[No_ - 1].courses[temp].showAllScore();//��ʾ��ʦ�����¸�ѧ�������п��˼��ɼ�
			string na;
			double score;
			cout << "�����뿼����Ŀ����";
			cin >> na;
			cout << "�����������";
			cin >> score;
			myTeachers[i].students[No_ - 1].courses[temp].enrollScore(na,score);//ֻ�Ǹ�����ʦ�����µĸ�ѧ����Ϣ������Ҫ������Ϣ���������ѧ�����ˣ�
			for (auto stu : myStudents)
				if (stu.getStuNum() == myTeachers[i].students[No_ - 1].getStuNum())
				{
					stu = myTeachers[i].students[No_ - 1];
					break;
				}

			break;
		}
			*/
		
		case '2':
			if (myTeachers[i].is_CourseEmpty()) { cout << "���޿γ̣�"; break; }
			teacherModifyCourseCheck(i);
			break;

		case '3':
			if (myTeachers[i].is_CourseEmpty()) { cout << "���޿γ̣�"; break; }
			myTeachers[i].showTeacherAllCourses();
			break;

		case '4':
			continue;

		default:
			cout << "�����������������루1/2/3/4��: ";
			continue;
		}
		std::system("pause");
		printTeacherMenu(i);
	} while (choice != '4');
}
void teacherLogin()
{
	string username;
	string password;
	int i, total = myTeachers.size();

	if (total == 0) { cout << "���޽�ʦ���ݣ�����¼�룡" << endl;	system("pause"); return; }
	GoToXY(13, 7);
	cin >> username;
	for (i = 0; i < total; ++i)
		if (username == myTeachers[i].getName())
		{
			GoToXY(13, 10);
			cin >> password;
			if (password == myTeachers[i].getPassword())
			{
				GoToXY(0, 19);
				cout << "��¼�ɹ�!";
				Sleep(2000);
				teacherMenu(i);
			}
			else
			{
				GoToXY(0,19);
				cout << "�������" << endl;
				system("pause");
			}
			break;
		}
	if (total == i) {
		GoToXY(0, 19);
		cout << "���޴��ˣ���ȷ�Ͻ�ʦID��" << endl; system("pause");
	}
}

void printStudentInfo()
{
	cout << left
		<< "------------------------------------------------------------------" << endl
		<< "���\t" << setw(10) << "ѧ��" << setw(8) << "����" << setw(6) << "�Ա�" << setw(14) << "ѧԺ" << setw(12) << "רҵ" << setw(12) << "�༶" << endl
		<< "------------------------------------------------------------------" << endl;
	int i=1;
	for (auto iter = myStudents.begin(); iter != myStudents.end(); ++iter, ++i)
	{
		cout << i << '\t'; (*iter).showStuInfo();
	}
	cout << "------------------------------------------------------------------" << endl
		<< right;
}
void studentManagementMenu_1()
{
	system("cls");
	cout << "���ڽ��С�����ѧ�������밴����ʾ������" << endl;

	Student newStudent;
	string newName;
	string newSex;
	string newNum;
	string newIns;
	string newMajor;
	string newClass;

	cout << "������ѧ������";
	cin >> newName;
	do 
	{
		cout << "�������Ա���/Ů����";
		cin >> newSex;
		if (!(newSex == "��" || newSex == "Ů")) cout << "�����������������룡" << endl;
	} while (!(newSex == "��" || newSex == "Ů"));
	
	cout << "������ѧ�ţ�";
	cin >> newNum;
	cout << "������ѧԺ��";
	cin >> newIns;
	cout << "������רҵ��";
	cin >> newMajor;
	cout << "������༶����";
	cin >> newClass;

	newStudent.setAllData(newName, newSex, newNum, newIns, newMajor, newClass, "000000");
	cout << "������ɣ���ʼ����Ϊ��000000��" << endl;
	myStudents.push_back(newStudent);
}
void studentManagementMenu_2()
{
	system("cls");
	if (!myStudents.empty()) {
		cout << "���ڽ��С�ɾ��ѧ�������밴����ʾ������" << endl;
		for (auto iter = myStudents.begin(); iter != myStudents.end(); ++iter)
			(*iter).showStuInfo();
	}
	else {
		cout << "��Ǹ������ѧ����" << endl; return;
	}

	string delNumber;
	cout << "������ѧ����ţ�" << endl;
	cin >> delNumber;
	bool flag = false;
	for (auto iter = myStudents.begin(); iter != myStudents.end(); ++iter)
		if (delNumber == (*iter).getStuNum())
		{
			flag = true;
			(*iter).showStuInfo();
			bool confirm;
			cout << "ȷ��ɾ������ 0.No/1.Yes ��" << endl;
			cin >> confirm;
			if (confirm) {
				myStudents.erase(iter);
				cout << "ɾ���ɹ���" << endl;
				break;
			}
			else cout << "��ȡ��������" << endl;
			break;
		}
	if (!flag) cout << "û�и�ѧ������ȷ��ѧ��ѧ��!" << endl;
}
void studentManagementMenu_3()
{
	system("cls");
	if (!myStudents.empty())
	{
		cout << "���ڽ��С�����ѧ�������밴����ʾ������" << endl;

		char choice2;
		cout << "\t1.����ѧ��ѧ��" << endl
			<< "\t2.����ѧ������" << endl
			<< "���������ѡ��";
		cin >> choice2;
		cin.ignore(1024, '\n');
		switch (choice2)
		{
		case '1':
		{
			string findNum;
			bool flag = false;//���޴���
			cout << "������ѧ��ѧ�ţ�";
			cin >> findNum;
			auto iter = myStudents.begin();
			for (iter; iter != myStudents.end(); ++iter)
			{
				if (iter->getStuNum() == findNum) {
					cout << "���ҵ�����ѧ����Ϣ���£�" << endl
						<< left
						<< "------------------------------------------------------------------" << endl
						<< setw(10) << "ѧ��" << setw(8) << "����" << setw(6) << "�Ա�" << setw(14) << "ѧԺ" << setw(12) << "רҵ" << setw(12) << "�༶" << endl
						<< "------------------------------------------------------------------" << endl;
						(*iter).showStuInfo();
					cout << "------------------------------------------------------------------" << endl
						<< right;
					flag = true;
					break;
				}
				break;
			}
			if (iter == myStudents.end()) cout << "���޴��ˣ���ȷ��ѧ��ѧ�ţ�" << endl;
		}
		break;

		case '2':
		{
			string findName;
			bool flag = false;//���޴���
			cout << "������ѧ��������";
			cin >> findName;
			auto iter = myStudents.begin();
			for (iter; iter != myStudents.end(); ++iter)
			{
				if (iter->getName() == findName) {
					cout << "���ҵ�����ѧ����Ϣ���£�" << endl
						<< left
						<< "------------------------------------------------------------------" << endl
						<< setw(10) << "ѧ��" << setw(8) << "����" << setw(6) << "�Ա�" << setw(14) << "ѧԺ" << setw(12) << "רҵ" << setw(12) << "�༶" << endl
						<< "------------------------------------------------------------------" << endl;
					(*iter).showStuInfo();
					cout << "------------------------------------------------------------------" << endl
						<< right;
					flag = true;
					break;
				}
			}
			if (!flag) cout << "���޴��ˣ���ȷ��ѧ��������" << endl;
		}
		break;

		default: 
			cout << "��ȷ�����ѡ��" << endl;
		}
	}
	else cout << "��Ǹ������ѧ����" << endl;

}
void studentManagementMenu_4()
{
	system("cls");
	if (!myStudents.empty()) {
		cout << "���ڽ��С��޸�ѧ����Ϣ�����밴����ʾ������" << endl;
		printStudentInfo();
	}
	else {
		cout << "��Ǹ������ѧ����" << endl; return;
	}
	string number;
	int choice_2;
	cout << "��������Ҫ�޸�ѧ����Ϣ����ţ�";
	cin >> number;
	auto iter = myStudents.begin();
	while (iter != myStudents.end())
	{
		if ((*iter).getStuNum() == number)
		{
			cout << "�����޸�\"" << (*iter).getName() << "\"����ţ�" << iter->getStuNum() << endl
				<< "\t1.�޸�����" << endl
				<< "\t2.�޸��Ա�" << endl
				<< "\t3.�޸�ѧ��" << endl
				<< "\t4.�޸�ѧԺ" << endl
				<< "\t5.�޸�רҵ" << endl
				<< "\t6.�޸İ༶" << endl
				<< "\t7.���ӿγ�" << endl
				<< "\t8.ɾ���γ�" << endl
				<< "\t9.�޸�����" << endl
				<< "\t0.ȡ��" << endl
				<< "�������޸���Ŀ��ţ�";
			cin >> choice_2;
			switch (choice_2)
			{
			case 1:
			{
				string newName;
				cout << "�����������֣�";
				cin >> newName;
				(*iter).setName(newName);
				cout << "�޸ĳɹ���������Ϊ " << (*iter).getName() << endl;
				break;
			}
			case 2:
			{
				string newSex;
				do
				{
					cout << "�������Ա���/Ů����";
					cin >> newSex;
					if (!(newSex == "��" || newSex == "Ů")) cout << "�����������������룡" << endl;
				} while (!(newSex == "��" || newSex == "Ů"));
				(*iter).setSex(newSex);
				cout << "�޸ĳɹ���";
				break;
			}
			case 3:
			{
				string newNum;
				cout << "��������ѧ�ţ�";
				cin >> newNum;
				iter->setStuNum(newNum);
				cout << "�޸ĳɹ�����ǰѧ��Ϊ " << (*iter).getStuNum() << endl;
				break;
			}
			case 4:
			{
				string newIns;
				cout << "������ѧԺ����";
				cin >> newIns;
				iter->setStuInstitude(newIns);
				cout << "�޸ĳɹ�����ǰѧԺΪ " << (*iter).getStuInstitude() << endl;
				break;
			}
			case 5:
			{
				string newMajor;
				cout << "������רҵ����";
				cin >> newMajor;
				iter->setStuMajor(newMajor);
				cout << "�޸ĳɹ�����ǰרҵΪ " << (*iter).getStuMajor() << endl;
				break;
			}
			case 6:
			{
				string newClass;
				cout << "������༶����";
				cin >> newClass;
				iter->setStuClass(newClass);
				cout << "�޸ĳɹ�����ǰ�༶Ϊ " << (*iter).getStuClass() << endl;
				break;
			}
			case 7:
			{
				if (!myCourses.empty())
				{
					int No_ = 1;
					for (auto iter_2 = myCourses.begin(); iter_2 != myCourses.end(); ++iter_2, ++No_)
					{
						cout << No_ << endl;
						iter_2->showInfo();
					}
					cout << "��ѡ����Ҫ���ӿγ̵���ţ�";
					cin >> No_;
					iter->addCourse(myCourses[No_ - 1]);
					//ѧ��ѡ��һ�ſγ̣�����ѧ�����ӵ������ſε���ʦ��student��
					for (auto iter_3 = myTeachers.begin(); iter_3 != myTeachers.end(); ++iter_3)
						if (iter_3->is_ExistCourse(myCourses[No_ - 1]) > -1)
							iter_3->addStudent(*iter);
						else break;
					cout << "���ӳɹ���" << endl;
				}
				else
				{
					cout << "��Ǹ�����޿γ̣�" << endl;
				}
				break;
			}
			case 8:
			{
				if (!iter->is_CourseEmpty())
				{
					int No_ = 1;
					cout << "------------------------------------------" << endl
						<< setw(5) << "���" << setw(12) << "�γ̱��" << setw(15) << "�γ�����" << endl
						<< "-------------------------------------------" << endl;
					iter->showAllCourses();
					cout << "------------------------------------------" << endl;
					cout << "��ѡ����Ҫɾ���γ̵���ţ�";
					cin >> No_;
					if (No_ - 1 >= iter->getClassSum()) {
						cout << "����������ȷ����ţ�" << endl;
						break;
					}
					iter->deleCourse(No_ - 1);
					for (auto iter_3 = myTeachers.begin(); iter_3 != myTeachers.end(); ++iter_3)
						if (iter_3->is_ExistCourse(myCourses[No_ - 1]) > -1)
						{
							iter_3->deleStudent(*iter); break;
						}
					cout << "ɾ���ɹ���" << endl;
				}
				else
					cout << "��Ǹ�����޿γ̣�" << endl;
				break;

			}
			case 9:
			{
				string newPW;
				string newPW2;
				cout << "�����������룺";
				cin >> newPW;
				cout << "���ٴ��������룺";
				cin >> newPW2;
				if (newPW == newPW2)
				{
					iter->setPassword(newPW);
					cout << "�޸ĳɹ���" << endl;
				}
				else cout << "�޸�ʧ�ܣ��������벻ƥ�䣬�����ԣ�" << endl;
				break;
			}	
			
			default:
				break;
			}
			break;
		}
		++iter;
	}
	if (iter == myStudents.end()) cout << "û�и�ѧ������ȷ��ѧ��ѧ��!" << endl;
}
void studentManagementMenu_5()
{
	if (!myStudents.empty())
		printStudentInfo();
	else cout << "��Ǹ������ѧ����" << endl;
}
void studentManagementMenu()
{
	char choice;
	printStudentManagementMenu();
	do
	{
		cin >> choice;
		cin.ignore(1024, '\n');
		switch (choice)
		{
		case '1':
			studentManagementMenu_1();
			break;
		case '2':
			studentManagementMenu_2();
			break;
		case '3':
			studentManagementMenu_3();
			break;
		case '4':
			studentManagementMenu_4();
			break;
		case '5':
			studentManagementMenu_5();
			break;
		case '6':
			continue;
		}
		std::system("pause");
		printStudentManagementMenu();
	} while (choice != '6');
}
void studentLogin()
{
	string username;
	string password;
	int i,total= myStudents.size();

	if (total == 0) { cout << "����ѧ�����ݣ�����¼�룡" << endl;	std::system("pause");	return; }
	GoToXY(13, 7);
	cin >> username;
	for ( i = 0; i < total; ++i)
		if (username == myStudents[i].getName())
		{
			GoToXY(13, 10);
			cin >> password;
			if (myStudents[i].is_IDPass(password))
			{
				GoToXY(0, 19);
				cout << "��¼�ɹ�!";
				Sleep(2000);
				printStudentInfo(myStudents[i]);
				std::system("pause");//��ֹ��ʾѧ���ɼ���ʱһ������
			}
			else
			{
				GoToXY(0, 19);
				cout << "�������" << endl;
				std::system("pause");		
			}	
			break;
		}
	if (total == i) {
		GoToXY(0, 19);
		cout << "���޴��ˣ���ȷ��ѧ��ID��" << endl; 
		system("pause");
	}
}

void adminMenu()
{
	char choice;
	printAdminMenu();
	do
	{
		cin >> choice;
		cin.ignore(1024, '\n');
		switch (choice)
		{
		case '1':
			courseManagementMenu();
			break;

		case '2':
			teacherManagementMenu();
			break;

		case '3':
			studentManagementMenu();
			break;

		case '4':
			break;

		default:
			cout << "�����������������루1/2/3/4��: ";
			continue;
		}
		printAdminMenu();
	} while (choice != '4');
}
void adminLogin()
{
	//���Խ׶��ݲ���¼
	string username;
	string password;
	GoToXY(13, 7);
	cin >> username;
	for (int i = 0; i < 1; ++i)
		if (username == "admin")
		{
			GoToXY(13, 10);
			cin >> password;
			if (password == "admin")
			{
				GoToXY(0, 19);
				cout << "��������֤��" << endl
					<< "����������������������������������" << endl
					<< "��     ��    ��    ��    ��     ��" << endl
					<< "����������������������������������" << endl;
				for (int i = 2; i < 31; i+=2)
				{
					GoToXY(i, 21);
					cout << "��" ;
					Sleep(200);
				}
				adminMenu();
			}
			else
			{
				GoToXY(0, 19);
				cout << "�������" << endl;
				std::system("pause");
			}
			break;
		}
}

int main()
{
	
	extern vector<Course> myCourses;
	char choice;
	printMainMenu();
	while (1)
	{
		cin >> choice;
		cin.ignore(1024, '\n');
		switch (choice)
		{
		case '1':
			adminLogin();    
			break;
		case '2':
			teacherLogin();
			break;

		case '3':
			studentLogin();
			break;

		case '4':
			printExit();
			return 0;

		default:
			GoToXY(0, 18);
			cout << "�����������������루1/2/3/4��: ";
			continue;
		}
		printMainMenu();
	}
	return 0;
}