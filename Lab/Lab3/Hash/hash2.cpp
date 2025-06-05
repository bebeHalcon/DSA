#include<iostream>
#include<cmath>
using namespace std;

int foldShift(long long key, int addressSize)
{
    string temp = to_string(key);
    int n = temp.size();
    int res = 0;
    for (int i=0; i<n; i++)
    {
        int sum = 0;
        for (int j=0; j<addressSize; j++)
        {
            sum = sum*10 + temp[i] - '0';
            i++;
            if (i == n) break;
        }
        i--;
        res += sum;
    }
    int num_ = pow(10, addressSize);
    return res % num_;
}

int rotation(long long key, int addressSize)
{
    int last_digit = key%10;
    key /= 10;
    int len = to_string(key).size();
    key += last_digit * pow(10, len);
    
    int num_ = pow(10, addressSize);
    return foldShift(key, addressSize) % num_;
}

int main(){

    cout << rotation(600101, 2); // 26

}



