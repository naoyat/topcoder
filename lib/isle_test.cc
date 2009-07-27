using namespace std;

#include "cout.h"

#include "isle.h"
#include <gtest/gtest.h>

TEST(test, 1)
{
  string g_[] = {"N"};
  vector<string> g(g_, g_+sizeof(g_)/sizeof(*g_));

  int id_[] = {0};
  vector<int> id_expected(id_, id_+sizeof(id_)/sizeof(*id_));
  vector<int> id_result = isle(g);
  // cout << id_result << endl;
  EXPECT_EQ( id_expected, id_result );

  map<int,int> id_summary_expected;
  id_summary_expected[0] = 1;
  map<int,int> id_summary_result = summary(id_result);
  // cout << id_summary_result << endl;
  EXPECT_EQ( id_summary_expected, id_summary_result );
}

TEST(test, 2_no_connection)
{
  string g_[] = {"NN",
                 "NN"};
  vector<string> g(g_, g_+sizeof(g_)/sizeof(*g_));

  int id_[] = {0,1};
  vector<int> id_expected(id_, id_+sizeof(id_)/sizeof(*id_));
  vector<int> id_result = isle(g);
  // cout << id_result << endl;
  EXPECT_EQ( id_expected, id_result );

  map<int,int> id_summary_expected;
  id_summary_expected[0] = id_summary_expected[1] = 1;
  map<int,int> id_summary_result = summary(id_result);
  EXPECT_EQ( id_summary_expected, id_summary_result );
}

TEST(test, 2_connected)
{
  string g_[] = {"NY",
                 "YN"};
  vector<string> g(g_, g_+sizeof(g_)/sizeof(*g_));

  int id_[] = {0,0};
  vector<int> id_expected(id_, id_+sizeof(id_)/sizeof(*id_));
  vector<int> id_result = isle(g);
  // cout << id_result << endl;
  EXPECT_EQ( id_expected, id_result );

  map<int,int> id_summary_expected;
  id_summary_expected[0] = 2;
  map<int,int> id_summary_result = summary(id_result);
  EXPECT_EQ( id_summary_expected, id_summary_result );
}

TEST(test, 5)
{
  string g_[] = {"NYYNN",
                 "YNYNN",
                 "YYNNN",
                 "NNNNY",
                 "NNNYN"};
  vector<string> g(g_, g_+sizeof(g_)/sizeof(*g_));

  int id_[] = {0,0,0,3,3};
  vector<int> id_expected(id_, id_+sizeof(id_)/sizeof(*id_));
  vector<int> id_result = isle(g);
  // cout << isle(g) << endl;
  EXPECT_EQ( id_expected, id_result );

  map<int,int> id_summary_expected;
  id_summary_expected[0] = 3; id_summary_expected[3] = 2;
  map<int,int> id_summary_result = summary(id_result);
  EXPECT_EQ( id_summary_expected, id_summary_result );
}

TEST(test, 7)
{
  string g_[] = {"NYYNNNN",
                 "YNYNNNN",
                 "YYNNNNN",
                 "NNNNYYN",
                 "NNNYNYY",
                 "NNNYYNY",
                 "NNNNYYN"};
  vector<string> g(g_, g_+sizeof(g_)/sizeof(*g_));

  int id_[] = {0,0,0,3,3,3,3};
  vector<int> id_expected(id_, id_+sizeof(id_)/sizeof(*id_));
  vector<int> id_result = isle(g);
  // cout << isle(g) << endl;
  EXPECT_EQ( id_expected, id_result );

  map<int,int> id_summary_expected;
  id_summary_expected[0] = 3; id_summary_expected[3] = 4;
  map<int,int> id_summary_result = summary(id_result);
  EXPECT_EQ( id_summary_expected, id_summary_result );
}

TEST(test, 12)
{
  string g_[] = {"NYNYNNNNNNNN",
                 "YNYNNNNNNNNN",
                 "NYNYYNNNNNNN",
                 "YNYNNNNNNNNN",
                 "NNYNNYYNNNNN",
                 "NNNNYNYNNNNN",
                 "NNNNYYNNNNNN",
                 "NNNNNNNNYYNN",
                 "NNNNNNNYNYNN",
                 "NNNNNNNYYNNN",
                 "NNNNNNNNNNNY",
                 "NNNNNNNNNNYN"};
  vector<string> g(g_, g_+sizeof(g_)/sizeof(*g_));

  int id_[] = {0,0,0,0,0,0,0,7,7,7,10,10};
  vector<int> id_expected(id_, id_+sizeof(id_)/sizeof(*id_));
  vector<int> id_result = isle(g);
  // cout << isle(g) << endl;
  EXPECT_EQ( id_expected, id_result );

  map<int,int> id_summary_expected;
  id_summary_expected[0] = 7; id_summary_expected[7] = 3; id_summary_expected[10] = 2;
  map<int,int> id_summary_result = summary(id_result);
  EXPECT_EQ( id_summary_expected, id_summary_result );
}

TEST(test, 6)
{
  string g_[] ={"NYNNNN",
                "YNYNNN",
                "NYNYNN",
                "NNYNNN",
                "NNNNNY",
                "NNNNYN"};
  vector<string> g(g_, g_+sizeof(g_)/sizeof(*g_));

  int id_[] = {0,0,0,0,4,4};
  vector<int> id_expected(id_, id_+sizeof(id_)/sizeof(*id_));
  vector<int> id_result = isle(g);
  // cout << isle(g) << endl;
  EXPECT_EQ( id_expected, id_result );

  map<int,int> id_summary_expected;
  id_summary_expected[0] = 4; id_summary_expected[4] = 2;
  map<int,int> id_summary_result = summary(id_result);
  EXPECT_EQ( id_summary_expected, id_summary_result );
}

TEST(test, 42)
{
  string g_[] = {"NNNNNNNNNNNNNNNYNNNNNNNYNNYNNNNNNNNNNNNNNN",
                 "NNNNNNNNNNNYNNNNNNNNNNNNNNNNNNYNNNNNNNNNNN",
                 "NNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
                 "NNNNNNNNNNNYNNNNNNNNNNNNNNNNNNYNNNNNYNNNNN",
                 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNN",
                 "NNNNNNNNNNNNNNYNYNNNNNNNNNNNNNNNNNNNNNNNNY",
                 "NNNNNNNNNYYNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNN",
                 "NNYNNNNNNNNNNNNNNYNNNNNNNNNYNNNNNNNNNNNNNN",
                 "NNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNN",
                 "NNNNNNYNNNYNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNN",
                 "NNNNNNYNNYNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNN",
                 "NYNYNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNYNNNNN",
                 "NNNNNNNNNNNNNYNNNNYNNNNNNNNNNNNNNNNNNNNYNN",
                 "NNNNNNNNNNNNYNNNNNYNNNNNNNNNNNNNNNNNNNNYNN",
                 "NNNNNYNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNY",
                 "YNNNNNNNNNNNNNNNNNNNNNNYNNYNNNNNNNNNNNNNNN",
                 "NNNNNYNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNY",
                 "NNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
                 "NNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNYNNNYNN",
                 "NNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNYNNNN",
                 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNYNNNNNNNNNN",
                 "NNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNYNNN",
                 "NNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNN",
                 "YNNNNNNNNNNNNNNYNNNNNNNNNNYNNNNNNNNNNNNNNN",
                 "NNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNYNNNNNNNN",
                 "NNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNN",
                 "YNNNNNNNNNNNNNNYNNNNNNNYNNNNNNNNNNNNNNNNNN",
                 "NNNNNNNYYNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNN",
                 "NNNNNNYNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
                 "NNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNN",
                 "NYNYNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNYNNNNN",
                 "NNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNYNYNNNNNYN",
                 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNN",
                 "NNNNYNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNN",
                 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNN",
                 "NNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNN",
                 "NNNYNNNNNNNYNNNNNNNNNNNNNNNNNNYNNNNNNNNNNN",
                 "NNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNN",
                 "NNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNN",
                 "NNNNNNNNNNNNYYNNNNYNNNNNNNNNNNNNNNNNNNNNNN",
                 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNN",
                 "NNNNNYNNNNNNNNYNYNNNNNNNNNNNNNNNNNNNNNNNNN"};
  vector<string> g(g_, g_+sizeof(g_)/sizeof(*g_));

  int id_[] = { 0, 1, 2, 1, 4, 5, 6, 2, 2, 6, 6, 1, 12, 12, 5, 0, 5, 2, 12, 19, 20, 19, 4, 0, 4, 2, 0, 2, 6, 20, 1, 20, 20, 4, 20, 12, 1, 19, 19, 12, 20, 5 };
  vector<int> id_expected(id_, id_+sizeof(id_)/sizeof(*id_));
  vector<int> id_result = isle(g);
  // cout << isle(g) << endl;
  EXPECT_EQ( id_expected, id_result );

  map<int,int> id_summary_expected;
  id_summary_expected[0] = id_summary_expected[4] = id_summary_expected[5] = id_summary_expected[6] = id_summary_expected[19] = 4;
  id_summary_expected[1] = id_summary_expected[12] = 5;
  id_summary_expected[2] = id_summary_expected[20] = 6;
  map<int,int> id_summary_result = summary(id_result);
  EXPECT_EQ( id_summary_expected, id_summary_result );
}

TEST(test, 40)
{
  string g_[] = {"NNNNNNNNNNNNYNNNNNNNNNNYNNNYNNNNNNNNNNNN",
                 "NNYNNNNNNNNNNNYNNNNNYNNNNNNNNNNNNNNNNNNN",
                 "NYNNNNNNNNNNNNYNNNNNYNNNNNNNNNNNNNNNNNNN",
                 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNN",
                 "NNNNNNNYNNNNNNNYNNNNNNNNYNNNNNNNNNNNYNNN",
                 "NNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
                 "NNNNNNNNNNYNNNNNNNNNNNNNNNYNNNNNNNNNNYNN",
                 "NNNNYNNNNNNNNNNYNNNNNNNNYNNNNNNNNNNNYNNN",
                 "NNNNNYNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNN",
                 "NNNNNNNNNNNYNNNNNYNNNNNNNNNNNNNNNNNNNNYN",
                 "NNNNNNYNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNYNN",
                 "NNNNNNNNNYNNNNNNNYNNNNNNNNNNNNNNNNNNNNYN",
                 "YNNNNNNNNNNNNNNNNNNNNNNYNNNYNNNNNNNNNNNN",
                 "NNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNYNNNNY",
                 "NYYNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNN",
                 "NNNNYNNYNNNNNNNNNNNNNNNNYNNNNNNNNNNNYNNN",
                 "NNNNNNNNYNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNN",
                 "NNNNNNNNNYNYNNNNNNNNNNNNNNNNNNNNNNNNNNYN",
                 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNYNNNNNNN",
                 "NNNNNNNNNNNNNNNNYNNNNNNNNYNNNNNNNNNNNNNN",
                 "NYYNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNN",
                 "NNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNYNNNNY",
                 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNN",
                 "YNNNNNNNNNNNYNNNNNNNNNNNNNNYNNNNNNNNNNNN",
                 "NNNNYNNYNNNNNNNYNNNNNNNNNNNNNNNNNNNNYNNN",
                 "NNNNNNNNNNNNNNNNNNNYNNNNNNNNNNYNNNNYNNNN",
                 "NNNNNNYNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNYNN",
                 "YNNNNNNNNNNNYNNNNNNNNNNYNNNNNNNNNNNNNNNN",
                 "NNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNYNNNNNN",
                 "NNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNN",
                 "NNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNN",
                 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNN",
                 "NNNYNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNN",
                 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNYNNNNNNNN",
                 "NNNNNNNNNNNNNYNNNNNNNYNNNNNNNNNNNNNNNNNY",
                 "NNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNN",
                 "NNNNYNNYNNNNNNNYNNNNNNNNYNNNNNNNNNNNNNNN",
                 "NNNNNNYNNNYNNNNNNNNNNNNNNNYNNNNNNNNNNNNN",
                 "NNNNNNNNNYNYNNNNNYNNNNNNNNNNNNNNNNNNNNNN",
                 "NNNNNNNNNNNNNYNNNNNNNYNNNNNNNNNNNNYNNNNN"};
  vector<string> g(g_, g_+sizeof(g_)/sizeof(*g_));

  int id_[] = { 0, 1, 1, 3, 4, 5, 6, 4, 5, 9, 6, 9, 0, 13, 1, 4, 5, 9, 3, 5, 1, 13, 22, 0, 4, 5, 6, 0, 22, 3, 5, 22, 3, 22, 13, 5, 4, 6, 9, 13 };
  vector<int> id_expected(id_, id_+sizeof(id_)/sizeof(*id_));
  vector<int> id_result = isle(g);
  // cout << isle(g) << endl;
  EXPECT_EQ( id_expected, id_result );

  map<int,int> id_summary_expected;
  id_summary_expected[0] = id_summary_expected[1] = id_summary_expected[3] = id_summary_expected[6] = id_summary_expected[9] = id_summary_expected[13] = id_summary_expected[22] = 4;
  id_summary_expected[4] = 5; id_summary_expected[5] = 7;
  map<int,int> id_summary_result = summary(id_result);
  EXPECT_EQ( id_summary_expected, id_summary_result );
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
