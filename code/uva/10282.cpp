#include <bits/stdc++.h>
using namespace std;
struct Trie {
  Trie * next[30];
  string word;
  int ok;
  Trie() {
    ok = 0;
    memset(next, 0, sizeof(next));
  }
};
Trie * head;
void insert(string w, string s)
{
  Trie * p = head;
  for (int i = 0; i < s.size(); i++) {
    int c = s[i] - 'a';
    if (p->next[c] == NULL) {
      p->next[c] = new Trie();
    }
    p = p->next[c];
  }
  p->ok = 1;
  p->word = w;
}
void search(string s)
{
  Trie * p = head;
  for (int i = 0; i < s.size(); i++) {
    int c = s[i] - 'a';
    if (p->next[c] == NULL) {
      cout << "eh" << endl;
      return;
    }
    p = p->next[c];
  }
  if (p->ok) 
    cout << p->word << endl;
  else
    cout << "eh" << endl;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  head = new Trie();
  string str;
  while (getline(cin, str)) {
    stringstream ss(str);
    int cnt = 0;
    string tmp[5];
    while (ss >> tmp[cnt]) {
      cnt++;
    }
    if (tmp[0] == "")
      continue;
    if (cnt == 2) {
      insert(tmp[0], tmp[1]);
    } else {
      search(tmp[0]);
    }
  }
  return 0;
}