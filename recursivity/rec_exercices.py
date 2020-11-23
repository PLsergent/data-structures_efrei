def multiply(a: int = 2, b: int = 2) -> int:
    if b == 0: return 0
    return a + multiply(a, b-1)


def enum(n: int = 0, range: int = 30):
    if n != range:
        n += 1
        print(n, end=" ")
        enum(n, range)

def hanoi(n , source, destination, auxiliary):
    print(n)
    if n == 1: 
        print("Move disk 1 from source", source, "to destination", destination)
        return
    hanoi(n-1, source, auxiliary, destination) 
    print("Move disk", n, "from source", source, "to destination", destination)
    hanoi(n-1, auxiliary, destination, source)
        

if __name__ == "__main__":
    print("Multiply :", multiply())
    print("Enum :", end=" ")
    enum()

    hanoi(3, 'A', 'C', 'B')  
