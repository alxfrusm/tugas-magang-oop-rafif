#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
int saldo = 0;

class transaksi{
    private:
    int id;
    double jumlahTransaksi;
    string tipe, kategori, tanggal; 

    public:
    transaksi() : id(0), jumlahTransaksi(0.0), tipe(""), kategori(""), tanggal("") {}
    transaksi(int id, double jumlahTransaksi, string tipe, string kategori, string tanggal) : id(id), jumlahTransaksi(jumlahTransaksi), tipe(tipe), kategori(kategori), tanggal(tanggal) {}

    int getid(){return id;};
    double getjumlahTransaksi(){return jumlahTransaksi;};
    string gettipe(){return tipe;};
    string getkategori(){return kategori;};
    string gettanggal(){return tanggal;};

    void setjumlahTransaksi(double jumlahtransaksi){jumlahTransaksi = jumlahtransaksi;}
    void setkategori(string Kategori){kategori = Kategori;}
    void settanggal(string Tanggal){tanggal = Tanggal;}

    void display(){
        cout << "ID: " << id << ", Tipe Transaksi: " << tipe << ", Amount: " << jumlahTransaksi
             << ", Kategori: " << kategori << ", Tanggal Transaksi: " << tanggal << ", Saldo: " << saldo << endl;
    }
};

class menghitung{
    private:
    unordered_map<int, transaksi> Transaksi;
    int nextid = 1;

    public:
    void createtransaksi(double jumlahtransaksi, string tipe, string kategori, string tanggal){
        transaksi newtransaksi(nextid, jumlahtransaksi, tipe, kategori, tanggal);
        Transaksi[nextid++] = newtransaksi;
        cout << "Transaksi Berhasil" << endl;
        if(tipe == "Pemasukan"){
            saldo += jumlahtransaksi;
        }else if(tipe == "pengeluaran"){
            saldo -= jumlahtransaksi;
        }
    }
    void readtransaksi(){
        for(auto itr = Transaksi.begin(); itr != Transaksi.end(); itr++){
            itr->second.display();
        }
    }
    void updatetransaksi(int id, double transaksi, string tipe, string kategori, string tanggal){
        if (Transaksi.find(id) != Transaksi.end()) {
            Transaksi[id].setjumlahTransaksi(transaksi);
            Transaksi[id].setkategori(kategori);
            Transaksi[id].settanggal(tanggal);
            cout << "data berhasil diupdate" << endl;
        }else {
            cout << "data data tidak ditemukan" << endl;
        }
    }
    void deletetransaksi(int id){
         if (Transaksi.erase(id)) {
            cout << "transaksi berhasil dihapus" << endl;
        } else {
            cout << "transaksi dengan id " << id << " tidak ditemukan" << endl;
        }
    }
};

int main(){
    menghitung manager;
    int pilihan;

    do {
        cout << "\nPersonal Finance Manager\n";
        cout << "1. Tambah Transaksi\n";
        cout << "2. Lihat Transaksi\n";
        cout << "3. Perbarui Transaksi\n";
        cout << "4. Hapus Transaksi\n";
        cout << "5. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        if (pilihan == 1) {
            double jumlah;
            string tipe, kategori, tanggal;

            cout << "Masukkan jumlah: ";
            cin >> jumlah;
            cout << "Masukkan tipe (Pemasukan/Pengeluaran): ";
            cin >> tipe;
            cout << "Masukkan kategori: ";
            cin >> kategori;
            cout << "Masukkan tanggal (e.g., 2024-10-25): ";
            cin >> tanggal;

            manager.createtransaksi(jumlah, tipe, kategori, tanggal);
        } else if (pilihan == 2) {
            manager.readtransaksi();
        } else if (pilihan == 3) {
            int id;
            double jumlahBaru;
            string kategoriBaru, tipeBaru, tanggalBaru;

            cout << "Masukkan ID transaksi yang akan diperbarui: ";
            cin >> id;
            cout << "Masukkan jumlah baru: ";
            cin >> jumlahBaru;
            cout << "Masukkan tipe baru: ";
            cin >> tipeBaru;
            cout << "Masukkan kategori baru: ";
            cin >> kategoriBaru;
            cout << "Masukkan tanggal baru: ";
            cin >> tanggalBaru;

            manager.updatetransaksi(id, jumlahBaru, tipeBaru, kategoriBaru, tanggalBaru);
        } else if (pilihan == 4) {
            int id;

            cout << "Masukkan ID transaksi yang akan dihapus: ";
            cin >> id;

            manager.deletetransaksi(id);
        } else if (pilihan == 5) {
            cout << "Keluar dari program." << endl;
        } else {
            cout << "Pilihan tidak valid. Coba lagi." << endl;
        }
    } while (pilihan != 5);

    return 0;
}