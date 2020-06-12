#include "pch.h"

#include "../MiroRL/Miro.h"


TEST(MiroTest, Move) {

    Miro* e1 = new Miro();
    e1->move(UP);
    e1->move(UP);
    e1->move(UP);
    e1->move(UP);
	
  EXPECT_EQ(e1->m_player_x, 0);
  EXPECT_EQ(e1->m_player_y, 4);

}

TEST(MiroTest, getReward)
{
    Miro* e = new Miro();
    e->move(UP);
    e->move(RIGHT);
    e->move(RIGHT);
    EXPECT_EQ(e->getReward(), 3);
    e->move(LEFT);
    EXPECT_EQ(e->getReward(), -2);
}