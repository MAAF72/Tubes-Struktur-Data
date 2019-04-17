#ifndef RELATION_H_INCLUDED
#define RELATION_H_INCLUDED

void CreateRelation(List<InfoRelation> &L, ElementList<InfoFood> *F, ElementList<InfoCustomer> *C) {
    InfoRelation Relation;
    Relation.Food = F;
    Relation.Customer = C;
    Info(F).JumlahPelanggan++;
    Info(C).JumlahMakanan++;
    /* Membuat Element Relation dengan Info = Relation */
    ElementList<InfoRelation> *R = CreateElement(Relation);
    AddToList(L, R);
}

ElementList<InfoRelation> *GetRelation(List<InfoRelation> L, ElementList<InfoFood> *F, ElementList<InfoCustomer> *C) {
    ElementList<InfoRelation> *P = First(L);
    while((P != NULL) && (Info(P).Food != F) && (Info(P).Customer != C)) {
        P = Next(P);
    }
    /* P == NULL atau Info(P).Food == F atau Info(P).Customer == C */
    return P;
}
#endif // RELATION_H_INCLUDED
