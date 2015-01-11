#include <utility>

#include <gmock/gmock.h>

#include <boost/typeof/typeof.hpp>


using namespace ::testing;


TEST(boost_auto, deduces_pair_type)
{
	BOOST_AUTO(item, std::make_pair("milk", 1.12));

	ASSERT_THAT(item.first, Eq("milk"));
	ASSERT_THAT(item.second, Eq(1.12));
}
