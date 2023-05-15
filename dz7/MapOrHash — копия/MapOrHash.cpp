// MapOrHash.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <map>
#include <unordered_map>
//#include <ctime>
//#include <cstdlib>
//#include <vector>
#include <random>
#include <chrono>

using namespace std;

//inline int randInt() {
//    random_device dev;
//    mt19937 rng(dev());
//    uniform_int_distribution<mt19937::result_type> dist6(65, 89);
//
//    return dist6(rng);
//}
//
//inline const char* randKey() {
//    const int n = randInt();
//    string s = "";
//    for (int i = 0; i < n; i++) {
//        s += char(randInt());
//    }
//    s += '0';
//    cout << s << endl;
//    return;
//}
inline const char* randKey() {
    const int k = 8;
    static char key[k + 1]{ 0 };
    for (int i = 0; i < k - 1; i++) {
        key[i] = rand() % ('c' - 'a' + 1) + 'a';
    }
    return key;
}


int main()
{
    map<string, int> m;
    unordered_map<string, int> u;
    const int n = 32;
    pair<string, int> data[n];
    const int M = 512;
    int c = 0;
    //cout << randKey() << endl;


    for (int i = 0; i < n; i++) {
        data[i] = { randKey(), rand() % n };
        //cout << data[i].first << "," << data[i].second << endl;
    }

    for (int i = 0; i < n; i++) {
        m.insert(make_pair(data[i].first, data[i].second));
    }


    auto start = chrono::steady_clock::now();
    /*for (int i = 0; i < n; i++) {
        m.insert(make_pair(data[i].first, data[i].second));
    }*/
    /*for (int i = 0; i < n; i++) {
        u.insert(make_pair(data[i].first, data[i].second));
    }*/
    for (int i = 0; i < M; i++) {
        int k = m.count(data[i % n].first);
        c += k;
    }
    auto stop = chrono::steady_clock::now();
    auto dt = chrono::duration_cast<chrono:: microseconds>(stop - start).count();


    /*for (int i = 0; i < n; i++) {
        u.insert(make_pair(data[i].first, data[i].second));
    }*/
    cout << "n: " << n <<  " dt: " << dt << " c: " << c << endl;
    /*for (auto const& pair : m) {
        cout << pair.first << ": " << pair.second << endl;
    }*/
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
