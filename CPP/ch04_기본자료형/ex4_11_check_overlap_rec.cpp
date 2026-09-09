/*
문제 4.11
사각형이 겹치는지 확인하기
*/

#include <algorithm>
using namespace std;

struct Rect
{
    int x, y, width, height;
};

bool IsIntersect(const Rect& r1, const Rect& r2)
{
    return r1.x <= r2.x + r2.width && r1.x + r1.width >= r2.x &&
            r1.y <= r2.y + r2.height && r1.y + r1.height >= r2.y;
}

Rect IntersectRectangle(const Rect& r1, const Rect& r2)
{
    if ( !IsIntersect (r1, r2))
    {
        return {0, 0, -1, -1};
    }

    return {max(r1.x, r2.x), max(r1.y, r2.y),
            min(r1.x + r1.width, r2.x + r2.width) - max(r1.x, r2.x),
            min(r1.y + r1.height, r2.y + r2.height) - max(r1.y, r2.y)};
}
