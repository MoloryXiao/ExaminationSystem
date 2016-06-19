#ifndef CHECK_H_
#define CHECK_H_

#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

class Check {
private:
	struct type {
		std::string name;
		double rate;
		std::vector<double> score;
	};
	std::vector<type> table;
public:
	Check() {}
	~Check() {}
	// ����һ�ֿ���
	void createCheck(std::string nm);
	// ɾ��һ�ֿ���
	void deleteCheck(int index);
	// ��¼�ɼ�
	void enrollScore(int index, double sc);
	// ɾ���ɼ�������ɼ����ᱻ����Ϊ0��
	void deleteScore(int index, int n);
	// ���óɼ�
	void resetScore(int index, int n, double sc);
	// ���ø�������ռ�ֱܷ���
	void resetRate();
	// ��ʾһ�ֿ������
	void showCheck(int index);
	// ��ʾ���˻�����Ϣ
	void showTableInfo();
	// ��ʾ���п��˵����
	void showTable();
	// ����ܷ�
	double getAllScore();
	int getCheckNum();		//��ȡ������Ŀ������
private:
	bool checkRate(std::vector<double> temp);
	void operateScore(int index, int n, double sc = 0);
	bool findIndexPos(int index, std::vector<type>::iterator &it);
	void printCheck(std::vector<type>::iterator it);
};

#endif // CHECK_H_
