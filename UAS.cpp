#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include "mobil.h"
using namespace std;

int IndexMobil, scoreSingle = 0;
int scorePlayer1 = 0, scorePlayer2 = 0;
string JawabanPengguna;
Mobil *mobil;
string NamaPengguna;
string NamaPlayer1, NamaPlayer2;

void TampilkanSoal() {
    string MobilAcak;
    int JumlahHurufAcak, PosisiHuruf;
    IndexMobil = rand() % JumlahMobil + 1;

    JumlahHurufAcak = mobil->DaftarMobil[IndexMobil].length() / 2;

    MobilAcak = mobil->DaftarMobil[IndexMobil];
    srand(time(0));
    for (int i = 0; i < JumlahHurufAcak; ++i) {
        do {
            PosisiHuruf = rand() % MobilAcak.length();
        } while (MobilAcak[PosisiHuruf] == ' ');
        MobilAcak[PosisiHuruf] = '_';
    }

    cout << "Tebak nama mobil sport berikut:" << endl;
    cout << "Mobil: " << MobilAcak << endl;
}

void MenerimaJawaban() {
    cout << "Masukkan nama mobil: ";
    getline(cin, JawabanPengguna);
}

void PeriksaJawaban(int &score) {
    if (JawabanPengguna == mobil->DaftarMobil[IndexMobil]) {
        cout << "Jawaban benar!" << endl;
        score++;
        cout << "Score: " << score << endl;
    } else {
        cout << "Jawaban salah. Jawabannya adalah " << mobil->DaftarMobil[IndexMobil] << endl;
    }
}

void SinglePlayer() {
    cout << "Masukkan nama Anda: ";
    getline(cin, NamaPengguna);
    cout << "Selamat datang, " << NamaPengguna << "!" << endl << endl;

    char lanjut;
    do {
        TampilkanSoal();
        MenerimaJawaban();
        PeriksaJawaban(scoreSingle);

        cout << "Apakah Anda ingin bermain lagi? (y/n): ";
        cin >> lanjut;
        cin.ignore(); // untuk membersihkan newline di buffer
        cout << endl;
    } while (tolower(lanjut) == 'y');
}

void Multiplayer() {
    cout << "Masukkan nama Player 1: ";
    getline(cin, NamaPlayer1);
    cout << "Masukkan nama Player 2: ";
    getline(cin, NamaPlayer2);
    cout << "Selamat datang, " << NamaPlayer1 << " dan " << NamaPlayer2 << "!" << endl << endl;

    char lanjut;
    bool giliranPlayer1 = true;

    do {
        if (giliranPlayer1) {
            cout << NamaPlayer1 << "'s turn:" << endl;
        } else {
            cout << NamaPlayer2 << "'s turn:" << endl;
        }

        TampilkanSoal();
        MenerimaJawaban();

        if (giliranPlayer1) {
            PeriksaJawaban(scorePlayer1);
        } else {
            PeriksaJawaban(scorePlayer2);
        }

        giliranPlayer1 = !giliranPlayer1; // Bergantian giliran

        cout << "Apakah Anda ingin bermain lagi? (y/n): ";
        cin >> lanjut;
        cin.ignore(); // untuk membersihkan newline di buffer
        cout << endl;
    } while (tolower(lanjut) == 'y');

    cout << "Score akhir:" << endl;
    cout << NamaPlayer1 << ": " << scorePlayer1 << endl;
    cout << NamaPlayer2 << ": " << scorePlayer2 << endl;
}

void MainMenu() {
    int pilihan;
    do {
        cout << "===== Main Menu =====" << endl;
        cout << "1. Start" << endl;
        cout << "2. About" << endl;
        cout << "3. Exit" << endl;
        cout << "Pilih opsi: ";
        cin >> pilihan;
        cin.ignore(); // untuk membersihkan newline di buffer

        switch (pilihan) {
            case 1:
                int mode;
                cout << "Pilih mode permainan:" << endl;
                cout << "1. Single Player" << endl;
                cout << "2. Multiplayer" << endl;
                cout << "Pilih mode: ";
                cin >> mode;
                cin.ignore(); // untuk membersihkan newline di buffer

                if (mode == 1) {
                    SinglePlayer();
                } else if (mode == 2) {
                    Multiplayer();
                } else {
                    cout << "Mode tidak valid. Kembali ke menu utama." << endl;
                }
                break;

            case 2:
                cout << "Game Tebak Nama Mobil Sport adalah permainan di mana Anda harus menebak nama mobil sport yang sebagian hurufnya telah diacak." << endl;
                cout << "Anda akan diberikan petunjuk berupa nama mobil dengan beberapa huruf yang dihilangkan, dan Anda harus menebak nama mobil tersebut." << endl << endl;
                break;

            case 3:
                cout << "Terima kasih telah bermain. Sampai jumpa!" << endl;
                break;

            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
        }
    } while (pilihan != 3);
}

int main() {
    srand(time(0));
    mobil = new Mobil();

    MainMenu();

    delete mobil;
    return 0;
}
