#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#define MAX 110000
#define LL long long
using namespace std;
LL n,m;
LL ans;
struct Tree
{
	LL l,r;
	LL add;
  LL mi;
	LL cmi;
};
Tree tree[MAX << 2];

void pushup(LL x)
{
	LL tmp=x << 1;
	tree[x].mi = min(tree[tmp].mi, tree[tmp+1].mi);
	tree[x].cmi = min(tree[tmp].cmi, tree[tmp+1].cmi);
}
void pushdown(LL x)
{
	LL tmp=x << 1;
	tree[tmp].add+=tree[x].add;
	tree[tmp+1].add+=tree[x].add;

	tree[tmp].mi += tree[x].add;
	tree[tmp + 1].mi += tree[x].add;

	tree[tmp].cmi =min(tree[tmp].cmi, tree[tmp].mi);
	tree[tmp + 1].cmi =min(tree[tmp + 1].cmi, tree[tmp + 1].mi);

	tree[x].add=0;
}
void build(LL l,LL r,LL x)
{
	tree[x].l=l;
	tree[x].r=r;
	tree[x].add=0;
	if(l==r)
	{
		scanf("%lld",&tree[x].mi);
    tree[x].cmi = tree[x].mi;
		return ;
	}
	LL tmp=x<<1;
	LL mid=(l+r)>>1;
	build(l,mid,tmp);
	build(mid+1,r,tmp+1);
	pushup(x);
}
void update(LL l,LL r,LL c,LL x)
{
	if(r<tree[x].l||l>tree[x].r)
		return ;
	if(l<=tree[x].l&&r>=tree[x].r)
	{
		tree[x].add+=c;
		tree[x].mi += c;
		tree[x].cmi = min(tree[x].mi, tree[x].cmi);
		return ;
	}
	if(tree[x].add)
		pushdown(x);
	LL tmp=x<<1;
	update(l,r,c,tmp);
	update(l,r,c,tmp+1);
	pushup(x);
}
void query(LL l,LL r,LL x)
{
	if(r<tree[x].l||l>tree[x].r)
		return ;
	if(l<=tree[x].l&&r>=tree[x].r)
	{
		ans = min(ans, tree[x].cmi);
		return ;
	}
	if(tree[x].add)
		pushdown(x);
	LL tmp=x<<1;
	LL mid=(tree[x].l+tree[x].r)>>1;
	if(r<=mid)
		query(l,r,tmp);
	else if(l>mid)
		query(l,r,tmp+1);
	else
	{
		query(l,mid,tmp);
		query(mid+1,r,tmp+1);
	}
}

int main()
{
  scanf("%lld", &n);
	build(1,n,1);
  scanf("%lld", &m);
	while(m--)
	{
    LL a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    update(a, b, c, 1);
    ans = 1e9;
    query(a, b, 1);
    printf("%lld\n", ans);
	}
	return 0;
}
