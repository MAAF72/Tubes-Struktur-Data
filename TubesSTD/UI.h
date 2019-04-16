#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED

void Continue() {
    system("pause");
}

void Print(string X, string End) {
    cout << X << End;
}

string GetInput(string X) {
    string Temp;
    Print(X, "");
    getline(cin, Temp);
    return Temp;
}

void ClearScreen() {
    system("cls");
}

void MenuUser(List<InfoCustomer> &LC, List<InfoFood> LF, List<InfoRelation> &LR, string Nama) {
    if(GetCustomer(LC, Nama) == NULL) {
        string Makanan;
        Print("Selamat datang " + Nama + " di AKMJ Caffe ^_^");
        auto C = CreateCustomer(LC, Nama);
        SortFood(LF);
        Print("\n=========================================");
        PrintFood(LF); //Menu yang tampil sudah tersorting
        Print("=========================================\n");
        Makanan = GetInput("Pilih Makanan : ");
        while(Makanan != "x") {
            auto F = GetFood(LF, Makanan);
            F != NULL ? CreateRelation(LR, F, C) : Print("Maaf " + Makanan + " tidak tersedia");
            Makanan = GetInput("Pilih Makanan : ");
        }
        Print("\nTerimakasih ^_^");
        Continue();
    } else {
        Print("MAAF, SUDAH ADA PELANGGAN DENGAN NAMA YANG SAMA!");
        Continue();
    }
}

void MenuAdmin(List<InfoCustomer> &LC, List<InfoFood> &LF, List<InfoRelation> &LR) {
    string Decision;
    do {
        Print("SELAMAT DATANG DI MENU ADMIN");
        Print("[1] Input Menu");
        Print("[2] Lihat Pesanan");
        Print("[3] Delete Menu");
        Print("\n[0] Kembali");
        Decision = GetInput("\nPilih Menu : ");
        ClearScreen();
        if(Decision == "1") {
            string Makanan = GetInput("Masukkan nama makanan : ");
            while(Makanan != "x") {
                auto F = GetFood(LF, Makanan);
                F == NULL ? CreateFood(LF, Makanan) : Print("Maaf " + Makanan + " sudah tersedia");
                Makanan = GetInput("Masukkan nama makanan : ");
            }
        } else if(Decision == "2") {
            string Decision2;
            do {
                Print("[1] Lihat Pesanan dari makanan");
                Print("[2] Lihat Pesanan dari pelanggan");
                Print("\n[0] Kembali");
                Decision2 = GetInput("\nPilih Menu : ");
                ClearScreen();
                if(Decision2 == "1") {
                    string Makanan;
                    Print("[ALL] Tampilkan semua pesanan");
                    Print("[FAV] Tampilkan menu yang paling banyak dipesan");
                    Print("[Nama Makanan] Tampilkan pesanan tertentu");
                    do {
                        Makanan = GetInput("\nMasukkan nama makanan : ");
                        if(Makanan == "ALL") ViewAllFood(LF, LR);
                        else if(Makanan == "FAV") SortFood(LF), ViewFood(LR, First(LF));
                        else if(Makanan != "x") ViewFood(LR, GetFood(LF, Makanan));
                    } while(Makanan != "x" && Makanan != "ALL");
                    Continue();
                } else if(Decision2 == "2") {
                    string Pelanggan;
                    Print("[ALL] Tampilkan semua pelanggan");
                    Print("[FAV] Tampilkan pelanggan yang paling banyak memesan");
                    Print("[Nama Customer] Tampilkan pelanggan tertentu");
                    do {
                        Pelanggan = GetInput("\nMasukkan nama pelanggan : ");
                        if(Pelanggan == "ALL") ViewAllCustomer(LC, LR);
                        else if(Pelanggan == "FAV") SortCustomer(LC), ViewCustomer(LR, First(LC));
                        else if(Pelanggan != "x") ViewCustomer(LR, GetCustomer(LC, Pelanggan));
                    } while(Pelanggan != "x" && Pelanggan != "ALL");
                    Continue();
                } else if(Decision2 != "0") {
                    Print("Menu tidak valid");
                    Continue();
                }
                ClearScreen();
            } while(Decision2 != "0");
        } else if(Decision == "3") {
            string Makanan;
            ClearScreen();
            Print("HAPUS MAKANAN");
            Print("\n=========================================");
            PrintFood(LF);
            Print("=========================================\n");
            do {
                Makanan = GetInput("Masukkan nama makanan : ");
                auto F = GetFood(LF, Makanan);
                if(F != NULL) {
                    auto R = GetRelation(LR, F, NULL);
                    while(R != NULL) {
                        Info(Info(R).Customer).JumlahMakanan--;
                        DeleteFromList(LR, R);
                        R = GetRelation(LR, F, NULL);
                    }
                    DeleteFromList(LF, F);
                    Print(Makanan + " Sukses dihapus!");

                } else Print("Maaf " + Makanan + " tidak ada");
            } while(Makanan != "x");
        }
        ClearScreen();
    } while(Decision != "0");
    ClearScreen();
}

#endif // UI_H_INCLUDED
