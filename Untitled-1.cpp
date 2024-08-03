#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Barang {
    int id;
    string nama;
    int jumlah;
    double harga;
};

class Inventory {
private:
    vector<Barang> barangList;

    int findBarangById(int id) {
        for (size_t i = 0; i < barangList.size(); ++i) {
            if (barangList[i].id == id) {
                return i;
            }
        }
        return -1;
    }

public:
    void tambahBarang(const Barang& barang) {
        barangList.push_back(barang);
        cout << "Barang berhasil ditambahkan.\n";
    }

    void hapusBarang(int id) {
        int index = findBarangById(id);
        if (index != -1) {
            barangList.erase(barangList.begin() + index);
            cout << "Barang berhasil dihapus.\n";
        } else {
            cout << "Barang tidak ditemukan.\n";
        }
    }

    void cariBarang(int id) {
        int index = findBarangById(id);
        if (index != -1) {
            cout << "Barang ditemukan: ID: " << barangList[index].id
                 << ", Nama: " << barangList[index].nama
                 << ", Jumlah: " << barangList[index].jumlah
                 << ", Harga: " << barangList[index].harga << "\n";
        } else {
            cout << "Barang tidak ditemukan.\n";
        }
    }

    void updateBarang(int id, const Barang& updatedBarang) {
        int index = findBarangById(id);
        if (index != -1) {
            barangList[index] = updatedBarang;
            cout << "Barang berhasil diperbarui.\n";
        } else {
            cout << "Barang tidak ditemukan.\n";
        }
    }

    void tampilkanBarang() {
        if (barangList.empty()) {
            cout << "Tidak ada barang dalam inventaris.\n";
            return;
        }

        for (const auto& barang : barangList) {
            cout << "ID: " << barang.id
                 << ", Nama: " << barang.nama
                 << ", Jumlah: " << barang.jumlah
                 << ", Harga: " << barang.harga << "\n";
        }
    }
};

int main() {
    Inventory inventory;
    int pilihan, id;
    Barang barang;

    do {
        cout << "Menu:\n"
             << "1. Tambah Barang\n"
             << "2. Hapus Barang\n"
             << "3. Cari Barang\n"
             << "4. Update Barang\n"
             << "5. Tampilkan Semua Barang\n"
             << "6. Keluar\n"
             << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan ID: ";
                cin >> barang.id;
                cin.ignore();
                cout << "Masukkan Nama: ";
                getline(cin, barang.nama);
                cout << "Masukkan Jumlah: ";
                cin >> barang.jumlah;
                cout << "Masukkan Harga: ";
                cin >> barang.harga;
                inventory.tambahBarang(barang);
                break;
            case 2:
                cout << "Masukkan ID barang yang ingin dihapus: ";
                cin >> id;
                inventory.hapusBarang(id);
                break;
            case 3:
                cout << "Masukkan ID barang yang ingin dicari: ";
                cin >> id;
                inventory.cariBarang(id);
                break;
            case 4:
                cout << "Masukkan ID barang yang ingin diupdate: ";
                cin >> id;
                cin.ignore();
                cout << "Masukkan Nama baru: ";
                getline(cin, barang.nama);
                cout << "Masukkan Jumlah baru: ";
                cin >> barang.jumlah;
                cout << "Masukkan Harga baru: ";
                cin >> barang.harga;
                barang.id = id; 
                inventory.updateBarang(id, barang);
                break;
            case 5:
                inventory.tampilkanBarang();
                break;
            case 6:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
                break;
        }
    } while (pilihan != 6);

    return 0;
}   
