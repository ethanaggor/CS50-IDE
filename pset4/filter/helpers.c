#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //Iterate through each row
    for (int i = 0; i < height; i++)
    {
        //Iterate through each column
        for (int j = 0; j < width; j++)
        {
            //Set a value for avg variable
            float preavg = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue);
            int avg = round(preavg / 3);

            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //Iterate through each row
    for (int i = 0; i < height; i++)
    {
        //Iterate through each column
        for (int j = 0; j < width; j++)
        {
            //Calculate sepia values
            int sepiaRed = round((.393 * image[i][j].rgbtRed) + (.769 * image[i][j].rgbtGreen) + (.189 * image[i][j].rgbtBlue));
            int sepiaGreen = round((.349 * image[i][j].rgbtRed) + (.686 * image[i][j].rgbtGreen) + (.168 * image[i][j].rgbtBlue));
            int sepiaBlue = round((.272 * image[i][j].rgbtRed) + (.534 * image[i][j].rgbtGreen) + (.131 * image[i][j].rgbtBlue));

            //If a sepia value is greater than 255, cap it at 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            //Set selected pixel value to sepia value
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //Iterate through each row
    for (int i = 0; i < height; i++)
    {
        //Iterate through each column
        for (int j = 0; j < (width / 2); j++)
        {
            //Store temp values
            int temp0 = image[i][j].rgbtRed;
            int temp1 = image[i][j].rgbtGreen;
            int temp2 = image[i][j].rgbtBlue;

            //Vertically mirror current location to opposite location
            image[i][j].rgbtRed = image[i][width - 1 - j].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - 1 - j].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - 1 - j].rgbtBlue;

            //Reflect backwards as well
            image[i][width - 1 - j].rgbtRed = temp0;
            image[i][width - 1 - j].rgbtGreen = temp1;
            image[i][width - 1 - j].rgbtBlue = temp2;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    //Iterate through each row
    for (int row = 0; row < height; row++)
    {
        //Iterate through each column
        for (int col = 0; col < width; col++)
        {
            //Counter for # of adjacent pixels
            int count = 0;
            //Array of possible adjacent pixels
            int adjRow[] = {row - 1, row, row + 1};
            int adjCol[] = {col - 1, col, col + 1};

            //Total RGB values
            float totRed = 0;
            float totGreen = 0;
            float totBlue = 0;

            //Iterate through each combination of row and col that simulates a coordinate on a 3x3
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    int curRow = adjRow[i];
                    int curCol = adjCol[j];

                    if (curRow >= 0 && curRow < height && curCol >= 0 && curCol < width)
                    {
                        //Current pixel containing all RGB values
                        RGBTRIPLE pixel = image[curRow][curCol];

                        //Adding RGB values to total
                        totRed += pixel.rgbtRed;
                        totGreen += pixel.rgbtGreen;
                        totBlue += pixel.rgbtBlue;
                        count++;

                    }
                }
            }

            //After total has been accumulated
            temp[row][col].rgbtRed = round((float)totRed / count);
            temp[row][col].rgbtGreen = round((float)totGreen / count);
            temp[row][col].rgbtBlue = round((float)totBlue / count);
        }
    }

    //Copy temp to original
    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
        {
            image[k][l] = temp[k][l];
        }
    }
    return;
}
