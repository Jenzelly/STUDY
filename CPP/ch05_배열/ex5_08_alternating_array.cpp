/*
문제 5.8
대체 연산
*/

#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void Rearrange(vector<int>* A_ptr)
{
    vector<int>& A= *A_ptr;
    for(size_t i= 1; i < size(A); ++i)
    {
        if((!(i%2) && A[i-1] < A[i]) || ((i%2) && A[i-1] > A[i]))
        {
            swap(A[i-1], A[i]);
        }
    }
}