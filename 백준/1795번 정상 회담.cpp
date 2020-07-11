//#include <iostream>
//#include <string>
//#include <vector>
//#include <queue>
//#include <cstring>
//using namespace std;
//
//int row;
//int col;
//string map[50];
//int dx[] = { -1, 1, -2, 2, -2, 2, -1, 1 };
//int dy[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
//vector<pair<int, pair<int,int>>> night; // 말의 번호랑 시작 좌표 저장
//vector<int> ans[50][50];
//int sum[50][50];
//bool check[50][50];
//
//void bfs(int num, int x, int y) {
//	queue<pair<int, pair<int, int>>> q;
//	check[x][y] = true;
//	q.push({ 0,{x,y} });
//	while (!q.empty()) {
//		int fx = q.front().second.first;
//		int fy = q.front().second.second;
//		int fd = q.front().first;
//		ans[fx][fy].push_back(fd);
//		q.pop();
//		for (int i = 0; i < num; i++) {
//			for (int j = 0; j < 8; j++) {
//				int nx = fx + dx[j];
//				int ny = fy + dy[j];
//				int nd = fd + 1;
//				if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
//					if (check[nx][ny] == false) {
//						check[nx][ny] = true;
//						q.push({ nd,{nx,ny} });
//						ans[nx][ny].push_back(nd);
//						//bfs(nd, nx, ny);
//					}
//				}
//			}
//		}
//	}
//}
//
//int main() {
//	cin.sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> row >> col;
//	for (int i = 0; i < row; i++) {
//		cin >> map[i];
//		for (int j = 0; j < map[i].length(); j++) {
//			if (map[i][j] != '.') {
//				night.push_back({ map[i][j] - '0', {i,j} }); // 말 번호랑 시작점 저장
//			}
//		}
//	}
//
//
//	/*for (int i = 0; i < night.size(); i++) {
//		cout << night[i].first << night[i].second.first << night[i].second.second << '\n';
//	}*/
//
//
//	
//	for (int i = 0; i < night.size(); i++) {
//		memset(check, false, sizeof(check));
//		bfs(night[i].first, night[i].second.first, night[i].second.second);
//	}
//
//	for (int i = 0; i < row; i++) {
//		for (int j = 0; j < col; j++) {
//			for (int k = 0; k < ans[i][j].size(); k++) {
//				sum[i][j] += ans[i][j][k];
//			}
//		}
//	}
//
//	int same = ans[0][0].size();
//	for (int i = 0; i < row; i++) {
//		for (int j = 0; j < col; j++) {
//			if (same != ans[i][j].size()){
//				cout << -1;
//				return 0;
//			}
//		}
//	}
//
//	int result = -1;
//	for (int i = 0; i < row; i++) {
//		for (int j = 0; j < col; j++) {
//			if (result == -1 || sum[i][j] < result) {
//				result = sum[i][j];
//			}
//		}
//	}
//
//	cout << result;
//	return 0;
//}


#include<iostream> 
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
int m[8][2] = { {-1,-2} ,{1,-2}, {-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2} };
int N, M;
string s[51];
int visit[51][51];
int result[51][51] = { 0 };
int visit_cnt[51][51] = { 0 };
bool isRange(int y, int x)
{
	if (0 > y || y >= N || 0 > x || x >= M)
		return false;
	return true;
}

void bfs(int i, int j, int maal)
{
	queue<pair<pair<int, int>, pair<int, int>>> q; // 위치, ()
	visit[i][j] = 0;
	++visit_cnt[i][j];
	q.push({ { i,j },{1, 0} });

	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int num = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int ny = y + m[i][0];
			int nx = x + m[i][1];
			if (isRange(ny, nx) && visit[ny][nx] == -1)
			{
				++visit_cnt[ny][nx]; // 모일수 있는지 확인하려고 나중에 cnt랑 비교
				if (cnt >= maal) // cnt 가 한번 시행했을때 maal과 비교
				{
					cnt = 0;
					++num;
				}
				visit[ny][nx] = num;
				q.push({ { ny,nx },{num,cnt + 1 } });
			}
		}
	}
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> s[i];

	int cnt = 0; // 나라 개수
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int num = s[i][j] - '0';
			if (1 <= num && num <= 9)
			{
				++cnt;
				memset(visit, -1, sizeof(visit));
				bfs(i, j, num); // 시작점, 말 번호
				for (int a = 0; a < N; a++)
					for (int b = 0; b < M; b++)
						result[a][b] += visit[a][b];
			}
		}
	}

	int ret = 100000;
	bool hasChanged = false;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (result[i][j] >= 0 && visit_cnt[i][j] == cnt)
			{
				ret = min(ret, result[i][j]);
				hasChanged = true;
			}
	if (!hasChanged)
		cout << -1;
	else
		cout << ret;
	return 0;
}