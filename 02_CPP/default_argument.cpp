#include<iostream>

using namespace std;

class Test
{
	private:
		int num1;
		int num2;

	public:
		//We are sending a default values to constructor parameter so this will act as parameterless and parameterized constructor as well. We know if we write a paramterized constructor then 
		//compiler will not give us parameterless constructor
		Test(int num1 = 0, int num2 = 0)
		{
			this->num1 = num1;
			this->num2 = num2;
		}

		int sum(int num1, int num2 = 10)
		{
			return num1+num2;
		}

		//int sum(int num1 = 10, int num2); // This will give error because the default values assignment should be done from right to left.
};

int main()
{
	Test t1;
	Test t2(10);
	Test t3(10,20);

	cout << "Addition is : " << t1.sum(100) << endl;

	//t1.sum();// This is error because no matching function call is present
	
	return 0;
}
