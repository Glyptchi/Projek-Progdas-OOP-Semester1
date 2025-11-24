#include "KendaraanManagement.h"

void KendaraanManagement::saveKendaraan(const vector<Mobil>& listMobil, const vector<Motor>& listMotor) {
    ofstream file("kendaraan.txt");

    file << "[MOBIL]\n";
    for (auto &m : listMobil){
        file << m.nama << ";" << m.tersedia << "\n";
    }

    file << "[MOTOR]\n";
    for (auto &m : listMotor){
        file << m.nama << ";" << m.tersedia << "\n";
    }
}

void KendaraanManagement::loadKendaraan(vector<Mobil>& listMobil, vector<Motor>& listMotor) {
    ifstream file("kendaraan.txt");
    if (!file.good()) return;

    string line;
    bool modeMobil = true;

    while (getline(file, line)) {
        if (line == "[MOBIL]") { modeMobil = true; continue; }
        if (line == "[MOTOR]") { modeMobil = false; continue; }

        stringstream ss(line);
        string nama, tersediaStr;
        getline(ss, nama, ';');
        getline(ss, tersediaStr, ';');

        bool tersedia = stoi(tersediaStr);

        // ===========================
        //  UPDATE MOBIL
        // ===========================
        if (modeMobil) {
            for (auto &m : listMobil) {
                if (m.nama == nama) {
                    m.tersedia = tersedia;
                    break;
                }
            }
        }

        // ===========================
        //  UPDATE MOTOR
        // ===========================
        else {
            for (auto &m : listMotor) {
                if (m.nama == nama) {
                    m.tersedia = tersedia;
                    break;
                }
            }
        }
    }
}

void KendaraanManagement::tampilMobil(const vector<Mobil>& listMobil) {
    cout << "\n=== Daftar Mobil ===\n";

    int wNo = 4;
    int wNama = 22;
    int wHarga = 12;
    int wStatus = 10;

    cout << "+-----+-----------------------+-------------+-----------+\n";
    cout << "| " << left << setw(wNo) << "No"
         << "| " << left << setw(wNama) << "Nama Kendaraan"
         << "| " << left << setw(wHarga) << "Harga/Hari"
         << "| " << left << setw(wStatus) << "Status"
         << "|\n";
    cout << "+-----+-----------------------+-------------+-----------+\n";

    for (int i = 0; i < listMobil.size(); i++) {
        cout << "| " << left << setw(wNo) << i+1
             << "| " << left << setw(wNama) << listMobil[i].nama
             << "| Rp" << left << setw(wHarga-2) << listMobil[i].hargaPerHari
             << "| " << left << setw(wStatus) << (listMobil[i].tersedia ? "Tersedia" : "Dipinjam")
             << "|\n";
    }

    cout << "+-----+-----------------------+-------------+-----------+\n";
}

void KendaraanManagement::tampilMotor(const vector<Motor>& listMotor) {
    cout << "\n=== Daftar Motor ===\n";

    int wNo = 4;
    int wNama = 22;
    int wHarga = 12;
    int wStatus = 10;

    cout << "+-----+-----------------------+-------------+-----------+\n";
    cout << "| " << left << setw(wNo) << "No"
         << "| " << left << setw(wNama) << "Nama Kendaraan"
         << "| " << left << setw(wHarga) << "Harga/Hari"
         << "| " << left << setw(wStatus) << "Status"
         << "|\n";
    cout << "+-----+-----------------------+-------------+-----------+\n";

    for (int i = 0; i < listMotor.size(); i++) {
        cout << "| " << left << setw(wNo) << i+1
             << "| " << left << setw(wNama) << listMotor[i].nama
             << "| Rp" << left << setw(wHarga-2) << listMotor[i].hargaPerHari
             << "| " << left << setw(wStatus) << (listMotor[i].tersedia ? "Tersedia" : "Dipinjam")
             << "|\n";
    }

    cout << "+-----+-----------------------+-------------+-----------+\n";
}