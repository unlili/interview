Node * getSuccessorNode(Node * n)
{
	if (n->right)
	{
		//获得该子树最左的节点
		while (n->left)
		{
			n = n->left;
		}
		return n;
	}
	else
	{
		while (n->parent == (n->parent)->right)
		{
			if (!n->parent) return nullptr;
			n = n->parent;
		}
		return n->parent;
		////第二种写法
		//Node * parent = n->parent;
		//while(parent && parent->left != n)
		//{
		//	n = parent;
		//	parent = n->parent;
		//}
		//return n->parent;
	}
}
