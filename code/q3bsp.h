
#ifndef Q3BSP_H
#define Q3BSP_H

// http://www.mralligator.com/q3/
// https://github.com/id-Software/Quake-III-Arena/blob/master/common/bspfile.h
// https://github.com/id-Software/Quake-III-Arena/blob/master/common/qfiles.h

#define Q3BSP_FILEID (('P'<<24)+('S'<<16)+('B'<<8)+'I') // little-endian "IBSP"
#define Q3BSP_VERSION 46

#define Q3BSP_MAX_PATH 64

#define Q3BSP_LIGHTMAP_WIDTH 128
#define Q3BSP_LIGHTMAP_HEIGHT 128

#define Q3BSP_SURFACE_POLYGON 1
#define Q3BSP_SURFACE_PATCH 2
#define Q3BSP_SURFACE_TRIANGLES 3
#define Q3BSP_SURFACE_BILLBOARD 4

#define Q3BSP_MAX_WORLD_COORD     (128*1024)
#define Q3BSP_MIN_WORLD_COORD     (-128*1024)
#define Q3BSP_WORLD_SIZE          (MAX_WORLD_COORD - MIN_WORLD_COORD)

#define Q3BSP_MAX_MODELS          0x400
#define Q3BSP_MAX_ENTITY_STRING   0x40000
#define Q3BSP_MAX_LEAFS           0x20000
#define Q3BSP_MAX_PLANES          0x20000
#define Q3BSP_MAX_NODES           0x20000
#define Q3BSP_MAX_LEAF_SURFACES   0x20000
#define Q3BSP_MAX_LEAF_BRUSHES    0x40000
#define Q3BSP_MAX_BRUSHES         0x8000
#define Q3BSP_MAX_BRUSH_SIDES     0x20000
#define Q3BSP_MAX_LIGHTMAPS       0xB4 // 0x800000 / (128*128*3)
#define Q3BSP_MAX_LIGHT_VOLUME    0x100000 // 0x800000 / (3+3+2)
#define Q3BSP_MAX_VISIBILITY      0x200000
#define Q3BSP_MAX_VERTICES        0x80000
#define Q3BSP_MAX_INDEXES         0x80000
#define Q3BSP_MAX_SURFACES        0x20000
#define Q3BSP_MAX_SHADERS         0x400
#define Q3BSP_MAX_FOGS            0x100

#define Q3BSP_SUCCESS 0
#define Q3BSP_INVALID_DATA 1
#define Q3BSP_INVALID_FILEID 2
#define Q3BSP_INVALID_VERSION 3
#define Q3BSP_FILE_CORRUPTED 4

namespace q3bsp
{
	enum directory_e
	{
		Dir_EntityString = 0,
		Dir_Shaders = 1,
		Dir_Planes = 2,
		Dir_Nodes = 3,
		Dir_Leafs = 4,
		Dir_LeafSurfaces = 5,
		Dir_LeafBrushes = 6,
		Dir_Models = 7,
		Dir_Brushes = 8,
		Dir_BrushSides = 9,
		Dir_DrawVertices = 10,
		Dir_DrawIndexes = 11,
		Dir_Fogs = 12,
		Dir_Surfaces = 13,
		Dir_Lightmaps = 14,
		Dir_LightVolumes = 15,
		Dir_Visibility = 16,

		MaxDirectory = 17
	}

	struct lumpt_t
	{
		int offset;
		int length;
	};

	struct header_t
	{
		int id;
		int version;
		lumpt_t lumps[MaxDirectory];
	};

	struct shader_t
	{
		char name[Q3BSP_MAX_PATH];
		int surface_flags;
		int content_flags;
	};

	struct plane_t
	{
		float normal[3];
		float distance;
	};

	struct node_t
	{
		int plane;
		int children[2];
		int mins[3];
		int maxs[3];
	};

	struct leaf_t
	{
		int cluster;
		int area;
		int mins[3];
		int maxs[3];
		int first_leaf_surface;
		int number_of_leaf_surfaces;
		int first_leaf_brush;
		int number_of_leaf_brushes;
	};

	struct model_t
	{
		float mins[3];
		float maxs[3];
		int first_surface;
		int number_of_surfaces;
		int first_brush;
		int number_of_brushes;
	};

	struct brush_t
	{
		int first_brush_side;
		int number_of_brush_sides;
		int shader;
	};

	struct brush_side_t
	{
		int plane;
		int shader;
	};

	struct vertex_t
	{
		float position[3];
		float shader_coords[2];
		float lightmap_coords[2];
		float normal[3];
		unsigned char color[4];
	};

	struct fog_t
	{
		char name[MAX_PATH];
		int brush;
		int visible_side;
	};

	struct surface_t
	{
		int shader;
		int fog;
		int surface_type;

		int first_vertex;
		int number_of_vertices;

		int first_index;
		int number_of_indexes;

		int lightmap;
		int lightmap_start[2];
		int lightmap_size[2];
		float lightmap_origin[3];

		float s_vector[3];
		float t_vector[3];
		float normal[3];

		int patch_size[2];
	};

	struct lightmap_t
	{
		unsigned char data[Q3BSP_LIGHTMAP_WIDTH*Q3BSP_LIGHTMAP_HEIGHT*3];
	};

	struct light_volume_t
	{
		unsigned char ambient[3];
		unsigned char directional[3];
		unsigned char direction[2];
	};

	struct file_content_t
	{
		char entity_string[Q3BSP_MAX_ENTITY_STRING];
		int entity_string_length;

		shader_t shaders[Q3BSP_MAX_SHADERS];
		int number_of_shaders;

		plane_t planes[Q3BSP_MAX_PLANES];
		int number_of_planes;

		node_t nodes[Q3BSP_MAX_NODES];
		int number_of_nodes;

		leaf_t leafs[Q3BSP_MAX_LEAFS];
		int number_of_leafs;

		int leaf_surfaces[Q3BSP_MAX_LEAF_SURFACES];
		int number_of_leaf_surfaces;

		int leaf_brushes[Q3BSP_MAX_LEAF_BRUSHES];
		int number_of_leaf_brushes;

		model_t models[Q3BSP_MAX_MODELS];
		int number_of_models;

		brush_t brushes[Q3BSP_MAX_BRUSHES];
		int number_of_brushes;

		brush_side_t brush_sides[Q3BSP_MAX_BRUSH_SIDES];
		int number_of_brush_sides;

		vertex_t vertices[Q3BSP_MAX_VERTICES];
		int number_of_vertices;

		int indexes[Q3BSP_MAX_INDEXES];
		int number_of_indexes;

		fog_t fogs[Q3BSP_MAX_FOGS];
		int number_of_fogs;

		surface_t surfaces[Q3BSP_MAX_SURFACES];
		int number_of_surfaces;

		lightmap_t lightmaps[Q3BSP_MAX_LIGHTMAPS];
		int number_of_lightmaps;

		light_volume_t light_volumes[Q3BSP_MAX_LIGHT_VOLUME];
		int number_of_light_volumes;

		unsigned char visibility[Q3BSP_MAX_VISIBILITY];
		int number_of_visibility_vectors;
		int number_of_visibility_vector_size;
	};

	bool LoadFromMemory(const void *file_data, int file_size, file_content_t *result);
}

#endif


#ifdef Q3BSP_IMPLEMENTATION

namespace q3bsp
{
	inline void Copy(void *dst, void *src, u64 size)
    {
        u8 *s = (u8 *)src;
        u8 *d = (u8 *)dst;
        while (size--) { *d++ = *s++; }
    }

    inline void CopyLump(const void *file_data, const header_t *header, directory_e directory, int entry_size, void* dst, int *count)
    {
    	const lump_t &lump = header->lumps[directory];
    	*count = lump.length / entry_size;
    	Copy(dst, file_data + lump.offset, lump.length);
    }

	int LoadFromMemory(const void *file_data, int file_size, file_content_t *result)
	{
		if (!file_data || size <= sizeof(header_t) || !result) return Q3BSP_INVALID_DATA;

		result->entity_string_lengt = 0;
		result->number_of_shaders = 0;
		result->number_of_planes = 0;
		result->number_of_nodes = 0;
		result->number_of_leafs = 0;
		result->number_of_leaf_surfaces = 0;
		result->number_of_leaf_brushes = 0;
		result->number_of_models = 0;
		result->number_of_brushes = 0;
		result->number_of_brush_sides = 0;
		result->number_of_vertices = 0;
		result->number_of_indexes = 0;
		result->number_of_fogs = 0;
		result->number_of_surfaces = 0;
		result->number_of_lightmaps = 0;
		result->number_of_light_volume = 0;
		result->number_of_visibility_vectors = 0;
		result->number_of_visibility_vector_size = 0;

		int visibility_count = 0;
		header_t header;
		Copy(&header, file_data, sizeof(header_t));

		if (header.id != Q3BSP_FILEID) return Q3BSP_INVALID_FILEID;
		if (header.version != Q3BSP_VERSION) return Q3BSP_INVALID_VERSION;

		for (int i = 0; i < MaxDirectory; ++i)
		{
			if (header.lumps[i].offset + header.lumps[i].length > file_size) return Q3BSP_FILE_CORRUPTED;
		}

		CopyLump(file_data, &header, Dir_EntityString, sizeof(char), &result->entity_string, &result->entity_string_lengt);
		CopyLump(file_data, &header, Dir_Shaders, sizeof(shader_t), &result->entity_string, &result->entity_string_lengt);
		CopyLump(file_data, &header, Dir_Planes, sizeof(plane_t), &result->planes, &result->number_of_planes);
		CopyLump(file_data, &header, Dir_Nodes, sizeof(node_t), &result->nodes, &result->number_of_nodes);
		CopyLump(file_data, &header, Dir_Leafs, sizeof(leaf_t), &result->leafs, &result->number_of_leafs);
		CopyLump(file_data, &header, Dir_LeafSurfaces, sizeof(int), &result->leaf_surfaces, &result->number_of_leaf_surfaces);
		CopyLump(file_data, &header, Dir_LeafBrushes, sizeof(int), &result->leaf_brushes, &result->number_of_leaf_brushes);
		CopyLump(file_data, &header, Dir_Models, sizeof(model_t), &result->models, &result->number_of_models);
		CopyLump(file_data, &header, Dir_Brushes, sizeof(brush_t), &result->brushes, &result->number_of_brushes);
		CopyLump(file_data, &header, Dir_BrushSides, sizeof(brush_side_t), &result->brush_sides, &result->number_of_brush_sides);
		CopyLump(file_data, &header, Dir_DrawVertices, sizeof(vertex_t), &result->vertices, &result->number_of_vertices);
		CopyLump(file_data, &header, Dir_DrawIndexes, sizeof(int), &result->indexes, &result->number_of_indexes);
		CopyLump(file_data, &header, Dir_Fogs, sizeof(fog_t), &result->fogs, &result->number_of_fogs);
		CopyLump(file_data, &header, Dir_Surfaces, sizeof(surface_t), &result->surfaces, &result->number_of_surfaces);
		CopyLump(file_data, &header, Dir_Lightmaps, sizeof(lightmap_t), &result->lightmaps, &result->number_of_lightmaps);
		CopyLump(file_data, &header, Dir_LightVolumes, sizeof(light_volume_t), &result->light_volumes, &result->number_of_light_volumes);
		CopyLump(file_data, &header, Dir_Visibility, sizeof(unsigned char),&result->visibility, &visibility_count);

		// TODO
		
		// result->number_of_visibility_vectors = 0;
		// result->number_of_visibility_vector_size = 0;

		// int n_vecs	Number of vectors.
		// int sz_vecs	Size of each vector, in bytes.
		// ubyte[n_vecs * sz_vecs] vecs	Visibility data. One bit per cluster per vector.
		// Cluster x is visible from cluster y if the (1 << y % 8) bit of vecs[x * sz_vecs + y / 8] is set


		// Lightvols make up a 3D grid whose dimensions are:
		//  nx = floor(models[0].maxs[0] / 64) - ceil(models[0].mins[0] / 64) + 1
		//  ny = floor(models[0].maxs[1] / 64) - ceil(models[0].mins[1] / 64) + 1
		//  nz = floor(models[0].maxs[2] / 128) - ceil(models[0].mins[2] / 128) + 1
		//lightVolumeSize.x = static_cast<int>(ltb::Math<float>::floor(static_cast<float>(models[0].bounds.maxs.x) / Q3BSP_WORLD_SCALE) - ltb::Math<float>::ceil(static_cast<float>(models[0].bounds.mins.x) / Q3BSP_WORLD_SCALE)) + 1;
		//lightVolumeSize.y = static_cast<int>(ltb::Math<float>::floor(static_cast<float>(models[0].bounds.maxs.y) / Q3BSP_WORLD_SCALE) - ltb::Math<float>::ceil(static_cast<float>(models[0].bounds.mins.y) / Q3BSP_WORLD_SCALE)) + 1;
		//lightVolumeSize.z = static_cast<int>(ltb::Math<float>::floor(static_cast<float>(models[0].bounds.maxs.z) / (2.0f * Q3BSP_WORLD_SCALE)) - ltb::Math<float>::ceil(static_cast<float>(models[0].bounds.mins.z) / (2.0f * Q3BSP_WORLD_SCALE))) + 1;

		//for (auto &face : faces) {
		//	if (face.type == Q3BSP_FACE_POLYGON && face.numMeshVertices > 0) {
		//		face.type = Q3BSP_FACE_MESH;
		//	}
		//}

		//void Quake3BSP::loadVisibilityData(const std::shared_ptr<File> &file) {
		//	if (header.lumps[Q3BSP_VISDATA].length > 0) {
		//		file->seek(header.lumps[Q3BSP_VISDATA].offset);
		//		if (file->read(&visibilityData.numVectors) && file->read(&visibilityData.vectorSize) && visibilityData.numVectors * visibilityData.vectorSize > 0) {
		//			file->readArray(&visibilityData.vectors, visibilityData.numVectors * visibilityData.vectorSize);
		//		}
		//	}
		//}

		return Q3BSP_SUCCESS;
	}
}

#endif
