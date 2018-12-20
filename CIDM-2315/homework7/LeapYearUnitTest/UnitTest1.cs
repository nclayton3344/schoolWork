//NATHANIEL CLAYTON
//CIDM-2315 ---- HOMEWORK 7
//NOVEMBER 7, 2018
using System;
using Xunit;

namespace LeapYearUnitTest
{
    public class UnitTest1
    {
        [Theory]
        [InlineData(1600, true)] // 1600 is an old leap year
        [InlineData(1800, false)] // 1800 is not a leap year
        [InlineData(1848, true)] // 1848 is a leap year
        [InlineData(1900, false)] // 1900 is century year that is not a leap year
        [InlineData(1901, false)] // 1901 is not a leap year
        [InlineData(2000, true)] // 2000 is century year that is a leap year
        [InlineData(2004, true)] // 2004 is normal leap year
        [InlineData(2006, false)] // 2006 is a common year
        [InlineData(2020, true)] // 2020 is a future leap year
        [InlineData(2400, true)] // 2400 is a future century leap year
        public void Test1(int year, bool isLeapYear)
        {
            Assert.Equal(isLeapYear, IsLeapYear(year));
        }

        public bool IsLeapYear(int year)
        {
            // bool isLeapYear = false; //< ----- DO NOT NEED IT, BECAUSE SKILLS
            // Write your code here. You must check if year variable is a leap year or not
            // If it is, set isLeapYear = true, otherwise set to false

            //this is more efficient, hope this is acceptable
            return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));

            // return isLeapYear; //<--- DO NOT NEED, BECAUSE SKILLS
        }
    }
}
