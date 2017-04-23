// dtypes.h
// A header file containing definitions of all the major data used

#ifndef DTYPES_H_INCLUDED
#define DTYPES_H_INCLUDED

#include <cstdint>

using BYTE      = uint8_t;
using CHAR      = int8_t;
using WORD      = uint16_t;
using DWORD     = uint32_t;
using LONG      = int32_t;
using WCHAR     = char16_t;
using ULONGLONG = uint64_t;
using BOOL      = bool;
using VOID      = void;

constexpr int SET_ZERO = 0x0;

struct CLSID
{
	DWORD Data1;
	WORD Data2;
	WORD Data3;
	BYTE Data4[8];

	CLSID();
	~CLSID();
}; // struct CLSID

struct FILETIME
{
	DWORD dwLowDateTime;
	DWORD dwHighDateTime;

	FILETIME();
	~FILETIME();
};



#endif // !DTYPES_H_INCLUDED

