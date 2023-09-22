#include <iostream>
using namespace std;

int maxmin(int i, int Arr[], int j, int &max, int &min);
int main()
{
    int unimax = INT32_MIN, unimin = INT32_MAX;
    int array[] = {41, 4, -4, 25, 24, 12, 24};
    maxmin(0, array, 6, unimax, unimin);
    cout << unimax << endl;
    cout << unimin << endl;
    return 0;
}
int maxmin(int i, int Arr[], int j, int &max, int &min)
{
    if (i == j)
    {
        max = Arr[i];
        min = Arr[i];
    }
    else if ((j - i) == 1)
    {
        if ((Arr[i] < Arr[j]))
        {
            max = Arr[j];
            min = Arr[i];
        }
        else
        {
            min = Arr[j];
            max = Arr[i];
        }
    }
    else
    {
        int mid = (i + j) / 2;
        int leftmax, leftmin, rightmax, rightmin;
        maxmin(i, Arr, mid, leftmax, leftmin);
        maxmin(mid + 1, Arr, j, rightmax, rightmin);

        if (leftmax > rightmax)
        {
            max = leftmax;
        }
        else
        {
            max = rightmax;
        }

        if (leftmin < rightmin)
        {
            min = leftmin;
        }
        else
        {
            min = rightmin;
        }
    }
}