#include <iostream>
#include <stdlib.h>
#include "tubes.h"
#include <windows.h>
#include <conio.h>

using namespace std;

void gotoxy(int x,int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int main()
{
    string username,password,nama,pass;
    int pil,rating;
    ListP1 L1;
    createListP1(L1);
    adrP1 P;
    adrP2 q;
    adrR S,Q;
    ListP2 L2,L3;
    createListP2(L2);
    relasi R;
    createListR(R);
    int jum,counter;

    do{
        awal:
        system("cls");
        gotoxy(60,25); cout << " Copyright © 2019 "<<endl;
        gotoxy(60,26); cout << " Created by Adiv Harjadinata            (1301183484) "<<endl;
        gotoxy(60,27); cout << "            Rifqi Zaidan Irsyad Yanis   (1301180020) "<<endl;
        gotoxy(49,9);  cout << " =========================== ";
        gotoxy(49,10); cout << " ||                       ||";
        gotoxy(49,11); cout << " ||        Login          ||"<<endl;
        gotoxy(49,12); cout << " ||                       ||";
        gotoxy(49,16); cout << " =========================== ";
        gotoxy(49,15); cout << " ||                       ||";
        gotoxy(49,13); cout << " ||   Username :          ||"; gotoxy(65,13); cin>>username;
        gotoxy(49,14); cout << " ||   Password :          ||"; gotoxy(65,14); cin>>password;

        if ((username == "admin")&&(password == "admin") ){
            system("cls");
            system("pause");
            do{
            system("cls");
            cout << " 1. Input Data Produk "<<endl;
            cout << " 2. Delete Data Produk "<<endl;
            cout << " 3. View Data Produk "<<endl;
            cout << " 4. View Data Customer "<<endl;
            cout << " 5. Hapus Customer "<<endl;
            cout << " 6. View Detail Produk "<<endl;
            cout << " 0. EXIT "<<endl;
            cout << " Masukkan Pilihan : ";
            cin >> pil;
            switch (pil){
            case 1 :
                system("cls");
                cout << " Masukkan Nama Produk : "; cin >> nama;
                q = allocationProduk(nama);
                InputProduk(L2,q);
                cout<<endl;
                cout<<" PRODUK BERHASIL DITAMBAHKAN BOSSQUE "<<endl;
                cout<<endl;
                system("pause");
                break;
            case 2 :
                system("cls");
                HistoriProduk(L2);
                cout<<" Masukkan Nama Produk Yang Akan Dihapus : "; cin>>nama;
                q = searchProduk(L2,nama);
                if (q != NULL){
                Q = first(R);
                while(Q!= NULL){
                    if (q == addressP(Q)){
                        DeleteRelasi(R,Q);
                        Q = first(R);
                    }
                    else{
                        Q = next(Q);
                    }
                }
                DeleteProduk(L2,q);
                cout<<" Produk Berhasil Di Delete "<<endl;
                cout<<endl;
                }
                else{
                    cout<< " PRODUK TIDAK ADA "<<endl;
                    cout<<endl;
                }
                system("pause");
                break;
            case 3 :
                system("cls");
                HistoriProduk(L2);
                system("pause");
                cout<<endl;
                break;
            case 4 :
                system("cls");
                HistoriCustomer(L1,R);
                system("pause");
                cout<<endl;
                break;
            case 5 :
                system("cls");
                cout << " Masukkan Username Yang Akan Dihapus : "; cin >> nama;
                P = searchAkun(L1,nama);
                if (P!= NULL){
                Q = first(R);
                while(Q!= NULL){
                    if(P == addressC(Q)){
                        DeleteRelasi(R,Q);
                        Q = first(R);
                    }
                    else{
                        Q = next(Q);
                    }

                }
                DeleteCustomer(L1,P);
                cout<<" Customer Berhasil Di Delete "<<endl;
                cout<<endl;
                }
                else{
                    cout << " USERNAME TIDAK ADA "<<endl;
                    cout <<endl;
                }
                system("pause");
                break;
            case 6 :
                system("cls");
                PrintProduk(L2,R);
                system("pause");
                break;
            default :
                break;
                cout<<endl;
                }
            }while (pil != 0);

        }else if ((username == "guest")&& (password == "guest")){
             system("cls");
             system("pause");
            do {
                system("cls");
                cout << " 1. Sign Up Customer "<<endl;
                cout << " 2. View Top 10 Produk "<<endl;
                cout << " 3. View All Produk "<<endl;
                cout << " 0. EXIT "<<endl;
                cout << " Masukkan Pilihan : ";
                cin >> pil;
                switch (pil){
                case 1 :
                    system("cls");
                    cout << " Masukkan Username Baru : "; cin >> nama;
                    cout << " Masukkan Password Baru : "; cin >> pass;
                    P = allocationID(nama,pass);
                    if (searchAkun(L1,nama)){
                        cout<< " Username Sudah Ada "<<endl;
                    }
                    else{
                    InputCustomer(L1,P);
                    cout<<" Customer Berhasil Di Tambah "<<endl;
                    }
                    system("pause");
                    break;
                case 2 :
                    system("cls");
                    L3 = L2;
                    RatingTertinggi(L3);
                    system("pause");
                    cout<<endl;
                    break;
                case 3 :
                    system("cls");
                    HistoriProduk(L2);
                    cout<<endl;
                    system("pause");
                    break;
                }

             }while(pil != 0);

          }else if ((searchAkun(L1,username)!= NULL)&& (searchPassword(L1,password)!= NULL)){
            system("cls");
            system("pause");
            do{
                system("cls");
                cout<<"";
                cout << " 1. Add Rating "<<endl;
                cout << " 2. Ubah Rating "<<endl;
                cout << " 3. Histori Rating Produk "<<endl;
                cout << " 4. Update Akun "<<endl;
                cout << " 0. EXIT "<<endl;
                cout << " Masukkan Pilihan : ";
                cin >> pil;
                switch (pil){
                case 1 :
                    system("cls");
                    cout<<" Masukkan Nama Produk Yang mau DiRating : ";
                    cin >> nama;
                    P = searchAkun(L1,username);
                    q = searchProduk(L2,nama);
                    if (q != NULL){
                        cout<<" Masukkan rating nya (0 - 5) : ";
                        cin >> rating;
                        InsertLastRelasi(R,AllocationRelasi(P,q,rating));
                        info(q).rating = rating;
                        cout<<endl;
                        system("pause");
                    }
                    else{
                        system("cls");
                        cout<<" Produk Tidak Ada Bossque "<<endl;
                        system("pause");
                    }
                    break;
                case 2 :
                    system("cls");
                    cout<<" Masukkan Rating Baru : ";
                    cin >> rating;
                    S = GantiRating(R,P);
                    rating(S) = rating;
                    info(q).rating = rating;
                    cout<<" Rating Berhasill Di Ubah "<<endl;
                    system("pause");
                    break;
                case 3 :
                    system("cls");
                    S = GantiRating(R,P);
                    cout<<" Histori Produk Oleh Akun : "<<info(P).username<<endl;
                    while(S != NULL){
                        if (addressC(S)== P){
                        cout<<" Nama Produk : "<<info(addressP(S)).nama<<" || "<<" Rating Produk : "<<rating(S)<<endl;
                        }
                        S = next(S);
                    }
                    cout<<endl;
                    system("pause");
                    break;
                case 4 :
                    system("cls");
                    cout<<" Masukkan Username Lama Anda : "; cin>>nama;
                    cout<<" Masukkan Password Lama Anda : "; cin >> pass;
                    cout<<endl;
                    if ((searchAkun(L1,nama)!= NULL)&&(searchPassword(L1,pass)!= NULL)){
                        cout << " Masukkan Username Baru Anda : "; cin >> nama;
                        cout << " Masukkan Password Baru Anda : "; cin >> pass;
                        info(P).username = nama;
                        info(P).password = pass;
                        cout<<endl;
                        cout<<" -- AKUN ANDA TELAH DI UPDATE -- "<<endl;
                        cout<<endl;
                   }
                   system("pause");
                  break;
                default :
                    break;
                    cout<<endl;
                }


            }while(pil != 0);


         }else{
            system("cls");
            gotoxy(30,13);cout<<" MAAF CUSTOMER TIDAK ADA DI LIST "<<endl;
            gotoxy(30,14);cout<<" Jika Ingin Membuat Akun Baru , Masuk Melalui Username = guest dan Password = guest "<<endl;
            gotoxy(60,25);system("pause");
            goto awal;
         }


    }while ((username != "exit") && (password != "exit"));
    system("cls");


    return 0;
}
