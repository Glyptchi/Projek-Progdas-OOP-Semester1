#include "Transaksi.h"

void Transaksi::pinjamKendaraan(vector<Kendaraan::Mobil>& listMobil, vector<Kendaraan::Motor>& listMotor) {

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

            m.lamaSewa = hari;
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

            m.lamaSewa = hari;
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

void Transaksi::kembalikanKendaraan(vector<Kendaraan::Mobil>& listMobil, vector<Kendaraan::Motor>& listMotor) {

    string nama;
    cout << "Masukkan nama kendaraan yang ingin dikembalikan: ";
    getline(cin, nama);

    // MOBIL
    for (auto &m : listMobil) {
        if (m.nama == nama) {

            if (m.tersedia) {
                cout << "Mobil ini belum dipinjam.\n";
                return;
            }

            int hariNyata;
            cout << "Berapa hari dipakai sebenarnya? ";
            cin >> hariNyata;
            cin.ignore();

            int hariPerjanjian = m.lamaSewa;
            int denda = 0;
            int harga = hariPerjanjian * m.hargaPerHari;

            if (hariNyata > hariPerjanjian) {
                denda = (hariNyata - hariPerjanjian) * (m.hargaPerHari * 2);
            }

            cout << "\n=== PENGEMBALIAN ===\n";
            cout << "Durasi perjanjian : " << hariPerjanjian << " hari\n";
            cout << "Pemakaian         : " << hariNyata << " hari\n";
            cout << "Harga sewa        : Rp" << harga << endl;
            cout << "Denda             : Rp" << denda << "\n";
            cout << "Total             : RP" << denda + harga << endl << endl;

            m.tersedia = true;
            m.lamaSewa = 0;   // reset
            cout << "Mobil berhasil dikembalikan! Terima kasih.\n";
            return;
        }
    }

    // MOTOR
    for (auto &m : listMotor) {
        if (m.nama == nama) {

            if (m.tersedia) {
                cout << "Motor ini belum dipinjam.\n";
                return;
            }

            int hariNyata;
            cout << "Berapa hari dipakai sebenarnya? ";
            cin >> hariNyata;
            cin.ignore();

            int hariPerjanjian = m.lamaSewa;
            int harga = hariPerjanjian * m.hargaPerHari;
            int denda = 0;

            if (hariNyata > hariPerjanjian) {
                denda = (hariNyata - hariPerjanjian) * (m.hargaPerHari*2);
            }

            cout << "\n=== PENGEMBALIAN ===\n";
            cout << "Durasi perjanjian : " << hariPerjanjian << " hari\n";
            cout << "Pemakaian         : " << hariNyata << " hari\n";
            cout << "Harga sewa        : Rp" << harga << endl;
            cout << "Denda             : Rp" << denda << "\n";
            cout << "Total             : RP" << denda + harga << endl;

            m.tersedia = true;
            m.lamaSewa = 0;   // reset
            cout << "Motor berhasil dikembalikan! Terima kasih.\n";
            return;
        }
    }

    cout << "Kendaraan tidak ditemukan!\n";
}
