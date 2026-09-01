//프로그램 속도 향상 시키는 다양한 비트 조작 (bit manipulation) 방법들이 있다.
//bit swap은 언제 필요할까?
// 엔디안 변환


/*
문제 4.2
64 bit 정수가 주어졌을때 i번째 비트와 j번째 비트를 스왑하는 코드를 작성하라.
*/

long long SwapBits(long long x, int i, int j)
{
	if(((x >> i) & 1) != ((x >> j) & 1))
	{
		//두 비트 다르면, 스왑구현
		unsigned long long bit_mask = (1LL << i) | (1LL << j); // 비트 마스킹
		x ^= bit_mask; //XOR 로 뒤집기
	}
	return x;
}