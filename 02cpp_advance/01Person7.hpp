#pragma once  // ��ֹͷ�ļ��ظ�����
#include <iostream>
using namespace std;

template<class T1, class T2>
class Person7 {
public:
	Person7(T1 name, T2 age);

	void showPerson7();

	T1 m_Name;
	T2 m_Age;
};

// ���캯������ʵ��
template<class T1, class T2>
Person7<T1, T2>::Person7(T1 name, T2 age) {
	this->m_Name = name;
	this->m_Age = age;
}

// ��Ա��������ʵ��
template<class T1, class T2>
void Person7<T1, T2>::showPerson7() {
	cout << "����: " << this->m_Name << " ����: " << this->m_Age << endl;

}
