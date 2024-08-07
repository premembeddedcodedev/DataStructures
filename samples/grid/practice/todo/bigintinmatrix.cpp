#include <bits/stdc++.h>
using namespace std;
int dfs(vector<vector<int>> &board, int i, int j, vector<vector<int>> &visited, int length){

	int n = board.size();
	int m = board[0].size();

	if(i<0 || i>=n || j<0 || j>=m || length==0 || visited[i][j] == 1)
		return 0;

	int ans = board[i][j]*pow(10, length-1);
	visited[i][j] = 1;
	int ret = ans;
	ret = max(ret, ans + dfs(board, i+1, j, visited, length-1));
	ret = max(ret, ans + dfs(board, i-1, j, visited, length-1));
	ret = max(ret, ans + dfs(board, i, j+1, visited, length-1));
	ret = max(ret, ans + dfs(board, i, j-1, visited, length-1));
	visited[i][j] = 0;
	return ret;
}
int solution(vector<vector<int>> &board){
	int n = board.size();
	int m = board[0].size();

	if(n==1){
		int ans = 0;
		for(int i=0; i+3<m; i++)
			ans = max(ans, board[0][i]*1000 + board[0][i+1]*100 + board[0][i+2]*10 + board[0][i+3]);
		for(int i=m-1; i>=3; i--)
			ans = max(ans, board[0][i]*1000 + board[0][i-1]*100 + board[0][i-2]*10 + board[0][i-3]);
		return ans;
	}
	if(m==1){
		int ans = 0;
		for(int i=0; i+3<n; i++)
			ans = max(ans, board[i][0]*1000 + board[i+1][0]*100 + board[i+2][0]*10 + board[i+3][0]);
		for(int i=n-1; i>=3; i--)
			ans = max(ans, board[i][0]*1000 + board[i-1][0]*100 + board[i-2][0]*10 + board[i-3][0]);
		return ans;
	}

	int max_ele = 0;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			max_ele = max(max_ele, board[i][j]);

	int ans = 0;
	int length = 4;
	vector<vector<int>> visited(n, vector<int>(m, 0));
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++){
			if(board[i][j] == max_ele){
				int smallans = dfs(board, i, j, visited, length);
				ans = max(ans, smallans);
			}
		}

	printf("Visited: ");

	for(int i = 0; i<visited.size();i++)
		for(int j=0; j<visited[0].size(); j++)
			printf("%d ", visited[i][j]);

	printf("\n");

	return ans;
}
int main() {
	int n, m;
	cin>>n>>m;
	vector<vector<int>> board(n, vector<int>(m, 0));
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin>>board[i][j];

	cout<<solution(board);
	return 0;
}
