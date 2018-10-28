#ifndef __SERIALIZATION_HPP__
#define __SERIALIZATION_HPP__

#include <string>
#include <vector>


#if _USE_MMAP
#include <boost/iostreams/device/mapped_file.hpp>
#include <boost/iostreams/stream.hpp>
using MappedFile = boost::iostreams::mapped_file_source;
using Stream = boost::iostreams::stream<MappedFile>;
#else
#include <fstream>
using MappedFile = std::string;
using Stream = std::ifstream;
#endif


void serialize_number(std::ostream &out, uint64_t number);

uint64_t load_number(std::istream &in);

template <typename T>
void serialize_number_vector(std::ostream &out,
                             const std::vector<T> &vector,
                             size_t bits_per_number = sizeof(T) * 8);
template <typename T>
std::vector<T> load_number_vector(std::istream &in);

uint64_t get_number_vector_size(std::istream &in);


template <class Map>
void serialize_number_number_map(std::ostream &out, const Map &map);

template <class Map>
void load_number_number_map(std::istream &in, Map *map);


template <class Map>
void serialize_string_number_map(std::ostream &out, const Map &M);

template <class Map>
void load_string_number_map(std::istream &in, Map *map);


#endif // __SERIALIZATION_HPP__
