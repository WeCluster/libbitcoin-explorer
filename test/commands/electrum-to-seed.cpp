/**
 * Copyright (c) 2011-2018 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "command.hpp"

BX_USING_NAMESPACES()

BOOST_AUTO_TEST_SUITE(offline)
BOOST_AUTO_TEST_SUITE(electrum_to_seed__invoke)

BOOST_AUTO_TEST_CASE(electrum_to_seed__invoke__okay_output)
{
    BX_DECLARE_COMMAND(electrum_to_seed);
    command.set_words_argument({ "foo", "bar", "baz" });
    BX_REQUIRE_OKAY(command.invoke(output, error));
    BX_REQUIRE_OUTPUT("c4033901dd61ba26cfd0a1cf1ceb4b347606635aa3cb951eb6e819d58beedc04dd400a2e600d783c83c75879d6538abeecc7bb1b292b2a4d775d348d5d686427\n");
}

BOOST_AUTO_TEST_CASE(electrum_to_seed__invoke__language_en__okay_output)
{
    BX_DECLARE_COMMAND(electrum_to_seed);
    command.set_language_option({ "en" });
    command.set_words_argument({ "foobar" });
    BX_REQUIRE_OKAY(command.invoke(output, error));

    // TODO: value retrofitted, verify correctness.
    BX_REQUIRE_OUTPUT("4fb0a3be09314418147c89e40e4972bdd9bd45cb7cb04bae515df966c2c2dc41d3807dc7fea6a00484bbc2c73feeca5aea5341c1e20d9e370275c7b3bb627830\n");
}

BOOST_AUTO_TEST_CASE(electrum_to_seed__invoke__12_words__okay_output)
{
    BX_DECLARE_COMMAND(electrum_to_seed);
    command.set_language_option({ "en" });
    command.set_words_argument({ "giggle", "crush", "argue", "inflict", "wear", "defy", "combine", "evolve", "tiger", "spatial", "crumble", "fury" });
    BX_REQUIRE_OKAY(command.invoke(output, error));
    BX_REQUIRE_OUTPUT("eb095e70f0eb8d24f2cef276c75b136c2ff41eb72a9291eb22ba45d11fbb875a965bd6ae09873543eea98bf3ae05067203cd56388e0978aebc3a511932704d80\n");
}

#ifdef WITH_ICU
    // TODO: add passphrase tests.
#endif

BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
