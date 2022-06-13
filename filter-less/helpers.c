#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int grayscale = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = grayscale;
            image[i][j].rgbtGreen = grayscale;
            image[i][j].rgbtRed = grayscale;


        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp_image[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // store number as int to avoid byte overrflow durign arithmatic.
            int sepiared = round((0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue));
            int sepiagreen = round((0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue));
            int sepiablue = round((0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue));

            //cap rgb value at 255
            if (sepiared > 255)
            {
                sepiared = 255;
            }
            if (sepiagreen > 255)
            {
                sepiagreen = 255;
            }
            if (temp_image[i][j].rgbtRed > 255)
            {
                sepiablue = 255;
            }
            temp_image[i][j].rgbtRed = sepiared;
            temp_image[i][j].rgbtGreen = sepiagreen;
            temp_image[i][j].rgbtBlue = sepiablue;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp_image[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp_image[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp_image[i][j].rgbtRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp_pixel[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp_pixel[i][j].rgbtRed = image[i][width - 1 - j].rgbtRed;
            temp_pixel[i][j].rgbtBlue = image[i][width - 1 - j].rgbtBlue;
            temp_pixel[i][j].rgbtGreen = image[i][width - 1 - j].rgbtGreen;
            temp_pixel[i][width - 1 - j].rgbtRed = image[i][j].rgbtRed;
            temp_pixel[i][width - 1 - j].rgbtBlue = image[i][j].rgbtBlue;
            temp_pixel[i][width - 1 - j].rgbtGreen = image[i][j].rgbtGreen;

        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp_pixel[i][j].rgbtRed;
            image[i][j].rgbtBlue = temp_pixel[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp_pixel[i][j].rgbtGreen;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp_image[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp_image[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if ((i == 0) && (j == 0)) //top left corneer
            {
                temp_image[i][j].rgbtRed =
                    round((image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 4.0);
                temp_image[i][j].rgbtGreen =
                    round((image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 4.0);
                temp_image[i][j].rgbtBlue =
                    round((image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 4.0);
            }
            else if ((i == 0) && (j == width - 1)) //top right corner
            {
                temp_image[i][j].rgbtRed =
                    round((image[i][j].rgbtRed + image[i][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed) / 4.0);
                temp_image[i][j].rgbtGreen =
                    round((image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen) / 4.0);
                temp_image[i][j].rgbtBlue =
                    round((image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue) / 4.0);
            }
            else if ((j == 0) && (i == height - 1)) //bottom left corner
            {
                temp_image[i][j].rgbtRed =
                    round((image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j + 1].rgbtRed) / 4.0);
                temp_image[i][j].rgbtGreen =
                    round((image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j + 1].rgbtGreen) / 4.0);
                temp_image[i][j].rgbtBlue =
                    round((image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j + 1].rgbtBlue) / 4.0);
            }
            else if ((i == height - 1) && (j == width - 1)) //bottom right corner
            {
                temp_image[i][j].rgbtRed =
                    round((image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i][j - 1].rgbtRed) / 4.0);
                temp_image[i][j].rgbtGreen =
                    round((image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i][j - 1].rgbtGreen) / 4.0);
                temp_image[i][j].rgbtBlue =
                    round((image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i][j - 1].rgbtBlue) / 4.0);
            }
            else if (i == 0) //top row
            {
                temp_image[i][j].rgbtRed =
                    round((image[i][j].rgbtRed + image[i][j - 1].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 6.0);
                temp_image[i][j].rgbtGreen =
                    round((image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 6.0);
                temp_image[i][j].rgbtBlue =
                    round((image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 6.0);
            }
            else if (i == height - 1) //bottom row
            {
                temp_image[i][j].rgbtRed =
                    round((image[i][j].rgbtRed + image[i][j - 1].rgbtRed + image[i][j + 1].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed) / 6.0);
                temp_image[i][j].rgbtGreen =
                    round((image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i][j + 1].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen) / 6.0);
                temp_image[i][j].rgbtBlue =
                    round((image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i][j + 1].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue) / 6.0);
            }
            else if (j == 0) //fist column
            {
                temp_image[i][j].rgbtRed =
                    round((image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i - 1][j].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 6.0);
                temp_image[i][j].rgbtGreen =
                    round((image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 6.0);
                temp_image[i][j].rgbtBlue =
                    round((image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 6.0);
            }
            else if (j == width - 1) //last column
            {
                temp_image[i][j].rgbtRed =
                    round((image[i][j].rgbtRed + image[i][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j - 1].rgbtRed) / 6.0);
                temp_image[i][j].rgbtGreen =
                    round((image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j - 1].rgbtGreen) / 6.0);
                temp_image[i][j].rgbtBlue =
                    round((image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j - 1].rgbtBlue) / 6.0);
            }
            else //all the other pixels
            {
                temp_image[i][j].rgbtRed =
                    round((image[i][j].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j - 1].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 9.0);
                temp_image[i][j].rgbtGreen =
                    round((image[i][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j - 1].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 9.0);
                temp_image[i][j].rgbtBlue =
                    round((image[i][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j - 1].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 9.0);
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp_image[i][j];
        }
    }
    return;
}
