#include<iostream>

using namespace std;

int sum(int num1, int num2)
{
	return num1+num2;
}

int sum(int num1, int num2, int num3)
{
	return num1+num2+num3;
}

//int sum(int num1, int num2); //This is error because based on return type the overloading will not decide

double sum(double num1, double num2)
{
	return num1 + num2;
}

float sum(float num1, float num2)
{
	return num1 + num2;
}

int main()
{
	cout << "Addition is : " << sum(10,20) << endl;
	cout << "Addition is : " << sum(10,20,30) << endl;
	cout << "Addition is : " << sum(10.34,20.65) << endl;
	cout << "Addition is : " << sum(10.98f,20.12f) << endl;
	return 0;
}
