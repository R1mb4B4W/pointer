#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 2024
#define MIN_LENGTH 1945

void lessThanRequired (int *length) {
    printf("The length of your text is less than specified, please update your text\n"); // Mencetak pesan ke pengguna, menginformasikan bahwa panjang teks kurang dari yang ditentukan.
    *length = MIN_LENGTH - 1; //Memperbarui nilai length yang dipass ke fungsi dengan MIN_LENGTH - 1
}

void equalThanRequired (int *length) {
    printf("Thank you, Your text length is correct\n");// Mencetak pesan ke pengguna, menyatakan bahwa panjang teks sudah sesuai.
}

void moreThanRequired (int *length) {
    printf("Your text is too long, please reduce the text\n");// Mencetak pesan ke pengguna, menginformasikan bahwa panjang teks melebihi yang ditentukan.
    *length = MIN_LENGTH - 1;//Memperbarui nilai length yang dipass ke fungsi dengan MIN_LENGTH - 1
}

int checkLenghtRequirement(char* text) {
    int length = strlen(text); // Menggunakan fungsi strlen untuk menghitung panjang teks yang diwakili oleh text.
    return (length < MIN_LENGTH) ? 0 : ((length == MIN_LENGTH) ? 1 : 2);
}

int main() {
    int lengthOfText, selectOption; // lengthOfText Untuk menyimpan panjang teks yang dibaca dari file. dan selectOption Untuk menyimpan kategori panjang teks 
    FILE *fptr = NULL; // Mendeklarasikan pointer file fptr dan menginisialisasinya dengan NULL
    char text[MAX_LENGTH];//Mendeklarasikan array karakter text dengan panjang maksimum MAX_LENGTH.

    fptr = fopen("file.txt", "r");// Membuka file "file.txt" untuk dibaca dengan fopen("file.txt", "r").

    if(fptr == NULL){ //Memeriksa apakah file berhasil dibuka
        printf("Error");
        exit(1);// Jika tidak, mencetak pesan "Kesalahan dalam membuka file" dan keluar dari program dengan exit(1)
    }

    fgets(text, MAX_LENGTH, fptr);//Membaca teks dari file ke array text dengan fgets(text, MAX_LENGTH, fptr).

    fclose(fptr);// Menutup file dengan fclose(fptr).

    selectOption = checkLenghtRequirement(text);//Memanggil fungsi checkLenghtRequirement(text) untuk menentukan kategori panjang teks dan menyimpan hasilnya di selectOption

    void (*functions[3])(int *) = {lessThanRequired, equalThanRequired, moreThanRequired};//Mendeklarasikan array penunjuk fungsi functions dengan 3 elemen.
    functions[selectOption](&lengthOfText);//Setiap elemen array berisi pointer ke fungsi yang menangani kategori panjang teks

    int initialLength = strlen(text); // Menghitung panjang teks awal sebelum pembaruan
    printf("Length Before: %d\n", initialLength);//Mencetak panjang teks awal

    printf("The Lenght is updated to %d", lengthOfText);//Mencetak pesan yang menunjukkan bahwa panjang teks telah diperbarui

    return 0;
}