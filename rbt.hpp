#ifndef rbt_hpp
#define rbt_hpp

#include "rbt_node.cpp"


template <typename data>
class rbt
{
	rbt_node<data>* root;
	bool is_empty;
	rbt_node<data>* bst_insert(const data& key);
	void in_order_output(rbt_node<data>* input);
	void revolve(rbt_node<data>* input,Direction d);
public:
	void in_order_output();
	rbt_node<data>* insert(const data& key);
	rbt();
	~rbt();
};

#endif /* rbt_hpp */















