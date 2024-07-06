#include<iostream>
using namespace std;

int main()
{
    int numberOfLaptops, price, quality, result = 0;
    cin >> numberOfLaptops;

    for(int i = 0; i < numberOfLaptops; i++)
    {
        cin >> price >> quality;
        if(price != quality)
        {
            result = 1;
        }
    }

    if(result == 1)
    {
        cout << "Happy Alex\n";
    }
    else
    {
        cout << "Poor Alex\n";
    }

    return 0;
}
