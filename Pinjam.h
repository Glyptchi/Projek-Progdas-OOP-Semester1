#ifndef PINJAM_H
#define PINJAM_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "KendaraanManagement.h"

class Pinjam {
public:
    void pinjamKendaraan(vector<Mobil>& listMobil, vector<Motor>& listMotor);
    void kembalikanKendaraan(vector<Mobil>& listMobil, vector<Motor>& listMotor);
};

#endif
