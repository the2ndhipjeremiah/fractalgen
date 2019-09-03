#pragma once
#pragma pack(push, 2) // stops any padding that may cause unreadable file.

struct BitmapInfoHeader
{
	__int32 header_size{ 40 };
	__int32 width{ 0 };
	__int32 height{ 0 };
	__int16 planes{ 1 };
	__int16 bits_per_pixel{ 24 };
	__int32 compression{ 0 };
	__int32 data_size{ 0 };
	__int32 horizontal_resolution{ 2400 };
	__int32 vertical_resolution{ 2400 };
	__int32 colors{ 0 };
	__int32 important_colors{ 0 };
};

#pragma pack(pop)