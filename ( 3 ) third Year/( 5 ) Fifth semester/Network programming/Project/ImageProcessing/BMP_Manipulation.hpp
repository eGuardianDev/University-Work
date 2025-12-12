#ifndef BMP_MANIPULATION_HPP__
#define BMP_MANIPULATION_HPP__


#include "BMP_File.hpp"
#include <cstdio>
#include <iostream>
#include <fcntl.h>

bmp_header load_header(unsigned char input[138]){

  bmp_header header;

    header.signature = input[0] | (input[1] << 8);

    header.file_size = 
        input[2]       |
        input[3] << 8  |
        input[4] << 16 |
        input[5] << 24;

    header.data_offset =
        input[10]       |
        input[11] << 8  |
        input[12] << 16 |
        input[13] << 24;

    header.i_file_size =
        input[14]       |
        input[15] << 8  |
        input[16] << 16 |
        input[17] << 24;

    header.width =
        input[18]       |
        input[19] << 8  |
        input[20] << 16 |
        input[21] << 24;

    header.height =
        input[22]       |
        input[23] << 8  |
        input[24] << 16 |
        input[25] << 24;


    
    header.compression =
        input[30]       |
        (input[31] << 8)  |
        (input[32] << 16) |
        (input[33] << 24);

    header.image_size =
        input[34]       |
        (input[35] << 8)  |
        (input[36] << 16) |
        (input[37] << 24);

    header.x_pixels_per_m =
        input[38]       |
        (input[39] << 8)  |
        (input[40] << 16) |
        (input[41] << 24);

    header.y_pixels_per_m =
        input[42]       |
        (input[43] << 8)  |
        (input[44] << 16) |
        (input[45] << 24);

    header.colours_used =
        input[46]       |
        (input[47] << 8)  |
        (input[48] << 16) |
        (input[49] << 24);

    header.important_colours =
        input[50]       |
        (input[51] << 8)  |
        (input[52] << 16) |
        (input[53] << 24);

    header.planes = input[26] | (input[27] << 8);
    header.bits_per_pixel = input[28] | (input[29] << 8);

    return header;
}

void header_print_basic(bmp_header &header)
{
  const char *bmp_format =
":==Header Data==:\n"
"  Signature: %c%c\n"
"  File Size: %u bytes\n"
"    Data Offset: %u bytes\n"
"  Width: %d px\n"
"  Height: %d px\n"
"    Bits Per Pixel: %u\n";
  printf(bmp_format,
      header.signature ,
      (header.signature >> 8),
      header.file_size,
      header.data_offset,
      header.width,
      header.height,
      header.bits_per_pixel);
};

pixel_value read_pixel(uint8_t *buffer,int offset){
    pixel_value res;

    res.blue  = buffer[offset*4 + 0];
    res.green = buffer[offset*4 + 1];
    res.red   = buffer[offset*4 + 2];
    return res;
}


bool validateFile(int fd){
    unsigned char buff_header[138];

    int size = read(fd, buff_header,138);
    if(size <= 138){
        if(size < 40){
            std::cerr << "File isn't too small for an image. Size: " << size << std::endl;
            return false;
        }
    }
    bmp_header header = load_header(buff_header);  
    if (header.signature == 'B' && (header.signature >> 8) ){
        std::cerr << "File header signature isn't correct" << std::endl;
        return false;
    }
    return true;
}


#endif //BMP_MANIPULATION_HPP__
