/*
문제 5.1
네덜란드 국기 문제
*/

#include <vector>      // vector<Color> 사용하려면 필요
#include <algorithm>   // swap() 함수 사용하려면 필요
#include <iterator>    // size() 자유 함수 사용하려면 필요 (C++17)

using namespace std;   // std::vector, std::swap 등을 그냥 vector, swap으로 쓰려면 필요


typedef enum 
{
    kRed,
    kWhite,
    kBlue
}Color;


// 방법 1.
void DutchFloaPartition(int pivot_index, vector<Color>* A_ptr)
{
    vector<Color>& A = *A_ptr;
    Color pivot = A[pivot_index];

    //첫 번째 단계 : 피벗보다 작은 원소의 그룹을 구한다.
    for(int i = 0; i < size(A); ++i)
    {
        //작은 원소를 찾는다.
        for(int j = i+1; j < size(A); ++j)
        {
            if(A[j] < pivot)
            {
                swap(A[i], A[j]);
                break;
            }
        }
    }
    
    //두 번째 단계: 피벗보다 큰 원소의 그룹을 구한다.
    for(int i = size(A) - 1; i >= 0; --i)
    {
        //큰 원소를 찾는다. 피벗보다 작은 원소에 맞닥뜨리게 되면 즉시 멈춘다.
        //왜냐하면 윗 단계에서 그들은 이미 A의 앞쪽으로 옮겨졌기 때문이다.
        for(int j = i-1; j >= 0; --j)
        {
            if(A[j] > pivot)
            {
                swap(A[i], A[j]);
                break;
            }
        }
    }
}



//방법 2.
void DutchFlagPartition(int pivot_index, vector<Color>* A_ptr)
{
    vector<Color>& A = *A_ptr;
    Color pivot = A[pivot_index];

    //첫 번째 단계: 피벗보다 작은 원소의 그룹을 구한다.
    int smaller = 0;
    for (int i = 0; i < size(A); ++i)
    {
        if(A[i] < pivot)
        {
            swap(A[i], A[smaller++]);
        }
    }

    //두 번째 단계: 피벗보다 큰 원소의 그룹을 구한다.   
    int larger = size(A) -1;
    for (int i = size(A) -1; i >= 0; --i)
    {
        if(A[i] > pivot)
        {
            swap(A[i], A[larger--]);
        }
    }    
}



//방법 3.
void DutchFlagPartition(int pivot_index, vector<Color>* A_ptr)
{
    vector<Color>& A = *A_ptr;
    Color pivot = A[pivot_index];

    /*
    분류할 때마다 다음 불변식을 만족해야 한다.
    피벗보다 작은 원소 그룹: A[0, smaller-1]
    피벗과 같은 원소 그룹: A[smaller, equal-1]
    미분류 원소 그룹: A[equal, larger -1]
    피벗보다 큰 원소 그룹: A[larger, size(A)-1]
    */

    int smaller = 0, equal = 0, larger = size(A);
    //분류되지 않은 원소가 있는 동안 계속 순회한다.

    while (equal < larger)
    {
        //A[equal]은 분류되지 않은 원소를 가리킨다.
        if(A[equal] < pivot)
        {
            swap(A[smaller++], A[equal++]);
        }
        else if(A[equal] == pivot)
        {
            ++equal;
        }
        else //A[equal] > pivot
        {
            swap(A[equal], A[--larger]);
        }
    }
}