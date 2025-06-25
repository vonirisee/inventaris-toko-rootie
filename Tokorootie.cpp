#include <iostream>
#include <string>
using namespace std;

struct BakeryItem {
    string nama;
    int harga;
    int stok;
    BakeryItem* next;
};

BakeryItem* head = nullptr;