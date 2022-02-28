#include <iostream>
#include <iomanip> //Нужно чтобы cout выводил больше знаков после ","
using namespace std;

double f(double x) { //Какая-то функция


    return (x - 12.3456789) * (x - 0.123456789);
}

int main()
{
    double a, b; //Дробное число с удвоенной точностью
    cin >> a >> b;
    double error; //Погрешность
    cout << "Enter needed error";
    cin >> error;

    if (f(a) * f(b) < 0) { //Корень на промежутке точно есть
        while (b - a > error * 2.) { //Ошибка должна быть минимум (b - a) / 2, т.к. иначе все ок
            double c = (a + b) / 2.; //Дописываем "." на всякий случай
            if (f(c) == 0) {
                break; //Ура!? Нельзя ничего сказат про ошибку
            }
            if (f(a) * f(c) < 0) { //Сдвигаем b потому, что можем сузить границы
                b = c;
            } else {
               a = c; //Теперь меняем a
            }
        }

        cout << setprecision(17) <<  "Answer" << (a + b) / 2; //Выводим ответ и выставляем нужное число знаков после ","
    } else {
        cout <<"Can't use binsearch of root. f(a) * f(b) >= 0" << '\n';
    }




    return 0;
}
