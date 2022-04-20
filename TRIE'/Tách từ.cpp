Trie *root = getnode();
    cin>>s>>n; 
    int len=s.size();
    for(int i=1;i<=n;i++){
        cin>>x;
        insert(root,x);
    }
    dp[len]=1;
    for(int i=len-1;i>=0;i--){
        Trie *p=root;
        for(int j=i;j<len;j++){
            int t=s[j]-'a';
            if(p->children[t]==NULL)break;
            p=p->children[t];
            if(p->isendofword)dp[i]+=dp[j+1];
        }
        dp[i]%=mod;
    }
    cout<<dp[0]<<endl;
