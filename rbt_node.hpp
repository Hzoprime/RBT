#ifndef rbt_node_hpp
#define rbt_node_hpp


#include <iostream>
#include <queue>
using namespace std;

enum Color
{
	black = 0, red

};


enum Direction
{
	left = 0, right
};

//ostream& operator<<(ostream& out, Color c);


template <typename data>
class rbt_node
{
public:
    data content;
    rbt_node* left_son;
    rbt_node* right_son;
    rbt_node* parent;
    Color color;
    
    rbt_node();
    rbt_node(const data& input);
    
    void set_son(rbt_node* input,Direction d);
    void break_son(rbt_node* input);
    rbt_node* break_son(Direction d);
    
    void set_color(Color c);
    
    
    
    friend ostream& operator<<(ostream& out,rbt_node* node)
    {
		out
			<< node->content
			<< ' ';
		if (node->color == Color::red)
		{
			out << "red";
		}
		else
		{
			out << "black";
		}
        return out;
    }
};


#endif /* rbt_node_hpp */
