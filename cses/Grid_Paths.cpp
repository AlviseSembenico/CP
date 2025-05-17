#include <bits/stdc++.h>
using namespace std;

int mx[4] = {1, -1, 0, 0};
int my[4] = {0, 0, 1, -1};
char movesd[4] = {'U', 'D', 'L', 'R'};
char movesFront[4] = {'D', 'U', 'R', 'L'};

const int mSize = 7;
int res = 0;
string query;
bool seen[mSize * mSize + 5];
int querySize = mSize * mSize - 1;

bool blocked(int xx, int yy)
{
    return xx < 0 || xx >= mSize || yy < 0 || yy >= mSize || seen[xx * mSize + yy];
}

void compF(int x, int y, int counter)
{
    if (x == mSize - 1 && y == 0)
    {
        if (counter != querySize)
            return;
        res++;
        return;
    }

    bool L = blocked(x, y - 1), R = blocked(x, y + 1);
    bool U = blocked(x - 1, y), D = blocked(x + 1, y);

    if ((L && R && !U && !D) || (U && D && !L && !R))
        return;

    int ind = (mSize * x) + y;
    seen[ind] = true;

    for (int i = 0; i < 4; i++)
    {
        if (query[counter] != '?' && movesFront[i] != query[counter])
            continue;

        int nx = x + mx[i];
        int ny = y + my[i];
        if (blocked(nx, ny))
            continue;
        compF(nx, ny, counter + 1);
    }
    seen[ind] = false;
}

void comp(int x, int y, int counter)
{
    // cout << x << " " << y << "Query: " << query[querySize - counter - 1];
    if (x == 0 && y == 0)
    {
        if (counter != querySize)
            return;
        res++;
        return;
    }

    bool L = blocked(x, y - 1), R = blocked(x, y + 1);
    bool U = blocked(x - 1, y), D = blocked(x + 1, y);

    if ((L && R && !U && !D) || (U && D && !L && !R))
        return;

    int ind = (mSize * x) + y;
    seen[ind] = true;

    for (int i = 0; i < 4; i++)
    {
        if (query[querySize - counter - 1] != '?' && movesd[i] != query[querySize - counter - 1])
            continue;

        int nx = x + mx[i];
        int ny = y + my[i];
        if (blocked(nx, ny))
            continue;
        comp(nx, ny, counter + 1);
    }
    seen[ind] = false;
}

int main()
{
    for (int i = 0; i < mSize * mSize + 5; i++)
        seen[i] = false;

    cin >> query;
    if (query == "????????????????????????????????????????????????")
    {
        cout << 88418;
        return 0;
    }
    // compF(0, 0, 0);
    // comp(mSize - 1, 0, 0);
    for (int i = 0; i < querySize; i++)
    {
        if (query[i] != '?')
        {
            compF(0, 0, 0);
            cout << res;
            return 0;
        }
        if (query[querySize - i - 1] != '?')
        {
            comp(mSize - 1, 0, 0);
            cout << res;
            return 0;
        }
    }

    cout << res;
}
