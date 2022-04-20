int n;
string s[N];
int dp[N];
const int size=27;
struct Trie{
    Trie *children [size];
    bool isendofword;
};
Trie *getnode(){
    Trie *a=new Trie;
    a->isendofword=0;
    for(int i=0;i<size;i++){
        a->children[i]=NULL;
    }
    return a;
}
void insert(Trie *root,string s){
    Trie *a=root;
    for(int i=0;i<s.size();i++){
        int id=s[i]-'a';
        if(!a->children[id]){
            a->children[id]=getnode();
        }
        a=a->children[id];
    }
    a->isendofword=1;
}
int search(Trie *root,string s){
    int ans=0;
    Trie *a=root;
    for(int i=0;i<s.size();i++){
        int id=s[i]-'a';
        if(!a->children[id])return ans;
        a=a->children[id];
        if(i!=s.size()-1&&a->isendofword)ans++;
    }
    return ans;
}
bool cmp(string x,string y){
    return (x.size()<y.size());
}
//
main(){
    Trie *root=getnode();
    cin>>n;
    for(int i=1;i<=n;i++)cin>>s[i];
    sort(s+1,s+n+1,cmp);
    for(int i=1;i<=n;i++){
        dp[i]=search(root,s[i])+1;
        insert(root,s[i]);
    }
    cout<<*max_element(dp+1,dp+n+1);
    return 0;
}
