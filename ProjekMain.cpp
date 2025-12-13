#include <bits/stdc++.h>
#include "UserManagement.h"
#include "Kendaraan.h"
#include "Transaksi.h"
#include "Feedback.h"

using namespace std;

int main(){

    vector<Kendaraan::Mobil> listMobil = {
        {"Toyota Avanza", 350000, true},
        {"Honda Brio", 300000, true},
        {"Daihatsu Xenia", 330000, true},
        {"Mitsubishi Xpander", 400000, true},
        {"Suzuki Ertiga", 350000, true},
    };

    vector<Kendaraan::Motor> listMotor = {
        {"Yamaha NMAX", 120000, true},
        {"Honda Vario", 100000, true},
        {"Suzuki GSX R150", 180000, true},
        {"Yamaha Aerox", 130000, true},
        {"Honda PCX", 140000, true},
    };

    UserManagement user;
    Kendaraan kendaraan;
    Transaksi pinjam;
    Feedback feedback;

    kendaraan.loadKendaraan(listMobil, listMotor);
    user.loadUsers();

    int pilihan;

    while(true){
        cout << "\nMasuk ke Aplikasi Rental Kendaraan" << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input harus angka!\n";
            continue;
        }
        cin.ignore(1000, '\n');

        if(pilihan == 1){

            if (!user.login()) {
                continue;
            };

            while(true){
                cout << "\nMenu Utama" << endl;
                cout << "1. Edit profil" << endl;
                cout << "2. Lihat Mobil Tersedia" << endl;
                cout << "3. Lihat Motor Tersedia" << endl;
                cout << "4. Pinjam kendaraan" << endl;
                cout << "5. Kembalikan kendaraan" << endl;
                cout << "6. Berikan feedback" << endl;
                cout << "7. Save data" << endl;
                cout << "8. Log out" << endl;
                cout << "Pilih menu: ";
                cin >> pilihan;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if(pilihan == 1){
                    user.editProfil();
                } else if(pilihan == 2){
                    kendaraan.tampilMobil(listMobil);
                } else if(pilihan == 3){
                    kendaraan.tampilMotor(listMotor);
                } else if(pilihan == 4){
                    pinjam.pinjamKendaraan(listMobil, listMotor);
                } else if(pilihan == 5){
                    pinjam.kembalikanKendaraan(listMobil, listMotor);
                } else if(pilihan == 6){
                    feedback.berikanFeedback(user);
                } else if(pilihan == 7){
                    kendaraan.saveKendaraan(listMobil, listMotor);
                    user.saveUsers();

                    cout<<"Save berhasil!"<<endl;
                } else if(pilihan == 8){
                    cout <<"Logout berhasil!\n";
                    break;
                } else {
                    cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                }

            }
        } else if(pilihan == 2){
            user.registerUser();
        } else if(pilihan == 3){
            cout << "Terima kasih telah menggunakan aplikasi kami!" << endl;
            break;
        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }

    return 0;
}