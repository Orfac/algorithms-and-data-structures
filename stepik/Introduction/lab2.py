def fib_digit(n):
    f = [1,1]
    for i in range(2,n):
        f[i % 2] = (f[i % 2] + f[(i + 1) % 2]) % 10
    return f[(n - 1) % 2]
    
def main():
    n = int(input())
    print(fib_digit(n))


if __name__ == "__main__":
    main()
