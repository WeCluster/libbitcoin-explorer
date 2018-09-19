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
BOOST_AUTO_TEST_SUITE(mnemonic_new__invoke)

BOOST_AUTO_TEST_CASE(mnemonic_new__invoke__64_bits__okay_output)
{
    BX_DECLARE_COMMAND(mnemonic_new);
    command.set_seed_argument({ "baadf00dbaadf00d" });
    BX_REQUIRE_OKAY(command.invoke(output, error));
    BX_REQUIRE_OUTPUT("rival hurdle address inspire tenant alone\n");
}

BOOST_AUTO_TEST_CASE(mnemonic_new__invoke__136_bits__failure_error)
{
    BX_DECLARE_COMMAND(mnemonic_new);
    command.set_seed_argument({ "baadf00dbaadf00dbaadf00dbaadf00dff" });
    BX_REQUIRE_FAILURE(command.invoke(output, error));
    BX_REQUIRE_ERROR(BX_EC_MNEMONIC_NEW_INVALID_SEED "\n");
}

BOOST_AUTO_TEST_CASE(mnemonic_new__invoke__128_bits__okay_output)
{
    BX_DECLARE_COMMAND(mnemonic_new);
    command.set_seed_argument({ "baadf00dbaadf00dbaadf00dbaadf00d" });
    BX_REQUIRE_OKAY(command.invoke(output, error));
    BX_REQUIRE_OUTPUT("rival hurdle address inspire tenant almost turkey safe asset step lab boy\n");
}

BOOST_AUTO_TEST_CASE(mnemonic_new__invoke__standard_default__okay_output)
{
    BX_DECLARE_COMMAND(mnemonic_new);
    command.set_seed_argument({ "7f7f7f7f7f7f7f7f7f7f7f7f7f7f7f7f" });
    BX_REQUIRE_OKAY(command.invoke(output, error));
    BX_REQUIRE_OUTPUT("legal winner thank year wave sausage worth useful legal winner thank yellow\n");
}

BOOST_AUTO_TEST_CASE(mnemonic_new__invoke__standard_en__okay_output)
{
    BX_DECLARE_COMMAND(mnemonic_new);
    command.set_language_option({ "en" });
    command.set_seed_argument({ "7f7f7f7f7f7f7f7f7f7f7f7f7f7f7f7f" });
    BX_REQUIRE_OKAY(command.invoke(output, error));
    BX_REQUIRE_OUTPUT("legal winner thank year wave sausage worth useful legal winner thank yellow\n");
}

BOOST_AUTO_TEST_CASE(mnemonic_new__invoke__standard_all__okay_output)
{
    BX_DECLARE_COMMAND(mnemonic_new);
    command.set_language_option({ "any" });
    command.set_seed_argument({ "7f7f7f7f7f7f7f7f7f7f7f7f7f7f7f7f" });
    BX_REQUIRE_OKAY(command.invoke(output, error));
    BX_REQUIRE_OUTPUT("legal winner thank year wave sausage worth useful legal winner thank yellow\n");
}

BOOST_AUTO_TEST_CASE(mnemonic_new__invoke__128_bits_en__okay_output)
{
    BX_DECLARE_COMMAND(mnemonic_new);
    command.set_language_option({ "en" });
    command.set_seed_argument({ "baadf00dbaadf00dbaadf00dbaadf00d" });
    BX_REQUIRE_OKAY(command.invoke(output, error));
    BX_REQUIRE_OUTPUT("rival hurdle address inspire tenant almost turkey safe asset step lab boy\n");
}

BOOST_AUTO_TEST_CASE(mnemonic_new__invoke__128_bits_es__okay_output)
{
    BX_DECLARE_COMMAND(mnemonic_new);
    command.set_language_option({ "es" });
    command.set_seed_argument({ "baadf00dbaadf00dbaadf00dbaadf00d" });
    BX_REQUIRE_OKAY(command.invoke(output, error));
    BX_REQUIRE_OUTPUT("previo humilde actuar jarabe tabique ahorro tope pulpo anís señal lavar bahía\n");
}

BOOST_AUTO_TEST_CASE(mnemonic_new__invoke__128_bits_fr__okay_output)
{
    BX_DECLARE_COMMAND(mnemonic_new);
    command.set_language_option({ "fr" });
    command.set_seed_argument({ "baadf00dbaadf00dbaadf00dbaadf00d" });
    BX_REQUIRE_OKAY(command.invoke(output, error));
    BX_REQUIRE_OUTPUT("placard garantir acerbe gratuit soluble affaire théorie ponctuel anguleux salon horrible bateau\n");
}

BOOST_AUTO_TEST_CASE(mnemonic_new__invoke__128_bits_it__okay_output)
{
    BX_DECLARE_COMMAND(mnemonic_new);
    command.set_language_option({ "it" });
    command.set_seed_argument({ "baadf00dbaadf00dbaadf00dbaadf00d" });
    BX_REQUIRE_OKAY(command.invoke(output, error));
    BX_REQUIRE_OUTPUT("rizoma lastra affabile lucidato sultano algebra tramonto rupe annuncio sonda mega bavosa\n");
}

BOOST_AUTO_TEST_CASE(mnemonic_new__invoke__128_bits_ja__okay_output)
{
    BX_DECLARE_COMMAND(mnemonic_new);
    command.set_language_option({ "ja" });
    command.set_seed_argument({ "baadf00dbaadf00dbaadf00dbaadf00d" });
    BX_REQUIRE_OKAY(command.invoke(output, error));
    BX_REQUIRE_OUTPUT("ねんかん すずしい あひる せたけ ほとんど あんまり めいあん のべる いなか ふとる ぜんりゃく えいせい\n");
}

BOOST_AUTO_TEST_CASE(mnemonic_new__invoke__128_bits_cs__okay_output)
{
    BX_DECLARE_COMMAND(mnemonic_new);
    command.set_language_option({ "cs" });
    command.set_seed_argument({ "baadf00dbaadf00dbaadf00dbaadf00d" });
    BX_REQUIRE_OKAY(command.invoke(output, error));
    BX_REQUIRE_OUTPUT("semeno mudrc babka nasekat uvolnit bazuka vydra skanzen broskev trefit nuget datel\n");
}

BOOST_AUTO_TEST_CASE(mnemonic_new__invoke__128_bits_ru__okay_output)
{
    BX_DECLARE_COMMAND(mnemonic_new);
    command.set_language_option({ "ru" });
    command.set_seed_argument({ "baadf00dbaadf00dbaadf00dbaadf00d" });
    BX_REQUIRE_OKAY(command.invoke(output, error));
    BX_REQUIRE_OUTPUT("ремарка кривой айсберг лауреат тротуар амнезия фонтан рояль бакалея сухой магазин бунт\n");
}

BOOST_AUTO_TEST_CASE(mnemonic_new__invoke__128_bits_uk__okay_output)
{
    BX_DECLARE_COMMAND(mnemonic_new);
    command.set_language_option({ "uk" });
    command.set_seed_argument({ "baadf00dbaadf00dbaadf00dbaadf00d" });
    BX_REQUIRE_OKAY(command.invoke(output, error));
    BX_REQUIRE_OUTPUT("сержант ледачий актив люкс фах арена цемент слон бесіда тротуар мандри верба" "\n");
}

BOOST_AUTO_TEST_CASE(mnemonic_new__invoke__128_bits_zh_Hans__okay_output)
{
    BX_DECLARE_COMMAND(mnemonic_new);
    command.set_language_option({ "zh_Hans" });
    command.set_seed_argument({ "baadf00dbaadf00dbaadf00dbaadf00d" });
    BX_REQUIRE_OKAY(command.invoke(output, error));
    BX_REQUIRE_OUTPUT("博 肉 地 危 惜 多 陪 荒 因 患 伊 基\n");
}

BOOST_AUTO_TEST_CASE(mnemonic_new__invoke__128_bits_zh_Hant__okay_output)
{
    BX_DECLARE_COMMAND(mnemonic_new);
    command.set_language_option({ "zh_Hant" });
    command.set_seed_argument({ "baadf00dbaadf00dbaadf00dbaadf00d" });
    BX_REQUIRE_OKAY(command.invoke(output, error));
    BX_REQUIRE_OUTPUT("博 肉 地 危 惜 多 陪 荒 因 患 伊 基\n");
}

BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
