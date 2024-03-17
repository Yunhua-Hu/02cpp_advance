#include<iostream>
#include<string>
#include<vector>
#include<algorithm>  // 标准算法头文件
#include<deque>
#include<ctime> // 随机种子
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




// 初识STL这一节看讲义

//### 1.1 STL的诞生
// 长久以来，软件界一直希望建立一种可重复利用的东西
//
// C++的面向对象和泛型编程思想，目的就是复用性的提升
//
// 大多情况下，数据结构和算法都未能有一套标准, 导致被迫从事大量重复工作
//
// 为了建立数据结构和算法的一套标准, 诞生了STL

// 1.2-1.4 看讲义

//### 1.5 容器算法迭代器初识

//了解STL中容器、算法、迭代器概念之后，我们利用代码感受STL的魅力
//STL中最常用的容器为Vector，可以理解为数组，下面我们将学习如何向这个容器中插入数据、并遍历这个容器


// 1.5.1 vector存放内置数据类型

//容器：   vector
//算法：   for_each
//迭代器： vector<int > ::iterator

void myPrint(int val) {
	cout << val << endl;
}


void test01() {
	// 创建一个vector容器, 数组
	vector<int> v;
	// 向容器中插入数据
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	//// 通过迭代器访问容器中的数据
	//vector<int>::iterator itBegin = v.begin(); // 起始迭代器 指向容器中第一个元素
	//vector<int>::iterator itEnd = v.end(); // 结束迭代器 指向容器中最后一个元素的下一个位置

	//// 第一遍遍历
	//while (itBegin != itEnd) {
	//	cout << *itBegin << endl;
	//	itBegin++;
	//}

	//// 第二种遍历
	//for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
	//	cout << *it << endl;
	//}

	// 第三种遍历 利用STL提供的遍历算法
	for_each(v.begin(), v.end(), myPrint);
}

// 1.5.2 Vector容器中存放自定义数据类型
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

	//向容器中添加数据
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	// 遍历容器中的数据
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		//cout << "姓名: " << (*it).m_Name << " 年龄: " << (*it).m_Age << endl;
		cout << "姓名: " << it->m_Name << " 年龄: " << it->m_Age << endl;
	}
}

// 存放自定义数据类型 指针
void test02_1() { 
	vector<Person*> v;
	Person p1("1", 10);
	Person p2("2", 20);
	Person p3("3", 30);
	Person p4("4", 40);
	Person p5("5", 50);

	//向容器中添加数据
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	// 遍历容器中的数据
	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "test02_1  姓名: " << (*it)->m_Name << " 年龄: " << (*it)->m_Age << endl;
		
	}
}


// 1.5.3 Vector容器中嵌套容器
void test03() {
	vector< vector<int>>v;

	// 创建小容器
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;

	// 向小容器中添加数据
	for (int i = 0; i < 4; i++) {
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}

	// 将小容器放入大容器中
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);

	// 通过大容器 遍历数据
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++) {
		// (*it) ----- 就是一个容器
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++) {
			cout << *vit << " ";
		}
		cout << endl;
	}

}


// 2.1 string容器

// 2.1.1 string基本概念看讲义

// 2.1.2 string构造函数
//构造函数原型：
//
// string();               		 //创建一个空的字符串 例如: string str;
// string(const char* s); 	     //使用字符串s初始化
// string(const string& str);    //使用一个string对象初始化另一个string对象
// string(int n, char c);        //使用n个字符c初始化 

void test04() {
	string s1; // 默认构造

	const char* str = "hello world";
	string s2(str);

	cout << "s2 = " << s2 << endl;

	string s3(s2);
	cout << "s3 = " << s3 << endl;

	string s4(10, 'a');
	cout << "s4 = " << s4 << endl;


}

// 2.1.3 string 赋值操作

/*
string& operator=(const char* s);             //char*类型字符串 赋值给当前的字符串
string& operator=(const string &s);         //把字符串s赋给当前的字符串
string& operator=(char c);                          //字符赋值给当前的字符串
string& assign(const char *s);            //把字符串s赋给当前的字符串
string& assign(const char *s, int n);     //把字符串s的前n个字符赋给当前的字符串
string& assign(const string &s);              //把字符串s赋给当前字符串
string& assign(int n, char c);                  //用n个字符c赋给当前字符串
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

//2.1.4 string 字符串拼接

/*
* `string& operator+=(const char* str);`                  //重载+=操作符
* `string& operator+=(const char c);`                     //重载+=操作符
* `string& operator+=(const string& str);`                //重载+=操作符
* `string& append(const char *s); `                       //把字符串s连接到当前字符串结尾
* `string& append(const char *s, int n);`                 //把字符串s的前n个字符连接到当前字符串结尾
* `string& append(const string &s);`                      //同operator+=(const string& str)
* `string& append(const string &s, int pos, int n);`      //字符串s中从pos开始的n个字符连接到字符串结尾
*/
void test06() {
	string str1 = "我";
	str1 += "爱打游戏";
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

// 2.1.5 string查找和替换

/*
* `int find(const string& str, int pos = 0) const;`              //查找str第一次出现位置,从pos开始查找
* `int find(const char* s, int pos = 0) const; `                     //查找s第一次出现位置,从pos开始查找
* `int find(const char* s, int pos, int n) const; `               //从pos位置查找s的前n个字符第一次位置
* `int find(const char c, int pos = 0) const; `                       //查找字符c第一次出现位置
* `int rfind(const string& str, int pos = npos) const;`      //查找str最后一次位置,从pos开始查找
* `int rfind(const char* s, int pos = npos) const;`              //查找s最后一次出现位置,从pos开始查找
* `int rfind(const char* s, int pos, int n) const;`              //从pos查找s的前n个字符最后一次位置
* `int rfind(const char c, int pos = 0) const;  `                      //查找字符c最后一次出现位置
* `string& replace(int pos, int n, const string& str); `       //替换从pos开始n个字符为字符串str
* `string& replace(int pos, int n,const char* s); `                 //替换从pos开始的n个字符为字符串s
*/


// 1)查找
void test07() {
	// 查找
	string str1 = "abcdefgde";
	int pos = str1.find("de");

	if (pos == -1) {
		cout << "未找到" << endl;
	}
	else {
		cout << "pos = " << pos << endl;
	}
	
	pos = str1.rfind("de");
	cout << "pos = " << pos << endl;


	// 2)替换
	str1.replace(1, 3, "1111");
	cout << "str1 = " << str1 << endl;


 }

// 2.1.6string 比较

// 字符串比较是按字符的ASCII码进行对比
// = 返回   0
// > 返回   1
// < 返回 - 1

//*`int compare(const string& s) const; `  //与字符串s比较
//* `int compare(const char* s) const; `      //与字符串s比较

void test08() {
	string str1 = "xello";
	string str2 = "hello";
	if (str1.compare(str2) == 0) {
		cout << "str1 等于 str2" << endl;
	}
	else if (str1.compare(str2) > 0){
		cout << "str1 大于 str2" << endl;
	}
	else{
		cout << "str1 小于 str2" << endl;
	}

}

// 2.1.7string 字符存取

void test09() {
	string str = "hello";
	
	// 1) 通过[]来访问单个字符 
	for (int i = 0; i < str.size(); i++) {
		cout << str[i] << " ";
	}
	cout << endl;

	// 2) 通过at方式访问单个字符
	for (int i = 0; i < str.size(); i++) {
		cout << str.at(i) << " ";
	}
	cout << endl;

	// 修改单个字符
	str[0] = 'x'; // xello
	cout << "str = " << str << endl;
	str.at(1) = 'x';
	cout << "str = " << str << endl;

}

// 2.1.8 string 插入和删除

/*
* `string& insert(int pos, const char* s);  `                //插入字符串
* `string& insert(int pos, const string& str); `        //插入字符串
* `string& insert(int pos, int n, char c);`                //在指定位置插入n个字符c
* `string& erase(int pos, int n = npos);`                    //删除从Pos开始的n个字符
*/

void test10() {
	string str = "hello";
	// 插入
	str.insert(1, "111");
	cout << "str = " << str << endl;
	
	// 删除
	str.erase(1, 3);
	cout << "str = " << str << endl;
}
// 总结: 插入和删除的起始下标都是从0开始

// 2.1.9 string 求子串

void test11() {
	string str = "abcdef";
	
	string subStr = str.substr(1, 3);

	cout << "subStr = " << subStr << endl;

	// 实例

	string email = "zhangsan@sina.com";

	// 邮件地址中 获取 用户信息
	int pos = email.find("@"); // 8

	string user = email.substr(0, pos);
	cout << user << endl;

}



//  3. vector容器

// 3.1 vector基本概念  看讲义

//功能：
//vector数据结构和数组非常相似，也称为单端数组
//
//vector与普通数组区别： 
//不同之处在于数组是静态空间，而vector可以动态扩展
//动态扩展:
//并不是在原空间之后续接新空间，而是找更大的内存空间，然后将原数据拷贝新空间，释放原空间

// 3.2 vector容器构造函数
// 3.3 vector容器赋值

void printVector(vector<int>&v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

// vector容器构造
void test12() {
	vector <int>v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}

	printVector(v1);

	// 通过区间方式进行构造
	vector<int> v2(v1.begin(), v1.end());
	printVector(v2);

	//n个elem方式构造
	vector<int>v3(10, 100);
	printVector(v3);

	//拷贝构造
	vector<int>v4(v3);
	printVector(v4);

	// 赋值 operator=
	v2 = v3;
	printVector(v2);
	// 赋值 assign
	v3.assign(v1.begin(), v1.end());
	printVector(v3);

	// n个elem方式赋值
	v4.assign(10, 1);
	printVector(v4);
}

// 3.4 vector容器的容量和大小操作

void test13() {
	vector <int>v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}

	printVector(v1);

	if (v1.empty()) { // 为真 代表容器为空
		cout << "空" << endl;
	}
	else {
		cout << "不空" << endl;
		cout << "v1的容量为: " << v1.capacity() << endl;
		cout << "v1的大小为: " << v1.size() << endl;
	}
	
	// 重新指定大小
	//v1.resize(15); 
	v1.resize(15, 100); // 利用重载版本,可以指定新位置的填充值
	printVector(v1); // 如果重新指定的比原来长了, 默认用0填充新的位置

	v1.resize(5);
	printVector(v1); // 如果重新指定的比原来短了, 超出部分会删除掉
}

// 3.5 vector 插入和删除

//* push_back(ele);                                          //尾部插入元素ele
//* pop_back();                                                 //删除最后一个元素
//* insert(const_iterator pos, ele);         //迭代器指向位置pos插入元素ele
//* insert(const_iterator pos, int count, ele); / / 迭代器指向位置pos插入count个元素ele
//* erase(const_iterator pos);                      //删除迭代器指向的元素
//* erase(const_iterator start, const_iterator end); / / 删除迭代器从start到end之间的元素
//* clear();       //删除容器中所有元素

void test14() {
	vector<int> v1;
	
	// 尾插
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);

	// 遍历
	printVector(v1);

	// 尾删
	v1.pop_back();
	printVector(v1);

	//插入 第一个参数是迭代器
	v1.insert(v1.begin(), 100);
	printVector(v1);
	
	v1.insert(v1.begin(), 2, 1000);
	printVector(v1);

	// 删除 参数也是迭代器
	v1.erase(v1.begin());
	printVector(v1);

	// 清空
	//v1.erase(v1.begin(), v1.end());
	v1.clear();
	printVector(v1);

}

// 3.6 vector 容器 数据存取
// 3.7 vector 容器互换
void test15() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	
	// []存取
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << " ";
	}
	cout << endl;

	// at函数 存取
	for (int i = 0; i < v1.size(); i++) {
		cout << v1.at(i) << " ";
	}
	cout << endl;

	// 打印第一个元素
	cout << "第一个元素为: " << v1.front() << endl;

	// 打印最后一个元素
	cout << "最后一个元素为: " << v1.back() << endl;

	// 容器互换的基本使用
	vector<int> v2;
	for (int i = 10; i > 0; i--) {
		v2.push_back(i);
	}
	cout << "互换前:" << endl;
	cout << "v1: ";
	printVector(v1);
	cout << "v2: ";
	printVector(v2);

	v1.swap(v2);
	cout << "互换后:" << endl;
	cout << "v1: ";
	printVector(v1);
	cout << "v2: ";
	printVector(v2);
}

// 巧用swap来收缩空间
void test15_1() {
	vector <int> v;
	for (int i = 0; i < 10000; i++) {
		v.push_back(i);
	}
	cout << "v的容量: " << v.capacity() << endl;
	cout << "v的大小: " << v.size() << endl;

	v.resize(3);
	cout << "v的容量: " << v.capacity() << endl;
	cout << "v的大小: " << v.size() << endl;

	vector<int>(v).swap(v);  // vector<int>(v) 匿名对象(当前行执行结束会被释放空间)   .swap(v) 容器交换  交换之
	cout << "v的容量: " << v.capacity() << endl;
	cout << "v的大小: " << v.size() << endl;
}

// 3.8 vector 预留空间
void test16() {
	vector<int>v;

	v.reserve(10000);
	int num = 0; // 统计开辟次数
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


// 4. deque容器
// 4.1 基本概念 看讲义 
// 4.2-4.7   deque构造 赋值 大小操作(无容量概念) 插入和删除 数据存取 排序
void printDeque(const deque<int>& d) {  //加了const 变为只读 不能被修改
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		//*it = 100; // 不能被修改了
		cout << *it << " ";
	}
	cout << endl;
}

void test17() {
	// 4.2 构造
	deque<int>d1; //无参构造
	for (int i = 0; i < 10; i++) {
		d1.push_back(i);
	}
	printDeque(d1);

	deque<int>d2(d1.begin(), d1.end()); // 迭代器
	printDeque(d2);

	deque<int>d3(10, 100); // 10个100
	printDeque(d3);

	deque<int>d4(d3); // 拷贝
	printDeque(d4);

	cout << "4.3-----------------" << endl;

	// 4.3 赋值
	// operator=
	d2 = d3;
	printDeque(d2);

	// assign 赋值
	d2.assign(d1.begin(), d1.end());
	printDeque(d2);

	d2.assign(10, 11);
	printDeque(d2);

	cout << "4.4-----------------" << endl;

	// 4.4 容器大小操作
	if (d1.empty()) {
		cout << "d1为空" << endl;
	}
	else {
		cout << "d1不为空" << endl;
		cout << "d1的大小为: " << d1.size() << endl;
		// 无容量概念
	}

	// 重新指定大小
	//d1.resize(15);  
	d1.resize(15, 1);
	printDeque(d1);

	d1.resize(5);
	printDeque(d1);
	cout << "4.5-----------------" << endl;

	// 4.5 deque 插入和删除

	// 两端操作
	// 尾插
	d1.push_back(11);
	d1.push_back(22);
	printDeque(d1);

	// 头插
	d1.push_front(11);
	d1.push_front(22);
	printDeque(d1);

	// 尾删
	d1.pop_back();
	d1.pop_back();
	printDeque(d1);

	// 头删
	d1.pop_front();
	d1.pop_front();
	printDeque(d1);

	// insert 插入
	d1.insert(d1.begin(), 101);
	printDeque(d1);

	d1.insert(d1.begin(), 2, 22);
	printDeque(d1);

	// insert 区间插入
	d1.insert(d1.begin(), d2.begin(), d2.end());
	printDeque(d1);

	// 删除
	deque<int>::iterator it = d1.begin();
	it++;
	d1.erase(it); // 删除第二个11
	printDeque(d1);
	// 区间删除
	d1.erase(d1.begin(), d1.end());
	// 清空
	//d1.clear();
	printDeque(d1);

	cout << "4.6-----------------" << endl;

	// 4.6 deque 数据存取
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_front(100);
	d1.push_front(200);
	d1.push_front(300);

	// 通过[]或at访问数据
	for (int i = 0; i < d1.size(); i++) {
		//cout << d1[i] << " ";
		cout << d1.at(i) << " ";
	}
	cout << endl;

	cout << "第一个元素: " << d1.front() << endl;
	cout << "最后一个元素: " << d1.back() << endl;
	
	cout << "4.7-----------------" << endl;
	
	// 4.7 deque 排序
	// 对于支持随机访问的迭代器的容器 都可以利用sort算法直接对其进行排序
	// vector容器也支持sort
	sort(d1.begin(), d1.end()); // 默认从小到大排序
	cout << "排序后: ";
	printDeque(d1);

}

// 5.评委打分案例

//有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。

//实现步骤
//1. 创建五名选手，放到vector中
//2. 遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
//3. sort算法对deque容器中分数排序，去除最高和最低分
//4. deque容器遍历一遍，累加总分
//5. 获取平均分

class Person2 {
public:
	Person2(string name, int score) {
		this->m_Name = name;
		this->m_Score = score;
	}

	string m_Name; // 姓名
	int m_Score;  // 平均分
};

void createPerson(vector<Person2>& v) {

	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++) {
		string name = "选手";
		name += nameSeed[i];

		int score = 0;

		Person2 p(name, score);

		// 放入容器
		v.push_back(p);
	}
}

// 打分
void setScore(vector<Person2>& v) {
	for (vector<Person2>::iterator it = v.begin(); it != v.end(); it++) {
		// 将评委的打分 放入到deque容器中
		deque<int>d;
		for (int i = 0; i < 10; i++) {
			int score = rand() % 41 + 60;  // 60 ~100
			d.push_back(score);
		}

		// 分数输出测试
		cout << "选手: " << (*it).m_Name << "打分:" << endl;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++) {
			cout << *dit << " ";
		}
		cout << endl;

		// 分数排序
		sort(d.begin(), d.end());

		// 去除最高分 和 最低分
		d.pop_back();
		d.pop_front();

		// 计算平均分数 并赋值
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++) {
			sum += (*dit);
		}
		int avg = sum / d.size();

		it->m_Score = avg;

	}
}
// 显示最终分数
void showScore(vector<Person2>&v) {
	for (vector<Person2>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "姓名: " << (*it).m_Name << "得分: " << it->m_Score << endl;
	}
}
void test18() {

	// 随机数种子
	srand((unsigned int)time(NULL));

	// 1)创建5名选手
	vector<Person2>v; // 存放选手容器
	createPerson(v);

	//// 测试
	//for (vector<Person2>::iterator it = v.begin(); it != v.end(); it++) {
	//	cout << "姓名: " << (*it).m_Name << "分数: " << (*it).m_Score << endl; 
	//}

	// 2)给5名选手打分
	setScore(v);

	// 3)显示最后得分
	showScore(v);



}


// 6. stack容器

// 6.1 概念 看讲义 (栈中只有顶端的元素才可以被外界使用，因此栈不允许有遍历行为)

// 6.2 stack 容器接口
 
/*
构造函数：
* `stack<T> stk;`                                 //stack采用模板类实现， stack对象的默认构造形式
* `stack(const stack &stk);`            //拷贝构造函数
赋值操作：
* `stack& operator=(const stack &stk);`           //重载等号操作符
数据存取：
* `push(elem);`      //向栈顶添加元素
* `pop();`                //从栈顶移除第一个元素
* `top(); `                //返回栈顶元素
大小操作：
* `empty();`            //判断堆栈是否为空
* `size(); `              //返回栈的大小
*/

void test19() {
	// 先进后出
	stack<int> s;

	// 入栈
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	cout << "栈的大小: " << s.size() << endl;
	// 只要栈不为空 查看栈顶 并执行出栈操作
	while (!s.empty()) {
		// 查看栈顶元素
		cout << "栈顶: " << s.top() << endl;

		// 出栈
		s.pop();

	}
	cout << "栈的大小: " << s.size() << endl;

}

// 7.queue容器

// 7.1 概念 看讲义 (队列中只有队头和队尾才可以被外界使用，因此队列不允许有遍历行为)

// 7.2 queue容器接口

void test20() {
	// 创建队列
	queue<Person> q;

	// 准备数据
	Person p1("1", 10);
	Person p2("2", 20);
	Person p3("3", 30);
	Person p4("4", 40);

	// 入队
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	cout << "q的大小为: " << q.size() << endl;

	// 判断只要队列不为空 查看队头队尾 出队
	while (!q.empty()) {

		// 查看队头
		cout << "队头元素-姓名: " << q.front().m_Name << "年龄: " << q.front().m_Age << endl;

		// 查看队尾
		cout << "队尾元素-姓名: " << q.back().m_Name << "年龄: " << q.back().m_Age << endl;

		q.pop();
	}

	cout << "q的大小为: " << q.size() << endl;
}


// 8.链式存储

void printList(const list<int>& L) {
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

bool myCompare(int v1, int v2) {
	// 降序  就让第一个数>第二个数
	return v1 > v2;
}

// 排序案例
class Person3 {
public:
	Person3(string name, int age, int height) {
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = height;
	}

	string m_Name; //姓名
	int m_Age;  //年龄
	int m_Height; // 身高
};

// 指定排序规则
bool comparePerson3(Person3& p1, Person3& p2) {

	// 按年龄排序 升序
	if (p1.m_Age == p2.m_Age) {
		// 年龄相同 按身高排序
		return p1.m_Height < p2.m_Height;
	}
	else {
		return p1.m_Age < p2.m_Age;
	}
}

void test21() {
	// 8.1 list基本概念 (双向循环链表) 看讲义

	// 8.2 list构造函数
	



	cout << "-------8.2------" << endl;
	// 8.2.1 无参构造
	list<int> L1;

	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	// 遍历容器
	printList(L1);

	// 8.2.2 区间方式构造
	list<int>L2(L1.begin(), L1.end());
	printList(L2);

	// 拷贝构造
	list<int>L3(L2);
	printList(L3);

	// 8.2.3  n个elem
	list<int>L4(10, 100);
	printList(L4);

	cout << "-------8.3------" << endl;
	// 8.3 赋值与交换
	
	// 8.3.1 赋值
	L2 = L4;// operator= 赋值
	printList(L2);
	L3.assign(L4.begin(), L4.end()); // 区间赋值 
	printList(L3);
	L3.assign(10, 1);  // n 个 elem
	printList(L3);

	// 8.3.2 交换
	cout << "交换前: " << endl;
	printList(L1);
	printList(L2);

	L1.swap(L2);
	cout << "交换后: " << endl;
	printList(L1);
	printList(L2);

	// 8.4 List 容器大小操作
	cout << "-------8.4------" << endl;

	// 判断是否为空
	if (L1.empty()) {
		cout << "L1空" << endl;
	}
	else {
		cout << "L1不空" << endl;
		cout << "L1元素个数: " << L1.size() << endl;
	}

	// 重新指定大小
	//L1.resize(10); // 长度为10
	L1.resize(11, 1); // 长度为11 填充数字为1;
	printList(L1);

	L1.resize(10);
	printList(L1);

	// 8.5 List 插入与删除
	cout << "-------8.5------" << endl;
	/*
	* push_back(elem);//在容器尾部加入一个元素
	* pop_back();//删除容器中最后一个元素
	* push_front(elem);//在容器开头插入一个元素
	* pop_front();//从容器开头移除第一个元素
	* insert(pos,elem);//在pos位置插elem元素的拷贝，返回新数据的位置。
	* insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
	* insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。
	* clear();//移除容器的所有数据
	* erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
	* erase(pos);//删除pos位置的数据，返回下一个数据的位置。
	* remove(elem);//删除容器中所有与elem值匹配的元素。
	*/

	L1.clear();
	
	//尾插
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	//头插
	L1.push_front(100);
	L1.push_front(200);
	L1.push_front(300);

	printList(L1);

	//尾删
	L1.pop_back();
	printList(L1);

	//头删
	L1.pop_front();
	printList(L1);

	//插入
	list<int>::iterator it = L1.begin();
	L1.insert(++it, 1000);
	printList(L1);

	//删除
	it = L1.begin();
	L1.erase(++it);
	printList(L1);

	//移除
	L1.push_back(10000);
	L1.push_back(10000);
	L1.push_back(10000);
	printList(L1);
	L1.remove(10000);
	printList(L1);

	// 8.6 list 数据存取
	cout << "-------8.6------" << endl;

	//L1[0]  // 不可以用[]访问
	//L1.at(1) // at 也不行
	// 原因是list本质链表, 不是用连续线性空间存储数据, 迭代器也是不支持随机访问的

	cout << "第一个元素: " << L1.front() << endl;
	cout << "最后一个元素: " << L1.back() << endl;

	// 验证迭代器是不支持随机访问的
	// list<int>::iterator 
	it = L1.begin();

	//it = it + 1; // 错误 不支持随机访问
	it++; // 支持双向
	it--;

	// 8.7 list容器反转和排序
	cout << "-------8.7------" << endl;

	// 反转
	cout << "反转前:" << endl;
	printList(L1);

	L1.reverse();
	cout << "反转后:" << endl;
	printList(L1);

	// 排序
	cout << "排序前:" << endl;
	printList(L1);

	// 所有不支持随机访问的迭代器的容器, 不可以用标准算法
	//sort(L1.begin(), L1.end());
	// 不支持随机访问的迭代器的容器, 内部会提供对应的一些算法
	L1.sort(); // 默认排序规则 从小到大 升序
	cout << "排序后:" << endl;
	printList(L1);

	L1.sort(myCompare); // 降序
	cout << "降序排序后:" << endl;
	printList(L1);
	

	// 8.8 排序案例 对于自定义数据类型 做排序
	cout << "-------8.8------" << endl;

	// 案例描述：将Person自定义数据类型进行排序，Person中属性有姓名、年龄、身高
	// 排序规则：按照年龄进行升序，如果年龄相同按照身高进行降序

	list<Person3> L;

	// 准备数据
	Person3 p1("刘备", 35, 175);
	Person3 p2("曹操", 45, 180);
	Person3 p3("孙权", 40, 170);
	Person3 p4("赵云", 25, 190);
	Person3 p5("张飞", 35, 160);
	Person3 p6("关羽", 35, 200);

	// 插入数据
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);

	for (list<Person3>::iterator it = L.begin(); it != L.end(); it++) {
		cout << "姓名: " << (*it).m_Name << " 年龄: " << it->m_Age << " 身高: " << it->m_Height << endl;
 	}

	// 排序
	cout << "排序后:" << endl;
	L.sort(comparePerson3);
	for (list<Person3>::iterator it = L.begin(); it != L.end(); it++) {
		cout << "姓名: " << (*it).m_Name << " 年龄: " << it->m_Age << " 身高: " << it->m_Height << endl;
	}
}




//  9. set/ multiset 容器
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
		// 按年龄降序
		return p1.m_Age > p2.m_Age;
	}
};



void test22() {

	// 9.1 set/ multiset 基本概念 看讲义

	/*
	简介:
	所有元素都会在插入时自动被排序
	本质：
	set/multiset属于关联式容器，底层结构是用二叉树实现。
	set和multiset区别：
	set不允许容器中有重复的元素
	multiset允许容器中有重复的元素
	*/

	// 9.2 set容器构造和赋值
	
	// 默认构造
	set<int>s1;

	// 插入数据 只有insert方式
	s1.insert(10);
	s1.insert(40);
	s1.insert(30);
	s1.insert(20);
	s1.insert(30);

	// 遍历容器
	// set容器特点: 所有元素插入时候自动被排序
	// set容器不允许插入重复值 不会报错 也不会插入成功
	printSet(s1);

	// 拷贝构造
	set<int>s2(s1);
	printSet(s2);

	// 赋值
	set<int>s3;
	s3 = s2;
	printSet(s3);
	

	cout << "-------9.3-------" << endl;
	// 9.3  set容器大小与交换
	
	// 大小
	if (s1.empty()) {
		cout << "s1 为空 " << endl;
	}
	else {
		cout << "s1不为空" << endl;
		cout << "s1大小为: " << s1.size() << endl;
	}

	// 交换
	cout << " 交换前: " << endl;
	s3.insert(100);
	printSet(s1);
	printSet(s3);
	
	s1.swap(s3);
	cout << "交换后: " << endl;
	printSet(s1);
	printSet(s3);

	cout << "-------9.4-------" << endl;
	// 9.4 set插入和删除
	
	s1.insert(200);
	printSet(s1);
	// 删除
	s1.erase(s1.begin());
	printSet(s1);
	
	s1.erase(200); // 删除200
	printSet(s1);

	//s1.erase(s1.begin(), s1.end());
	s1.clear();
	printSet(s1);

	cout << "-------9.5-------" << endl;
	// 9.5 set查找与统计
	// 查找
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);

	set<int>::iterator  pos = s1.find(10);
	if (pos != s1.end()) {
		cout << "找到元素: " << *pos << endl;
	}
	else {
		cout << "未找到元素" << endl;
	}

	// 统计
	// 统计30的个数
	int num = s1.count(30);
	// 对于set而言 num只可能是0或者1
	cout << "num = " << num << endl;


	// 9.6 set 与 multiset 区别
	cout << "-------9.6-------" << endl;

	set<int>s4;

	pair<set<int>::iterator, bool> ret = s4.insert(10);
	if (ret.second) {
		cout << "第一次插入成功" << endl;
	}
	else {
		cout << "第一次插入失败" << endl;
	}


	ret = s4.insert(10);
	if (ret.second) {
		cout << "第二次插入成功" << endl;
	}
	else {
		cout << "第二次插入失败" << endl;
	}

	multiset<int> ms;
	// 允许插入重复值
	ms.insert(10);
	ms.insert(10);

	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	// 9.7 pair 队组创建
	cout << "-------9.7-------" << endl;

	// 第一种方式
	pair<string, int> p("Tom", 20);
	cout << "姓名: " << p.first << "年龄: " << p.second << endl;

	// 第二种方式
	pair<string, int> p2 = make_pair("Jeff", 10) ;
	cout << "姓名: " << p2.first << "年龄: " << p2.second << endl;

	// 9.8 set 排序规则 从小到大
	cout << "-------9.8-------" << endl;
    
	// 指定排序规则为从大到小
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

	// set中存放自定义数据类型
	// 自定义的数据 都需要自定义好排序规则
	set<Person, comparePerson>s;

	// 创建Person对象
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
		cout << "姓名： " << it->m_Name << "年龄： " << (*it).m_Age << endl;
	}
}


// 10. map/ multimap 容器

void printMap(map<int, int>& m) {
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
		cout << "key = " << (*it).first << " value = " << it->second << endl;
	}
	cout << endl;
}


void test23() {
	// 10.1 map 基本概念 看讲义

	// 10.2 map 构造和赋值

	map<int, int> m1; // 默认构造
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	printMap(m1);
	
	map<int, int> m2(m1); // 拷贝构造
	printMap(m2);

	map<int, int> m3;
	m3 = m2; // 赋值
	printMap(m3);


	cout << "------10.3-------" << endl;
	// 10.3 map 大小和交换

	if (m1.empty()) {
		cout << "m1为空" << endl;
	}
	else {
		cout << "m1不为空" << endl;
		cout << "m1的大小为: " << m1.size() << endl;
	}
	
	m2.insert(pair<int, int>(12, 120));
	cout << "对换前:" << endl;
	printMap(m1);
	printMap(m2);
	m1.swap(m2);
	cout << "对换后: " << endl;
	printMap(m1);
	printMap(m2);
	
	// 10.4 map 插入和删除
	
	// 插入

	printMap(m3);
	m3.insert(pair<int, int>(10, 100));  //  插入元素
	printMap(m3);
	
	m3.erase(10); // 删除容器中值为10的元素
	printMap(m3);

	m3.erase(m3.begin()); // 删除p指定位置 返回下一个元素的迭代器
	printMap(m3);

	//m3.erase(m3.begin(), m3.end()); // 删除指定区间元素
	m3.clear(); // 清空
	printMap(m3);

	// 10.5 map 查找和统计


	


	
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