#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<pii>;
using qi = queue<int>;
using vvi = vector<vi>;
using vvii = vector<vii>;

constexpr auto inf = int{ 987654321 };

int solve(int d, const vvii& ve) {
	auto dist = vi(d + 1, inf);
	dist[0] = 0;

	auto q = qi{};
	q.push(0);

	while (!q.empty()) {
		auto f = q.front();
		q.pop();

		for (const auto& y : ve[f]) {
			const auto& next = y.first;
			const auto& nextDist = y.second;

			const auto& newDist = dist[f] + nextDist;
			if (newDist < dist[next]) {
				dist[next] = newDist;
				q.push(next);
			}
		}
	}

	return dist[d];
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, d; cin >> n >> d;

	auto ve = vvii(d + 1, vii{});
	for (auto i = 0; i < d; ++i) {
		ve[i].push_back({ i + 1, 1 });
	}

	while (0 < (n--)) {
		int a, b, c;
		cin >> a >> b >> c;

		if (b <= d) {
			ve[a].push_back({ b, c });
		}
	}

	const auto& ans = solve(d, ve);
	cout << ans;

	return 0;
}