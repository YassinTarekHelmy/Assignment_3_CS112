#include <iostream>
#include "bmplib.cpp"
#include <cstring>
using namespace std;
unsigned char image[SIZE][SIZE];

void readImage(unsigned char img[SIZE][SIZE]){
    char bitmapImage[100];
    printf("Please enter the name of the Photo:");
    cin >> bitmapImage;
    strcat(bitmapImage,".bmp");
    readGSBMP(bitmapImage,img);
}

void saveImage(){
    char imageFile[100];
    printf("Enter Your new File Name:");
    cin >> imageFile;
    strcat(imageFile,".bmp");
    writeGSBMP(imageFile,image);
    printf("Thanks For Using My Program, See You Soon!");
}


void blackAndWhite(){
    int avg = 0;
    for (int row = 0; row < SIZE; row++){
        for(int col = 0;col < SIZE; col++){
            avg += image[row][col];
        }
    }
    avg /= (SIZE*SIZE);       //to Get the average you have to divide by the number of pixels in image.
    for (int row = 0; row < SIZE;row++){
        for (int col = 0; col < SIZE; col++){
            if (image[row][col] > avg) image[row][col] = 255;
            else image[row][col] = 0;
        }
    }
}

int main() {
    readImage(image);
    blackAndWhite();
    saveImage();
}
