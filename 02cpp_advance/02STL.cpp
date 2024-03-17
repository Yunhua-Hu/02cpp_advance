#include<iostream>
#include<string>
#include<vector>
#include<algorithm>  // ��׼�㷨ͷ�ļ�
#include<deque>
#include<ctime> // �������
#include<stack> //   test19
#include<queue> //   test20
#include<list> // test21
#include<set> // test22
#include<map> // test23
using namespace std;
// @file : 
// @author : hua
// @data : 2023/12/21
// @brief : 




// ��ʶSTL��һ�ڿ�����

//### 1.1 STL�ĵ���
// ���������������һֱϣ������һ�ֿ��ظ����õĶ���
//
// C++���������ͷ��ͱ��˼�룬Ŀ�ľ��Ǹ����Ե�����
//
// �������£����ݽṹ���㷨��δ����һ�ױ�׼, ���±��ȴ��´����ظ�����
//
// Ϊ�˽������ݽṹ���㷨��һ�ױ�׼, ������STL

// 1.2-1.4 ������

//### 1.5 �����㷨��������ʶ

//�˽�STL���������㷨������������֮���������ô������STL������
//STL����õ�����ΪVector���������Ϊ���飬�������ǽ�ѧϰ�������������в������ݡ��������������


// 1.5.1 vector���������������

//������   vector
//�㷨��   for_each
//�������� vector<int > ::iterator

void myPrint(int val) {
	cout << val << endl;
}


void test01() {
	// ����һ��vector����, ����
	vector<int> v;
	// �������в�������
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	//// ͨ�����������������е�����
	//vector<int>::iterator itBegin = v.begin(); // ��ʼ������ ָ�������е�һ��Ԫ��
	//vector<int>::iterator itEnd = v.end(); // ���������� ָ�����������һ��Ԫ�ص���һ��λ��

	//// ��һ�����
	//while (itBegin != itEnd) {
	//	cout << *itBegin << endl;
	//	itBegin++;
	//}

	//// �ڶ��ֱ���
	//for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
	//	cout << *it << endl;
	//}

	// �����ֱ��� ����STL�ṩ�ı����㷨
	for_each(v.begin(), v.end(), myPrint);
}

// 1.5.2 Vector�����д���Զ�����������
class Person {
public:
	Person(string name, int age) {
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};

void test02() {
	vector<Person> v;
	Person p1("1", 10);
	Person p2("2", 20);
	Person p3("3", 30);
	Person p4("4", 40);
	Person p5("5", 50);

	//���������������
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	// ���������е�����
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		//cout << "����: " << (*it).m_Name << " ����: " << (*it).m_Age << endl;
		cout << "����: " << it->m_Name << " ����: " << it->m_Age << endl;
	}
}

// ����Զ����������� ָ��
void test02_1() { 
	vector<Person*> v;
	Person p1("1", 10);
	Person p2("2", 20);
	Person p3("3", 30);
	Person p4("4", 40);
	Person p5("5", 50);

	//���������������
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	// ���������е�����
	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "test02_1  ����: " << (*it)->m_Name << " ����: " << (*it)->m_Age << endl;
		
	}
}


// 1.5.3 Vector������Ƕ������
void test03() {
	vector< vector<int>>v;

	// ����С����
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;

	// ��С�������������
	for (int i = 0; i < 4; i++) {
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}

	// ��С���������������
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);

	// ͨ�������� ��������
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++) {
		// (*it) ----- ����һ������
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++) {
			cout << *vit << " ";
		}
		cout << endl;
	}

}


// 2.1 string����

// 2.1.1 string�����������

// 2.1.2 string���캯��
//���캯��ԭ�ͣ�
//
// string();               		 //����һ���յ��ַ��� ����: string str;
// string(const char* s); 	     //ʹ���ַ���s��ʼ��
// string(const string& str);    //ʹ��һ��string�����ʼ����һ��string����
// string(int n, char c);        //ʹ��n���ַ�c��ʼ�� 

void test04() {
	string s1; // Ĭ�Ϲ���

	const char* str = "hello world";
	string s2(str);

	cout << "s2 = " << s2 << endl;

	string s3(s2);
	cout << "s3 = " << s3 << endl;

	string s4(10, 'a');
	cout << "s4 = " << s4 << endl;


}

// 2.1.3 string ��ֵ����

/*
string& operator=(const char* s);             //char*�����ַ��� ��ֵ����ǰ���ַ���
string& operator=(const string &s);         //���ַ���s������ǰ���ַ���
string& operator=(char c);                          //�ַ���ֵ����ǰ���ַ���
string& assign(const char *s);            //���ַ���s������ǰ���ַ���
string& assign(const char *s, int n);     //���ַ���s��ǰn���ַ�������ǰ���ַ���
string& assign(const string &s);              //���ַ���s������ǰ�ַ���
string& assign(int n, char c);                  //��n���ַ�c������ǰ�ַ���
*/

void test05() {
	string str1;
	str1 = "hello world";
	cout << "str1 = " << str1 << endl;

	string str2;
	str2 = str1;
	cout << "str2 = " << str2 << endl;

	string str3;
	str3 = 'a';
	cout << "str3 = " << str3 << endl;

	string str4;
	str4.assign("hello c++");
	cout << "str4 = " << str4 << endl;

	string str5;
	str5.assign("hello c++", 5);
	cout << "str5 = " << str5 << endl;

	string str6;
	str6.assign(str5);
	cout << "str6 = " << str6 << endl;

	string str7;
	str7.assign(10, 'w');
	cout << "str7 = " << str7 << endl;
}

//2.1.4 string �ַ���ƴ��

/*
* `string& operator+=(const char* str);`                  //����+=������
* `string& operator+=(const char c);`                     //����+=������
* `string& operator+=(const string& str);`                //����+=������
* `string& append(const char *s); `                       //���ַ���s���ӵ���ǰ�ַ�����β
* `string& append(const char *s, int n);`                 //���ַ���s��ǰn���ַ����ӵ���ǰ�ַ�����β
* `string& append(const string &s);`                      //ͬoperator+=(const string& str)
* `string& append(const string &s, int pos, int n);`      //�ַ���s�д�pos��ʼ��n���ַ����ӵ��ַ�����β
*/
void test06() {
	string str1 = "��";
	str1 += "������Ϸ";
	cout << " str1 = " << str1 << endl;

	str1 += ':';
	cout << " str1 = " << str1 << endl;

	string str2 = "DNF LOL";
	str1 += str2;
	cout << " str1 = " << str1 << endl;

	string str3 = "I";
	str3.append(" love ");
	cout << " str3 = " << str3 << endl;

	str3.append("game asdf", 4);
	cout << " str3 = " << str3 << endl;
	
	str3.append(str2, 0, 3); // DNF
	//str3.append(str2,4,3) // LOL
	//str3.append(str2); // DNF LOL
	cout << " str3 = " << str3 << endl;

}

// 2.1.5 string���Һ��滻

/*
* `int find(const string& str, int pos = 0) const;`              //����str��һ�γ���λ��,��pos��ʼ����
* `int find(const char* s, int pos = 0) const; `                     //����s��һ�γ���λ��,��pos��ʼ����
* `int find(const char* s, int pos, int n) const; `               //��posλ�ò���s��ǰn���ַ���һ��λ��
* `int find(const char c, int pos = 0) const; `                       //�����ַ�c��һ�γ���λ��
* `int rfind(const string& str, int pos = npos) const;`      //����str���һ��λ��,��pos��ʼ����
* `int rfind(const char* s, int pos = npos) const;`              //����s���һ�γ���λ��,��pos��ʼ����
* `int rfind(const char* s, int pos, int n) const;`              //��pos����s��ǰn���ַ����һ��λ��
* `int rfind(const char c, int pos = 0) const;  `                      //�����ַ�c���һ�γ���λ��
* `string& replace(int pos, int n, const string& str); `       //�滻��pos��ʼn���ַ�Ϊ�ַ���str
* `string& replace(int pos, int n,const char* s); `                 //�滻��pos��ʼ��n���ַ�Ϊ�ַ���s
*/


// 1)����
void test07() {
	// ����
	string str1 = "abcdefgde";
	int pos = str1.find("de");

	if (pos == -1) {
		cout << "δ�ҵ�" << endl;
	}
	else {
		cout << "pos = " << pos << endl;
	}
	
	pos = str1.rfind("de");
	cout << "pos = " << pos << endl;


	// 2)�滻
	str1.replace(1, 3, "1111");
	cout << "str1 = " << str1 << endl;


 }

// 2.1.6string �Ƚ�

// �ַ����Ƚ��ǰ��ַ���ASCII����жԱ�
// = ����   0
// > ����   1
// < ���� - 1

//*`int compare(const string& s) const; `  //���ַ���s�Ƚ�
//* `int compare(const char* s) const; `      //���ַ���s�Ƚ�

void test08() {
	string str1 = "xello";
	string str2 = "hello";
	if (str1.compare(str2) == 0) {
		cout << "str1 ���� str2" << endl;
	}
	else if (str1.compare(str2) > 0){
		cout << "str1 ���� str2" << endl;
	}
	else{
		cout << "str1 С�� str2" << endl;
	}

}

// 2.1.7string �ַ���ȡ

void test09() {
	string str = "hello";
	
	// 1) ͨ��[]�����ʵ����ַ� 
	for (int i = 0; i < str.size(); i++) {
		cout << str[i] << " ";
	}
	cout << endl;

	// 2) ͨ��at��ʽ���ʵ����ַ�
	for (int i = 0; i < str.size(); i++) {
		cout << str.at(i) << " ";
	}
	cout << endl;

	// �޸ĵ����ַ�
	str[0] = 'x'; // xello
	cout << "str = " << str << endl;
	str.at(1) = 'x';
	cout << "str = " << str << endl;

}

// 2.1.8 string �����ɾ��

/*
* `string& insert(int pos, const char* s);  `                //�����ַ���
* `string& insert(int pos, const string& str); `        //�����ַ���
* `string& insert(int pos, int n, char c);`                //��ָ��λ�ò���n���ַ�c
* `string& erase(int pos, int n = npos);`                    //ɾ����Pos��ʼ��n���ַ�
*/

void test10() {
	string str = "hello";
	// ����
	str.insert(1, "111");
	cout << "str = " << str << endl;
	
	// ɾ��
	str.erase(1, 3);
	cout << "str = " << str << endl;
}
// �ܽ�: �����ɾ������ʼ�±궼�Ǵ�0��ʼ

// 2.1.9 string ���Ӵ�

void test11() {
	string str = "abcdef";
	
	string subStr = str.substr(1, 3);

	cout << "subStr = " << subStr << endl;

	// ʵ��

	string email = "zhangsan@sina.com";

	// �ʼ���ַ�� ��ȡ �û���Ϣ
	int pos = email.find("@"); // 8

	string user = email.substr(0, pos);
	cout << user << endl;

}



//  3. vector����

// 3.1 vector��������  ������

//���ܣ�
//vector���ݽṹ������ǳ����ƣ�Ҳ��Ϊ��������
//
//vector����ͨ�������� 
//��֮ͬ�����������Ǿ�̬�ռ䣬��vector���Զ�̬��չ
//��̬��չ:
//��������ԭ�ռ�֮�������¿ռ䣬�����Ҹ�����ڴ�ռ䣬Ȼ��ԭ���ݿ����¿ռ䣬�ͷ�ԭ�ռ�

// 3.2 vector�������캯��
// 3.3 vector������ֵ

void printVector(vector<int>&v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

// vector��������
void test12() {
	vector <int>v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}

	printVector(v1);

	// ͨ�����䷽ʽ���й���
	vector<int> v2(v1.begin(), v1.end());
	printVector(v2);

	//n��elem��ʽ����
	vector<int>v3(10, 100);
	printVector(v3);

	//��������
	vector<int>v4(v3);
	printVector(v4);

	// ��ֵ operator=
	v2 = v3;
	printVector(v2);
	// ��ֵ assign
	v3.assign(v1.begin(), v1.end());
	printVector(v3);

	// n��elem��ʽ��ֵ
	v4.assign(10, 1);
	printVector(v4);
}

// 3.4 vector�����������ʹ�С����

void test13() {
	vector <int>v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}

	printVector(v1);

	if (v1.empty()) { // Ϊ�� ��������Ϊ��
		cout << "��" << endl;
	}
	else {
		cout << "����" << endl;
		cout << "v1������Ϊ: " << v1.capacity() << endl;
		cout << "v1�Ĵ�СΪ: " << v1.size() << endl;
	}
	
	// ����ָ����С
	//v1.resize(15); 
	v1.resize(15, 100); // �������ذ汾,����ָ����λ�õ����ֵ
	printVector(v1); // �������ָ���ı�ԭ������, Ĭ����0����µ�λ��

	v1.resize(5);
	printVector(v1); // �������ָ���ı�ԭ������, �������ֻ�ɾ����
}

// 3.5 vector �����ɾ��

//* push_back(ele);                                          //β������Ԫ��ele
//* pop_back();                                                 //ɾ�����һ��Ԫ��
//* insert(const_iterator pos, ele);         //������ָ��λ��pos����Ԫ��ele
//* insert(const_iterator pos, int count, ele); / / ������ָ��λ��pos����count��Ԫ��ele
//* erase(const_iterator pos);                      //ɾ��������ָ���Ԫ��
//* erase(const_iterator start, const_iterator end); / / ɾ����������start��end֮���Ԫ��
//* clear();       //ɾ������������Ԫ��

void test14() {
	vector<int> v1;
	
	// β��
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);

	// ����
	printVector(v1);

	// βɾ
	v1.pop_back();
	printVector(v1);

	//���� ��һ�������ǵ�����
	v1.insert(v1.begin(), 100);
	printVector(v1);
	
	v1.insert(v1.begin(), 2, 1000);
	printVector(v1);

	// ɾ�� ����Ҳ�ǵ�����
	v1.erase(v1.begin());
	printVector(v1);

	// ���
	//v1.erase(v1.begin(), v1.end());
	v1.clear();
	printVector(v1);

}

// 3.6 vector ���� ���ݴ�ȡ
// 3.7 vector ��������
void test15() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	
	// []��ȡ
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << " ";
	}
	cout << endl;

	// at���� ��ȡ
	for (int i = 0; i < v1.size(); i++) {
		cout << v1.at(i) << " ";
	}
	cout << endl;

	// ��ӡ��һ��Ԫ��
	cout << "��һ��Ԫ��Ϊ: " << v1.front() << endl;

	// ��ӡ���һ��Ԫ��
	cout << "���һ��Ԫ��Ϊ: " << v1.back() << endl;

	// ���������Ļ���ʹ��
	vector<int> v2;
	for (int i = 10; i > 0; i--) {
		v2.push_back(i);
	}
	cout << "����ǰ:" << endl;
	cout << "v1: ";
	printVector(v1);
	cout << "v2: ";
	printVector(v2);

	v1.swap(v2);
	cout << "������:" << endl;
	cout << "v1: ";
	printVector(v1);
	cout << "v2: ";
	printVector(v2);
}

// ����swap�������ռ�
void test15_1() {
	vector <int> v;
	for (int i = 0; i < 10000; i++) {
		v.push_back(i);
	}
	cout << "v������: " << v.capacity() << endl;
	cout << "v�Ĵ�С: " << v.size() << endl;

	v.resize(3);
	cout << "v������: " << v.capacity() << endl;
	cout << "v�Ĵ�С: " << v.size() << endl;

	vector<int>(v).swap(v);  // vector<int>(v) ��������(��ǰ��ִ�н����ᱻ�ͷſռ�)   .swap(v) ��������  ����֮
	cout << "v������: " << v.capacity() << endl;
	cout << "v�Ĵ�С: " << v.size() << endl;
}

// 3.8 vector Ԥ���ռ�
void test16() {
	vector<int>v;

	v.reserve(10000);
	int num = 0; // ͳ�ƿ��ٴ���
	int* p = NULL;
	for (int i = 0; i < 10000; i++) {
		v.push_back(i);
		if (p != &v[0]) {
			p = &v[0];
			num++;
		}
	}
	cout << num << endl;
}


// 4. deque����
// 4.1 �������� ������ 
// 4.2-4.7   deque���� ��ֵ ��С����(����������) �����ɾ�� ���ݴ�ȡ ����
void printDeque(const deque<int>& d) {  //����const ��Ϊֻ�� ���ܱ��޸�
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		//*it = 100; // ���ܱ��޸���
		cout << *it << " ";
	}
	cout << endl;
}

void test17() {
	// 4.2 ����
	deque<int>d1; //�޲ι���
	for (int i = 0; i < 10; i++) {
		d1.push_back(i);
	}
	printDeque(d1);

	deque<int>d2(d1.begin(), d1.end()); // ������
	printDeque(d2);

	deque<int>d3(10, 100); // 10��100
	printDeque(d3);

	deque<int>d4(d3); // ����
	printDeque(d4);

	cout << "4.3-----------------" << endl;

	// 4.3 ��ֵ
	// operator=
	d2 = d3;
	printDeque(d2);

	// assign ��ֵ
	d2.assign(d1.begin(), d1.end());
	printDeque(d2);

	d2.assign(10, 11);
	printDeque(d2);

	cout << "4.4-----------------" << endl;

	// 4.4 ������С����
	if (d1.empty()) {
		cout << "d1Ϊ��" << endl;
	}
	else {
		cout << "d1��Ϊ��" << endl;
		cout << "d1�Ĵ�СΪ: " << d1.size() << endl;
		// ����������
	}

	// ����ָ����С
	//d1.resize(15);  
	d1.resize(15, 1);
	printDeque(d1);

	d1.resize(5);
	printDeque(d1);
	cout << "4.5-----------------" << endl;

	// 4.5 deque �����ɾ��

	// ���˲���
	// β��
	d1.push_back(11);
	d1.push_back(22);
	printDeque(d1);

	// ͷ��
	d1.push_front(11);
	d1.push_front(22);
	printDeque(d1);

	// βɾ
	d1.pop_back();
	d1.pop_back();
	printDeque(d1);

	// ͷɾ
	d1.pop_front();
	d1.pop_front();
	printDeque(d1);

	// insert ����
	d1.insert(d1.begin(), 101);
	printDeque(d1);

	d1.insert(d1.begin(), 2, 22);
	printDeque(d1);

	// insert �������
	d1.insert(d1.begin(), d2.begin(), d2.end());
	printDeque(d1);

	// ɾ��
	deque<int>::iterator it = d1.begin();
	it++;
	d1.erase(it); // ɾ���ڶ���11
	printDeque(d1);
	// ����ɾ��
	d1.erase(d1.begin(), d1.end());
	// ���
	//d1.clear();
	printDeque(d1);

	cout << "4.6-----------------" << endl;

	// 4.6 deque ���ݴ�ȡ
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_front(100);
	d1.push_front(200);
	d1.push_front(300);

	// ͨ��[]��at��������
	for (int i = 0; i < d1.size(); i++) {
		//cout << d1[i] << " ";
		cout << d1.at(i) << " ";
	}
	cout << endl;

	cout << "��һ��Ԫ��: " << d1.front() << endl;
	cout << "���һ��Ԫ��: " << d1.back() << endl;
	
	cout << "4.7-----------------" << endl;
	
	// 4.7 deque ����
	// ����֧��������ʵĵ����������� ����������sort�㷨ֱ�Ӷ����������
	// vector����Ҳ֧��sort
	sort(d1.begin(), d1.end()); // Ĭ�ϴ�С��������
	cout << "�����: ";
	printDeque(d1);

}

// 5.��ί��ְ���

//��5��ѡ�֣�ѡ��ABCDE��10����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷֣�ȥ����ί����ͷ֣�ȡƽ���֡�

//ʵ�ֲ���
//1. ��������ѡ�֣��ŵ�vector��
//2. ����vector������ȡ����ÿһ��ѡ�֣�ִ��forѭ�������԰�10�����ִ�ִ浽deque������
//3. sort�㷨��deque�����з�������ȥ����ߺ���ͷ�
//4. deque��������һ�飬�ۼ��ܷ�
//5. ��ȡƽ����

class Person2 {
public:
	Person2(string name, int score) {
		this->m_Name = name;
		this->m_Score = score;
	}

	string m_Name; // ����
	int m_Score;  // ƽ����
};

void createPerson(vector<Person2>& v) {

	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++) {
		string name = "ѡ��";
		name += nameSeed[i];

		int score = 0;

		Person2 p(name, score);

		// ��������
		v.push_back(p);
	}
}

// ���
void setScore(vector<Person2>& v) {
	for (vector<Person2>::iterator it = v.begin(); it != v.end(); it++) {
		// ����ί�Ĵ�� ���뵽deque������
		deque<int>d;
		for (int i = 0; i < 10; i++) {
			int score = rand() % 41 + 60;  // 60 ~100
			d.push_back(score);
		}

		// �����������
		cout << "ѡ��: " << (*it).m_Name << "���:" << endl;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++) {
			cout << *dit << " ";
		}
		cout << endl;

		// ��������
		sort(d.begin(), d.end());

		// ȥ����߷� �� ��ͷ�
		d.pop_back();
		d.pop_front();

		// ����ƽ������ ����ֵ
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++) {
			sum += (*dit);
		}
		int avg = sum / d.size();

		it->m_Score = avg;

	}
}
// ��ʾ���շ���
void showScore(vector<Person2>&v) {
	for (vector<Person2>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "����: " << (*it).m_Name << "�÷�: " << it->m_Score << endl;
	}
}
void test18() {

	// ���������
	srand((unsigned int)time(NULL));

	// 1)����5��ѡ��
	vector<Person2>v; // ���ѡ������
	createPerson(v);

	//// ����
	//for (vector<Person2>::iterator it = v.begin(); it != v.end(); it++) {
	//	cout << "����: " << (*it).m_Name << "����: " << (*it).m_Score << endl; 
	//}

	// 2)��5��ѡ�ִ��
	setScore(v);

	// 3)��ʾ���÷�
	showScore(v);



}


// 6. stack����

// 6.1 ���� ������ (ջ��ֻ�ж��˵�Ԫ�زſ��Ա����ʹ�ã����ջ�������б�����Ϊ)

// 6.2 stack �����ӿ�
 
/*
���캯����
* `stack<T> stk;`                                 //stack����ģ����ʵ�֣� stack�����Ĭ�Ϲ�����ʽ
* `stack(const stack &stk);`            //�������캯��
��ֵ������
* `stack& operator=(const stack &stk);`           //���صȺŲ�����
���ݴ�ȡ��
* `push(elem);`      //��ջ�����Ԫ��
* `pop();`                //��ջ���Ƴ���һ��Ԫ��
* `top(); `                //����ջ��Ԫ��
��С������
* `empty();`            //�ж϶�ջ�Ƿ�Ϊ��
* `size(); `              //����ջ�Ĵ�С
*/

void test19() {
	// �Ƚ����
	stack<int> s;

	// ��ջ
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	cout << "ջ�Ĵ�С: " << s.size() << endl;
	// ֻҪջ��Ϊ�� �鿴ջ�� ��ִ�г�ջ����
	while (!s.empty()) {
		// �鿴ջ��Ԫ��
		cout << "ջ��: " << s.top() << endl;

		// ��ջ
		s.pop();

	}
	cout << "ջ�Ĵ�С: " << s.size() << endl;

}

// 7.queue����

// 7.1 ���� ������ (������ֻ�ж�ͷ�Ͷ�β�ſ��Ա����ʹ�ã���˶��в������б�����Ϊ)

// 7.2 queue�����ӿ�

void test20() {
	// ��������
	queue<Person> q;

	// ׼������
	Person p1("1", 10);
	Person p2("2", 20);
	Person p3("3", 30);
	Person p4("4", 40);

	// ���
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	cout << "q�Ĵ�СΪ: " << q.size() << endl;

	// �ж�ֻҪ���в�Ϊ�� �鿴��ͷ��β ����
	while (!q.empty()) {

		// �鿴��ͷ
		cout << "��ͷԪ��-����: " << q.front().m_Name << "����: " << q.front().m_Age << endl;

		// �鿴��β
		cout << "��βԪ��-����: " << q.back().m_Name << "����: " << q.back().m_Age << endl;

		q.pop();
	}

	cout << "q�Ĵ�СΪ: " << q.size() << endl;
}


// 8.��ʽ�洢

void printList(const list<int>& L) {
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

bool myCompare(int v1, int v2) {
	// ����  ���õ�һ����>�ڶ�����
	return v1 > v2;
}

// ������
class Person3 {
public:
	Person3(string name, int age, int height) {
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = height;
	}

	string m_Name; //����
	int m_Age;  //����
	int m_Height; // ���
};

// ָ���������
bool comparePerson3(Person3& p1, Person3& p2) {

	// ���������� ����
	if (p1.m_Age == p2.m_Age) {
		// ������ͬ ���������
		return p1.m_Height < p2.m_Height;
	}
	else {
		return p1.m_Age < p2.m_Age;
	}
}

void test21() {
	// 8.1 list�������� (˫��ѭ������) ������

	// 8.2 list���캯��
	



	cout << "-------8.2------" << endl;
	// 8.2.1 �޲ι���
	list<int> L1;

	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	// ��������
	printList(L1);

	// 8.2.2 ���䷽ʽ����
	list<int>L2(L1.begin(), L1.end());
	printList(L2);

	// ��������
	list<int>L3(L2);
	printList(L3);

	// 8.2.3  n��elem
	list<int>L4(10, 100);
	printList(L4);

	cout << "-------8.3------" << endl;
	// 8.3 ��ֵ�뽻��
	
	// 8.3.1 ��ֵ
	L2 = L4;// operator= ��ֵ
	printList(L2);
	L3.assign(L4.begin(), L4.end()); // ���丳ֵ 
	printList(L3);
	L3.assign(10, 1);  // n �� elem
	printList(L3);

	// 8.3.2 ����
	cout << "����ǰ: " << endl;
	printList(L1);
	printList(L2);

	L1.swap(L2);
	cout << "������: " << endl;
	printList(L1);
	printList(L2);

	// 8.4 List ������С����
	cout << "-------8.4------" << endl;

	// �ж��Ƿ�Ϊ��
	if (L1.empty()) {
		cout << "L1��" << endl;
	}
	else {
		cout << "L1����" << endl;
		cout << "L1Ԫ�ظ���: " << L1.size() << endl;
	}

	// ����ָ����С
	//L1.resize(10); // ����Ϊ10
	L1.resize(11, 1); // ����Ϊ11 �������Ϊ1;
	printList(L1);

	L1.resize(10);
	printList(L1);

	// 8.5 List ������ɾ��
	cout << "-------8.5------" << endl;
	/*
	* push_back(elem);//������β������һ��Ԫ��
	* pop_back();//ɾ�����������һ��Ԫ��
	* push_front(elem);//��������ͷ����һ��Ԫ��
	* pop_front();//��������ͷ�Ƴ���һ��Ԫ��
	* insert(pos,elem);//��posλ�ò�elemԪ�صĿ��������������ݵ�λ�á�
	* insert(pos,n,elem);//��posλ�ò���n��elem���ݣ��޷���ֵ��
	* insert(pos,beg,end);//��posλ�ò���[beg,end)��������ݣ��޷���ֵ��
	* clear();//�Ƴ���������������
	* erase(beg,end);//ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ�á�
	* erase(pos);//ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�
	* remove(elem);//ɾ��������������elemֵƥ���Ԫ�ء�
	*/

	L1.clear();
	
	//β��
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	//ͷ��
	L1.push_front(100);
	L1.push_front(200);
	L1.push_front(300);

	printList(L1);

	//βɾ
	L1.pop_back();
	printList(L1);

	//ͷɾ
	L1.pop_front();
	printList(L1);

	//����
	list<int>::iterator it = L1.begin();
	L1.insert(++it, 1000);
	printList(L1);

	//ɾ��
	it = L1.begin();
	L1.erase(++it);
	printList(L1);

	//�Ƴ�
	L1.push_back(10000);
	L1.push_back(10000);
	L1.push_back(10000);
	printList(L1);
	L1.remove(10000);
	printList(L1);

	// 8.6 list ���ݴ�ȡ
	cout << "-------8.6------" << endl;

	//L1[0]  // ��������[]����
	//L1.at(1) // at Ҳ����
	// ԭ����list��������, �������������Կռ�洢����, ������Ҳ�ǲ�֧��������ʵ�

	cout << "��һ��Ԫ��: " << L1.front() << endl;
	cout << "���һ��Ԫ��: " << L1.back() << endl;

	// ��֤�������ǲ�֧��������ʵ�
	// list<int>::iterator 
	it = L1.begin();

	//it = it + 1; // ���� ��֧���������
	it++; // ֧��˫��
	it--;

	// 8.7 list������ת������
	cout << "-------8.7------" << endl;

	// ��ת
	cout << "��תǰ:" << endl;
	printList(L1);

	L1.reverse();
	cout << "��ת��:" << endl;
	printList(L1);

	// ����
	cout << "����ǰ:" << endl;
	printList(L1);

	// ���в�֧��������ʵĵ�����������, �������ñ�׼�㷨
	//sort(L1.begin(), L1.end());
	// ��֧��������ʵĵ�����������, �ڲ����ṩ��Ӧ��һЩ�㷨
	L1.sort(); // Ĭ��������� ��С���� ����
	cout << "�����:" << endl;
	printList(L1);

	L1.sort(myCompare); // ����
	cout << "���������:" << endl;
	printList(L1);
	

	// 8.8 ������ �����Զ����������� ������
	cout << "-------8.8------" << endl;

	// ������������Person�Զ����������ͽ�������Person�����������������䡢���
	// ������򣺰�����������������������ͬ������߽��н���

	list<Person3> L;

	// ׼������
	Person3 p1("����", 35, 175);
	Person3 p2("�ܲ�", 45, 180);
	Person3 p3("��Ȩ", 40, 170);
	Person3 p4("����", 25, 190);
	Person3 p5("�ŷ�", 35, 160);
	Person3 p6("����", 35, 200);

	// ��������
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);

	for (list<Person3>::iterator it = L.begin(); it != L.end(); it++) {
		cout << "����: " << (*it).m_Name << " ����: " << it->m_Age << " ���: " << it->m_Height << endl;
 	}

	// ����
	cout << "�����:" << endl;
	L.sort(comparePerson3);
	for (list<Person3>::iterator it = L.begin(); it != L.end(); it++) {
		cout << "����: " << (*it).m_Name << " ����: " << it->m_Age << " ���: " << it->m_Height << endl;
	}
}




//  9. set/ multiset ����
void printSet(set<int>& s) {
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

class MyCompare {
public:
	bool operator()(int v1, int v2) const{
		return v1 > v2;
	}
};

class comparePerson {
public:
	bool operator()(const Person &p1,const Person &p2)const {
		// �����併��
		return p1.m_Age > p2.m_Age;
	}
};



void test22() {

	// 9.1 set/ multiset �������� ������

	/*
	���:
	����Ԫ�ض����ڲ���ʱ�Զ�������
	���ʣ�
	set/multiset���ڹ���ʽ�������ײ�ṹ���ö�����ʵ�֡�
	set��multiset����
	set���������������ظ���Ԫ��
	multiset�������������ظ���Ԫ��
	*/

	// 9.2 set��������͸�ֵ
	
	// Ĭ�Ϲ���
	set<int>s1;

	// �������� ֻ��insert��ʽ
	s1.insert(10);
	s1.insert(40);
	s1.insert(30);
	s1.insert(20);
	s1.insert(30);

	// ��������
	// set�����ص�: ����Ԫ�ز���ʱ���Զ�������
	// set��������������ظ�ֵ ���ᱨ�� Ҳ�������ɹ�
	printSet(s1);

	// ��������
	set<int>s2(s1);
	printSet(s2);

	// ��ֵ
	set<int>s3;
	s3 = s2;
	printSet(s3);
	

	cout << "-------9.3-------" << endl;
	// 9.3  set������С�뽻��
	
	// ��С
	if (s1.empty()) {
		cout << "s1 Ϊ�� " << endl;
	}
	else {
		cout << "s1��Ϊ��" << endl;
		cout << "s1��СΪ: " << s1.size() << endl;
	}

	// ����
	cout << " ����ǰ: " << endl;
	s3.insert(100);
	printSet(s1);
	printSet(s3);
	
	s1.swap(s3);
	cout << "������: " << endl;
	printSet(s1);
	printSet(s3);

	cout << "-------9.4-------" << endl;
	// 9.4 set�����ɾ��
	
	s1.insert(200);
	printSet(s1);
	// ɾ��
	s1.erase(s1.begin());
	printSet(s1);
	
	s1.erase(200); // ɾ��200
	printSet(s1);

	//s1.erase(s1.begin(), s1.end());
	s1.clear();
	printSet(s1);

	cout << "-------9.5-------" << endl;
	// 9.5 set������ͳ��
	// ����
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);

	set<int>::iterator  pos = s1.find(10);
	if (pos != s1.end()) {
		cout << "�ҵ�Ԫ��: " << *pos << endl;
	}
	else {
		cout << "δ�ҵ�Ԫ��" << endl;
	}

	// ͳ��
	// ͳ��30�ĸ���
	int num = s1.count(30);
	// ����set���� numֻ������0����1
	cout << "num = " << num << endl;


	// 9.6 set �� multiset ����
	cout << "-------9.6-------" << endl;

	set<int>s4;

	pair<set<int>::iterator, bool> ret = s4.insert(10);
	if (ret.second) {
		cout << "��һ�β���ɹ�" << endl;
	}
	else {
		cout << "��һ�β���ʧ��" << endl;
	}


	ret = s4.insert(10);
	if (ret.second) {
		cout << "�ڶ��β���ɹ�" << endl;
	}
	else {
		cout << "�ڶ��β���ʧ��" << endl;
	}

	multiset<int> ms;
	// ��������ظ�ֵ
	ms.insert(10);
	ms.insert(10);

	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	// 9.7 pair ���鴴��
	cout << "-------9.7-------" << endl;

	// ��һ�ַ�ʽ
	pair<string, int> p("Tom", 20);
	cout << "����: " << p.first << "����: " << p.second << endl;

	// �ڶ��ַ�ʽ
	pair<string, int> p2 = make_pair("Jeff", 10) ;
	cout << "����: " << p2.first << "����: " << p2.second << endl;

	// 9.8 set ������� ��С����
	cout << "-------9.8-------" << endl;
    
	// ָ���������Ϊ�Ӵ�С
	set<int,MyCompare> s5;

	s5.insert(10);
	s5.insert(30);
	s5.insert(20);
	s5.insert(40);
	s5.insert(60);

	for (set<int,MyCompare>::iterator it = s5.begin(); it != s5.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	// set�д���Զ�����������
	// �Զ�������� ����Ҫ�Զ�����������
	set<Person, comparePerson>s;

	// ����Person����
	Person p11("1", 24);
	Person p22("2", 22);
	Person p33("3", 32);
	Person p44("4", 12);
	Person p55("5", 23);

	s.insert(p11);
	s.insert(p22);
	s.insert(p33);
	s.insert(p44);
	s.insert(p55);

	for (set<Person, comparePerson>::iterator it = s.begin(); it != s.end(); it++) {
		cout << "������ " << it->m_Name << "���䣺 " << (*it).m_Age << endl;
	}
}


// 10. map/ multimap ����

void printMap(map<int, int>& m) {
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
		cout << "key = " << (*it).first << " value = " << it->second << endl;
	}
	cout << endl;
}


void test23() {
	// 10.1 map �������� ������

	// 10.2 map ����͸�ֵ

	map<int, int> m1; // Ĭ�Ϲ���
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	printMap(m1);
	
	map<int, int> m2(m1); // ��������
	printMap(m2);

	map<int, int> m3;
	m3 = m2; // ��ֵ
	printMap(m3);


	cout << "------10.3-------" << endl;
	// 10.3 map ��С�ͽ���

	if (m1.empty()) {
		cout << "m1Ϊ��" << endl;
	}
	else {
		cout << "m1��Ϊ��" << endl;
		cout << "m1�Ĵ�СΪ: " << m1.size() << endl;
	}
	
	m2.insert(pair<int, int>(12, 120));
	cout << "�Ի�ǰ:" << endl;
	printMap(m1);
	printMap(m2);
	m1.swap(m2);
	cout << "�Ի���: " << endl;
	printMap(m1);
	printMap(m2);
	
	// 10.4 map �����ɾ��
	
	// ����

	printMap(m3);
	m3.insert(pair<int, int>(10, 100));  //  ����Ԫ��
	printMap(m3);
	
	m3.erase(10); // ɾ��������ֵΪ10��Ԫ��
	printMap(m3);

	m3.erase(m3.begin()); // ɾ��pָ��λ�� ������һ��Ԫ�صĵ�����
	printMap(m3);

	//m3.erase(m3.begin(), m3.end()); // ɾ��ָ������Ԫ��
	m3.clear(); // ���
	printMap(m3);

	// 10.5 map ���Һ�ͳ��


	


	
}







int main() {

	//test01();
	//test02();
	//test02_1();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	//test08();
	//test09();
	//test10();
	//test11();
	//test12();
	//test13();
	//test14();
	//test15();
	//test15_1();
	//test16();
	//test17();
	//test18();
	//test19();
	//test20();
	//test21();
	//test22();
	test23();

	system("pause");
	return 0;
}