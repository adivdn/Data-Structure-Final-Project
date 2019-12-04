#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
#define Nil NULL
#define rating(Q) (Q)->rating
#define addressC(P) (P)->addressC
#define addressP(P) (P)->addressP
#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define first(L) ((L).first)
#define last(L) ((L).last)

using namespace std;

struct id{
    string username;
    string password;
};
struct produk{
    string nama;
    int rating;
};
typedef struct elmlistP1 *adrP1;
typedef struct elmlistP2 *adrP2;
typedef struct elmrelasi *adrR;

struct elmlistP1{
    id info;
    adrP1 next;
    adrP1 prev;
};
struct elmlistP2{
    produk info;
    adrP2 next;
    adrP2 prev;
};
struct elmrelasi{
    adrP1 addressC;
    adrP2 addressP;
    int rating;
    adrR next;
};

struct ListP1{
    adrP1 first;
};
struct ListP2{
    adrP2 first;
};
struct relasi{
    adrR first;
    adrR last;
};

// Create List Baru
void createListP1(ListP1 &L1);
void createListP2(ListP2 &L2);
void createListR(relasi &R);

// Alokasi

adrR AllocationRelasi(adrP1 C,adrP2 P,int rating);
adrP2 allocationProduk(string nama);
adrP1 allocationID(string username , string password);

// View All Parent Data
void HistoriProduk(ListP2 L2);
void HistoriCustomer(ListP1 L1,relasi R);
void PrintProduk(ListP2 L2,relasi R);

// Searching
adrP1 searchAkun(ListP1 L1,string username);
adrP1 searchPassword(ListP1 L1,string password);
adrP2 searchProduk(ListP2 L2,string nama);

// Input Dan Delete Data

void InputProduk(ListP2 &L2, adrP2 P);
void InputCustomer(ListP1 &L1,adrP1 P);
void DeleteProduk(ListP2 &L2,adrP2 &P);
void DeleteCustomer(ListP1 &L1,adrP1 &P);
void UpdateCustomer(ListP1 L1,string username,string password);
void DeleteRelasi(relasi &R,adrR P);

// Relasi

void RatingTertinggi(ListP2 L2);
void InsertLastRelasi(relasi &R,adrR P);
adrR GantiRating(relasi R,adrP1 P);




#endif // TUBES_H_INCLUDED
