#include "rbt.hpp"
template <typename data>
rbt<data>::rbt():is_empty(1)
{
	root=new rbt_node<data>;
}

template <typename data>
rbt<data>::~rbt()
{
	if(!is_empty)
	{
		queue<rbt_node<data>*> destroy;
		destroy.push(root);
		while(!destroy.empty())
		{
			rbt_node<data>* temp=destroy.front();
			destroy.pop();
			if(temp->left_son!=nullptr)
			{
				destroy.push(temp->left_son);
			}
			if(temp->right_son!=nullptr)
			{
				destroy.push(temp->right_son);
			}
			delete temp;
			temp=nullptr;
		}
		root=nullptr;
		is_empty=1;
	}
}

template <typename data>
rbt_node<data>* rbt<data>::bst_insert(const data& key)
{
	rbt_node<data>* it;
	if(!is_empty)
	{
		it=root;
		while(it!=nullptr)
		{
			if(key<it->content)
			{
				if(it->left_son==nullptr)
				{
					rbt_node<data>* input=new rbt_node<data>(key);
					it->set_son(input,Direction::left);
				}
				it=it->left_son;
			}
			else if(key>it->content)
			{
				if(it->right_son==nullptr)
				{
					rbt_node<data>* input=new rbt_node<data>(key);
					it->set_son(input,Direction::right);
				}
				it=it->right_son;
			}
			else
			{
				return it;
			}
		}
	}
	else
	{
		if(root==nullptr)
		{
			root=new rbt_node<data>(key);
		}
		root->content=key;
		is_empty=0;
		it=root;
	}
	return it;
}

template <typename data>
void rbt<data>::in_order_output(rbt_node<data>* input)
{
	if(input==nullptr)
	{
		return;
	}
	if(input->left_son!=nullptr)
	{
		in_order_output(input->left_son);
	}
	cout<<input<<endl;
	if(input->right_son!=nullptr)
	{
		in_order_output(input->right_son);
	}
}

template <typename data>
void rbt<data>::in_order_output()
{
	in_order_output(root);
}



template <typename data>
rbt_node<data>* rbt<data>::insert(const data& key)
{
	return bst_insert(key);
}



template<typename data>
void rbt<data>::revolve(rbt_node<data>* input, Direction d)
{
	if (input == nullptr)
	{
		return;
	}
	rbt_node<data>* parent = nullptr;
	rbt_node<data>* alternative = nullptr;
	if (input->parent != nullptr)
	{
		parent = input->parent;
		parent->break_son(input);

	}
	if (d == Direction::left)
	{
		//alternative = input->left_son;
	}
}

