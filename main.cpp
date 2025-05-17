#include <iostream>
#include <vector>
#include <ranges>

using namespace std;

//5 immediate if (if constexpr) (if consteval)
template <typename T>
void stampa(T num)
{
    if constexpr(std::is_integral_v<T>)
        cout << "num is intero: " << num << endl;
    else
        cout << "num non è intero: " << num << endl;

}

int main() {
    static_assert(__cplusplus == 202002L, "Devi compilare in C++20!");
/*
    int numero;
    cout << "Inserisci un numero: ";
    cin >> numero;
    cout << "Hai inserito: " << numero << endl;
*/

    //1 designated initialization
    struct Persona {
        std::string nome;
        int eta;
    };
    Persona p {.nome = "Mario", .eta = 32};

    cout << p.nome << endl;
    cout << p.eta << endl;

    //2 enum classes
    enum class Maglione {Rosso, Blu, Verde};
    enum class Pullover {Rosso, Bianco, Verde};

    Maglione viola = Maglione::Blu;
    Pullover vestito = Pullover::Rosso;

    //cout << "viola: " << viola << endl;
    //cout << "vestito: " << vestito << endl;

    //3 switch statement with variable declaration
    std::string prova = "viva la vita";

    switch(int len = prova.size(); len)
    {
        case 0 : cout << "len is zero" << endl; break;
        default : cout << "len is " << len << endl; break; 
    }

    stampa(5);
    stampa(3.14);

    //7 Class Template Argument Deduction
    vector v{1,2,3,4,5};

    for( int r : v)
    {
        cout << "vector: " << r << endl;
    }

    //8 lambda function and mutable
    int x = 10;
    cout << "pre lambda, x = " << x << endl;
    stampa(x);
    auto f = [x]() mutable {
        cout << "BEGIN in lamba, x = " << x << endl;
        x += 10;
        cout << "END in lamba, x = " << x << endl;
    };
    f();
    
    cout << "post lambda. x = " << x << endl;

    vector<int> num {1,2,3,4,5,6,7,8,9,10};
    auto t = num | std::views::filter([] (int c) {return (c % 2 == 0);});
    for(int m : t)
    {
        cout << "t = " << m << endl;
    }

    cout "Programma TERMINATO"; 

    return 0;
}