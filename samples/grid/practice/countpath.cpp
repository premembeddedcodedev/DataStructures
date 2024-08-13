//Referenc: Kun

#include <iostream>
#include <climits>
#include <unordered_map>
using namespace std;

#define MAX 10

int reciter = 0;

int countnumpaths(int a[][MAX], int rows, int cols)
{
        if((rows == 1) || (cols == 1))
                return 1;

        int down = countnumpaths(a, rows-1, cols);
        int side = countnumpaths(a, rows, cols-1);
	
        return side + down;
}

int countnumpaths_memo(int a[][MAX], unordered_map<string, int> &hmap, int rows, int cols)
{
	string key = to_string(rows) + '#' + to_string(cols);
	if(hmap[key] > 0)
		return hmap[key];
	
	reciter++;
        if((rows == 1) || (cols == 1))
                return 1;

	hmap[key] = 0;

        int down = countnumpaths_memo(a, hmap, rows-1, cols);
        int side = countnumpaths_memo(a, hmap, rows, cols-1);
	
	string key2 = to_string(rows) + '#' + to_string(cols);
	hmap[key2] = 0;
	hmap[key2] = side + down;

        return side + down;
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
			cout << a[i][j] << ",";
		cout << "}\n";
	}

	cout << "\n";
	cout << "min path sum: \n" << countnumpaths(a, rows, cols) << "\n";
	cout << "min path sum: \n" << countnumpaths_memo(a, hmap, rows, cols) << "\n";

	cout << "reciter : "<< reciter << "\n";

	return 0;
}
