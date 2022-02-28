#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<int> input_vector() {
    vector<int> A;
    string line;
    getline(cin, line);
    stringstream line_stream(line);
    while(not line_stream.eof()) { //Записываем пока строка потока не кончится
        int x;
        line_stream >> x;
        A.push_back(x);
    }
    return A;
}

void print_vector(vector<int> A) {
    for (auto &x: A) {
        cout << x << ' ';
    }
    cout << '\n';
}

bool is_acsending_order(const vector<int> &A) {
    int i = 0;
    while(i < int(A.size()) - 1) {
        if (A[i] > A[i + 1]) {
            return false;
        }
        i++;
    }
    return true;
}

void fool_sort(vector<int> &A) {
    int i = 0;
    while(i < int(A.size()) - 1) { //Пока есть для i — i+1
        if (A[i] > A[i + 1]) {
            swap(A[i], A[i + 1]); //Сортируем два элемента и начинаем сначала
            i = 0;
        } else {
            i++; //Всё ок, идём дальше
        }
}



int main()
{
    vector<int> A;
    A = input_vector();

    fool_sort(A);
    print_vector(A);

    return 0;
}

