#include "movieP.h"
// ========================= TAMBAHAN ========================
void deleteAfteraktor(list_aktor &m, adr_aktor p){
    // Delete After
    if (p == first_aktor(m)){
        first_aktor(m) = next_aktor(p);
    } else{
        adr_aktor q = first_aktor(m);
        while (next_aktor(q) != p){
            q = next_aktor(q);
        }
        next_aktor(q) = next_aktor(p);
    }
}

void deleterelasi(list_relasi &r, adr_relasi p){
    // Delete After
    if (p == first_relasi(r)){
        first_relasi(r) = next_relasi(p);
    } else{
        adr_relasi rr = first_relasi(r);
        while (next_relasi(rr) != p){
            rr = next_relasi(rr);
        }
        next_relasi(rr) = next_relasi(p);
    }
}

adr_aktor searchaktor(list_aktor m, aktor aktor){
    // Mencari Aktor
    adr_aktor q = first_aktor(m);
    while (q != NULL){
        if (info_aktor(q).nama_aktor == aktor.nama_aktor){
            return q;
        }
        q = next_aktor(q);
    }
    return NULL;
}


// ========================= FUNGSIONALITAS F - K =========================
void deleterelasi2(list_relasi &r, movie movie, aktor aktor){
    adr_relasi rr = first_relasi(r);
    if (rr != NULL){
        while ((info_movie(next_movie(rr)).nama_movie != movie.nama_movie) || (info_aktor(next_aktor(rr)).nama_aktor != aktor.nama_aktor && next_relasi(rr) != NULL)){
            rr = next_relasi(rr);
        }
        if ((info_movie(next_movie(rr)).nama_movie == movie.nama_movie) && (info_aktor(next_aktor(rr)).nama_aktor == aktor.nama_aktor)){
            next_movie(rr) = NULL;
            next_aktor(rr) = NULL;
           deleterelasi(r, rr);
        }
        cout << "PENGHAPUSAN BERHASIL" << endl;
    } else{
        cout << "BELUM DITEMUKAN RELASI" << endl;
    }
}

void deleteaktor(list_aktor &m, list_relasi &r, aktor aktor){
    adr_aktor q = searchaktor(m, aktor); //Mencari aktor pada movie tertentu
    adr_relasi rr = first_relasi(r);
    if (q != NULL){
        while (rr != NULL){
            if (next_aktor(rr) == q){
                next_aktor(rr) = NULL;
                next_movie(rr) = NULL;
                deleterelasi(r,rr);
            }
            rr = next_relasi(rr);
        }
        if (q == first_aktor(m)){
            first_aktor(m) = next_aktor(q);
            next_aktor(q) = NULL;
        } else if (next_aktor(q) == NULL){
            adr_aktor o = first_aktor(m);
            while (next_aktor(o) != q){
                o = next_aktor(o);
            }
            next_aktor(o) = next_aktor(q);
            next_aktor(q) = NULL;
        } else {
            deleteAfteraktor(m,q);
        }
        cout << "PENGHAPUSAN BERHASIL" << endl;
    } else {
        cout << "Kosong" << endl;
    }
}

 void viewrelasi(list_movie d, list_relasi r){
    adr_movie p = first_movie(d);
    adr_relasi rr = first_relasi(r);
    if (p != NULL && rr != NULL){
        while (p != NULL){
            cout << "Nama movie\t\t: " << info_movie(p).nama_movie << endl;
            cout << "genre\t\t: " << info_movie(p).genre << endl;
            cout << "Tahun rilis\t: " << info_movie(p).tahun << endl;
            cout << "[ Berelasi dengan ] ---->" << endl;
            adr_relasi rr = first_relasi(r);
            while (rr != NULL){
                if (info_movie(next_movie(rr)).nama_movie == info_movie(p).nama_movie){
                    cout << "Nama aktor\t\t: " << info_aktor(next_aktor(rr)).nama_aktor<< endl;
                    cout << "Umur\t\t\t: " << info_aktor(next_aktor(rr)).umur<< endl;
                    cout << "Dibintangi\t: " << info_aktor(next_aktor(rr)).dibintangi<< endl;
                    cout << "Tinggi\t\t: " << info_aktor(next_aktor(rr)).tinggi<< endl;
                    cout << endl;
                }
                rr = next_relasi(rr);
            }
            cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            p = next_movie(p);
        }
    } else if (p != NULL && rr == NULL){
        while (p != NULL){
            cout << "Nama movie\t\t: " << info_movie(p).nama_movie << endl;
            cout << "Genre\t\t: " << info_movie(p).genre << endl;
            cout << "Jumlah aktor\t: " << info_movie(p).tahun << endl;
            cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            cout << "Nama aktor\t\t: Kosong" <<  endl;
            cout << "Umur\t\t\t: Kosong " << endl;
            cout << "Dibintangi\t\t: Kosong" << endl;
            cout << "Tinggi\t\t: Kosong" << endl;
            cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            p = next_movie(p);
        }
    } else if (p == NULL && rr == NULL){
        cout << "Data movie dan Data aktor belum direlasikan" << endl;
        cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    }
}

int countJMLHmovie(list_movie m,list_relasi r,movie movie){
    adr_movie p = first_movie(m);
    adr_relasi rr = first_relasi(r);
    int i;
    i = 0;
    while(rr != NULL){
        if(info_movie(next_movie(rr)).nama_movie == info_movie(p).nama_movie || info_movie(next_movie(rr)).nama_movie == info_aktor(next_aktor(rr)).dibintangi){
            i++;
        }
        rr = next_relasi(rr);
    }
    return i;
}

void viewaktor1(list_relasi r, list_movie d){ //revisi
    movie movie;
    adr_movie p = first_movie(d);
    adr_relasi rr = first_relasi(r);
    int total = 0;
    cout << "Masukkan nama movie : ";
    cin >> movie.nama_movie;
    cout << "+++++++++++++++++ Data aktor berdasarkan movie +++++++++++++++++" << endl;
    if (p != NULL){
            while (rr != NULL){
                    aktor aktor;
                    if (info_movie(next_movie(rr)).nama_movie == info_aktor(next_aktor(rr)).dibintangi ){
                        total++;
                        cout << "Nama aktor\t: " << info_aktor(next_aktor(rr)).nama_aktor << endl;
                        cout << "Umur\t\t: " << info_aktor(next_aktor(rr)).umur << endl;
                        cout << "Dibintangi\t: " << info_aktor(next_aktor(rr)).dibintangi << endl;
                        cout << "Tinggi\t: " << info_aktor(next_aktor(rr)).tinggi << endl;
                    } else {
                        cout << "Kosong" << endl;
                    }
                    rr = next_relasi(rr);
                    cout << endl;
            }
            cout << "Jumlah aktor yang terbanyak  di Movie tersebut sebanyak : " << total << endl;
    } else {
            cout << "Kosong" << endl;
    }
}

// ===== FUNGSIONALITAS K LANGSUNG DI MAIN =====
