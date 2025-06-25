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

void ubahItem() {
    if (!head) {
        cout << "[!] Inventaris kosong.\n";
        return;
    }

    string target;
    cout << "Masukkan nama produk yang ingin diubah: ";
    getline(cin, target);

    BakeryItem* temp = head;
    while (temp) {
        if (temp->nama == target) {
            int opsi;
            cout << "Pilih data yang ingin diubah:\n";
            cout << "1. Nama\n2. Harga\n3. Stok\n>> ";
            cin >> opsi;
            cin.ignore();

            switch (opsi) {
                case 1:
                    cout << "Nama baru: ";
                    getline(cin, temp->nama);
                    break;
                case 2:
                    cout << "Harga baru: ";
                    cin >> temp->harga;
                    cin.ignore();
                    break;
                case 3:
                    cout << "Stok baru: ";
                    cin >> temp->stok;
                    cin.ignore();
                    break;
                default:
                    cout << "[!] Opsi tidak valid.\n";
                    return;
            }
            cout << "[✓] Produk berhasil diperbarui.\n";
            return;
        }
        temp = temp->next;
    }
    cout << "[!] Produk tidak ditemukan.\n";
}

void hapusItem() {
    if (!head) {
        cout << "[!] Inventaris kosong.\n";
        return;
    }

    string target;
    cout << "Masukkan nama produk yang ingin dihapus: ";
    getline(cin, target);

    BakeryItem* temp = head;
    BakeryItem* prev = nullptr;

    if (temp->nama == target) {
        head = temp->next;
        delete temp;
        cout << "[✓] Produk berhasil dihapus.\n";
        return;
    }

    while (temp) {
        if (temp->nama == target) {
            prev->next = temp->next;
            delete temp;
            cout << "[✓] Produk berhasil dihapus.\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    cout << "[!] Produk tidak ditemukan.\n";
}

void menu() {
    int pilihan;
    do {
        cout << "\n===== Menu Inventaris Toko Roti =====\n";
        cout << "1. Tambah Produk\n";
        cout << "2. Tampilkan Produk\n";
        cout << "3. Ubah Produk\n";
        cout << "4. Hapus Produk\n";
        cout << "5. Keluar\n";
        cout << "Pilih (1-5): ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: tambahItem(); break;
            case 2: tampilItem(); break;
            case 3: ubahItem(); break;
            case 4: hapusItem(); break;
            case 5: cout << "Terima kasih telah menggunakan sistem inventaris.\n"; break;
            default: cout << "[!] Pilihan tidak valid.\n";
        }
    } while (pilihan != 5);
}

int main() {
    menu();
    return 0;
}
