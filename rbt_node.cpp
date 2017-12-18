#include "rbt_node.hpp"

//
//
//
//ostream& operator<<(ostream& out, Color c)
//{
//	if (c == Color::red)
//		out << "red";
//	else
//		out << "black";
//	return out;
//}



template <typename data>
rbt_node<data>::rbt_node():left_son(nullptr),right_son(nullptr),parent(nullptr),color(Color::red)
{
    
}

template <typename data>
rbt_node<data>::rbt_node(const data& input):content(input),left_son(nullptr),right_son(nullptr),parent(nullptr),color(Color::red)
{
}

template <typename data>
void rbt_node<data>::set_son(rbt_node* input, Direction d)
{
    d==Direction::left?(this->left_son=input):(this->right_son=input);
    input->parent=this;
}

template <typename data>
void rbt_node<data>::break_son(rbt_node* input)
{
    this->left_son==input?(this->left_son=nullptr):(this->right_son=nullptr);
    input->parent=nullptr;
}

template <typename data>
rbt_node<data>* rbt_node<data>::break_son(Direction d)
{
    rbt_node<data>* temp=nullptr;
    if(d==Direction::left)
    {
        temp=this->left_son;
        this->left_son=nullptr;
    }
    else
    {
        temp=this->right_son;
        this->right_son=nullptr;
    }
    temp->parent=nullptr;
    return temp;
}








template <typename data>
void rbt_node<data>::set_color(Color c)
{
    this->color=c;
}
