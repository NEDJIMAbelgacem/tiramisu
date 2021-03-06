#include <fstream>

template<typename T>
void print_global_buffer_to_file( T *device_data, int size, const std::string &file_path )
{
    T *host_data = (T *) malloc( size );
    cudaError_t cudaStatus = cudaMemcpy(device_data, host_data, size * sizeof( T ), cudaMemcpyHostToDevice);
    std::ofstream output_file;
    output_file.open( file_path.c_str() );
    if ( output_file.is_open() )
    {
      for (int i = 0; i < size; ++i)
          output_file << (double)host_data[i] << "\n";
      output_file.close();
    } else {
      std::cout << "Couldn't open file: " << file_path << std::endl;
    }
    free( host_data );
}