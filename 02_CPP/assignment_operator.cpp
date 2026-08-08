#include<iostream>

using namespace std;

class Test
{
	private:
		int num1;
		int num2;

	public:
		Test()
		{
		}

		Test(int num1, int num2)
		{
			this->num1 = num1;
			this->num2 = num2;
		}

		Test& operator=(const Test &temp)
		{
			cout << "Inside assignment operator function" << endl;

			this->num1 = temp.num1;
			this->num2 = temp.num2;

			return *this;
		}

		void display()
		{
			cout << "num1 : " << this->num1 << endl;
			cout << "num2 : " << this->num2 << endl;
		}
};

int main()
{
	Test t1(10,20);
	Test t2;
	t2 = t1;

	t1.display();
	t2.display();

	return 0;
}
