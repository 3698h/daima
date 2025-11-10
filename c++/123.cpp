#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1,3,5,7,9};
    int *p = arr;
    for (int i = 0; i <5; i++)
    {
        cout << *(p + i) << " "<<endl;
        p++;
    }
}