
#ifndef __Q2BSP_H
#define __Q2BSP_H

// https://www.flipcode.com/archives/Quake_2_BSP_File_Format.shtml
// https://github.com/id-Software/Quake-2/blob/master/qcommon/qfiles.h

#define Q2BSP_FILEID (('P'<<24)+('S'<<16)+('B'<<8)+'I') // little-endian "IBSP"
#define Q2BSP_VERSION 38

#define Q2BSP_MAX_LIGHTMAPS_PER_FACE 4

namespace q2bsp
{
	enum directory_e
	{
		Dir_EntityString = 0,
		Dir_Planes = 1,
		Dir_DrawVertices = 2,
		Dir_Visibility = 3,
		Dir_Nodes = 4,
		Dir_Shaders = 5,
		Dir_Surfaces = 6,
		Dir_Lightmaps = 7,
		Dir_Leafs = 8,
		Dir_LeafSurfaces = 9,
		Dir_LeafBrushes = 10,
		Dir_Edges = 11,
		Dir_SurfaceEdges = 12,
		Dir_Models = 13,
		Dir_Brushes = 14,
		Dir_BrushSides = 15,
		Dir_Pop = 16,
		Dir_Areas = 17,
		Dir_AreaPortals = 18,
		
		MaxDirectory = 19
	};

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

	struct surface_t
	{
		unsigned short plane;
		short plane_side;

		int first_edge;
		short number_of_edges;

		short shader;

		char lightmap_styles[Q2BSP_MAX_LIGHTMAPS_PER_FACE];
		int lightmap_offset;
	};

	struct plane_t
	{
		float normal[3];
		float distance;
		int type;
	};

	struct node_t
	{
		/*
		uint32   plane;             // index of the splitting plane (in the plane array)
    
	    int32    front_child;       // index of the front child node or leaf
	    int32    back_child;        // index of the back child node or leaf
	   
	    point3s  bbox_min;          // minimum x, y and z of the bounding box
	    point3s  bbox_max;          // maximum x, y and z of the bounding box
		
	    uint16   first_face;        // index of the first face (in the face array)
	    uint16   num_faces;         // number of consecutive edges (in the face array)
		*/
	};

	struct lump_t
	{
		/*
		uint32   brush_or;          // ?
	
	    uint16   cluster;           // -1 for cluster indicates no visibility information
	    uint16   area;              // ?

	    point3s  bbox_min;          // bounding box minimums
	    point3s  bbox_max;          // bounding box maximums

	    uint16   first_leaf_face;   // index of the first face (in the face leaf array)
	    uint16   num_leaf_faces;    // number of consecutive edges (in the face leaf array)

	    uint16   first_leaf_brush;  // ?
	    uint16   num_leaf_brushes;  // ?
		*/
	};

	struct shader_t
	{
		/*
		point3f  u_axis;
	    float    u_offset;
	   
	    point3f  v_axis;
	    float    v_offset;

	    uint32   flags;
	    uint32   value;

	    char     texture_name[32];

	    uint32   next_texinfo;
		*/

		/*
		 Texture coords:
		  u = x * u_axis.x + y * u_axis.y + z * u_axis.z + u_offset
		  v = x * v_axis.x + y * v_axis.y + z * v_axis.z + v_offset
		*/
	};
}

#endif

#ifdef Q2BSP_IMPLEMENTATION

namespace q2bsp
{
	
}

#endif
