#ifndef KENDARAANMANAGEMENT_H
#define KENDARAANMANAGEMENT_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

struct Mobil {
    string nama;
    int hargaPerHari;
    bool tersedia = true;
};

struct Motor {
    string nama;
    int hargaPerHari;
    bool tersedia = true;
};

class KendaraanManagement {
public:
    void saveKendaraan(const vector<Mobil>& listMobil, const vector<Motor>& listMotor);
    void loadKendaraan(vector<Mobil>& listMobil, vector<Motor>& listMotor);
    void tampilMobil(const vector<Mobil>& listMobil);
    void tampilMotor(const vector<Motor>& listMotor);
};

#endif
