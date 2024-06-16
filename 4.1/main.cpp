#include <iostream>
#include <ctime>
#include "vector.h"
using namespace std;

int main()
{
    srand(time(NULL));
    int x, n, v_size, max_el;
    cout << "choose input method:\n  (0)manual     (1+)random \n";
    cin >> n;
    cout << "sequence size: ";
    cin >> v_size;
    cout << "max element: ";
    cin >> max_el;
    if (v_size > 1e9 || max_el > 1e4)
        cout << "wrong value";
    else
    {
        /// int* mas = new int[max_el+1];
        Vector mas(max_el+1);
        for (int i = 1; i <= max_el; i++)
            mas[i] = 0;

        if (n == 0)//manual
            for (int i = 1; i <= v_size; i++)
            {
                cin >> x;
                if (x > max_el || x < 1)
                {
                    cout << "wrong value";
                    return 0;
                }
                mas[x] = mas[x] + 1;
            }
        else//random
        {
            cout << "elements: ";
            mas.fill_random(v_size, max_el);
            cout << endl;
        }

        cout << "\nfinal sequence: ";
        for (int i = 1; i <= max_el; i++)
            if (mas[i] > 1)
                cout << i << ' ';
    }
    return 0;
}
