#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;

const int MAX_V = 100000;
const ll INF = (ll)1e18;

struct info {
	int to;
	ll weight;
	bool operator<(const info &o) const {
		return weight > o.weight;
	}
};

ll dist[MAX_V + 1];
vector<info> adj[MAX_V + 1];

ll dijkstra(int n)
{
	fill(dist, dist + n + 1, INF);
	priority_queue<info> pq;
	pq.push({ 1, 0 });
	dist[1] = 0;

	while (!pq.empty())
	{
		info cur = pq.top();
		pq.pop();

		if (cur.weight > dist[cur.to])
			continue;

		for (info &nxt : adj[cur.to])
		{
			if (dist[cur.to] + nxt.weight < dist[nxt.to])
			{
				dist[nxt.to] = dist[cur.to] + nxt.weight;
				pq.push({ nxt.to, dist[nxt.to] });
			}
		}
	}

	return dist[n] >= INF ? -1 : dist[n];
}

int main()
{
	int v, e;
	scanf("%d%d", &v, &e);
	for (int i = 0; i < e; i++)
	{
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		adj[a].push_back({ b, w });
	}

	printf("%lld\n", dijkstra(v));
}
