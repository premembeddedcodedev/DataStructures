#include <iostream>
#include <climits>
#include <unordered_map>
using namespace std;

#define MAX 10

int recpathsum(int a[][MAX], int rows, int cols, int max_rows, int max_cols)
{
	if((rows == max_rows) && (cols == max_cols))
		return a[rows][cols];

	if((rows > max_rows) || (cols > max_cols))
		return INT_MIN;

	int side = recpathsum(a, rows, cols+1, max_rows, max_cols);
	int down = recpathsum(a, rows+1, cols, max_rows, max_cols);

	int total = a[rows][cols] + max(side, down);

	return total;
}

int memopathsum(int a[][MAX], unordered_map<string, int> &hmap, int rows, int cols, int max_rows, int max_cols)
{
	string key;
        if((rows == max_rows) && (cols == max_cols))
                return a[rows][cols];

        if((rows > max_rows) || (cols > max_cols))
                return INT_MIN;

	key = to_string(rows) + '#'+ to_string(cols);
	if(hmap[key] > 1) {
		cout << key << ":" << "value : " << hmap[key] << "\n";
		return hmap[key];
	}
	hmap[key] = 0;
  
        int side = memopathsum(a, hmap, rows, cols+1, max_rows, max_cols);
        int down = memopathsum(a, hmap, rows+1, cols, max_rows, max_cols);
	
	string key2 = to_string(rows) + '#'+ to_string(cols);
	//cout << "\n" << key2;
	hmap[key2] = 0;
	hmap[key2] = a[rows][cols] + max(side, down);

        return a[rows][cols] + max(side, down);
}

int main() {

	int a[MAX][MAX], rows = 0, cols = 0;

	unordered_map<string, int> hmap;

	cout << "Enter the rows: " << "\n";
	cin >> rows;

	cout << "Enter the cols: " << "\n";
	cin >> cols;


	for(auto i = 0; i<rows; i++) {
		for(int j=0; j<cols; j++)
			cin >> a[i][j];
	}

	for(auto i = 0; i<rows; i++) {
		cout << "{";
		for(int j=0; j<cols; j++)
			cout << a[i][j];
		cout << "}\n";
	}

	cout << "\n";

	int dp[MAX][MAX] = {0};

	//cout << "min path sum: " << pathsum(a, 0, 0, rows-1, cols-1);
	cout << "min path sum: \n" << memopathsum(a, hmap, 0, 0, rows-1, cols-1) << "\n";

	for (auto x : hmap) 
		cout << x.first << " " << x.second << endl; 

	return 0;
}
