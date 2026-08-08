#include<iostream>

using namespace std;

class Test
{
	private:
		int num1;

	public:
		Test()
		{
			cout << "Parameterless constructor called" << endl;
		}

		Test(int num1)
		{
			this->num1 = num1;
			cout << "Parameterized constructor called" << endl;
		}

		Test(const Test &temp)
		{
			cout << "Copy constructor called" << endl;
			this->num1 = temp.num1;
		}
};

int main()
{
	Test t1; //Parameterless constructor called
	Test t2(10); //Parameterized constructor called
	Test t3 = t2; //Copy constructor called
	return 0;
}
