/*
문제 4.4 
같은 무게를 가진 가장 가까운 정수 찾기

같은 무게?
정수를 2진수로 표현했을 때 1로 세팅된 비트의 개수가 같다
*/

unsigned long long ClosestIntSameBitCount (unsigned long long x)
{
    const static int kNumUnsignedBits = 64;         //64bit
    for (int i = 0; i < kNumUnsignedBits -1; ++i)   //0~62bit 순회, 안에서 i+1까지 확인하므로 63bit 까지 확인됨
    {
        if(((x>>i) & 1) != ((x >> (i+1)) & 1))      //i와 i+1번째 비트 꺼내서 비교 다르면
        {
            x ^= (1ULL << i) | (1ULL << (i+1));     // i와 i+1번째 위치에 마스크 만들어 XOR로 스왑
            return x;
        }
    }
}