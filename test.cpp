#include<bits/stdc++.h>
using namespace std;
struct hb
{
	int g,l;
	bool used;
	hb(int x=0,int y=0,bool used=false):g(x),l(y),used(used){}
};
bool cmp(hb a,hb b)
{
	if(a.l==b.l) return a.g<b.g;
	return a.l>b.l;
}
int n,k,sumw=0,mxl=0,suml=0;
int main() {
	cin>>n>>k;
	vector<hb> a;
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		hb b(x,y);
		a.push_back(b);
	}
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<n;i++){
		if(a[i].used) continue;
		sumw=a[i].g;
		a[i].used=true;
		for(int j=i+1;j<n;j++){
			if(sumw+a[j].g<=k and !a[j].used){
				sumw+=a[j].g;
				a[j].used=true;
			}
		}
		suml+=a[i].l*2;
	}
	cout<<suml;
	return 0;
}
