//Reference: Kun

#include <iostream>
#include <climits>
#include <vector>
#include <unordered_map>
#include <cstring>
using namespace std;

#define MAX 10

int reciter = 0;

void findallpaths(int a[][MAX], vector<string> &slist, char s[MAX], unordered_map<string, int> &hmap, int rows, int cols, int soff)
{
	if((rows == 1) && (cols == 1)) {
		for(int i = 0; i<soff; i++)
			cout << s[i] << " => ";
		cout << "\n";
		return;
	}
	
	if(rows > 1) {
		s[soff] = 'V';
		findallpaths(a, slist, s, hmap, rows-1, cols, soff+1);
	}

	if(cols > 1) {
		s[soff] = 'R';
		findallpaths(a, slist, s, hmap, rows, cols-1, soff+1);
	}
}

int main()
{

	int a[MAX][MAX], rows = 0, cols = 0;

	unordered_map<string, int> hmap;
	char str[MAX];
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
	vector<string> slist;
	findallpaths(a, slist, str, hmap, rows, cols, 0);

	//cout << "reciter : "<< reciter << "\n";

	//for(auto it = slist.begin(); it!=slist.end(); it++)
	//	cout << *it << "\n" << endl;

	//char s[MAX][MAX];

	//memset(s, 0, MAX * MAX);

	//int level = 0, offset = 0;

	//countnumpaths_memo(a, s, rows, cols, &level, &offset);

	return 0;
}
