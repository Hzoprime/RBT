#include"rbt.cpp"
#include<string>
#include<fstream>
using namespace std;

int main()
{
	rbt<int> a;
	for (int i = 0; i < 10; i++)
	{
		a.insert(i + 1);
	}
	a.in_order_output();
	system("pause");
}