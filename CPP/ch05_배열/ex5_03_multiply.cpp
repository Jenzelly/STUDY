/*
문제 5.3
임의의 두 정수값 곱하기
*/

#include <vector>
#include <iterator>
#include <algorithm>
#include <cstdlib>
using namespace std;

vector<int> Multiply(vector<int> num1, vector<int> num2)
{
    const int sign = (num1.front() < 0) ^ (num2.front() < 0) ? -1 : 1;

    num1.front() = abs(num1.front()), num2.front() = abs(num2.front());

    vector<int> result(size(num1) + size(num2), 0);
    for (int i = size(num1) -1; i>= 0; --i)
    {
        for (int j = size(num2) -1; j>= 0; --j)
        {   
            result[i+j+1] += num1[i] * num2[j];
            result[i+j] += result[i+j+1]/10;
            result[i+j+1] %= 10;
        }
    }

    //0으로 시작하는 부분을 제거한다.
    result = { find_if_not (begin(result), end(result), [](int a) {return a == 0; }), end(result) };
    if(empty(result))
    {
        return {0};
    }
    result.front() *= sign;
    return result;
}


