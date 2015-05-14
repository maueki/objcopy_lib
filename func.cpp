#include <cstddef>

extern "C" char _binary_test_data_start[];
extern "C" char _binary_test_data_end[];
extern "C" char _binary_test_data_size[];

size_t get_size1() {
	return reinterpret_cast<size_t>(_binary_test_data_size);
}

size_t get_size2() {
	return static_cast<size_t>(_binary_test_data_end - _binary_test_data_start);
}
