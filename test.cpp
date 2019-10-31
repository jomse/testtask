#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE tests
#include <boost/test/unit_test.hpp>
#include "fileOperation.h"

BOOST_AUTO_TEST_SUITE(TestCountChecksum)
struct Fixture {
    testtask::FileOperation checksum;
};

BOOST_FIXTURE_TEST_CASE(emptyStream, Fixture) {
    std::stringstream ss(std::string(""));
    auto result = checksum.countChecksum(ss);        
    BOOST_CHECK_EQUAL(result, 0);
}

BOOST_FIXTURE_TEST_CASE(SymbolStream, Fixture) {
    std::stringstream ss(std::string("A"));
    auto result = checksum.countChecksum(ss);        
    BOOST_CHECK_EQUAL(result, 1090519040);
}

BOOST_FIXTURE_TEST_CASE(ManySymbolsStream, Fixture) {
    std::stringstream ss(std::string("BCDEF"));
    auto result = checksum.countChecksum(ss);        
    BOOST_CHECK_EQUAL(result, 2286109765);
}


BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(TestCountWord)
struct Fixture {
    testtask::FileOperation word;
};

BOOST_FIXTURE_TEST_CASE(emptyStreamAndWord, Fixture) {
    std::stringstream ss(std::string(""));
    auto result = word.countWord(ss, "a");        
    BOOST_CHECK_EQUAL(result, 0);
}

BOOST_FIXTURE_TEST_CASE(LongSymbolsStream, Fixture) {
    std::stringstream ss(std::string("mother washed the mother`s frame\n"));
    auto result = word.countWord(ss, "mother");        
    BOOST_CHECK_EQUAL(result, 1);
}

BOOST_AUTO_TEST_SUITE_END()