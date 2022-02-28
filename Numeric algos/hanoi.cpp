#include <iostream>
using namespace std;

void hanoi(int n, int start, int finish) {
    if (n == 1) { //Крайний случай
        cout << n << " from " << start << " to " << finish << endl;
    } else { //Рекурентный случай
        int tmp = 6 - start - finish; // Вычисляем временный столбец, сумма всех 1 + 2 + 3 = 6
        hanoi(n - 1, start, tmp);
        cout << n << " from " << start << " to " << finish << endl;
        hanoi(n - 1, tmp, finish);
    }
}



int main()
{
    hanoi(4, 1, 3);

    return 0;
}
