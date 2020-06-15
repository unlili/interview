//先序遍历（非递归） 根左右
void preOrderUnRecur(Node * head)
{
	if (head)
	{
		stack<Node *> stack;
		stack.push(head);//压入头结点
		while (!stack.empty())
		{
			head = stack.top();
			stack.pop();
			cout << head->data << " ";
			if (head->right)
			{
				stack.push(head->right);
			}
			if (head->left)
			{
				stack.push(head->left);
			}
		}
	}
}

//中序遍历（非递归） 左根右
void inOrderUnRecur(Node * head)
{
	if (head)
	{
		stack<Node *> stack;
		while (!stack.empty() || head)
		{
			if (head)
			{
				stack.push(head);
				head = head->left;
			}
			else
			{
				head = stack.top();
				stack.pop();
				cout << head->data << " ";
				head = head->right;
			}
		}
	}
}

//后序遍历（非递归） 左右根
void postOrderUnRecur(Node * head)
{
	std::stack<Node *> stack;
	std::stack<int> s2;
	if (head)
	{//根 右 左 压栈--> 左 右 根
		stack.push(head);//压入头结点
		while (!stack.empty())
		{
			head = stack.top();
			stack.pop();
			s2.push(head->data);
			if (head->left)
			{
				stack.push(head->left);
			}
			if (head->right)
			{
				stack.push(head->right);
			}
		}
	}
	while (!s2.empty())
	{
		cout << s2.top() << " ";
		s2.pop();
	}
}

