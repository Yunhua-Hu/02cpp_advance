#pragma once
#include <iostream>
using namespace std;
// @file:
// @author:
// @date: 2023/12/14
// @brief:


template<class T>
class MyArray {
public:
	// �вι��� ���� ����
	MyArray(int capacity) {
		//cout << "�вι������" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}

	// ��������
	MyArray(const MyArray& arr) {
		//cout << "������������" << endl;

		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		// ǳ���� �������Զ�����
		//this->pAddress = arr.pAddress;
		
		// ���
		this->pAddress = new T[arr.m_Capacity];

		// ��arr�е����ݸ��ƹ���
		for (int i = 0; i < this->m_Size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}

	}

	// ����operator= ��ֹǳ����    a = b = c
	MyArray& operator=(const MyArray& arr) {
		//cout << "=����" << endl;

		// ���ж�ԭ�������Ƿ�Ϊ��, �����Ϊ�յ����ͷ�
		if (this->pAddress != NULL) {
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}

		// ���
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < this->m_Size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
		
		return *this;
	}



	// ��������
	~MyArray() {

		if (this->pAddress != NULL) {
			//cout << "������������" << endl;

			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}

	// β�巨
	void Push_Back(const T& val) {
		// �ж������Ƿ���ڴ�С
		if (this->m_Capacity == this->m_Size) {
			return;
		}

		this->pAddress[this->m_Size] = val;  // ����ĩβ��������
		this->m_Size++; // ���������С
	}

	// βɾ��
	void Pop_Back() {
		// ���û����ʲ������һ��Ԫ��, ��Ϊβɾ, �߼�ɾ��
		if (this->m_Size == 0) {
			return;
		}
		this->m_Size--;
	}

	// ͨ���±귽ʽ���������е�Ԫ��  arr[0] = 100;
	// ����[]
	T& operator[](int index) {
		return this->pAddress[index];
	}

	// ������������
	int getCapacity() {
		return this->m_Capacity;
	}

	// ���������С
	int getSize() {
		return this->m_Size;
	}

private:
	
	T *pAddress; // ָ��ָ��������ٵ���ʵ����λ��

	int m_Capacity; // ��������

	int m_Size; // �����С	

};


