#pragma once
#include <vector>
#include <cstdint>
#include "util.hpp"

namespace wav
{
	using namespace util::endian;

	// https://ccrma.stanford.edu/courses/422-winter-2014/projects/WaveFormat/
	__declspec(align(1)) struct RiffHeader {
		uint32_t chunkId; // riff
		uint32_t chunkSize;
		uint32_t format; // wave

		RiffHeader(uint32_t sz): 
			chunkId(BigEndian(0x52494646)), 
			chunkSize(LittleEndian(sz)), 
			format(BigEndian(0x57415645)) {}
		explicit RiffHeader() = default;
	};

	__declspec(align(1)) struct FmtHeader{
		uint32_t fmtChunkId;  // fmt
		uint32_t fmtChunkSize;
		uint16_t audioFormat;
		uint16_t numChannels;
		uint32_t sampleRate;
		uint32_t byteRate;
		uint16_t blockAlign;
		uint16_t bitsPerSample; 

		FmtHeader(
			bool isMono,   // true for mono, false for stereo
			uint32_t sampleRate, 
			uint16_t bitsPerSample
		) :
			fmtChunkId(BigEndian(0x666d7420)),
			fmtChunkSize(LittleEndian(16)),
			audioFormat(LittleEndian(1)),
			numChannels(isMono? LittleEndian(1) : LittleEndian(2)),
			sampleRate(LittleEndian(sampleRate)),
			bitsPerSample(LittleEndian(bitsPerSample)) {
			byteRate = LittleEndian(sampleRate * numChannels * bitsPerSample / 8);
			blockAlign = LittleEndian(numChannels * bitsPerSample / 8);
		}

		explicit FmtHeader() = default;
	};

	__declspec(align(1)) struct DataHeader
	{
		uint32_t dataChunkId;
		uint32_t dataChunkSize;

		static DataHeader FromFmtHeader(const FmtHeader& fmt, uint32_t numSamples) {
			DataHeader ret;
			ret.dataChunkId = BigEndian(0x64617461);
			ret.dataChunkSize = LittleEndian(numSamples * fmt.numChannels * fmt.bitsPerSample / 8);
		}

		explicit DataHeader() = default;
	};

	class WavFile {
		RiffHeader riffHeader;
		FmtHeader fmtHeader; 
		DataHeader dataHeader;
		std::vector<char> data;

	public:

	};
}
