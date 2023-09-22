#include <iostream>
using namespace std;

int maxmin(int i, int j, int Arr[], int &max_val, int &min_val);

int main()
{
    int array[] = {41, 4, -4, 25, 24, 12, 24};
    int max_val = INT32_MIN;
    int min_val = INT32_MAX;

    maxmin(0, 6, array, max_val, min_val);

    cout << "Maximum: " << max_val << endl;
    cout << "Minimum: " << min_val << endl;

    return 0;
}

int maxmin(int i, int j, int Arr[], int &max_val, int &min_val)
{
    if (i == j)
    {
        max_val = Arr[i];
        min_val = Arr[i];
    }
    else if ((j - i) == 1)
    {
        if (Arr[i] < Arr[j])
        {
            max_val = Arr[j];
            min_val = Arr[i];
        }
        else
        {
            min_val = Arr[j];
            max_val = Arr[i];
        }
    }
    else
    {
        int mid = (i + j) / 2;
        int left_max, left_min, right_max, right_min;

        maxmin(i, mid, Arr, left_max, left_min);
        maxmin(mid + 1, j, Arr, right_max, right_min);

        if (left_max > right_max)
        {
            max_val = left_max;
        }
        else
        {
            max_val = right_max;
        }

        if (left_min < right_min)
        {
            min_val = left_min;
        }
        else
        {
            min_val = right_min;
        }
    }
}