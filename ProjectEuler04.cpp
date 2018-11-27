// A palindromic number reads the same both ways.The largest palindrome made from the product of two 2 - digit numbers is 9009 = 91 × 99.
// Find the largest palindrome made from the product of two 3 - digit numbers.
// Answer: 906609
//Optimization needed in code.

#include <iostream>
#include<map>

using namespace std;

struct Prod {
	int one;
	int two;
};

bool IsPalindrome(int number)
{
	int reversedNumber = 0, originalNumber = number, remainder;
	while (number != 0)
	{
		remainder = number % 10;
		reversedNumber = reversedNumber * 10 + remainder;
		number /= 10;
	}
	if (reversedNumber == originalNumber)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

Prod ProductOfNumber()
{
	Prod num;
	int largestNumber = 0;
	map<int, Prod> mymap;
	
	for (int i = 100; i <= 999; i++)
	{
		for (int j = 100; j <= 999; j++)
		{
			if (IsPalindrome(i*j))
			{
				num.one = i; 
				num.two = j;
				mymap.insert(std::pair<int, Prod>(i*j, num));
			}
		}
	}
	
	Prod result;
	for (std::map<int, Prod>::iterator it = mymap.begin(); it != mymap.end(); ++it)
	{
		if ((it->first) > largestNumber)
		{
			largestNumber = it->first;
			result.one = it->second.one;
			result.two = it->second.two;
		}

	}

	return result;
}


int main()
{
	
	Prod product = ProductOfNumber();

	cout << "Num1 : " << product.one << " Num2 : " << product.two << endl;
	
	return 0;
}
