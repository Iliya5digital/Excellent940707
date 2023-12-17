#include<bits/stdc++.h>
using namespace std;
bool check(int count_two, int cnt[]){

    bool is_zero=1;
    for(int i=0;i<34;++i){
        if(cnt[i]>0){
            is_zero=0;
            break;
        }
    }
    if(is_zero)return 1;

    bool valid=0;
    for(int i=0;i<34;++i){
        if(cnt[i]>=3){
            cnt[i]-=3;
            valid |= check(count_two, cnt);
            cnt[i]+=3;
        }
    }
    if(count_two>0){
        for(int i=0;i<34;++i){
            if(cnt[i]>=2){
                cnt[i]-=2;
                valid |= check(count_two-1, cnt);
                cnt[i]+=2;
            }
        }
    }
    for(int i=0;i<=6;++i){
          if(cnt[i]>0&&cnt[i+1]>0&&cnt[i+2]>0){
               cnt[i]-=1;
               cnt[i+1]-=1;
               cnt[i+2]-=1;
               valid |= check(count_two, cnt);
               cnt[i]+=1;
               cnt[i+1]+=1;
               cnt[i+2]+=1;
          }
     }
     for(int i=9;i<=15;++i){
          if(cnt[i]>0&&cnt[i+1]>0&&cnt[i+2]>0){
               cnt[i]-=1;
               cnt[i+1]-=1;
               cnt[i+2]-=1;
               valid |= check(count_two, cnt);
               cnt[i]+=1;
               cnt[i+1]+=1;
               cnt[i+2]+=1;
          }
     }
     for(int i=18;i<=24;++i){
          if(cnt[i]>0&&cnt[i+1]>0&&cnt[i+2]>0){
               cnt[i]-=1;
               cnt[i+1]-=1;
               cnt[i+2]-=1;
               valid |= check(count_two, cnt);
               cnt[i]+=1;
               cnt[i+1]+=1;
               cnt[i+2]+=1;
          }
     }
     for(int i=27;i<=31;++i){
          if(cnt[i]>0&&cnt[i+1]>0&&cnt[i+2]>0){
               cnt[i]-=1;
               cnt[i+1]-=1;
               cnt[i+2]-=1;
               valid |= check(count_two, cnt);
               cnt[i]+=1;
               cnt[i+1]+=1;
               cnt[i+2]+=1;
          }
     }
    return valid;
}
int main() {
     int num,cnt[34]={0};
     for(int i=0;i<17;++i){
        cin>>num;
        cnt[num]+=1;
     }
     cout<<check(1,cnt)<<'\n';
    return 0;
}