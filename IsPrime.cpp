bool isPrime(int n)
{
    if (n == 0 || n == 1)
    {
        return false;
    }
    else
    {
        if (n == 2)
        {
            return true;
        }
        if (n % 2 == 0)
        {
            return false;
        }
        int temp = sqrt(n);
        for (int i = 3; i <= temp; ++i)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
    }
    return true;
}