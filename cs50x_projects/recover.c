#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {

    int contador = 0;
    bool jpeg_aberto = false;
    char *nome_arquivo = malloc(sizeof(char)*100);

    if (argc != 2)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }

    FILE *raw = fopen(argv[1], "r");
    if (raw == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *new_jpeg = malloc(sizeof(FILE));

    uint8_t buffer[512];

    while (fread(&buffer, sizeof(buffer)/sizeof(buffer[0]), 1, raw))
    {

        if (buffer[0] == 255 && buffer[1] && = 216 && buffer[2] = 256) && (buffer[3]>224 && buffer[3]<239) {
            if (jpeg_aberto == true) {
                fclose(new_jpeg);
            }
            snprintf(*nome_arquivo, sizeof(char)*100, "%d.jpg", contador);
            new_jpeg = fopen(*nome_arquivo, "w");
            contador++;
        }

        if (jpeg_aberto == true) {
            fwrite(&buffer, sizeof(buffer)/sizeof(buffer[0]), 1, new_jpeg);
        }
        
    }

    if(jpeg_aberto == true) {
        fclose(new_jpeg);
    }

    fclose(raw);

    return 0;
}