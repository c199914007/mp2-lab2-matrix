#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int> v(10);
	v[0] = 6;

	TVector<int> d(v);
  EXPECT_EQ(d , v);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
  TVector<int> v(10);
	TVector<int> d(v);

	v[5] = 9;
  EXPECT_NE(d[5] , v[5]);
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
  TVector<int> v(4);
  ASSERT_ANY_THROW( v[-1]);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	 TVector<int> v(4);
	 ASSERT_ANY_THROW( v [6]);
}

TEST(TVector, can_assign_vector_to_itself)
{
	 TVector<int> v(4);
	 v[2] = 40;
	  TVector<int> t(v);
	  v = t;
  EXPECT_EQ(v, t);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
  TVector<int> v(4);
	 v[2] = 40;
	  TVector<int> t(4);
	  v = t;
  EXPECT_EQ(v, t);
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> v(4);
   TVector<int> f(6);
   v = f;
   EXPECT_EQ(6, v.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
  TVector<int> v(4);
   TVector<int> f(10);

   v[2] = 9;
   f[2] = 10;
   v = f;
   EXPECT_EQ(v,f);
}

TEST(TVector, compare_equal_vectors_return_true)
{
  TVector<int> v(4);
   TVector<int> f(4);
  
   EXPECT_EQ(true, v==f);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
  TVector<int> v(4);
   
   EXPECT_EQ(true, v==v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
  TVector<int> v(4);
   TVector<int> f(6);
  
   EXPECT_EQ(false, v==f);
}

TEST(TVector, can_add_scalar_to_vector)
{
  TVector<int> v(4);
  v = v+6;
  TVector<int> f(4);
  f[0] = f[1] = f[2] = f[3] = 6;
   EXPECT_EQ(v,f);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
  TVector<int> v(4);
  v = v+6;
  v = v - 6;
  TVector<int> f(4);
  f[0] = f[1] = f[2] = f[3] = 0;
   EXPECT_EQ(v,f);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
 TVector<int> v(4);
 v[0] = v[1] = v[2] = v[3] = 1;
  v = v*6;
  TVector<int> f(4);
  f[0] = f[1] = f[2] = f[3] = 6;
   EXPECT_EQ(v,f);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
  TVector<int> v(4);
 v[0] = v[1] = v[2] = v[3] = 1;
  TVector<int> f(4);
  f[0] = f[1] = f[2] = f[3] = 6;
  TVector<int> res(4);
  v=v+f;
  res[0] = res[1] = res[2] = res[3] = 7;

   EXPECT_EQ(v, res);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> v(4);
  TVector<int> g(8);
  ASSERT_ANY_THROW(v+g);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
  TVector<int> v(4);
 v[0] = v[1] = v[2] = v[3] = 1;
  TVector<int> f(4);
  f[0] = f[1] = f[2] = f[3] = 6;
  TVector<int> res(4);
  res[0] = res[1] = res[2] = res[3] = 7;

  res = res - f;
   EXPECT_EQ(res , v);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
  TVector<int> v(4);
  TVector<int> g(8);
  ASSERT_ANY_THROW(v-g);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
  TVector<int> v(4);
 v[0] = v[1] = v[2] = v[3] = 1;
  TVector<int> f(4);
  f[0] = f[1] = f[2] = f[3] = 6;
  int res = 24;

   EXPECT_EQ(v*f, res);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
  TVector<int> v(4);
  TVector<int> g(8);
  ASSERT_ANY_THROW(v*g);
}
