/*!
 * Canvas class implementation.
 * @file canvas.cpp
 */

#include "canvas.h"

namespace life {
/*!
 * Deep copy of the canvas.
 * @param clone The object we are copying from.
 */
Canvas::Canvas(const Canvas& clone) {
    m_width = clone.m_width;
    m_height = clone.m_height;
    m_pixels = clone.m_pixels;
}

/*!
 * @param source The object we are copying information from.
 * @return A reference to the `this` object.
 */
Canvas& Canvas::operator=(const Canvas& source) { return *this; }

/// Assigns a black color to the whole image.
void Canvas::clear(const Color& color) {
    for (size_t i{ 0 }; i < m_width; ++i)
        for (size_t j{ 0 }; j < m_height; ++j)
            pixel(i, j, color);
}

/*!
 * @throw `std::invalid_argument()` it the pixel coordinate is located outside the canvas.
 * @param x The (virtual) X coordinate of the pixel we want to know the color of.
 * @param x The (virtual) Y coordinate of the pixel we want to know the color of.
 * @return The pixel color.
 */
Color Canvas::pixel(coord_t x, coord_t y) const {
    if (not in_bounds(x, y))
        throw std::invalid_argument("Invalid pixel coordinate.");
    auto channels = pixel_channels(x, y);
    return Color{ channels[Color::R], channels[Color::G], channels[Color::B] };
}

/*!
 * Draw a pixel on the virtual image at the requested coordinate.
 *
 * @note Nothing is done if the  pixel coordinate is located outside the canvas.
 * @param x The (virtual) X coordinate of the pixel we want to know the color of.
 * @param x The (virtual) Y coordinate of the pixel we want to know the color of.
 * @param c The color.
 */
void Canvas::pixel(coord_t x, coord_t y, const Color& c) {
    if (not in_bounds(x, y))
        return;
    for (int i = 0; i < m_block_size; i++) {
        for (int j = 0; j < m_block_size; j++) {
            if (in_bounds(x + i, y + j)) {
                m_pixels[((y + j) * m_width + (x + i)) * 4 + Color::R] = c.channels[Color::R];
                m_pixels[((y + j) * m_width + (x + i)) * 4 + Color::G] = c.channels[Color::G];
                m_pixels[((y + j) * m_width + (x + i)) * 4 + Color::B] = c.channels[Color::B];
                m_pixels[((y + j) * m_width + (x + i)) * 4 + 3]
                  = 255;  //!< Setting alpha to full opacity
            }
        }
    }
}
}  // namespace life
//================================[ canvas.cpp ]================================//
