#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct aula
{
    char namaPeminjam[50];
    char nimMahasiswa[50];
    char tanggalBooking[50];
    char jamBooking[50];
    char keterangan[50];
};


void informasi(){
    struct aula informasiAula[100];
    char informasiPinjam[500];
    memset(informasiAula, 0, sizeof(informasiAula));
    FILE *fptr;
    char *hasil;
    fptr = fopen("data.txt", "r");
    int loop = 0;

    while (fgets(informasiPinjam, sizeof(informasiPinjam), fptr))
    {
    int loop2 = 0;
    int index[4];
        hasil = strchr(informasiPinjam, '|');
        while (hasil != NULL)
        {
            index[loop2] = hasil - informasiPinjam;
            hasil = strchr(hasil+1, '|');
            loop2++;
        }

        for (int i = 0; i < index[0]; i++)
        {
            informasiAula[loop].namaPeminjam[i] = informasiPinjam[i];
        }
        for (int i = 0; i < index[1] - index[0] - 1; i++)
        {
            informasiAula[loop].nimMahasiswa[i] = informasiPinjam[i + index[0] + 1];
        }
        for (int i = 0; i < index[2] - index[1] - 1; i++)
        {
            informasiAula[loop].tanggalBooking[i] = informasiPinjam[i + index[1] + 1];
        }
        for (int i = 0; i < index[3] - index[2] - 1; i++)
        {
            informasiAula[loop].jamBooking[i] = informasiPinjam[i + index[2] + 1];
        }
         for (int i = 0; i < strlen(informasiPinjam) - index[2] - 1; i++)
        {
            informasiAula[loop].keterangan[i] = informasiPinjam[i + index[3  
            ] + 1];
        }
        
        printf("Nama Peminjam : %s\n", informasiAula[loop].namaPeminjam);
        printf("Nim Mahasiswa : %s\n", informasiAula[loop].nimMahasiswa);
        printf("Tanggal Booking: %s\n", informasiAula[loop].tanggalBooking);
        printf("Jam Booking : %s\n", informasiAula[loop].jamBooking);
         printf("Keterangan : %s\n", informasiAula[loop].keterangan);
        
          loop++;  
    }
    
}

void formulirPeminjaman(){
    struct aula pinjamAula[100];
    memset(pinjamAula, 0, sizeof(pinjamAula));
    char str[500];
    printf("Nama Peminjam : ");
    scanf(" %[^\n]s", &pinjamAula[0].namaPeminjam);
    printf("Nim Mahasiswa : ");
    scanf(" %[^\n]s", &pinjamAula[0].nimMahasiswa);
    printf("Tanggal Booking : ");
    scanf(" %[^\n]s", &pinjamAula[0].tanggalBooking);
    printf("Jam Booking : ");
    scanf(" %[^\n]s", &pinjamAula[0].jamBooking);
    printf("Keterangan : ");
    scanf(" %[^\n]s", &pinjamAula[0].keterangan);
    strcat(str, pinjamAula[0].namaPeminjam );
    strcat(str, "|");
    strcat(str, pinjamAula[0].nimMahasiswa );
    strcat(str, "|");
    strcat(str, pinjamAula[0].tanggalBooking );
    strcat(str, "|");
    strcat(str, pinjamAula[0].jamBooking );
    strcat(str, "|");
    strcat(str, pinjamAula[0].keterangan );
    strcat(str, "\n");
    FILE *fptr;
    fptr = fopen("data.txt", "a");
    fprintf(fptr, "%s", str);
    fclose(fptr);
}

int main(){
    while (1)
    {
    int menu;
    printf("---- Sistem Peminjaman aula ----\n");
    printf("-------- Menu ----------\n");
    printf(" 1. Informasi     \n");
    printf(" 2. Formulir Peminjaman      \n");
    printf(" 3. Pengembalian    \n");
    printf(" 4. Laporan Peminjaman  \n");
    printf(" 5. Exit                \n");
    printf("----------------------\n");
    printf("Masukan Pilihan anda[ 1 s.d. 5 ] = ");
    scanf("%d", &menu);
    switch (menu)
    {
    case 1:
        informasi();
        break;
    case 2:
        formulirPeminjaman();
        break;
    case 3:
        // pengembalian();
        break;
    case 4:
        // laporanPeminjaman();
        break;
    case 5:
        return 0;
        break;
    
    default:
        break;
    }
    }
}
