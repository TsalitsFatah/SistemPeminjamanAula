#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>


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
            informasiAula[loop].tanggalBooking[i] = informasiPinjam[i];
        }
        for (int i = 0; i < index[1] - index[0] - 1; i++)
        {
            informasiAula[loop].jamBooking[i] = informasiPinjam[i + index[0] + 1];
        }
        for (int i = 0; i < index[2] - index[1] - 1; i++)
        {
            informasiAula[loop].namaPeminjam[i] = informasiPinjam[i + index[1] + 1];
        }
        for (int i = 0; i < index[3] - index[2] - 1; i++)
        {
            informasiAula[loop].nimMahasiswa[i] = informasiPinjam[i + index[2] + 1];
        }
         for (int i = 0; i < strlen(informasiPinjam) - index[3] - 1; i++)
        {
            informasiAula[loop].keterangan[i] = informasiPinjam[i + index[3] + 1];
        }
        printf("\n");
        printf("Tanggal Booking     : %s\n", informasiAula[loop].tanggalBooking);
        printf("Jam Booking         : %s\n", informasiAula[loop].jamBooking);
        printf("Nama Peminjam       : %s\n", informasiAula[loop].namaPeminjam);
        printf("Nim Mahasiswa       : %s\n", informasiAula[loop].nimMahasiswa);
        printf("Keterangan          : %s\n", informasiAula[loop].keterangan);
        
          loop++;  
    }
    
}
void formulirPeminjaman(){
    struct aula pinjamAula[100];
    memset(pinjamAula, 0, sizeof(pinjamAula));
    char str[500];
    printf("Tanggal Pinjam : ");
    scanf(" %[^\n]s", &pinjamAula[0].tanggalBooking);
    printf("Jam Pinjam : ");
    scanf(" %[^\n]s", &pinjamAula[0].jamBooking);
    printf("Nama Peminjam  : ");
    scanf(" %[^\n]s", &pinjamAula[0].namaPeminjam);
    printf("Nim Mahasiswa : ");
    scanf(" %[^\n]s", &pinjamAula[0].nimMahasiswa);
     printf("Keterangan : ");
    scanf(" %[^\n]s", &pinjamAula[0].keterangan);
    strcat(str, pinjamAula[0].tanggalBooking );
    strcat(str, "|");
    strcat(str, pinjamAula[0].jamBooking );
    strcat(str, "|");
    strcat(str, pinjamAula[0].namaPeminjam );
    strcat(str, "|");
    strcat(str, pinjamAula[0].nimMahasiswa );
    strcat(str, "|");
    strcat(str, pinjamAula[0].keterangan );
    strcat(str, "\n");
    FILE *fptr;
    fptr = fopen("data.txt", "a");
    fprintf(fptr, "%s", str);
    fclose(fptr);
}

void pengembalian(){
  int loop = 0;
  int loop6 = 0;
  char *hasil;
  char searchData[50];
  char dataAula[100];
  struct aula cariData[50];
  FILE *fptr;
  fptr = fopen("data.txt", "r");
  memset(cariData, 0, sizeof(cariData));

  /*Menu Cari Data*/
	printf("-------------------- CARI DATA PEMINJAM --------------------\n");
    printf("Masukkan Nim Peminjam : ");
    scanf(" %[^\n]s", &searchData);
    /*End Menu Cari Data*/

  	while (fgets(dataAula, sizeof(dataAula), fptr)){
    int loop5 = 0;
  	  int loop2 = 0;
  	  int loop3 = 0;
  	  int loop4 = 0;
  	  int index2[4];

  	  	/*Mencari Index Dari Char '|'*/
  	  	hasil = strchr(dataAula, '|');
  	  	while(hasil != NULL){
  	  	  	index2[loop2] = hasil - dataAula;
  	  	  	hasil = strchr(hasil+1, '|');
  	  	  	loop2++;
  	  	}


  	  	  	for (int i = 0; i < index2[3] - index2[2] - 1; i++){
  	  	  	  	loop4 = 0;
  	  	  	  	for (int j = 0; j < strlen(searchData); j++){
  	  	  	  	  	if (tolower(dataAula[i+j+index2[2]+1]) == tolower(searchData[j]) && strlen(searchData) == index2[3]-index2[2]-1){
  	  	  	  	  	  	loop4++;
  	  	  	  	  	}
  	  	  	  	  	if (loop4 == strlen(searchData)){
  	  	  	  	  	  	loop3 = index2[0];
  	  	  	  	  	}
  	  	  	  	}
  	  	  	}
  	

  if (loop3 != index2[0]){/*Jika Tidak Data Sesuai Dengan Yang Dicari User*/
  char str[500] = {""};
  strcat(str, dataAula);
          
  	if (loop6 > 0){
  	  /*Simpan String Hasil Penggabungan Ke data.txt*/
  	  FILE *fptr;
  	  fptr = fopen("data.txt", "a");
  	  fprintf(fptr,"%s", str);
  	  fclose(fptr);
  	  /*End Simpan String Hasil Penggabungan Ke data.txt*/
  	}
  	if (loop6 == 0) /*Hapus Data Sebelumnya*/{
  	  /*Simpan String Hasil Penggabungan Ke data.txt*/
  	  FILE *fptr;
  	  fptr = fopen("data.txt", "w");
  	  fprintf(fptr,"%s", str);
  	  fclose(fptr);
  	  /*End Simpan String Hasil Penggabungan Ke data.txt*/
  	  loop6++;
  	}
  }else{  /*Jika NIP Sama Dengan Input User (Kosongkan File)*/

  	  }
  	  loop++;
  	}
  	fclose(fptr); /*Tutup File data.txt*/
		printf("Peminjaman Telah Selesai\n");
		printf("Loading ");
		sleep(1);
		printf(". ");
		sleep(1);
		printf(". ");
		sleep(1);
		printf(". ");
		sleep(1);
		printf(". ");
		system("cls");
}


void pembatalan(){
  int loop = 0;
  int loop6 = 0;
  char *hasil;
  char searchData[50];
  char dataAula[100];
  struct aula cariData[50];
  FILE *fptr;
  fptr = fopen("data.txt", "r");
  memset(cariData, 0, sizeof(cariData));

  /*Menu Cari Data*/
	printf("-------------------- CARI DATA PEMINJAM --------------------\n");
    printf("Masukkan Nim Peminjam : ");
    scanf(" %[^\n]s", &searchData);
    /*End Menu Cari Data*/

  	while (fgets(dataAula, sizeof(dataAula), fptr)){
    int loop5 = 0;
  	  int loop2 = 0;
  	  int loop3 = 0;
  	  int loop4 = 0;
  	  int index2[4];

  	  	/*Mencari Index Dari Char '|'*/
  	  	hasil = strchr(dataAula, '|');
  	  	while(hasil != NULL){
  	  	  	index2[loop2] = hasil - dataAula;
  	  	  	hasil = strchr(hasil+1, '|');
  	  	  	loop2++;
  	  	}


  	  	  	for (int i = 0; i < index2[3] - index2[2] - 1; i++){
  	  	  	  	loop4 = 0;
  	  	  	  	for (int j = 0; j < strlen(searchData); j++){
  	  	  	  	  	if (tolower(dataAula[i+j+index2[2]+1]) == tolower(searchData[j]) && strlen(searchData) == index2[3]-index2[2]-1){
  	  	  	  	  	  	loop4++;
  	  	  	  	  	}
  	  	  	  	  	if (loop4 == strlen(searchData)){
  	  	  	  	  	  	loop3 = index2[0];
  	  	  	  	  	}
  	  	  	  	}
  	  	  	}
  	

  if (loop3 != index2[0]){/*Jika Tidak Data Sesuai Dengan Yang Dicari User*/
  char str[500] = {""};
  strcat(str, dataAula);
          
  	if (loop6 > 0){
  	  /*Simpan String Hasil Penggabungan Ke data.txt*/
  	  FILE *fptr;
  	  fptr = fopen("data.txt", "a");
  	  fprintf(fptr,"%s", str);
  	  fclose(fptr);
  	  /*End Simpan String Hasil Penggabungan Ke data.txt*/
  	}
  	if (loop6 == 0) /*Hapus Data Sebelumnya*/{
  	  /*Simpan String Hasil Penggabungan Ke data.txt*/
  	  FILE *fptr;
  	  fptr = fopen("data.txt", "w");
  	  fprintf(fptr,"%s", str);
  	  fclose(fptr);
  	  /*End Simpan String Hasil Penggabungan Ke data.txt*/
  	  loop6++;
  	}
  }else{  /*Jika NIP Sama Dengan Input User (Kosongkan File)*/

  	  }
  	  loop++;
  	}
  	fclose(fptr); /*Tutup File data.txt*/
		printf("Peminjaman Telah Dibatalkan\n");
		printf("Loading ");
		sleep(1);
		printf(". ");
		sleep(1);
		printf(". ");
		sleep(1);
		printf(". ");
		sleep(1);
		printf(". ");
		system("cls");
}



int main(){
    while (1)
    {
    int menu;
    printf("\t\t\t========== Sistem Peminjaman Ruang Aula ==========\t\t\t\n");
    printf("---------- Menu ----------\n");
    printf(" 1. Informasi     \n");
    printf(" 2. Formulir Peminjaman      \n");
    printf(" 3. Pengembalian    \n");
    printf(" 4. Pembatalan  \n");
    printf(" 6. Exit                \n");
    printf("-------------------------\n");
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
        pengembalian();
        break;
    case 4:
        pembatalan();
        break;
    case 5:
        return 0;
        break;
    
    default:
        break;
    }
  }
     printf("GOOD BAY WORLD");
}

