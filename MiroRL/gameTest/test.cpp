#include "pch.h"

#include "../MiroRL/Miro.h"
#include "../MiroRL/Ai.h"
#include "../MiroRL/Tool.h"

TEST(MiroTest, Move) {
  //  Ai* agent = new Ai();
  //  Miro* e1 = new Miro(agent);
  //  e1->move(UP);
  //  e1->move(UP);
  //  e1->move(UP);
  //  e1->move(UP);
	
  //EXPECT_EQ(e1->m_player_x, 0);
  //EXPECT_EQ(e1->m_player_y, 4);

	Ai ai = Ai();
}
//
//TEST(MiroTest, getReward)
//{
//    Ai* agent = new Ai();
//    Miro* e = new Miro(agent);
//    e->move(UP);
//    e->move(RIGHT);
//    e->move(RIGHT);
//    EXPECT_EQ(e->getReward(), 3);
//    e->move(LEFT);
//    EXPECT_EQ(e->getReward(), -2);
//}

//TEST(Position, oldPosition)
//{
//    XY* old = Positon::old(new XY(1, 1), RIGHT);
//
//    EXPECT_EQ(old->x, 0);
//    EXPECT_EQ(old->y, 1);
//}