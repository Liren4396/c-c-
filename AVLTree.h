#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <assert.h>
#include <cstdlib>


using namespace std;

template <class k, class v>
struct AVLTreeNode {
	pair<k, v> _kv;
	AVLTreeNode<k, v>* _left;
	AVLTreeNode<k, v>* _right;
	AVLTreeNode<k, v>* _parent;

	int _bf;

	AVLTreeNode(const pair<k, v>& kv)
		:_kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
	{}
};
template <class k, class v>
class AVLTree {
	typedef AVLTreeNode<k, v> Node;
public:

	void levelOrder(Node* root) {
		if (root == nullptr) {
			return ;
		}
		queue<Node*> my_queue;

		my_queue.push(root);
		//cout << root->_kv.first << endl;

		while (!my_queue.empty()) {
			int level_size = my_queue.size();
			for (int i = 0; i < level_size; ++i) {
				Node* cur = my_queue.front();
				my_queue.pop();
				cout << cur->_kv.first << " ";
				if (cur->_left != nullptr) {
					my_queue.push(cur->_left);
				}
				if (cur->_right != nullptr) {
					my_queue.push(cur->_right);
				}
			}
			cout << endl;
		}
	}
	Node* get_root() {
		return _root;
	}

	void Rotate_right(Node* cur) {
		Node* grandparent = cur->_parent;
		Node* sub_left = cur->_left;
		Node* sub_left_right = sub_left->_right;
		sub_left->_right = cur;
		
		cur->_bf = 0;

		if (cur == _root) {
			_root = sub_left;

		}
		
		sub_left->_parent = cur->_parent;
		sub_left->_bf = 0;
		if (grandparent != nullptr) {
			if (grandparent->_left == cur) {
				grandparent->_left = sub_left;
			}
			if (grandparent->_right == cur) {
				grandparent->_right = sub_left;
			}
			
		}
		cur->_parent = sub_left;
		cur->_left = sub_left_right;
		
		if (sub_left_right != nullptr) {
			sub_left_right->_parent = cur;
		}
		
	}

	void Rotate_left(Node* cur) {
		Node* grandparent = cur->_parent;
		Node* sub_right = cur->_right;
		Node* sub_right_left = sub_right->_left;
		sub_right->_left = cur;
		
		cur->_bf = 0;


		if (cur == _root) {
			_root = sub_right;
		}

		sub_right->_parent = cur->_parent;
		sub_right->_bf = 0;

		if (grandparent != nullptr) {
			if (grandparent->_left == cur) {
				grandparent->_left = sub_right;
			}
			if (grandparent->_right == cur) {
				grandparent->_right = sub_right;
			}

		}

		cur->_parent = sub_right;
		cur->_right = sub_right_left;
		if (sub_right_left != nullptr) {
			sub_right_left->_parent = cur;
		}
		
	}

	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;

		Rotate_left(parent->_left);
		Rotate_right(parent);

		// 更新平衡因子
		if (bf == 0)
		{
			parent->_bf = 0;
			subL->_bf = 0;
			subLR->_bf = 0;
		}
		else if (bf == 1)
		{
			parent->_bf = 0;
			subL->_bf = -1;
			subLR->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 1;
			subL->_bf = 0;
			subLR->_bf = 0;
		}
		else
		{
			// subLR->_bf旋转前就有问题
			assert(false);
		}
	}

	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		Rotate_right(parent->_right);
		Rotate_left(parent);

		if (bf == 0)
		{
			subRL->_bf = 0;
			parent->_bf = 0;
			subR->_bf = 0;
		}
		else if (bf == 1)
		{
			subRL->_bf = 0;
			parent->_bf = -1;
			subR->_bf = 0;
		}
		else if (bf == -1)
		{
			subRL->_bf = 0;
			parent->_bf = 0;
			subR->_bf = 1;
		}
		else
		{
			// subLR->_bf旋转前就有问题
			assert(false);
		}
	}

	bool insert(const pair<k, v>& kv) {
		if (_root == nullptr) {
			_root = new Node(kv);
			_root->_bf = 0;
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur) {
   			if (cur->_kv.first < kv.first) {
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first) {
				parent = cur;
				cur = cur->_left;
			}
			else {
				return false;
			}
		}
		cur = new Node(kv);
		
		if (parent->_kv.first < kv.first) {
			parent->_right = cur;
		}
		else if (parent->_kv.first > kv.first) {
			parent->_left = cur;
		}
		cur->_parent = parent;


		//更新平衡因子
		//子树高度变了,就要继续往上更新
		//子树的高度不变,则更新完成
		//子树违反平衡规则,则停止更新,选转
		while (parent != nullptr && parent->_bf < 2 && parent->_bf > -2) {
			if (cur == parent->_right) {
				parent->_bf++;
			}
			else {
				parent->_bf--;
			}
			
			if (parent->_bf == 0) {
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1) {
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2) {
				if (parent->_bf == 2 && cur->_bf == 1) {
					Rotate_left(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == -1) {
					Rotate_right(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1) {
					RotateLR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1) {
					RotateRL(parent);
				}
				break;
			}
			else {
				assert(false);
			}
		}
		
		return true;
	}



	int _max_height(Node* root) {
		if (root == nullptr) {
			return 0;
		}
		int lefth = _max_height(root->_left);
		int righth = _max_height(root->_right);
		return lefth > righth ? lefth + 1 : righth + 1;
	}
	int max_height() {
		return _max_height(_root);
	}

	/*int _min_height(Node* cur) {
		if (cur == nullptr) {
			return 0;
		}
		else {
			int left = _min_height(cur->_left);
			int right = _min_height(cur->_right)
				return left > right ? right + 1 : left + 1;
		}
	}
	int min_height() {
		return _min_height(_root);
	}
*/


	bool _if_balanced(Node* cur) {
		if (cur == nullptr) {
			return true;
		}

		int leftheight = _max_height(cur->_left);
		int rightheight = _max_height(cur->_right);
		int diff = rightheight - leftheight;

		if (abs(diff) >= 2) {
			cout << "平衡因子异常" << endl;
			return false;
		}
		if (diff != cur->_bf) {
			cout << "平衡因子不符合实际" << endl;
			return false;
		}
		return _if_balanced(cur->_left) && _if_balanced(cur->_right);
	}
	bool if_balanced() {
		return _if_balanced(_root);
	}
	

private:
	Node* _root = nullptr;
};

void Test1() {
	AVLTree<int, int> t;
	
	for (int i = 0; i < 100000; ++i) {
		//t.insert(make_pair(i, i));
		t.insert(make_pair(rand(), rand()));
	}
	//t.insert(make_pair(1, 1));
	//t.insert(make_pair(3, 3));
	//t.insert(make_pair(2, 2));


	t.levelOrder(t.get_root());
	//cout << t.if_balanced() << endl;
	cout << "是否平衡: " << t.if_balanced() << endl;
	cout << "高度: " << t.max_height() << endl;
}
