#include <bits\stdc++.h>
using namespace std;
string s;
vector<string> ans;

string ts(string ex){
    int n = ex.size();
    int id = 0;
    while(id+1<n && ex[id]=='0') id++;
    return ex.substr(id);
}

int main(){
    cin>>s;
    int sum = 0, flag = 0;
    int len = s.length();
    for(int i=0;i<len;i++){
        sum  = (sum + s[i]-'0') % 3;
        if(s[i] == '0') flag = 1;
    }
    if(sum==0){
        cout<<s<<endl;
        return 0;
    }
    for(int i=len-1;i>=0;i--){
        int x = s[i]-'0';
        if(x%3 == sum ){
            string t = s.substr(0,i) + s.substr(i+1);
            t = ts(t);
            if(!t.empty()){
                ans.push_back(t);
                break;
            }
        }
    }
    int k = -1;
    for(int i=len-1;i>=0;i--){
        int x= s[i]-'0';
        if(x%3==0 || x%3 == sum) continue;
        if(k==-1) {
            k = i;
            continue;
        }
       string str = s.substr(0,i);                  // 0 i-1
       if(i+1 != k) str += s.substr(i+1,k-i-1);    // i+1 k-1
       if(k+1 < len) str += s.substr(k+1);          // k+1
        str = ts(str);
        if(!str.empty()) {
          ans.push_back(str);
        };
        break;
    }
    if(ans.empty()) {
        if(flag) printf("0\n");
        else printf("-1\n");
    }
    else{
        string ss;
        int lens = ans.size(), leng = 0;
        for(int i=0;i<lens;i++){
            if(ans[i].length() > leng ){
                ss = ans[i];
                leng = ans[i].length();
            }
        }
        cout<<ss<<"\n";
    }
    return 0;
}
