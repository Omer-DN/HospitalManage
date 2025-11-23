#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../HospitalManage/Patient.h"

TEST_CASE("Patient basic properties", "[patient]") {
    Patient p("Omer", 3, "headache",100);

    REQUIRE(p.getName() == "Omer");
    REQUIRE(p.getSeverity() == 3);
    REQUIRE(p.getArrivalTime() == 100);
}

TEST_CASE("Patient severity ordering", "[patient][ordering]") {
    Patient p1("A", 5, 10);
    Patient p2("B", 3, 20);

    REQUIRE(p1.getSeverity() > p2.getSeverity());
}
