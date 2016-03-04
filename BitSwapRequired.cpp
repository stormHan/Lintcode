#include "BitSwapRequired.h"


void BitSwapRequired::test()
{
	int a, b;
	cin >> a >> b;

	cout << -a << " " << b << endl;

	int result = bitSwapRequired(a, b);
	cout << result << endl;

}


int BitSwapRequired::bitSwapRequired(int a, int b)
{
	int count = 0, d;
	int c = a ^ b;
	
	if (c > 0)
		d = (int)log2(c) + 1;
	if (c < 0)
		d = 32;
	for (int i = 0; i < d; i++)
	{
		if (c & 1) count++;
		c = c >> 1;
	}
	return count;
}
