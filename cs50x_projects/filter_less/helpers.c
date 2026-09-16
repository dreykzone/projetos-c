#include <math.h>

void grayscale(int height, int width, RGBTRIPLE image[height][width]) {
    float media = 0;
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            media = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue)/3.0);
            image[i][j].rgbtRed = media;
            image[i][j].rgbtGreen = media;
            image[i][j].rgbtBlue = media;
        }
    }
}

void sepia(int height, int width, RGBTRIPLE image[height][width]) {
    
    float R_original, G_original, B_original;
    float R_novo, G_novo, B_novo;
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            R_original = image[i][j].rgbtRed;
            G_original = image[i][j].rgbtGreen;
            B_original = image[i][j].rgbtBlue;

            R_novo = round((0.393 * R_original) + (0.769 * G_original) + (0.189 * B_original));
            if (R_novo > 255) {
                R_novo = 255;
            }
            image[i][j].rgbtRed = R_novo;


            G_novo = round((0.349 * R_original) + (0.686 * G_original) + (0.168 * B_original));
            if (G_novo > 255) {
                G_novo = 255;
            }
            image[i][j].rgbtGreen = G_novo;

            B_novo = round((0.272 * R_original) + (0.534 * G_original) + (0.131 * B_original));
            if (B_novo > 255) {
                B_novo = 255;
            }
            image[i][j].rgbtBlue = B_novo;

        }
    }
}

void reflect(int height, int width, RGBTRIPLE image[height][width]) {
    int auxiliarR, auxiliarG, auxiliarB;
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < (width/2); j++) {

            auxiliarR = image[i][(width-1) - j].rgbtRed;
            auxiliarG = image[i][(width-1) - j].rgbtGreen;
            auxiliarB = image[i][(width-1) - j].rgbtBlue;

            image[i][(width-1) - j].rgbtRed = image[i][j].rgbtRed;
            image[i][(width-1) - j].rgbtGreen = image[i][j].rgbtGreen;
            image[i][(width-1) - j].rgbtBlue = image[i][j].rgbtBlue;


            image[i][j].rgbtRed = auxiliarR;
            image[i][j].rgbtGreen = auxiliarG;
            image[i][j].rgbtBlue = auxiliarB;

        }
    }
}

void blur(int height, int width, RGBTRIPLE image[height][width]) {
    
}