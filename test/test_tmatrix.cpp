#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> m(5);
	TMatrix<int> w(9);
	 w = m;
  EXPECT_EQ (m,w);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
  TMatrix<int> m(5);
	TMatrix<int> w(9);
	 w = m;
	 m[0][1] = 11;
  EXPECT_NE (m,w);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(5);
  ASSERT_NO_THROW(m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
  TMatrix<int> m(5);
  m[2][4] = 8;
  EXPECT_EQ(8, m[2][4]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(5);
ASSERT_ANY_THROW(m[-1][-1]);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
  TMatrix<int> m(5);
ASSERT_ANY_THROW(m[6][6]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
  TMatrix<int> m(5);
  TMatrix<int> t(m);
  m = t;
  EXPECT_EQ(m,t);

}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
  TMatrix<int> m(5);
  TMatrix<int> t(5);
  m = t;
  EXPECT_EQ(m,t);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
  TMatrix<int> m(5);
  TMatrix<int> t(7);
  m = t;
  EXPECT_EQ (7,m.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
  TMatrix<int> m(5);
  TMatrix<int> t(7);
  m = t;
  EXPECT_EQ(m,t);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
  TMatrix<int> m(5);
  TMatrix<int> t(7);
  m = t;
  EXPECT_EQ(m==t, true);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
  TMatrix<int> m(5);
 
  EXPECT_EQ(m == m, true);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
  TMatrix<int> m(5);
  TMatrix<int> t(7);
  EXPECT_EQ(m == t, false);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
  TMatrix<int> m(3);
  TMatrix<int> t(3);
  TMatrix<int> res(3);
  m[0][0] = m [1][1] = m[2][2] = 1;
  t[0][0] = t [1][1] = t[2][2] = 1;
  res[0][0] = res [1][1] = res [2][2] = 2;
  EXPECT_EQ(m+t, res);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
  TMatrix<int> m(3);
  TMatrix<int> t(7);
  ASSERT_ANY_THROW(m+t);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
  TMatrix<int> m(3);
  TMatrix<int> t(3);
  TMatrix<int> res(3);
  m[0][0] = m [1][1] = m[2][2] = 1;
  t[0][0] = t [1][1] = t[2][2] = 1;
  res[0][0] = res [1][1] = res [2][2] = 2;
 

  EXPECT_EQ(m, res - t);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
  TMatrix<int> m(3);
  TMatrix<int> t(7);
  ASSERT_ANY_THROW(m-t);
}

