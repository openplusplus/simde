#define SIMDE__EMULATE_NATIVE

#if defined(TEST_NATIVE)
#  define SIMDE__MMX_NATIVE
#  define SIMDE__SSE_NATIVE
#  define SIMDE__SSE2_NATIVE

#  if defined(__GNUC__)
#    pragma GCC target("sse4.1")
#  endif
#endif

#include <stdio.h>
#include <limits.h>

#include "sse2.h"
#include "munit/munit.h"

/*** MMX ***/

/* void print_pi16(const char* prefix, __m64 v) { */
/*   short* vp = (short*) &v; */
/*   printf("%s: 0x%04hx 0x%04hx 0x%04hx 0x%04hx\n", prefix, vp[0], vp[1], vp[2], vp[3]); */
/* } */

/* void print_si64(const char* prefix, __m64 v) { */
/*   printf("%s: 0x%016lx\n", prefix, *((int64_t*) &v)); */
/* } */

static MunitResult
test_simd_mm_set_pi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  char d[8 / sizeof(char)];
  munit_rand_memory(sizeof(d), (uint8_t*) d);

  __m64 x = _mm_set_pi8(d[0], d[1], d[2], d[3], d[4], d[5], d[6], d[7]);
  char* c = (char*) &x;

  munit_assert_int8(c[0], ==, d[7]);
  munit_assert_int8(c[1], ==, d[6]);
  munit_assert_int8(c[2], ==, d[5]);
  munit_assert_int8(c[3], ==, d[4]);
  munit_assert_int8(c[4], ==, d[3]);
  munit_assert_int8(c[5], ==, d[2]);
  munit_assert_int8(c[6], ==, d[1]);
  munit_assert_int8(c[7], ==, d[0]);

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_set_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  short d[8 / sizeof(short)];
  munit_rand_memory(sizeof(d), (uint8_t*) d);

  __m64 x = _mm_set_pi16(d[0], d[1], d[2], d[3]);
  short* s = (short*) &x;

  munit_assert_short(s[0], ==, d[3]);
  munit_assert_short(s[1], ==, d[2]);
  munit_assert_short(s[2], ==, d[1]);
  munit_assert_short(s[3], ==, d[0]);

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_set_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  int d[8 / sizeof(int)];
  munit_rand_memory(sizeof(d), (uint8_t*) d);

  __m64 x = _mm_set_pi32(d[0], d[1]);
  int* i = (int*) &x;

  munit_assert_int(i[0], ==, d[1]);
  munit_assert_int(i[1], ==, d[0]);

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_set1_pi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  char v = (char) munit_rand_int_range(CHAR_MIN, CHAR_MAX);

  __m64 x = _mm_set1_pi8(v);
  char* r = (char*) &x;

  munit_assert_int8(r[0], ==, v);
  munit_assert_int8(r[1], ==, v);
  munit_assert_int8(r[2], ==, v);
  munit_assert_int8(r[3], ==, v);
  munit_assert_int8(r[4], ==, v);
  munit_assert_int8(r[5], ==, v);
  munit_assert_int8(r[6], ==, v);
  munit_assert_int8(r[7], ==, v);

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_set1_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  short v = (short) munit_rand_int_range(SHRT_MIN, SHRT_MAX);

  __m64 x = _mm_set1_pi16(v);
  short* r = (short*) &x;

  munit_assert_int8(r[0], ==, v);
  munit_assert_int8(r[1], ==, v);
  munit_assert_int8(r[2], ==, v);
  munit_assert_int8(r[3], ==, v);

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_set1_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  int v = (int) munit_rand_int_range(INT_MIN, INT_MAX);

  __m64 x = _mm_set1_pi32(v);
  int* r = (int*) &x;

  munit_assert_int8(r[0], ==, v);
  munit_assert_int8(r[1], ==, v);

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_setr_pi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  char d[8 / sizeof(char)];
  munit_rand_memory(sizeof(d), (uint8_t*) d);

  __m64 x = _mm_setr_pi8(d[0], d[1], d[2], d[3], d[4], d[5], d[6], d[7]);
  char* c = (char*) &x;

  munit_assert_int8(c[0], ==, d[0]);
  munit_assert_int8(c[1], ==, d[1]);
  munit_assert_int8(c[2], ==, d[2]);
  munit_assert_int8(c[3], ==, d[3]);
  munit_assert_int8(c[4], ==, d[4]);
  munit_assert_int8(c[5], ==, d[5]);
  munit_assert_int8(c[6], ==, d[6]);
  munit_assert_int8(c[7], ==, d[7]);

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_setr_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  short d[8 / sizeof(short)];
  munit_rand_memory(sizeof(d), (uint8_t*) d);

  __m64 x = _mm_setr_pi16(d[0], d[1], d[2], d[3]);
  short* s = (short*) &x;

  munit_assert_short(s[0], ==, d[0]);
  munit_assert_short(s[1], ==, d[1]);
  munit_assert_short(s[2], ==, d[2]);
  munit_assert_short(s[3], ==, d[3]);

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_setr_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  int d[8 / sizeof(int)];
  munit_rand_memory(sizeof(d), (uint8_t*) d);

  __m64 x = _mm_setr_pi32(d[0], d[1]);
  int* i = (int*) &x;

  munit_assert_int(i[0], ==, d[0]);
  munit_assert_int(i[1], ==, d[1]);

  return MUNIT_OK;
}

#define assert_m64_pi8(a, cmp, b)					\
  do {									\
    munit_assert_int8(((char*) (&a))[0], cmp, ((char*) (&b))[0]);	\
    munit_assert_int8(((char*) (&a))[1], cmp, ((char*) (&b))[1]);	\
    munit_assert_int8(((char*) (&a))[2], cmp, ((char*) (&b))[2]);	\
    munit_assert_int8(((char*) (&a))[3], cmp, ((char*) (&b))[3]);	\
    munit_assert_int8(((char*) (&a))[4], cmp, ((char*) (&b))[4]);	\
    munit_assert_int8(((char*) (&a))[5], cmp, ((char*) (&b))[5]);	\
    munit_assert_int8(((char*) (&a))[6], cmp, ((char*) (&b))[6]);	\
    munit_assert_int8(((char*) (&a))[7], cmp, ((char*) (&b))[7]);	\
  } while (0)

#define assert_m64_pi16(a, cmp, b)					\
  do {									\
    munit_assert_short(((short*) (&a))[0], cmp, ((short*) (&b))[0]);	\
    munit_assert_short(((short*) (&a))[1], cmp, ((short*) (&b))[1]);	\
    munit_assert_short(((short*) (&a))[2], cmp, ((short*) (&b))[2]);	\
    munit_assert_short(((short*) (&a))[3], cmp, ((short*) (&b))[3]);	\
  } while (0)

#define assert_m64_pi32(a, cmp, b)				\
  do {								\
    munit_assert_int(((int*) (&a))[0], cmp, ((int*) (&b))[0]);	\
    munit_assert_int(((int*) (&a))[1], cmp, ((int*) (&b))[1]);	\
  } while (0)

#define assert_m64_si64(a, cmp, b)				\
  do {								\
    munit_assert_int64(((long long int*) (&a))[0], cmp, ((long long int*) (&b))[0]);	\
  } while (0)

#define assert_m64_pu16(a, cmp, b)					\
  do {									\
    munit_assert_ushort(((unsigned short*) (&a))[0], cmp, ((unsigned short*) (&b))[0]);	\
    munit_assert_ushort(((unsigned short*) (&a))[1], cmp, ((unsigned short*) (&b))[1]);	\
    munit_assert_ushort(((unsigned short*) (&a))[2], cmp, ((unsigned short*) (&b))[2]);	\
    munit_assert_ushort(((unsigned short*) (&a))[3], cmp, ((unsigned short*) (&b))[3]);	\
  } while (0)

#define assert_m64_pu8(a, cmp, b)					\
  do {									\
    munit_assert_uint8(((unsigned char*) (&a))[0], cmp, ((unsigned char*) (&b))[0]);	\
    munit_assert_uint8(((unsigned char*) (&a))[1], cmp, ((unsigned char*) (&b))[1]);	\
    munit_assert_uint8(((unsigned char*) (&a))[2], cmp, ((unsigned char*) (&b))[2]);	\
    munit_assert_uint8(((unsigned char*) (&a))[3], cmp, ((unsigned char*) (&b))[3]);	\
    munit_assert_uint8(((unsigned char*) (&a))[4], cmp, ((unsigned char*) (&b))[4]);	\
    munit_assert_uint8(((unsigned char*) (&a))[5], cmp, ((unsigned char*) (&b))[5]);	\
    munit_assert_uint8(((unsigned char*) (&a))[6], cmp, ((unsigned char*) (&b))[6]);	\
    munit_assert_uint8(((unsigned char*) (&a))[7], cmp, ((unsigned char*) (&b))[7]);	\
  } while (0)

static MunitResult
test_simd_mm_add_pi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    __m64 b;
    __m64 r;
  } test_vec[8] = {
    { _mm_set_pi8(0x19, 0x96, 0x5d, 0x56, 0xc8, 0x65, 0x4f, 0x53),
      _mm_set_pi8(0xda, 0xfa, 0x2f, 0x3b, 0xbd, 0xdc, 0x7f, 0x68),
      _mm_set_pi8(0xf3, 0x90, 0x8c, 0x91, 0x85, 0x41, 0xce, 0xbb) },
    { _mm_set_pi8(0x97, 0x71, 0x16, 0xa5, 0x3b, 0xfc, 0x43, 0x2b),
      _mm_set_pi8(0xf3, 0x5d, 0x51, 0x6c, 0x98, 0x7b, 0x69, 0x77),
      _mm_set_pi8(0x8a, 0xce, 0x67, 0x11, 0xd3, 0x77, 0xac, 0xa2) },
    { _mm_set_pi8(0xf8, 0x34, 0x5c, 0x79, 0x3a, 0x98, 0x1b, 0xb0),
      _mm_set_pi8(0x3e, 0x9c, 0x05, 0xa1, 0xf0, 0x6d, 0x7f, 0x3e),
      _mm_set_pi8(0x36, 0xd0, 0x61, 0x1a, 0x2a, 0x05, 0x9a, 0xee) },
    { _mm_set_pi8(0x20, 0x7c, 0x73, 0x03, 0x68, 0x1b, 0x2b, 0xf5),
      _mm_set_pi8(0xea, 0x1b, 0xd1, 0x2d, 0xa0, 0xcf, 0xb6, 0xde),
      _mm_set_pi8(0x0a, 0x97, 0x44, 0x30, 0x08, 0xea, 0xe1, 0xd3) },
    { _mm_set_pi8(0xf2, 0xb1, 0xda, 0xa3, 0xc9, 0x53, 0x4e, 0xa6),
      _mm_set_pi8(0x5b, 0xc3, 0x84, 0xc0, 0x4c, 0xf1, 0x8b, 0x0b),
      _mm_set_pi8(0x4d, 0x74, 0x5e, 0x63, 0x15, 0x44, 0xd9, 0xb1) },
    { _mm_set_pi8(0x89, 0x21, 0xc7, 0x36, 0xee, 0x4f, 0x56, 0xe7),
      _mm_set_pi8(0x8d, 0x8e, 0x48, 0x82, 0xb0, 0x72, 0x82, 0x2a),
      _mm_set_pi8(0x16, 0xaf, 0x0f, 0xb8, 0x9e, 0xc1, 0xd8, 0x11) },
    { _mm_set_pi8(0x3c, 0x6d, 0x5d, 0xd3, 0xc2, 0x98, 0xd7, 0x48),
      _mm_set_pi8(0x48, 0xaa, 0x15, 0x4f, 0x2b, 0x17, 0xb6, 0xc2),
      _mm_set_pi8(0x84, 0x17, 0x72, 0x22, 0xed, 0xaf, 0x8d, 0x0a) },
    { _mm_set_pi8(0x6e, 0x6a, 0xa2, 0x66, 0xae, 0x6c, 0xf4, 0xd0),
      _mm_set_pi8(0x6c, 0x03, 0xa5, 0x41, 0x1e, 0x6a, 0xff, 0x64),
      _mm_set_pi8(0xda, 0x6d, 0x47, 0xa7, 0xcc, 0xd6, 0xf3, 0x34) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_add_pi8(test_vec[i].a, test_vec[i].b);
    assert_m64_pi8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_add_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    __m64 b;
    __m64 r;
  } test_vec[8] = {
    { _mm_set_pi16(0xcc36, 0xddb8, 0x7e6d, 0xf0d1),
      _mm_set_pi16(0x4e32, 0x5b79, 0xfcfa, 0x16b2),
      _mm_set_pi16(0x1a68, 0x3931, 0x7b67, 0x0783) },
    { _mm_set_pi16(0x2c47, 0x7424, 0x65cb, 0xc564),
      _mm_set_pi16(0xca34, 0xae46, 0x07c9, 0x8945),
      _mm_set_pi16(0xf67b, 0x226a, 0x6d94, 0x4ea9) },
    { _mm_set_pi16(0x009f, 0x5c4c, 0xbcb8, 0xa508),
      _mm_set_pi16(0xb881, 0x1e13, 0x574f, 0xc092),
      _mm_set_pi16(0xb920, 0x7a5f, 0x1407, 0x659a) },
    { _mm_set_pi16(0x2389, 0xe8a2, 0x6e1f, 0x803d),
      _mm_set_pi16(0xbde8, 0xb989, 0x81fd, 0x28a5),
      _mm_set_pi16(0xe171, 0xa22b, 0xf01c, 0xa8e2) },
    { _mm_set_pi16(0x0831, 0x5f83, 0x63bd, 0xc883),
      _mm_set_pi16(0x9193, 0x1184, 0xa931, 0x4619),
      _mm_set_pi16(0x99c4, 0x7107, 0x0cee, 0x0e9c) },
    { _mm_set_pi16(0xbb0a, 0x30a3, 0x3025, 0x144e),
      _mm_set_pi16(0x9822, 0x7c91, 0xc6c0, 0x18ea),
      _mm_set_pi16(0x532c, 0xad34, 0xf6e5, 0x2d38) },
    { _mm_set_pi16(0x7b0a, 0xb6da, 0xda08, 0xbd6e),
      _mm_set_pi16(0x4281, 0x3382, 0x9abd, 0x3aa9),
      _mm_set_pi16(0xbd8b, 0xea5c, 0x74c5, 0xf817) },
    { _mm_set_pi16(0x26b0, 0x9263, 0x8285, 0xfafb),
      _mm_set_pi16(0xe3ea, 0xf882, 0x681e, 0x8527),
      _mm_set_pi16(0x0a9a, 0x8ae5, 0xeaa3, 0x8022) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_add_pi16(test_vec[i].a, test_vec[i].b);
    assert_m64_pi16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_add_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    __m64 b;
    __m64 r;
  } test_vec[8] = {
    { _mm_set_pi32(0xa4e05d2d, 0x93297f7c),
      _mm_set_pi32(0xb6b4ca2f, 0x3b0097a1),
      _mm_set_pi32(0x5b95275c, 0xce2a171d) },
    { _mm_set_pi32(0x73715e7c, 0x4f55c863),
      _mm_set_pi32(0xe1da937c, 0x57b2d16a),
      _mm_set_pi32(0x554bf1f8, 0xa70899cd) },
    { _mm_set_pi32(0x2eb84efc, 0x72a06142),
      _mm_set_pi32(0x65566652, 0xf58a7afd),
      _mm_set_pi32(0x940eb54e, 0x682adc3f) },
    { _mm_set_pi32(0x4749244b, 0x4f39928a),
      _mm_set_pi32(0xdb8caca1, 0x2eed6088),
      _mm_set_pi32(0x22d5d0ec, 0x7e26f312) },
    { _mm_set_pi32(0x38a16c13, 0x22075321),
      _mm_set_pi32(0x65255049, 0x96ef5dc0),
      _mm_set_pi32(0x9dc6bc5c, 0xb8f6b0e1) },
    { _mm_set_pi32(0x026fa3d0, 0x08e4259d),
      _mm_set_pi32(0x6159d6bf, 0xf2a5a065),
      _mm_set_pi32(0x63c97a8f, 0xfb89c602) },
    { _mm_set_pi32(0xd525e259, 0x569edf13),
      _mm_set_pi32(0x0360eaae, 0xdc8cf548),
      _mm_set_pi32(0xd886cd07, 0x332bd45b) },
    { _mm_set_pi32(0xc759ded1, 0xffe934bc),
      _mm_set_pi32(0x9bd96cf5, 0x13223ea9),
      _mm_set_pi32(0x63334bc6, 0x130b7365) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_add_pi32(test_vec[i].a, test_vec[i].b);
    assert_m64_pi32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_adds_pi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    __m64 b;
    __m64 r;
  } test_vec[8] = {
    { _mm_set_pi8(  99,   16,  -73,  -73,   34,   32,   87,   42),
      _mm_set_pi8( -29,  -82,  -26,  -38,   66,  -51,   82,   53),
      _mm_set_pi8(  70,  -66,  -99, -111,  100,  -19,  127,   95) },
    { _mm_set_pi8( -63, -116,  -41,  -11,  -99,  -60,  -36,  -15),
      _mm_set_pi8(  84, -113,  107,   81,  -28,  -25,  -90, -115),
      _mm_set_pi8(  21, -128,   66,   70, -127,  -85, -126, -128) },
    { _mm_set_pi8( -79, -104,  -10,  -65,   84,  -40, -102,   75),
      _mm_set_pi8(  30,   54,  127,   16,   -7,  -31,  -83,  -89),
      _mm_set_pi8( -49,  -50,  117,  -49,   77,  -71, -128,  -14) },
    { _mm_set_pi8(-115,  -50,  111,  104,  -19,  -48,  122,   59),
      _mm_set_pi8( -74,  -15,   43,    9,   94,  -81,  -68,   15),
      _mm_set_pi8(-128,  -65,  127,  113,   75, -128,   54,   74) },
    { _mm_set_pi8(  18,  -79,    5,   80,   99,  108,   39,  -27),
      _mm_set_pi8( 127,   44,   22,  -80,  -86,  -11,  108,  -95),
      _mm_set_pi8( 127,  -35,   27,    0,   13,   97,  127, -122) },
    { _mm_set_pi8( -35,   62,  102,  -79,  117,  108,   56,  -21),
      _mm_set_pi8(  68,  119,  -10,   17,   40, -124,  -75,  -39),
      _mm_set_pi8(  33,  127,   92,  -62,  127,  -16,  -19,  -60) },
    { _mm_set_pi8(  45,   -5,  -10,   -4,  -23,  -76, -111,  -38),
      _mm_set_pi8(  24,  -15,   -2,   75,   11, -108,   -5,  124),
      _mm_set_pi8(  69,  -20,  -12,   71,  -12, -128, -116,   86) },
    { _mm_set_pi8( 116,   38,   87,    5,  -25, -119,  117,  -12),
      _mm_set_pi8( -51,   25, -122,   40, -111,  -50,  -55, -109),
      _mm_set_pi8(  65,   63,  -35,   45, -128, -128,   62, -121) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_adds_pi8(test_vec[i].a, test_vec[i].b);
    assert_m64_pi8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_adds_pu8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    __m64 b;
    __m64 r;
  } test_vec[8] = {
    { _mm_set_pi8(0x3c, 0x96, 0x00, 0x26, 0x5f, 0x5e, 0xd9, 0xd0),
      _mm_set_pi8(0xfb, 0x3d, 0x8c, 0x9e, 0xbf, 0x76, 0x0f, 0xa5),
      _mm_set_pi8(0xff, 0xd3, 0x8c, 0xc4, 0xff, 0xd4, 0xe8, 0xff) },
    { _mm_set_pi8(0xe7, 0x1d, 0xd1, 0xe2, 0xaf, 0x23, 0xd8, 0x31),
      _mm_set_pi8(0xf4, 0xed, 0xad, 0xea, 0xd2, 0x50, 0x65, 0xf0),
      _mm_set_pi8(0xff, 0xff, 0xff, 0xff, 0xff, 0x73, 0xff, 0xff) },
    { _mm_set_pi8(0xf9, 0x8d, 0x68, 0x80, 0x09, 0xc3, 0x99, 0x86),
      _mm_set_pi8(0xca, 0x8f, 0xb8, 0xbf, 0x7a, 0xfb, 0xa0, 0xa1),
      _mm_set_pi8(0xff, 0xff, 0xff, 0xff, 0x83, 0xff, 0xff, 0xff) },
    { _mm_set_pi8(0x1f, 0xb9, 0x3f, 0x16, 0x02, 0x23, 0x72, 0xda),
      _mm_set_pi8(0xd6, 0xc2, 0xa7, 0xbe, 0x8c, 0xf8, 0x7f, 0x88),
      _mm_set_pi8(0xf5, 0xff, 0xe6, 0xd4, 0x8e, 0xff, 0xf1, 0xff) },
    { _mm_set_pi8(0x92, 0x59, 0xd9, 0x40, 0x81, 0xf7, 0xb4, 0x14),
      _mm_set_pi8(0x7c, 0x9d, 0x89, 0xc9, 0x10, 0x95, 0x35, 0x2d),
      _mm_set_pi8(0xff, 0xf6, 0xff, 0xff, 0x91, 0xff, 0xe9, 0x41) },
    { _mm_set_pi8(0xfa, 0x5d, 0x04, 0x54, 0xc4, 0x92, 0x20, 0xfd),
      _mm_set_pi8(0x05, 0x53, 0x92, 0x2f, 0x7e, 0x5d, 0xdf, 0x33),
      _mm_set_pi8(0xff, 0xb0, 0x96, 0x83, 0xff, 0xef, 0xff, 0xff) },
    { _mm_set_pi8(0x65, 0x67, 0x88, 0x23, 0x38, 0x51, 0xab, 0x96),
      _mm_set_pi8(0x3f, 0xc7, 0xd8, 0xa7, 0x36, 0x23, 0x1a, 0xef),
      _mm_set_pi8(0xa4, 0xff, 0xff, 0xca, 0x6e, 0x74, 0xc5, 0xff) },
    { _mm_set_pi8(0x72, 0x91, 0x2f, 0x87, 0x35, 0x43, 0x17, 0x3d),
      _mm_set_pi8(0x10, 0xd3, 0xfe, 0x73, 0x96, 0x22, 0xed, 0xe9),
      _mm_set_pi8(0x82, 0xff, 0xff, 0xfa, 0xcb, 0x65, 0xff, 0xff) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_adds_pu8(test_vec[i].a, test_vec[i].b);
    assert_m64_pi8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_adds_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    __m64 b;
    __m64 r;
  } test_vec[8] = {
    { _mm_set_pi16(0x85b3, 0xea33, 0xcb36, 0x9f96),
      _mm_set_pi16(0x4db4, 0xd080, 0x0cc2, 0x232a),
      _mm_set_pi16(0xd367, 0xbab3, 0xd7f8, 0xc2c0) },
    { _mm_set_pi16(0x5054, 0x9c2e, 0x485a, 0xff95),
      _mm_set_pi16(0x3028, 0x3253, 0x08cb, 0xb551),
      _mm_set_pi16(0x7fff, 0xce81, 0x5125, 0xb4e6) },
    { _mm_set_pi16(0x4e8a, 0xc367, 0x9c30, 0xa339),
      _mm_set_pi16(0x2c74, 0x125a, 0x41f6, 0x2c28),
      _mm_set_pi16(0x7afe, 0xd5c1, 0xde26, 0xcf61) },
    { _mm_set_pi16(0x87a9, 0xcf38, 0x2f76, 0x0158),
      _mm_set_pi16(0xab19, 0x2ca0, 0x4b8e, 0xa790),
      _mm_set_pi16(0x8000, 0xfbd8, 0x7b04, 0xa8e8) },
    { _mm_set_pi16(0x5a94, 0xae33, 0x696f, 0xd389),
      _mm_set_pi16(0x5066, 0x19e4, 0x7d61, 0x5b65),
      _mm_set_pi16(0x7fff, 0xc817, 0x7fff, 0x2eee) },
    { _mm_set_pi16(0x06fd, 0x6f96, 0x4a33, 0x810c),
      _mm_set_pi16(0x809f, 0x8947, 0x0706, 0x6f45),
      _mm_set_pi16(0x879c, 0xf8dd, 0x5139, 0xf051) },
    { _mm_set_pi16(0x483b, 0xd1fb, 0x949d, 0x0151),
      _mm_set_pi16(0x01a4, 0x7066, 0x8679, 0x3b98),
      _mm_set_pi16(0x49df, 0x4261, 0x8000, 0x3ce9) },
    { _mm_set_pi16(0xc2b9, 0x638f, 0x5a08, 0xdee2),
      _mm_set_pi16(0x2437, 0xed6c, 0xd0c9, 0xc3e9),
      _mm_set_pi16(0xe6f0, 0x50fb, 0x2ad1, 0xa2cb) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_adds_pi16(test_vec[i].a, test_vec[i].b);
    assert_m64_pi16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_adds_pu16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    __m64 b;
    __m64 r;
  } test_vec[8] = {
    { _mm_set_pi16(0x4d12, 0x3df9, 0x335a, 0xeb86),
      _mm_set_pi16(0xef25, 0x3789, 0x6db3, 0x462f),
      _mm_set_pi16(0xffff, 0x7582, 0xa10d, 0xffff) },
    { _mm_set_pi16(0xb40b, 0x746f, 0x5718, 0xbb81),
      _mm_set_pi16(0xa38b, 0x1fb9, 0x08ef, 0x2bc5),
      _mm_set_pi16(0xffff, 0x9428, 0x6007, 0xe746) },
    { _mm_set_pi16(0xb3bf, 0x9d1f, 0x9696, 0x9d99),
      _mm_set_pi16(0x36de, 0x7c18, 0xb6c4, 0x1b9d),
      _mm_set_pi16(0xea9d, 0xffff, 0xffff, 0xb936) },
    { _mm_set_pi16(0x996f, 0x0c13, 0x78c5, 0xadd2),
      _mm_set_pi16(0x735e, 0x3ffa, 0xf5a8, 0xf088),
      _mm_set_pi16(0xffff, 0x4c0d, 0xffff, 0xffff) },
    { _mm_set_pi16(0xa440, 0xc25f, 0x76c2, 0x1f54),
      _mm_set_pi16(0x04f4, 0x2fc9, 0xdd12, 0xf7e7),
      _mm_set_pi16(0xa934, 0xf228, 0xffff, 0xffff) },
    { _mm_set_pi16(0x072d, 0xfb9c, 0xa259, 0xc05c),
      _mm_set_pi16(0xe9c1, 0x0209, 0xccb3, 0x851f),
      _mm_set_pi16(0xf0ee, 0xfda5, 0xffff, 0xffff) },
    { _mm_set_pi16(0xe577, 0x82f6, 0x1fcd, 0xcb4a),
      _mm_set_pi16(0xf8ec, 0x61df, 0xbd83, 0xcccc),
      _mm_set_pi16(0xffff, 0xe4d5, 0xdd50, 0xffff) },
    { _mm_set_pi16(0x8b03, 0xc9b5, 0x2685, 0xeaa2),
      _mm_set_pi16(0xa38a, 0x6e80, 0x15d0, 0x7667),
      _mm_set_pi16(0xffff, 0xffff, 0x3c55, 0xffff) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_adds_pu16(test_vec[i].a, test_vec[i].b);
    assert_m64_pi16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_and_si64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    __m64 b;
    __m64 r;
  } test_vec[8] = {
    { _mm_set_pi32(0x144c257e, 0x33ba1fbe),
      _mm_set_pi32(0x99c6657b, 0x13835d57),
      _mm_set_pi32(0x1044257a, 0x13821d16) },
    { _mm_set_pi32(0x15b94c0e, 0x91869bf9),
      _mm_set_pi32(0x196337a0, 0xdfee49cd),
      _mm_set_pi32(0x11210400, 0x918609c9) },
    { _mm_set_pi32(0x48da74ac, 0x8bbf676f),
      _mm_set_pi32(0x0641aef3, 0x1443debe),
      _mm_set_pi32(0x004024a0, 0x0003462e) },
    { _mm_set_pi32(0x28732761, 0x50acbfb4),
      _mm_set_pi32(0x3eab5e0e, 0xc30b648f),
      _mm_set_pi32(0x28230600, 0x40082484) },
    { _mm_set_pi32(0x6cb04b6a, 0x991ae02b),
      _mm_set_pi32(0x43f0cdd5, 0x3419e02a),
      _mm_set_pi32(0x40b04940, 0x1018e02a) },
    { _mm_set_pi32(0x0b3f944b, 0x36ca8c12),
      _mm_set_pi32(0xe1e07d37, 0x9b9452a5),
      _mm_set_pi32(0x01201403, 0x12800000) },
    { _mm_set_pi32(0xa7641f1a, 0x12570460),
      _mm_set_pi32(0x9513fe43, 0x750d4083),
      _mm_set_pi32(0x85001e02, 0x10050000) },
    { _mm_set_pi32(0xda6f00b9, 0xfb1799bc),
      _mm_set_pi32(0x5fc97d85, 0x33b95b4c),
      _mm_set_pi32(0x5a490081, 0x3311190c) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_and_si64(test_vec[i].a, test_vec[i].b);
    assert_m64_pi32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_andnot_si64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    __m64 b;
    __m64 r;
  } test_vec[8] = {
    { _mm_set_pi32(0x3425e371, 0xd02dfafb),
      _mm_set_pi32(0x13a8010e, 0x1c99a489),
      _mm_set_pi32(0x0388000e, 0x0c900400) },
    { _mm_set_pi32(0xc7af1daf, 0x74738f9e),
      _mm_set_pi32(0xc97744fb, 0xded2bbba),
      _mm_set_pi32(0x08504050, 0x8a803020) },
    { _mm_set_pi32(0xf0e35afb, 0x5813fda1),
      _mm_set_pi32(0xa1b63aec, 0xa03a2993),
      _mm_set_pi32(0x01142004, 0xa0280012) },
    { _mm_set_pi32(0xdd14761c, 0x3134f75f),
      _mm_set_pi32(0x972f6a8e, 0xd9a4754f),
      _mm_set_pi32(0x022b0882, 0xc8800000) },
    { _mm_set_pi32(0xffacf087, 0x296a73ad),
      _mm_set_pi32(0x9fcf4978, 0x0cdd9711),
      _mm_set_pi32(0x00430978, 0x04958410) },
    { _mm_set_pi32(0x554f2958, 0x3c2df6ee),
      _mm_set_pi32(0x9c91ca9a, 0xd44aee0d),
      _mm_set_pi32(0x8890c282, 0xc0420801) },
    { _mm_set_pi32(0x65c0b6ff, 0xa8d8d28e),
      _mm_set_pi32(0xc36aba80, 0x8fd87d5b),
      _mm_set_pi32(0x822a0800, 0x07002d51) },
    { _mm_set_pi32(0x1407f68e, 0x885a1c80),
      _mm_set_pi32(0x8b36f6ec, 0xcf11be13),
      _mm_set_pi32(0x8b300060, 0x4701a213) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_andnot_si64(test_vec[i].a, test_vec[i].b);
    assert_m64_pi32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_cmpeq_pi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    __m64 b;
    __m64 r;
  } test_vec[8] = {
    { _mm_set_pi8(0x3d, 0x8b, 0x8b, 0xe9, 0xed, 0x06, 0xe8, 0x59),
      _mm_set_pi8(0x2f, 0x47, 0x97, 0x0d, 0xe6, 0x5d, 0x76, 0xc6),
      _mm_set_pi8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00) },
    { _mm_set_pi8(0x4e, 0x0b, 0xfe, 0x56, 0xce, 0xcf, 0xff, 0x5c),
      _mm_set_pi8(0xab, 0x9d, 0xd7, 0x74, 0x4a, 0x72, 0xfd, 0x9e),
      _mm_set_pi8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00) },
    { _mm_set_pi8(0x3c, 0x0a, 0xde, 0x1e, 0x30, 0xf3, 0x96, 0x69),
      _mm_set_pi8(0x51, 0x6c, 0xbf, 0xc6, 0xe2, 0xa6, 0x2a, 0x00),
      _mm_set_pi8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00) },
    { _mm_set_pi8(0x8f, 0xbd, 0xc9, 0x54, 0xa4, 0xbe, 0x07, 0x15),
      _mm_set_pi8(0x8f, 0xbd, 0xc9, 0x54, 0xa4, 0xbe, 0x07, 0x15),
      _mm_set_pi8(0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff) },
    { _mm_set_pi8(0xb8, 0xc8, 0x98, 0xfa, 0x25, 0x8e, 0x54, 0x15),
      _mm_set_pi8(0x4d, 0xe7, 0x98, 0x00, 0xd9, 0x26, 0xca, 0xa6),
      _mm_set_pi8(0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00) },
    { _mm_set_pi8(0x2e, 0x78, 0xf3, 0x83, 0x32, 0x0a, 0x78, 0xf6),
      _mm_set_pi8(0x55, 0x59, 0x09, 0x41, 0xae, 0xb0, 0x41, 0xbf),
      _mm_set_pi8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00) },
    { _mm_set_pi8(0xf4, 0xd7, 0xca, 0x5c, 0xa9, 0xae, 0x88, 0x25),
      _mm_set_pi8(0x5e, 0xeb, 0x24, 0x87, 0xc2, 0xfc, 0x2a, 0x89),
      _mm_set_pi8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00) },
    { _mm_set_pi8(0xf8, 0xc4, 0x23, 0xe1, 0x99, 0xf9, 0xd9, 0x2f),
      _mm_set_pi8(0x0d, 0xac, 0x82, 0x81, 0xae, 0x25, 0x3c, 0x1e),
      _mm_set_pi8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_cmpeq_pi8(test_vec[i].a, test_vec[i].b);
    assert_m64_pi8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_cmpeq_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    __m64 b;
    __m64 r;
  } test_vec[8] = {
    { _mm_set_pi16(0xc9b1, 0x919d, 0x2a22, 0x5fc6),
      _mm_set_pi16(0x1493, 0x0784, 0x33e1, 0x9e21),
      _mm_set_pi16(0x0000, 0x0000, 0x0000, 0x0000) },
    { _mm_set_pi16(0xaa43, 0xcb55, 0xfe7a, 0x18e9),
      _mm_set_pi16(0xda91, 0x1adc, 0x5cd8, 0x1841),
      _mm_set_pi16(0x0000, 0x0000, 0x0000, 0x0000) },
    { _mm_set_pi16(0x2c64, 0x6edf, 0x3429, 0x37b5),
      _mm_set_pi16(0x346e, 0x7d21, 0x0fd7, 0x15f7),
      _mm_set_pi16(0x0000, 0x0000, 0x0000, 0x0000) },
    { _mm_set_pi16(0x00ce, 0xf9e1, 0xbcff, 0x46f6),
      _mm_set_pi16(0x7737, 0x77b3, 0x7fdf, 0xef9d),
      _mm_set_pi16(0x0000, 0x0000, 0x0000, 0x0000) },
    { _mm_set_pi16(0x633e, 0xb859, 0xc202, 0xc36f),
      _mm_set_pi16(0x633e, 0xb859, 0xc202, 0xc36f),
      _mm_set_pi16(0xffff, 0xffff, 0xffff, 0xffff) },
    { _mm_set_pi16(0x5391, 0x591f, 0x0142, 0x2588),
      _mm_set_pi16(0x5d91, 0x8448, 0xe286, 0x7cfc),
      _mm_set_pi16(0x0000, 0x0000, 0x0000, 0x0000) },
    { _mm_set_pi16(0xbf86, 0xfc67, 0x8243, 0x480c),
      _mm_set_pi16(0xd79c, 0x9232, 0x5df9, 0xe479),
      _mm_set_pi16(0x0000, 0x0000, 0x0000, 0x0000) },
    { _mm_set_pi16(0xfb6b, 0x9b0c, 0xd617, 0x5669),
      _mm_set_pi16(0x6572, 0x31ae, 0x6350, 0x2e5b),
      _mm_set_pi16(0x0000, 0x0000, 0x0000, 0x0000) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_cmpeq_pi16(test_vec[i].a, test_vec[i].b);
    assert_m64_pi16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_cmpeq_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    __m64 b;
    __m64 r;
  } test_vec[8] = {
    { _mm_set_pi32(0xcb55aa43, 0x18e9fe7a),
      _mm_set_pi32(0x1adcda91, 0x18415cd8),
      _mm_set_pi32(0x00000000, 0x00000000) },
    { _mm_set_pi32(0x6edf2c64, 0x37b53429),
      _mm_set_pi32(0x7d21346e, 0x15f70fd7),
      _mm_set_pi32(0x00000000, 0x00000000) },
    { _mm_set_pi32(0xf9e100ce, 0x46f6bcff),
      _mm_set_pi32(0x77b37737, 0xef9d7fdf),
      _mm_set_pi32(0x00000000, 0x00000000) },
    { _mm_set_pi32(0x07841493, 0x9e2133e1),
      _mm_set_pi32(0x07841493, 0x9e2133e1),
      _mm_set_pi32(0xffffffff, 0xffffffff) },
    { _mm_set_pi32(0xb859633e, 0xc36fc202),
      _mm_set_pi32(0xc2526ad6, 0xc4ce7bc7),
      _mm_set_pi32(0x00000000, 0x00000000) },
    { _mm_set_pi32(0x591f5391, 0x25880142),
      _mm_set_pi32(0x84485d91, 0x7cfce286),
      _mm_set_pi32(0x00000000, 0x00000000) },
    { _mm_set_pi32(0xfc67bf86, 0x480c8243),
      _mm_set_pi32(0x9232d79c, 0xe4795df9),
      _mm_set_pi32(0x00000000, 0x00000000) },
    { _mm_set_pi32(0x9b0cfb6b, 0x5669d617),
      _mm_set_pi32(0x31ae6572, 0x2e5b6350),
      _mm_set_pi32(0x00000000, 0x00000000) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_cmpeq_pi32(test_vec[i].a, test_vec[i].b);
    assert_m64_pi32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_cmpgt_pi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    __m64 b;
    __m64 r;
  } test_vec[8] = {
    { _mm_set_pi8(0xb3, 0x1d, 0xde, 0x92, 0xb2, 0xf8, 0x5c, 0x2c),
      _mm_set_pi8(0xc7, 0x63, 0xf6, 0x1c, 0x2e, 0x4f, 0xb4, 0x3b),
      _mm_set_pi8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00) },
    { _mm_set_pi8(0x60, 0xf7, 0xc3, 0x2e, 0x68, 0x97, 0x59, 0x30),
      _mm_set_pi8(0x6d, 0x46, 0x0d, 0x5a, 0x8c, 0xe9, 0x0a, 0xa0),
      _mm_set_pi8(0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0xff, 0xff) },
    { _mm_set_pi8(0xe8, 0xfe, 0x49, 0x24, 0xe3, 0xba, 0x49, 0x87),
      _mm_set_pi8(0x11, 0xef, 0x4d, 0xfe, 0x6f, 0x91, 0xbe, 0xe2),
      _mm_set_pi8(0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0xff, 0x00) },
    { _mm_set_pi8(0x48, 0x9a, 0x87, 0x29, 0xe3, 0x9c, 0xba, 0x52),
      _mm_set_pi8(0x65, 0x76, 0x92, 0xb6, 0xc7, 0xfe, 0x59, 0xf0),
      _mm_set_pi8(0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff) },
    { _mm_set_pi8(0x40, 0x02, 0x8a, 0x17, 0xa8, 0x88, 0x3d, 0x72),
      _mm_set_pi8(0x3c, 0x5b, 0x60, 0xea, 0x26, 0x31, 0x50, 0xe3),
      _mm_set_pi8(0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff) },
    { _mm_set_pi8(0x1f, 0xe0, 0x87, 0x09, 0x50, 0x6c, 0x1d, 0x02),
      _mm_set_pi8(0x89, 0x21, 0x09, 0x65, 0x65, 0x4f, 0x29, 0x57),
      _mm_set_pi8(0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00) },
    { _mm_set_pi8(0x60, 0xb5, 0x87, 0x9b, 0x0a, 0x82, 0x3a, 0x3c),
      _mm_set_pi8(0x65, 0xb7, 0x7e, 0x69, 0xd0, 0x89, 0x9f, 0xa6),
      _mm_set_pi8(0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0xff, 0xff) },
    { _mm_set_pi8(0x76, 0x76, 0xeb, 0xcf, 0x55, 0x45, 0x54, 0x6f),
      _mm_set_pi8(0xa0, 0x79, 0x92, 0xa9, 0xb7, 0x25, 0x2d, 0x88),
      _mm_set_pi8(0xff, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_cmpgt_pi8(test_vec[i].a, test_vec[i].b);
    assert_m64_pi8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_cmpgt_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    __m64 b;
    __m64 r;
  } test_vec[8] = {
    { _mm_set_pi16(0x6a97, 0xbbdb, 0x1ebc, 0x4543),
      _mm_set_pi16(0x827e, 0xcf9b, 0xc297, 0xd6df),
      _mm_set_pi16(0xffff, 0x0000, 0xffff, 0xffff) },
    { _mm_set_pi16(0xa4dd, 0x4b52, 0x6c3e, 0x1200),
      _mm_set_pi16(0x807a, 0xf6f1, 0x4cfe, 0x6351),
      _mm_set_pi16(0xffff, 0xffff, 0xffff, 0x0000) },
    { _mm_set_pi16(0x72a6, 0xcfbc, 0xb93b, 0x8e02),
      _mm_set_pi16(0x271f, 0xecf1, 0x7815, 0xefd0),
      _mm_set_pi16(0xffff, 0x0000, 0x0000, 0x0000) },
    { _mm_set_pi16(0x77e9, 0xef89, 0x7b44, 0x2e89),
      _mm_set_pi16(0x95d8, 0x4503, 0x8911, 0xf77d),
      _mm_set_pi16(0xffff, 0x0000, 0xffff, 0xffff) },
    { _mm_set_pi16(0x23f7, 0x12b9, 0x9fec, 0x2765),
      _mm_set_pi16(0xb6d9, 0xfc5f, 0x1b8b, 0x2295),
      _mm_set_pi16(0xffff, 0xffff, 0x0000, 0xffff) },
    { _mm_set_pi16(0x58ce, 0x1702, 0xf25e, 0x9e9e),
      _mm_set_pi16(0x5c68, 0x38d4, 0x7c3e, 0xb835),
      _mm_set_pi16(0x0000, 0x0000, 0x0000, 0x0000) },
    { _mm_set_pi16(0x8fac, 0x08a3, 0xc30b, 0x82f6),
      _mm_set_pi16(0xd060, 0xd581, 0x703b, 0x1ee7),
      _mm_set_pi16(0x0000, 0xffff, 0x0000, 0x0000) },
    { _mm_set_pi16(0xda52, 0xdea0, 0xfcb5, 0x2f6c),
      _mm_set_pi16(0x10e4, 0x740a, 0x3563, 0xdc5d),
      _mm_set_pi16(0x0000, 0x0000, 0x0000, 0xffff) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_cmpgt_pi16(test_vec[i].a, test_vec[i].b);
    assert_m64_pi16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_cmpgt_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    __m64 b;
    __m64 r;
  } test_vec[8] = {
    { _mm_set_pi32(0xbbdb6a97, 0x45431ebc),
      _mm_set_pi32(0xcf9b827e, 0xd6dfc297),
      _mm_set_pi32(0x00000000, 0xffffffff) },
    { _mm_set_pi32(0x4b52a4dd, 0x12006c3e),
      _mm_set_pi32(0xf6f1807a, 0x63514cfe),
      _mm_set_pi32(0xffffffff, 0x00000000) },
    { _mm_set_pi32(0xcfbc72a6, 0x8e02b93b),
      _mm_set_pi32(0xecf1271f, 0xefd07815),
      _mm_set_pi32(0x00000000, 0x00000000) },
    { _mm_set_pi32(0xef8977e9, 0x2e897b44),
      _mm_set_pi32(0x450395d8, 0xf77d8911),
      _mm_set_pi32(0x00000000, 0xffffffff) },
    { _mm_set_pi32(0x12b923f7, 0x27659fec),
      _mm_set_pi32(0xfc5fb6d9, 0x22951b8b),
      _mm_set_pi32(0xffffffff, 0xffffffff) },
    { _mm_set_pi32(0x170258ce, 0x9e9ef25e),
      _mm_set_pi32(0x38d45c68, 0xb8357c3e),
      _mm_set_pi32(0x00000000, 0x00000000) },
    { _mm_set_pi32(0x08a38fac, 0x82f6c30b),
      _mm_set_pi32(0xd581d060, 0x1ee7703b),
      _mm_set_pi32(0xffffffff, 0x00000000) },
    { _mm_set_pi32(0xdea0da52, 0x2f6cfcb5),
      _mm_set_pi32(0x740a10e4, 0xdc5d3563),
      _mm_set_pi32(0x00000000, 0xffffffff) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_cmpgt_pi32(test_vec[i].a, test_vec[i].b);
    assert_m64_pi32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_cvtm64_si64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    int64_t r;
  } test_vec[8] = {
    { _mm_set_pi32(0x1909df06, 0xadc023ad), INT64_C(0x1909df06adc023ad) },
    { _mm_set_pi32(0x5d92f02c, 0x3a641e20), INT64_C(0x5d92f02c3a641e20) },
    { _mm_set_pi32(0x62195939, 0xd5d4f1fa), INT64_C(0x62195939d5d4f1fa) },
    { _mm_set_pi32(0x0f025282, 0x69d9aa4a), INT64_C(0x0f02528269d9aa4a) },
    { _mm_set_pi32(0xe33aa06e, 0x07284161), INT64_C(0xe33aa06e07284161) },
    { _mm_set_pi32(0xcfd51386, 0x785a7181), INT64_C(0xcfd51386785a7181) },
    { _mm_set_pi32(0xa1cd4124, 0x447edb08), INT64_C(0xa1cd4124447edb08) },
    { _mm_set_pi32(0x5e193237, 0x299721b7), INT64_C(0x5e193237299721b7) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    munit_assert_int64(_mm_cvtm64_si64(test_vec[i].a), ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_cvtsi32_si64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int a;
    __m64 r;
  } test_vec[8] = {
    { 0xaf9e3edb, _mm_set_pi32(0x00000000, 0xaf9e3edb) },
    { 0xd2e56f4a, _mm_set_pi32(0x00000000, 0xd2e56f4a) },
    { 0xaa880cfd, _mm_set_pi32(0x00000000, 0xaa880cfd) },
    { 0xb17f1bfa, _mm_set_pi32(0x00000000, 0xb17f1bfa) },
    { 0x437a54ab, _mm_set_pi32(0x00000000, 0x437a54ab) },
    { 0x9b8f13e5, _mm_set_pi32(0x00000000, 0x9b8f13e5) },
    { 0xd157be56, _mm_set_pi32(0x00000000, 0xd157be56) },
    { 0xa06adee8, _mm_set_pi32(0x00000000, 0xa06adee8) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_cvtsi32_si64(test_vec[i].a);
    assert_m64_pi32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_cvtsi64_m64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int64_t a;
    __m64 r;
  } test_vec[8] = {
    { INT64_C(0x0a213992287922eb), _mm_set_pi32(0x0a213992, 0x287922eb) },
    { INT64_C(0x6c1adb746c427d55), _mm_set_pi32(0x6c1adb74, 0x6c427d55) },
    { INT64_C(0xebf6a214f17bb34a), _mm_set_pi32(0xebf6a214, 0xf17bb34a) },
    { INT64_C(0xe06cc3268ead51ef), _mm_set_pi32(0xe06cc326, 0x8ead51ef) },
    { INT64_C(0x2ed66dbe21b71687), _mm_set_pi32(0x2ed66dbe, 0x21b71687) },
    { INT64_C(0xcb7f6152a87edf94), _mm_set_pi32(0xcb7f6152, 0xa87edf94) },
    { INT64_C(0xafbf4e510dd4d94b), _mm_set_pi32(0xafbf4e51, 0x0dd4d94b) },
    { INT64_C(0xda8a49210de6b19b), _mm_set_pi32(0xda8a4921, 0x0de6b19b) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_cvtsi64_m64(test_vec[i].a);
    assert_m64_pi32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_cvtsi64_si32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    int r;
  } test_vec[8] = {
    { _mm_set_pi32(0x5263c8d6, 0xfef29fb0), 0xfef29fb0, },
    { _mm_set_pi32(0x7f1adc3c, 0xa7900f8d), 0xa7900f8d, },
    { _mm_set_pi32(0xcefdc926, 0x3bdb4413), 0x3bdb4413, },
    { _mm_set_pi32(0x21516e35, 0x8f86cc25), 0x8f86cc25, },
    { _mm_set_pi32(0x374884bb, 0x688d1d66), 0x688d1d66, },
    { _mm_set_pi32(0xb294efec, 0xbf90c942), 0xbf90c942, },
    { _mm_set_pi32(0x86bcf25e, 0x4bdca3ef), 0x4bdca3ef, },
    { _mm_set_pi32(0xbd93981f, 0x4e9cd8dc), 0x4e9cd8dc, }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = _mm_cvtsi64_si32(test_vec[i].a);
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_madd_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    __m64 b;
    __m64 r;
  } test_vec[8] = {
    { _mm_set_pi16(0x8979, 0x98e8, 0x300b, 0x11f9),
      _mm_set_pi16(0x05ce, 0x68b9, 0x1e9c, 0x9b33),
      _mm_set_pi32(0xd323bc06, 0xfeaae84f) },
    { _mm_set_pi16(0x0762, 0x7a49, 0x8a83, 0x09f8),
      _mm_set_pi16(0x96d8, 0x8c9c, 0x3bc4, 0x67d2),
      _mm_set_pi32(0xc5d9172c, 0xe89d32bc) },
    { _mm_set_pi16(0x5770, 0x02b8, 0x6533, 0x9ed4),
      _mm_set_pi16(0xd1af, 0x6a76, 0x8322, 0x1e74),
      _mm_set_pi32(0xf14fa660, 0xc31459d6) },
    { _mm_set_pi16(0x7504, 0xf723, 0x19f1, 0xa621),
      _mm_set_pi16(0x1fcf, 0x7715, 0x3c33, 0xc74d),
      _mm_set_pi32(0x0a6aa51b, 0x1a0145f0) },
    { _mm_set_pi16(0x1dbf, 0x4fa0, 0x14ce, 0xd074),
      _mm_set_pi16(0x690d, 0x4bfc, 0x0622, 0xade6),
      _mm_set_pi32(0x23d71b33, 0x0fbf4394) },
    { _mm_set_pi16(0x542c, 0x206b, 0x92d9, 0xb353),
      _mm_set_pi16(0xe189, 0xb2e8, 0x91d3, 0x4980),
      _mm_set_pi32(0xec387e84, 0x18f6465b) },
    { _mm_set_pi16(0xc622, 0xabc3, 0x0fdd, 0x7d94),
      _mm_set_pi16(0x6626, 0x3fd3, 0x8e4e, 0x0eb5),
      _mm_set_pi32(0xd3e883c5, 0x002b4cfa) },
    { _mm_set_pi16(0xc7f3, 0x7170, 0x2abf, 0xc5c3),
      _mm_set_pi16(0x1240, 0x70ba, 0x0571, 0x11a9),
      _mm_set_pi32(0x2df47e20, 0xfce41a0a) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_madd_pi16(test_vec[i].a, test_vec[i].b);
    assert_m64_pi32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_mulhi_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    __m64 b;
    __m64 r;
  } test_vec[8] = {
    { _mm_set_pi16(0x2313, 0x1422, 0xbdae, 0x78d0),
      _mm_set_pi16(0x0083, 0x9862, 0x90a4, 0x0c54),
      _mm_set_pi16(0x0011, 0xf7d9, 0x1cd9, 0x05d1) },
    { _mm_set_pi16(0xaf0c, 0x80ce, 0xef41, 0xd126),
      _mm_set_pi16(0xfa81, 0xb003, 0x092e, 0xec08),
      _mm_set_pi16(0x01bc, 0x27be, 0xff66, 0x03a7) },
    { _mm_set_pi16(0xb4d6, 0xb026, 0x9f1d, 0x6846),
      _mm_set_pi16(0x33b1, 0xe5b0, 0x01c9, 0x415b),
      _mm_set_pi16(0xf0d2, 0x0835, 0xff53, 0x1a9e) },
    { _mm_set_pi16(0xe16a, 0x4a31, 0x07ff, 0x7fdf),
      _mm_set_pi16(0x4295, 0xa56c, 0xc089, 0xe71f),
      _mm_set_pi16(0xf80b, 0xe5bf, 0xfe04, 0xf392) },
    { _mm_set_pi16(0xb095, 0xf915, 0x1c97, 0xf784),
      _mm_set_pi16(0x6b51, 0x0e98, 0x680b, 0x9fc8),
      _mm_set_pi16(0xdeb5, 0xff9b, 0x0b9e, 0x0330) },
    { _mm_set_pi16(0x49af, 0x72ab, 0x562f, 0x61a0),
      _mm_set_pi16(0x7b9e, 0x2a62, 0xfb6a, 0x18f2),
      _mm_set_pi16(0x2394, 0x12fb, 0xfe74, 0x0983) },
    { _mm_set_pi16(0x3277, 0x6cbc, 0xc38f, 0x79fb),
      _mm_set_pi16(0xf7fd, 0x1879, 0xc9f1, 0x39cb),
      _mm_set_pi16(0xfe6b, 0x0a65, 0x0cc3, 0x1b89) },
    { _mm_set_pi16(0xb0d7, 0xf6ad, 0x0765, 0x40de),
      _mm_set_pi16(0x7b65, 0xe045, 0x6812, 0x1b46),
      _mm_set_pi16(0xd9d8, 0x0127, 0x0301, 0x06e9) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_mulhi_pi16(test_vec[i].a, test_vec[i].b);
    assert_m64_pi16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_mullo_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    __m64 b;
    __m64 r;
  } test_vec[8] = {
    { _mm_set_pi16(0x04db, 0x4fc0, 0x3d33, 0x114e),
      _mm_set_pi16(0xe971, 0x6846, 0x4284, 0x5bf1),
      _mm_set_pi16(0x77ab, 0xce80, 0xb44c, 0x046e) },
    { _mm_set_pi16(0xeb92, 0xaf0a, 0x81d3, 0x10e4),
      _mm_set_pi16(0x7ab8, 0x9eda, 0x6f4a, 0x90c6),
      _mm_set_pi16(0xe4f0, 0x3a84, 0x03fe, 0x5058) },
    { _mm_set_pi16(0x0167, 0x6e9b, 0x759d, 0x76a2),
      _mm_set_pi16(0x2c62, 0xa02a, 0xe19d, 0x863a),
      _mm_set_pi16(0x3d6e, 0x056e, 0x1e49, 0xacb4) },
    { _mm_set_pi16(0xe1fe, 0xbbc0, 0x0465, 0x87f3),
      _mm_set_pi16(0x6abb, 0x5326, 0x6eac, 0x9720),
      _mm_set_pi16(0x408a, 0x1e80, 0x59dc, 0x5360) },
    { _mm_set_pi16(0x6f34, 0xf04b, 0x5b1d, 0xa033),
      _mm_set_pi16(0x723a, 0xebf1, 0x2fd1, 0xe9d9),
      _mm_set_pi16(0x59c8, 0x0f9b, 0xb5ad, 0x363b) },
    { _mm_set_pi16(0xd41f, 0xdbed, 0xa4d4, 0xffc9),
      _mm_set_pi16(0xabc1, 0xca87, 0x5424, 0x7fae),
      _mm_set_pi16(0xa05f, 0xfbfb, 0xbdd0, 0x919e) },
    { _mm_set_pi16(0x607f, 0x9603, 0x33e9, 0x5161),
      _mm_set_pi16(0x8014, 0x3d58, 0x298b, 0xc9a9),
      _mm_set_pi16(0x09ec, 0x4808, 0x8083, 0xe209) },
    { _mm_set_pi16(0xb053, 0xbc73, 0xf80a, 0xa10f),
      _mm_set_pi16(0x9d40, 0x0a76, 0xba7a, 0x27f3),
      _mm_set_pi16(0xfbc0, 0x5b02, 0x78c4, 0x2a3d), }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_mullo_pi16(test_vec[i].a, test_vec[i].b);
    assert_m64_pi16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_or_si64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < 32 ; i++) {
    int64_t ai, bi, ri;
    __m64 a, b, r;
    munit_rand_memory(sizeof(ai), (uint8_t*) &ai);
    munit_rand_memory(sizeof(bi), (uint8_t*) &bi);

    a = _mm_cvtsi64_m64(ai);
    b = _mm_cvtsi64_m64(bi);
    r = _mm_or_si64(a, b);

    ri = ai | bi;

    munit_assert_int64(ri, ==, *((int64_t*) &r));
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_packs_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    __m64 b;
    __m64 r;
  } test_vec[8] = {
    { _mm_set_pi16(0xbc19, 0xd06b, 0xf468, 0x6802),
      _mm_set_pi16(0xd8c8, 0x3578, 0x8717, 0xf03b),
      _mm_set_pi8 (0x80, 0x7f, 0x80, 0x80,
		   0x80, 0x80, 0x80, 0x7f) },
    { _mm_set_pi16(0xb11e, 0x302b, 0xa5bb, 0x624a),
      _mm_set_pi16(0xfbd1, 0x5029, 0x035c, 0x16f3),
      _mm_set_pi8 (0x80, 0x7f, 0x7f, 0x7f,
		   0x80, 0x7f, 0x80, 0x7f) },
    { _mm_set_pi16(0xd021, 0x33dd, 0x8eea, 0x1485),
      _mm_set_pi16(0x62ff, 0xfb1c, 0x0de9, 0x1d72),
      _mm_set_pi8 (0x7f, 0x80, 0x7f, 0x7f,
		   0x80, 0x7f, 0x80, 0x7f) },
    { _mm_set_pi16(0xd40d, 0xad82, 0xf7e3, 0xb090),
      _mm_set_pi16(0x5b74, 0x1eda, 0xf20d, 0x241a),
      _mm_set_pi8 (0x7f, 0x7f, 0x80, 0x7f,
		   0x80, 0x80, 0x80, 0x80) },
    { _mm_set_pi16(0x6e14, 0x62fb, 0x4f68, 0x0beb),
      _mm_set_pi16(0x799f, 0x0dfd, 0x2d20, 0x61ca),
      _mm_set_pi8 (0x7f, 0x7f, 0x7f, 0x7f,
		   0x7f, 0x7f, 0x7f, 0x7f) },
    { _mm_set_pi16(0x3731, 0xf45a, 0xcc34, 0xd03f),
      _mm_set_pi16(0xfdd3, 0xc71c, 0x925f, 0x6424),
      _mm_set_pi8 (0x80, 0x80, 0x80, 0x7f,
		   0x7f, 0x80, 0x80, 0x80) },
    { _mm_set_pi16(0x7a65, 0x513c, 0x419b, 0xebf9),
      _mm_set_pi16(0x562c, 0x29b9, 0x705b, 0x0b1f),
      _mm_set_pi8 (0x7f, 0x7f, 0x7f, 0x7f,
		   0x7f, 0x7f, 0x7f, 0x80) },
    { _mm_set_pi16(0x00a7, 0x00e9, 0x0073, 0x007e),
      _mm_set_pi16(0x000a, 0x005e, 0x00b5, 0x00e9),
      _mm_set_pi8 (0x0a, 0x5e, 0x7f, 0x7f,
		   0x7f, 0x7f, 0x73, 0x7e) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_packs_pi16(test_vec[i].a, test_vec[i].b);
    assert_m64_pi8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_packs_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    __m64 b;
    __m64 r;
  } test_vec[8] = {
    { _mm_set_pi32(0xffd41e9c, 0xfffffffc),
      _mm_set_pi32(0xffffffcb, 0x000e43e4),
      _mm_set_pi16(0xffcb, 0x7fff, 0x8000, 0xfffc) },
    { _mm_set_pi32(0x00000001, 0xf3140acf),
      _mm_set_pi32(0x00000078, 0xfffa33eb),
      _mm_set_pi16(0x0078, 0x8000, 0x0001, 0x8000) },
    { _mm_set_pi32(0xffffffee, 0x00000119),
      _mm_set_pi32(0xffff7ed8, 0x00000082),
      _mm_set_pi16(0x8000, 0x0082, 0xffee, 0x0119) },
    { _mm_set_pi32(0xffff35ef, 0x0000000e),
      _mm_set_pi32(0x00001ac4, 0xffffffdc),
      _mm_set_pi16(0x1ac4, 0xffdc, 0x8000, 0x000e) },
    { _mm_set_pi32(0xffffffff, 0xffffff2e),
      _mm_set_pi32(0x002e285f, 0x01d860a7),
      _mm_set_pi16(0x7fff, 0x7fff, 0xffff, 0xff2e) },
    { _mm_set_pi32(0x0000001c, 0x0000037a),
      _mm_set_pi32(0xffe1000f, 0xffffeb43),
      _mm_set_pi16(0x8000, 0xeb43, 0x001c, 0x037a) },
    { _mm_set_pi32(0xffffffb0, 0x00411d82),
      _mm_set_pi32(0x02125ab9, 0x0001f081),
      _mm_set_pi16(0x7fff, 0x7fff, 0xffb0, 0x7fff) },
    { _mm_set_pi32(0xffd5af7d, 0xffffffd6),
      _mm_set_pi32(0x00000021, 0x0035eed5),
      _mm_set_pi16(0x0021, 0x7fff, 0x8000, 0xffd6) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_packs_pi32(test_vec[i].a, test_vec[i].b);
    assert_m64_pi16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_packs_pu16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    __m64 b;
    __m64 r;
  } test_vec[8] = {
    { _mm_set_pi16(0xfffe, 0x0071, 0x0031, 0xfd79),
      _mm_set_pi16(0x0038, 0x0005, 0x0001, 0xffca),
      _mm_set_pi8 (0x38, 0x05, 0x01, 0x00,
		   0x00, 0x71, 0x31, 0x00) },
    { _mm_set_pi16(0xffff, 0xff32, 0xf98e, 0xff93),
      _mm_set_pi16(0xf10c, 0x0002, 0x01d7, 0x0002),
      _mm_set_pi8 (0x00, 0x02, 0xff, 0x02,
		   0x00, 0x00, 0x00, 0x00) },
    { _mm_set_pi16(0x0003, 0xfffe, 0x01f4, 0xff9c),
      _mm_set_pi16(0xf9da, 0xffff, 0xffff, 0x0002),
      _mm_set_pi8 (0x00, 0x00, 0x00, 0x02,
		   0x03, 0x00, 0xff, 0x00) },
    { _mm_set_pi16(0xfff3, 0xff27, 0x0ce9, 0xfff6),
      _mm_set_pi16(0xfe8e, 0x00b5, 0x0001, 0xfa66),
      _mm_set_pi8 (0x00, 0xb5, 0x01, 0x00,
		   0x00, 0x00, 0xff, 0x00) },
    { _mm_set_pi16(0x0363, 0xffc1, 0xfc15, 0x000d),
      _mm_set_pi16(0x8b62, 0xfffa, 0x0021, 0x0005),
      _mm_set_pi8 (0x00, 0x00, 0x21, 0x05,
		   0xff, 0x00, 0x00, 0x0d) },
    { _mm_set_pi16(0x0303, 0xffff, 0xfff3, 0xfffe),
      _mm_set_pi16(0xffbf, 0x0037, 0x0127, 0x4466),
      _mm_set_pi8 (0x00, 0x37, 0xff, 0xff,
		   0xff, 0x00, 0x00, 0x00) },
    { _mm_set_pi16(0x0032, 0x7e51, 0x000d, 0x4fe1),
      _mm_set_pi16(0xfc7f, 0xff8f, 0xf0e6, 0xc271),
      _mm_set_pi8 (0x00, 0x00, 0x00, 0x00,
		   0x32, 0xff, 0x0d, 0xff) },
    { _mm_set_pi16(0x0000, 0x1195, 0x00ca, 0x2614),
      _mm_set_pi16(0xfffe, 0xffff, 0xc024, 0xe762),
      _mm_set_pi8 (0x00, 0x00, 0x00, 0x00,
		   0x00, 0xff, 0xca, 0xff) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_packs_pu16(test_vec[i].a, test_vec[i].b);
    assert_m64_pu8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_sll_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    __m64 count;
    __m64 r;
  } test_vec[8] = {
    { _mm_set_pi16(0xf5cc, 0xe395, 0x6194, 0x31c8),
      _mm_cvtsi64_m64(15),
      _mm_set_pi16(0x0000, 0x8000, 0x0000, 0x0000) },
    { _mm_set_pi16(0x42f7, 0xd120, 0x7dff, 0x1548),
      _mm_cvtsi64_m64(10),
      _mm_set_pi16(0xdc00, 0x8000, 0xfc00, 0x2000) },
    { _mm_set_pi16(0x04c3, 0xb817, 0x60bb, 0x32df),
      _mm_cvtsi64_m64(3),
      _mm_set_pi16(0x2618, 0xc0b8, 0x05d8, 0x96f8) },
    { _mm_set_pi16(0x877b, 0xfe4a, 0xcca2, 0xf65c),
      _mm_cvtsi64_m64(10),
      _mm_set_pi16(0xec00, 0x2800, 0x8800, 0x7000) },
    { _mm_set_pi16(0xb089, 0x77f9, 0x67c6, 0x23fd),
      _mm_cvtsi64_m64(7),
      _mm_set_pi16(0x4480, 0xfc80, 0xe300, 0xfe80) },
    { _mm_set_pi16(0xc7ff, 0xecde, 0x7f92, 0xecb0),
      _mm_cvtsi64_m64(5),
      _mm_set_pi16(0xffe0, 0x9bc0, 0xf240, 0x9600) },
    { _mm_set_pi16(0x5490, 0x6348, 0x4dd1, 0xbe9e),
      _mm_cvtsi64_m64(0),
      _mm_set_pi16(0x5490, 0x6348, 0x4dd1, 0xbe9e) },
    { _mm_set_pi16(0xd780, 0xb3e5, 0xc3cc, 0x8ae5),
      _mm_cvtsi64_m64(9),
      _mm_set_pi16(0x0000, 0xca00, 0x9800, 0xca00) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_sll_pi16(test_vec[i].a, test_vec[i].count);
    assert_m64_pi8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_sll_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    __m64 count;
    __m64 r;
  } test_vec[8] = {
    { _mm_set_pi32(0x7f4ad262, 0x9ce45b37),
      _mm_cvtsi64_m64(10),
      _mm_set_pi32(0x2b498800, 0x916cdc00) },
    { _mm_set_pi32(0x76509267, 0xfb7918be),
      _mm_cvtsi64_m64(14),
      _mm_set_pi32(0x2499c000, 0x462f8000) },
    { _mm_set_pi32(0xb1961bea, 0x99a67ad1),
      _mm_cvtsi64_m64(22),
      _mm_set_pi32(0xfa800000, 0xb4400000) },
    { _mm_set_pi32(0xcf780e55, 0x2ffc2805),
      _mm_cvtsi64_m64(9),
      _mm_set_pi32(0xf01caa00, 0xf8500a00) },
    { _mm_set_pi32(0xa14be044, 0x7f1e6323),
      _mm_cvtsi64_m64(1),
      _mm_set_pi32(0x4297c088, 0xfe3cc646) },
    { _mm_set_pi32(0x2ea0903c, 0x819cf8de),
      _mm_cvtsi64_m64(16),
      _mm_set_pi32(0x903c0000, 0xf8de0000) },
    { _mm_set_pi32(0x9b698d6c, 0xb4ae77cf),
      _mm_cvtsi64_m64(16),
      _mm_set_pi32(0x8d6c0000, 0x77cf0000) },
    { _mm_set_pi32(0xb4ff9134, 0x3a22907b),
      _mm_cvtsi64_m64(5),
      _mm_set_pi32(0x9ff22680, 0x44520f60) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_sll_pi32(test_vec[i].a, test_vec[i].count);
    assert_m64_pi8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_sll_si64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    __m64 count;
    __m64 r;
  } test_vec[8] = {
    { _mm_cvtsi64_m64(UINT64_C(0x2c04f0afbb6ea869)),
      _mm_cvtsi64_m64(26),
      _mm_cvtsi64_m64(UINT64_C(0xbeedbaa1a4000000)) },
    { _mm_cvtsi64_m64(UINT64_C(0x7a46741e0e1d199a)),
      _mm_cvtsi64_m64(35),
      _mm_cvtsi64_m64(UINT64_C(0x70e8ccd000000000)) },
    { _mm_cvtsi64_m64(UINT64_C(0x728909a27299f7e0)),
      _mm_cvtsi64_m64(60),
      _mm_cvtsi64_m64(UINT64_C(0x0000000000000000)) },
    { _mm_cvtsi64_m64(UINT64_C(0xfe7a4be78826c849)),
      _mm_cvtsi64_m64(35),
      _mm_cvtsi64_m64(UINT64_C(0x4136424800000000)) },
    { _mm_cvtsi64_m64(UINT64_C(0x0b12beceffaf415c)),
      _mm_cvtsi64_m64(19),
      _mm_cvtsi64_m64(UINT64_C(0xf677fd7a0ae00000)) },
    { _mm_cvtsi64_m64(UINT64_C(0xdf28bbede8bf899f)),
      _mm_cvtsi64_m64(28),
      _mm_cvtsi64_m64(UINT64_C(0xde8bf899f0000000)) },
    { _mm_cvtsi64_m64(UINT64_C(0x2a161b540172d78c)),
      _mm_cvtsi64_m64(28),
      _mm_cvtsi64_m64(UINT64_C(0x40172d78c0000000)) },
    { _mm_cvtsi64_m64(UINT64_C(0x4fae0c57c0b6e410)),
      _mm_cvtsi64_m64(44),
      _mm_cvtsi64_m64(UINT64_C(0x6e41000000000000)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_sll_si64(test_vec[i].a, test_vec[i].count);
    assert_m64_pi8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_slli_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    int count;
    __m64 r;
  } test_vec[8] = {
    { _mm_set_pi16(0xcb19, 0x18d8, 0xfae6, 0xe8c4),
      6,
      _mm_set_pi16(0xc640, 0x3600, 0xb980, 0x3100) },
    { _mm_set_pi16(0x196a, 0x908b, 0x0f94, 0x8616),
      10,
      _mm_set_pi16(0xa800, 0x2c00, 0x5000, 0x5800) },
    { _mm_set_pi16(0x4bbc, 0xee58, 0x256e, 0x2b3b),
      9,
      _mm_set_pi16(0x7800, 0xb000, 0xdc00, 0x7600) },
    { _mm_set_pi16(0x2ee0, 0x70cc, 0x748a, 0xca52),
      13,
      _mm_set_pi16(0x0000, 0x8000, 0x4000, 0x4000) },
    { _mm_set_pi16(0x1228, 0xf799, 0x97ef, 0x93f5),
      13,
      _mm_set_pi16(0x0000, 0x2000, 0xe000, 0xa000) },
    { _mm_set_pi16(0xf6cf, 0x4f5d, 0x1d02, 0x60d4),
      8,
      _mm_set_pi16(0xcf00, 0x5d00, 0x0200, 0xd400) },
    { _mm_set_pi16(0xe7e2, 0x7b04, 0x6f9f, 0xb061),
      1,
      _mm_set_pi16(0xcfc4, 0xf608, 0xdf3e, 0x60c2) },
    { _mm_set_pi16(0x895d, 0x43b6, 0x097c, 0xee32),
      5,
      _mm_set_pi16(0x2ba0, 0x76c0, 0x2f80, 0xc640) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_slli_pi16(test_vec[i].a, test_vec[i].count);
    assert_m64_pi8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_slli_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    int count;
    __m64 r;
  } test_vec[8] = {
    { _mm_set_pi32(0x04ffee39, 0x50f0b271),
      27,
      _mm_set_pi32(0xc8000000, 0x88000000) },
    { _mm_set_pi32(0x808c26ce, 0x87a74a01),
      21,
      _mm_set_pi32(0xd9c00000, 0x40200000) },
    { _mm_set_pi32(0xef396ea2, 0xa32de51c),
      27,
      _mm_set_pi32(0x10000000, 0xe0000000) },
    { _mm_set_pi32(0xb8065dee, 0xd69715dd),
      7,
      _mm_set_pi32(0x032ef700, 0x4b8aee80) },
    { _mm_set_pi32(0x35ce5c4f, 0x3837d0e9),
      20,
      _mm_set_pi32(0xc4f00000, 0x0e900000) },
    { _mm_set_pi32(0x00714779, 0x8a4c973c),
      5,
      _mm_set_pi32(0x0e28ef20, 0x4992e780) },
    { _mm_set_pi32(0x0a6a1f78, 0xcae36ead),
      23,
      _mm_set_pi32(0xbc000000, 0x56800000) },
    { _mm_set_pi32(0x08083026, 0x8f1bda56),
      27,
      _mm_set_pi32(0x30000000, 0xb0000000) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_slli_pi32(test_vec[i].a, test_vec[i].count);
    assert_m64_pi32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_slli_si64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    int count;
    __m64 r;
  } test_vec[8] = {
    { _mm_cvtsi64_m64(UINT64_C(0xcd43562d622ff9b1)),
      37,
      _mm_cvtsi64_m64(UINT64_C(0x45ff362000000000)) },
    { _mm_cvtsi64_m64(UINT64_C(0x4a92fbd485a9b75f)),
      49,
      _mm_cvtsi64_m64(UINT64_C(0x6ebe000000000000)) },
    { _mm_cvtsi64_m64(UINT64_C(0x0d43ccc2a755e98b)),
      11,
      _mm_cvtsi64_m64(UINT64_C(0x1e66153aaf4c5800)) },
    { _mm_cvtsi64_m64(UINT64_C(0x3d8d216dac296ce8)),
      32,
      _mm_cvtsi64_m64(UINT64_C(0xac296ce800000000)) },
    { _mm_cvtsi64_m64(UINT64_C(0x0712ddca397d1f67)),
      0,
      _mm_cvtsi64_m64(UINT64_C(0x0712ddca397d1f67)) },
    { _mm_cvtsi64_m64(UINT64_C(0x2aec7cc06c8e582f)),
      24,
      _mm_cvtsi64_m64(UINT64_C(0xc06c8e582f000000)) },
    { _mm_cvtsi64_m64(UINT64_C(0x829e3515410b7239)),
      38,
      _mm_cvtsi64_m64(UINT64_C(0x42dc8e4000000000)) },
    { _mm_cvtsi64_m64(UINT64_C(0x73e930dce2b1e174)),
      34,
      _mm_cvtsi64_m64(UINT64_C(0x8ac785d000000000)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_slli_si64(test_vec[i].a, test_vec[i].count);
    assert_m64_si64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_srl_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    __m64 count;
    __m64 r;
  } test_vec[8] = {
    { _mm_set_pi16(0xf075, 0x8ac3, 0x5934, 0x1d0e),
      _mm_cvtsi64_m64(5),
      _mm_set_pi16(0x0783, 0x0456, 0x02c9, 0x00e8) },
    { _mm_set_pi16(0xba1f, 0x8621, 0x08b9, 0x71f8),
      _mm_cvtsi64_m64(9),
      _mm_set_pi16(0x005d, 0x0043, 0x0004, 0x0038) },
    { _mm_set_pi16(0xc810, 0x8d5b, 0xed98, 0x0bd7),
      _mm_cvtsi64_m64(6),
      _mm_set_pi16(0x0320, 0x0235, 0x03b6, 0x002f) },
    { _mm_set_pi16(0x7022, 0xc4f7, 0xf329, 0xcad7),
      _mm_cvtsi64_m64(13),
      _mm_set_pi16(0x0003, 0x0006, 0x0007, 0x0006) },
    { _mm_set_pi16(0xef04, 0x37f4, 0x30cb, 0x8005),
      _mm_cvtsi64_m64(2),
      _mm_set_pi16(0x3bc1, 0x0dfd, 0x0c32, 0x2001) },
    { _mm_set_pi16(0xfa52, 0xf3c0, 0x4204, 0x9966),
      _mm_cvtsi64_m64(11),
      _mm_set_pi16(0x001f, 0x001e, 0x0008, 0x0013) },
    { _mm_set_pi16(0x59f8, 0x5229, 0x081a, 0x8990),
      _mm_cvtsi64_m64(9),
      _mm_set_pi16(0x002c, 0x0029, 0x0004, 0x0044) },
    { _mm_set_pi16(0x0963, 0x17b6, 0xc003, 0x3b5e),
      _mm_cvtsi64_m64(10),
      _mm_set_pi16(0x0002, 0x0005, 0x0030, 0x000e) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_srl_pi16(test_vec[i].a, test_vec[i].count);
    assert_m64_pi16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_srl_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    __m64 count;
    __m64 r;
  } test_vec[8] = {
    { _mm_set_pi32(0x45500e39, 0x29ce91a0),
      _mm_cvtsi64_m64(12),
      _mm_set_pi32(0x00045500, 0x00029ce9) },
    { _mm_set_pi32(0x98e22875, 0x5841f889),
      _mm_cvtsi64_m64(7),
      _mm_set_pi32(0x0131c450, 0x00b083f1) },
    { _mm_set_pi32(0x878f4877, 0xff28f0c5),
      _mm_cvtsi64_m64(9),
      _mm_set_pi32(0x0043c7a4, 0x007f9478) },
    { _mm_set_pi32(0x48326f60, 0xdf3c5d81),
      _mm_cvtsi64_m64(13),
      _mm_set_pi32(0x00024193, 0x0006f9e2) },
    { _mm_set_pi32(0x1f65e5a9, 0xae33f533),
      _mm_cvtsi64_m64(6),
      _mm_set_pi32(0x007d9796, 0x02b8cfd4) },
    { _mm_set_pi32(0x0f5d5327, 0x54fc0ab6),
      _mm_cvtsi64_m64(0),
      _mm_set_pi32(0x0f5d5327, 0x54fc0ab6) },
    { _mm_set_pi32(0x2cc48188, 0x8c7f8abd),
      _mm_cvtsi64_m64(6),
      _mm_set_pi32(0x00b31206, 0x0231fe2a) },
    { _mm_set_pi32(0xd60f89f8, 0x5881863d),
      _mm_cvtsi64_m64(14),
      _mm_set_pi32(0x0003583e, 0x00016206) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_srl_pi32(test_vec[i].a, test_vec[i].count);
    assert_m64_pi32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_srl_si64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    __m64 count;
    __m64 r;
  } test_vec[8] = {
    { _mm_cvtsi64_m64(UINT64_C(0xea7aa541209e78a3)),
      _mm_cvtsi64_m64(27),
      _mm_cvtsi64_m64(UINT64_C(0x0000001d4f54a824)) },
    { _mm_cvtsi64_m64(UINT64_C(0xbbec34bf863cb4d4)),
      _mm_cvtsi64_m64(51),
      _mm_cvtsi64_m64(UINT64_C(0x000000000000177d)) },
    { _mm_cvtsi64_m64(UINT64_C(0x0ae429e18cbb8916)),
      _mm_cvtsi64_m64(61),
      _mm_cvtsi64_m64(UINT64_C(0x0000000000000000)) },
    { _mm_cvtsi64_m64(UINT64_C(0x9c9f203aff59da8a)),
      _mm_cvtsi64_m64(36),
      _mm_cvtsi64_m64(UINT64_C(0x0000000009c9f203)) },
    { _mm_cvtsi64_m64(UINT64_C(0xfe491dcbefe1048e)),
      _mm_cvtsi64_m64(20),
      _mm_cvtsi64_m64(UINT64_C(0x00000fe491dcbefe)) },
    { _mm_cvtsi64_m64(UINT64_C(0x4f62e48272d323ba)),
      _mm_cvtsi64_m64(33),
      _mm_cvtsi64_m64(UINT64_C(0x0000000027b17241)) },
    { _mm_cvtsi64_m64(UINT64_C(0xd0d70b418df5be8a)),
      _mm_cvtsi64_m64(63),
      _mm_cvtsi64_m64(UINT64_C(0x0000000000000001)) },
    { _mm_cvtsi64_m64(UINT64_C(0xb5abd94b7f048cf1)),
      _mm_cvtsi64_m64(7),
      _mm_cvtsi64_m64(UINT64_C(0x016b57b296fe0919)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_srl_si64(test_vec[i].a, test_vec[i].count);
    assert_m64_si64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_srli_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    int count;
    __m64 r;
  } test_vec[8] = {
    { _mm_set_pi16(0xc2ae, 0x81ca, 0x0153, 0x0da8),
      10,
      _mm_set_pi16(0x0030, 0x0020, 0x0000, 0x0003) },
    { _mm_set_pi16(0x9581, 0xb910, 0xaff9, 0xad4b),
      6,
      _mm_set_pi16(0x0256, 0x02e4, 0x02bf, 0x02b5) },
    { _mm_set_pi16(0x5cfd, 0xc5a3, 0x199e, 0xa2a8),
      6,
      _mm_set_pi16(0x0173, 0x0316, 0x0066, 0x028a) },
    { _mm_set_pi16(0x5806, 0x9522, 0xdaef, 0xc19c),
      7,
      _mm_set_pi16(0x00b0, 0x012a, 0x01b5, 0x0183) },
    { _mm_set_pi16(0x08a4, 0x8dd9, 0xb2b9, 0xeff7),
      0,
      _mm_set_pi16(0x08a4, 0x8dd9, 0xb2b9, 0xeff7) },
    { _mm_set_pi16(0x5fef, 0xaaa6, 0x884a, 0x53af),
      14,
      _mm_set_pi16(0x0001, 0x0002, 0x0002, 0x0001) },
    { _mm_set_pi16(0xf357, 0x84ee, 0x0e4e, 0x41a5),
      5,
      _mm_set_pi16(0x079a, 0x0427, 0x0072, 0x020d) },
    { _mm_set_pi16(0xca93, 0x1bcd, 0xc339, 0xdf50),
      14,
      _mm_set_pi16(0x0003, 0x0000, 0x0003, 0x0003) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_srli_pi16(test_vec[i].a, test_vec[i].count);
    assert_m64_pi16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_srli_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    int count;
    __m64 r;
  } test_vec[8] = {
    { _mm_set_pi32(0x06eb9f8e, 0xdb7ca4b4),
      14,
      _mm_set_pi32(0x00001bae, 0x00036df2) },
    { _mm_set_pi32(0xde11ef32, 0x3ef12f10),
      8,
      _mm_set_pi32(0x00de11ef, 0x003ef12f) },
    { _mm_set_pi32(0x32c19cf4, 0xb074f693),
      15,
      _mm_set_pi32(0x00006583, 0x000160e9) },
    { _mm_set_pi32(0xa504922a, 0x07c97d7c),
      14,
      _mm_set_pi32(0x00029412, 0x00001f25) },
    { _mm_set_pi32(0x92c20b1b, 0xfe4899a0),
      0,
      _mm_set_pi32(0x92c20b1b, 0xfe4899a0) },
    { _mm_set_pi32(0xa550f015, 0x0db9339b),
      4,
      _mm_set_pi32(0x0a550f01, 0x00db9339) },
    { _mm_set_pi32(0x3a86be3b, 0xd26a9556),
      15,
      _mm_set_pi32(0x0000750d, 0x0001a4d5) },
    { _mm_set_pi32(0x8f650e77, 0x57c7dfe5),
      10,
      _mm_set_pi32(0x0023d943, 0x0015f1f7) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_srli_pi32(test_vec[i].a, test_vec[i].count);
    assert_m64_pi32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_srli_si64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    int count;
    __m64 r;
  } test_vec[8] = {
    { _mm_cvtsi64_m64(UINT64_C(0x8ce4027b1e0d360e)),
      62,
      _mm_cvtsi64_m64(UINT64_C(0x0000000000000002)) },
    { _mm_cvtsi64_m64(UINT64_C(0x6186090de6e3b8c5)),
      7,
      _mm_cvtsi64_m64(UINT64_C(0x00c30c121bcdc771)) },
    { _mm_cvtsi64_m64(UINT64_C(0x24c5ffa8091448c9)),
      19,
      _mm_cvtsi64_m64(UINT64_C(0x00000498bff50122)) },
    { _mm_cvtsi64_m64(UINT64_C(0x0acdfc81055556b5)),
      12,
      _mm_cvtsi64_m64(UINT64_C(0x0000acdfc8105555)) },
    { _mm_cvtsi64_m64(UINT64_C(0x142c9011f8b32d28)),
      17,
      _mm_cvtsi64_m64(UINT64_C(0x00000a164808fc59)) },
    { _mm_cvtsi64_m64(UINT64_C(0x0b94e13d3efa50ab)),
      22,
      _mm_cvtsi64_m64(UINT64_C(0x0000002e5384f4fb)) },
    { _mm_cvtsi64_m64(UINT64_C(0x1a24842798802ebd)),
      12,
      _mm_cvtsi64_m64(UINT64_C(0x0001a24842798802)) },
    { _mm_cvtsi64_m64(UINT64_C(0x6e47a6cda4f29c7c)),
      61,
      _mm_cvtsi64_m64(UINT64_C(0x0000000000000003)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_srli_si64(test_vec[i].a, test_vec[i].count);
    assert_m64_si64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

/*** SSE ***/

#define assert_m128_ps(a, cmp, b)					\
  do {									\
    munit_assert_float(((float*) (&a))[0], cmp, ((float*) (&b))[0]);	\
    munit_assert_float(((float*) (&a))[1], cmp, ((float*) (&b))[1]);	\
    munit_assert_float(((float*) (&a))[2], cmp, ((float*) (&b))[2]);	\
    munit_assert_float(((float*) (&a))[3], cmp, ((float*) (&b))[3]);	\
  } while (0)

static MunitResult
test_simd_mm_set_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  float d[4];
  munit_rand_memory(sizeof(d), (uint8_t*) d);

  __m128 x = _mm_set_ps(d[0], d[1], d[2], d[3]);

  float* f = (float*) &x;
  munit_assert_float(f[0], ==, d[3]);
  munit_assert_float(f[1], ==, d[2]);
  munit_assert_float(f[2], ==, d[1]);
  munit_assert_float(f[3], ==, d[0]);

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_set1_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  float d;
  munit_rand_memory(sizeof(d), (uint8_t*) &d);

  __m128 x = _mm_set1_ps(d);

  float* f = (float*) &x;
  munit_assert_float(f[0], ==, d);
  munit_assert_float(f[1], ==, d);
  munit_assert_float(f[2], ==, d);
  munit_assert_float(f[3], ==, d);

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_add_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const __m128 expected = _mm_set_ps(6.0f, 8.0f, 10.0f, 12.0f);

  __m128 a = _mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f);
  __m128 b = _mm_set_ps(5.0f, 6.0f, 7.0f, 8.0f);
  __m128 r = _mm_add_ps(a, b);

  assert_m128_ps(r, ==, expected);

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_add_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const __m128 expected = _mm_set_ps(1.0f, 2.0f, 3.0f, 12.0f);

  __m128 a = _mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f);
  __m128 b = _mm_set_ps(5.0f, 6.0f, 7.0f, 8.0f);
  __m128 r = _mm_add_ss(a, b);

  assert_m128_ps(r, ==, expected);

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_and_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  return MUNIT_FAIL;
}

union test_m128 {
  __m128 flt;
  unsigned int u32 __attribute__((__vector_size__(16)));
};

#define assert_test_m128_equal(a, b)			\
  do {							\
    munit_assert_uint((a).u32[0], ==, (b).u32[0]);	\
    munit_assert_uint((a).u32[1], ==, (b).u32[1]);	\
    munit_assert_uint((a).u32[2], ==, (b).u32[2]);	\
    munit_assert_uint((a).u32[3], ==, (b).u32[3]);	\
  } while (0)

static MunitResult
test_simd_mm_andnot_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    union test_m128 a;
    union test_m128 b;
    union test_m128 r;
  } test_vec[] = {
    { { .u32 = { 0x68a765a6U, 0x3615220eU, 0xf27caeb4U, 0x145357a5U } },
      { .u32 = { 0x7db442f9U, 0xc2f92119U, 0xdf75482eU, 0xa5d29ccaU } },
      { .u32 = { 0x15100259U, 0xc0e80111U, 0x0d01400aU, 0xa180884aU } } },
    { { .u32 = { 0xbac21a36U, 0x1b8c1a30U, 0x207e65f1U, 0x7e986bc6U } },
      { .u32 = { 0xb4e0053fU, 0xb1b443c2U, 0x1df73f23U, 0xb88c9b63U } },
      { .u32 = { 0x04200509U, 0xa03041c2U, 0x1d811a02U, 0x80049021U } } },
    { { .u32 = { 0x9f9907b0U, 0x266cf90bU, 0xefbcb2daU, 0x63721e2fU } },
      { .u32 = { 0xb418e8e0U, 0x04c49252U, 0x85f1d529U, 0x20ab72fcU } },
      { .u32 = { 0x2000e840U, 0x00800250U, 0x00414521U, 0x008960d0U } } },
    { { .u32 = { 0x32a6778fU, 0x927fa890U, 0x2f76ea91U, 0x9fdc18a3U } },
      { .u32 = { 0x9a45c22bU, 0xfb88b4f5U, 0x8d063b31U, 0x832b9acdU } },
      { .u32 = { 0x88418020U, 0x69801465U, 0x80001120U, 0x0023824cU } } },
    { { .u32 = { 0x659de4f8U, 0xf213fa5eU, 0xc6c9e0beU, 0x6b9bf277U } },
      { .u32 = { 0x31908876U, 0x1eeec04cU, 0x5310af8fU, 0xef14b6d9U } },
      { .u32 = { 0x10000806U, 0x0cec0000U, 0x11100f01U, 0x84040488U } } },
    { { .u32 = { 0x6d451104U, 0x027c2d5cU, 0xdc87cb64U, 0x6bf717a5U } },
      { .u32 = { 0x01e81e45U, 0xa1fea0d1U, 0x68287855U, 0x54e0538dU } },
      { .u32 = { 0x00a80e41U, 0xa1828081U, 0x20283011U, 0x14004008U } } },
    { { .u32 = { 0xb1e89e3aU, 0x6d79a9c6U, 0x43e7d670U, 0x98a011a6U } },
      { .u32 = { 0x96a71891U, 0x43f287c0U, 0x125aace7U, 0x8e69b84bU } },
      { .u32 = { 0x06070081U, 0x02820600U, 0x10182887U, 0x0649a849U } } },
    { { .u32 = { 0xe497a675U, 0x9ab8e09eU, 0x25f2ae74U, 0xfc5647eaU } },
      { .u32 = { 0x045e24cdU, 0xd72971afU, 0x1ec71d1fU, 0x9f4d091dU } },
      { .u32 = { 0x00480088U, 0x45011121U, 0x1a05110bU, 0x03090815U } } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    union test_m128 r;
    r.flt = _mm_andnot_ps(test_vec[i].a.flt, test_vec[i].b.flt);

    assert_test_m128_equal(r, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_sub_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const __m128 expected = _mm_set1_ps(-4.0f);

  __m128 a = _mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f);
  __m128 b = _mm_set_ps(5.0f, 6.0f, 7.0f, 8.0f);
  __m128 sum = _mm_sub_ps(a, b);

  assert_m128_ps(sum, ==, expected);

  return MUNIT_OK;
}

/*** SSE2 ***/

#define assert_m128i_epi8(a, cmp, b)					\
  do {									\
    munit_assert_int8(((char*) (&a))[ 0], cmp, ((char*) (&b))[ 0]);	\
    munit_assert_int8(((char*) (&a))[ 1], cmp, ((char*) (&b))[ 1]);	\
    munit_assert_int8(((char*) (&a))[ 2], cmp, ((char*) (&b))[ 2]);	\
    munit_assert_int8(((char*) (&a))[ 3], cmp, ((char*) (&b))[ 3]);	\
    munit_assert_int8(((char*) (&a))[ 4], cmp, ((char*) (&b))[ 4]);	\
    munit_assert_int8(((char*) (&a))[ 5], cmp, ((char*) (&b))[ 5]);	\
    munit_assert_int8(((char*) (&a))[ 6], cmp, ((char*) (&b))[ 6]);	\
    munit_assert_int8(((char*) (&a))[ 7], cmp, ((char*) (&b))[ 7]);	\
    munit_assert_int8(((char*) (&a))[ 8], cmp, ((char*) (&b))[ 8]);	\
    munit_assert_int8(((char*) (&a))[ 9], cmp, ((char*) (&b))[ 9]);	\
    munit_assert_int8(((char*) (&a))[10], cmp, ((char*) (&b))[10]);	\
    munit_assert_int8(((char*) (&a))[11], cmp, ((char*) (&b))[11]);	\
    munit_assert_int8(((char*) (&a))[12], cmp, ((char*) (&b))[12]);	\
    munit_assert_int8(((char*) (&a))[13], cmp, ((char*) (&b))[13]);	\
    munit_assert_int8(((char*) (&a))[14], cmp, ((char*) (&b))[14]);	\
    munit_assert_int8(((char*) (&a))[15], cmp, ((char*) (&b))[15]);	\
  } while (0)

#define assert_m128i_epi16(a, cmp, b)					\
  do {									\
    munit_assert_int8(((short*) (&a))[ 0], cmp, ((short*) (&b))[ 0]);	\
    munit_assert_int8(((short*) (&a))[ 1], cmp, ((short*) (&b))[ 1]);	\
    munit_assert_int8(((short*) (&a))[ 2], cmp, ((short*) (&b))[ 2]);	\
    munit_assert_int8(((short*) (&a))[ 3], cmp, ((short*) (&b))[ 3]);	\
    munit_assert_int8(((short*) (&a))[ 4], cmp, ((short*) (&b))[ 4]);	\
    munit_assert_int8(((short*) (&a))[ 5], cmp, ((short*) (&b))[ 5]);	\
    munit_assert_int8(((short*) (&a))[ 6], cmp, ((short*) (&b))[ 6]);	\
    munit_assert_int8(((short*) (&a))[ 7], cmp, ((short*) (&b))[ 7]);	\
  } while (0)

static MunitResult
test_simd_mm_add_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m128i a;
    __m128i b;
    __m128i r;
  } test_vec[8] = {
    { _mm_set_epi8(0x38, 0x70, 0xd8, 0x83, 0x2b, 0x0d, 0xc8, 0x0e,
		   0x59, 0xc5, 0x29, 0x93, 0xf8, 0x91, 0x24, 0x5c),
      _mm_set_epi8(0xf7, 0xae, 0xd8, 0x72, 0x43, 0xc2, 0xa3, 0xad,
		   0xaf, 0x39, 0xbf, 0x20, 0x01, 0x44, 0x1d, 0x37),
      _mm_set_epi8(0x2f, 0x1e, 0xb0, 0xf5, 0x6e, 0xcf, 0x6b, 0xbb,
		   0x08, 0xfe, 0xe8, 0xb3, 0xf9, 0xd5, 0x41, 0x93) },
    { _mm_set_epi8(0x94, 0x89, 0xfb, 0x0a, 0x1a, 0xb2, 0xe5, 0x8f,
		   0xfe, 0xc5, 0x90, 0x45, 0x74, 0xf5, 0x58, 0x6b),
      _mm_set_epi8(0xaf, 0xa6, 0x18, 0xae, 0x73, 0x15, 0x76, 0xfd,
		   0x75, 0x66, 0xb8, 0x3c, 0x83, 0x9f, 0x0b, 0xe7),
      _mm_set_epi8(0x43, 0x2f, 0x13, 0xb8, 0x8d, 0xc7, 0x5b, 0x8c,
		   0x73, 0x2b, 0x48, 0x81, 0xf7, 0x94, 0x63, 0x52) },
    { _mm_set_epi8(0xb6, 0x3a, 0x7d, 0x4e, 0xc0, 0xb0, 0x5b, 0x39,
		   0xa4, 0x2b, 0xac, 0x0e, 0x77, 0xa3, 0xca, 0x3e),
      _mm_set_epi8(0x7f, 0x82, 0x01, 0x7d, 0xde, 0xa2, 0x79, 0x1c,
		   0x35, 0x55, 0x53, 0x79, 0xf4, 0x8f, 0x7f, 0x51),
      _mm_set_epi8(0x35, 0xbc, 0x7e, 0xcb, 0x9e, 0x52, 0xd4, 0x55,
		   0xd9, 0x80, 0xff, 0x87, 0x6b, 0x32, 0x49, 0x8f) },
    { _mm_set_epi8(0x1f, 0xe1, 0x17, 0x2f, 0x13, 0x9f, 0xb0, 0x85,
		   0xf7, 0xca, 0x31, 0xaa, 0xf3, 0x99, 0xa8, 0x60),
      _mm_set_epi8(0x73, 0x1e, 0x9a, 0xdf, 0xc0, 0x9d, 0x2d, 0x8d,
		   0x56, 0xa7, 0xca, 0xa1, 0x80, 0x0e, 0x8f, 0x3b),
      _mm_set_epi8(0x92, 0xff, 0xb1, 0x0e, 0xd3, 0x3c, 0xdd, 0x12,
		   0x4d, 0x71, 0xfb, 0x4b, 0x73, 0xa7, 0x37, 0x9b) },
    { _mm_set_epi8(0x85, 0x9c, 0xe7, 0x43, 0x6f, 0x7f, 0x1a, 0x80,
		   0xce, 0x88, 0x1d, 0x46, 0x44, 0x73, 0xe1, 0xd7),
      _mm_set_epi8(0x6a, 0x5e, 0x79, 0xca, 0x60, 0xd5, 0xd0, 0xcd,
		   0x9f, 0x0f, 0xc2, 0xcc, 0xcd, 0x00, 0x97, 0x37),
      _mm_set_epi8(0xef, 0xfa, 0x60, 0x0d, 0xcf, 0x54, 0xea, 0x4d,
		   0x6d, 0x97, 0xdf, 0x12, 0x11, 0x73, 0x78, 0x0e) },
    { _mm_set_epi8(0x9d, 0xec, 0x07, 0x00, 0x3a, 0xdc, 0xfb, 0xcc,
		   0xf3, 0x36, 0xe5, 0x07, 0xc3, 0xe6, 0xa1, 0x17),
      _mm_set_epi8(0x2d, 0xbe, 0x44, 0x1c, 0xec, 0xfd, 0x3d, 0x97,
		   0x5d, 0x5b, 0x85, 0xbe, 0x27, 0x35, 0x8d, 0x1f),
      _mm_set_epi8(0xca, 0xaa, 0x4b, 0x1c, 0x26, 0xd9, 0x38, 0x63,
		   0x50, 0x91, 0x6a, 0xc5, 0xea, 0x1b, 0x2e, 0x36) },
    { _mm_set_epi8(0x31, 0x8b, 0xcc, 0x7e, 0x91, 0x8a, 0x17, 0xab,
		   0xd8, 0xa1, 0xe6, 0xa9, 0x39, 0x8b, 0x4d, 0x20),
      _mm_set_epi8(0xf8, 0x50, 0x4f, 0xcf, 0x7c, 0x59, 0x25, 0x48,
		   0x04, 0x09, 0x37, 0xe4, 0x91, 0x2f, 0x4d, 0x72),
      _mm_set_epi8(0x29, 0xdb, 0x1b, 0x4d, 0x0d, 0xe3, 0x3c, 0xf3,
		   0xdc, 0xaa, 0x1d, 0x8d, 0xca, 0xba, 0x9a, 0x92) },
    { _mm_set_epi8(0xff, 0xfb, 0xc0, 0xae, 0xb9, 0x1e, 0x09, 0xe6,
		   0xa1, 0x01, 0xf4, 0xe4, 0x07, 0xed, 0x37, 0x76),
      _mm_set_epi8(0x17, 0x64, 0x65, 0xca, 0xb9, 0xaf, 0xdd, 0xf8,
		   0xc9, 0x16, 0x4a, 0x1c, 0x09, 0x20, 0x3d, 0x38),
      _mm_set_epi8(0x16, 0x5f, 0x25, 0x78, 0x72, 0xcd, 0xe6, 0xde,
		   0x6a, 0x17, 0x3e, 0x00, 0x10, 0x0d, 0x74, 0xae) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m128i r = _mm_add_epi8(test_vec[i].a, test_vec[i].b);
    assert_m128i_epi8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_set_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < 32 ; i++) {
    char a[16];
    __m128i r;

    munit_rand_memory(sizeof(a), (uint8_t*) a);
    r = _mm_set_epi8(a[15], a[14], a[13], a[12], a[11], a[10], a[ 9], a[ 8],
    		     a[ 7], a[ 6], a[ 5], a[ 4], a[ 3], a[ 2], a[ 1], a[ 0]);

    munit_assert_memory_equal(sizeof(a), a, &r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_set_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < 32 ; i++) {
    short a[8];
    __m128i r;

    munit_rand_memory(sizeof(a), (uint8_t*) a);
    r = _mm_set_epi16(a[7], a[6], a[5], a[4], a[3], a[2], a[1], a[0]);

    munit_assert_memory_equal(sizeof(a), a, &r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_set_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < 32 ; i++) {
    int a[4];
    __m128i r;

    munit_rand_memory(sizeof(a), (uint8_t*) a);
    r = _mm_set_epi32(a[3], a[2], a[1], a[0]);

    munit_assert_memory_equal(sizeof(a), a, &r);
  }

  return MUNIT_OK;
}

/*** SSE3 ***/

static MunitTest test_suite_tests[] = {
  { (char*) "/mmx/mm_set_pi8",      test_simd_mm_set_pi8,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_set_pi16",     test_simd_mm_set_pi16,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_set_pi32",     test_simd_mm_set_pi32,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_set1_pi8",     test_simd_mm_set1_pi8,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_set1_pi16",    test_simd_mm_set1_pi16,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_set1_pi32",    test_simd_mm_set1_pi32,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_setr_pi8",     test_simd_mm_setr_pi8,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_setr_pi16",    test_simd_mm_setr_pi16,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_setr_pi32",    test_simd_mm_setr_pi32,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_add_pi8",      test_simd_mm_add_pi8,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_add_pi16",     test_simd_mm_add_pi16,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_add_pi32",     test_simd_mm_add_pi32,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_adds_pi8",     test_simd_mm_adds_pi8,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_adds_pi16",    test_simd_mm_adds_pi16,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_adds_pu8",     test_simd_mm_adds_pu8,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_adds_pu16",    test_simd_mm_adds_pu16,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_and_si64",     test_simd_mm_and_si64,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_andnot_si64",  test_simd_mm_andnot_si64,  NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_cmpeq_pi8",    test_simd_mm_cmpeq_pi8,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_cmpeq_pi16",   test_simd_mm_cmpeq_pi16,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_cmpeq_pi32",   test_simd_mm_cmpeq_pi32,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_cmpgt_pi8",    test_simd_mm_cmpgt_pi8,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_cmpgt_pi16",   test_simd_mm_cmpgt_pi16,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_cmpgt_pi32",   test_simd_mm_cmpgt_pi32,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_cvtm64_si64",  test_simd_mm_cvtm64_si64,  NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_cvtsi32_si64", test_simd_mm_cvtsi32_si64, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_cvtsi64_m64",  test_simd_mm_cvtsi64_m64,  NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_cvtsi64_si32", test_simd_mm_cvtsi64_si32, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_madd_pi16",    test_simd_mm_madd_pi16,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_mulhi_pi16",   test_simd_mm_mulhi_pi16,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_mullo_pi16",   test_simd_mm_mullo_pi16,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_or_si64",      test_simd_mm_or_si64,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_packs_pi16",   test_simd_mm_packs_pi16,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_packs_pi32",   test_simd_mm_packs_pi32,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_packs_pu16",   test_simd_mm_packs_pu16,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_sll_pi16",     test_simd_mm_sll_pi16,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_sll_pi32",     test_simd_mm_sll_pi32,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_sll_si64",     test_simd_mm_sll_si64,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_slli_pi16",    test_simd_mm_slli_pi16,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_slli_pi32",    test_simd_mm_slli_pi32,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_slli_si64",    test_simd_mm_slli_si64,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_srl_pi16",     test_simd_mm_srl_pi16,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_srl_pi32",     test_simd_mm_srl_pi32,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_srl_si64",     test_simd_mm_srl_si64,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_srli_pi16",    test_simd_mm_srli_pi16,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_srli_pi32",    test_simd_mm_srli_pi32,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_srli_si64",    test_simd_mm_srli_si64,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },

  { (char*) "/sse/mm_set_ps",       test_simd_mm_set_ps,       NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_set1_ps",      test_simd_mm_set1_ps,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_add_ps",       test_simd_mm_add_ps,       NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_add_ss",       test_simd_mm_add_ss,       NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_and_ps",       test_simd_mm_and_ps,       NULL, NULL, MUNIT_TEST_OPTION_TODO, NULL },
  { (char*) "/sse/mm_andnot_ps",    test_simd_mm_andnot_ps,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },

  { (char*) "/sse2/mm_set_epi8",    test_simd_mm_set_epi8,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse2/mm_set_epi16",   test_simd_mm_set_epi16,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse2/mm_set_epi32",   test_simd_mm_set_epi32,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse2/mm_add_epi8",    test_simd_mm_add_epi8,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },

  { (char*) "/sse/mm_sub_ps", test_simd_mm_sub_ps, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite test_suite = {
#if defined(TEST_NATIVE)
  (char*) "/native",
#else
  (char*) "/emul",
#endif
  test_suite_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
  return munit_suite_main(&test_suite, NULL, argc, argv);
}