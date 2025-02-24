#include <bits/stdc++.h>

using namespace std;

void recursion(string& str, int i, int j, int n, vector<char>& buff){
    if (i == n){
        //buff[j] = '\0';
        for(int k = 0; k < buff.size(); ++k){
            cout<<buff[k];
        }
        cout<<"\n";
        return;
    }
    buff[j] = str[i];
    recursion(str,i+1,j+1,n,buff);

    buff[j] = ' ';
    buff[j+1] = str[i];
    recursion(str,i+1,j+2,n,buff);


}

void printAllStr(string& str, int n)
{

    vector<char> buff(2*n, ' ');
    buff[0] = str[0];

    recursion(str,1,1,n,buff);
}
int main(){

    string str = "abcdefghiksfgsdfgergvdfbsdfgsdfgsdgsfd";
    int n = str.size();
    printAllStr(str,n);
}
