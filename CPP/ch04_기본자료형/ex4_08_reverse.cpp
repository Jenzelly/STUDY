/*
문제 4.8
숫자 뒤집기
*/

long long Reverse(int x)
{
    long long result = 0;
    while (x)
    {
        //x가 음수이면, x%10은 최하위 숫자의 음수 값과 같다.
        //예를 들어 -256%10=-6
        result = result * 10 + x % 10;   // result를 한 자리 왼쪽으로 밀고(×10), x의 마지막 자릿수를 붙임(%10)
        x /= 10;                        // x의 마지막 자릿수를 제거
    }
    return result;
}
