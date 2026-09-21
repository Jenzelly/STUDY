/*
문제 5.5
정렬된 배열에서 중복 제거하기
*/

#include <vector>
using namespace std;

int DeleteDuplicates(vector<int>* A_ptr)
{
    vector<int>& A = *A_ptr;
    if (empty(A))
    {
        return 0;
    }

    int write_index = 1;
    for (int i = 1; i < size(A); ++i)
    {
        if (A[write_index -1] != A[i])
        {
            A[write_index++] = A[i];
        }
    }
    return write_index;
}