//Tìm số N nhỏ nhất thỏa mãn: A là tổng các chữ số của N, B là tổng bình phương các chữ số của N. 
int dp[101][10001];
int mind(int a,int b){
    if(a<0||b<0||a>100||b>10001)return -1;
    if(a==0&&b==0)return 0;
    if(dp[a][b]!=-1)return dp[a][b];
    int ans=101;
    for(int i=9;i>=1;i--){
        int k=mind(a-i,b-i*i);
        if(k!=-1)ans=min(ans,k+1);
    }
    return dp[a][b]=ans;
}
void print(int a,int b){
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    int k=mind(a,b);
    if(k==-1||k>100)cout<<-1;
    else {
        while(a>0&&b>0){
            for(int i=1;i<=9;i++){
                if(a>=i&&b>=i*i&&dp[a][b]==dp[a-i][b-i*i]+1){
                    cout<<i;
                    a-=i;
                    b-=i*i;
                    break;
                }
            }
        }
    }
}
