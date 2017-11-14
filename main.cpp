#include <iostream>
#include <string>
#include <vector>
using namespace std;
//ask the user to input images until they have 10 or as many as they desire under 10
//convert the images to matrixes
//average the images together
//save the image as a new image
Bitmap image;
Pixel rgb;
int row;
int col;

//this code will ask the user to input a bmp file
//Done
string addImage()
{
    string fileName;
    cout << "Enter the name of a valid bmp file" << endl;
    cin >> fileName;
    return fileName;
}

//this code will ask the user if they would like to save the composite image
//Done
void saveImage()
{
    string fileSave;
    cout << "Enter a name to save the file" << endl;
    cin >> fileSave;
    image.fromPixelMatrix(compositeImage);
    image.save(fileSave);
}

//Checks if the image is the right size
//Done
bool checkImageSize(int row,int col)
{
    if ( row == 600)
    {
        if ( col == 400)
        {
            return 1;
        }
        else if (col != 400)
        {
            return 0;
        }
    }
    else if (row != 600)
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
    
    if (validBmp == true)
    {
        cout << "Image is valid" << endl;
    }
    else if (validBmp == false)
    {
        cout << "Invalid File Type." << endl;
    }
}

//this code will create a composite form of all pixel averages
Bitmap composeImage()
{
    
}

//this code will average the RGB Value of a pixel across all images
Pixel averageRGB(int row, int col, vector <vector<Pixel> > bmp)
{
    Pixel finalPixel;
    for (int i = 0 ; i < numImages ; i++)
    {
        
    }
}
//this code will convert the users input image into a matrix (vector of vector of pixels)
vector<vector<Pixels>> toMatrix(string addImage)
{
    
    vector <vector <Pixel> > toPixelMatrix();
    vector <vector<Pixel> > bmp;
    bmp = image.toPixelMatrix;
    return bmp;

}

//This is where all the functions will be used together
int main()
{
    vector<vector <vector <Pixels>>> files;

    cout << "Welcome to the Composite Image Maker." << endl;
    cout << "You will have the option to enter up to 10 images." << endl;
    for (int i = 0 ; i < 10 ; i++)
    {
        addImage();
        if (addImage() == "DONE")
        {
            numImages = i+1;
            i = 10;
        }
        else
        {
            checkImageType(addImage);
            if (checkImageType == 1)
            {
                toMatrix(addImage);
                toMatrix.size = row;
                toMatrix[row].size = col;
                checkImageSize(row,col);
                if (checkImageSize == 1)
                {
                    files[i] = toMatrix;
                }
                else if (checkImageSize == 0)
                {
                    cout << "Incorrect image size, please retry." << endl;
                    i--;
                }


            }
            else if (checkImageType == 0)
            {
                i--;
                cout << "Retry." << endl;
            }
            

            
        }
    }

}
