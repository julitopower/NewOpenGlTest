/*
 * Simple Raspberry Pi OpenGl-ES window tests application 
 * Copyright (C) 2013-2014, Julio Delgado <julio.delgadomangas@gmail.com>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include "../src/FizzBuzz.hpp"
#include <cppunit/extensions/HelperMacros.h>
#include <string>
using namespace std;


class FizzBuzzTest : public CppUnit::TestFixture {

	CPPUNIT_TEST_SUITE(FizzBuzzTest);
	CPPUNIT_TEST(testGiven3WhenFizzBuzzThenFizz);
	CPPUNIT_TEST(testGive5WhenFizzBuzzThenBuzz);
	CPPUNIT_TEST(testGiven15WhenFizzBuzzThenFizzBuzz);
	CPPUNIT_TEST_SUITE_END();
	public:
		void testGiven3WhenFizzBuzzThenFizz() {
			CPPUNIT_ASSERT_EQUAL ( string("Fizz"), fizzBuzz(3) );
		}

		void testGive5WhenFizzBuzzThenBuzz() {
			CPPUNIT_ASSERT_EQUAL ( string("Buzz"), fizzBuzz(5) );

		}

		void testGiven15WhenFizzBuzzThenFizzBuzz() {
			CPPUNIT_ASSERT_EQUAL ( string("FizzBuzz"), fizzBuzz(15) );
		}
};

CPPUNIT_TEST_SUITE_REGISTRATION(FizzBuzzTest);

