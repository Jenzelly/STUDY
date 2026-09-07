/*
문제 4.5

곱셈과 덧셈없이 x*y 계산하기

보청기 같은 저전력 기기의 프로세서에 곱셈 연산기가 없는 경우가 종종있다.

*/

unsigned long long Multiply(unsigned long long x, unsigned long long y)
{
	unsigned long long sum = 0;
	while(x)
	{
		//x의 각 비트를 확인해 본다
		if(x & 1)
		{
			sum = Add(sum, y);
		}
		x >>= 1, y <<= 1;
	}
	return sum;
}


unsigned long long Add(unsigned long long a, unsigned long long b)
{
	while(b)
	{
		unsigned long long carry = a & b;
		a = a ^ b;
		b = carry << 1;
	}
	return a;
}
