#include<bits/stdc++.h>
using namespace std;




cols = (60 - max) / (max + 2) + 1
rows = (n - 1) / cols + 1;
rep(int i = 0; i < rows; i++)
  rep(c 0, cols, ++)
    int idx = c * rows + r;
    if (idx < n)
      cout filename[idx], c == cols - 1 ? max : max + 2












int main()
    int n,i;
    while(cin>>n) {
        string st;
        vector<string>s;
        int cnt=0;
        for( i=0;i<n;i++) {
            cin>>st;
            int z=st.length();
            cnt=max(cnt,z);
            s.push_back(st);
        }
        sort(s.begin(),s.end());

        cout<<'\n';
        int col,row;
        col=((60-cnt)/(cnt+2))+1;
        if(n%col==0)row=n/col;
        else row=(n/col)+1;
        int k,j;
        for( i=0;i<row;i++) {
            for(j=0;j<col;j++) {
                k=j*row+i;
                if(k<n){
                  if(i==col-1) {
                      cout<<s[k];
                      for(int jj=0;jj<cnt-s[k].length();jj++)
                        cout<<' ';
                  } else {
                      cout<<s[k];
                      int nn=cnt+2-s[k].length();
                      for(int jj=0;jj<cnt+2-s[k].length();jj++)
                        cout<<' ';
                  }
                }
            }
            printf("\n");
        }

    }
    return 0;
}
