#include <algorithm>
using namespace std;

bool intersect(int l1, int r1, int l2, int r2)
{
    return max(l1, l2) <= min(r1, r2);
}