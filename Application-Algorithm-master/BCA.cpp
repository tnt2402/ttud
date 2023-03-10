#include <bits/stdc++.h>

using namespace std;
// m giao vien, n mon hoc
int m, n;
bool A[11][31];
bool conflict[31][31];
int x[31];
int res = -1;

vector<int> P[11];

void Try(int course_index)
{
    if (course_index > n)
    {
        // dk1
        for (int i = 1; i <= m; i++)
        {
            if (P[i].size() < 1)
                return;
        }
        // dk2
        for (int i = 1; i <= m; i++)
        {
            for (int course : P[i])
            {
                if (A[i][course] == false)
                    return;
            }
        }
        // dk3
        for (int i = 1; i <= m; i++)
        {
            for (int course : P[i])
            {
                for (int _course : P[i])
                {
                    if (course != _course && conflict[course][_course] == true)
                    {
                        return;
                    }
                }
            }
        }
        return;
    }

    for (int teacher_index = 1; teacher_index <= m; teacher_index++)
    {
        x[course_index] = teacher_index;
        P[teacher_index].push_back(course_index);
        Try(course_index + 1);

        // reset
        x[course_index] = 0;
        P[teacher_index].pop_back();
    }
}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        while (k--)
        {
            int c;
            cin >> c;
            A[i][c] = true;
        }
    }
    int k;
    cin >> k;
    while (k--)
    {
        int a, b;
        cin >> a >> b;
        conflict[a][b] = true;
        conflict[b][a] = true;
    }

    return 0;
}