//#include<iostream>
//using namespace std;
//#include<string>
//
//// 1.����ģ��
//
//// ����ģ������
//// ����һ��ͨ�ú������亯������ֵ���ͺ��β����Ϳ��Բ������ƶ�����һ�����������������
//
//
//
//// �������ͽ����ĺ���
//void swapInt(int& a, int& b) {
//
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//// �������������ͺ���
//void swapDouble(double& a, double& b) {
//	double temp = a;
//	a = b;
//	b = temp;
//}
//
//// �ɴ�����
//// ����ģ��
//
//// 1.1 ����ģ���﷨
//template<typename T>  // ����һ��ģ��, ���߱�������������н����ŵ�T��Ҫ����, T��һ��ͨ����������
//// template<class T>  // typenameҲ���Ի���class
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
//	// ���ú���ģ����н���
//	// ���ַ�ʽʹ�ú���ģ��
//	// 1) �Զ������Ƶ�
//	//mySwap(a, b);
//	// 2) ��ʾָ������
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
////  1.2����ģ��ע������
//
////  1)�Զ������Ƶ��������Ƶ���һ�µ���������T, �ſ���ʹ��
//void test02() {
//
//	int a = 10;
//	int b = 20;
//	char c = 'c';
//
//	mySwap(a, b); // ��ȷ!
//	//mySwap(a, c); // ����! �Ƶ�����һ�µ�T���� 
//
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//}
//
//
////  2)ģ�����Ҫȷ����T���������ͣ��ſ���ʹ��
//template<class T>
//void func() {
//	cout << "func����" << endl;
//}
//
//void test02_1() {
//	//func(); // ����
//	func<int>(); 
//}
//
//// 1.3 ����ģ�尸��
//
//// ����������
//// ���ú���ģ���װһ������ĺ��������ԶԲ�ͬ�������������������
//// �������Ӵ�С�������㷨Ϊѡ������
//// �ֱ�����char�����int������в���
//
//// ʵ��ͨ�� �������������ĺ���
//// ���� �Ӵ�С
//// �㷨 ѡ������
//// ���� char int ����
//
//// ͨ�ô�ӡ���麯��
//template<class T>
//void print(T arr[], int len) {
//	for (int i = 0; i < len; i++) {
//		cout << arr[i];
//	}
//	cout << endl;
//}
//
//// ͨ��ѡ���������麯��
//template<class T>
//void arrSort(T arr[], int len) {
//	for (int i = 0; i < len; i++) {
//		int max = i; // �϶����ֵ�±�
//		for (int j = i + 1; j < len; j++) {
//
//			// �϶������ֵ �� ����������ֵ ҪС,˵�� j�±��Ԫ�ز������������ֵ
//			if (arr[max] < arr[j]) {
//				max = j; // ��������±�
//			}
//		}
//		if (max != i) {
//			mySwap(arr[max], arr[i]); // ����max��i�±��Ԫ��
//		}
//	}
//}
//
//
//void test03() {
//
//	// char �������
//	char charArr[] = { "abcfde" };
//	int num = sizeof(charArr) / sizeof(char);
//	arrSort(charArr, num);
//	print(charArr, num);
//	
//	// int �������
//	int intArr[] = { 1,7,5,6,4,3,2 };
//	int num2 = sizeof(intArr) / sizeof(int);
//	arrSort(intArr, num2);
//	print(intArr, num2);
//}
//
//
//
//// 1.4 ��ͨ�����뺯��ģ�������
//
//// ��ͨ�����뺯��ģ������
//// 1)��ͨ��������ʱ���Է����Զ�����ת������ʽ����ת����
//// 2)����ģ�����ʱ����������Զ������Ƶ������ᷢ����ʽ����ת��
//// 3)���������ʾָ�����͵ķ�ʽ�����Է�����ʽ����ת��
//
//// ��ͨ����
//int myAdd01(int a, int b) {
//	return a + b;
//}
//
//// ����ģ��
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
//	cout << myAdd01(a, c) << endl; // ���ᱨ��
//
//	// �Զ������Ƶ�
//	//cout<< myAdd02(a, c) << endl;// ����
//	cout<< myAdd02<int>(a, c)<< endl; // ��ʾָ�����;���
//	
//}
//// �ܽ᣺����ʹ����ʾָ�����͵ķ�ʽ�����ú���ģ�壬��Ϊ�����Լ�ȷ��ͨ������T
//
//// 1.5 ��ͨ�����뺯��ģ��ĵ��ù���
//
//// ���ù������£�
//// 1)�������ģ�����ͨ����������ʵ�֣����ȵ�����ͨ����
//// 2)����ͨ����ģ������б���ǿ�Ƶ��ú���ģ��
//// 3)����ģ��Ҳ���Է�������
//// 4)�������ģ����Բ������õ�ƥ��, ���ȵ��ú���ģ��
//
//void myPrint(int a, int b) {
//	cout << "������ͨ����" << endl;
//}
//
//template<class T>
//void myPrint(T a, T b) {
//	cout << "����ģ��" << endl;
//}
//
//template<class T>
//void myPrint(T a, T b, T c) {
//	cout << "��������ģ��" << endl;
//}
//
//
//void test05() {
//	int a = 100;
//	int b = 10;
//	myPrint(a, b);
//	
//	// ͨ����ģ������б�, ǿ�Ƶ��ú���ģ��
//	myPrint<>(a, b); 
//
//	myPrint(a, b, 100); // ���: ��������ģ��
//
//	// �������ģ����Բ������õ�ƥ��, ���ȵ��ú���ģ��
//	char c = '1';
//	char d = '2';
//
//	myPrint(c, d);
//
//}
////�ܽ᣺��Ȼ�ṩ�˺���ģ�壬��þͲ�Ҫ�ṩ��ͨ�������������׳��ֶ�����
//
//
//// 1.6 ģ��ľ�����
//
//// ģ�岻�����ܵ�,��Щ�ض���������, ��Ҫ�þ��廯��ʽ������ʵ��
//
//class Person {
//public:
//	Person(string name, int age){
//		this->m_Age = age;
//		this->m_Name = name;
//	}
//	// ����
//	string m_Name;
//	// ����
//	int m_Age;
//};
//
//
//// �Ա����������Ƿ���Ⱥ���
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
//// ����Person���廯Person�İ汾ʵ�ִ���, ���廯���ȵ���
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
//		cout << "ab���" << endl;
//	}
//	else {
//		cout << "ab�����" << endl;
//	}
//
//	// �Զ�����������
//	Person p1("Tom", 10);
//	Person p2("Tom", 10);
//	bool ret1 = myCompare(p1, p2);
//
//	if (ret1) {
//		cout << "Person���" << endl;
//	}
//	else {
//		cout << "Person�����" << endl;
//	}
//	
//}
//// �ܽ᣺
//// ���þ��廯��ģ�壬���Խ���Զ������͵�ͨ�û�
//// ѧϰģ�岢����Ϊ��дģ�壬������STL�ܹ�����ϵͳ�ṩ��ģ��
//
//
//
//
//
//// 2.��ģ��
//
//// ��ģ�����ã�
//// ����һ��ͨ���࣬���еĳ�Ա �������Ϳ��Բ������ƶ�����һ�����������������
//
//// 2.1 ��ģ���﷨
//template<class NameType, class AgeType = int>
//class Person1 {
//public:
//	Person1(NameType name, AgeType age) {
//		this->m_Name = name;
//		this->m_Age = age;
//	}
//	
//	void showPerson1() {
//		cout << "����: " << m_Name << " ����: " << m_Age << endl;
//	}
//
//	NameType m_Name;
//	AgeType m_Age;
//};
//
//void test07() {
//	Person1<string, int> p1("�����", 13);
//	p1.showPerson1();
//}
//
//// 2.2 ��ģ���뺯��ģ������
//
////��ģ���뺯��ģ��������Ҫ�����㣺
//// 1)��ģ��û���Զ������Ƶ���ʹ�÷�ʽ 
//// 2)��ģ����ģ������б��п�����Ĭ�ϲ���
//
//void test08() {
//
//	//Person1 p1("�����", 13); // �޷����Զ������Ƶ�
//
//	Person1<string> p1("��˽�", 12);  // Ĭ�ϲ���  int  ��ԭģ���ϼ�һ��.
//	p1.showPerson1();
//}
//
//// 2.3 ��ģ���г�Ա��������ͨ���г�Ա��������ʱ��
//
//// ����
//// ��ͨ���еĳ�Ա����һ��ʼ�Ϳ��Դ���
//// ��ģ���еĳ�Ա�����ڵ���ʱ�Ŵ���
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
//	// ��ģ���еĳ�Ա����
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
//// 2.4 ��ģ��Ķ�������������
//
////  һ�������ִ��뷽ʽ��
//// 1)ָ�����������-- - ֱ����ʾ�������������
//// 2)����ģ�廯-- - �������еĲ�����Ϊģ����д���
//// 3)������ģ�廯-- - ������������� ģ�廯���д���
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
//		cout << "����: " << this->m_Name << "����: " << this->m_Age << endl;
//	}
//
//	T1 m_Name;
//	T2 m_Age;
//};
//
//// 2.4.1 ָ����������
//void printPerson1(Person4<string, int>& p) {
//	p.showPerson4();
//}
//
//// 2.4.2 ����ģ�廯
//template<class T1, class T2>
//void printPerson2(Person4<T1, T2>&p) {
//	p.showPerson4();
//
//	cout << "T1������Ϊ: " << typeid(T1).name() << endl;
//	cout << "T2������Ϊ: " << typeid(T2).name() << endl;
//}
//
//// 2.4.3 ������ģ�廯
//template<class T>
//void printPerson3(T& p) {
//	p.showPerson4();
//	cout << "T������Ϊ: " << typeid(T).name() << endl;
//
//}
//
//void test10() {
//
//	Person4<string, int>p("�����", 100);
//	printPerson1(p);
//	printPerson2(p);
//	printPerson3(p);
//
//}
//// �ܽ᣺
//// ͨ����ģ�崴���Ķ��󣬿��������ַ�ʽ�����н��д���
//// ʹ�ñȽϹ㷺�ǵ�һ�֣�ָ�����������
//
//
//// 2.5 ��ģ����̳�
//
//// ����ģ�������̳�ʱ����Ҫע��һ�¼��㣺
//// ������̳еĸ�����һ����ģ��ʱ��������������ʱ��Ҫָ����������T������
//// �����ָ�����������޷�����������ڴ�
//// ��������ָ����������T�����ͣ�����Ҳ���Ϊ��ģ��
//
//template<class T>
//class Base {
//	T m;
//};
//
////class Son :public Base { };// ����, ����Ҫ֪�������е�T������, ���ܼ̳и�����
//class Son: public Base<int>{};
//
//// ��������ָ����������T�����ͣ�����Ҳ���Ϊ��ģ��
//template<class T1, class T2>
//class Son2 : public Base<T2>{
//public:
//	Son2() {
//		cout << "T1������: " << typeid(T1).name() << endl;
//		cout << "T2������: " << typeid(T2).name() << endl;
//	}
//	T1 obj;
//};
//
//void test11() {
//	Son2<int, char>S;
//}
//
//
//// 2.6 ��ģ���Ա��������ʵ��
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
//	//		cout << "����: " << this->m_Name << " ����: " << this->m_Age << endl;
//	//}
//
//	T1 m_Name;
//	T2 m_Age;
//};
//
//// ���캯������ʵ��
//template<class T1, class T2>
//Person6<T1, T2>::Person6(T1 name, T2 age) {
//	this->m_Name = name;
//	this->m_Age = age;
//}
//
//// ��Ա��������ʵ��
//template<class T1, class T2>
//void Person6<T1, T2>::showPerson6(){
//	cout << "����: " << this->m_Name << " ����: " << this->m_Age << endl;
//
//}
//
//void test12() {
//	Person6 < string, int>P("tom", 13);
//	P.showPerson6();
//}
//
//
//// 2.7 ��ģ����ļ���д�Լ����
//
//// ѧϰĿ�꣺
//// ������ģ���Ա�������ļ���д�����������Լ������ʽ
//// ���⣺
//// ��ģ���г�Ա��������ʱ�����ڵ��ý׶Σ����·��ļ���дʱ���Ӳ���
//// �����
//// �����ʽ1��ֱ�Ӱ���.cppԴ�ļ�
//// �����ʽ2����������ʵ��д��ͬһ���ļ��У������ĺ�׺��Ϊ.hpp��hpp��Լ�������ƣ�������ǿ��
//
//// #include "01Person7.h" ����
////#include "01Person7.cpp" // �������1
//#include "01Person7.hpp" // ��2 ��������
//void test13() {
//	Person7<string, int>p("Jeff", 13);
//	p.showPerson7();
//}
//
//// 2.8 ��ģ������Ԫ
//
//// ѧϰĿ��:
////			������ģ�������Ԫ���������ں�����ʵ��
//// ȫ�ֺ�������ʵ�� - ֱ��������������Ԫ����
//// ȫ�ֺ�������ʵ�� - ��Ҫ��ǰ�ñ�����֪��ȫ�ֺ����Ĵ���
//
//
//// ͨ��ȫ�ֺ��� ��ӡPerson8��Ϣ
//
//// ��ǰ�ñ�����֪��Person��Ĵ���
//template<class T1, class T2>
//class Person8;
//// ����ʵ��
//// �ñ�������ǰ֪����������Ĵ���
//template<class T1, class T2>
//void printPerson8_1(Person8<T1, T2> p) {
//	cout << "����ʵ��----����: " << p.m_Name << " ����: " << p.m_Age;
//}
//
//
//template<class T1, class T2>
//class Person8 {
//	// ȫ�ֺ��� ����ʵ��
//	friend void printPerson8(Person8<T1, T2> p) {
//		cout << "����: " << p.m_Name << " ����: " << p.m_Age;
//	}
//
//	// ȫ�ֺ��� ����ʵ��
//	// �ӿ�ģ������б�
//	// ���ȫ�ֺ��� ������ʵ��, ��Ҫ�ñ�������ǰ֪����������Ĵ���
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
//	// 1)ȫ�ֺ���������ʵ��  �Ƽ�ʹ��
//	Person8<string, int>p("tom", 13);
//	printPerson8(p);
//
//	// 2)ȫ�ֺ���������ʵ��
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