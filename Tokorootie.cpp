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

void tambahItem() {
    string nama;
    int harga, stok;
    cout << "Masukkan nama produk    : ";
    getline(cin, nama);
    cout << "Masukkan harga produk   : ";
    cin >> harga;
    cout << "Masukkan stok produk    : ";
    cin >> stok;
    cin.ignore();

    BakeryItem* produkBaru = new BakeryItem{nama, harga, stok, nullptr};

    if (!head) {
        head = produkBaru;
    } else {
        BakeryItem* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = produkBaru;
    }
    cout << "[✓] Produk berhasil ditambahkan.\n";
}

void tampilItem() {
    if (!head) {
        cout << "[!] Inventaris kosong.\n";
        return;
    }

    BakeryItem* temp = head;
    cout << "\n=== Daftar Produk ===\n";
    while (temp) {
        cout << "Nama   : " << temp->nama << endl;
        cout << "Harga  : Rp" << temp->harga << endl;
        cout << "Stok   : " << temp->stok << "\n" << endl;
        temp = temp->next;
    }
}

