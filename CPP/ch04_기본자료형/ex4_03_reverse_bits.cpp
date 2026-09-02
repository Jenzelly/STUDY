/*
문제 4.3
64 bit 정수가 주어졌을때 이를 역순으로 재구성한 숫자를 반환하는 코드를 작성하라.

예)
1110000000000001  =>  1000000000000111
*/

//최상위비트와 최하위 비트를 bit swap 해도 괜찮다.
//그런데, 이 연산을 반복적으로 수행 할때는 캐시를 염두할 필요가 있다.
//많은 역순 연산이 필요로 하는경우 가장 효율적인 방법은 미리 룩업 테이블을 만들어 두는 것이다,

unsigned long long  ReverseBits(unsigned long long x)
{
    const int kMaskSize = 16;  // 64bit는 기니까 16bit로 쪼갠다 [A/B/C/D]
    const int kBitMask = 0xFFFF; // 이진수로 16개의 1 이니까 이걸로 & 연산하면 하위 16비트씩 추출가능

    return precomputed_reverse[x & kBitMask] << (3*kMaskSize) |             //최하위 비트D를 48칸 왼쪽으로 밀어서 맨 위에 배치
        precomputed_reverse[(x >> kMaskSize) & kBitMask] << (2*kMaskSize) | //16칸 밀어서 c를 맨끝으로 밀고 하위 16비트 추출후, 32칸 밀어서 위에서 두번째 배치
        precomputed_reverse[(x >> (2*kMaskSize)) & kBitMask] << kMaskSize | //32칸 밀어서 B를 맨끝으로 밀고 하위 16비트 추출후, 16칸 밀어서 세번째 위치
        precomputed_reverse[(x >> (3*kMaskSize)) & kBitMask];               //최상위 비트A를 48칸 오른쪽으로 밀어서 맨 아래에 배치
}