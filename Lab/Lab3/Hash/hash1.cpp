#include<iostream>
using namespace std;

long int midSquare(long int seed)
{
    seed = seed * seed;
    seed /= 100;
    return seed % 10000;
}
long int moduloDivision(long int seed, long int mod)
{
    return seed % mod;
}
long int digitExtraction(long int seed,int* extractDigits,int size)
{
    string temp = to_string(seed);
    long int res = 0;
    for (int i=0; i<size; i++)
    {
        res = res * 10 + temp[extractDigits[i]] - '0';
    }
    return res;
}

int main(){

    int a[]={1,2,5};
    cout << digitExtraction(122443,a,3) << endl; // 223

    cout <<midSquare(9452); // 3403

}