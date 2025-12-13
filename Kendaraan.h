#ifndef KENDARAAN_H
#define KENDARAAN_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

class Kendaraan {
    public:
    struct Mobil {
        string nama;
        int hargaPerHari;
        bool tersedia = true;
        int lamaSewa;
    };

    struct Motor {
        string nama;
        int hargaPerHari;
        bool tersedia = true;
        int lamaSewa;
    };
    
    void saveKendaraan(const vector<Mobil>& listMobil, const vector<Motor>& listMotor);
    void loadKendaraan(vector<Mobil>& listMobil, vector<Motor>& listMotor);
    void tampilMobil(const vector<Mobil>& listMobil);
    void tampilMotor(const vector<Motor>& listMotor);
};

#endif
