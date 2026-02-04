#include <bits/stdc++.h>
using namespace std;

// Time - o(length of string)
// space - o(1) no extra space used
int binaryToDecimal(string binary)
{
    int len = binary.length();
    int p2 = 1;
    int res = 0;
    for (int i = len - 1; i >= 0; --i)
    {
        if (binary[i] == '1')
            res += p2;
        p2 *= 2;
    }
    return res;
}

int main()
{
    string binary;
    cin >> binary;
    cout << binaryToDecimal(binary);
}