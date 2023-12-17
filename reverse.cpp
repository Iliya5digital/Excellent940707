#include <bits/stdc++.h>
using namespace std;
vector<string> reverse(vector<string> v){
    int n=v.size();
    if(n<=1)return v;
    vector<string> result, tmp;
    result.push_back(v[n-1]);
    v.pop_back();
    tmp = reverse(v);
    result.insert(result.end(), tmp.begin(), tmp.end());
    return result;
}
int main() {
    vector<string> s;
    stringstream s1;
    string line, tmp;
    getline(cin, line);
    s1.clear();
    s1<<line;
    while(s1>>tmp){
        s.push_back(tmp);
    }
    s = reverse(s);
    for(auto e:s)cout<<e<<' ';
    return 0;
}