/*
문제 5.10
배열 안의 원소로 순열 구하기
*/

#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

void ApplyPermutation(vector<int> perm, vector<int>* A_ptr)
{
    vector<int>& A = *A_ptr;
    for(int i = 0; i<size(A); ++i)
    {
        while (perm[i] != i)
        {
            swap(A[i], A[perm[i]]);
            swap(perm[i], perm[perm[i]]);
        }
    }
}