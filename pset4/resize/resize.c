#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: resize n infile outfile\n");
        return 1;
    }

    // check that n is an integer 
    for (int i=0, l=strlen(argv[1]); i<l; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("n must be an integer\n");
            return 2;
        }
    }

    // remember n
    int n = atoi(argv[1]);

    // check that n is in [1,100]
    if (n < 1 || n > 100)
    {
        printf("n must be an integer between [1,100]\n");
        return 2;
    }

    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // modify data of headers necessary to resize the file
    int OWidth = bi.biWidth;
    // determine original padding for scanlines
    int OPadding =  (4 - (OWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // scale width and height by factor of n
    bi.biWidth *= n;
    bi.biHeight *= n;

    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // biSizeImage = width * height * 3 bytes pp + (padding per line)
    bi.biSizeImage = (bi.biWidth * abs(bi.biHeight) * 3) + padding*abs(bi.biHeight);
    // change the file size to reflect the new file size
    bf.bfSize = bi.biSizeImage + bf.bfOffBits;

    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);
    
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < OWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;
            
            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // write RGB triple to outfile n times horizontally
            for(int k = 0; k < n; k++)
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
        }

        // skip over padding, if any
        fseek(inptr, OPadding, SEEK_CUR);
        
        // then add it back (to demonstrate how)
        for (int k = 0; k < padding; k++)
            fputc(0x00, outptr);

        // if i % n is 0, write a new row, else repeat the last row
        long offset = OWidth*sizeof(RGBTRIPLE) + OPadding;
        if((i+1) % n != 0)
            fseek(inptr, -offset, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}