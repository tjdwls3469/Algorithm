//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//
//int main() {
//	int row;
//	int col;
//	int x;
//	int y;
//	int dir;
//	int ans = 0;
//	cin >> row >> col;
//	cin >> x >> y >> dir;
//	vector<vector<int>> map(row, vector<int>(col));
//	vector<vector<bool>> check(row, vector<bool>(col));
//	for (int i = 0; i < row; i++) {
//		for (int j = 0; j < col; j++) {
//			cin >> map[i][j];
//		}
//	}
//	int dx[] = { 0,-1,0,1 };
//	int dy[] = { -1,0,1,0 };
//	queue<pair<int, int>> q;
//	check[x][y] = true;
//	q.push(make_pair(x, y));
//	ans++;
//	while (!q.empty()) {
//		int fx = q.front().first;
//		int fy = q.front().second;
//		q.pop();
//
//
//		bool okC = true;
//		bool okD = true;
//		for (int i = 0; i < 4; i++) {
//			int cx = fx + dx[i];
//			int cy = fy + dy[i];
//			if (cx >= 0 && cx < row && cy >= 0 && cy < col) {
//				if (map[cx][cy] == 0 && check[cx][cy] == false) {
//					okC = false;
//				}
//			}
//		}
//		if (okC == true) {
//			int cx = fx;
//			int cy = fy;
//			switch (dir) {
//			case 0:
//				cx += 1;
//				break;
//			case 1:
//				cy -= 1;
//				break;
//			case 2:
//				cx -= 1;
//				break;
//			case 3:
//				cy += 1;
//				break;
//			default:;
//				break;
//			}
//			if (cx >= 0 && cx < row && cy >= 0 && cy < col) {
//				if (map[cx][cy] == 0) {
//					q.push(make_pair(cx, cy));
//					okD = false;
//				}
//			}
//			if (okD == true) {
//				cout << ans;
//				return 0;
//			}
//		}
//
//
//		int nx = fx + dx[dir];
//		int ny = fy + dy[dir];
//		bool okA = false;
//		if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
//			if (map[nx][ny] == 0 && check[nx][ny] == false) {
//				check[nx][ny] = true;
//				q.push(make_pair(nx, ny));
//				dir = (dir + 1) % 4;
//				ans++;
//				okA = true;
//			}
//		}
//		if (okA == false) {
//			dir = (dir + 1) % 4;
//		}
//
//		cout << '\n';
//		for (int i = 0; i < row; i++) {
//			for (int j = 0; j < col; j++) {
//				cout << check[i][j] << ' ';
//			}
//			cout << '\n';
//		}
//	}
//	cout << ans;
//	return 0;
//}