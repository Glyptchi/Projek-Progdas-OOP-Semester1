#ifndef TRANSAKSI_H
#define TRANSAKSI_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "Kendaraan.h"

class Transaksi {
public:
    void pinjamKendaraan(vector<Kendaraan::Mobil>& listMobil, vector<Kendaraan::Motor>& listMotor);
    void kembalikanKendaraan(vector<Kendaraan::Mobil>& listMobil, vector<Kendaraan::Motor>& listMotor);
};

#endif
