#include "helpers.h"

#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int k = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen)/3.0);
            image[i][j].rgbtRed = k;
            image[i][j].rgbtBlue = k;
            image[i][j].rgbtGreen = k;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
     for(int i = 0; i < height; i++)
     {
         for(int j = 0; j < width; j++)
         {
            int r = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int g = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int b = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            image[i][j].rgbtRed = r < 255? r :255;
            image[i][j].rgbtBlue = b < 255? b :255;
            image[i][j].rgbtGreen = g < 255? g:255;
         }
     }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width/2; j++)
        {
            RGBTRIPLE tmp;
            int k = width - 1 - j;
                tmp = image[i][j];
                image[i][j] = image[i][k];
                image[i][k] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[height][width];
    for(int i = 0; i < height; i++)
    {
         for(int j = 0; j < width; j++)
         {
            double r = 0, g = 0, b = 0,n = 0;
            for(int w = -1;w < 2; w++ )
            {
                for(int h = -1;h < 2; h++ )
                {
                    //检查 i + h 是否在有效的行范围内。如果不在，跳过当前循环的剩余部分，继续下一次循环。
                    if(i + h < 0||i + h > height - 1)
                    {
                        continue;
                    }
                    if(j + w < 0||j + w> width - 1)
                    {
                        //检查 j + w 是否在有效的列范围内。如果不在，跳过当前循环的剩余部分，继续下一次循环。
                        continue;
                    }
                    //如果前两个条件都不满足（即像素在有效范围内），则将计数器 n 增加 1。
                    n++;
                    r += image[i + h][j + w].rgbtRed;
                    b += image[i + h][j + w].rgbtBlue;
                    g += image[i + h][j + w].rgbtGreen;
                }
            }
            tmp[i][j].rgbtRed = round(r / n);
            tmp[i][j].rgbtGreen = round(g / n);
            tmp[i][j].rgbtBlue = round(b / n);
         }
    }
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            image[i][j] = tmp[i][j];
        }
    }
    return;
}

