#include <cstddef>
#include <fstream>
#include <iostream>
#include <vector>

#include "canvas.h"
#include "lodepng.h"

using namespace life;

/// Saves an image as a **ascii** PPM file.
bool save_ppm3(const unsigned char* data,
               size_t w,
               size_t h,
               size_t d,
               const std::string& file_name) {
    std::ofstream ofs_file(file_name, std::ios::out);
    if (not ofs_file.is_open()) {
        return false;
    }

    ofs_file << 'P' << d << '\n' << w << ' ' << h << "\n255\n";
    for (size_t i{ 0 }; i < w * h * d; ++i) {
        ofs_file << (int)data[i] << ' ';
    }
    ofs_file.close();

    return true;  // stub
}

// Example 1
// Encode from raw pixels to disk with a single function call
// The image argument has width * height RGBA pixels or width * height * 4 bytes
void encode_png(const char* filename, const unsigned char* image, unsigned width, unsigned height) {
    // Encode the image
    unsigned error = lodepng::encode(filename, image, width, height);

    // if there's an error, display it
    if (error != 0U) {
        std::cout << "encoder error " << error << ": " << lodepng_error_text(error) << std::endl;
    }
}

// Saves image to filename given as argument. Warning, this overwrites the file
// without warning!
int main(int argc, char* argv[]) {
    // NOTE: this sample will overwrite the file or test.png without warning!
    const char* filename = argc > 1 ? argv[1] : "test.png";

    // Test parameters: generate some image
    unsigned width = 20;
    unsigned height = 15;
    short block_size = 50;

    // Criar uma imagem para desenho.
    Canvas image(width, height, block_size);

    // Preenche os pixels da imagem com um tabuleiro.
    for (auto x{ 0U }; x < width; ++x) {
        for (auto y{ 0U }; y < height; ++y) {
            if ((y % 2) != 0U) {
                if ((x % 2) == 0U) {
                    // another way to define a color.
                    image.pixel(x, y, color_pallet["deep_sky_blue"]);
                    // image.pixel( x,y , DEEP_SKY_BLUE );
                } else {
                    image.pixel(x, y, RED);
                }
            } else if ((x % 2) == 0U) {
                image.pixel(x, y, RED);
            } else {
                image.pixel(x, y, DEEP_SKY_BLUE);
            }
        }
    }
    /// X = Column, Y = Row
    image.pixel(5, 2, color_pallet["green"]);
    std::cout << ">>> Gravando imagem '" << filename << "', dimensions: " << width << " x "
              << height << " (bs = " << block_size << "), please wait...\n";

    encode_png(filename, image.pixels(), image.real_width(), image.real_height());
    save_ppm3(image.pixels(), image.real_width(), image.real_height(), 4, "test.ppm");
    std::cout << "<<< done!\n";
}
