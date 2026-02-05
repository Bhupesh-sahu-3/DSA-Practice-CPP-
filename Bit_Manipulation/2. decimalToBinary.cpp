#include<bits/stdc++.h>
using namespace std;


//---------using vector to store the result-------
//o(log n) base2 time and o(log n) base2 space
vector<int> decimalToBinaryUsingVector(int num)
{
    vector<int>res;                       //o(log n) space   
    
    if(num ==0)
    return {0};

    while(num)                          //divide by 2 and store remainder   0(log n)
    {
        int rem = num%2;
        res.push_back(rem);
        num/=2;
    }
    reverse(res.begin(),res.end());     //reverse the vector  o(n) time
return res;
}


//------using a string--------
// o(log n) base 2 time and o(log n) base 2 space
string decimalToBinaryUsingString(int num)
{
    string res = "";
    if(num==0)
    return "0";

    while(num)
    {
        if(num%2==1)
        res+='1';
        else
        res+='0';
        num/=2;
    }
    reverse(res.begin(),res.end());
    return res;
}

int main()
{
    int num;
    cin>> num;

    // using vector to store
    vector<int>ans=decimalToBinaryUsingVector(num);
    for(auto it:ans)
    cout<<it<<" ";

    cout<<endl;
    //using string to store
    cout<<decimalToBinaryUsingString(num);

    
}