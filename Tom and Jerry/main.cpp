#include "System.h"
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"


TEST_CASE("Drone test")
{
    Drone d;

    CHECK(d.getRoom().size() == d.getRoomLenght());
    CHECK(d.getRoom()[0].size() == d.getRoomWidth());

    CHECK(d.getRoomLenght() >= d.getCurrPos().x); 
    CHECK(d.getRoomLenght() >= d.getGoalPos().x);
    CHECK(d.getRoomWidth() >= d.getCurrPos().y); 
    CHECK(d.getRoomWidth() >= d.getGoalPos().y);

    for(Position p : d.getPaintPoses())
    {
        CHECK(p.x <= d.getRoomLenght());
        CHECK(p.y <= d.getRoomWidth());
    }
}

TEST_CASE("Path tree test")
{
    PTree t;

    std::queue<char> q1, q2;

    q1.push('N');
    q1.push('N');
    q1.push('E');
    q1.push('P');
    q1.push('S');

    q2.push('W');
    q2.push('W');
    q2.push('W');
    q2.push('N');
    q2.push('P');
    q2.push('E');

    t.add(q1);
    t.add(q2);
    t.createLeafIndex();

    std::string str = t.wantedPath(0);
    CHECK(str[0] == 'B');
    CHECK(str[1] == 'N');
    CHECK(str[2] == 'N');
    CHECK(str[3] == 'E');
    CHECK(str[4] == 'P');
    CHECK(str[5] == 'S');

    str = t.wantedPath(1);
    CHECK(str[0] == 'B');
    CHECK(str[1] == 'W');
    CHECK(str[2] == 'W');
    CHECK(str[3] == 'W');
    CHECK(str[4] == 'N');
    CHECK(str[5] == 'P');
    CHECK(str[6] == 'E');

    str = t.wantedPath(5);
    CHECK(str.size() == 0);

    CHECK(PTree::indexCounter == 2);

    PTree::indexCounter = 0;
}



int PTree::indexCounter = 0;
int main()
{
    doctest::Context().run();

    System system;
    system.run();


    return 0;
}
