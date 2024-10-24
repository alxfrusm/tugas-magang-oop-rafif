#include <iostream>

using namespace std;

class its{
public:
    int jumlahMahasiswa = 10000;
    int jumlahPengajar = 200;
};

class fteic : public its {
public:
    int jumlahMahasiswafteic = 3000;
    void display(){
        cout << jumlahMahasiswa << endl << jumlahPengajar << endl << jumlahMahasiswafteic;
    }
};

int main(){
    fteic fteic;
    fteic.display();
}