#include<iostream>
#include<iomanip>
#include<algorithm>
#include<utility>
#include<vector>

using namespace std;
int N, M, R;

struct UnionFind
{
  vector<int> uf;
  UnionFind(int n) : uf(n) {
    for (int i = 0; i < n; i++) uf[i] = i;
  }
  
  int find(int x) {
    return (uf[x] == x) ? x : (uf[x] = find(uf[x]));
  }
  
  bool merge(int x, int y) {
    int res1 = find(x), res2 = find(y);
    if (res1 == res2) return false;
    uf[res2] = res1;
    return true;
  }
};

class Edge {
public:
   bool operator<(const Edge& e) const { return w > e.w; } //changed to revsort
   int v1, v2;
   int w; };

int solve(int n, vector<Edge> elist, int u, int v)
{
  UnionFind uf(n);
  sort(elist.begin(), elist.end());
  int i = 0;
  int mini = R;
  while(uf.find(u) != uf.find(v) and i < elist.size()){
     uf.merge(elist[i].v1, elist[i].v2);
     mini = min(R, elist[i++].w);
  }
  return (uf.find(u) == uf.find(v) ? mini : -1);
}

int overlap(pair<int,int> g1, pair<int,int> g2){
   if(g1.second <= g2.first or g2.second <= g1.first)
      return 0;
   if(g1.first >= g2.first and g1.second <= g2.second)
      return g1.second - g1.first;
   if(g2.first >= g1.first and g2.second <= g1.second)
      return g2.second - g2.first;
   return min(g1.second - g2.first, g2.second - g1.first);
}

int main()
{  
   cin >> N >> M >> R;
   pair<int,int> Car[105][105], Gap[105][105];
   int pos[105], pos2[105];
   fill(pos, pos+105, 0);
   fill(pos2, pos2+105, 0);
   pair<int,int> ACM;
   for(int i = 0; i < M; i++){
      int lane_num, length, dis_start;
      cin >> lane_num >> length >> dis_start;
      if(i == 0)
	 ACM = make_pair(dis_start, dis_start+length);
      else
	 Car[lane_num][pos[lane_num]++] = make_pair(dis_start, dis_start+length);
   }
   for(int i = 0; i <= N; i++){
      Car[i][pos[i]++] = make_pair(R,R);
   }
   for(int i = 0; i <= N; i++){
      sort(Car[i], Car[i] + pos[i]);
      int low = 0,high;
      for(int j = 0; j < pos[i]; j++){
	 high = Car[i][j].first;
	 if(low != high){
	    Gap[i][pos2[i]++] = make_pair(low, high);
	 }
	 low = Car[i][j].second;
      }
   }

   int start;
   int potans;
   for(int j = 0; j < pos2[0]; j++){
      if( ACM.first >= Gap[0][j].first and ACM.second <= Gap[0][j].second){
	 start = j;
	 potans = min(ACM.first - Gap[0][j].first, Gap[0][j].second - ACM.second);
      }
   }

   vector<Edge> elist;
   for(int i = 1; i <= N; i++){
      for(int j = 0; j < pos2[i]; j++){
	 for(int k = 0; k < pos2[i-1]; k++){
	    int l = overlap(Gap[i][j], Gap[i-1][k]);
	    if( l > 0 ){
	       Edge e;
	       e.v1 = i*105 + j; e.v2 = (i-1)*105 + k; e.w = l;
	       elist.push_back(e);
	    }
	 }
      }
   }
   int ans = solve(105*N + 1, elist, start,105*N);
   if(ans == -1 or ans < ACM.second - ACM.first){
      cout << "Impossible" << endl;
   }
   else
      cout << fixed << setprecision(6) << min((double)(ans-ACM.second+ACM.first)/2.0, (double)potans) << endl;
   return 0;
}
