#pragma once

#include "libmorton/morton.h"

struct UESVON_API SVONLeafNode
{
	uint_fast64_t myVoxelGrid = 0;


	inline bool GetNode(uint_fast32_t aX, uint_fast32_t aY, uint_fast32_t aZ)
	{
		uint_fast64_t index = 0;
		morton3D_64_decode(index, aX, aY, aZ);
		return (myVoxelGrid & (1ULL << index)) != 0;
	}

	inline void SetNodeAt(uint_fast32_t aX, uint_fast32_t aY, uint_fast32_t aZ)
	{
		uint_fast64_t index = 0;
		morton3D_64_decode(index, aX, aY, aZ);
		myVoxelGrid |= 1ULL << index;
	}
};