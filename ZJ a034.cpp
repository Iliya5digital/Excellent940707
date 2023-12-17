#include<iostream>
using namespace std;
int main(){
    long long n,ans,tmp;
    while(cin>>n){
        ans=0,tmp=1;
        for(n;n>0;n/=2){
            ans+=(n%2)*tmp;//每次取餘數
            tmp*=10;//計算位數
        }
        cout<<ans<<'\n';
    }
    return 0;
}