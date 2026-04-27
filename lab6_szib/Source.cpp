#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <bitset>
using namespace std;
bitset<8> XOR(bitset<8> a, bitset<8> b) {
	bitset<8> c;
	for (int i = 0; i < 8; i++) {
		c[i] = a[i]!=b[i];
	}
	return c;
}
int main() {
	string Text;
	vector<int> text;
	cout << "Print the text: ";
	getline(cin, Text);
	for (int i = 0; i < Text.length(); i++) {
		text.push_back(Text[i]);
		cout << text[i] << " ";
	}
	cout << endl;
	vector <int> S, K, Key1,Key;
	Key1.push_back(347);
	int n = 0;
	for (int i = 0; Key1[0] / (pow(10,i)) >= 1; i++) {
		n++;
	}
	for (int i= n-1,j=0; i >= 0; i--,j++) {
		Key.push_back((int)(Key1[0] / pow(10, i)) % 10);
		cout << Key[j] << " ";
	}
	cout << endl;
	for (int i = 0,j=0; i < 256; i++,j++) {
		S.push_back(i);
		if (j == n) j = 0;
		K.push_back(Key[j]);
	}
	for (int i = 0; i < 256; i++) {
		cout << S[i]<< " ";
	}
	cout << endl;
	for (int i = 0; i < 256; i++) {
		cout << K[i] << " ";
	}
	int j = 0;
	for (int i = 0; i < 256; i++) {
		j = (j + S[i] + K[i]) % 256;
		int temp = S[i];
		S[i] = S[j];
		S[j] = temp; // заміна місцями S[i] i S[j]
	}
	vector<int> S_initial = S;
	cout << endl;
	for (int i = 0; i < 256; i++) {
		cout << S[i] << " ";
	}
	bitset<8> temp1, temp2;
	vector<bitset<8>> shifrtext;
	for (int i = 0, j = 0, n = 0; n < text.size(); n++) {// шифрування
		i = (i + 1) % 8;
		j = (j + S[i]) % 8;
		int temp = S[i];
		S[i] = S[j];
		S[j] = temp; // заміна місцями S[i] i S[j]
		int t = (S[i] + S[j]) % 8;
		int k = S[t];
		temp1 = k;
		temp2 = text[n];
		shifrtext.push_back(XOR(temp1, temp2));
		if (n == 0) cout <<endl<< temp1 <<" "<< temp2<< " " << shifrtext[0]<<" ";
	}
	vector<bitset<8>> deshifrtext;
	vector<char> deshtext;
	for (int i = 0, j = 0, n = 0; n < shifrtext.size(); n++) {// розшифрування
		i = (i + 1) % 8;
		j = (j + S_initial[i]) % 8;
		int temp = S_initial[i];
		S_initial[i] = S_initial[j];
		S_initial[j] = temp; // заміна місцями S[i] i S[j]
		int t = (S_initial[i] + S_initial[j]) % 8;
		int k = S_initial[t];
		temp1 = k;
		deshifrtext.push_back(XOR(temp1, shifrtext[n]));
		if (n == 0) cout << endl << temp1 << " " << shifrtext[0] << " " << deshifrtext[0] << " ";
		char character = static_cast<char>(deshifrtext[n].to_ulong());
		deshtext.push_back(character);
		cout << deshtext[n];
	}

}

