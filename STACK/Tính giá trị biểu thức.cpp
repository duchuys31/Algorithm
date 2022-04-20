#include<bits/stdc++.h>
using namespace std; 
//S31[:v]
#define int long long 
#define fi first
#define se second
typedef pair <int,int> ii;
typedef vector<int> v;
int di[]={-1,0,0,1,-1,-1,1,1};
int dj[]={0,-1,1,0,-1,1,-1,1};
//
int solve(int a,int b,char c){
    if(c=='+')return a+b;
    if(c=='-')return a-b;
    if(c=='*')return a*b;
    return a/b;
}
int check(char c){
    if(c=='(') return 0;
	if(c=='+'||c=='-') return 1;
     return 2;
}
string convert(string s){
    string res="";
    stack <char> st;
    int i=0;
    while(i<s.size()){
        char c=s[i];
        if(c>='0'&&c<='9')res+=c;
        else{
            res+=' ';
            if(c=='(')st.push(c);
            else{
                if(c==')'){
                    while(st.top()!='('){
                        res+=st.top();
                        st.pop();
                    }
                    st.pop();
                }
                else{
                    while(!st.empty()&&check(st.top())>=check(c)){
                        res+=st.top();
                        st.pop();
                    }
                    st.push(c);
                }
            }
        }
        i++;
    }
    while(!st.empty()){
		res+=st.top();
		st.pop();
	}
	return res;
}
void solution(string s){
    vector<int> st;
	for(int i = 0;i<s.size();){
		int sum = 0;
		bool check = true;
		while(s[i]-'0'>=0&&s[i]-'0'<=9){
			check = false;
			sum = sum*10+ (s[i]-'0');
			i++;
		}
		if(check == false)st.push_back(sum);	
		if(s[i]==' ') i++;
		if(s[i]=='*'||s[i]=='/'||s[i]=='+'||s[i]=='-'){
			int x = st.back();
			st.pop_back();
			int y = st.back();
			st.pop_back();
			if(s[i]=='+') st.push_back(x+y);
			if(s[i]=='-') st.push_back(y-x);
			if(s[i]=='*') st.push_back(y*x);
			if(s[i]=='/') st.push_back(y/x);
			i++;
		}
 
	}
	cout<<st.back()<<endl;
}
// 
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        s=convert(s);
        // cout<<s<<endl;
        solution(s);
       
    }
    return 0;
}
//TheEnd
