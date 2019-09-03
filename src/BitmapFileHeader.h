#pragma once
#pragma pack(push, 2) // stops any padding that may cause unreadable file.

struct BitmapFileHeader
{
	char header[2]{ 'B', 'M' };
	__int32 file_size{ 0 };
	__int32 reserved{ 0 };
	__int32 data_offset{ 0 };
};

#pragma pack(pop)