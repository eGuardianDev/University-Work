#ifndef BMP_FILE_HPP__
#define BMP_FILE_HPP__

#include <cstdint>
const unsigned int BUFFER_MAX_SIZE = 25 * 1000 * 1000;

#pragma pack(push, 1)
struct bmp_header{
  // Header
  uint16_t signature;
  uint32_t file_size;
  uint32_t data_offset;

  // Info
  uint32_t i_file_size;
  uint32_t width;
  uint32_t height;
  uint16_t planes;
  uint16_t bits_per_pixel;
  uint32_t compression;
  uint32_t image_size;
  uint32_t x_pixels_per_m;
  uint32_t y_pixels_per_m;
  uint32_t colours_used;
  uint32_t important_colours;

  //color table
  uint8_t red_intensity;
  uint8_t green_intensity;
  uint8_t blue_intensity;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct pixel_value{
  uint8_t red;
  uint8_t green;
  uint8_t blue;
  uint8_t alpha;

};
#pragma pack(pop)


#endif // BMP_FILE_HPP__
