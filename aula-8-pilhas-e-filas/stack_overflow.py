def fibonacci(pos):
    return fibonacci(pos -1) + fibonacci(pos -2)

if __name__ == "__main__":
    print(fibonacci(30))