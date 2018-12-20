using System;
using Xunit;

namespace TemperatureUnitTest
{
    public class UnitTest1
    {
        [Theory]
        [InlineData(0.0, 32.0)] // 0 celsius is 32 fahrenheit
        [InlineData(-40, -40)] // -40 celsius is -40 fahrenheit
        [InlineData(100, 212)]
        [InlineData(-20.5, -4.9)]
        public void CelsiusTest(double value1, double value2)
        {
            Assert.Equal(value1, Celsius(value2), 2);
        }

        [Theory]
        [InlineData(98.6, 37)]
        [InlineData(-40, -40)]
        [InlineData(32.0, 0.0)]
        [InlineData(414.14, 212.3)]
        public void FahrenheitTest(double value1, double value2)
        {
            Assert.Equal(value1, Fahrenheit(value2), 2);
        }

        [Fact]
        public void BothTest()
        {
            Assert.Equal(20.0, Celsius(Fahrenheit(20.0)));
            Assert.Equal(80.95, Fahrenheit(Celsius(80.95)));
            Assert.Equal(-34.5, Celsius(Fahrenheit(-34.5)));
            Assert.Equal(-34.5, Fahrenheit(Celsius(-34.5)));
        }
        //Converts fahrenheit temp to celsius
        public double Celsius(double fahrenheit){
            //returns the F->C calculation
            return 5.0 / 9.0 * (fahrenheit - 32);
        }
        //Converts celsius temp to fahrenheit
        public double Fahrenheit(double celsius){
            //returns the C->F calculation
            return 9.0 / 5.0 * celsius + 32;
        }

    }
}
