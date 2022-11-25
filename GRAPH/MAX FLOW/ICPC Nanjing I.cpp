
struct Edge {
    int u, v;
    ll cap, flow;
    Edge() {}
    Edge(int _u, int _v, ll _cap): u(_u), v(_v), cap(_cap), flow(0) {}
};

struct Dinic {
    int N;
    vector<Edge> E;
    vector<vector<int>> g;
    vector<int> d, pt;
    Dinic(int _N): N(_N), E(0), g(_N), d(_N), pt(_N) {}
    void AddEdge(int u, int v, ll cap) {
        if (u != v) {
            E.emplace_back(Edge(u, v, cap));
            g[u].emplace_back(E.size() - 1);
            E.emplace_back(Edge(v, u, 0));
            g[v].emplace_back(E.size() - 1);
        }
    }
    bool BFS(int S, int T) {
        queue<int> q({S});
        fill(d.begin(), d.end(), N + 1);
        d[S] = 0;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            if (u == T) break;
            for (int k: g[u]) {
                Edge &e = E[k];
                if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
                    d[e.v] = d[e.u] + 1;
                    q.emplace(e.v);
                }
            }
        }
        return d[T] != N + 1;
    }
    ll DFS(int u, int T, ll flow = -1) {
        if (u == T || flow == 0) return flow;
        for (int &i = pt[u]; i < sz(g[u]); ++i) {
            Edge &e = E[g[u][i]];
            Edge &oe = E[g[u][i]^1];
            if (d[e.v] == d[e.u] + 1) {
                ll amt = e.cap - e.flow;
                if (flow != -1 && amt > flow) amt = flow;
                if (ll pushed = DFS(e.v, T, amt)) {
                    e.flow += pushed;
                    oe.flow -= pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }

    ll MaxFlow(int S, int T) {
        ll total = 0;
        while (BFS(S, T)) {
            fill(pt.begin(), pt.end(), 0);
            while (ll flow = DFS(S, T))
                total += flow;
        }
        return total;
    }
};


void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	Dinic g(n+m+4);
	rep(i,0,n){
		int p;
		cin>>p;
		rep(j,0,p){
			int temp;
			cin>>temp;
			temp--;
			g.AddEdge(i,n+temp,1);
		}
	}
	g.AddEdge(n+m,n+m+1,n);
	g.AddEdge(n+m,n+m+2,k);
	rep(i,0,n){
		g.AddEdge(n+m+1,i,1);
		g.AddEdge(n+m+2,i,1);
	}
	rep(i,0,m){
		g.AddEdge(n+i,n+m+3,1);
	}
	cout<<g.MaxFlow(n+m,n+m+3)<<endl;
}


