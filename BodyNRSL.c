/* File        : bodyNRSL.c */
/* Deskripsi   : Body prototype ADT Non Restricted Single Linked/Linear list yang hanya dikenali First(L) */
/* Dibuat oleh : Ade Chandra Nugraha */
/* Tanggal     : 24-10-2001 */


#include <stdio.h>
#include <boolean.h>
#include <limits.h>
#include <malloc.h>
#include "spnrsll.h"

/* Mengecek apakah List kosong */
boolean ListEmpty(List L) {
    return (First(L) == Nil);
}

/* Membuat List kosong */
void CreateList(List *L) {
    First(*L) = Nil;
}

/* Mengalokasikan memori untuk elemen baru */
address Alokasi(infotype X) {
    address P = (address)malloc(sizeof(ElmtList));
    if (P != Nil) {
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}

/* Dealokasi elemen */
void DeAlokasi(address P) {
    free(P);
}

/* Mencari elemen dengan nilai X */
address Search(List L, infotype X) {
    address P = First(L);
    while (P != Nil) {
        if (Info(P) == X) return P;
        P = Next(P);
    }
    return Nil;
}

/* Mencari apakah elemen beralamat P ada di list */
boolean FSearch(List L, address P) {
    address Temp = First(L);
    while (Temp != Nil) {
        if (Temp == P) return true;
        Temp = Next(Temp);
    }
    return false;
}

/* Mencari elemen sebelum elemen dengan nilai X */
address SearchPrec(List L, infotype X) {
    address Prec = Nil, P = First(L);
    while (P != Nil && Info(P) != X) {
        Prec = P;
        P = Next(P);
    }
    return (P == Nil) ? Nil : Prec;
}

/* Menambahkan elemen di awal */
void InsVFirst(List *L, infotype X) {
    address P = Alokasi(X);
    if (P != Nil) {
        Next(P) = First(*L);
        First(*L) = P;
    }
}

/* Menambahkan elemen di akhir */
void InsVLast(List *L, infotype X) {
    address P = Alokasi(X);
    if (P != Nil) {
        if (ListEmpty(*L)) {
            First(*L) = P;
        } else {
            address Last = First(*L);
            while (Next(Last) != Nil) {
                Last = Next(Last);
            }
            Next(Last) = P;
        }
    }
}

/* Menghapus elemen pertama */
void DelVFirst(List *L, infotype *X) {
    if (!ListEmpty(*L)) {
        address P = First(*L);
        *X = Info(P);
        First(*L) = Next(P);
        DeAlokasi(P);
    }
}

/* Menghapus elemen terakhir */
void DelVLast(List *L, infotype *X) {
    if (!ListEmpty(*L)) {
        address P = First(*L), Prec = Nil;
        while (Next(P) != Nil) {
            Prec = P;
            P = Next(P);
        }
        *X = Info(P);
        if (Prec == Nil) {
            First(*L) = Nil;
        } else {
            Next(Prec) = Nil;
        }
        DeAlokasi(P);
    }
}

/* Menambahkan elemen setelah elemen tertentu */
void InsertAfter(List *L, address P, address Prec) {
    if (P != Nil && Prec != Nil) {
        Next(P) = Next(Prec);
        Next(Prec) = P;
    }
}

/* Menghapus elemen tertentu dalam list */
void DelP(List *L, infotype X) {
    address P = First(*L), Prec = Nil;
    while (P != Nil && Info(P) != X) {
        Prec = P;
        P = Next(P);
    }
    if (P != Nil) {
        if (Prec == Nil) {
            First(*L) = Next(P);
        } else {
            Next(Prec) = Next(P);
        }
        DeAlokasi(P);
    }
}

/* Mencetak isi List */
void PrintInfo(List L) {
    address P = First(L);
    if (P == Nil) {
        printf("List Kosong\n");
    } else {
        while (P != Nil) {
            printf("%d -> ", Info(P));
            P = Next(P);
        }
        printf("Nil\n");
    }
}

/* Menghapus semua elemen dalam List */
void DelAll(List *L) {
    infotype X;
    while (!ListEmpty(*L)) {
        DelVFirst(L, &X);
    }
}

/* Prosedur untuk menghapus semua bilangan ganjil dari list */
void DelOdd(List *L) {
    address P = First(*L);
    address Temp;
    while (P != Nil) {
        if (Info(P) % 2 != 0) { // Jika bilangan ganjil
            Temp = P;
            P = Next(P);
            DelP(L, Info(Temp));
        } else {
            P = Next(P);
        }
    }
}