
#ifndef __WAD_H
#define __WAD_H

// https://zdoom.org/wiki/WAD

namespace wad
{
	enum GameType_
	{
		GameType_Doom = 0,
		GameType_Doom2,
		GameType_Hexen,
		GameType_Heretic,
		GameType_Doom64,
		GameType_Strife
	};

	enum Color_
	{
		Color_Black = 0x0,
		Color_Blue 0x1,
		Color_Green 0x2,
		Color_Cyan 0x3,
		Color_Red 0x4,
		Color_Magenta 0x5,
		Color_Brown 0x6,
		Color_LightGray 0x7,
		Color_DarkGray = 0x8,
		Color_LightBlue = 0x9,
		Color_LightGreen = 0xA,
		Color_LightCyan = 0xB,
		Color_LightRed = 0xC,
		Color_LightMagenta = 0xD,
		Color_Yellow = 0xE,
		Color_White = 0xF
	};

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

	// PLAYPAL
	struct palette_t
	{
		unsigned char colors[255][3];
	};

	// COLORMAP
	// TODO

	// TINTTAB (Hexen, Heretic)
	// TODO

	// ENDOOM / ENDTEXT (Heretic) / ENDSTRF (Strife)
	// https://doomwiki.org/wiki/ENDOOM
	struct endoom_t
	{
		char text[25][80];
		Color_ foreground_color[25][80];
		Color_ background_color[25][80];
	};

	// THINGS
	struct thing_t // dthing_t & hthing_t
	{
		// https://doom.fandom.com/wiki/Thing
	};

	// FLATS
	struct flat_t // 64x65 in Heretic, 64x128 in Hexen
	{
		unsigned char image[64*64];
		// https://doomwiki.org/wiki/Flat
	};

	// SPRITES
	struct sprite_t
	{
		
	};

	// PATCHES
	struct patch_t
	{

	};

	struct map_t
	{
		
	};

	bool LoadFromMemory(const void *file_data, int file_size, GameType type, file_content_t *result);
}

#endif

#ifdef WAD_IMPLEMENTATION

namespace wad
{
	bool LoadFromMemory(const void *file_data, int file_size, GameType type, file_content_t *result)
	{
		// TODO
		return false;
	}
}

#endif