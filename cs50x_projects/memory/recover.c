#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {

    int contador = 0;
    bool jpeg_aberto = false;
    char *nome_arquivo = malloc(sizeof(char)*10);

    if (argc != 2)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }

    FILE *raw = fopen(argv[1], "rb");
    if (raw == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *new_jpeg;

    uint8_t buffer[512];
    int quantidade_lida = fread(&buffer, sizeof(uint8_t), 512, raw);
    while (quantidade_lida>0)
    {
        
        if ((buffer[0] == 255 && buffer[1] == 216 && buffer[2] == 255) && (buffer[3]>=224 && buffer[3]<=239)) {
            if (jpeg_aberto == true) {
                fclose(new_jpeg);
            }
            jpeg_aberto = true;

            if (contador >= 10 && contador < 100) {
                snprintf(nome_arquivo, sizeof(char)*10, "0%d.jpg", contador);
            } else if (contador >= 100) {
                snprintf(nome_arquivo, sizeof(char)*10, "%d.jpg", contador);
            } else {
                snprintf(nome_arquivo, sizeof(char)*10, "00%d.jpg", contador);
            }
            
            new_jpeg = fopen(nome_arquivo, "wb");
                if (new_jpeg == NULL)
                {
                    printf("Could not open file.\n");
                    return 1;
                }
            contador++;
        }

        if (jpeg_aberto == true) {
            fwrite(&buffer, sizeof(uint8_t), quantidade_lida, new_jpeg);
        }
        quantidade_lida = fread(&buffer, sizeof(uint8_t), 512, raw);
    }

    if(jpeg_aberto == true) {
        fclose(new_jpeg);
    }
    free(nome_arquivo);
    fclose(raw);

    return 0;
}