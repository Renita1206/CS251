// Decimal to Binary
int fun(int n)
{
    if (n==0)
        return 0;
    
    fun(n/2);
    printf("%d",n%2);
}

int factorial(int n)
{
    if(n==0)
        return 1;
    
    return n * factorial(n-1);
}

int fib(int n)
{
    if(n==0)
        return 0;
    else if(n==1 || n==2)
        return 1;
    else
        return fib(n-1)+fib(n-2);
}