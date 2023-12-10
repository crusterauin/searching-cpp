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

void swap(string& a, string& b) {
    string temp = a;
    a = b;
    b = temp;
}	

void selectionSort(vector<string>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int binarySearch(vector<string>& arr, string x) {
	int bawah = 0;
	int atas = arr.size() - 1;
	while (bawah <= atas) {
		int tengah = bawah + (atas - bawah) / 2;
		if (x==arr[tengah]){
			return tengah;
		}
		if (x > arr[tengah]){
			bawah = tengah + 1;
		} else {
			atas = tengah - 1;
		}	
	}
	return -1;
}


void printVector(const vector<string>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
	vector<string> input;
	char ulangiProgram;
	string x;
	int hasil;
	
	do {
		input.clear();
		ulangiProgram = ' ';
		
		cout << "Selamat datang di program searching!\n";
		cout << "Masukkan beberapa angka yang akan diurutkan. Pisahkan dengan spasi. \nJika sudah selesai, masukkan tanda titik (.) dan tekan enter.\n";
		bahanSearch(input);
		selectionSort(input);
		cout << "Elemen setelah diurutkan: ";
		printVector(input);	
		cout << "Masukkan elemen yang ingin dicari!\n";
		cin >> x;
		hasil = binarySearch(input, x);
		
		if(hasil == -1){
			cout<<("Elemen tidak ditemukan!");
		} else {
			cout<<("Elemen ditemukan di index: ") << hasil << endl;
		}
      	
		cout << "Apakah Anda ingin mengulangi program? (y/n) \n";
		cin >> ulangiProgram;
	} while (ulangiProgram == 'Y' || ulangiProgram == 'y');
	return 0;
}
