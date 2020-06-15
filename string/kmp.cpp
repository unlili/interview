#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<cstdio>
#include<queue>
#include<map>
#include<queue>
#include<algorithm> 
#include<regex>          // 正则
#include<unordered_map>  // ===> hash_map
#include<random>         //假随机引擎
#include<ctime>          //ctime
#include<functional>     //二元谓词  真牛逼累   2333
#include<memory>         //智能指针
using namespace std;
string reconPreOrder(queue<char> q);
vector<int> getNextArray(string str2);
vector<int> getNextArray(char * b, int b_num);
int kmp(string str1, string str2);
int kmp(char * a, char *b, int a_num, int b_num);

struct Node
{
	int data;
	Node(int a):data(a){}
	Node * right;
	Node * left;
	Node * parent;
};

int kmp(string str1, string str2)
{
	if (str1.empty() || str2.empty()) return -1;
	decltype(str2.size()) p1 = 0;//指向str1
	decltype(str2.size()) p2 = 0;//指向str2
	vector<int> next = getNextArray(str2);

	while (p1 < str1.size() && p2 < str2.size())
	{
		if (str1[p1] == str2[p2])
		{
			++p1;
			++p2;
		}
		else if(next[p2]==-1)
		{
			++p1;
		}
		else
		{
			p2 = next[p2];
		}
	}

	return p2 == str2.size() ? p1 - p2 : -1;
}
int kmp(char * a, char *b,int a_num,int b_num)
{
	if (a_num <= 0 || b_num <= 0) return -1;
	int p1 = 0;
	int p2 = 0;
	vector<int> next = getNextArray(b,b_num);
	while (p1 < a_num && p2 < b_num)
	{
		if (a[p1] == b[p2])
		{
			++p1; ++p2;
		}
		 else if(next[p2] == -1)
		{
			++p1;
		}
		 else
		 {
			 p2 = next[p2];
		 }
	}
	return (p2 == b_num) ? p1 - p2 : -1;
}
vector<int> getNextArray(string str2)
{
	vector<int> next = {-1,0};
	next.resize(str2.size());
	decltype(str2.size()) p = 2; //求解位置
	int cn = 0;//跳到的位置

	while (p<str2.size())
	{
		if (str2[p - 1] == str2[cn])
		{
			next[p++] = ++cn;
		}
		else if (cn > 0)
		{
			cn = next[cn];
		}else
		{
			next[p++] = 0;
		}
	}
	return next;
}
vector<int> getNextArray(char * b,int b_num)
{
	vector<int> next = { -1,0 };
	int p = 2;
	int cn = 0;
	while (p < b_num)
	{
		if (b[p - 1] == b[cn])//相等的情况下
		{
			next[p++] = ++cn;
		}
		else if(cn > 0)//不相等的情况下,且cn存在
		{
			cn = next[cn];
		}
		else//不相等的情况下,且cn不存在,该位置最长前缀和最长后缀的匹配长度就为0
		{
			next[p++] = 0;
		}

	}
	return next;

}

/*
把一个字符串变成一个大字符串,要求大字符串中有俩个原字符串.

abcabc ===> abcabcabc
aaaa ===> aaaaa
a ===> aa
bbb ===> bbbb
*/
string q1(string s)
{
	s += " ";
	vector<int> v = getNextArray(s);
	int a = v[v.size() - 1];
	s.erase(s.end() - 1);//移除空格
	string w = "";
	for (size_t i = 0; i < (s.size() - a); ++i)
		w += s.at(i);
	return s += w;
}

/*
判断一颗二叉树是否为另一颗二叉树的子树
二叉树序列化--> kmp
*/
string serialByPre(Node * head)
{
	if (!head) return "#_";
	string res = to_string(head->data) + "_";
	res += serialByPre(head->left);
	res += serialByPre(head->right);
	return res;
}


bool isSon(Node * fa, Node * sun)
{
	string fa_str = serialByPre(fa);
	string sun_str = serialByPre(sun);
	return kmp(fa_str, sun_str) != -1;
}
