#include<iostream>
using namespace std;
 
char a[500][500];
int Gc=0;
void floodfill(int r, int c, int n, int m){
	if ((r < 0 || r >= n || c < 0 || c >= m)|| a[r][c] =='#'){
		return;
	}
	if(a[r][c]=='G'){
		Gc--;
	}
	a[r][c] = '#';
	floodfill(r, c + 1, n, m);
	floodfill(r, c - 1, n, m);
	floodfill(r + 1, c, n, m);
	floodfill(r - 1, c, n, m);
}
 
int main(){
	int t;
	cin>>t;
	for(int k=0;k<t;k++){
		int n, m, var=1;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>a[i][j];
				if(a[i][j]=='G'){
					Gc++;
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(a[i][j]=='B'){
					if(a[i-1][j]=='.'){
						a[i-1][j]='#';
					}
					if(a[i+1][j]=='.'){
						a[i+1][j]='#';
					}
					if(a[i][j-1]=='.'){
						a[i][j-1]='#';
					}
					if(a[i][j+1]=='.'){
						a[i][j+1]='#';
					}
					if(a[i-1][j]=='G'){
						var=0;
					}
					if(a[i+1][j]=='G'){
						var=0;
					}
					if(a[i][j-1]=='G'){
						var=0;
					}
					if(a[i][j+1]=='G'){
						var=0;
					}
				}
			}
		}
		if(a[n-1][m-1]=='.'){
			a[n-1][m-1]='G';
			Gc++;
		}
		if(var==0){
			cout<<"No";
		}
		if(var==1){	
			if(a[n-1][m-1]!='G'){
				if(Gc==0){
					cout<<"Yes";
				}
				else{
					cout<<"No";
				}
			}
			if(a[n-1][m-1]=='G'){
				floodfill(n-1,m-1,n,m);
				if(Gc==0){
					cout<<"Yes";
				}
				else{
					cout<<"No";
				}
			}
		}
		cout<<endl;
		Gc=0;
	}
}
