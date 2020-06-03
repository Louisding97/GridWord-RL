#include "pch.h"
#include "../MiroRL/MiroRL.h"


TEST(MiroTest, Move) {

    Environment* e1 = new Environment();
    e1->move(UP);
    e1->move(UP);
    e1->move(UP);
    e1->move(UP);
	
  EXPECT_EQ(e1->m_player_x, 0);
  EXPECT_EQ(e1->m_player_y, 4);

}

TEST(MiroTest, getReward)
{
    Environment* e = new Environment();
    e->move(UP);
    e->move(RIGHT);
    e->move(RIGHT);
    EXPECT_EQ(e->getReward(), 3);
    e->move(LEFT);
    EXPECT_EQ(e->getReward(), -2);

}