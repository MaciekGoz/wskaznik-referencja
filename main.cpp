#include <iostream>

using namespace std;

void funkcja(int &zmien) {
    zmien = 0;
}

void funk2(int tab[]) {
    tab[0] = 0;
}

int * stworzTablice(int rozmiar) {
    int tab[rozmiar];
    for (int i = 0; i < rozmiar; i++)
        tab[i] = i;
    return tab;
}

void wyswietlTab(int *tablica, int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        cout << *(tablica+i) << " ";
    }
}



int main() {
    //referencja
    int zmienna = 22;
    funkcja(zmienna);
    cout << zmienna << endl; //z 22 na 0
    int tab[] = {1,2,3,4,5,6,7,8};
    funk2(tab);
    cout << tab[0] << endl; // z 1 na 0

    cout << &zmienna << endl; // miejsce w pamieci

    //wskaznik
    zmienna = 22;
    int *wsk;
    wsk = &zmienna;
    cout << wsk << endl; //= &zmienna | miejsce w pamieci
    cout << *wsk << endl; //zmienna = 22;

    zmienna = 22;
    double *wsk_double;
    int *wsk_int;
    void *wsk_void;

    wsk_double = (double *)wsk_int;
    wsk_double = reinterpret_cast<double*>(wsk_int);

    wsk_void = wsk_int;
    wsk_int = (int *)wsk_void;

    //int *arr = stworzTablice(5); nie dziala

    wyswietlTab(tab, 8);
    cout << endl;

    //dynamiczna alokacja pamieci
    int in;
    int *dynamicznaTablica;
    cin >> in;
    dynamicznaTablica = new int[in];

    for (int i = 0; i < in; i++) {
        dynamicznaTablica[i] = i;
        cout << dynamicznaTablica[i] << " ";
    }
}
