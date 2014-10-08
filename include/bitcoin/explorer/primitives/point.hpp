/**
 * Copyright (c) 2011-2014 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin-explorer.
 *
 * libbitcoin-explorer is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <sstream>
#include <cstdint>
#include <string>
#include <vector>
#include <boost/program_options.hpp>
#include <bitcoin/bitcoin.hpp>
#include <bitcoin/explorer/define.hpp>
#include <bitcoin/explorer/primitives/btc256.hpp>
#include <bitcoin/explorer/utility/utility.hpp>

/* NOTE: don't declare 'using namespace foo' in headers. */

namespace libbitcoin {
namespace explorer {
namespace primitives {

/**
 * Parse two tokens into an output point.
 * Throws if the hash digest or index is not valid.
 *
 * @param[out] point   The out point to populate.
 * @param[in]  tokens  The two tokens to parse.
 */
    static void parse_point(output_point& point,
        const std::vector<std::string>& tokens);

/**
 * Serialization helper to convert between text and an output_point.
 */
class point
{
public:

    /**
     * Default constructor.
     */
    point();

    /**
     * Initialization constructor.
     * @param[in]  tuple  The value to initialize with.
     */
    point(const std::string& tuple);

    /**
     * Initialization constructor.
     * @param[in]  value  The value to initialize with.
     */
    point(const output_point& value);

    /**
     * Copy constructor.
     * @param[in]  other  The object to copy into self on construct.
     */
    point(const point& other);

    /**
     * Return a reference to the data member.
     * @return  A reference to the object's internal data.
     */
    output_point& data();

    /**
     * Overload cast to internal type.
     * @return  This object's value cast to internal type.
     */
    operator const output_point&() const;

    /**
     * Overload stream in. Throws if input is invalid.
     * @param[in]   input     The input stream to read the value from.
     * @param[out]  argument  The object to receive the read value.
     * @return                The input stream reference.
     */
    friend std::istream& operator>>(std::istream& input, point& argument);

    /**
     * Overload stream out.
     * @param[in]   output    The output stream to write the value to.
     * @param[out]  argument  The object from which to obtain the value.
     * @return                The output stream reference.
     */
    friend std::ostream& operator<<(std::ostream& output,
        const point& argument);

private:

    /**
     * The state of this object.
     */
    output_point value_;
};

} // namespace explorer
} // namespace primitives
} // namespace libbitcoin

#endif