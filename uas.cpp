#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

//struktur data barang
struct Barang {
    int id;
    string nama;
    string kategori;
    float harga;
};

// vector 
vector<Barang> inventaris;

//cek id
bool idSudahAda(int id) {
    for (const auto &b : inventaris) {
        if (b.id == id) {
            return true;
        }
    }
    return false;
}

//tambah barang
void tambahBarang() {
    Barang b;

    cout << "Masukkan ID            : ";
    cin >> b.id;

    if (idSudahAda(b.id)) {
        cout << "ID sudah digunakan! Gunakan ID lain.\n";
        return;
    }

    cin.ignore();
    cout << "Masukkan Nama Barang   : ";
    getline(cin, b.nama);

    cout << "Masukkan Kategori      : ";
    getline(cin, b.kategori);

    cout << "Masukkan Harga         : ";
    cin >> b.harga;

    inventaris.push_back(b);
    cout << "Barang berhasil ditambahkan!\n";
}

//hapus barang
void hapusBarang() {
    int id;
    cout << "Masukkan ID barang yang akan dihapus: ";
    cin >> id;

    for (auto it = inventaris.begin(); it != inventaris.end(); ++it) {
        if (it->id == id) {
            inventaris.erase(it);
            cout << "Barang berhasil dihapus!\n";
            return;
        }
    }
    cout << "Barang dengan ID tersebut tidak ditemukan.\n";
}

//edit barang
void editBarang() {
    int id;
    cout << "Masukkan ID barang yang akan diedit: ";
    cin >> id;
    cin.ignore();

    for (auto &b : inventaris) {
        if (b.id == id) {
            cout << "Nama Baru     : ";
            getline(cin, b.nama);

            cout << "Kategori Baru : ";
            getline(cin, b.kategori);

            cout << "Harga Baru    : ";
            cin >> b.harga;

            cout << "Data barang berhasil diperbarui!\n";
            return;
        }
    }
    cout << "Barang tidak ditemukan.\n";
}

//fungsi tampilkan inventaris
void tampilkanInventaris() {
    if (inventaris.empty()) {
        cout << "Inventaris kosong.\n";
        return;
    }

    cout << left << setw(5) << "ID"
         << setw(20) << "Nama"
         << setw(15) << "Kategori"
         << setw(10) << "Harga" << endl;

    cout << "-----------------------------------------------\n";

    for (const auto &b : inventaris) {
        cout << left << setw(5) << b.id
             << setw(20) << b.nama
             << setw(15) << b.kategori
             << setw(10) << b.harga << endl;
    }
}

//urutkan barang
void urutkanBarang() {
    int pilihan;
    cout << "Urutkan berdasarkan:\n";
    cout << "1. Nama\n";
    cout << "2. Harga\n";
    cout << "Pilih: ";
    cin >> pilihan;

    if (pilihan == 1) {
        sort(inventaris.begin(), inventaris.end(),
             [](Barang a, Barang b) {
                 return a.nama < b.nama;
             });
        cout << "Barang diurutkan berdasarkan nama.\n";
        tampilkanInventaris(); 
    } 
    else if (pilihan == 2) {
        sort(inventaris.begin(), inventaris.end(),
             [](Barang a, Barang b) {
                 return a.harga < b.harga;
             });
        cout << "Barang diurutkan berdasarkan harga.\n";
        tampilkanInventaris(); 
    } 
    else {
        cout << "Pilihan tidak valid.\n";
    }
}

//cari barang
void cariBarang() {
    string namaCari;
    cin.ignore();
    cout << "Masukkan nama barang yang dicari: ";
    getline(cin, namaCari);

    bool ditemukan = false;
    for (const auto &b : inventaris) {
        if (b.nama.find(namaCari) != string::npos) {
            cout << "ID: " << b.id
                 << ", Nama: " << b.nama
                 << ", Kategori: " << b.kategori
                 << ", Harga: " << b.harga << endl;
            ditemukan = true;
        }
    }

    if (!ditemukan) {
        cout << "Barang tidak ditemukan.\n";
    }
}

//menu
void menu() {
    cout << "\n===== MENU INVENTARIS =====\n";
    cout << "1. Tambah Barang\n";
    cout << "2. Hapus Barang\n";
    cout << "3. Edit Barang\n";
    cout << "4. Urutkan Barang\n";
    cout << "5. Cari Barang\n";
    cout << "6. Tampilkan Inventaris\n";
    cout << "0. Keluar\n";
    cout << "Pilih menu: ";
}

//main
int main() {
    int pilihan;

    do {
        menu();
        cin >> pilihan;

        switch (pilihan) {
            case 1: tambahBarang(); break;
            case 2: hapusBarang(); break;
            case 3: editBarang(); break;
            case 4: urutkanBarang(); break;
            case 5: cariBarang(); break;
            case 6: tampilkanInventaris(); break;
            case 0: cout << "Keluar dari program...\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}
