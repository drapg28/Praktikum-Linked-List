/* File        : mainNRSL.cpp */
/* Deskripsi   : Driver / main program untuk ADT Non Restricted Single Linked/Linear List */
/* Dibuat oleh : Ade Chandra Nugraha*/
/* Tanggal     : 25-10-2001 */
/* Diupdate oleh : Santi Sundari, 6-4-2011, hanya tdd operasi2 dasar */
/* Diupdate oleh : WW & AM, 8-3-2025, penyesuaian area body & main untuk latihan Diploma 3 */

#include "SpNRSLL.h"
#include <stdio.h>

int main() {
    /* Kamus Lokal */
    List MyList;
    infotype isi;
    address P, Prec;

    /* Program */
    CreateList(&MyList); // Membuat list kosong
    printf("List telah dibuat kosong.\n");

    // 1. Insert First(7)
    printf("Menambahkan 7 di awal list.\n");
    InsVFirst(&MyList, 7);
    PrintInfo(MyList);

    // 2. Insert Last(11)
    printf("Menambahkan 11 di akhir list.\n");
    InsVLast(&MyList, 11);
    PrintInfo(MyList);

    // 3. Insert After(9 setelah 7)
    printf("Menambahkan 9 setelah 7.\n");
    P = Alokasi(9);
    Prec = Search(MyList, 7);
    if (P != Nil && Prec != Nil) {
        InsertAfter(&MyList, P, Prec);
    } else {
        printf("Gagal menambahkan 9 setelah 7.\n");
    }
    PrintInfo(MyList);

    // 4. Insert First(5)
    printf("Menambahkan 5 di awal list.\n");
    InsVFirst(&MyList, 5);
    PrintInfo(MyList);

    // 5. Insert Last(13)
    printf("Menambahkan 13 di akhir list.\n");
    InsVLast(&MyList, 13);
    PrintInfo(MyList);

    // 6. Delete Last (hapus 13)
    if (!ListEmpty(MyList)) {
        DelVLast(&MyList, &isi);
        printf("Elemen terakhir dengan nilai %d telah dihapus.\n", isi);
    } else {
        printf("Gagal menghapus elemen terakhir, list kosong.\n");
    }
    PrintInfo(MyList);

    // 7. Delete Specific (hapus 7)
    printf("Menghapus elemen dengan nilai 7.\n");
    if (Search(MyList, 7) != Nil) {
        DelP(&MyList, 7);
    } else {
        printf("Gagal menghapus 7, elemen tidak ditemukan.\n");
    }
    PrintInfo(MyList);

    // 8. Delete First (hapus 5)
    if (!ListEmpty(MyList)) {
        DelVFirst(&MyList, &isi);
        printf("Elemen pertama dengan nilai %d telah dihapus.\n", isi);
    } else {
        printf("Gagal menghapus elemen pertama, list kosong.\n");
    }
    PrintInfo(MyList);

    // 9. Delete Odd (hapus semua bilangan ganjil)
    printf("Menghapus semua bilangan ganjil dalam list.\n");
    void DelOdd(List *L);
    PrintInfo(MyList);

    return 0;
}
