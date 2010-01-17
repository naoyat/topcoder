#include <gtest/gtest.h>
#include "dijkstra.cc"

TEST(dijkstra1,int)
{
  vector<vector<int> > arclength(8, vector<int>(8, infty));
  arclength[0][1] = 3; arclength[0][2] = 5;
  arclength[1][2] = 1; arclength[1][3] = 10; arclength[1][4] = 11;
  arclength[2][1] = 3; arclength[2][3] = 2; arclength[2][4] = 3;
  arclength[3][4] = 2; arclength[3][5] = 7; arclength[3][6] = 12;
  arclength[4][1] = 15; arclength[4][2] = 2; arclength[4][6] = 2;
  arclength[5][4] = 11; arclength[5][7] = 2;
  arclength[6][5] = 3; arclength[6][7] = 2;

  int ans_expected_[] = { 0,1,2,4,6,7 };
  pair<list<int>,int> ans_expected
      = make_pair( list<int>(ans_expected_,
                             ans_expected_+sizeof(ans_expected_)/sizeof(*ans_expected_)),
                   11 );
  pair<list<int>,int> ans_actual = dijkstra1(arclength, 0, 7);
  EXPECT_EQ( ans_expected, ans_actual );
}

TEST(dijkstra1,double)
{
  vector<vector<double> > arclength(8, vector<double>(8, infty));
  arclength[0][1] = 3; arclength[0][2] = 5;
  arclength[1][2] = 1; arclength[1][3] = 10; arclength[1][4] = 11;
  arclength[2][1] = 3; arclength[2][3] = 2; arclength[2][4] = 3;
  arclength[3][4] = 2; arclength[3][5] = 7; arclength[3][6] = 12;
  arclength[4][1] = 15; arclength[4][2] = 2; arclength[4][6] = 2;
  arclength[5][4] = 11; arclength[5][7] = 2;
  arclength[6][5] = 3; arclength[6][7] = 2;

  int ans_expected_[] = { 0,1,2,4,6,7 };
  pair<list<int>,double> ans_expected
      = make_pair( list<int>(ans_expected_,
                             ans_expected_+sizeof(ans_expected_)/sizeof(*ans_expected_)),
                   11.0 );
  pair<list<int>,double> ans_actual = dijkstra1(arclength, 0, 7);
  EXPECT_EQ( ans_expected, ans_actual );
}


TEST(dijkstra,int)
{
  vector<vector<int> > arclength(8, vector<int>(8, infty));
  arclength[0][1] = 3; arclength[0][2] = 5;
  arclength[1][2] = 1; arclength[1][3] = 10; arclength[1][4] = 11;
  arclength[2][1] = 3; arclength[2][3] = 2; arclength[2][4] = 3;
  arclength[3][4] = 2; arclength[3][5] = 7; arclength[3][6] = 12;
  arclength[4][1] = 15; arclength[4][2] = 2; arclength[4][6] = 2;
  arclength[5][4] = 11; arclength[5][7] = 2;
  arclength[6][5] = 3; arclength[6][7] = 2;

  int ans_expected_0_[] = { 0 };
  int ans_expected_1_[] = { 0,1 };
  int ans_expected_2_[] = { 0,1,2 };
  int ans_expected_3_[] = { 0,1,2,3 };
  int ans_expected_4_[] = { 0,1,2,4 };
  int ans_expected_5_[] = { 0,1,2,4,6,5 };
  int ans_expected_6_[] = { 0,1,2,4,6 };
  int ans_expected_7_[] = { 0,1,2,4,6,7 };
  list<int> ans_expected_0(ans_expected_0_,
                           ans_expected_0_+sizeof(ans_expected_0_)/sizeof(*ans_expected_0_));
  list<int> ans_expected_1(ans_expected_1_,
                           ans_expected_1_+sizeof(ans_expected_1_)/sizeof(*ans_expected_1_));
  list<int> ans_expected_2(ans_expected_2_,
                           ans_expected_2_+sizeof(ans_expected_2_)/sizeof(*ans_expected_2_));
  list<int> ans_expected_3(ans_expected_3_,
                           ans_expected_3_+sizeof(ans_expected_3_)/sizeof(*ans_expected_3_));
  list<int> ans_expected_4(ans_expected_4_,
                           ans_expected_4_+sizeof(ans_expected_4_)/sizeof(*ans_expected_4_));
  list<int> ans_expected_5(ans_expected_5_,
                           ans_expected_5_+sizeof(ans_expected_5_)/sizeof(*ans_expected_5_));
  list<int> ans_expected_6(ans_expected_6_,
                           ans_expected_6_+sizeof(ans_expected_6_)/sizeof(*ans_expected_6_));
  list<int> ans_expected_7(ans_expected_7_,
                           ans_expected_7_+sizeof(ans_expected_7_)/sizeof(*ans_expected_7_));

  vector<pair<list<int>,int> > ans_actual_all = dijkstra(arclength, 0);

  EXPECT_EQ( make_pair(ans_expected_0, 0), ans_actual_all[0] );
  EXPECT_EQ( make_pair(ans_expected_1, 3), ans_actual_all[1] );
  EXPECT_EQ( make_pair(ans_expected_2, 4), ans_actual_all[2] );
  EXPECT_EQ( make_pair(ans_expected_3, 6), ans_actual_all[3] );
  EXPECT_EQ( make_pair(ans_expected_4, 7), ans_actual_all[4] );
  EXPECT_EQ( make_pair(ans_expected_5,12), ans_actual_all[5] );
  EXPECT_EQ( make_pair(ans_expected_6, 9), ans_actual_all[6] );
  EXPECT_EQ( make_pair(ans_expected_7,11), ans_actual_all[7] );
}

TEST(prim,int)
{
  vector<vector<int> > arclength(8, vector<int>(8, infty));
  arclength[0][1] = 3; arclength[0][2] = 5;
  arclength[1][2] = 1; arclength[1][3] = 10; arclength[1][4] = 11;
  arclength[2][3] = 2; arclength[2][4] = 3;
  arclength[3][4] = 2; arclength[3][5] = 7; arclength[3][6] = 12;
  arclength[4][5] = 11; arclength[4][6] = 2;
  arclength[5][6] = 3; arclength[5][7] = 2;
  arclength[6][7] = 2;

  int ans_expected_[] = { -1, 0, 1, 2, 3, 7, 4, 6 }; // predecessor[]
  vector<int> ans_expected(ans_expected_,
                           ans_expected_+sizeof(ans_expected_)/sizeof(*ans_expected_));
  EXPECT_EQ( ans_expected, prim(arcs_to_edges(arclength),0) );
}

///
int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}

