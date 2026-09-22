/*
문제 5.11
다음 순열 구하기
*/

#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

vector<int> NextPermutation(vector<int> perm)
{
    auto inversion_point = is_sorted_until(rbegin(perm), rend(perm));
    if(inversion_point == rend(perm))
    {
        return {};
    }

    auto least_upper_bound = upper_bound(rbegin(perm), inversion_point, *inversion_point);

    iter_swap(inversion_point, least_upper_bound);
    reverse(rbegin(perm), inversion_point);
    return perm;
}