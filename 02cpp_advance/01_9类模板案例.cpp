//#include <iostream>
//#include"01_9MyArray.hpp"
//#include<string>
//using namespace std;
//// @file : 
//// @autor: hua
//// @date: 2012/12/13
//// @brief: 类模板案例
//
//
//
//// 2.9 类模板案例
//
////	案例描述 : 实现一个通用的数组类，要求如下：
////
////* 可以对内置数据类型以及自定义数据类型的数据进行存储
////* 将数组中的数据存储到堆区
////* 构造函数中可以传入数组的容量
////* 提供对应的拷贝构造函数以及operator = 防止浅拷贝问题
////* 提供尾插法和尾删法对数组中的数据进行增加和删除
////* 可以通过下标的方式访问数组中的元素
////* 可以获取数组中当前元素个数和数组的容量
//
//
//void printArray(MyArray<int>& arr) {
//	for (int i = 0; i < arr.getSize(); i++) {
//		cout << arr[i] << endl;
//	}
//}
//
//void test01() {
//	MyArray <int>arr1(5);
//	//MyArray <int>arr2(arr1);
//	//MyArray <int>arr3(100);
//	//arr3 = arr1;
//
//	for (int i = 0; i < 5; i++) {
//		// 利用尾插法向数组中插入数据
//		arr1.Push_Back(i);
//	}
//	
//	cout << "arr1的打印输出为: " << endl;
//	printArray(arr1);
//
//	cout << "arr1容量为: " << arr1.getCapacity() << endl;
//	cout << "arr1大小为: " << arr1.getSize() << endl;
//
//	MyArray<int> arr2(arr1);
//	cout << "arr2的打印输出为: " << endl;
//	printArray(arr2);
//	arr2.Pop_Back();
//	cout << "arr2尾删后: " << endl;
//	cout << "arr2容量为: " << arr2.getCapacity() << endl;
//	cout << "arr2大小为: " << arr2.getSize() << endl;
//}
// 
//// 测试自定义数据类型
//class Person {
//
//public:
//	Person() {};
//	Person(string name, int age) {
//		this->m_Age = age;
//		this->m_Name = name;
//	}
//
//
//	string m_Name;
//	int m_Age;
//};
//
//void printPersonArray(MyArray<Person>& arr) {
//	for (int i = 0; i < arr.getSize(); i++) {
//		cout << "姓名: " << arr[i].m_Name << " 年龄: " << arr[i].m_Age << endl;
//	}
//}
//void test02() {
//	MyArray<Person>arr(10);
//
//	Person p1("孙悟空1", 10);
//	Person p2("孙悟空2", 11);
//	Person p3("孙悟空3", 12);
//	Person p4("孙悟空4", 13);
//	Person p5("孙悟空5", 14);
//
//	// 数据插入
//	arr.Push_Back(p1);
//	arr.Push_Back(p2);
//	arr.Push_Back(p3);
//	arr.Push_Back(p4);
//	arr.Push_Back(p5);
//
//	// 打印数组
//	printPersonArray(arr);
//
//	// 输出容量
//	cout << "arr容量为: " << arr.getCapacity() << endl;
//	
//	// 输出大小
//	cout << "arr大小为: " << arr.getSize() << endl;
//}
//
//
//int main() {
//
//	//test01();
//	test02();
//
//	system("pause");
//	
//	return 0;
//}
