/*
문제 4.7
pow(x,y) 계산하기
*/

double Power(double x, int y)
{
    double result = 1.0;                    // 최종 결과 누적 변수. 곱셈의 항등원 1.0으로 시작
    long long power = y;                    // int 최솟값(-2147483648)의 부호 반전 시 오버플로 방지를 위해 long long으로 복사
    if(y < 0)
    {
        power = -power, x = 1.0/x;         // 음수 지수 처리: x^(-3) = (1/x)^3. power를 양수로, x를 역수로
    }
    while (power)                           // power가 0이 될 때까지 반복 (이진수 자릿수만큼 = O(log y))
    {
        if (power &1)                       // power의 최하위 비트가 1이면 → 이 자릿수의 거듭제곱을 결과에 포함
        {
            result *=x;                     // 현재 x 값(x^1, x^2, x^4, x^8...)을 result에 곱함
        }
        x*=x, power >>= 1;                 // x를 제곱(x→x²→x⁴→x⁸...), power를 1비트 오른쪽 시프트(다음 자릿수로)
    }
    return result;                          // 선택된 거듭제곱들의 곱 = x^y
}
