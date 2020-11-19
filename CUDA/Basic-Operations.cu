
// basic int main function stored here for safe keeping. 
/*
GpuTimer timer;

// size
int size = 10000;

// number of blocks we will be using
int blocks = size / 512 + 1;

// threads per block, = size of problem / number of blocks
int threads = size / blocks;

// host data
int* host_data = new int[size];

// initialize host
zero_initialize(host_data, size);

// device data
int* device_data = new int[size];

// allocate for device
allocate<int>(&device_data, size);

// initialize device
index_initialize <<< blocks, threads >>>(device_data);

// square device
//square<int><<< 1, size >>> (device_data);

// copy device to host
copy_to_host<int>(host_data, device_data, size);

cudaDeviceReset();

// print contents
print_array(host_data, size);
*/




