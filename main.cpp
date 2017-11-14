#include <iostream>
#include <string>
#include <vector>
#include "bitmap.h"
using namespace std;
//ask the user to input images until they have 10 or as many as they desire under 10
//convert the images to matrixes
//average the images together
//save the image as a new image
Bitmap image;
Pixel rgb;
int row;
int col;
int numImages;




//this code will ask the user to input a bmp file
//Done
string addImage()
{
    string fileName;
    cout << "Enter the name of a valid bmp file" << endl;
    cin >> fileName;
    return fileName;
}

//this code will ask the user if they would like to save the image
void saveImage(vector<vector<Pixel> > endProduct)
{
    string fileSave;
    cout << "Enter a name to save the file." << endl;
    cin >> fileSave;
    image.fromPixelMatrix(endProduct);
    image.save(fileSave);
}

//Checks if the image is the right size
//Done
bool checkImageSize(int row,int col)
{
    if ( row == 400)
    {
        if ( col == 600)
        {
            return 1;
        }
        else if (col != 600)
        {
            return 0;
        }
    }
    else if (row != 400)
    {
        return 0;
    }
}

//Checks if the image is a valid file type
//Done
bool checkImageType(string addImage)
{
    cout << "Checking image validity" << endl;
    image.open(addImage);
    bool validBmp;
    validBmp = image.isImage();

    if (validBmp == 1)
    {
        cout << "Image is valid" << endl;
        return true;
    }
    else if (validBmp == 0)
    {
        cout << "Invalid File Type." << endl;
        return false;
    }
}

//this code will create a composite form of all pixel averages
vector <vector<Pixel> > compositeImage(vector<vector<Pixel> > pixelMatrix, vector<vector<Pixel> > oldMatrix)
{
    int r;
    int c;
    vector<vector<Pixel > > newMatrix;
    for (r = 0 ; r < 400 ; r++ )
    {
        for (c = 0 ; c < 600 ; c++)
        {
            newMatrix[r][c].red = oldMatrix[r][c].red + pixelMatrix[r][c].red;
            newMatrix[r][c].green = oldMatrix[r][c].green + pixelMatrix[r][c].green;
            newMatrix[r][c].blue = oldMatrix[r][c].blue + pixelMatrix[r][c].blue;

        }
    }
    return newMatrix;

}

//this code will average the RGB Value of a pixel across all images
vector<vector<Pixel> > averageMatrix(vector <vector<Pixel> > compImage, int numImages)
{
    int row2;
    int col2;
    vector<vector<Pixel> > finalMatrix;
    for (row2 = 0 ; row2 < 400 ; row2++)
    {
        for (col2 = 0 ; col2 < 600 ; col2++)
        {

            finalMatrix[row2][col2].red = compImage[row2][col2].red/numImages;
            finalMatrix[row2][col2].green = compImage[row2][col2].green/numImages;
            finalMatrix[row2][col2].blue = compImage[row2][col2].blue/numImages;


        }
    }
    return finalMatrix;
}
//this code will convert the users input image into a matrix (vector of vector of pixels)
vector<vector<Pixel> > toMatrix(string addImage)
{

    vector <vector <Pixel> > bmp;
    bmp = image.toPixelMatrix();
    return bmp;

}

//This is where all the functions will be used together
int main()
{
    vector<string> files;
    vector<vector<Pixel> > compImage;

    cout << "Welcome to the Composite Image Maker." << endl;
    cout << "You will have the option to enter up to 10 images." << endl;
    for (int i = 0 ; i < 10 ; i++)
    {
        string pic = addImage();
        if (pic == "DONE")
        {
            numImages = i;
            i = 10;
        }
        else
        {

            bool isValid;
            image.open(pic);
            isValid = image.isImage();

            if (isValid == 1)
            {
                int r;
                int c;
                vector<vector<Pixel> > pixelMatrix = toMatrix(pic);
                pixelMatrix.size();
                pixelMatrix[row].size();
                r = row;
                c = col;
                checkImageSize(row,col);
                if (isValid == 1)
                {
                vector<vector<Pixel> > oldMatrix;
                compImage = compositeImage(pixelMatrix, oldMatrix);
                cout << "Image " << i << " is complete." << endl;
                }
                else if (isValid == 0)
                {
                    cout << "Incorrect image size, please retry." << endl;
                    i--;
                }


            }
            else if (isValid == 0)
            {
                i--;
                cout << "Retry." << endl;
            }



        }
    }
    vector<vector<Pixel> > endProduct = averageMatrix(compImage, numImages);
    saveImage(endProduct);

    return 0;
}
