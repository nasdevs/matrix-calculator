#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int ordo_baris_MA, ordo_kolom_MA;
    int ordo_baris_MB, ordo_kolom_MB;
    int baris_MA, kolom_MA;
    int baris_MB, kolom_MB;
    int input_baris, input_kolom;
    int total = 0;
    int pilih_menu;
    bool penjumlahan = false;
    bool pengurangan = false;
    bool perkalian = false;
    bool output = false;
    char ulang;

    // Ketentuan
    cout << "==========Ketentuan aritmatika pada matriks==========" << "\n";
    cout << "1. Penjumlahan dan Pengurangan matriks : harus memiliki ordo yang sama" << "\n";
    cout << "2. Perkalian matriks : kolom matriks A dan baris matriks B memiliki jumlah yang sama" << "\n";
    cout << "-----------------------------  ------------------------" << "\n";

    // input ordo matriks
    cout << "Input ordo Matriks A" << endl;
    cout << "Input baris Matriks A : "; cin >> baris_MA;
    cout << "Input kolom Matris A  : "; cin >> kolom_MA;
    cout << "-----------------------------" << "\n";

    cout << "Input ordo Matriks B" << endl;
    cout << "Input baris Matriks B : "; cin >> baris_MB;
    cout << "Input kolom Matris B  : "; cin >> kolom_MB;
    cout << "-----------------------------" << "\n";

    int matriks_A[baris_MA][kolom_MA];
    int matriks_B[baris_MB][kolom_MB];
    int result[baris_MA][kolom_MB];
    

    cout << "Matriks A" << endl;
    for (int i = 0; i < baris_MA; i++) {
        for (int j = 0; j < kolom_MA; j++) {
            cout << "Input Matriks [" << i << "] [" << j << "] : "; cin >> matriks_A[i][j];
        }
        cout << "\n";
    }

    cout << "\nMatriks B" << endl;
    for (int i = 0; i < baris_MB; i++) {
        for (int j = 0; j < kolom_MB; j++) {
            cout << "Input Matriks [" << i << "] [" << j << "] : "; cin >> matriks_B[i][j];
        }
        cout << "\n";
    }

    if (baris_MA == kolom_MA && baris_MB == kolom_MB) {
        penjumlahan = true;
        pengurangan = true;
    }

    if (kolom_MA == baris_MB) perkalian = true;

    do {
        system("cls");
        cout << "========Menu========" << "\n";
        cout << "1. Penjumlahan : " << (penjumlahan == true ? "Y" : "N") << "\n";
        cout << "2. Pengurangan : " << (pengurangan == true ? "Y" : "N") << "\n";
        cout << "3. Perkalian   : " << (perkalian   == true ? "Y" : "N") << "\n";
        cout << "4. Keluar" << "\n";
        cout << "Ket : Y (Tersedia) | N (Tidak tersedia)" << "\n";
        cout << "Pilih [1...3] : "; cin >> pilih_menu;

        // penjumlahan
        if (pilih_menu == 1 && penjumlahan == true) {
            output = true;
            for (int i = 0; i < baris_MA; i++) {
                for (int j = 0; j < baris_MA; j++) {
                    result[i][j] = matriks_A[i][j] + matriks_B[i][j];
                }
            }
            cout << "Penjumlahan Matriks " << baris_MA << " x " << kolom_MA << " dan " << baris_MB << " x " << kolom_MB  << " : " << "\n";
        }

        // pengurangan
        else if (pilih_menu == 2 && pengurangan == true) {
            output = true;
            for (int i = 0; i < baris_MA; i++) {
                for (int j = 0; j < baris_MA; j++) {
                    result[i][j] = matriks_A[i][j] - matriks_B[i][j];
                }
            }
            cout << "Pengurangan Matriks " << baris_MA << " x " << kolom_MA << " dan " << baris_MB << " x " << kolom_MB  << " : " << "\n";
        }
        
        // perkalian
        else if (pilih_menu == 3 && perkalian == true) {
            output = true;
            for (int i = 0; i < baris_MA; i++) {
                for (int j = 0; j < kolom_MB; j++) {
                    for (int k = 0; k < baris_MB; k++) {
                        total += matriks_A[j][k] * matriks_B[k][j];
                    }
                    result[i][j] = total;
                    total = 0;
                }
            }
            cout << "Perkalian Matriks " << baris_MA << " x " << kolom_MA << " dan " << baris_MB << " x " << kolom_MB  << " : " << "\n";
        }
        
        else if (pilih_menu == 4) return 0;

        else cout << "Pilihan tidak tersedia atau tidak sesuai ketentuan" << "\n";

        // output

        if (output == true) {
            for (int i = 0; i < baris_MA; i++) {
                for (int j = 0; j < kolom_MB; j++) {
                    cout << setw(5) << result[i][j];
                }
                cout << "\n";
            }
        }

        output = false;
        cout << "Input ulang [y/n] : "; cin >> ulang;
    }
    while(ulang == 'Y' || ulang == 'y');
}
