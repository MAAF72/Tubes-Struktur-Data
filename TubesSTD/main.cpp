#include "Header.h"

void Testing(List<InfoFood> LF, List<InfoCustomer> LC, List<InfoRelation> LR) {
  	/* Membuat makanan dengan nama AYAM GEPREK */
    if(GetFood(LF, "AYAM GEPREK") == NULL) {
        CreateFood(LF, "AYAM GEPREK");
    }

	/* Membuat makanan dengan nama AYAM GORENG */
    if(GetFood(LF, "AYAM GORENG") == NULL) {
        CreateFood(LF, "AYAM GORENG");
    }

    Print("Daftar Makanan");
    PrintFood(LF);

  	/* Membuat pelanggan dengan nama Fatih */
    if(GetCustomer(LC, "Fatih") == NULL) {
        CreateCustomer(LC, "Fatih");
    }

  	/* Membuat pelanggan dengan nama Akif */
    if(GetCustomer(LC, "Akif") == NULL) {
        CreateCustomer(LC, "Akif");
    }

    Print("\nDaftar Pelanggan");
    PrintCustomer(LC);

    auto Fatih = GetCustomer(LC, "Fatih");
    auto Akif = GetCustomer(LC, "Akif");
    auto Geprek = GetFood(LF, "AYAM GEPREK");
    auto Goreng = GetFood(LF, "AYAM GORENG");

  	/* Menambahkan hubungan antara AYAM GEPREK dengan Akif */
    CreateRelation(LR, Geprek, Akif);
  	/* Menambahkan hubungan antara AYAM GEPREK dengan Fatih */
    CreateRelation(LR, Geprek, Fatih);
  	/* Menambahkan hubungan antara AYAM GORENG dengan Fatih */
    CreateRelation(LR, Goreng, Fatih);

    Print("\nData makanan Ayam Geprek");
    ViewFood(LR, Geprek);

    Print("\nData pelanggan Akif");
    ViewCustomer(LR, Akif);

    SortCustomer(LC);
    SortFood(LF);

    Print("\nData pelanggan yang sudah tersorting");
    ViewAllCustomer(LC, LR);

    Print("\nData makanan yang sudah tersorting");
    ViewAllFood(LF, LR);

    Print("\nMenghapus AYAM GEPREK...");
    auto R = GetRelation(LR, Geprek, NULL);
    while(R != NULL) {
        Info(Info(R).Customer).JumlahMakanan--;
        DeleteFromList(LR, R);
        R = GetRelation(LR, Geprek, NULL);
    }
    DeleteFromList(LF, Geprek);
    Print("AYAM GEPREK Sukses dihapus!");

    Print("\nData pelanggan sesudah AYAM GEPREK dihapus");
    ViewAllCustomer(LC, LR);

    Print("\nData makanan sesudah AYAM GEPREK dihapus");
    ViewAllFood(LF, LR);
}

int main() {
    List<InfoFood> LF;
    List<InfoCustomer> LC;
    List<InfoRelation> LR;
    CreateList(LF);
    CreateList(LC);
    CreateList(LR);

    string Nama;

    bool IsTest = false;

    if(IsTest) Testing(LF, LC, LR);
    else {
        do {
            ClearScreen();
            Print("==============================");
            Print("||AKMJ Caffe by MAMANX GAROX||");
            Print("==============================");
            Print();
            Nama = GetInput("Masukkan nama anda : ");
            ClearScreen();
            if(Nama != "x") {
                Nama == "ADMIN" ? MenuAdmin(LC, LF, LR) : MenuUser(LC, LF, LR, Nama);
            }
        } while(Nama != "x");
        /* Loop akan terhenti jika user menginputkan "x" */
    }
    Print("Program selesai!");
    return 0;
}
