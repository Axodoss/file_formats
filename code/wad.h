
#ifndef __WAD_H
#define __WAD_H

// https://zdoom.org/wiki/WAD

namespace wad
{
	struct header_t
	{
		char id[4]; // IWAD or PWAD
		int number_of_entries;
		int offset;
	};

	struct lump_t
	{
		int offset;
		int length;
		char name[8] = {0};
	};

	bool LoadFromMemory(const void *file_data, int file_size, file_content_t *result);
}

#endif

#ifdef WAD_IMPLEMENTATION

namespace wad
{
	bool LoadFromMemory(const void *file_data, int file_size, file_content_t *result)
	{
		// TODO
		return false;
	}
}

#endif