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
    if(First(LF) != NULL) {
        if(GetCustomer(LC, Nama) == NULL) {
            string Makanan;
            Print("Selamat datang " + Nama + " di AKMJ Caffe ^_^");
            auto C = CreateCustomer(LC, Nama);
            Print("\n=========================================");
            SortFood(LF);
            /* Menu yang tampil sudah tersorting */
            PrintFood(LF);
            Print("=========================================\n");
            Makanan = GetInput("Pilih Makanan : ");
            while(Makanan != "x") {
                auto F = GetFood(LF, Makanan);
                F != NULL ? CreateRelation(LR, F, C) : Print("Maaf " + Makanan + " tidak tersedia");
                Makanan = GetInput("Pilih Makanan : ");
            }
            /* Loop akan terhenti jika user menginputkan "x" */
            Print("\nTerimakasih ^_^");

            /* Jika user tidak membeli makanan, delete user tersebut */
            if(GetRelation(LR, NULL, C) == NULL) {
                DeleteFromList(LC, C);
            }
        } else {
            Print("MAAF, SUDAH ADA PELANGGAN DENGAN NAMA YANG SAMA!");
        }
    } else {
        Print("MAAF, WARUNG BELUM BUKA!");
    }
    Continue();
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
            /* Menu Input Menu */
            string Makanan = GetInput("Masukkan nama makanan : ");
            while(Makanan != "x") {
                auto F = GetFood(LF, Makanan);
                F == NULL ? CreateFood(LF, Makanan) : Print("Maaf " + Makanan + " sudah tersedia");
                Makanan = GetInput("Masukkan nama makanan : ");
            }
            /* Loop akan terhenti jika user menginputkan "x" */
        } else if(Decision == "2") {
            /* Menu Lihat Pesanan */
            string Decision2;
            do {
                Print("[1] Lihat Pesanan dari makanan");
                Print("[2] Lihat Pesanan dari pelanggan");
                Print("\n[0] Kembali");
                Decision2 = GetInput("\nPilih Menu : ");
                ClearScreen();
                if(Decision2 == "1") {
                    /* Sub-Menu Lihat Pesanan dari Makanan */
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
                    /* Loop akan terhenti jika user menginputkan "x" atau "ALL" */
                } else if(Decision2 == "2") {
                    /* Sub-Menu Lihat Pesanan dari pelanggan */
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
                    /* Loop akan terhenti jika user menginputkan "x" atau "ALL" */
                    Continue();
                } else if(Decision2 != "0") {
                    Print("Menu tidak valid");
                    Continue();
                }
                ClearScreen();
            } while(Decision2 != "0");
            /* Loop akan terhenti jika user menginputkan "0" */
        } else if(Decision == "3") {
            /* Menu Delete Menu */
            ClearScreen();
            Print("HAPUS MAKANAN");
            Print("\n=========================================");
            PrintFood(LF);
            Print("=========================================\n");
            string Makanan = GetInput("Masukkan nama makanan : ");
            while(Makanan != "x") {
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
                Makanan = GetInput("Masukkan nama makanan : ");
            }
            /* Loop akan terhenti jika user menginputkan "x" */
        } else if(Decision != "0") {
            Print("Menu tidak valid");
            Continue();
        }
        ClearScreen();
    } while(Decision != "0");
    /* Loop akan terhenti jika user menginputkan "0" */
}

#endif // UI_H_INCLUDED
