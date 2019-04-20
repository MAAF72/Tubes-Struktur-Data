#ifndef FOOD_H_INCLUDED
#define FOOD_H_INCLUDED

void CreateFood(List<InfoFood> &L, string X) {
    InfoFood Food;
    Food.NamaMakanan = X;
    Food.JumlahPelanggan = 0;
    /* Membuat Element Food dengan Info = Food, lalu memasukkannya kedalam list */
    AddToList(L, CreateElement(Food));
}

void PrintFood(List<InfoFood> L) {
    if(First(L) != NULL) {
        auto P = First(L);
        while(P != NULL) {
            Print("->" + Info(P).NamaMakanan);
            P = Next(P);
        }
    } else {
        Print("Makanan Kosong");
    }
}

auto GetFood(List<InfoFood> L, string X) {
    auto P = First(L);
    while((P != NULL) && (Info(P).NamaMakanan != X)) {
        P = Next(P);
    }
    /* P == NULL atau Info(P).NamaMakanan == X */
    return P;
}

void ViewFood(List<InfoRelation> L, ElementList<InfoFood> *P) {
    if(P != NULL) {
        Print("Nama Makanan : " + Info(P).NamaMakanan);
        Print("Jumlah Pembeli : " + to_string(Info(P).JumlahPelanggan));
        Print("Pembeli : ");
        ViewFoodsBuyers(L, P);
        Print();
    } else {
        Print("Makanan Tidak Ada!");
    }
}

void ViewAllFood(List<InfoFood> LF, List<InfoRelation> LR) {
    auto P = First(LF);
    while(P != NULL) {
        Print();
        ViewFood(LR, P);
        P = Next(P);
    }
}

void ViewCustomersFoods(List<InfoRelation> L, ElementList<InfoCustomer> *X) {
    auto P = First(L);
    while(P != NULL) {
        if(Info(P).Customer == X) {
            Print("->" + Info(Info(P).Food).NamaMakanan);
        }
        P = Next(P);
    }
}

void SortFood(List<InfoFood> &L) {
    List<InfoFood> LSort;
    CreateList(LSort);
    /* Sorting secara Descending menggunakan Algoritma Selection Sort */
    while(First(L) != NULL) {
        auto Max = First(L);
        auto P = Next(Max);
        while(P != NULL) {
            if(Info(P).JumlahPelanggan > Info(Max).JumlahPelanggan) {
                Max = P;
            }
            P = Next(P);
        }
        DeleteFromList(L, Max);
        AddToList(LSort, Max);
    }
    L = LSort;
}

#endif // FOOD_H_INCLUDED
