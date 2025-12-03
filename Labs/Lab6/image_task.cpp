// ====================================================
// img PROCESSING LAB TASK (with hints + self-check)
// ====================================================
//
// Toy Example (3×3):
// A =
//   10   200   30
//   40    60   80
//   90   100  120
//
// Rotation 90° clockwise:
//   90   40   10
//   100  60  200
//   120  80   30
//
// Rotation 180°:
//   120  100   90
//   80    60   40
//   30   200   10
//
// Rotation 270° clockwise:
//   30    80  120
//   200   60  100
//   10    40   90
//
// Flip Horizontal (mirror left-right):
//   30   200   10
//   80    60   40
//   120  100   90
//
// Flip Vertical (mirror top-bottom):
//   90   100  120
//   40    60   80
//   10   200   30
//
// Blur (center only blurred):
//   (60 + 40 + 80 + 200 + 100) / 5 = 96
//   newarray matrix becomes:
//   10   200   30
//   40    96   80
//   90   100  120
//
// ----------------------------------------------------
// Self-check Index Mapping (for ROWS x COLS matrix):
//
// Rotation 90° clockwise:
//   newarray[i][j] = img[ROWS - 1 - j][i]
//
// Rotation 180°:
//   newarray[i][j] = img[ROWS - 1 - i][COLS - 1 - j]
//
// Rotation 270° clockwise:
//   newarray[i][j] = img[j][COLS - 1 - i]
//
// Horizontal flip (left-right mirror):
//   newarray[i][j] = img[i][COLS - 1 - j]
//
// Vertical flip (top-bottom mirror):
//   newarray[i][j] = img[ROWS - 1 - i][j]
//
// Blur (center only):
//   newarray[i][j] = (img[i][j] + img[i-1][j] + img[i+1][j] + img[i][j-1] + img[i][j+1]) / 5
//   Copy edges directly
// ====================================================

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

const int ROWS = 16;
const int COLS = 16;

// Example img (16x16 smiley)
int img[ROWS][COLS] = {
    {255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255},
    {255,255,255,255,150,150,255,255,255,255,150,150,255,255,255,255},
    {255,255,255,150,0,0,150,255,255,150,0,0,150,255,255,255},
    {255,255,150,0,0,0,0,150,150,0,0,0,0,150,255,255},
    {255,150,0,0,0,0,0,0,0,0,0,0,0,0,150,255},
    {255,150,0,0,0,0,0,0,0,0,0,0,0,0,150,255},
    {255,150,0,0,150,150,0,0,0,0,150,150,0,0,150,255},
    {255,150,0,0,0,0,0,0,0,0,0,0,0,0,150,255},
    {255,150,0,0,0,0,0,0,0,0,0,0,0,0,150,255},
    {255,150,0,0,150,150,150,150,150,150,150,150,0,0,150,255},
    {255,255,150,0,0,0,0,0,0,0,0,0,0,0,150,255},
    {255,255,255,150,0,0,0,0,0,0,0,0,0,150,255,255},
    {255,255,255,255,150,0,0,0,0,0,0,0,150,255,255,255},
    {255,255,255,255,255,150,150,150,150,150,150,150,255,255,255,255},
    {255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255},
    {255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255}
};

// Helper: Save matrix as .png file (requires stb_image_write.h)
void savePNG(const string &dir, const string &filename, int img[ROWS][COLS]) {
    unsigned char buffer[ROWS * COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            buffer[i * COLS + j] = (unsigned char) img[i][j];
        }
    }
    string path = dir + "/" + filename;
    if (stbi_write_png(path.c_str(), COLS, ROWS, 1, buffer, COLS)) {
        cout << "Saved " << path << endl;
    } else {
        cerr << "Error saving " << path << endl;
    }
}

int main() {
    int img[16][16] = {
    {255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255},
    {255,255,255,255,150,150,255,255,255,255,150,150,255,255,255,255},
    {255,255,255,150,0,0,150,255,255,150,0,0,150,255,255,255},
    {255,255,150,0,0,0,0,150,150,0,0,0,0,150,255,255},
    {255,150,0,0,0,0,0,0,0,0,0,0,0,0,150,255},
    {255,150,0,0,0,0,0,0,0,0,0,0,0,0,150,255},
    {255,150,0,0,150,150,0,0,0,0,150,150,0,0,150,255},
    {255,150,0,0,0,0,0,0,0,0,0,0,0,0,150,255},
    {255,150,0,0,0,0,0,0,0,0,0,0,0,0,150,255},
    {255,150,0,0,150,150,150,150,150,150,150,150,0,0,150,255},
    {255,255,150,0,0,0,0,0,0,0,0,0,0,0,150,255},
    {255,255,255,150,0,0,0,0,0,0,0,0,0,150,255,255},
    {255,255,255,255,150,0,0,0,0,0,0,0,150,255,255,255},
    {255,255,255,255,255,150,150,150,150,150,150,150,255,255,255,255},
    {255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255},
    {255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255}
};
    int newarray[16][16];
    int i=0,j;
    string outDir = "output_images";

    // Create directory if it doesn’t exist
    if (!fs::exists(outDir)) {
        fs::create_directory(outDir);
    }

    // Save original
    savePNG(outDir, "original.png", img);

    // ----------------------------------------------------
    // 1. ROTATIONS
    // ----------------------------------------------------
    int rotated90[ROWS][COLS];
    // Hint: newarray[i][j] = img[ROWS - 1 - j][i]
    for (int i = 0; i<19;i++) { 
        for (int j = 0;j<19;j++) { 
            newarray[i][j] = img[j][i];
        }
    }
    savePNG(outDir, "rotated90.png", newarray);

    int rotated180[ROWS][COLS];
    // Hint: newarray[i][j] = img[ROWS - 1 - i][COLS - 1 - j]
    for (int i = 0; i<19;i++) { 
        for (int j = 0;j<19;j++) { 
    newarray[i][j] = img[ROWS - 1 - i][COLS - 1 - j];
        }
    }
    savePNG(outDir, "rotated180.png", newarray);

    int rotated270[ROWS][COLS];
    // Hint: newarray[i][j] = img[j][COLS - 1 - i]
    for (int i = 0; i<19;i++) { 
        for (int j = 0;j<19;j++) { 
    rotated270[i][j] = img[j][COLS - 1 - i];
        }
    }
    savePNG(outDir, "rotated270.png", rotated270);

    // ----------------------------------------------------
    // 2. FLIPS
    // ----------------------------------------------------

    int flippedH[ROWS][COLS];
    // Hint: newarray[i][j] = img[i][COLS - 1 - j]
    for (int i = 0; i<19;i++) { 
        for (int j = 0;j<19;j++) { 
    flippedH[i][j] = img[i][COLS - 1 - j];
        } 
    }
    savePNG(outDir, "flipped_horizontal.png", flippedH);

    int flippedV[ROWS][COLS];
    // Hint: newarray[i][j] = img[ROWS - 1 - i][j]
    for (int i = 0; i<19;i++) { 
        for (int j = 0;j<19;j++) { 
    flippedV[i][j] = img[ROWS - 1 - i][j];
        }
    }
    savePNG(outDir, "flipped_vertical.png", flippedV);

    // ----------------------------------------------------
    // 3. BLUR
    // ----------------------------------------------------

    int blurred[ROWS][COLS];
    // Hint: newarray[i][j] = average of itself + 4 neighbors
    //       Do NOT overwrite original while computing.
    //       Copy edges directly.
  for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++) {
            int average = (img[i][j] + img[i+1][j] + img[i-1][j] + img[i][j-1] + img[i][j+1])/5;
            if ( i == ROWS-1 or j == COLS)
                blurred[i][j] = img[i][j];
            else
                blurred[i][j] = average;
        }
    }
    savePNG(outDir, "blurred.png", blurred);

    return 0;
}