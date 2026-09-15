/*
문제 5.4
배열에서 이동하기
*/

#include <vector>
#include <iterator>
using namespace std;

bool CanReachEnd (const vector<int>& max_advance_steps) // 배열을 const 참조로 받음
{
    int furthest_reach_so_far = 0, last_index = size(max_advance_steps) -1; // 지금까지 도달 가능한 가장 먼 인덱스와 마지막 인덱스

    for(int i = 0; i <= furthest_reach_so_far && furthest_reach_so_far < last_index; ++i) // 현재위치가 도달가능 범위이고, 아직 끝에 도달하지 않았으면 계속
    {
        furthest_reach_so_far = max(furthest_reach_so_far, max_advance_steps[i]+i); //최대도달거리와 현재위치에서 갈수 있는 최대 거리 비교
    } 
    return furthest_reach_so_far >= last_index; //끝에 도달가능하면 true
}