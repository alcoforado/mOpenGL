#ifndef TESTSELECTOR_H
#define TESTSELECTOR_H

#include <gtest/gtest.h>
#include <framework/ArraySelect.h>
#include <framework/Vector2.h>
#include <framework/Vector4.h>
class ArraySelectTest: public testing::Test
{
public:
    struct VerticeData {
        Vector4 Position;
        Vector2 TexCoord;
        int a;
    };

    struct VerticeData2 {
        float a;
        int b;
        float c;
    };



    std::vector<VerticeData> m_v;
    std::vector<VerticeData2> m_v2;

    virtual void SetUp()
    {
       m_v.push_back({{1,2,3,4},{1,2},33});
       m_v.push_back({{5,6,7,8},{9,10},34});

        m_v2.push_back({1.0,2,3.0});
        m_v2.push_back({4.0,5,6.0});



    }

};

TEST_F(ArraySelectTest,GetSetSelectVector4MemberTestPositionReading)
{
    ArraySelect<Vector4> select(m_v,&VerticeData::Position);

    EXPECT_EQ(select[0].x,m_v[0].Position.x);
    EXPECT_EQ(select[0].y,m_v[0].Position.y);
    EXPECT_EQ(select[0].z,m_v[0].Position.z);
    EXPECT_EQ(select[0].w,m_v[0].Position.w);

    EXPECT_EQ(select[1].x,m_v[1].Position.x);
    EXPECT_EQ(select[1].y,m_v[1].Position.y);
    EXPECT_EQ(select[1].z,m_v[1].Position.z);
    EXPECT_EQ(select[1].w,m_v[1].Position.w);



    EXPECT_EQ(m_v.size()  ,2);
    EXPECT_EQ(select.size(),2);


}


TEST_F(ArraySelectTest,GetSetSelectVector4MemberTestPositionWritting)
{
    ArraySelect<Vector4> select(m_v,&VerticeData::Position);


    select[0]=Vector4(31,32,33,34);
    select[1]=Vector4(41,42,43,44);

    EXPECT_EQ(31,m_v[0].Position.x);
    EXPECT_EQ(32,m_v[0].Position.y);
    EXPECT_EQ(33,m_v[0].Position.z);
    EXPECT_EQ(34,m_v[0].Position.w);


    EXPECT_EQ(41,m_v[1].Position.x);
    EXPECT_EQ(42,m_v[1].Position.y);
    EXPECT_EQ(43,m_v[1].Position.z);
    EXPECT_EQ(44,m_v[1].Position.w);


}



TEST_F(ArraySelectTest,GetSetSelectTestIntMemberB)
{
    ArraySelect<int> select(m_v2,&VerticeData2::b);

    EXPECT_EQ(select[0],m_v2[0].b);
    EXPECT_EQ(select[1],m_v2[1].b);

    select[0]=20;
    select[1]=30;

    EXPECT_EQ(m_v2[0].b,20);
    EXPECT_EQ(m_v2[1].b,30);


    EXPECT_EQ(m_v2.size()  ,2);
    EXPECT_EQ(select.size(),2);

}

TEST_F(ArraySelectTest,GetSetSelectTestFloatMemberC)
{
    ArraySelect<float> select(m_v2,&VerticeData2::c);

    EXPECT_EQ(select[0],m_v2[0].c);
    EXPECT_EQ(select[1],m_v2[1].c);

    select[0]=20;
    select[1]=30;

    EXPECT_EQ(m_v2[0].c,20);
    EXPECT_EQ(m_v2[1].c,30);


    EXPECT_EQ(m_v2.size()  ,2);
    EXPECT_EQ(select.size(),2);

}






TEST(MathTest, TwoPlusTwoEqualsFour) {
  EXPECT_EQ(4, 2 + 2);
}



#endif // TESTSELECTOR_H
