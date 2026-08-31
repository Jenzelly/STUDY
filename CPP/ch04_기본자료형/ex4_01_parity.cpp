//정수 1로 세팅된 비트의 개수 찾기
//최하위 비트 부터 시작해서 한비트씩 테스트
//shift와 mask 사용방법 알수있고, 
//단어 크기에 관계없이 비트의 개수 찾을 수 있다.
short CountBits(unsigned int x) 
{
	short num_bits = 0;
	while(x)
	{
		num_bits += 1;
		x >>= 1;
	}
	return num_bits;
}


/*
parity?
정보 전달과정에서 오류가 생겼는지 검사하기 위한 값
전체 비트개수를 2로 나눈 나머지값

2진수의 패리티는 1로 세팅된 비트의 개수와 같다.
즉, 1이 홀수개면 1, 짝수개 0
*/

/*
문제 4.1 
64bit로 이뤄진 숫자가 굉장히 많다면, 패리티를 어떻게 계산할까?
*/

short Parity(unsigned long long x)
{
	short result = 0;
	while(x)
	{
		result ^= (x & 1); //x에서 1의 개수 짝수인지 홀수인지 찾고(AND), XOR 연산(같으면 0, 다르면 1)
		x >>= 1; 
	}
	return result;
}

//하위 비트를 지우기, 위에꺼 보다 빠름
short Parity(unsigned long long x)
{
	short result = 0;
	while(x)
	{
		result ^= 1;
		x &= (x - 1); // x&(x-1)은 1로 세팅된 비트중 가장 낮은 비트를 지움
	}
	return result;
}

//비트 마스크, lookup table, 가장 빠름
short Parity(unsigned long long x)
{
	const int KmaskSize = 16;
	const int kBitMask = 0xFFFF;
	return kPreComputedParity[x >> (3 * KmaskSize)] ^
		kPreComputedParity[(x >> (2 * KmaskSize)) & kBitMask] ^
		kPreComputedParity[(x >> KmaskSize) & kBitMask] ^
		kPreComputedParity[x & KmaskSize];
}

//XOR 폴딩
short Parity(unsigned long long x)
{
	x ^= x >> 32;
	x ^= x >> 16;
	x ^= x >> 8;
	x ^= x >> 4;
	x ^= x >> 2;
	x ^= x >> 1;
	return x & 1;
}