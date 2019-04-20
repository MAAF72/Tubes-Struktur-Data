#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
#include <string>
#define First(L) L.First
#define Last(L) L.Last
#define Next(E) E->Next
#define Info(E) E->Info
#define Address ElementList<Data>*

using namespace std;

/* Menggunakan Single Linked List dengan 2 Penunjuk, yaitu First dan Last */

template <class Data>
struct ElementList {
    Data Info;
    Address Next;
};

template <class Data>
struct List {
    Address First;
    Address Last;
};

struct InfoFood {
    string NamaMakanan;
    int JumlahPelanggan;
};

struct InfoCustomer {
    string NamaPelanggan;
    int JumlahMakanan;
};

struct InfoRelation {
    ElementList<InfoFood> *Food;
    ElementList<InfoCustomer> *Customer;
};

/* Primitive for List.h */
template <class Data>
auto CreateElement(Data X);
template <class Data>
void CreateList(List<Data> &L);
template <class Data>
void AddToList(List<Data> &L, Address A);
template <class Data>
auto DeleteFromList(List<Data> &L, Address &A);

/* Primitive for Food.h */
void CreateFood(List<InfoFood> &L, string X);
void PrintFood(List<InfoFood> L);
auto GetFood(List<InfoFood> L, string X);
void ViewFood(List<InfoRelation> L, ElementList<InfoFood> *P);
void ViewAllFood(List<InfoFood> LF, List<InfoRelation> LR);
void ViewFoodsBuyers(List<InfoRelation> L, ElementList<InfoFood> *X);
void SortFood(List<InfoFood> &L);

/* Primitive for Customer.h */
auto CreateCustomer(List<InfoCustomer> &L, string X);
void PrintCustomer(List<InfoCustomer> L);
auto GetCustomer(List<InfoCustomer> L, string X);
void ViewCustomer(List<InfoRelation> L, ElementList<InfoCustomer> *P);
void ViewAllCustomer(List<InfoCustomer> LC, List<InfoRelation> LR);
void ViewCustomersFoods(List<InfoRelation> L, ElementList<InfoCustomer> *X);
void SortCustomer(List<InfoCustomer> &L);

/* Primitive for Relation.h */
void CreateRelation(List<InfoRelation> &L, ElementList<InfoFood> *F, ElementList<InfoCustomer> *C);
auto GetRelation(List<InfoRelation> L, ElementList<InfoFood> *F, ElementList<InfoCustomer> *C);

/* Primitive for UI.h */
void Continue();
void Print(string X = "", string End = "\n");
string GetInput(string X = "");
void ClearScreen();
void MenuUser(List<InfoCustomer> &LC, List<InfoFood> LF, List<InfoRelation> &LR, string Nama);
void MenuAdmin(List<InfoCustomer> &LC, List<InfoFood> &LF, List<InfoRelation> &LR);

#include "List.h"
#include "Food.h"
#include "Customer.h"
#include "Relation.h"
#include "UI.h"
#endif // HEADER_H_INCLUDED
