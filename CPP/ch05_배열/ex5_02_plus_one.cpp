/*
문제 5.2
임의의 정수값 증가시키기
*/

#include <vector>
#include <iterator>
using namespace std;

vector<int> PlusOne(vector<int> A)
{
    ++A.back();
    for(int i = size(A)-1; i>0 && A[i] == 10; --i)
    {
        A[i] = 0, ++A[i-1];
    }

    if(A[0] == 10)
    {
        //최상위 숫자에 올림수가 존재하므로, 결과를 저장하려면 한 자리가 더 필요하다.
        //한 자리를 늘리는 깔끔한 방법은,
        //첫 번째 항목을 1로 업데이트하고, 배열 끝에는 0을 추가해 주는 것이다.
        A[0] = 1;
        A.emplace_back(0);
    }
    return A;
}
