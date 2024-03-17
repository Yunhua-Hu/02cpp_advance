//#include<iostream>
//using namespace std;
//#include<string>
//
//// 1.函数模板
//
//// 函数模板作用
//// 建立一个通用函数，其函数返回值类型和形参类型可以不具体制定，用一个虚拟的类型来代表。
//
//
//
//// 两个整型交换的函数
//void swapInt(int& a, int& b) {
//
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//// 交换两个浮点型函数
//void swapDouble(double& a, double& b) {
//	double temp = a;
//	a = b;
//	b = temp;
//}
//
//// 由此引出
//// 函数模板
//
//// 1.1 函数模板语法
//template<typename T>  // 声明一个模板, 告诉编译器后面代码中紧跟着的T不要报错, T是一个通用数据类型
//// template<class T>  // typename也可以换成class
//void mySwap(T& a, T& b) {
//	T temp = a;
//	a = b;
//	b = temp;
//}
//
//void test01() {
//
//	int a = 20;
//	int b = 10;
//	swapInt(a, b);
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	// 利用函数模板进行交换
//	// 两种方式使用函数模板
//	// 1) 自动类型推导
//	//mySwap(a, b);
//	// 2) 显示指定类型
//	mySwap<int>(a, b);
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//
//	double c = 1.1;
//	double d = 2.2;
//	swapDouble(c, d);
//	cout << "c = " << c << endl;
//	cout << "d = " << d << endl;
//
//}
//
//
////  1.2函数模板注意事项
//
////  1)自动类型推导，必须推导出一致的数据类型T, 才可以使用
//void test02() {
//
//	int a = 10;
//	int b = 20;
//	char c = 'c';
//
//	mySwap(a, b); // 正确!
//	//mySwap(a, c); // 错误! 推导不出一致的T类型 
//
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//}
//
//
////  2)模板必须要确定出T的数据类型，才可以使用
//template<class T>
//void func() {
//	cout << "func调用" << endl;
//}
//
//void test02_1() {
//	//func(); // 错误
//	func<int>(); 
//}
//
//// 1.3 函数模板案例
//
//// 案例描述：
//// 利用函数模板封装一个排序的函数，可以对不同数据类型数组进行排序
//// 排序规则从大到小，排序算法为选择排序
//// 分别利用char数组和int数组进行测试
//
//// 实现通用 对数组进行排序的函数
//// 规则 从大到小
//// 算法 选择排序
//// 测试 char int 数组
//
//// 通用打印数组函数
//template<class T>
//void print(T arr[], int len) {
//	for (int i = 0; i < len; i++) {
//		cout << arr[i];
//	}
//	cout << endl;
//}
//
//// 通用选择排序数组函数
//template<class T>
//void arrSort(T arr[], int len) {
//	for (int i = 0; i < len; i++) {
//		int max = i; // 认定最大值下标
//		for (int j = i + 1; j < len; j++) {
//
//			// 认定的最大值 比 遍历出的数值 要小,说明 j下标的元素才是真正的最大值
//			if (arr[max] < arr[j]) {
//				max = j; // 更新最大下标
//			}
//		}
//		if (max != i) {
//			mySwap(arr[max], arr[i]); // 交换max与i下标的元素
//		}
//	}
//}
//
//
//void test03() {
//
//	// char 数组测试
//	char charArr[] = { "abcfde" };
//	int num = sizeof(charArr) / sizeof(char);
//	arrSort(charArr, num);
//	print(charArr, num);
//	
//	// int 数组测试
//	int intArr[] = { 1,7,5,6,4,3,2 };
//	int num2 = sizeof(intArr) / sizeof(int);
//	arrSort(intArr, num2);
//	print(intArr, num2);
//}
//
//
//
//// 1.4 普通函数与函数模板的区别
//
//// 普通函数与函数模板区别：
//// 1)普通函数调用时可以发生自动类型转换（隐式类型转换）
//// 2)函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
//// 3)如果利用显示指定类型的方式，可以发生隐式类型转换
//
//// 普通函数
//int myAdd01(int a, int b) {
//	return a + b;
//}
//
//// 函数模板
//template<class T>
//T myAdd02(T a, T b) {
//	return a + b;
//}
//
//void test04() {
//
//	int a = 10;
//	int b = 20;
//	char c = 'c'; // a - 97 c - 99
//	cout << myAdd01(a, c) << endl; // 不会报错
//
//	// 自动类型推导
//	//cout<< myAdd02(a, c) << endl;// 报错
//	cout<< myAdd02<int>(a, c)<< endl; // 显示指定类型就行
//	
//}
//// 总结：建议使用显示指定类型的方式，调用函数模板，因为可以自己确定通用类型T
//
//// 1.5 普通函数与函数模板的调用规则
//
//// 调用规则如下：
//// 1)如果函数模板和普通函数都可以实现，优先调用普通函数
//// 2)可以通过空模板参数列表来强制调用函数模板
//// 3)函数模板也可以发生重载
//// 4)如果函数模板可以产生更好的匹配, 优先调用函数模板
//
//void myPrint(int a, int b) {
//	cout << "调用普通函数" << endl;
//}
//
//template<class T>
//void myPrint(T a, T b) {
//	cout << "调用模板" << endl;
//}
//
//template<class T>
//void myPrint(T a, T b, T c) {
//	cout << "调用重载模板" << endl;
//}
//
//
//void test05() {
//	int a = 100;
//	int b = 10;
//	myPrint(a, b);
//	
//	// 通过空模板参数列表, 强制调用函数模板
//	myPrint<>(a, b); 
//
//	myPrint(a, b, 100); // 输出: 调用重载模板
//
//	// 如果函数模板可以产生更好的匹配, 优先调用函数模板
//	char c = '1';
//	char d = '2';
//
//	myPrint(c, d);
//
//}
////总结：既然提供了函数模板，最好就不要提供普通函数，否则容易出现二义性
//
//
//// 1.6 模板的局限性
//
//// 模板不是万能的,有些特定数据类型, 需要用具体化方式做特殊实现
//
//class Person {
//public:
//	Person(string name, int age){
//		this->m_Age = age;
//		this->m_Name = name;
//	}
//	// 姓名
//	string m_Name;
//	// 年龄
//	int m_Age;
//};
//
//
//// 对比两个数据是否相等函数
//template<class T>
//bool myCompare(T& a, T& b) {
//	if (a == b) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//
//// 利用Person具体化Person的版本实现代码, 具体化优先调用
//template<> bool myCompare(Person& p1, Person& p2) {
//	if (p1.m_Age == p2.m_Age && p1.m_Name == p2.m_Name) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//
//
//
//void test06() {
//	int a = 10;
//	int b = 20;
//
//	bool ret = myCompare(a, b);
//
//	if (ret) {
//		cout << "ab相等" << endl;
//	}
//	else {
//		cout << "ab不相等" << endl;
//	}
//
//	// 自定义类型数据
//	Person p1("Tom", 10);
//	Person p2("Tom", 10);
//	bool ret1 = myCompare(p1, p2);
//
//	if (ret1) {
//		cout << "Person相等" << endl;
//	}
//	else {
//		cout << "Person不相等" << endl;
//	}
//	
//}
//// 总结：
//// 利用具体化的模板，可以解决自定义类型的通用化
//// 学习模板并不是为了写模板，而是在STL能够运用系统提供的模板
//
//
//
//
//
//// 2.类模板
//
//// 类模板作用：
//// 建立一个通用类，类中的成员 数据类型可以不具体制定，用一个虚拟的类型来代表。
//
//// 2.1 类模板语法
//template<class NameType, class AgeType = int>
//class Person1 {
//public:
//	Person1(NameType name, AgeType age) {
//		this->m_Name = name;
//		this->m_Age = age;
//	}
//	
//	void showPerson1() {
//		cout << "姓名: " << m_Name << " 年龄: " << m_Age << endl;
//	}
//
//	NameType m_Name;
//	AgeType m_Age;
//};
//
//void test07() {
//	Person1<string, int> p1("孙悟空", 13);
//	p1.showPerson1();
//}
//
//// 2.2 类模板与函数模板区别
//
////类模板与函数模板区别主要有两点：
//// 1)类模板没有自动类型推导的使用方式 
//// 2)类模板在模板参数列表中可以有默认参数
//
//void test08() {
//
//	//Person1 p1("孙悟空", 13); // 无法用自动类型推导
//
//	Person1<string> p1("猪八戒", 12);  // 默认参数  int  在原模板上加一个.
//	p1.showPerson1();
//}
//
//// 2.3 类模板中成员函数和普通类中成员函数创建时机
//
//// 区别：
//// 普通类中的成员函数一开始就可以创建
//// 类模板中的成员函数在调用时才创建
//
//class Person2 {
//public:
//	void showPerson2() {
//		cout << "Person2 show" << endl;
//	}
//};
//
//class Person3 {
//public:
//	void showPerson3() {
//		cout << "Person3 show" << endl;
//	}
//};
//
//template<class T>
//class myClass {
//public:
//	T obj;
//
//	// 类模板中的成员函数
//	void func1() {
//		obj.showPerson2();
//	}
//
//	void func2() {
//		obj.showPerson3();
//	}
//};
//
//void test09() {
//
//	myClass<Person2>m;
//	m.func1();
//	//m.func2(); 
//}
//
//// 2.4 类模板的对象做函数参数
//
////  一共有三种传入方式：
//// 1)指定传入的类型-- - 直接显示对象的数据类型
//// 2)参数模板化-- - 将对象中的参数变为模板进行传递
//// 3)整个类模板化-- - 将这个对象类型 模板化进行传递
//
//template<class T1,class T2>
//class Person4 {
//public:
//	Person4(T1 name,T2 age) {
//		m_Name = name;
//		m_Age = age;
//	}
//
//	void showPerson4() {
//		cout << "姓名: " << this->m_Name << "年龄: " << this->m_Age << endl;
//	}
//
//	T1 m_Name;
//	T2 m_Age;
//};
//
//// 2.4.1 指定传入类型
//void printPerson1(Person4<string, int>& p) {
//	p.showPerson4();
//}
//
//// 2.4.2 参数模板化
//template<class T1, class T2>
//void printPerson2(Person4<T1, T2>&p) {
//	p.showPerson4();
//
//	cout << "T1的类型为: " << typeid(T1).name() << endl;
//	cout << "T2的类型为: " << typeid(T2).name() << endl;
//}
//
//// 2.4.3 整个类模板化
//template<class T>
//void printPerson3(T& p) {
//	p.showPerson4();
//	cout << "T的类型为: " << typeid(T).name() << endl;
//
//}
//
//void test10() {
//
//	Person4<string, int>p("孙悟空", 100);
//	printPerson1(p);
//	printPerson2(p);
//	printPerson3(p);
//
//}
//// 总结：
//// 通过类模板创建的对象，可以有三种方式向函数中进行传参
//// 使用比较广泛是第一种：指定传入的类型
//
//
//// 2.5 类模板与继承
//
//// 当类模板碰到继承时，需要注意一下几点：
//// 当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
//// 如果不指定，编译器无法给子类分配内存
//// 如果想灵活指定出父类中T的类型，子类也需变为类模板
//
//template<class T>
//class Base {
//	T m;
//};
//
////class Son :public Base { };// 错误, 必须要知道父类中的T的类型, 才能继承给子类
//class Son: public Base<int>{};
//
//// 如果想灵活指定出父类中T的类型，子类也需变为类模板
//template<class T1, class T2>
//class Son2 : public Base<T2>{
//public:
//	Son2() {
//		cout << "T1的类型: " << typeid(T1).name() << endl;
//		cout << "T2的类型: " << typeid(T2).name() << endl;
//	}
//	T1 obj;
//};
//
//void test11() {
//	Son2<int, char>S;
//}
//
//
//// 2.6 类模板成员函数类外实现
//template<class T1,class T2>
//class Person6 {
//public:
//	Person6(T1 name, T2 age);
//	/*{
//		this->m_Name = name;
//		this->m_Age = age;
//	}*/
//	void showPerson6();
//	//{
//	//		cout << "姓名: " << this->m_Name << " 年龄: " << this->m_Age << endl;
//	//}
//
//	T1 m_Name;
//	T2 m_Age;
//};
//
//// 构造函数类外实现
//template<class T1, class T2>
//Person6<T1, T2>::Person6(T1 name, T2 age) {
//	this->m_Name = name;
//	this->m_Age = age;
//}
//
//// 成员函数类外实现
//template<class T1, class T2>
//void Person6<T1, T2>::showPerson6(){
//	cout << "姓名: " << this->m_Name << " 年龄: " << this->m_Age << endl;
//
//}
//
//void test12() {
//	Person6 < string, int>P("tom", 13);
//	P.showPerson6();
//}
//
//
//// 2.7 类模板分文件编写以及解决
//
//// 学习目标：
//// 掌握类模板成员函数分文件编写产生的问题以及解决方式
//// 问题：
//// 类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到
//// 解决：
//// 解决方式1：直接包含.cpp源文件
//// 解决方式2：将声明和实现写到同一个文件中，并更改后缀名为.hpp，hpp是约定的名称，并不是强制
//
//// #include "01Person7.h" 报错
////#include "01Person7.cpp" // 解决方法1
//#include "01Person7.hpp" // 法2 主流方法
//void test13() {
//	Person7<string, int>p("Jeff", 13);
//	p.showPerson7();
//}
//
//// 2.8 类模板与友元
//
//// 学习目标:
////			掌握类模板配合友元函数的类内和类外实现
//// 全局函数类内实现 - 直接在类内声明友元即可
//// 全局函数类外实现 - 需要提前让编译器知道全局函数的存在
//
//
//// 通过全局函数 打印Person8信息
//
//// 提前让编译器知道Person类的存在
//template<class T1, class T2>
//class Person8;
//// 类外实现
//// 让编译器提前知道这个函数的存在
//template<class T1, class T2>
//void printPerson8_1(Person8<T1, T2> p) {
//	cout << "类外实现----姓名: " << p.m_Name << " 年龄: " << p.m_Age;
//}
//
//
//template<class T1, class T2>
//class Person8 {
//	// 全局函数 类内实现
//	friend void printPerson8(Person8<T1, T2> p) {
//		cout << "姓名: " << p.m_Name << " 年龄: " << p.m_Age;
//	}
//
//	// 全局函数 类外实现
//	// 加空模板参数列表
//	// 如果全局函数 是类外实现, 需要让编译器提前知道这个函数的存在
//	friend void printPerson8_1<>(Person8<T1, T2> p);
//
//public:
//	Person8(T1 name, T2 age) {
//		this->m_Name = name;
//		this->m_Age = age;
//	}
//
//private:
//	T1 m_Name;
//	T2 m_Age;
//};
//
//void test14() {
//
//	// 1)全局函数在类内实现  推荐使用
//	Person8<string, int>p("tom", 13);
//	printPerson8(p);
//
//	// 2)全局函数在类外实现
//	Person8<string, int>p1("Jeff", 20);
//	printPerson8_1(p1);
//
//}
//
//
//
//
//int main() {
//
//	//test01();
//	//test02();
//	//test03();
//	//test04();
//	//test05();
//	//test06();
//	//test07();
//	//test08();
//	//test09();
//	//test10();
//	//test11();
//	//test12();
//	//test13();
//	test14();
//
//
//	return 0;
//}