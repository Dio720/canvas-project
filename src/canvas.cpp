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
Canvas::Canvas(const Canvas& clone) {}

/*!
 * @param source The object we are copying information from.
 * @return A reference to the `this` object.
 */
Canvas& Canvas::operator=(const Canvas& source) { return *this; }

/// Assigns a black color to the whole image.
void Canvas::clear(const Color& /*unused*/) {}

/*!
 * @throw `std::invalid_argument()` it the pixel coordinate is located outside the canvas.
 * @param x The (virtual) X coordinate of the pixel we want to know the color of.
 * @param x The (virtual) Y coordinate of the pixel we want to know the color of.
 * @return The pixel color.
 */
Color Canvas::pixel(coord_t x, coord_t y) const { return BLACK; }

/*!
 * Draw a pixel on the virtual image at the requested coordinate.
 *
 * @note Nothing is done if the  pixel coordinate is located outside the canvas.
 * @param x The (virtual) X coordinate of the pixel we want to know the color of.
 * @param x The (virtual) Y coordinate of the pixel we want to know the color of.
 * @param c The color.
 */
void Canvas::pixel(coord_t x, coord_t y, const Color& c) {}

}  // namespace life
//================================[ canvas.cpp ]================================//
