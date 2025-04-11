
/*
 * MIT No Attribution
 * Full text: https://opensource.org/licenses/MIT-0
 *
 * Copyright 2025 Antônio Ivo da Silva Gomes
 */

#ifndef INCLUDE_SMOL_AABB_HEADER
#define INCLUDE_SMOL_AABB_HEADER

typedef struct smol_aabb_rect {
  float x;
  float y;
  float w; // width
  float h; // height
} smol_aabb_rect;

int smol_aabb_intersects(smol_aabb_rect a, smol_aabb_rect b);

#ifdef SMOL_AABB_IMPLEMENTATION

int smol_aabb_intersects(smol_aabb_rect a, smol_aabb_rect b) {
  int vertical = a.x + a.w <= b.x || b.x + b.w <= a.x;
  int horizontal = a.y + a.h <= b.y || b.y + b.w <= a.y;
  return !(vertical || horizontal);
}

#endif /* SMOL_AABB_IMPLEMENTATION */

#endif /* INCLUDE_SMOL_AABB_HEADER */
