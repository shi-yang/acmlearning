#include <bits/stdc++.h>
using namespace std;
map<char, char> map1;
map<char, bool> map2;
int main()
{
    string s, t;
    cin >> s >> t;
    int len = s.size();
    int ans = 0;
    for (int i = 0; i < len; i++) {
        if (map1[s[i]] == NULL && map1[t[i]] == NULL) {
            map1[s[i]] = t[i];
            map1[t[i]] = s[i];
            if (s[i] != t[i]) {
                ans++;
                map2[s[i]] == 0;
            }
        } else if (map1[s[i]] != t[i]){
            ans = -1;
            break;
        }
    }
    cout << ans << endl;
    if (ans != -1) {
        for (int i = 0; i < len; i++) {
            if (s[i] != t[i] && !map2[s[i]] && map1[s[i]] != NULL) {
                cout << s[i] << ' ' << t[i] << endl;
                map1[s[i]] = map1[t[i]] = NULL;
                map2[s[i]] = 1;
            }
        }
    }
    return 0;
}
