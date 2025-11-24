#include "Pinjam.h"

void Pinjam::pinjamKendaraan(vector<Mobil>& listMobil, vector<Motor>& listMotor) {

        string nama;
        cout << "Masukkan nama kendaraan yang ingin dipinjam: ";
        getline(cin, nama);

    for (auto &m : listMobil) {
        if (m.nama == nama) {

            if (!m.tersedia) {
                cout << "Maaf, mobil sedang dipinjam orang lain!\n";
                return;
            }

            int hari;
            cout << "Berapa hari ingin disewa? ";
            cin >> hari;
            cin.ignore();

            int total = hari * m.hargaPerHari;
            m.tersedia = false;

            int w1 = 16; 
            int w2 = 20;

            cout << "\n+------------------+-----------------------+\n";
            cout << "| " << left << setw(w1) << "Kendaraan"   << " | " << left << setw(w2) << m.nama           << " |\n";
            cout << "| " << left << setw(w1) << "Harga / Hari" << " | " << left << setw(w2) << ("Rp" + to_string(m.hargaPerHari)) << " |\n";
            cout << "| " << left << setw(w1) << "Durasi"       << " | " << left << setw(w2) << (to_string(hari) + " hari")        << " |\n";
            cout << "| " << left << setw(w1) << "TOTAL"        << " | " << left << setw(w2) << ("Rp" + to_string(total))          << " |\n";
            cout << "+------------------+-----------------------+\n";
            return;
        }
    }

    for (auto &m : listMotor) {
        if (m.nama == nama) {

            if (!m.tersedia) {
                cout << "Maaf, motor sedang dipinjam orang lain!\n";
                return;
            }

            int hari;
            cout << "Berapa hari ingin disewa? ";
            cin >> hari;
            cin.ignore();

            int total = hari * m.hargaPerHari;
            m.tersedia = false;

            int w1 = 16; 
            int w2 = 20;

            cout << "\n+------------------+----------------------+\n";
            cout << "| " << left << setw(w1) << "Kendaraan"   << " | " << left << setw(w2) << m.nama           << " |\n";
            cout << "| " << left << setw(w1) << "Harga / Hari" << " | " << left << setw(w2) << ("Rp" + to_string(m.hargaPerHari)) << " |\n";
            cout << "| " << left << setw(w1) << "Durasi"       << " | " << left << setw(w2) << (to_string(hari) + " hari")        << " |\n";
            cout << "| " << left << setw(w1) << "TOTAL"        << " | " << left << setw(w2) << ("Rp" + to_string(total))          << " |\n";
            cout << "+------------------+----------------------+\n";

            return;
        }
    }

    cout << "Kendaraan tidak ditemukan!\n";
}

void Pinjam::kembalikanKendaraan(vector<Mobil>& listMobil, vector<Motor>& listMotor) {

    string nama;
    cout << "Masukkan nama kendaraan yang ingin dikembalikan: ";
    getline(cin, nama);

    for (auto &m : listMobil) {
        if (m.nama == nama) {

            if (m.tersedia) {
                cout << "Mobil ini belum dipinjam.\n";
                return;
            }

            m.tersedia = true;
            cout << "Mobil berhasil dikembalikan! Terima kasih.\n";
            return;
        }
    }

    for (auto &m : listMotor) {
        if (m.nama == nama) {

            if (m.tersedia) {
                cout << "Motor ini belum dipinjam.\n";
                return;
            }

            m.tersedia = true;
            cout << "Motor berhasil dikembalikan! Terima kasih.\n";
            return;
        }
    }

    cout << "Kendaraan tidak ditemukan!\n";
}