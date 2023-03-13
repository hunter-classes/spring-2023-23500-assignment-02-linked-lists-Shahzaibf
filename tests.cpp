#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "List.h"
#include "OList.h"
#include "Node.h"

TEST_CASE("insert and toString"){
    OList* l = new OList();
    l->insert("1");
    l->insert("11");
    l->insert("123");
    CHECK(l->toString() == "1-->11-->123-->nullptr");
}

TEST_CASE("contains"){
    OList *l = new OList();
    l->insert("11");
    l->insert("22");
    CHECK(l->contains("11") == true);
    CHECK(l->contains("5") == false);
    CHECK(l->contains("8") == false);
}

TEST_CASE("get"){
 
    OList *l = new OList();

    l->insert("11");
    l->insert("22");
    l->insert("33");

    CHECK(l->get(0) == "11");
    CHECK(l->get(1) == "22");

}

TEST_CASE("remove"){
    OList *l = new OList();

    l->insert("1");
    l->insert("2");
    l->insert("3");
    l->remove(1);
    CHECK(l->get(0) == "1");
    CHECK(l->get(1) == "3");
}

TEST_CASE("reverse"){
    OList *l = new OList();

    l->insert("3");
    l->insert("6");
    l->insert("9");
    l->reverse();

    CHECK(l->toString() == "9-->6-->3-->nullptr");

}