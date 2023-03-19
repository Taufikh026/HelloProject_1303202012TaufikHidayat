#include <cstdlib>
#include <iostream>
#include "movieP.h"

//Taufik Hidayat
//1303202012

int main()
{
    // Jadi yang direlasikan itu variable Nama_Movie dari parent MOVIE dan variable Dibintangi dari child AKTOR  :)

    list_movie m;
    // createListmovie(d);      // Buat dulu Prosedurenya
    list_aktor d;
    // createListaktor(m);      // Buat dulu Prosedurenya
    list_relasi r;
    // createListrelasi(r);     // Buat dulu Prosedurenya
    // adr_movie p;             // biar kepake buat fungsionalitas 1 - 5 (buat masukin insert dan function Create Elm)
    // adr_aktor q;             // biar kepake buat fungsionalitas 1 - 5 (buat masukin insert dan functionCreate Elm)
    movie movie;
    aktor aktor;
    int pilihan = -1;
    // int x;                   // Ini buat looping insert data movie sama aktornya
    // INI FUNGSI K PROGRAM UTAMA
    while (pilihan != 0){
        cout << "++++++++++++++++++++++++++++++++++++++++++ PROGRAM UTAMA ++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "1.  Menambahkan data movie." << endl;
        cout << "2.  Menambahkan data aktor/aktris." << endl;
        cout << "3.  Mencari data movie tertentu." << endl;
        cout << "4.  Menambahkan relasi aktor/aktris dengan movie yang dibintanginya." << endl;
        cout << "5.  Mencari data movie yang dibintangi oleh aktor atau aktris tertentu." << endl;
        cout << "6.  Menghapus data movie berserta relasinya." << endl;
        cout << "7.  Menghapus data aktor/aktris pada movie tertentu." << endl;
        cout << "8.  Menampilkan data seluruh movie beserta semua aktor/aktris yang membintanginya." << endl;
        cout << "9.  Menghitung banyaknya movie yang dimainkan oleh seorang aktor/aktris tertentu." << endl;
        cout << "10. Menampilkan data movie yang paling banyak dibintangi oleh aktris." << endl;
        cout << "0. Exit" << endl;
        cout << "++++++++++++++++++++++++++++++++++++++ MEMILIH MENU +++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "Pilihan menu : ";
        cin >> pilihan;
        switch(pilihan){
        case 1:
            //Insert data ovie
                system("pause");
                system("cls");
                break;
        case 2:
            //insert data Aktor
                system("pause");
                system("cls");
                break;
        case 3:
             // Cari data Movie Tertentu
                system("pause");
                system("cls");
                break;
        case 4:
            // Menambah relasi aktor dengan movie
                system("pause");
                system("cls");
                break;
        case 5:
            // Mencari data Movie oleh aktor tertentu
                system("pause");
                system("cls");
                break;
        case 6:
            // Menghapus data movie beserta relasinya
            cout << "data relasi yang akan dihapus" << endl;
            cout << "Masukkan Nama movie Pembimbing: ";
            cin >> movie.nama_movie;
            cout << "Masukkan Nama aktor: ";
            deleterelasi2(r,movie,aktor);
                system("pause");
                system("cls");
                break;
        case 7:
            // Menghapus data aktor pada movie tertentu
            cout << "Masukan Nama Aktor yang mau dihapus: ";
            cin >> aktor.nama_aktor;
            deleteaktor(d,r,aktor);
                system("pause");
                system("cls");
                break;
        case 8:
            // Menampilkan data seluruh movie beserta aktor
            viewrelasi(m,r);
                system("pause");
                system("cls");
                break;
        case 9:
            // Menghitung banyaknya movie yang dimainkan
            cout << "Jumlah movie yang dimainkan oleh seorang aktor/aktris tertentu = "<< countJMLHmovie(m,r,movie) << endl;
                system("pause");
                system("cls");
                break;
        case 10:
            // Menampilkan data movie yang paling banyak dibintangi
            viewaktor1(r,m);
                system("pause");
                system("cls");
                break;
        case 0:
            cout << "PROGRAM KELUAR!!" << endl;
        }
    }
    return 0;
}
