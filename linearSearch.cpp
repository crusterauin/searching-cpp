#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

void bahanSearch(vector<string>& arr) {	
	string input;
	while (cin >> input && input != ".") {
		arr.push_back(input);
	}
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

vector<int> linearSearch(vector<string>& arr, string x) {
    vector<int> indeks;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == x) {
            indeks.push_back(i);
        }
    }
    return indeks;
}

int main() {
	vector<string> input;
	char ulangiProgram;
	string x;
	int hasil;
	
	do {
		input.clear();
		ulangiProgram = ' ';
		
		cout << "Selamat datang di program searching!\n";
		cout << "Masukkan beberapa elemen yang akan diurutkan. Pisahkan dengan spasi. \nJika sudah selesai, masukkan tanda titik (.) dan tekan enter.\n";
		bahanSearch(input);
		cout << "Masukkan elemen yang ingin dicari!\n";
		cin >> x;
		
		vector<int> hasil = linearSearch(input, x);
        if (hasil.empty()) {
            cout << "Elemen tidak ditemukan!\n";
        } else {
            cout << "Elemen ditemukan di indeks ke: ";
            for (int i = 0; i < hasil.size(); i++) {
                cout << hasil[i] + 1;
                if (i < hasil.size() - 1) {
                    cout << ", ";
                }
            }
            cout << "\n";
        }
		
		cout << "Apakah Anda ingin mengulangi program? (y/n) \n";
		cin >> ulangiProgram;
	} while (ulangiProgram == 'Y' || ulangiProgram == 'y');
	
	return 0;
}
