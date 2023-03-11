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
        cin >> call;
        if (call == "#")
        {
            break;
        }
        totalCall++;
        cin >> from_number >> to_number >> date >> from_time >> end_time;
        if (!checkPhone(from_number) || !checkPhone(to_number))
        {
            ++incorrectNumber;
        }
        numberCall[from_number]++;
        timeCall[from_number] += countTime(from_time, end_time);
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
    } while (1);
}
