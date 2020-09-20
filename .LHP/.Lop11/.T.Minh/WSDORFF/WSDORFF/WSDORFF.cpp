#include <iostream>
#include <iomanip>
#include <array>
#include <string>
#include <tuple>
#include <algorithm>
using namespace std;

int N, M, sx, sy;

template<int, int>
class Board
{
public:
	array<pair<int, int>, 8> moves;
	array<array<int, int>, int> data;

	Board()
	{
		moves[0] = make_pair(2, 1);
		moves[1] = make_pair(1, 2);
		moves[2] = make_pair(-1, 2);
		moves[3] = make_pair(-2, 1);
		moves[4] = make_pair(-2, -1);
		moves[5] = make_pair(-1, -2);
		moves[6] = make_pair(1, -2);
		moves[7] = make_pair(2, -1);
	}

	array<int, 8> sortMoves(int x, int y) const
	{
		array<tuple<int, int>, 8> counts;
		for (int i = 0; i < 8; ++i)
		{
			int dx = get<0>(moves[i]);
			int dy = get<1>(moves[i]);

			int c = 0;
			for (int j = 0; j < 8; ++j)
			{
				int x2 = x + dx + get<0>(moves[j]);
				int y2 = y + dy + get<1>(moves[j]);

				if (x2 < 0 || x2 >= N || y2 < 0 || y2 >= M)
					continue;
				if (data[y2][x2] != 0)
					continue;

				c++;
			}

			counts[i] = make_tuple(c, i);
		}

		// Shuffle to randomly break ties
		random_shuffle(counts.begin(), counts.end());

		// Lexicographic sort
		sort(counts.begin(), counts.end());

		array<int, 8> out;
		for (int i = 0; i < 8; ++i)
			out[i] = get<1>(counts[i]);
		return out;
	}

	void solve(const int sx, const int sy)
	{
		for (int v = 0; v < N; ++v)
			for (int u = 0; u < M; ++u)
				data[v][u] = 0;

		int x0 = sx - 1;
		int y0 = M - sy;
		data[y0][x0] = 1;

		array<tuple<int, int, int, array<int, 8>>, N* M> order;
		order[0] = make_tuple(x0, y0, 0, sortMoves(x0, y0));

		int n = 0;
		while (n < N * M - 1)
		{
			int x = get<0>(order[n]);
			int y = get<1>(order[n]);

			bool ok = false;
			for (int i = get<2>(order[n]); i < 8; ++i)
			{
				int dx = moves[get<3>(order[n])[i]].first;
				int dy = moves[get<3>(order[n])[i]].second;

				if (x + dx < 0 || x + dx >= N || y + dy < 0 || y + dy >= M)
					continue;
				if (data[y + dy][x + dx] != 0)
					continue;

				++n;
				get<2>(order[n]) = i + 1;
				data[y + dy][x + dx] = n + 1;
				order[n] = make_tuple(x + dx, y + dy, 0, sortMoves(x + dx, y + dy));
				ok = true;
				break;
			}

			if (!ok) // Failed. Backtrack.
			{
				data[y][x] = 0;
				--n;
			}
		}
	}

	template<int N>
	friend ostream& operator<<(ostream& out, const Board<N>& b);
};

template<int N, int M>
ostream& operator<<(ostream& out, const Board<N, M>& b)
{
	for (int v = 0; v < N; ++v)
	{
		for (int u = 0; u < M; ++u)
		{
			if (u != 0) out << ",";
			out << setw(3) << b.data[v][u];
		}
		out << endl;
	}
	return out;
}


bool check(const int n, const int m) {
	if (n > m) std::swap(n, m);
	if (n % 2 && m % 2) { cout << -1; return 0; }
	if ((n == 1 || n == 2 || n == 4) && (m != 1)) { cout << -1; return 0; }
	if (n == 3 && (m == 4 || m == 6 || m == 8)) { cout << -1; return 0; }
	return 1;
}


int main()
{
	std::cin >> N >> M >> sx >> sy;

	if (!check(N, M)) {
		std::cout << -1;
		return 0;
	}

	Board<N, M> b1;
	//b1.solve("c3");
	cout << b1 << endl;

	/*Board<8> b2;
	//b2.solve("b5");
	cout << b2 << endl;

	Board<31> b3; // Max size for <1000 squares
	//b3.solve("a1");
	cout << b3 << endl;
	return 0;*/
}