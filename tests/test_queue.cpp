#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_exception.hpp>

#include "../sources/Queue/ArrayQueue.hpp"
#include "../sources/Queue/LinkedQueue.hpp"

using Catch::Matchers::Message;

using namespace hellods;

template <typename Queue>
void test()
{
    // Constructor / Destructor
    Queue empty;
    Queue some = {1, 2, 3, 4, 5};

    // Comparison
    REQUIRE(empty == Queue());
    REQUIRE(some == Queue({1, 2, 3, 4, 5}));
    REQUIRE(empty != some);
    REQUIRE(some != Queue({1, 2, 3, 4, 6}));

    // Access
    REQUIRE(some.front() == 1);
    some.front() = 0;
    REQUIRE(some.front() == 0);
    REQUIRE_THROWS_MATCHES(empty.front(), std::runtime_error, Message("Error: The container is empty."));

    // Examination
    REQUIRE(empty.size() == 0);
    REQUIRE(empty.is_empty() == true);

    REQUIRE(some.size() == 5);
    REQUIRE(some.is_empty() == false);

    // Manipulation
    empty.enqueue(1);
    REQUIRE(empty == Queue({1}));
    empty.enqueue(2);
    REQUIRE(empty == Queue({1, 2}));
    empty.enqueue(3);
    REQUIRE(empty == Queue({1, 2, 3}));

    REQUIRE(empty.dequeue() == 1);
    REQUIRE(empty.dequeue() == 2);
    REQUIRE(empty.dequeue() == 3);
    REQUIRE_THROWS_MATCHES(empty.dequeue(), std::runtime_error, Message("Error: The container is empty."));

    REQUIRE(some.clear() == empty);
    REQUIRE(some.clear() == empty); // double clear
}

TEST_CASE("ArrayQueue")
{
    test<ArrayQueue<int>>();
    test<ArrayQueue<double>>();
}

TEST_CASE("LinkedQueue")
{
    test<LinkedQueue<int>>();
    test<LinkedQueue<double>>();
}
