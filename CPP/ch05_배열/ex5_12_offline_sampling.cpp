/*
문제 5.12
오프라인 데이터 샘플 구하기
*/

#include <vector>
#include <algorithm>
#include <random>
using namespace std;

void RandomSampling(int k, vector<int>* A_ptr)
{
    vector<int>& A = *A_ptr;
    default_random_engine seed((random_device()) ()); //난수 생성기 초기화

    for(int i = 0; i<k; ++i)
    {
        // i번 자리와 무작위 인덱스를 교환
        swap(A[i], A[uniform_int_distribution<int>{i, static_cast<int>(A.size()) - 1}(seed)]);
    }
}