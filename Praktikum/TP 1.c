#include <stdio.h>

int main() {
    int n = 6; // Ukuran pola
    
    // Bagian atas
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++)
            printf(" "); // Spasi sebelum bintang pertama
        
        printf("*"); // Bintang pertama

        if (i > 0) { // Untuk menampilkan bintang kedua setelah spasi di dalam
            for (int j = 0; j < i - 1; j++)
                printf(" ");
            printf("*");
        }
        printf("\n");
    }

    // Bagian bawah
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < n - i - 1; j++)
            printf(" "); // Spasi sebelum bintang pertama
        
        printf("*"); // Bintang pertama

        if (i > 0) { // Untuk menampilkan bintang kedua setelah spasi di dalam
            for (int j = 0; j < i - 1; j++)
                printf(" ");
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
