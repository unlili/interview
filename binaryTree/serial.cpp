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
using namespace std;     //滑水16行
Node * reconPreOrder(queue<char> q);


Node * reconByPreString(string preStr)
{
	queue<char> q;
	for (decltype(preStr.size()) i = 0; i < preStr.size(); ++i)
	{
		if (preStr[i] == '_')
		{
			continue;
		}
		q.push(preStr[i]);
	}
	return reconPreOrder(q);
}

Node * reconPreOrder(queue<char> q)
{
	char value = q.front();
	q.pop();
	Node * head = new Node(value -'0');
	head->left = reconPreOrder(q);
	head->right = reconPreOrder(q);

	return head;
}
