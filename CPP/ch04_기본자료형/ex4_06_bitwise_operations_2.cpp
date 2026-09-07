
/*
문제 4.6
산술 연산자 없이 나눗셈 계산하기

양의 정수 x, y를 나눈 몫을 구하라.
단, 사용 가능한 연산은 덧셈, 뺄셈, 그리고 시프트 연산 뿐이다.
*/



int Divide(int x, int y)
{
	int result = 0;
	int power = 32;
	unsigned long long y_power = static_cast<unsigned long long>(y) << power;
	while(x >= y)
	{
		while(y_power > x)
		{
			y_power >>= 1;
			--power;
		}

		result += 1 << power;
		x -= y_power;
	}
	return result;
}
