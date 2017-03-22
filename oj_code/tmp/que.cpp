using namespace std;
deque<int> p[1005];
map<int,int> mp;
deque<int> que;
void init(int T){
    for(int i=1;i<=T;i++)
        p[i].clear();
    que.clear();
    mp.clear();
}
int main(){
    int T,G,A,cnt=0;
    while(scanf("%d",&T)&&T){
        printf("Scenario #%d\n",++cnt);
        init(T);
        for(int i=1;i<=T;i++){
            scanf("%d",&G);
            while(G--){
                scanf("%d",&A);
                mp[A]=i;
            }
        }
        char s[10];
        int B;
        while(scanf("%s",s)&&s[0]!='S'){
            if(s[0]=='E'){
                scanf("%d",&B);
                if(p[mp[B]].empty())
                    que.push_back(mp[B]);
                p[mp[B]].push_back(B);
            }
            else{
                int x=que.front();
                cout<<p[x].front()<<endl;
                p[x].pop_front();
                if(p[x].empty())
                    que.pop_front();
            }
        }
        printf("\n");
    }
    return 0;
}
