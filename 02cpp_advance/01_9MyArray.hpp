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
	// 有参构造 参数 容量
	MyArray(int capacity) {
		//cout << "有参构造调用" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}

	// 拷贝函数
	MyArray(const MyArray& arr) {
		//cout << "拷贝函数调用" << endl;

		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		// 浅拷贝 编译器自动拷贝
		//this->pAddress = arr.pAddress;
		
		// 深拷贝
		this->pAddress = new T[arr.m_Capacity];

		// 把arr中的数据复制过来
		for (int i = 0; i < this->m_Size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}

	}

	// 重载operator= 防止浅拷贝    a = b = c
	MyArray& operator=(const MyArray& arr) {
		//cout << "=调用" << endl;

		// 先判断原来堆区是否为空, 如果不为空得先释放
		if (this->pAddress != NULL) {
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}

		// 深拷贝
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < this->m_Size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
		
		return *this;
	}



	// 析构函数
	~MyArray() {

		if (this->pAddress != NULL) {
			//cout << "析构函数调用" << endl;

			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}

	// 尾插法
	void Push_Back(const T& val) {
		// 判断容量是否等于大小
		if (this->m_Capacity == this->m_Size) {
			return;
		}

		this->pAddress[this->m_Size] = val;  // 数组末尾插入数据
		this->m_Size++; // 更新数组大小
	}

	// 尾删法
	void Pop_Back() {
		// 让用户访问不到最后一个元素, 即为尾删, 逻辑删除
		if (this->m_Size == 0) {
			return;
		}
		this->m_Size--;
	}

	// 通过下标方式访问数组中的元素  arr[0] = 100;
	// 重载[]
	T& operator[](int index) {
		return this->pAddress[index];
	}

	// 返回数组容量
	int getCapacity() {
		return this->m_Capacity;
	}

	// 返回数组大小
	int getSize() {
		return this->m_Size;
	}

private:
	
	T *pAddress; // 指针指向堆区开辟的真实数组位置

	int m_Capacity; // 数组容量

	int m_Size; // 数组大小	

};



