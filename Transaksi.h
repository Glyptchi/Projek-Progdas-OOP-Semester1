#ifndef TRANSAKSI_H
#define TRANSAKSI_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "Kendaraan.h"

class Transaksi {
public:
    void pinjamKendaraan(vector<Mobil>& listMobil, vector<Motor>& listMotor);
    void kembalikanKendaraan(vector<Mobil>& listMobil, vector<Motor>& listMotor);
};

#endif
