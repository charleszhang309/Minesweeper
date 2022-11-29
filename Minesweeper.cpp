#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
using namespace std;
const int p[8][2]= {{0,1},{1,0},{-1,0},{0,-1},{1,1},{1,-1},{-1,-1}};
char c;
char xmp[21][21];
int mp[21][21],n,m,k,t1,t2;
bool mpb[21][21],bo[21][21];
void dfs0(int x, int y) {
	mpb[x][y]=1;
	for (int i=0;i<8;i++){
		if (x+p[i][0]<1 || x+p[i][0]>n || y+p[i][0]<1 || y+p[i][i]>m)
			continue;
		if(mp[x+p[i][0]][y+p[i][1]]==0) {
			xmp[x+p[i][0]][y+p[i][1]]='0';
			if(!mpb[x+p[i][0]][y+p[i][1]])
				dfs0(x+p[i][0],y+p[i][1]);
		}
		if(mp[x+p[i][0]][y+p[i][1]]>0)
			xmp[x+p[i][0]][y+p[i][1]]=mp[x+p[i][0]][y+p[i][1]]+'0';
	}
	return;
}
void bai(int x,int y) {
	system("cls");
	if(bo[x][y])
		return;
	bo[x][y]=1;
	system("color C");
	for(int k=1; k<=19; k++) {
		Sleep(260);
		system("cls");
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				cout<<xmp[i][j]<<" ";
				if(xmp[i][j]=='*')
					xmp[i][j]='_';
			}
			cout<<endl<<endl;
		}
		int j=y+k;
		for(int i=x-k; i<=x+k; i++) {
			if(i<1 || i>n || j<1 || j>m)
				continue;
			if(mp[i][j]==-1) {
				xmp[i][j]='*';
				for(int l=0; l<8; l++)
					xmp[i+p[l][0]][j+p[l][1]]='_';
			}
		}
		j=y-k;
		for(int i=x-k; i<=x+k; i++) {
			if(i<1 || i>n || j<1 || j>m)
				continue;
			if(mp[i][j]==-1) {
				xmp[i][j]='*';
				for(int l=0; l<8; l++)
					xmp[i+p[l][0]][j+p[l][1]]='_';
			}
		}
		int i=x+k;
		for(int j=x-k; j<=x+k; j++) {
			if(i<1 || i>n || j<1 || j>m)
				continue;
			if(mp[i][j]==-1) {
				xmp[i][j]='*';
				for(int l=0; l<8; l++)
					xmp[i+p[l][0]][j+p[l][1]]='_';
			}
		}
		i=x-k;
		for(int j=x-k; j<=x+k; j++) {
			if(i<1 || i>n || j<1 || j>m)
				continue;
			if(mp[i][j]==-1) {
				xmp[i][j]='*';
				for(int l=0; l<8; l++)
					xmp[i+p[l][0]][j+p[l][1]]='_';
			}
		}
	}
	system("pause");
	system("color 7");
}
void win(){
	t2=time (0); 
	for (int k=1; k<=n;k++){
		Sleep(150);
		system("cls");
		for (int i=1;i<=m;i++){
			if (mp[k-1][i]>0)
				xmp[k-1][i]=mp[k-1][i]+'0';
			else
				xmp[k-1][i]='*';
			xmp[k][i]=45;
		}
		for (int i=1; i<=n;i++){
			for (int j=1;j<m;j++)
				cout <<  xmp[i][j] << " ";
		}
	} 
	system("cls");
	cout << "Game success, total time: " << t2-t1 << " seconds" << endl<< endl;
	system ("pause");
	system ("cls"); 
}
void game(){
	memset(mp,0,sizeof mp);
	memset(mpb,0,sizeof mpb);
	while (1){
		system("cls");
		cout << "Please enter the length: (>=5,<=20)" << endl;
		cin >>m;
		if (m<5 ||m>20){
			cout << "The number you entered is too large or too small. Please enter again" << endl;
			Sleep(1200);
		}
		else
			break;
	}
	while (1){
		system("cls");
		cout << "Please enter the width: (>=5,<=12)" << endl;
		cin >>n;
		if (n<5 || n>12){
			cout << "The number you entered is too large or too small. Please enter again" << endl;
			Sleep(1200);
		}
		else
			break;
	}
	while (1){
		system("cls");
		cout << "Please enter number of mines: (>=5,<=" << n*m-5<< " )" << endl;
		cin >>k;
		if (k<5 || k>n*m-5){
			cout << "The number you entered is too large or too small. Please enter again" << endl;
			Sleep(1200);
		}
		else
			break;
	}
	system("cls");
	for (int i=1;i<=3;i++){
		cout << "Initializing.";
		Sleep(280);
		cout << ".";
		Sleep(280);
		cout << "." ;
		Sleep (280);
		system("cls");
	}
	srand((unsigned)time(NULL));
	for(int i=1; i<=k; i++) {
		int x=rand()%n+1,y=rand()%m+1;
		if(mp[x][y]==-1) {
			i--;
			continue;
		} else
			mp[x][y]=-1;
	}
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++) {
			if(mp[i][j]==-1)
				continue;
			for(int k=0; k<8; k++)
				if(mp[i+p[k][0]][j+p[k][1]]==-1)
					mp[i][j]++;
		}
	char s[21][21];
	for(int i=1; i<=20; i++)
		for(int j=1; j<=20; j++) {
			s[i][j]=' ';
			xmp[i][j]=22;
		}
	int x=1,y=1,sum=0;
	bool o=0,f=0,fir=0;
	while(1) {
		sum=0;
		system("cls");
		s[x][y]='<';
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				if(xmp[i][j]==127)
					sum++;
				cout<<xmp[i][j]<<s[i][j];
			}
			cout<<endl<<endl;
		}
		cout<<"Remaining mines: "<<k-sum;
		if(o) {
			Sleep(2000);
			bai(x,y);
			system("cls");
			cout<<"Game over!";
			Sleep(2500);
			system("cls");
			return;
		}
		c=getch();
		switch(c) {
			case 'w': {
				s[x][y]=' ';
				if(--x<1)
					x=n;
				break;
			}
			case 's': {
				s[x][y]=' ';
				if(++x>n)
					x=1;
				break;
			}
			case 'a': {
				s[x][y]=' ';
				if(--y<1)
					y=m;
				break;
			}
			case 'd': {
				s[x][y]=' ';
				if(++y>m)
					y=1;
				break;
			}
			case 'j': {
				if(!fir) {
					t1=time(0);
					fir=1;
				}
				if(mp[x][y]==-1) {
					if(!f) {
						f=1;
						cout<<endl<<"This is a mine! (Just one reminder)";
						Sleep(2000);
					} else {
						xmp[x][y]='*';
						o=1;
					}
				}
				if(mp[x][y]==0) {
					xmp[x][y]='0';
					dfs0(x,y);
				}
				if(mp[x][y]>0)
					xmp[x][y]=mp[x][y]+'0';
				bool bo=0;
				for(int i=1; i<=n; i++) {
					for(int j=1; j<=m; j++) {
						if(mp[i][j]==-1)
							continue;
						if(xmp[i][j]!=mp[i][j]+'0')
							bo=1;
					}
				}
				if(bo)
					break;
				win();
				return;
			}
			case 'k': {
				if(xmp[x][y]==22) {
					xmp[x][y]=127;
					break;
				}
				if(xmp[x][y]==127) {
					xmp[x][y]='?';
					break;
				}
				xmp[x][y]=22;
				break;
			}
		}
	}
}
int main() {
	HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle,&CursorInfo);
	SetConsoleCursorInfo(handle, &CursorInfo);
	cout<<"                           ----Welcome to the Minesweeper----";
	Sleep(2500);
	system("cls");
	for(int i=1; i<=2; i++) {
		cout<<"Loading.";
		Sleep(300);
		cout<<".";
		Sleep(300);
		cout<<".";
		Sleep(300);
		system("cls");
	}
	string s[3]= {" "," "," "};
	int now=0;
	while(1) {
		s[now]='<';
		cout<<"Level Editor "<<s[0]<<endl;
		cout<<"Game Tutorial "<<s[1]<<endl;
		cout<<"Exit "<<s[2]<<endl<<endl;
		cout<<"w: up; s: down£¬j: enter";
		c=getch();
		system("cls");
		switch(c) {
			case 'w': {
				s[now]=' ';
				if(--now<0)
					now=3;
				break;
			}
			case 's': {
				s[now]=' ';
				if(++now>3)
					now=0;
				break;
			}
			case 'j': {
				if(now==0)
					game();
				if(now==1) {
					system("cls");
					cout<<"Use WASD to Control the selected cells"<<endl;
					cout<<"click j to open the cell and double click k to mark the Mine-box"<<endl;
					cout<<"The first time you hit Mine, you'll get a warning"<<endl<<endl;
					system("pause");
					system("cls");
				}
				if (now==2)
					return 0;
				break;
			}
		}
	}
}

