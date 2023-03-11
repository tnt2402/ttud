#include <bits/stdc++.h>
using namespace std;
#define MAX 100;
map<string, int> numberCall, timeCall;
bool checkPhone(string numberPhone)
{
    if (numberPhone.length() != 10)
        return false;
    for (int i = 0; i < numberPhone.length(); i++)
    {
        if (numberPhone[i] < '0' || numberPhone[i] > '9')
            return false;
    }
    return true;
}
// void covertTime(string timeCall, int rs[])
// {
//     rs[0] = atoi(timeCall[0]);
//     rs[1] = atoi(timeCall[3]);
//     rs[2] = atoi(timeCall[6]);
// }
// int totalTimeCall(int from_time, inr end_time)
// {
//     int fromTime[3];
//     covertTime(from_time, fromTime);
//     // printf ("%d %d %d\n",fromTime[0],fromTime[1],fromTime[2]);
//     int endTime[3];
//     covertTime(end_time, endTime);
//     // printf ("%d %d %d\n",endTime[0],endTime[1],endTime[2]);
//     // printf ("from: %d %d %d\n",fromTime[0],fromTime[1],fromTime[2]);
//     // printf ("end : %d %d %d\n",endTime[0],endTime[1],endTime[2]);
//     int total += 3600 * (-fromTime[0] + endTime[0]) + 60 * (-fromTime[1] + endTime[1]) + (-fromTime[2] + endTime[2]);
//     return total;
// }
int countTime(string ftime, string etime)
{
    int startTime = 3600 * ((ftime[0] - '0') * 10 + ftime[1] - '0') + 60 * ((ftime[3] - '0') * 10 + ftime[4] - '0') + ((ftime[6] - '0') * 10 + ftime[7] - '0');
    int endTime = 3600 * ((etime[0] - '0') * 10 + etime[1] - '0') + 60 * ((etime[3] - '0') * 10 + etime[4] - '0') + ((etime[6] - '0') * 10 + etime[7] - '0');
    return endTime - startTime;
}
int main()
{
    int incorrectNumber = 0, totalCall = 0;
    string call;
    string from_number, to_number, date, from_time, end_time;
    while (1)
    {
        // scanf("%s", call);
        cin >> call;
        if (call == "#")
        {
            break;
        }
        totalCall++;
        // scanf("%s %s %s %s %s", from_number, to_number, date, from_time, end_time);
        cin >> from_number >> to_number >> date >> from_time >> end_time;
        if (!checkPhone(from_number) || !checkPhone(to_number))
        {
            ++incorrectNumber;
        }
        numberCall[from_number]++;
        timeCall[from_number] += countTime(from_time, end_time);
        // cout << from_number << to_number << endl;
    }
    do
    {
        cin >> call;
        string S;
        if (call == "#")
            break;
        if (call == "?check_phone_number")
        {
            if (incorrectNumber == 0)
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
        else if (call == "?number_calls_from")
        {
            cin >> S;
            cout << numberCall[S] << endl;
        }
        else if (call == "?number_total_calls")
        {
            cout << totalCall << endl;
        }
        else if (call == "?count_time_calls_from")
        {
            cin >> S;
            cout << timeCall[S] << endl;
        }
        else
        {
            break;
        }
    } while (call != "#");
}
