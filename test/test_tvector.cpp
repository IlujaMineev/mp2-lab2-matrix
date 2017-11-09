#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
	ASSERT_NO_THROW(TVector<int> a(3,0));
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
	int Size = 3;
   TVector<int> a(Size);
   for (int i=0; i<Size; i++)
		a[i] = i+1;
	TVector<int> b(a);
	EXPECT_EQ(a,b);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
  TVector<int> a(3);
  TVector<int> b(a);
  EXPECT_NE(&a[0],&b[0]);
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
  TVector<int> a(3);
  ASSERT_ANY_THROW(a[-3]);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
  TVector<int> a(3);
  ASSERT_ANY_THROW(a[5]);
}

TEST(TVector, can_assign_vector_to_itself)
{
   int Size = 3;
   TVector<int> a(Size);
   for (int i=0; i<Size; i++)
		a[i] = i+1;
	a = a;
	EXPECT_EQ(a,a);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	int Size = 3;
   TVector<int> a(Size),b(Size);
   for (int i=0; i<Size; i++)
		a[i] = i+1;
	b = a;
	EXPECT_EQ(a,b);
}

TEST(TVector, assign_operator_change_vector_size)
{
  int Size = 3;
   TVector<int> a(Size),b(10);
   for (int i=0; i<Size; i++)
		a[i] = i+1;
	b = a;
	EXPECT_EQ(Size,b.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
  int Size = 3;
   TVector<int> a(Size),b(10);
   for (int i=0; i<Size; i++)
		a[i] = i+1;
	b = a;
	EXPECT_EQ(a,b);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	int Size = 3;
   TVector<int> a(Size),b(Size);
   for (int i=0; i<Size; i++)
		a[i] = i+1;
	b = a;
   EXPECT_TRUE(a == b);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
   int Size = 3;
   TVector<int> a(Size);
   for (int i=0; i<Size; i++)
		a[i] = i+1;
   EXPECT_TRUE(a == a);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
   int Size1 = 3, Size2 = 4;
   TVector<int> v1(Size1),v2(Size2);
	EXPECT_FALSE(v1 == v2);
}

TEST(TVector, can_add_scalar_to_vector)
{
	int s=0;
	int Size1 = 2;
   TVector<int> v1(Size1);
	v1[0] = 1;
	v1[1] = 1;
	v1 = v1 + 1;
	for (int i=0; i<Size1; i++)
		s = s + v1[i];
   EXPECT_EQ(s,4);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
   int Size1 = 2;
	int s=0;
   TVector<int> v1(Size1);
	v1[0] = 2;
	v1[1] = 2;
	v1 = v1 - 1;
	for (int i=0; i<Size1; i++)
		s += v1[i];
   EXPECT_EQ(s,2);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
   int Size1 = 2;
	int s=0;
   TVector<int> v1(Size1);
	v1[0] = 1;
	v1[1] = 1;
	v1 = v1 * 2;
	for (int i=0; i<Size1; i++)
		s += v1[i];
   EXPECT_EQ(s,4);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
   int Size1 = 3, Size2 = 4;
	int s=0;
   TVector<int> v1(Size1),v2(Size1);
   for (int i=0; i<Size1; i++)
	{
		v1[i] = 2;
		v2[i] = 1;
	}
	v1 = v1 + v2;
	for (int i=0; i<Size1; i++)
		s += v1[i];
	EXPECT_EQ(s,9);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
   int Size1 = 3, Size2 = 4;
   TVector<int> v1(Size1),v2(Size2);
   for (int i=0; i<Size1; i++)
	{
		v1[i] = 2;
		v2[i] = 1;
	}
	v2[3] = 1;
	EXPECT_ANY_THROW(v1 + v2);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
  int Size1 = 3, Size2 = 4;
  int s=0;
   TVector<int> v1(Size1),v2(Size1);
   for (int i=0; i<Size1; i++)
	{
		v1[i] = 2;
		v2[i] = 1;
	}
	v1 = v1 - v2;
	for (int i=0; i<Size1; i++)
		s += v1[i];
	EXPECT_EQ(s,3);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
  int Size1 = 3, Size2 = 4;
   TVector<int> v1(Size1),v2(Size2);
   for (int i=0; i<Size1; i++)
	{
		v1[i] = 2;
		v2[i] = 1;
	}
	v2[3] = 1;
	EXPECT_ANY_THROW(v1 - v2);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
  int Size1 = 3, Size2 = 4;
  int s=0;
   TVector<int> v1(Size1),v2(Size1);
   for (int i=0; i<Size1; i++)
	{
		v1[i] = 2;
		v2[i] = 1;
	}
	s = v1 * v2;
	EXPECT_EQ(s,6);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
  int Size1 = 3, Size2 = 4;
   TVector<int> v1(Size1),v2(Size2);
   for (int i=0; i<Size1; i++)
	{
		v1[i] = 2;
		v2[i] = 1;
	}
	v2[3] = 1;
	EXPECT_ANY_THROW(v1 * v2);
}

