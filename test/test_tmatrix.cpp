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
	int Size1 = 2;
   TMatrix<int> m1(Size1);
   for (int i = 0; i < Size1; i++)
		for (int j = i; j < Size1; j++ )
			m1[i][j] = 1;
	TMatrix<int> m2(m1);
	EXPECT_EQ(m1,m2);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
   TMatrix<int> m1(2);
	TMatrix<int> m2(3);
	EXPECT_NE(&m1[0],&m2[0]);
}

TEST(TMatrix, can_get_size)
{
   int Size1 = 2;
	int tmp = 0;
   TMatrix<int> m1(Size1);
   for (int i = 0; i < Size1; i++)
		for (int j = i; j < Size1; j++ )
			m1[i][j] = 1;
	tmp = m1.GetSize();
	EXPECT_EQ(tmp,Size1);
}

TEST(TMatrix, can_set_and_get_element)
{
   int Size1 = 2;
   TMatrix<int> m1(Size1);
	m1[0][0] = 3;
	EXPECT_EQ(m1[0][0],3);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
   int Size1 = 2;
   TMatrix<int> m1(Size1);
	ASSERT_ANY_THROW(m1[-1][1] = 1);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
  int Size1 = 2;
   TMatrix<int> m1(Size1);
	ASSERT_ANY_THROW(m1[4][1] = 1);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
   int Size1 = 2;
   TMatrix<int> m1(Size1);
   for (int i = 0; i < Size1; i++)
		for (int j = i; j < Size1; j++ )
			m1[i][j] = 1;
	EXPECT_EQ(m1,m1=m1);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
   int Size1 = 2;
   TMatrix<int> m1(Size1), m2(Size1);
   for (int i = 0; i < Size1; i++)
		for (int j = i; j < Size1; j++ )
			m1[i][j] = 1;
	m2 = m1;
	EXPECT_EQ(m1,m2);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
  int Size1 = 2;
   TMatrix<int> m1(Size1), m2(Size1+2);
   for (int i = 0; i < Size1; i++)
		for (int j = i; j < Size1; j++ )
			m1[i][j] = 1;
	m2 = m1;
	EXPECT_EQ(m2.GetSize(),Size1);
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
  int Size1 = 2;
   TMatrix<int> m1(Size1), m2(Size1+10);
   for (int i = 0; i < Size1; i++)
		for (int j = i; j < Size1; j++ )
			m1[i][j] = 1;
	m2 = m1;
	EXPECT_EQ(m1,m2);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	int Size1 = 2;
   TMatrix<int> m1(Size1);
   for (int i = 0; i < Size1; i++)
		for (int j = i; j < Size1; j++ )
			m1[i][j] = 1;
	TMatrix<int> m2(m1);
	EXPECT_EQ(m1 == m2,true);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
   int Size1 = 2;
   TMatrix<int> m1(Size1);
   for (int i = 0; i < Size1; i++)
		for (int j = i; j < Size1; j++ )
			m1[i][j] = 1;
	EXPECT_EQ(m1 == m1,true);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	int Size1 = 2;
   TMatrix<int> m1(Size1),m2(Size1+1);
	EXPECT_EQ(m1 == m2, false);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
   int Size1 = 2;
   TMatrix<int> m1(Size1),m2(Size1),m3(Size1);
   for (int i = 0; i < Size1; i++)
		for (int j = i; j < Size1; j++ )
		{
			m1[i][j] = 1;
			m2[i][j] = 2;
			m3[i][j] = 3;
		}
	EXPECT_EQ(m1+m2,m3);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
   int Size1 = 2;
   TMatrix<int> m1(Size1),m2(Size1+1);
	EXPECT_ANY_THROW(m1+m2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
  int Size1 = 2;
   TMatrix<int> m1(Size1),m2(Size1),m3(Size1);
   for (int i = 0; i < Size1; i++)
		for (int j = i; j < Size1; j++ )
		{
			m1[i][j] = 1;
			m2[i][j] = 2;
			m3[i][j] = 3;
		}
	EXPECT_EQ(m3-m2,m1);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
  int Size1 = 2;
   TMatrix<int> m1(Size1),m2(Size1+1);
	EXPECT_ANY_THROW(m1-m2);
}

