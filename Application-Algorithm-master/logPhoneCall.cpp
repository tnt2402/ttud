#include <bits/stdc++.h>
using namespace std;

map<string, int> countCalls, timeCalls;
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

// call 0912345678 0945324545 2022-07-13 11:30:10 11:35:11

int timeCallsCal(string from_time, string to_time)
{
    int start_time = ((from_time[0] - '0') * 10 + (from_time[1] - '0')) * 3600 +
                     ((from_time[3] - '0') * 10 + (from_time[4] - '0')) * 60 +
                     ((from_time[6] - '0') * 10 + (from_time[7] - '0'));
    int end_time = ((to_time[0] - '0') * 10 + (to_time[1] - '0')) * 3600 +
                   ((to_time[3] - '0') * 10 + (to_time[4] - '0')) * 60 +
                   ((to_time[6] - '0') * 10 + (to_time[7] - '0'));

    return end_time - start_time;
}

int main()
{
    bool check_phone_number = true;
    string call;
    string from_number, to_number, date, from_time, to_time;
    int total_calls = 0;
    while (1)
    {
        cin >> call;
        if (call == "#")
            break;
        total_calls++;
        cin >> from_number >> to_number >> date >> from_time >> to_time;
        if (!checkPhone(from_number) || !checkPhone(to_number))
        {
            check_phone_number = false;
        }
        countCalls[from_number]++;
        timeCalls[from_number] += timeCallsCal(from_time, to_time);
    }

    do
    {
        cin >> call;
        string phone_number;
        if (call == "#")
            break;
        if (call == "?check_phone_number")
        {
            if (check_phone_number)
            {
                cout << 1 << endl;
            }
            else
                cout << 0 << endl;
        }
        if (call == "?number_calls_from")
        {
            cin >> phone_number;
            cout << countCalls[phone_number] << endl;
        }
        if (call == "?number_total_calls")
        {
            cout << total_calls << endl;
        }
        if (call == "?count_time_calls_from")
        {
            cin >> phone_number;
            cout << timeCalls[phone_number] << endl;
        }
    } while (call != "#");
}