/* 
 * Args:
 *   edge: edges of graph, (u, v, w) = (edge[i].second.first, edge[i].second.first, edge[i].first)
 *   n: number of node, from 1 to n
 * Return:
 *   minimum spanning tree
 */
vector<pair<int, pair<int, int> > > edge;
int pre[N];
int find(int u)
{
  return u == pre[u] ? u : pre[u] = find(pre[u]);
}
int Union(int u, int v)
{
  pre[find(u)] = find(v);
}
int kruskal(int n) 
{
  for (int i = 1; i <= n; i ++) pre[i] = i;
  sort(edge.begin(), edge.end());
  int ans = 0;
  for (auto x : edge) {
    int u = x.second.first, v = x.second.second, w = x.first;
    if (find(u) != find(v)) {
      Union(u, v);
      ans += w;
    }
  }
  return ans;
}
