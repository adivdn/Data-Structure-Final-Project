#include "tubes.h"

void createListP1(ListP1 &L1){
    first(L1) = NULL;
}
void createListP2(ListP2 &L2){
    first(L2) = NULL;
}
void createListR(relasi &R){
    first(R) = NULL;
    last(R) = NULL;
}
adrR AllocationRelasi(adrP1 C,adrP2 P,int rating){
    adrR Q;
    Q = new elmrelasi;
    addressC(Q) = C;
    addressP(Q) = P;
    rating(Q) = rating;
    next(Q) = NULL;
    return Q;

}
adrP2 allocationProduk (string nama){
    adrP2 P = new elmlistP2;
    if (P != NULL){
        info(P).nama = nama;
        info(P).rating = 0;
        next(P) = NULL;
        prev(P) = NULL;
    }
    return P;

}
adrP1 allocationID(string username,string password){
    adrP1 P = new elmlistP1;

        info(P).username = username;
        info(P).password = password;
        next(P) = NULL;
        prev(P) = NULL;

    return P;

}


void HistoriProduk (ListP2 L2){
    adrP2 P;
    if (first(L2)!= NULL){
        P = first(L2);
        cout<< "\t\t ==============================  LIST PRODUK ============================== \n"<<endl;
        do{
            cout<< "\t\t\t  Produk : "<<info(P).nama<<"\t\t\t Rating : "<<info(P).rating<<endl;
            P = next(P);
        }while (P != first(L2));

        cout<<"\t\t =========================================================================== \n"<<endl;
    }
    else {
        cout<<" PRODUK KOSONG "<<endl;
    }

}
adrP1 searchAkun(ListP1 L1,string username){
    adrP1 P;
    if (first(L1)!= NULL){
        P = first(L1);
        while ((next(P)!= NULL) && (info(P).username != username)){
            P = next(P);
        }
        if (info(P).username == username){
            return P;
        }
    }
    return NULL;
}

//string searchUser(ListP1 L1,string username){
//    adrP1 P;
//    if (first(L1)!= NULL){
//        P = first(L1);
//        while ((next(P)!= NULL) && (info(P).username != username)){
//            P = next(P);
//        }
//        if (info(P).username == username){
//            return info(P).username;
//        }
//    }
//    return " i";
//}
adrP1 searchPassword (ListP1 L1,string password){
    adrP1 P;
    if (first(L1)!= NULL){
        P = first(L1);
        while ((next(P)!= NULL)&& (info(P).password != password)){
            P = next(P);
        }
        if (info(P).password == password){
            return P;
        }
    }
    return NULL;

}
void InputProduk(ListP2 &L2, adrP2 P){
    if (first(L2)== NULL){
        first(L2) = P;
        next(P) = first(L2);
        prev(P) = first(L2);
    }
    else{
        next(P) = first(L2);
        next(prev(first(L2))) = P;
        prev(P) = prev(first(L2));
        prev(first(L2)) = P;
    }


}
void InputCustomer(ListP1 &L1,adrP1 P){
    if(first(L1)!= NULL){
     if ((info(first(L1)).username) > (info(P).username)){
        if (first(L1)== NULL){
            first(L1) = P;
            next(P) = first(L1);
            prev(P) = first(L1);
        }
        else{
            next(P) = first(L1);
            prev(P) = prev(first(L1));
            next(prev(P)) = P;
            prev(next(P)) = P;
            first(L1) = P;
        }
     }
     else if((info(first(L1)).username)<(info(P).username)){
        if (first(L1)== NULL){
            first(L1) = P;
            next(P) = first(L1);
            prev(P) = first(L1);
        }
        else{
            next(P) = first(L1);
            next(prev(first(L1))) = P;
            prev(P) = prev(first(L1));
            prev(first(L1)) = P;
        }
     }
     else{
        adrP1 Prec = first(L1);
        while((info(next(Prec)).username) < (info(P).username)){
            Prec = next(Prec);
        }
        next(P) = next(Prec);
        next(Prec) = P;
        prev(next(Prec)) = P;
        prev(P) = Prec;
    }
  }
  else {
    first(L1) = P;
    next(P) = first(L1);
    prev(P) = first(L1);
  }

}
adrP2 searchProduk(ListP2 L2,string nama){
    adrP2 P;
    if (first(L2)!= NULL){
        P = first(L2);
        while (next(P)!= NULL && (info(P).nama != nama)){
            P = next(P);
        }
        if (info(P).nama == nama){
            return P;
        }
    }
    return NULL;

}
void DeleteCustomer(ListP1 &L1,adrP1 &P){
    adrP1 Q;
    if (P == first(L1)){
        if (next(first(L1))== first(L1)){
            P = first(L1);
            next(P) = NULL;
            prev(P) = NULL;
            first(L1) = NULL;
        }
        else {
            Q = first(L1);
            while (next(Q)!= first(L1)){
                Q = next(Q);
            }
            P = first(L1);
            first(L1) = next(P);
            next(Q) = next(P);
            prev(next(P)) = Q;
            next(P) = NULL;
        }

    } else if (P = prev(first(L1))){
        Q = first(L1);
            while (next(Q)!= P){
                Q = next(Q);
            }
            next(Q) = first(L1);
            prev(first(L1)) = Q;
            next(P) = NULL;
            prev(P) = NULL;

    }else{
        Q = prev(P);
        next(Q) = next(P);
        prev(next(P)) = Q;
        next(P) = NULL;
        prev(P) = NULL;
    }

}
void DeleteProduk(ListP2 &L2, adrP2 &P){
    adrP2 Q;
    if (P == first(L2)){
        if (next(P)== first(L2)){
            P = first(L2);
            next(P) = NULL;
            prev(P) = NULL;
            first(L2) = NULL;
        }
        else{
            Q = prev(first(L2));
            first(L2) = next(P);
            next(Q) = next(P);
            prev(next(P)) = Q;
            next(P) = NULL;
            prev(P) = NULL;
        }

    }else{
        Q = prev(P);
        next(Q) = next(P);
        prev(next(P)) = Q;
        next(P) = NULL;
        prev(P) = NULL;
    }

}
void HistoriCustomer(ListP1 L1,relasi R){
    adrP1 P;
    adrR Q;
    if ((first(L1)!= NULL)&&(first(R)!= NULL)){
        P = first(L1);
        cout<< "\t\t ==============================  LIST CUSTOMER ============================== \n"<<endl;
        do {
            Q = first(R);

            do{
                if (P == addressC(Q)){
                    cout<<"\t\t Customer : "<<info(P).username<<"\t\t Produk : "<<info(addressP(Q)).nama<<"\t\t Rating : "<<rating(Q)<<endl;
                }
                Q = next(Q);
            }while (Q!= NULL);

            P = next(P);
        }while (P != first(L1));
        cout<<"\t\t ============================================================================ \n"<<endl;
    }
    else if (first(L1)!= NULL){
        P = first(L1);
        cout<< "\t\t ==============================  LIST CUSTOMER ============================== \n"<<endl;
        do {
            cout<< "\t\t Customer : "<<info(P).username<<endl;
            P = next(P);
        }while(P!= first(L1));
        cout<<"\t\t ============================================================================ \n"<<endl;
    }
    else{
        cout<<" CUSTOMER KOSONG "<<endl;
    }

}
void RatingTertinggi(ListP2 L2){
    adrP2 P,q,r;
    produk temp;
    cout<< "\t\t ==============================  LIST RATING TERTINGGI ============================== \n"<<endl;
//        for(int i = 0;i<= 9;i++){
//            P = first(L3);
//            q = first(L3);
//            if(first(L3)!= NULL){
//              do{
//                 if ((info(q).rating) > info(P).rating){
//                    P = q;
//                }
//                q = next(q);
//            }while(q != first(L3));
//            cout<<"\t\t\t  Produk : "<<info(P).nama<<"\t\t\t Rating : "<<info(P).rating<<endl;
//            DeleteProduk(L3,P);
//            }
//        }
    P = first(L2);
    if(first(L2)!= NULL){
        do{
            if(next(P)!= first(L2)){
                q = next(P);
                do{
                    if(info(q).rating > info(P).rating){
                        temp.nama = info(P).nama;
                        temp.rating = info(P).rating;
                        info(P).nama = info(q).nama;
                        info(P).rating = info(q).rating;
                        info(q).nama = temp.nama;
                        info(q).rating = temp.rating;
                    }
                    q  = next(q);
                }while(q != first(L2));

            }
            P = next(P);
        }while(P != first(L2));
    }
    r = first(L2);
        do{
            cout<<"\t\t\t  Produk : "<<info(r).nama<<"\t\t\t Rating : "<<info(r).rating<<endl;
            r = next(r);
        }while(r != first(L2));


    cout<<"\t\t ==================================================================================== \n"<<endl;
}

void InsertLastRelasi(relasi &R,adrR P){
    if(first(R)== NULL){
        first(R) = P;
        last(R) = P;
    }
    else{
        next(last(R)) = P;
        last(R) = P;
    }


}
adrR GantiRating(relasi R,adrP1 P){
    adrR Q;
    if (first(R)!= NULL){
        Q = first(R);
        while ((Q!=NULL)&&(addressC(Q)!= P)){
            Q = next(Q);
        }
        if (addressC(Q) == P){
            return Q;
        }

    }
    return NULL;
}

void DeleteRelasi(relasi &R,adrR P){
    if (P == first(R)){
        if(next(P)== NULL){
            P = first(R);
            first(R) = NULL;
            last(R) = NULL;
        }
        else{
            P = first(R);
            first(R) = next(P);
            next(P) = NULL;
        }
    }
    else if(P == last(R)){
        adrR Q = first(R);
        while (next(Q) != P){
            Q = next(Q);
        }
        last(R) = Q;
        next(Q) = NULL;
    }
    else{
        adrR Q = first(R);
        while (next(Q)!= P){
            Q = next(Q);
        }
        next(Q) = next(P);
        next(P) = NULL;
    }

}
void PrintProduk(ListP2 L2,relasi R){
    adrR P;
    adrP2 Q;
    if ((first(L2)!= NULL)&& first(R)!= NULL){
        Q = first(L2);
         cout<< "\t\t ==============================  LIST PRODUK ============================== \n"<<endl;
        do{
            P = first(R);
            do{
                if(Q == addressP(P)){
                    cout<<" \t\t Produk : "<<info(Q).nama<<"\t\t Customer : "<<info(addressC(P)).username<<"\t\t Rating : "<<rating(P)<<endl;
                }
                P = next(P);
            } while (P != NULL);
            Q = next(Q);
        }while (Q != first(L2));

        cout<<"\t\t ========================================================================== \n"<<endl;
    }else{
        cout<< " PRODUK KOSONG "<<endl;
    }

}

