int x,y,ans;
int getx(int l,int r){
    l=max(l,0ll);
    r=min(r,x);
    return r-l+1;
}
int gety(int l,int r){
    l=max(l,0ll);
    r=min(r,y);
    return r-l+1;
}
void solve(int i,int j){
    ans+=getx(i-j,i-j+y)*gety(i+j-x,i+j)-1;
    ans+=getx(i+j-y,i+j)*gety(-i+j,-i+j+x)-1;
}
void solution(){
    cin>>x>>y;
    ans=0;
    for(int i=0;i<=x;i++){
        for(int j=0;j<=y;j++){
            solve(i,j);
        }
    }
    cout<<ans/2<<endl;
}

