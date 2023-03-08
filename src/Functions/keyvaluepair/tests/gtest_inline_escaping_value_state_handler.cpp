#include <Functions/keyvaluepair/src/impl/state/strategies/escaping/InlineEscapingValueStateHandler.h>
#include <gtest/gtest.h>

namespace DB
{

void test_wait(const auto & handler, std::string_view input, std::size_t expected_pos, State expected_state)
{
    auto next_state = handler.wait(input, 0u);

    ASSERT_EQ(next_state.position_in_string, expected_pos);
    ASSERT_EQ(next_state.state, expected_state);
}

TEST(InlineEscapingValueStateHandler, Wait)
{
//    auto key_value_delimiters = std::unordered_set<char> {':', '='};
//    auto pair_delimiters = std::unordered_set<char> {',', ' '};
//    auto quoting_characters = std::unordered_set<char> {'"'};
//
//    ExtractorConfiguration configuration(key_value_delimiters, pair_delimiters, quoting_characters);
//    InlineEscapingValueStateHandler handler(configuration);
//
//    test_wait(handler, "name", 0u, READING_KEY);
//    test_wait(handler, "\\:name", 2u, READING_KEY);
//    test_wait(handler, R"(\\"name)", 3u, READING_ENCLOSED_KEY);
//
//    test_wait(handler, "", 0u, END);
//    test_wait(handler, "\\\\", 2u, END);
}

}
