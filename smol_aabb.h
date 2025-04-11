
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

smol_aabb_rect smol_aabb_intersection(smol_aabb_rect a, smol_aabb_rect b);

#ifdef SMOL_AABB_IMPLEMENTATION

int smol_aabb_intersects(smol_aabb_rect a, smol_aabb_rect b) {
  int vertical = a.x + a.w <= b.x || b.x + b.w <= a.x;
  int horizontal = a.y + a.h <= b.y || b.y + b.h <= a.y;
  return !(vertical || horizontal);
}

smol_aabb_rect smol_aabb_intersection(smol_aabb_rect a, smol_aabb_rect b) {
  smol_aabb_rect c;

  float min_x = (a.x > b.x) ? a.x : b.x;
  float min_y = (a.y > b.y) ? a.y : b.y;
  float max_x = ((a.x + a.w) < (b.x + b.w)) ? (a.x + a.w) : (b.x + b.w);
  float max_y = ((a.y + a.h) < (b.y + b.h)) ? (a.y + a.h) : (b.y + b.h);

  if (max_x <= min_x || max_y <= min_y) {
    c.x = 0;
    c.y = 0;
    c.w = 0;
    c.h = 0;
  } else {
    c.x = min_x;
    c.y = min_y;
    c.w = max_x - min_x;
    c.h = max_y - min_y;
  }

  return c;
}

#endif /* SMOL_AABB_IMPLEMENTATION */

#endif /* INCLUDE_SMOL_AABB_HEADER */
