struct Trie{
    Trie *children [2];
    int count,f;
    bool isendofword;
};
Trie *getnode(){
    Trie *a=new Trie;
    a->isendofword=0;
    a->count=0;
    a->f=0;
    for(int i=0;i<2;i++){
        a->children[i]=NULL;
    }
    return a;
}
void insert(Trie *root,string s){
    Trie *a=root;
    for(int i=0;i<s.size();i++){
        int id=s[i]-'0';
        if(!a->children[id]){
            a->children[id]=getnode();
        }
        a=a->children[id];
    }
    a->count++;
    a->isendofword=1;
}
void solve(Trie *root,string s){
    Trie *a=root;
    int ans=0,i=0;
    for(i=0;i<s.size();i++){
        int id=s[i]-'0';
        if(!a->children[id])break;
        a=a->children[id];
        ans+=a->count;
    }
    if(i==s.size())ans+=a->f;
    cout<<ans<<endl;
}
int DFS(Trie *root){
    if(root==NULL)return 0;
    root->f=DFS(root->children[0])+DFS(root->children[1]);
    return root->f+root->count;
}
string init(){
    string s="";
    int len;char x;
    cin>>len;
    for(int i=0;i<len;i++){
        cin>>x;s+=x;
    }
    return s;
}
//
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    Trie *root=getnode();
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string s=init();
        insert(root,s);
    }
    DFS(root);
    while(m--){
        string s=init();
        Trie *a=root;
        solve(a,s);
    }
    return 0;
}
