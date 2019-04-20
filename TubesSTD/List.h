#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

template <class Data>
auto CreateElement(Data X) {
    auto P = new ElementList<Data>;
    Info(P) = X;
    Next(P) = NULL;
    return P;
}

template <class Data>
void CreateList(List<Data> &L) {
    First(L) = Last(L) = NULL;
}

template <class Data>
void AddToList(List<Data> &L, Address A) {
    /* Menambahkan Element ke List dengan algoritma Insert Last */
    if(First(L) == NULL) {
        First(L) = A;
    } else {
        Next(Last(L)) = A;
    }
    Last(L) = A;
}

template <class Data>
auto DeleteFromList(List<Data> &L, Address &A) {
    /* A tidak boleh NULL */
    if(A == NULL) return A;
    if(First(L) == A) {
        /* Delete First */
        First(L) = Next(A);
        /* Kalau cuman 1 Element gimana? */
        if(First(L) == NULL) {
            Last(L) = NULL;
        }
    } else {
        auto Prev = First(L);
        while(Next(Prev) != A) {
            Prev = Next(Prev);
        }
        /* Next(Prev) == A, Prev adalah element dibelakang A */
        Next(Prev) = Next(A);

        if(Last(L) == A) {
            /* Set Last ke Prev */
            Last(L) = Prev;
        }
    }
    Next(A) = NULL;

    return A;
}
#endif // LIST_H_INCLUDED
