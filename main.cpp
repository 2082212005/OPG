#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cmath>

using namespace std;

const int maxn=1e4+5;

map<char,int> mp;
int a[6][6]={{0,1,1,1,0,0},{0,0,1,1,0,0},{0,0,3,3,0,0},{1,1,1,1,2,3},{0,0,3,3,0,0},{1,1,1,1,3,3}};//'>'Ϊ0,'<'Ϊ1,'='Ϊ2,' 'Ϊ3

void init()
{
    mp.clear();
    mp['+']=0;
    mp['*']=1;
    mp['i']=2;
    mp['(']=3;
    mp[')']=4;
    mp['#']=5;
}

int main(int argc,char* argv[])
{
    init();
	/*fstream file1;
	file1.open(argv[1]);*/
	string s="";
	/*file1>>noskipws;
	char ch;
	while(file1.peek()!=EOF)
    {
        ch=file1.get();
        s+=ch;
    }*/
    cin >> s;
    s+='#';
    string st;
    int i;
    for(i=0;i<s.length();)
    {
        if(i==0)
        {
            if(s[0]!='+'&&s[0]!='*'&&s[0]!='('&&s[0]!=')'&&s[0]!='i') 
            {
            	cout << "E";
                break;
			}
			st+=s[0];
            cout << "I" << s[0];
            i++;
        }
        else
        {
            cout << endl;
			if(s[i]!='+'&&s[i]!='*'&&s[i]!='('&&s[i]!=')'&&s[i]!='i'&&i!=s.length()-1) 
            {
           		cout << "E";
               	break;
			}
            int k;
            for(k=st.length()-1;k>=0&&st[k]=='N';k--)
                ;
            if(k<0)
            {
				st+=s[i];
                cout << "I" << s[i];
                i++;
            }
            else if(a[mp[st[k]]][mp[s[i]]]==1||a[mp[st[k]]][mp[s[i]]]==2)
            {
				st+=s[i];
                cout << "I" << s[i];
                i++;
            }
            else if(a[mp[st[k]]][mp[s[i]]]==0)
            {
                if(st[k]=='i')
                {
                    st=st.substr(0,k);
                    st+='N';
                    cout << "R";
                }
                else if(st[k]=='+'||st[k]=='*')
                {
                    if(st[k-1]=='N'&&st[k+1]=='N')
                    {
                        st=st.substr(0,k-1);
                        st+='N';
                        cout << "R";
                    }
                    else
                    {
                        cout << "RE";
                        break;
                    }
                }
                else if(st[k]==')')
                {
                    if(st[k-1]=='N'&&st[k-2]=='(')
                    {
                        st=st.substr(0,k-2);
                        st+='N';
                        cout << "R";
                    }
                    else
                    {
                        cout << "RE";
                        break;
                    }
                }
                if(st=="N"&&i==s.length()-1)
                {
                    break;
                }
            }
            else
            {
                cout << "E";
                break;
            }
        }
    }
    //file1.close();
    return 0;
}
