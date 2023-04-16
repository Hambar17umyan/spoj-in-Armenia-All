#include <iostream>
using namespace std;

struct queen {
	int x, y;
};

char arr[10][10];
int r;
void f(queen q, char op, char oq){
	for (int i = q.x + 1; i < 8; i++){
		if (arr[i][q.y] != '.'){
			if (arr[i][q.y] == op || arr[i][q.y] == oq){
				r++;
			}
			break;
		}
	}
	for (int i = q.x - 1; i >= 0; i--) {
		if (arr[i][q.y] != '.'){
			if (arr[i][q.y] == op || arr[i][q.y] == oq){
				r++;
			}
			break;
		}
	}
	for (int i = q.x + 1; i < 8; i++) {
		if (arr[q.x][i] != '.'){
			if (arr[q.x][i] == op || arr[q.x][i] == oq){
				r++;
			}
			break;
		}
	}
	for (int i = q.x - 1; i >= 0; i--) {
		if (arr[q.x][i] != '.'){
			if (arr[q.x][i] == op || arr[q.x][i] == oq){
				r++;
			}
			break;
		}
	}
	for (int i = 1; i + q.x < 8 && i + q.y < 8; i++){
		if (arr[q.x + i][q.y + i] != '.') {
			if (arr[q.x + i][q.y + i] == op || arr[q.x + i][q.y + i] == oq) {
				r++;
			}
			break;
		}
	}
	for (int i = 1; -i + q.x >= 0 && i + q.y < 8; i++) {
		if (arr[q.x - i][q.y + i] != '.') {
			if (arr[q.x - i][q.y + i] == op || arr[q.x - i][q.y + i] == oq) {
				r++;
			}
			break;
		}
	}
	for (int i = 1; -i + q.x >= 0 && -i + q.y >=0; i++) {
		if (arr[q.x - i][q.y - i] != '.') {
			if (arr[q.x - i][q.y - i] == op || arr[q.x - i][q.y - i] == oq) {
				r++;
			}
			break;
		}
	}
	for (int i = 1; i + q.x < 8 && -i + q.y >= 0; i++) {
		if (arr[q.x + i][q.y - i] != '.') {
			if (arr[q.x + i][q.y - i] == op || arr[q.x + i][q.y - i] == oq) {
				r++;
			}
			break;
		}
	}
}
int main() {
	int i, j, k, l, m, n;
	queen a, b;
	b.x = -1;
	b.y = -1;
	a = b;
	for (i = 0; i < 8; i++){

		for (j = 0; j < 8; j++){

			cin >> arr[i][j];

			if (arr[i][j] == 'q'){
				b.x = i;
				b.y = j;
			}

			else if (arr[i][j] == 'Q'){
				a.x = i;
				a.y = j;
			}
		}
	}
	//cout << a.x << ' ' << a.y << endl;
	//cout << b.x << ' ' << b.y << endl;

	if (a.x + 1){
		r = 0;
		f(a, 'b', 'q');
		cout << r << ' ';
	}
	else cout << -1 << ' ';

	if (b.x + 1) {
		r = 0;
		f(b, 'w', 'Q');
		cout << r;
	}
	else cout << -1;

	return 0;
}