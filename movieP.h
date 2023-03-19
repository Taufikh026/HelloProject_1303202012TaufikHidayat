#ifndef MOVIEP_H_INCLUDED
#define MOVIEP_H_INCLUDED

#include <iostream>
using namespace std;

#define first_movie(L) L.first_movie
#define info_movie(P) P->info_movie
#define next_movie(P) P->next_movie
#define prev_movie(P) P->prev_movie

#define first_aktor(L) L.first_aktor
#define last_aktor(L) L.last_aktor
#define info_aktor(P) P->info_aktor
#define next_aktor(P) P->next_aktor
#define prev_aktor(P) P->prev_aktor

#define first_relasi(L) L.first_relasi
#define next_relasi(P) P->next_relasi

struct infotype_movie{
    string genre;
    string nama_movie;
    int tahun;
};

struct infotype_aktor{
 string nama_aktor;
 int umur;
 string dibintangi;
 int tinggi;
};

typedef infotype_movie movie;
typedef infotype_aktor aktor;

typedef struct elm_aktor *adr_aktor;
typedef struct elm_movie *adr_movie;
typedef struct elm_relasi *adr_relasi;

// Bagian parent Single Linked List
struct list_movie{
    adr_movie first_movie;
};

// Bagian Child Double Linked List Circular
struct list_aktor{
    adr_aktor first_aktor;
    adr_aktor last_aktor;

};

// Bagian relasi Single Linked List
struct list_relasi{
    adr_relasi first_relasi;
};

/** Membuat Elemen aktor*/
struct elm_aktor{
    infotype_aktor info_aktor;
    adr_aktor next_aktor;
    adr_aktor prev_aktor;
};

struct elm_movie{
    infotype_movie info_movie;
    adr_movie next_movie;
    adr_movie prev_movie;

};

struct elm_relasi{
    adr_aktor next_aktor;
    adr_movie next_movie;
    adr_relasi next_relasi;
};

void deleteAfteraktor(list_aktor &m, adr_aktor p);
void deleterelasi(list_relasi &r, adr_relasi p);
adr_aktor searchaktor(list_aktor m, aktor aktor);
void deleterelasi2(list_relasi &r, movie movie, aktor aktor);
void deleteaktor(list_aktor &m, list_relasi &r, aktor aktor);
void viewrelasi(list_movie d, list_relasi r);
int countJMLHmovie(list_movie m,list_relasi r,movie movie);
void viewaktor1(list_relasi r, list_movie d);
#endif // MOVIEP_H_INCLUDED
