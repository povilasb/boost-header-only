#include <utility>

#include <gmock/gmock.h>

#include <boost/typeof/typeof.hpp>
#include <boost/iterator/filter_iterator.hpp>


using namespace ::testing;

namespace boost
{


TEST(boost_auto, deduces_pair_type)
{
	BOOST_AUTO(item, std::make_pair("milk", 1.12));

	ASSERT_THAT(item.first, Eq("milk"));
	ASSERT_THAT(item.second, Eq(1.12));
}


struct odd_number {
	bool
	operator()(int num)
	{
		return (num % 2) != 0;
	}
};

TEST(boost_filter_iterator_create,
	returns_iterator_pointing_to_first_element_satisfying_predicate)
{
	std::vector<int> numbers;
	numbers.push_back(2);
	numbers.push_back(4);
	numbers.push_back(5);

	odd_number predicate;
	BOOST_AUTO(it, make_filter_iterator<odd_number>(numbers.begin(),
		numbers.end())
	);

	ASSERT_THAT(*it, Eq(5));
}


} // namespace boost.
