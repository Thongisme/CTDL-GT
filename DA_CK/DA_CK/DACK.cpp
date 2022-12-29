#include <bits/stdc++.h>

#include <iostream>
#include <iomanip>

using namespace std;


int ToHop(int n, int k)
{
    if (k == 0 || k == n)
        return 1;
    return (ToHop(n - 1, k - 1) + ToHop(n - 1, k));
}

float Bernoulli(int n)
{
    if (n == 0)
        return 1;
    else
    {
        float t = 1;
        for (int i = 0; i < n; i++)
            t += ToHop(n, i) * Bernoulli(i) / (n - i + 1);
        return float(1 - t);
    }
}

float Tangent(int i)
{
    return float((pow(2, 2 * i) * (pow(2, 2 * i) - 1) * abs(Bernoulli(2 * i))) / (2 * i));
}

void TBernoulli()
{
    for (size_t n = 0; n <= 15; n += n >= 2 ? 2 : 1)
    {

        cout << "B(" << right << setw(1) << n << ") = ";
        cout << right << setw(44) << Bernoulli(n) << endl;   
    }
}

void TTangent()
{
    for (int n = 1; n<= 10; n++)
    {
        cout << "T(" << right << setw(1) << n << ") = ";
        cout << right << setw(44) << Tangent(n) << endl;
    }
}

int EulerNumbers(int  n)
{
    if (n == 0)
        return 1;
    else
    {
        float t = 0;
        for (int i = 0; i < n; i++)
            t += ToHop(n, i) * EulerNumbers(i) * pow(2, (n - i - 1));
        return float(1 - t);
    }
}
void TEulerNumbers()
{
    for (int n = 0; n < 15; n++)
    {
        if (EulerNumbers(n) != 0)
        {
            cout << "E(" << right << setw(1) << n << ") = ";
            cout << right << setw(44) << abs(EulerNumbers(n)) << endl;
        }
    }
}
int main()
{
    cout << "Bernoulli Number \n";
    TBernoulli();
    cout << endl;
    cout << "Tangent Number \n";
    TTangent();
    cout << endl;
    cout << "Euler Number \n";
    TEulerNumbers();
    return 1;
}
