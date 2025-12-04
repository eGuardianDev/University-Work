
#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <cstdint>

#include "BMP_File.hpp"
#include "BMP_Manipulation.hpp"
#include "Algorithms.hpp"

int fd;


void error(const char * msg){
    if(fd >=0){
        close(fd);
    }
    throw std::runtime_error(msg);
}

#define INPUT_FILE "compress/output.bmp"
#define OUTPUT_FILE "output.bmp"
#define MAX_FILE_SIZE 25 * 1024 * 1024  // 25 MB - 4K image, 24 bit


int main(int argc, char*argv[]){


    // * == open file == *
  fd = open(INPUT_FILE, O_RDONLY);

  if(fd < 0){
    error("File failed to open.");
  }

    // * == read file == *
  unsigned char buff_header[138];

  int size = read(fd, buff_header,138);

  bmp_header header = load_header(buff_header);  


    // * == verification == *

    uint16_t expected_signature = 'B' | 'M' << 8;
  if(header.signature != expected_signature){
    error("Opened file isn't a BMP format.");
  }

  header_print_basic(header);

  // * Reading data from image

  
  std::cout << "Data starts at " << header.data_offset << std::endl;
  
  lseek(fd,header.data_offset,SEEK_SET);
  
  uint8_t *buff_data = new uint8_t[MAX_FILE_SIZE];
  
  int size_of_read_data = read(fd, buff_data, MAX_FILE_SIZE);
  

  std::cout << "Size of data:  "<< size_of_read_data << std::endl;
  std::cout << "Size of image: "<< header.image_size << std::endl;
  std::cout << "Data is correctly loaded: " << std::boolalpha <<
  ((size_of_read_data  - header.data_offset) == header.image_size) << std::endl;
  std::cout << " Size of header "<< header.i_file_size << ((header.i_file_size == 124) ? " (BITMAPV5HEADER)" : "") << std::endl;
  std::cout << "Compression used "<< header.compression << std::endl;
  

  if(header.compression != 0){
    error("Cannot decompress images, yet! Please try uncompressed image");
  }
  // * == modification of the image == *

std::cout <<"working on it";
  for(int i =0;i <size_of_read_data;++i){
    long long base = i*3;
    if(base+2 <=size_of_read_data){
      buff_data[base+2] = 255 - buff_data[base + 2];
      buff_data[base+1] = 255 - buff_data[base + 1];
      buff_data[base+0] = 255 - buff_data[base + 0];
      buff_data[base+1] = 0;
    }


    // std::cout << (int)buff_data[base + 2] << " ";
    // std::cout << (int)buff_data[base + 1] << " ";
    // std::cout << (int)buff_data[base + 0] << " ";
    // std::cout << std::endl;
  }
  std::cout << std::endl;

  // * == save file == *
  
  int out_fd = open(OUTPUT_FILE, O_CREAT | O_TRUNC | O_WRONLY, 0664);
  
  lseek(fd, 0, SEEK_SET);
  char buffer[255];

  size = read(fd, buffer,header.data_offset);
  
  write(out_fd, buffer, size);
  
  std::cout << "Writing..." << std::endl;
  size = write(out_fd, buff_data, size_of_read_data);
  std::cout << "data saved: " << size << std::endl;

    // * == clean up == *
  close(fd);
  close(out_fd);
  delete [] buff_data;
    
  return 0;
}
