#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

ElementList<InfoCustomer> *CreateCustomer(List<InfoCustomer> &L, string X) {
    InfoCustomer Customer;
    Customer.NamaPelanggan = X;
    Customer.JumlahMakanan = 0;
    ElementList<InfoCustomer> *C = CreateElement(Customer);
    AddToList(L, C);
    return C;
}

void PrintCustomer(List<InfoCustomer> L) {
    if(First(L) != NULL) {
        ElementList<InfoCustomer> *P = First(L);
        while(P != NULL) {
            Print("->" + Info(P).NamaPelanggan);
            P = Next(P);
        }
    } else {
        Print("Pelanggan kosong");
    }
}

ElementList<InfoCustomer> *GetCustomer(List<InfoCustomer> L, string X) {
    ElementList<InfoCustomer> *P = First(L);
    while((P != NULL) && (Info(P).NamaPelanggan != X)) {
        P = Next(P);
    }
    return P;
}

void ViewCustomer(List<InfoRelation> L, ElementList<InfoCustomer> *P) {
    if(P != NULL) {
        Print("Nama Pelanggan : " + Info(P).NamaPelanggan);
        Print("Jumlah Makanan : " + to_string(Info(P).JumlahMakanan));
        Print("Makanan : ");
        ViewCustomersFoods(L, P);
        Print();
    } else {
        Print("Pelanggan Tidak Ada!");
    }
}

void ViewAllCustomer(List<InfoCustomer> LC, List<InfoRelation> LR) {
    ElementList<InfoCustomer> *P = First(LC);
    while(P != NULL) {
        Print();
        ViewCustomer(LR, P);
        P = Next(P);
    }
}

void ViewFoodsBuyers(List<InfoRelation> L, ElementList<InfoFood> *X) {
    ElementList<InfoRelation> *P = First(L);
    while(P != NULL) {
        if(Info(P).Food == X) {
            Print("->" + Info(Info(P).Customer).NamaPelanggan);
        }
        P = Next(P);
    }
}

void SortCustomer(List<InfoCustomer> &L) {
    ElementList<InfoCustomer> *Max, *P;
    List<InfoCustomer> LSort;
    CreateList(LSort);
    while(First(L) != NULL) {
        Max = First(L);
        P = Next(Max);
        while(P != NULL) {
            if(Info(P).JumlahMakanan > Info(Max).JumlahMakanan) {
                Max = P;
            }
            P = Next(P);
        }
        DeleteFromList(L, Max);
        AddToList(LSort, Max);
    }
    L = LSort;
}

#endif // CUSTOMER_H_INCLUDED
