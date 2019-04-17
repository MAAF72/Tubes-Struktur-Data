#include "Header.h"

int main() {
    List<InfoFood> LF;
    List<InfoCustomer> LC;
    List<InfoRelation> LR;
    CreateList(LF);
    CreateList(LC);
    CreateList(LR);

    string Nama;

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
    Print("Program selesai!");
    return 0;
}
