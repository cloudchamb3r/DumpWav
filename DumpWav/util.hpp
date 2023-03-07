#pragma once
#include <algorithm>

namespace util {
	
	namespace endian {
		enum t_endian {
			little, 
			big,
		};

		static constexpr t_endian NativeEndian() {
			return (0xffffff & 1) == 1 
				? t_endian::little 
				: t_endian::big;
		}

		template<typename T>
		constexpr static T ByteSwap(T val) {
			for (int i = 0; i < sizeof(T); i++) {
				std::swap(((char*)val)[i], ((char*)val)[sizeof(T) - 1 - i]);
			}
			return val;
		}

		template<typename T>
		constexpr static T BigEndian(T val) {
			if (NativeEndian() == t_endian::big) return val;
			return ByteSwap<T>(val);
		} 

		template<typename T>
		constexpr static T LittleEndian(T val) {
			if (NativeEndian() == t_endian::little) return val;
			return ByteSwap<T>(val);
		}
	}
}