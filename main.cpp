#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int hist[3] = {0};
	int b[n];

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		b[i] = a;
		if (a < 0) hist[0]++;
		else if (a > 0) hist[1]++;
		else hist[2]++;
	}

	// hist[2] == 1; 0 bit info
	// hist[1] + hist[0] == n - 1; 0 bit info

	// hist[0] is even -> hist[2]++, hist[0]--
	// hist[1] == 0 -> hist[0] -= 2, hist[1] += 2
	int h = ((hist[1] == 0) * 2);
	hist[0] -= h;
	hist[1] += h; 

	int c = 1 - (hist[0] % 2);
	hist[0] -= c;
	hist[2] += c;
	cout << hist[0] << ' ';
	for (int i = 0; i < n && hist[0] > 0; i++) {
		if (b[i] < 0) {
			cout << b[i] << ' ';
			b[i] = 0;
			hist[0]--;
		}
	}

	cout << '\n';

	cout << hist[1] << ' ';
	for (int i = 0; i < n && hist[1] > 0; i++) {
		if (b[i] > 0) {
			cout << b[i] << ' ';
			b[i] = 0;
			hist[1]--;
		} 
		else if (h > 0 && b[i] < 0) {
			cout << b[i] << ' ';
			b[i] = 0;
			hist[1]--;
			h--;
		} 
	}

	cout << '\n';

	cout << hist[2] << ' ';
	for (int i = 0; i < n && hist[2] > 0; i++) {
		if (b[i] != 0) {
			cout << b[i] << ' ';
			hist[2]--;
		}
	}
	cout << 0;
}
