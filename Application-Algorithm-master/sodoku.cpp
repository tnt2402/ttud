#include <iostream>
using namespace std;
/*
    điền vào mỗi ô 1 số 1 đến 9
    ràng buộc:
        +mỗi hàng       |
        +mỗi cột        |   =>  các số đôi một khác nhau: 1-9 xuất hiện đúng 1 lần
        +mỗi ô 3x3      |

    markRow[9][10]: markRow[r][v]==true nghĩa là v đa xuất hiện trên hàng r (r=0..8,v=1...9)
    markCol[9][10]: markCol[c][v]==true nghĩa là v đã xuất hiện trên cột  c (c=0..8,v=1...9)
    markSquare[3][3][10]
*/

bool markRow[9][10];
bool markCol[9][10];
bool markSquare[3][3][10];
int x[9][9];
void Solution()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
}

bool check(int v, int r, int c)
{
    return markRow[r][v] == false && markCol[c][v] == false && markSquare[r / 3][c / 3][v] == false;
}

void Try(int r, int c)
{
    for (int v = 1; v <= 9; v++)

    {
        if (check(v, r, c))
        {
            x[r][c] = v;
            markRow[r][v] = true;
            markCol[c][v] = true;
            markSquare[r / 3][c / 3][v] = true;
            if (r == 8 && c == 8)
            {
                Solution();
                break;
            }
            else
            {
                if (c < 8)
                    Try(r, c + 1);
                else
                    Try(r + 1, 0);
            }
            markRow[r][v] = false;
            markCol[c][v] = false;
            markSquare[r / 3][c / 3][v] = false;
        }
    }
}

int main()
{
    for (int v = 1; v <= 9; v++)
    {
        for (int c = 0; c < 9; c++)
            markCol[c][v] = false;
        for (int r = 0; r < 9; r++)
            markRow[r][v] = false;
        for (int i = 0; i <= 2; i++)
            for (int j = 0; j <= 2; j++)
                markSquare[i][j][v] = false;
    }
    Try(0, 0);
    return 0;
}