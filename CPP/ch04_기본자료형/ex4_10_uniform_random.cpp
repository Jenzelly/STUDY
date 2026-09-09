/*
문제 4.10

임의의 숫자를 균등한 확률로 생성하기
*/

int UniformRandom (int lower_bound, int upper_bound)
{
    int number_of_outcomes = upper_bound - lower_bound +1, result;
    do
    {
        result = 0;
        for( int i = 0; (1<<i) < number_of_outcomes; ++i)
        {
            //ZeroOneRandom()은 임의의 숫자를 생성하는 함수이다.
            result = (result << 1) | ZeroOneRandom();
        }
    } while (result >= number_of_outcomes);
    return result + lower_bound;
}
