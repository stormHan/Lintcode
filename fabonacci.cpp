#include "fabonacci.h"

int fabonacci::_fibonacci(int n)
{
	/*------------------µ›πÈÀ„∑®--------------
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;

	return _fibonacci(n - 1) + _fibonacci(n - 2);
	*/

	//==================∑«µ›πÈÀ„∑®============
	long a = 0,b = 1;
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	for (int i = 2; i < n - 1; i++)
	{
		b = a + b;
		a = b - a;
	}
	return a + b;
}

void fabonacci::test(void)
{
	cin >> n;
	result = _fibonacci(n);
	cout << result << endl;
	getchar();
}
