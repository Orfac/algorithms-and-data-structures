[2~elements = []
elements.append(1)
elements.append(1)

def fib(n):
    if n <= len(elements):
        return elements[n - 1]
    value = fib(n-1) + fib(n-2)
    elements.append(value)
    return value
    
def main():
    n = int(input())
    print(fib(n))


if __name__ == "__main__":
    main()
