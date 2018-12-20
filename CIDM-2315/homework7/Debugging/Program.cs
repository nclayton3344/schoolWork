namespace Debugging
{
    class Program
    {
        static void Main(string[] args)
        {
            int x = 5;
            int y = ~x;
            int z = y^x & 20 | 42;
            int a = z & x | y^~z;
        }
    }
}
