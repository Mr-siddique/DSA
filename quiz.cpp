#include <iostream>
#include <vector>
#include<cstring>
using namespace std;
const char hashTable[10][5] = {"", "", "abc", "def", "ghi", "jkl",
                               "mno", "pqrs", "tuv", "wxyz"};
void digits(int arr[], string output, int index, int n, vector<string> &res)
{
    if (index == n)
    {
        res.push_back(output);
        return;
    }
    for(int i=0;i<strlen(hashTable[arr[index]]);i++){
        output+=hashTable[arr[index]][i];
        digits(arr,output,index+1,n,res);
        output.pop_back();
        if(arr[index]==0||arr[index]==1)
        return;
    }
}

int main()
{
    // print(1000);
    // getchar();
    int arr[]={3, 4, 5};
    vector<string>res;
digits(arr,"",0,3,res);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }   
    return 0;
}