#include "int20.h"
int main() {
	Int20 first, second;
	std::cin >> first >> second;
	long long sum1 = 0 ,sum2 = 0;
	for (long long loop = 0; loop < 1048560; loop += 1)
	{
		first++;
		second--;
		sum1 += first;
		sum2 -= second;
	}
	std::cout << first + second << sum1 << sum2 << std::endl;
	return 0;
}
